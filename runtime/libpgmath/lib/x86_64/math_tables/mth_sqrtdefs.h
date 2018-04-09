/*
 * Copyright (c) 2017-2018, NVIDIA CORPORATION.  All rights reserved.
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

MTHINTRIN(sqrt  , sv4m , any        , __fs_sqrt_4_mn         , __rs_sqrt_4_mn         , __ps_sqrt_4_mn         ,__math_dispatch_error)
MTHINTRIN(sqrt  , dv2m , any        , __fd_sqrt_2_mn         , __rd_sqrt_2_mn         , __pd_sqrt_2_mn         ,__math_dispatch_error)
MTHINTRIN(sqrt  , sv8m , avx        , __fs_sqrt_8_mn         , __rs_sqrt_8_mn         , __ps_sqrt_8_mn         ,__math_dispatch_error)
MTHINTRIN(sqrt  , dv4m , avx        , __fd_sqrt_4_mn         , __rd_sqrt_4_mn         , __pd_sqrt_4_mn         ,__math_dispatch_error)
MTHINTRIN(sqrt  , sv8m , avxfma4    , __fs_sqrt_8_mn         , __rs_sqrt_8_mn         , __ps_sqrt_8_mn         ,__math_dispatch_error)
MTHINTRIN(sqrt  , dv4m , avxfma4    , __fd_sqrt_4_mn         , __rd_sqrt_4_mn         , __pd_sqrt_4_mn         ,__math_dispatch_error)
MTHINTRIN(sqrt  , sv8m , avx2       , __fs_sqrt_8_mn         , __rs_sqrt_8_mn         , __ps_sqrt_8_mn         ,__math_dispatch_error)
MTHINTRIN(sqrt  , dv4m , avx2       , __fd_sqrt_4_mn         , __rd_sqrt_4_mn         , __pd_sqrt_4_mn         ,__math_dispatch_error)
MTHINTRIN(sqrt  , sv8m , avx512knl  , __fs_sqrt_8_mn         , __rs_sqrt_8_mn         , __ps_sqrt_8_mn         ,__math_dispatch_error)
MTHINTRIN(sqrt  , dv4m , avx512knl  , __fd_sqrt_4_mn         , __rd_sqrt_4_mn         , __pd_sqrt_4_mn         ,__math_dispatch_error)
MTHINTRIN(sqrt  , sv16m, avx512knl  , __fs_sqrt_16_mn        , __rs_sqrt_16_mn        , __ps_sqrt_16_mn         ,__math_dispatch_error)
MTHINTRIN(sqrt  , dv8m , avx512knl  , __fd_sqrt_8_mn         , __rd_sqrt_8_mn         , __pd_sqrt_8_mn         ,__math_dispatch_error)
MTHINTRIN(sqrt  , sv8m , avx512     , __fs_sqrt_8_mn         , __rs_sqrt_8_mn         , __ps_sqrt_8_mn         ,__math_dispatch_error)
MTHINTRIN(sqrt  , dv4m , avx512     , __fd_sqrt_4_mn         , __rd_sqrt_4_mn         , __pd_sqrt_4_mn         ,__math_dispatch_error)
MTHINTRIN(sqrt  , sv16m, avx512     , __fs_sqrt_16_mn        , __rs_sqrt_16_mn        , __ps_sqrt_16_mn         ,__math_dispatch_error)
MTHINTRIN(sqrt  , dv8m , avx512     , __fd_sqrt_8_mn         , __rd_sqrt_8_mn         , __pd_sqrt_8_mn         ,__math_dispatch_error)

MTHINTRIN(sqrt  , cs   , em64t      , csqrtf                 , csqrtf                 , csqrtf                 ,__math_dispatch_error)
MTHINTRIN(sqrt  , zs   , em64t      , csqrt                  , csqrt                  , csqrt                  ,__math_dispatch_error)
MTHINTRIN(sqrt  , zv1  , em64t      , __gz_sqrt_1v_f         , __gz_sqrt_1v_r         , __gz_sqrt_1v_p         ,__math_dispatch_error)
MTHINTRIN(sqrt  , cv2  , em64t      , __gc_sqrt_2_f          , __gc_sqrt_2_r          , __gc_sqrt_2_p          ,__math_dispatch_error)
MTHINTRIN(sqrt  , cs   , sse4       , csqrtf                 , csqrtf                 , csqrtf                 ,__math_dispatch_error)
MTHINTRIN(sqrt  , zs   , sse4       , csqrt                  , csqrt                  , csqrt                  ,__math_dispatch_error)
MTHINTRIN(sqrt  , zv1  , sse4       , __gz_sqrt_1v_f         , __gz_sqrt_1v_r         , __gz_sqrt_1v_p         ,__math_dispatch_error)
MTHINTRIN(sqrt  , cv2  , sse4       , __gc_sqrt_2_f          , __gc_sqrt_2_r          , __gc_sqrt_2_p          ,__math_dispatch_error)
MTHINTRIN(sqrt  , cs   , avx        , csqrtf                 , csqrtf                 , csqrtf                 ,__math_dispatch_error)
MTHINTRIN(sqrt  , zs   , avx        , csqrt                  , csqrt                  , csqrt                  ,__math_dispatch_error)
MTHINTRIN(sqrt  , zv1  , avx        , __gz_sqrt_1v_f         , __gz_sqrt_1v_r         , __gz_sqrt_1v_p         ,__math_dispatch_error)
MTHINTRIN(sqrt  , cv2  , avx        , __gc_sqrt_2_f          , __gc_sqrt_2_r          , __gc_sqrt_2_p          ,__math_dispatch_error)
MTHINTRIN(sqrt  , cv4  , avx        , __gc_sqrt_4_f          , __gc_sqrt_4_r          , __gc_sqrt_4_p          ,__math_dispatch_error)
MTHINTRIN(sqrt  , zv2  , avx        , __gz_sqrt_2_f          , __gz_sqrt_2_r          , __gz_sqrt_2_p          ,__math_dispatch_error)
MTHINTRIN(sqrt  , cs   , avxfma4    , csqrtf                 , csqrtf                 , csqrtf                 ,__math_dispatch_error)
MTHINTRIN(sqrt  , zs   , avxfma4    , csqrt                  , csqrt                  , csqrt                  ,__math_dispatch_error)
MTHINTRIN(sqrt  , zv1  , avxfma4    , __gz_sqrt_1v_f         , __gz_sqrt_1v_r         , __gz_sqrt_1v_p         ,__math_dispatch_error)
MTHINTRIN(sqrt  , cv2  , avxfma4    , __gc_sqrt_2_f          , __gc_sqrt_2_r          , __gc_sqrt_2_p          ,__math_dispatch_error)
MTHINTRIN(sqrt  , cv4  , avxfma4    , __gc_sqrt_4_f          , __gc_sqrt_4_r          , __gc_sqrt_4_p          ,__math_dispatch_error)
MTHINTRIN(sqrt  , zv2  , avxfma4    , __gz_sqrt_2_f          , __gz_sqrt_2_r          , __gz_sqrt_2_p          ,__math_dispatch_error)
MTHINTRIN(sqrt  , cs   , avx2       , csqrtf                 , csqrtf                 , csqrtf                 ,__math_dispatch_error)
MTHINTRIN(sqrt  , zs   , avx2       , csqrt                  , csqrt                  , csqrt                  ,__math_dispatch_error)
MTHINTRIN(sqrt  , zv1  , avx2       , __gz_sqrt_1v_f         , __gz_sqrt_1v_r         , __gz_sqrt_1v_p         ,__math_dispatch_error)
MTHINTRIN(sqrt  , cv2  , avx2       , __gc_sqrt_2_f          , __gc_sqrt_2_r          , __gc_sqrt_2_p          ,__math_dispatch_error)
MTHINTRIN(sqrt  , cv4  , avx2       , __gc_sqrt_4_f          , __gc_sqrt_4_r          , __gc_sqrt_4_p          ,__math_dispatch_error)
MTHINTRIN(sqrt  , zv2  , avx2       , __gz_sqrt_2_f          , __gz_sqrt_2_r          , __gz_sqrt_2_p          ,__math_dispatch_error)
MTHINTRIN(sqrt  , cs   , avx512knl  , csqrtf                 , csqrtf                 , csqrtf                 ,__math_dispatch_error)
MTHINTRIN(sqrt  , zs   , avx512knl  , csqrt                  , csqrt                  , csqrt                  ,__math_dispatch_error)
MTHINTRIN(sqrt  , zv1  , avx512knl  , __gz_sqrt_1v_f         , __gz_sqrt_1v_r         , __gz_sqrt_1v_p         ,__math_dispatch_error)
MTHINTRIN(sqrt  , cv2  , avx512knl  , __gc_sqrt_2_f          , __gc_sqrt_2_r          , __gc_sqrt_2_p          ,__math_dispatch_error)
MTHINTRIN(sqrt  , cv4  , avx512knl  , __gc_sqrt_4_f          , __gc_sqrt_4_r          , __gc_sqrt_4_p          ,__math_dispatch_error)
MTHINTRIN(sqrt  , cv8  , avx512knl  , __gc_sqrt_8_f          , __gc_sqrt_8_r          , __gc_sqrt_8_p          ,__math_dispatch_error)
MTHINTRIN(sqrt  , zv2  , avx512knl  , __gz_sqrt_2_f          , __gz_sqrt_2_r          , __gz_sqrt_2_p          ,__math_dispatch_error)
MTHINTRIN(sqrt  , zv4  , avx512knl  , __gz_sqrt_4_f          , __gz_sqrt_4_r          , __gz_sqrt_4_p          ,__math_dispatch_error)
MTHINTRIN(sqrt  , cs   , avx512     , csqrtf                 , csqrtf                 , csqrtf                 ,__math_dispatch_error)
MTHINTRIN(sqrt  , zs   , avx512     , csqrt                  , csqrt                  , csqrt                  ,__math_dispatch_error)
MTHINTRIN(sqrt  , zv1  , avx512     , __gz_sqrt_1v_f         , __gz_sqrt_1v_r         , __gz_sqrt_1v_p         ,__math_dispatch_error)
MTHINTRIN(sqrt  , cv2  , avx512     , __gc_sqrt_2_f          , __gc_sqrt_2_r          , __gc_sqrt_2_p          ,__math_dispatch_error)
MTHINTRIN(sqrt  , cv4  , avx512     , __gc_sqrt_4_f          , __gc_sqrt_4_r          , __gc_sqrt_4_p          ,__math_dispatch_error)
MTHINTRIN(sqrt  , cv8  , avx512     , __gc_sqrt_8_f          , __gc_sqrt_8_r          , __gc_sqrt_8_p          ,__math_dispatch_error)
MTHINTRIN(sqrt  , zv2  , avx512     , __gz_sqrt_2_f          , __gz_sqrt_2_r          , __gz_sqrt_2_p          ,__math_dispatch_error)
MTHINTRIN(sqrt  , zv4  , avx512     , __gz_sqrt_4_f          , __gz_sqrt_4_r          , __gz_sqrt_4_p          ,__math_dispatch_error)
