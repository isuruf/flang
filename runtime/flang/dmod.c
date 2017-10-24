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

#include "mthdecls.h"

#if defined(_WIN32)
double __fmth_i_dmod(double f, double g);
#endif

double
__mth_i_dmod(double f, double g)
{
/* TODO: Need to do this way until a bug in the Win64 fmod routine is fixed */
#if defined(_WIN32)
  return fmod(f, g);
#else
  return fmod(f, g);
#endif
}
