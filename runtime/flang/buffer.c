/*
 * Copyright (c) 2017, NVIDIA CORPORATION.  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/** \file
 * \brief FIXME
 */

#if !defined(PARAMID) && !defined(_WIN32)
#include <fcntl.h>
#endif
#include "stdioInterf.h"
#include "fioMacros.h"

#if defined(_WIN32)
#define write _write
#define creat _creat
#define close _close
#endif

#define MAXBUF 4096

static char *buf;
static char *bufp;
static char *bufe;
static int fd;
static int off;

/*
 * the routines in this module are used as follows:
 *
 *	__fort_zopen("path");
 *	...
 *	__fort_zwrite(adr,len);
 *	...
 *	__fort_zclose();
 *
 * the file is written with all data from cpu 0, followed by all data
 * from cpu 1, ....
 */

/* open */

void
__fort_zopen(char *path)
{
  int ioproc;
  int n;
  int s;

  if (buf == (char *)0) {
    buf = __fort_gmalloc(MAXBUF);
  }
  ioproc = GET_DIST_IOPROC;
  if (GET_DIST_LCPU != ioproc) {
    bufp = buf + sizeof(int);
    *((int *)buf) = 0;
    bufe = buf + MAXBUF;
    __fort_rrecv(ioproc, &off, sizeof(off), 1, __UCHAR);
  } else {
    off = 0;
    fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
      __fort_abortp(path);
    }
    for (n = 0; n < ioproc; n++) {
      __fort_rsend(n, &off, sizeof(off), 1, __UCHAR);
      __fort_rrecv(n, buf, MAXBUF, 1, __UCHAR);
      while (*((int *)buf) != 0) {
        s = write(fd, buf + sizeof(int), *((int *)buf));
        if (s == -1) {
          __fort_abortp("__fort_zopen/write");
        }
        off += *((int *)buf);
        __fort_rrecv(n, buf, MAXBUF, 1, __UCHAR);
      }
    }
  }
}

/* write */

void __fort_zwrite(adr, len) char *adr;
int len;
{
  int ioproc;
  int s;

  ioproc = GET_DIST_IOPROC;
  if (GET_DIST_LCPU != ioproc) {
    if ((len + sizeof(int)) > (bufe - bufp)) {
      if (len > MAXBUF) {
        __fort_abort("__fort_zwrite: message too big");
      }
      __fort_rsend(ioproc, buf, MAXBUF, 1, __UCHAR);
      off += *((int *)buf);
      bufp = buf;
      *((int *)buf) = 0;
      bufp += sizeof(int);
    }
    *((int *)buf) += len;
    __fort_bcopy(bufp, adr, len);
    bufp += len;
  } else {
    s = write(fd, adr, len);
    if (s == -1) {
      __fort_abortp("__fort_zwrite");
    }
    off += len;
  }
}

/* tell */

int
__fort_ztell()
{
  return (off);
}

/* close */

void
__fort_zclose()
{
  int ioproc;
  int n;
  int s;
  int tcpus;

  ioproc = GET_DIST_IOPROC;
  if (GET_DIST_LCPU != ioproc) {
    if (*((int *)buf) != 0) {
      __fort_rsend(ioproc, buf, MAXBUF, 1, __UCHAR);
      off += *((int *)buf);
      *((int *)buf) = 0;
    }
    __fort_rsend(ioproc, buf, MAXBUF, 1, __UCHAR);
  } else {
    tcpus = GET_DIST_TCPUS;
    for (n = ioproc + 1; n < tcpus; n++) {
      __fort_rsend(n, &off, sizeof(off), 1, __UCHAR);
      __fort_rrecv(n, buf, MAXBUF, 1, __UCHAR);
      while (*((int *)buf) != 0) {
        s = write(fd, buf + sizeof(int), *((int *)buf));
        if (s == -1) {
          __fort_abortp("__fort_zclose/write");
        }
        off += *((int *)buf);
        __fort_rrecv(n, buf, MAXBUF, 1, __UCHAR);
      }
    }
    close(fd);
  }
}

