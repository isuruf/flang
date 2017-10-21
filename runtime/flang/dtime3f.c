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

/* clang-format off */

/*	dtime3f.c - Implements LIB3F dtime subprogram.  */

/* assumes the Unix times system call */
/* how do we do this for WINNT */
#include "ent3f.h"

#define _LIBC_LIMITS_H_
#ifndef _WIN32
#include <unistd.h>
#include <sys/times.h>
#endif
#include <sys/types.h>
#include <limits.h>

#ifndef CLK_TCK
#define CLK_TCK sysconf(_SC_CLK_TCK)
#endif

#ifndef _WIN32
static clock_t accum_user = 0, accum_sys = 0;

float ENT3F(DTIME, dtime)(float *tarray)
{
  struct tms b;
  float inv_ticks = 1 / (float)CLK_TCK;

  times(&b);
  tarray[0] = ((float)(b.tms_utime - accum_user)) * inv_ticks;
  tarray[1] = ((float)(b.tms_stime - accum_sys)) * inv_ticks;
  accum_user = b.tms_utime;
  accum_sys = b.tms_stime;
  return (tarray[0] + tarray[1]);
}
#else
#include <Windows.h>
static FILETIME accum_user;
static FILETIME accum_sys;

float convert_filetime( const FILETIME *ac_FileTime )
{
  ULARGE_INTEGER    lv_Large ;

  lv_Large.LowPart  = ac_FileTime->dwLowDateTime   ;
  lv_Large.HighPart = ac_FileTime->dwHighDateTime  ;

  return (float)lv_Large.QuadPart ;
}

float ENT3F(DTIME, dtime)(float *tarray)
{

  FILETIME time_create;
  FILETIME time_exit;

  GetProcessTimes( GetCurrentProcess(),
        &time_create, &time_exit, &accum_sys, &accum_user );

  tarray[0] = ((float)(convert_filetime(&accum_user)));
  tarray[1] = ((float)(convert_filetime(&accum_sys)));
  return (tarray[0] + tarray[1]);
}
#endif

