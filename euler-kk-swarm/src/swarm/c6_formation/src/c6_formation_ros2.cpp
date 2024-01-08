//
// File: c6_formation_ros2.cpp
//
// Code generated for Simulink model 'c6_formation_ros2'.
//
// Model version                  : 5.2
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Sat Oct 21 12:55:02 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "c6_formation_ros2.h"
#include "rtwtypes.h"
#include "c6_formation_ros2_types.h"
#include <string.h>
#include <math.h>
#include <emmintrin.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "c6_formation_ros2_private.h"
#include "rt_defines.h"
#include "rmw/qos_profiles.h"
#include "rmw/types.h"
#include <stddef.h>

// Named constants for Chart: '<Root>/Chart'
const uint8_T c6_formation_IN_DuiXingBianHuan = 1U;
const uint8_T c6_formation_ros2_IN_Circle = 1U;
const uint8_T c6_formation_ros2_IN_DuiDao = 2U;
const uint8_T c6_formation_ros2_IN_FengCao = 3U;
const uint8_T c6_formation_ros2_IN_Init = 2U;
const uint8_T c6_formation_ros2_IN_LieDui = 4U;
const uint8_T c6_formation_ros2_IN_SanKai = 5U;
const uint8_T c6_formation_ros2_IN_default = 6U;
int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

int32_T div_s32(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    // Divide by zero handler
  } else {
    uint32_T tempAbsQuotient;
    tempAbsQuotient = (numerator < 0 ? ~static_cast<uint32_T>(numerator) + 1U :
                       static_cast<uint32_T>(numerator)) / (denominator < 0 ? ~
      static_cast<uint32_T>(denominator) + 1U : static_cast<uint32_T>
      (denominator));
    quotient = (numerator < 0) != (denominator < 0) ? -static_cast<int32_T>
      (tempAbsQuotient) : static_cast<int32_T>(tempAbsQuotient);
  }

  return quotient;
}

// Function for MATLAB Function: '<S26>/Discrete-Time SqrtKF - Calculate SLMZ'
real_T c6_formation_ros2::c6_formation_ros2_xnrm2(int32_T n, const real_T x[50],
  int32_T ix0, B_CalculatePL_c6_formation_ro_T *localB)
{
  real_T y;
  int32_T kend;
  y = 0.0;
  localB->scale = 3.3121686421112381E-170;
  kend = (ix0 + n) - 1;
  for (int32_T k = ix0; k <= kend; k++) {
    localB->absxk_f = fabs(x[k - 1]);
    if (localB->absxk_f > localB->scale) {
      localB->t_g = localB->scale / localB->absxk_f;
      y = y * localB->t_g * localB->t_g + 1.0;
      localB->scale = localB->absxk_f;
    } else {
      localB->t_g = localB->absxk_f / localB->scale;
      y += localB->t_g * localB->t_g;
    }
  }

  return localB->scale * sqrt(y);
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = sqrt(b * b + 1.0) * a;
  } else if (rtIsNaN(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

// Function for MATLAB Function: '<S26>/Discrete-Time SqrtKF - Calculate SLMZ'
void c6_formation_ros2::c6_formation_ros2_xgemv(int32_T m, int32_T n, const
  real_T A[50], int32_T ia0, const real_T x[50], int32_T ix0, real_T y[5],
  B_CalculatePL_c6_formation_ro_T *localB)
{
  if (n != 0) {
    int32_T b;
    memset(&y[0], 0, static_cast<uint8_T>(n) * sizeof(real_T));
    b = (n - 1) * 10 + ia0;
    for (int32_T b_iy = ia0; b_iy <= b; b_iy += 10) {
      int32_T e;
      int32_T ia;
      localB->c_d = 0.0;
      e = (b_iy + m) - 1;
      for (ia = b_iy; ia <= e; ia++) {
        localB->c_d += x[((ix0 + ia) - b_iy) - 1] * A[ia - 1];
      }

      ia = div_nde_s32_floor(b_iy - ia0, 10);
      y[ia] += localB->c_d;
    }
  }
}

// Function for MATLAB Function: '<S26>/Discrete-Time SqrtKF - Calculate SLMZ'
void c6_formation_ros2::c6_formation_ros2_xgerc(int32_T m, int32_T n, real_T
  alpha1, int32_T ix0, const real_T y[5], real_T A[50], int32_T ia0,
  B_CalculatePL_c6_formation_ro_T *localB)
{
  if (!(alpha1 == 0.0)) {
    int32_T b;
    localB->jA_j = ia0;
    b = static_cast<uint8_T>(n);
    for (int32_T j = 0; j < b; j++) {
      localB->temp_l = y[j];
      if (localB->temp_l != 0.0) {
        int32_T c;
        localB->temp_l *= alpha1;
        c = m + localB->jA_j;
        for (int32_T ijA = localB->jA_j; ijA < c; ijA++) {
          A[ijA - 1] += A[((ix0 + ijA) - localB->jA_j) - 1] * localB->temp_l;
        }
      }

      localB->jA_j += 10;
    }
  }
}

// Function for MATLAB Function: '<S26>/Discrete-Time SqrtKF - Calculate SLMZ'
void c6_formation_ros2::c6_formation_ros2_qrFactor(const real_T A[25], real_T S
  [25], const real_T Ns[25], B_CalculatePL_c6_formation_ro_T *localB)
{
  __m128d tmp;
  int32_T exitg1;
  boolean_T exitg2;
  for (localB->j = 0; localB->j < 5; localB->j++) {
    for (localB->ii = 0; localB->ii < 5; localB->ii++) {
      localB->aoffset = localB->ii * 5;
      localB->s_p = 0.0;
      for (localB->lastv = 0; localB->lastv < 5; localB->lastv++) {
        localB->s_p += A[localB->lastv * 5 + localB->j] * S[localB->aoffset +
          localB->lastv];
      }

      localB->lastv = 10 * localB->j + localB->ii;
      localB->b_A[localB->lastv] = localB->s_p;
      localB->b_A[localB->lastv + 5] = Ns[5 * localB->ii + localB->j];
    }

    localB->work[localB->j] = 0.0;
  }

  for (localB->j = 0; localB->j < 5; localB->j++) {
    localB->ii = localB->j * 10 + localB->j;
    localB->atmp = localB->b_A[localB->ii];
    localB->lastv = localB->ii + 2;
    localB->tau[localB->j] = 0.0;
    localB->s_p = c6_formation_ros2_xnrm2(9 - localB->j, localB->b_A, localB->ii
      + 2, localB);
    if (localB->s_p != 0.0) {
      localB->b_A_c = localB->b_A[localB->ii];
      localB->s_p = rt_hypotd_snf(localB->b_A_c, localB->s_p);
      if (localB->b_A_c >= 0.0) {
        localB->s_p = -localB->s_p;
      }

      if (fabs(localB->s_p) < 1.0020841800044864E-292) {
        localB->aoffset = 0;
        localB->coltop = (localB->ii - localB->j) + 10;
        do {
          localB->aoffset++;
          localB->scalarLB = (((((localB->coltop - localB->ii) - 1) / 2) << 1) +
                              localB->ii) + 2;
          localB->vectorUB_b = localB->scalarLB - 2;
          for (localB->c_k = localB->lastv; localB->c_k <= localB->vectorUB_b;
               localB->c_k += 2) {
            tmp = _mm_loadu_pd(&localB->b_A[localB->c_k - 1]);
            _mm_storeu_pd(&localB->b_A[localB->c_k - 1], _mm_mul_pd(tmp,
              _mm_set1_pd(9.9792015476736E+291)));
          }

          for (localB->c_k = localB->scalarLB; localB->c_k <= localB->coltop;
               localB->c_k++) {
            localB->b_A[localB->c_k - 1] *= 9.9792015476736E+291;
          }

          localB->s_p *= 9.9792015476736E+291;
          localB->atmp *= 9.9792015476736E+291;
        } while ((fabs(localB->s_p) < 1.0020841800044864E-292) &&
                 (localB->aoffset < 20));

        localB->s_p = rt_hypotd_snf(localB->atmp, c6_formation_ros2_xnrm2(9 -
          localB->j, localB->b_A, localB->ii + 2, localB));
        if (localB->atmp >= 0.0) {
          localB->s_p = -localB->s_p;
        }

        localB->tau[localB->j] = (localB->s_p - localB->atmp) / localB->s_p;
        localB->atmp = 1.0 / (localB->atmp - localB->s_p);
        for (localB->c_k = localB->lastv; localB->c_k <= localB->vectorUB_b;
             localB->c_k += 2) {
          tmp = _mm_loadu_pd(&localB->b_A[localB->c_k - 1]);
          _mm_storeu_pd(&localB->b_A[localB->c_k - 1], _mm_mul_pd(tmp,
            _mm_set1_pd(localB->atmp)));
        }

        for (localB->c_k = localB->scalarLB; localB->c_k <= localB->coltop;
             localB->c_k++) {
          localB->b_A[localB->c_k - 1] *= localB->atmp;
        }

        for (localB->lastv = 0; localB->lastv < localB->aoffset; localB->lastv++)
        {
          localB->s_p *= 1.0020841800044864E-292;
        }

        localB->atmp = localB->s_p;
      } else {
        localB->tau[localB->j] = (localB->s_p - localB->b_A_c) / localB->s_p;
        localB->atmp = 1.0 / (localB->b_A_c - localB->s_p);
        localB->coltop = (localB->ii - localB->j) + 10;
        localB->scalarLB = (((((localB->coltop - localB->ii) - 1) / 2) << 1) +
                            localB->ii) + 2;
        localB->vectorUB_b = localB->scalarLB - 2;
        for (localB->aoffset = localB->lastv; localB->aoffset <=
             localB->vectorUB_b; localB->aoffset += 2) {
          tmp = _mm_loadu_pd(&localB->b_A[localB->aoffset - 1]);
          _mm_storeu_pd(&localB->b_A[localB->aoffset - 1], _mm_mul_pd(tmp,
            _mm_set1_pd(localB->atmp)));
        }

        for (localB->aoffset = localB->scalarLB; localB->aoffset <=
             localB->coltop; localB->aoffset++) {
          localB->b_A[localB->aoffset - 1] *= localB->atmp;
        }

        localB->atmp = localB->s_p;
      }
    }

    localB->b_A[localB->ii] = localB->atmp;
    if (localB->j + 1 < 5) {
      localB->b_A[localB->ii] = 1.0;
      if (localB->tau[localB->j] != 0.0) {
        localB->lastv = 10 - localB->j;
        localB->aoffset = (localB->ii - localB->j) + 9;
        while ((localB->lastv > 0) && (localB->b_A[localB->aoffset] == 0.0)) {
          localB->lastv--;
          localB->aoffset--;
        }

        localB->aoffset = 4 - localB->j;
        exitg2 = false;
        while ((!exitg2) && (localB->aoffset > 0)) {
          localB->coltop = ((localB->aoffset - 1) * 10 + localB->ii) + 10;
          localB->scalarLB = localB->coltop;
          do {
            exitg1 = 0;
            if (localB->scalarLB + 1 <= localB->coltop + localB->lastv) {
              if (localB->b_A[localB->scalarLB] != 0.0) {
                exitg1 = 1;
              } else {
                localB->scalarLB++;
              }
            } else {
              localB->aoffset--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        localB->lastv = 0;
        localB->aoffset = 0;
      }

      if (localB->lastv > 0) {
        c6_formation_ros2_xgemv(localB->lastv, localB->aoffset, localB->b_A,
          localB->ii + 11, localB->b_A, localB->ii + 1, localB->work, localB);
        c6_formation_ros2_xgerc(localB->lastv, localB->aoffset, -localB->
          tau[localB->j], localB->ii + 1, localB->work, localB->b_A, localB->ii
          + 11, localB);
      }

      localB->b_A[localB->ii] = localB->atmp;
    }
  }

  for (localB->j = 0; localB->j < 5; localB->j++) {
    for (localB->ii = 0; localB->ii <= localB->j; localB->ii++) {
      localB->y[localB->ii + 5 * localB->j] = localB->b_A[10 * localB->j +
        localB->ii];
    }

    for (localB->ii = localB->j + 2; localB->ii < 6; localB->ii++) {
      localB->y[(localB->ii + 5 * localB->j) - 1] = 0.0;
    }
  }

  for (localB->j = 0; localB->j < 5; localB->j++) {
    for (localB->ii = 0; localB->ii < 5; localB->ii++) {
      S[localB->ii + 5 * localB->j] = localB->y[5 * localB->ii + localB->j];
    }
  }
}

// Function for MATLAB Function: '<S26>/Discrete-Time SqrtKF - Calculate SLMZ'
void c6_formation_ros2::c6_formation_ros2_trisolve(const real_T A[25], real_T B
  [25], B_CalculatePL_c6_formation_ro_T *localB)
{
  for (int32_T j = 0; j < 5; j++) {
    int32_T jBcol;
    jBcol = 5 * j;
    for (int32_T b_k = 0; b_k < 5; b_k++) {
      int32_T B_tmp;
      int32_T kAcol;
      kAcol = 5 * b_k;
      B_tmp = b_k + jBcol;
      localB->B = B[B_tmp];
      if (localB->B != 0.0) {
        B[B_tmp] = localB->B / A[b_k + kAcol];
        for (int32_T i = b_k + 2; i < 6; i++) {
          int32_T tmp;
          tmp = (i + jBcol) - 1;
          B[tmp] -= A[(i + kAcol) - 1] * B[B_tmp];
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S26>/Discrete-Time SqrtKF - Calculate SLMZ'
void c6_formation_ros2::c6_formation_ros2_linsolve(const real_T A[25], const
  real_T B[25], real_T C[25], B_CalculatePL_c6_formation_ro_T *localB)
{
  memcpy(&C[0], &B[0], 25U * sizeof(real_T));
  c6_formation_ros2_trisolve(A, C, localB);
}

// Function for MATLAB Function: '<S26>/Discrete-Time SqrtKF - Calculate SLMZ'
void c6_formation_ros2::c6_formation_ros2_trisolve_f(const real_T A[25], real_T
  B[25], B_CalculatePL_c6_formation_ro_T *localB)
{
  for (int32_T j = 0; j < 5; j++) {
    int32_T jBcol;
    jBcol = 5 * j;
    for (int32_T k = 4; k >= 0; k--) {
      int32_T kAcol;
      int32_T tmp;
      kAcol = 5 * k;
      tmp = k + jBcol;
      localB->d = B[tmp];
      if (localB->d != 0.0) {
        B[tmp] = localB->d / A[k + kAcol];
        for (int32_T i = 0; i < k; i++) {
          int32_T tmp_0;
          tmp_0 = i + jBcol;
          B[tmp_0] -= A[i + kAcol] * B[tmp];
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S26>/Discrete-Time SqrtKF - Calculate SLMZ'
void c6_formation_ros2::c6_formation_ros2_linsolve_h(const real_T A[25], const
  real_T B[25], real_T C[25], B_CalculatePL_c6_formation_ro_T *localB)
{
  memcpy(&C[0], &B[0], 25U * sizeof(real_T));
  c6_formation_ros2_trisolve_f(A, C, localB);
}

// Function for MATLAB Function: '<S26>/Discrete-Time SqrtKF - Calculate SLMZ'
real_T c6_formation_ros2::c6_formation_ros2_xnrm2_a(int32_T n, const real_T x[25],
  int32_T ix0, B_CalculatePL_c6_formation_ro_T *localB)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      int32_T kend;
      localB->scale_p = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (int32_T k = ix0; k <= kend; k++) {
        localB->absxk_l = fabs(x[k - 1]);
        if (localB->absxk_l > localB->scale_p) {
          localB->t_j = localB->scale_p / localB->absxk_l;
          y = y * localB->t_j * localB->t_j + 1.0;
          localB->scale_p = localB->absxk_l;
        } else {
          localB->t_j = localB->absxk_l / localB->scale_p;
          y += localB->t_j * localB->t_j;
        }
      }

      y = localB->scale_p * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S26>/Discrete-Time SqrtKF - Calculate SLMZ'
real_T c6_formation_ros2::c6_formation_ros2_xdotc(int32_T n, const real_T x[25],
  int32_T ix0, const real_T y[25], int32_T iy0)
{
  real_T d;
  int32_T b;
  d = 0.0;
  b = static_cast<uint8_T>(n);
  for (int32_T k = 0; k < b; k++) {
    d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
  }

  return d;
}

// Function for MATLAB Function: '<S26>/Discrete-Time SqrtKF - Calculate SLMZ'
void c6_formation_ros2::c6_formation_ros2_xaxpy(int32_T n, real_T a, int32_T ix0,
  real_T y[25], int32_T iy0)
{
  if (!(a == 0.0)) {
    for (int32_T k = 0; k < n; k++) {
      int32_T tmp;
      tmp = (iy0 + k) - 1;
      y[tmp] += y[(ix0 + k) - 1] * a;
    }
  }
}

// Function for MATLAB Function: '<S26>/Discrete-Time SqrtKF - Calculate SLMZ'
real_T c6_formation_ros2::c6_formation_ros2_xnrm2_az(int32_T n, const real_T x[5],
  int32_T ix0, B_CalculatePL_c6_formation_ro_T *localB)
{
  real_T y;
  int32_T kend;
  y = 0.0;
  localB->scale_d = 3.3121686421112381E-170;
  kend = (ix0 + n) - 1;
  for (int32_T k = ix0; k <= kend; k++) {
    localB->absxk_g = fabs(x[k - 1]);
    if (localB->absxk_g > localB->scale_d) {
      real_T t;
      t = localB->scale_d / localB->absxk_g;
      y = y * t * t + 1.0;
      localB->scale_d = localB->absxk_g;
    } else {
      real_T t;
      t = localB->absxk_g / localB->scale_d;
      y += t * t;
    }
  }

  return localB->scale_d * sqrt(y);
}

// Function for MATLAB Function: '<S26>/Discrete-Time SqrtKF - Calculate SLMZ'
void c6_formation_ros2::c6_formation_ros2_xrotg(real_T *a, real_T *b, real_T *c,
  real_T *s, B_CalculatePL_c6_formation_ro_T *localB)
{
  localB->roe = *b;
  localB->absa = fabs(*a);
  localB->absb = fabs(*b);
  if (localB->absa > localB->absb) {
    localB->roe = *a;
  }

  localB->scale_g = localB->absa + localB->absb;
  if (localB->scale_g == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *a = 0.0;
    *b = 0.0;
  } else {
    localB->ads = localB->absa / localB->scale_g;
    localB->bds = localB->absb / localB->scale_g;
    localB->scale_g *= sqrt(localB->ads * localB->ads + localB->bds *
      localB->bds);
    if (localB->roe < 0.0) {
      localB->scale_g = -localB->scale_g;
    }

    *c = *a / localB->scale_g;
    *s = *b / localB->scale_g;
    if (localB->absa > localB->absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }

    *a = localB->scale_g;
  }
}

// Function for MATLAB Function: '<S26>/Discrete-Time SqrtKF - Calculate SLMZ'
void c6_formation_ros2::c6_formation_ros2_xrot(real_T x[25], int32_T ix0,
  int32_T iy0, real_T c, real_T s, B_CalculatePL_c6_formation_ro_T *localB)
{
  for (int32_T k = 0; k < 5; k++) {
    int32_T temp_tmp_tmp;
    int32_T temp_tmp_tmp_0;
    temp_tmp_tmp = (iy0 + k) - 1;
    localB->temp_tmp = x[temp_tmp_tmp];
    temp_tmp_tmp_0 = (ix0 + k) - 1;
    localB->temp_tmp_d = x[temp_tmp_tmp_0];
    x[temp_tmp_tmp] = localB->temp_tmp * c - localB->temp_tmp_d * s;
    x[temp_tmp_tmp_0] = localB->temp_tmp_d * c + localB->temp_tmp * s;
  }
}

// Function for MATLAB Function: '<S26>/Discrete-Time SqrtKF - Calculate SLMZ'
void c6_formation_ros2::c6_formation_ros2_xaxpy_b(int32_T n, real_T a, const
  real_T x[25], int32_T ix0, real_T y[5], int32_T iy0,
  B_CalculatePL_c6_formation_ro_T *localB)
{
  if (!(a == 0.0)) {
    localB->scalarLB_d = (n / 2) << 1;
    localB->vectorUB_e = localB->scalarLB_d - 2;
    for (localB->k_b = 0; localB->k_b <= localB->vectorUB_e; localB->k_b += 2) {
      __m128d tmp;
      localB->i1 = (iy0 + localB->k_b) - 1;
      tmp = _mm_loadu_pd(&y[localB->i1]);
      _mm_storeu_pd(&y[localB->i1], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&x[(ix0 +
        localB->k_b) - 1]), _mm_set1_pd(a)), tmp));
    }

    for (localB->k_b = localB->scalarLB_d; localB->k_b < n; localB->k_b++) {
      localB->i1 = (iy0 + localB->k_b) - 1;
      y[localB->i1] += x[(ix0 + localB->k_b) - 1] * a;
    }
  }
}

// Function for MATLAB Function: '<S26>/Discrete-Time SqrtKF - Calculate SLMZ'
void c6_formation_ros2::c6_formation_ros2_xaxpy_b5(int32_T n, real_T a, const
  real_T x[5], int32_T ix0, real_T y[25], int32_T iy0,
  B_CalculatePL_c6_formation_ro_T *localB)
{
  if (!(a == 0.0)) {
    localB->scalarLB_n = (n / 2) << 1;
    localB->vectorUB = localB->scalarLB_n - 2;
    for (localB->k = 0; localB->k <= localB->vectorUB; localB->k += 2) {
      __m128d tmp;
      localB->i_bs = (iy0 + localB->k) - 1;
      tmp = _mm_loadu_pd(&y[localB->i_bs]);
      _mm_storeu_pd(&y[localB->i_bs], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&x[(ix0
        + localB->k) - 1]), _mm_set1_pd(a)), tmp));
    }

    for (localB->k = localB->scalarLB_n; localB->k < n; localB->k++) {
      localB->i_bs = (iy0 + localB->k) - 1;
      y[localB->i_bs] += x[(ix0 + localB->k) - 1] * a;
    }
  }
}

// Function for MATLAB Function: '<S26>/Discrete-Time SqrtKF - Calculate SLMZ'
void c6_formation_ros2::c6_formation_ros2_xswap(real_T x[25], int32_T ix0,
  int32_T iy0, B_CalculatePL_c6_formation_ro_T *localB)
{
  for (int32_T k = 0; k < 5; k++) {
    int32_T temp_tmp;
    int32_T tmp;
    temp_tmp = (ix0 + k) - 1;
    localB->temp_lx = x[temp_tmp];
    tmp = (iy0 + k) - 1;
    x[temp_tmp] = x[tmp];
    x[tmp] = localB->temp_lx;
  }
}

// Function for MATLAB Function: '<S26>/Discrete-Time SqrtKF - Calculate SLMZ'
void c6_formation_ros2::c6_formation_ros2_svd(const real_T A[25], real_T U[25],
  real_T s[5], real_T V[25], B_CalculatePL_c6_formation_ro_T *localB)
{
  __m128d tmp;
  boolean_T exitg1;
  memcpy(&localB->b_A_m[0], &A[0], 25U * sizeof(real_T));
  for (localB->i_b = 0; localB->i_b < 5; localB->i_b++) {
    localB->b_s[localB->i_b] = 0.0;
    localB->e[localB->i_b] = 0.0;
    localB->work_c[localB->i_b] = 0.0;
  }

  memset(&U[0], 0, 25U * sizeof(real_T));
  memset(&V[0], 0, 25U * sizeof(real_T));
  for (localB->i_b = 0; localB->i_b < 4; localB->i_b++) {
    localB->qp1 = localB->i_b + 2;
    localB->qq_tmp = 5 * localB->i_b + localB->i_b;
    localB->qq = localB->qq_tmp + 1;
    localB->apply_transform = false;
    localB->nrm = c6_formation_ros2_xnrm2_a(5 - localB->i_b, localB->b_A_m,
      localB->qq_tmp + 1, localB);
    if (localB->nrm > 0.0) {
      localB->apply_transform = true;
      if (localB->b_A_m[localB->qq_tmp] < 0.0) {
        localB->nrm = -localB->nrm;
      }

      localB->b_s[localB->i_b] = localB->nrm;
      if (fabs(localB->nrm) >= 1.0020841800044864E-292) {
        localB->nrm = 1.0 / localB->nrm;
        localB->h = (localB->qq_tmp - localB->i_b) + 5;
        localB->qjj = ((((localB->h - localB->qq_tmp) / 2) << 1) +
                       localB->qq_tmp) + 1;
        localB->kase = localB->qjj - 2;
        for (localB->e_k = localB->qq; localB->e_k <= localB->kase; localB->e_k +=
             2) {
          tmp = _mm_loadu_pd(&localB->b_A_m[localB->e_k - 1]);
          _mm_storeu_pd(&localB->b_A_m[localB->e_k - 1], _mm_mul_pd(tmp,
            _mm_set1_pd(localB->nrm)));
        }

        for (localB->e_k = localB->qjj; localB->e_k <= localB->h; localB->e_k++)
        {
          localB->b_A_m[localB->e_k - 1] *= localB->nrm;
        }
      } else {
        localB->h = (localB->qq_tmp - localB->i_b) + 5;
        localB->qjj = ((((localB->h - localB->qq_tmp) / 2) << 1) +
                       localB->qq_tmp) + 1;
        localB->kase = localB->qjj - 2;
        for (localB->e_k = localB->qq; localB->e_k <= localB->kase; localB->e_k +=
             2) {
          tmp = _mm_loadu_pd(&localB->b_A_m[localB->e_k - 1]);
          _mm_storeu_pd(&localB->b_A_m[localB->e_k - 1], _mm_div_pd(tmp,
            _mm_set1_pd(localB->b_s[localB->i_b])));
        }

        for (localB->e_k = localB->qjj; localB->e_k <= localB->h; localB->e_k++)
        {
          localB->b_A_m[localB->e_k - 1] /= localB->b_s[localB->i_b];
        }
      }

      localB->b_A_m[localB->qq_tmp]++;
      localB->b_s[localB->i_b] = -localB->b_s[localB->i_b];
    } else {
      localB->b_s[localB->i_b] = 0.0;
    }

    for (localB->kase = localB->qp1; localB->kase < 6; localB->kase++) {
      localB->qjj = (localB->kase - 1) * 5 + localB->i_b;
      if (localB->apply_transform) {
        c6_formation_ros2_xaxpy(5 - localB->i_b, -(c6_formation_ros2_xdotc(5 -
          localB->i_b, localB->b_A_m, localB->qq_tmp + 1, localB->b_A_m,
          localB->qjj + 1) / localB->b_A_m[localB->qq_tmp]), localB->qq_tmp + 1,
          localB->b_A_m, localB->qjj + 1);
      }

      localB->e[localB->kase - 1] = localB->b_A_m[localB->qjj];
    }

    for (localB->kase = localB->i_b + 1; localB->kase < 6; localB->kase++) {
      localB->qjj = (5 * localB->i_b + localB->kase) - 1;
      U[localB->qjj] = localB->b_A_m[localB->qjj];
    }

    if (localB->i_b + 1 <= 3) {
      localB->nrm = c6_formation_ros2_xnrm2_az(4 - localB->i_b, localB->e,
        localB->i_b + 2, localB);
      if (localB->nrm == 0.0) {
        localB->e[localB->i_b] = 0.0;
      } else {
        if (localB->e[localB->i_b + 1] < 0.0) {
          localB->e[localB->i_b] = -localB->nrm;
        } else {
          localB->e[localB->i_b] = localB->nrm;
        }

        localB->nrm = localB->e[localB->i_b];
        if (fabs(localB->e[localB->i_b]) >= 1.0020841800044864E-292) {
          localB->nrm = 1.0 / localB->e[localB->i_b];
          localB->qjj = ((((4 - localB->i_b) / 2) << 1) + localB->i_b) + 2;
          localB->kase = localB->qjj - 2;
          for (localB->qq = localB->qp1; localB->qq <= localB->kase; localB->qq +=
               2) {
            tmp = _mm_loadu_pd(&localB->e[localB->qq - 1]);
            _mm_storeu_pd(&localB->e[localB->qq - 1], _mm_mul_pd(tmp,
              _mm_set1_pd(localB->nrm)));
          }

          for (localB->qq = localB->qjj; localB->qq < 6; localB->qq++) {
            localB->e[localB->qq - 1] *= localB->nrm;
          }
        } else {
          localB->qjj = ((((4 - localB->i_b) / 2) << 1) + localB->i_b) + 2;
          localB->kase = localB->qjj - 2;
          for (localB->qq = localB->qp1; localB->qq <= localB->kase; localB->qq +=
               2) {
            tmp = _mm_loadu_pd(&localB->e[localB->qq - 1]);
            _mm_storeu_pd(&localB->e[localB->qq - 1], _mm_div_pd(tmp,
              _mm_set1_pd(localB->nrm)));
          }

          for (localB->qq = localB->qjj; localB->qq < 6; localB->qq++) {
            localB->e[localB->qq - 1] /= localB->nrm;
          }
        }

        localB->e[localB->i_b + 1]++;
        localB->e[localB->i_b] = -localB->e[localB->i_b];
        for (localB->qjj = localB->qp1; localB->qjj < 6; localB->qjj++) {
          localB->work_c[localB->qjj - 1] = 0.0;
        }

        for (localB->qjj = localB->qp1; localB->qjj < 6; localB->qjj++) {
          c6_formation_ros2_xaxpy_b(4 - localB->i_b, localB->e[localB->qjj - 1],
            localB->b_A_m, (localB->i_b + 5 * (localB->qjj - 1)) + 2,
            localB->work_c, localB->i_b + 2, localB);
        }

        for (localB->qjj = localB->qp1; localB->qjj < 6; localB->qjj++) {
          c6_formation_ros2_xaxpy_b5(4 - localB->i_b, -localB->e[localB->qjj - 1]
            / localB->e[localB->i_b + 1], localB->work_c, localB->i_b + 2,
            localB->b_A_m, (localB->i_b + 5 * (localB->qjj - 1)) + 2, localB);
        }
      }

      for (localB->qjj = localB->qp1; localB->qjj < 6; localB->qjj++) {
        V[(localB->qjj + 5 * localB->i_b) - 1] = localB->e[localB->qjj - 1];
      }
    }
  }

  localB->i_b = 3;
  localB->b_s[4] = localB->b_A_m[24];
  localB->e[3] = localB->b_A_m[23];
  localB->e[4] = 0.0;
  for (localB->qp1 = 0; localB->qp1 < 5; localB->qp1++) {
    U[localB->qp1 + 20] = 0.0;
  }

  U[24] = 1.0;
  for (localB->qp1 = 3; localB->qp1 >= 0; localB->qp1--) {
    localB->qq = 5 * localB->qp1 + localB->qp1;
    if (localB->b_s[localB->qp1] != 0.0) {
      for (localB->kase = localB->qp1 + 2; localB->kase < 6; localB->kase++) {
        localB->qjj = ((localB->kase - 1) * 5 + localB->qp1) + 1;
        c6_formation_ros2_xaxpy(5 - localB->qp1, -(c6_formation_ros2_xdotc(5 -
          localB->qp1, U, localB->qq + 1, U, localB->qjj) / U[localB->qq]),
          localB->qq + 1, U, localB->qjj);
      }

      for (localB->kase = localB->qp1 + 1; localB->kase < 6; localB->kase++) {
        localB->qjj = (5 * localB->qp1 + localB->kase) - 1;
        U[localB->qjj] = -U[localB->qjj];
      }

      U[localB->qq]++;
      for (localB->qjj = 0; localB->qjj < localB->qp1; localB->qjj++) {
        U[localB->qjj + 5 * localB->qp1] = 0.0;
      }
    } else {
      for (localB->qjj = 0; localB->qjj < 5; localB->qjj++) {
        U[localB->qjj + 5 * localB->qp1] = 0.0;
      }

      U[localB->qq] = 1.0;
    }
  }

  for (localB->qp1 = 4; localB->qp1 >= 0; localB->qp1--) {
    if ((localB->qp1 + 1 <= 3) && (localB->e[localB->qp1] != 0.0)) {
      localB->qjj = (5 * localB->qp1 + localB->qp1) + 2;
      for (localB->kase = localB->qp1 + 2; localB->kase < 6; localB->kase++) {
        localB->qq = ((localB->kase - 1) * 5 + localB->qp1) + 2;
        c6_formation_ros2_xaxpy(4 - localB->qp1, -(c6_formation_ros2_xdotc(4 -
          localB->qp1, V, localB->qjj, V, localB->qq) / V[localB->qjj - 1]),
          localB->qjj, V, localB->qq);
      }
    }

    for (localB->qjj = 0; localB->qjj < 5; localB->qjj++) {
      V[localB->qjj + 5 * localB->qp1] = 0.0;
    }

    V[localB->qp1 + 5 * localB->qp1] = 1.0;
  }

  localB->qp1 = 0;
  localB->nrm = 0.0;
  for (localB->qq = 0; localB->qq < 5; localB->qq++) {
    localB->r = localB->b_s[localB->qq];
    if (localB->r != 0.0) {
      localB->rt = fabs(localB->r);
      localB->r /= localB->rt;
      localB->b_s[localB->qq] = localB->rt;
      if (localB->qq + 1 < 5) {
        localB->e[localB->qq] /= localB->r;
      }

      localB->qq_tmp = 5 * localB->qq + 1;
      localB->qjj = 4 + localB->qq_tmp;
      localB->kase = localB->qq_tmp + 2;
      for (localB->h = localB->qq_tmp; localB->h <= localB->kase; localB->h += 2)
      {
        tmp = _mm_loadu_pd(&U[localB->h - 1]);
        _mm_storeu_pd(&U[localB->h - 1], _mm_mul_pd(tmp, _mm_set1_pd(localB->r)));
      }

      for (localB->h = localB->qjj; localB->h <= localB->qq_tmp + 4; localB->h++)
      {
        U[localB->h - 1] *= localB->r;
      }
    }

    if (localB->qq + 1 < 5) {
      localB->r = localB->e[localB->qq];
      if (localB->r != 0.0) {
        localB->rt = fabs(localB->r);
        localB->r = localB->rt / localB->r;
        localB->e[localB->qq] = localB->rt;
        localB->b_s[localB->qq + 1] *= localB->r;
        localB->qq_tmp = (localB->qq + 1) * 5 + 1;
        localB->qjj = 4 + localB->qq_tmp;
        localB->kase = localB->qq_tmp + 2;
        for (localB->h = localB->qq_tmp; localB->h <= localB->kase; localB->h +=
             2) {
          tmp = _mm_loadu_pd(&V[localB->h - 1]);
          _mm_storeu_pd(&V[localB->h - 1], _mm_mul_pd(tmp, _mm_set1_pd(localB->r)));
        }

        for (localB->h = localB->qjj; localB->h <= localB->qq_tmp + 4; localB->h
             ++) {
          V[localB->h - 1] *= localB->r;
        }
      }
    }

    localB->r = fabs(localB->b_s[localB->qq]);
    localB->rt = fabs(localB->e[localB->qq]);
    if ((localB->r >= localB->rt) || rtIsNaN(localB->rt)) {
      localB->rt = localB->r;
    }

    if ((!(localB->nrm >= localB->rt)) && (!rtIsNaN(localB->rt))) {
      localB->nrm = localB->rt;
    }
  }

  while ((localB->i_b + 2 > 0) && (localB->qp1 < 75)) {
    localB->qq = localB->i_b + 1;
    exitg1 = false;
    while (!(exitg1 || (localB->qq == 0))) {
      localB->rt = fabs(localB->e[localB->qq - 1]);
      if (localB->rt <= (fabs(localB->b_s[localB->qq - 1]) + fabs(localB->
            b_s[localB->qq])) * 2.2204460492503131E-16) {
        localB->e[localB->qq - 1] = 0.0;
        exitg1 = true;
      } else if ((localB->rt <= 1.0020841800044864E-292) || ((localB->qp1 > 20) &&
                  (localB->rt <= 2.2204460492503131E-16 * localB->nrm))) {
        localB->e[localB->qq - 1] = 0.0;
        exitg1 = true;
      } else {
        localB->qq--;
      }
    }

    if (localB->i_b + 1 == localB->qq) {
      localB->kase = 4;
    } else {
      localB->qjj = localB->i_b + 2;
      localB->kase = localB->i_b + 2;
      exitg1 = false;
      while ((!exitg1) && (localB->kase >= localB->qq)) {
        localB->qjj = localB->kase;
        if (localB->kase == localB->qq) {
          exitg1 = true;
        } else {
          localB->rt = 0.0;
          if (localB->kase < localB->i_b + 2) {
            localB->rt = fabs(localB->e[localB->kase - 1]);
          }

          if (localB->kase > localB->qq + 1) {
            localB->rt += fabs(localB->e[localB->kase - 2]);
          }

          localB->r = fabs(localB->b_s[localB->kase - 1]);
          if ((localB->r <= 2.2204460492503131E-16 * localB->rt) || (localB->r <=
               1.0020841800044864E-292)) {
            localB->b_s[localB->kase - 1] = 0.0;
            exitg1 = true;
          } else {
            localB->kase--;
          }
        }
      }

      if (localB->qjj == localB->qq) {
        localB->kase = 3;
      } else if (localB->i_b + 2 == localB->qjj) {
        localB->kase = 1;
      } else {
        localB->kase = 2;
        localB->qq = localB->qjj;
      }
    }

    switch (localB->kase) {
     case 1:
      localB->rt = localB->e[localB->i_b];
      localB->e[localB->i_b] = 0.0;
      for (localB->qjj = localB->i_b + 1; localB->qjj >= localB->qq + 1;
           localB->qjj--) {
        c6_formation_ros2_xrotg(&localB->b_s[localB->qjj - 1], &localB->rt,
          &localB->sqds, &localB->smm1, localB);
        if (localB->qjj > localB->qq + 1) {
          localB->r = localB->e[localB->qjj - 2];
          localB->rt = -localB->smm1 * localB->r;
          localB->e[localB->qjj - 2] = localB->r * localB->sqds;
        }

        c6_formation_ros2_xrot(V, 5 * (localB->qjj - 1) + 1, 5 * (localB->i_b +
          1) + 1, localB->sqds, localB->smm1, localB);
      }
      break;

     case 2:
      localB->rt = localB->e[localB->qq - 1];
      localB->e[localB->qq - 1] = 0.0;
      for (localB->qjj = localB->qq + 1; localB->qjj <= localB->i_b + 2;
           localB->qjj++) {
        c6_formation_ros2_xrotg(&localB->b_s[localB->qjj - 1], &localB->rt,
          &localB->sqds, &localB->smm1, localB);
        localB->r = localB->e[localB->qjj - 1];
        localB->rt = -localB->smm1 * localB->r;
        localB->e[localB->qjj - 1] = localB->r * localB->sqds;
        c6_formation_ros2_xrot(U, 5 * (localB->qjj - 1) + 1, 5 * (localB->qq - 1)
          + 1, localB->sqds, localB->smm1, localB);
      }
      break;

     case 3:
      localB->sqds = localB->b_s[localB->i_b + 1];
      localB->r = fabs(localB->sqds);
      localB->rt = fabs(localB->b_s[localB->i_b]);
      if ((localB->r >= localB->rt) || rtIsNaN(localB->rt)) {
        localB->rt = localB->r;
      }

      localB->r = fabs(localB->e[localB->i_b]);
      if ((localB->rt >= localB->r) || rtIsNaN(localB->r)) {
        localB->r = localB->rt;
      }

      localB->rt = fabs(localB->b_s[localB->qq]);
      if ((localB->r >= localB->rt) || rtIsNaN(localB->rt)) {
        localB->rt = localB->r;
      }

      localB->r = fabs(localB->e[localB->qq]);
      if ((localB->rt >= localB->r) || rtIsNaN(localB->r)) {
        localB->r = localB->rt;
      }

      localB->rt = localB->sqds / localB->r;
      localB->smm1 = localB->b_s[localB->i_b] / localB->r;
      localB->emm1 = localB->e[localB->i_b] / localB->r;
      localB->sqds = localB->b_s[localB->qq] / localB->r;
      localB->smm1 = ((localB->smm1 + localB->rt) * (localB->smm1 - localB->rt)
                      + localB->emm1 * localB->emm1) / 2.0;
      localB->emm1 *= localB->rt;
      localB->emm1 *= localB->emm1;
      if ((localB->smm1 != 0.0) || (localB->emm1 != 0.0)) {
        localB->shift = sqrt(localB->smm1 * localB->smm1 + localB->emm1);
        if (localB->smm1 < 0.0) {
          localB->shift = -localB->shift;
        }

        localB->shift = localB->emm1 / (localB->smm1 + localB->shift);
      } else {
        localB->shift = 0.0;
      }

      localB->rt = (localB->sqds + localB->rt) * (localB->sqds - localB->rt) +
        localB->shift;
      localB->r = localB->e[localB->qq] / localB->r * localB->sqds;
      for (localB->qq_tmp = localB->qq + 1; localB->qq_tmp <= localB->i_b + 1;
           localB->qq_tmp++) {
        c6_formation_ros2_xrotg(&localB->rt, &localB->r, &localB->sqds,
          &localB->smm1, localB);
        if (localB->qq_tmp > localB->qq + 1) {
          localB->e[localB->qq_tmp - 2] = localB->rt;
        }

        localB->emm1 = localB->e[localB->qq_tmp - 1];
        localB->r = localB->b_s[localB->qq_tmp - 1];
        localB->e[localB->qq_tmp - 1] = localB->emm1 * localB->sqds - localB->r *
          localB->smm1;
        localB->rt = localB->smm1 * localB->b_s[localB->qq_tmp];
        localB->b_s[localB->qq_tmp] *= localB->sqds;
        localB->qjj = (localB->qq_tmp - 1) * 5 + 1;
        localB->kase = 5 * localB->qq_tmp + 1;
        c6_formation_ros2_xrot(V, localB->qjj, localB->kase, localB->sqds,
          localB->smm1, localB);
        localB->b_s[localB->qq_tmp - 1] = localB->r * localB->sqds +
          localB->emm1 * localB->smm1;
        c6_formation_ros2_xrotg(&localB->b_s[localB->qq_tmp - 1], &localB->rt,
          &localB->sqds, &localB->smm1, localB);
        localB->r = localB->e[localB->qq_tmp - 1];
        localB->rt = localB->r * localB->sqds + localB->smm1 * localB->
          b_s[localB->qq_tmp];
        localB->b_s[localB->qq_tmp] = localB->r * -localB->smm1 + localB->sqds *
          localB->b_s[localB->qq_tmp];
        localB->r = localB->smm1 * localB->e[localB->qq_tmp];
        localB->e[localB->qq_tmp] *= localB->sqds;
        c6_formation_ros2_xrot(U, localB->qjj, localB->kase, localB->sqds,
          localB->smm1, localB);
      }

      localB->e[localB->i_b] = localB->rt;
      localB->qp1++;
      break;

     default:
      if (localB->b_s[localB->qq] < 0.0) {
        localB->b_s[localB->qq] = -localB->b_s[localB->qq];
        localB->qp1 = 5 * localB->qq + 1;
        localB->qjj = 4 + localB->qp1;
        localB->kase = localB->qp1 + 2;
        for (localB->qq_tmp = localB->qp1; localB->qq_tmp <= localB->kase;
             localB->qq_tmp += 2) {
          tmp = _mm_loadu_pd(&V[localB->qq_tmp - 1]);
          _mm_storeu_pd(&V[localB->qq_tmp - 1], _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
        }

        for (localB->qq_tmp = localB->qjj; localB->qq_tmp <= localB->qp1 + 4;
             localB->qq_tmp++) {
          V[localB->qq_tmp - 1] = -V[localB->qq_tmp - 1];
        }
      }

      localB->qp1 = localB->qq + 1;
      while ((localB->qq + 1 < 5) && (localB->b_s[localB->qq] < localB->
              b_s[localB->qp1])) {
        localB->rt = localB->b_s[localB->qq];
        localB->b_s[localB->qq] = localB->b_s[localB->qp1];
        localB->b_s[localB->qp1] = localB->rt;
        localB->qjj = 5 * localB->qq + 1;
        localB->kase = (localB->qq + 1) * 5 + 1;
        c6_formation_ros2_xswap(V, localB->qjj, localB->kase, localB);
        c6_formation_ros2_xswap(U, localB->qjj, localB->kase, localB);
        localB->qq = localB->qp1;
        localB->qp1++;
      }

      localB->qp1 = 0;
      localB->i_b--;
      break;
    }
  }

  for (localB->i_b = 0; localB->i_b < 5; localB->i_b++) {
    s[localB->i_b] = localB->b_s[localB->i_b];
  }
}

// Function for MATLAB Function: '<S26>/Discrete-Time SqrtKF - Calculate SLMZ'
void c6_formation_ros2::c6_formation_ros2_xgemv_m(int32_T m, int32_T n, const
  real_T A[25], int32_T ia0, const real_T x[25], int32_T ix0, real_T y[5],
  B_CalculatePL_c6_formation_ro_T *localB)
{
  if (n != 0) {
    int32_T b;
    memset(&y[0], 0, static_cast<uint8_T>(n) * sizeof(real_T));
    b = (n - 1) * 5 + ia0;
    for (int32_T b_iy = ia0; b_iy <= b; b_iy += 5) {
      int32_T e;
      int32_T ia;
      localB->c = 0.0;
      e = (b_iy + m) - 1;
      for (ia = b_iy; ia <= e; ia++) {
        localB->c += x[((ix0 + ia) - b_iy) - 1] * A[ia - 1];
      }

      ia = div_nde_s32_floor(b_iy - ia0, 5);
      y[ia] += localB->c;
    }
  }
}

// Function for MATLAB Function: '<S26>/Discrete-Time SqrtKF - Calculate SLMZ'
void c6_formation_ros2::c6_formation_ros2_xgerc_c(int32_T m, int32_T n, real_T
  alpha1, int32_T ix0, const real_T y[5], real_T A[25], int32_T ia0,
  B_CalculatePL_c6_formation_ro_T *localB)
{
  if (!(alpha1 == 0.0)) {
    int32_T b;
    localB->jA_h = ia0;
    b = static_cast<uint8_T>(n);
    for (int32_T j = 0; j < b; j++) {
      localB->temp = y[j];
      if (localB->temp != 0.0) {
        int32_T c;
        localB->temp *= alpha1;
        c = m + localB->jA_h;
        for (int32_T ijA = localB->jA_h; ijA < c; ijA++) {
          A[ijA - 1] += A[((ix0 + ijA) - localB->jA_h) - 1] * localB->temp;
        }
      }

      localB->jA_h += 5;
    }
  }
}

// Function for MATLAB Function: '<S26>/Discrete-Time SqrtKF - Calculate SLMZ'
void c6_formation_ros2::c6_formation_ros2_qr(const real_T A[25], real_T Q[25],
  real_T R[25], B_CalculatePL_c6_formation_ro_T *localB)
{
  __m128d tmp;
  int32_T exitg1;
  boolean_T exitg2;
  memcpy(&Q[0], &A[0], 25U * sizeof(real_T));
  for (localB->i_l = 0; localB->i_l < 5; localB->i_l++) {
    localB->tau_k[localB->i_l] = 0.0;
    localB->work_cx[localB->i_l] = 0.0;
  }

  for (localB->d_i = 0; localB->d_i < 5; localB->d_i++) {
    localB->i_l = localB->d_i * 5 + localB->d_i;
    if (localB->d_i + 1 < 5) {
      localB->atmp_m = Q[localB->i_l];
      localB->b_lastv = localB->i_l + 2;
      localB->tau_k[localB->d_i] = 0.0;
      localB->beta1 = c6_formation_ros2_xnrm2_a(4 - localB->d_i, Q, localB->i_l
        + 2, localB);
      if (localB->beta1 != 0.0) {
        localB->b_A_n = Q[localB->i_l];
        localB->beta1 = rt_hypotd_snf(localB->b_A_n, localB->beta1);
        if (localB->b_A_n >= 0.0) {
          localB->beta1 = -localB->beta1;
        }

        if (fabs(localB->beta1) < 1.0020841800044864E-292) {
          localB->knt = 0;
          localB->b_coltop = (localB->i_l - localB->d_i) + 5;
          do {
            localB->knt++;
            localB->f = (((((localB->b_coltop - localB->i_l) - 1) / 2) << 1) +
                         localB->i_l) + 2;
            localB->d_k = localB->f - 2;
            for (localB->c_k_o = localB->b_lastv; localB->c_k_o <= localB->d_k;
                 localB->c_k_o += 2) {
              tmp = _mm_loadu_pd(&Q[localB->c_k_o - 1]);
              _mm_storeu_pd(&Q[localB->c_k_o - 1], _mm_mul_pd(tmp, _mm_set1_pd
                (9.9792015476736E+291)));
            }

            for (localB->c_k_o = localB->f; localB->c_k_o <= localB->b_coltop;
                 localB->c_k_o++) {
              Q[localB->c_k_o - 1] *= 9.9792015476736E+291;
            }

            localB->beta1 *= 9.9792015476736E+291;
            localB->atmp_m *= 9.9792015476736E+291;
          } while ((fabs(localB->beta1) < 1.0020841800044864E-292) &&
                   (localB->knt < 20));

          localB->beta1 = rt_hypotd_snf(localB->atmp_m,
            c6_formation_ros2_xnrm2_a(4 - localB->d_i, Q, localB->i_l + 2,
            localB));
          if (localB->atmp_m >= 0.0) {
            localB->beta1 = -localB->beta1;
          }

          localB->tau_k[localB->d_i] = (localB->beta1 - localB->atmp_m) /
            localB->beta1;
          localB->atmp_m = 1.0 / (localB->atmp_m - localB->beta1);
          for (localB->c_k_o = localB->b_lastv; localB->c_k_o <= localB->d_k;
               localB->c_k_o += 2) {
            tmp = _mm_loadu_pd(&Q[localB->c_k_o - 1]);
            _mm_storeu_pd(&Q[localB->c_k_o - 1], _mm_mul_pd(tmp, _mm_set1_pd
              (localB->atmp_m)));
          }

          for (localB->c_k_o = localB->f; localB->c_k_o <= localB->b_coltop;
               localB->c_k_o++) {
            Q[localB->c_k_o - 1] *= localB->atmp_m;
          }

          for (localB->b_lastv = 0; localB->b_lastv < localB->knt;
               localB->b_lastv++) {
            localB->beta1 *= 1.0020841800044864E-292;
          }

          localB->atmp_m = localB->beta1;
        } else {
          localB->tau_k[localB->d_i] = (localB->beta1 - localB->b_A_n) /
            localB->beta1;
          localB->atmp_m = 1.0 / (localB->b_A_n - localB->beta1);
          localB->f = (localB->i_l - localB->d_i) + 5;
          localB->knt = (((((localB->f - localB->i_l) - 1) / 2) << 1) +
                         localB->i_l) + 2;
          localB->b_coltop = localB->knt - 2;
          for (localB->d_k = localB->b_lastv; localB->d_k <= localB->b_coltop;
               localB->d_k += 2) {
            tmp = _mm_loadu_pd(&Q[localB->d_k - 1]);
            _mm_storeu_pd(&Q[localB->d_k - 1], _mm_mul_pd(tmp, _mm_set1_pd
              (localB->atmp_m)));
          }

          for (localB->d_k = localB->knt; localB->d_k <= localB->f; localB->d_k
               ++) {
            Q[localB->d_k - 1] *= localB->atmp_m;
          }

          localB->atmp_m = localB->beta1;
        }
      }

      Q[localB->i_l] = 1.0;
      if (localB->tau_k[localB->d_i] != 0.0) {
        localB->b_lastv = 5 - localB->d_i;
        localB->knt = (localB->i_l - localB->d_i) + 4;
        while ((localB->b_lastv > 0) && (Q[localB->knt] == 0.0)) {
          localB->b_lastv--;
          localB->knt--;
        }

        localB->knt = 4 - localB->d_i;
        exitg2 = false;
        while ((!exitg2) && (localB->knt > 0)) {
          localB->b_coltop = ((localB->knt - 1) * 5 + localB->i_l) + 5;
          localB->f = localB->b_coltop;
          do {
            exitg1 = 0;
            if (localB->f + 1 <= localB->b_coltop + localB->b_lastv) {
              if (Q[localB->f] != 0.0) {
                exitg1 = 1;
              } else {
                localB->f++;
              }
            } else {
              localB->knt--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        localB->b_lastv = 0;
        localB->knt = 0;
      }

      if (localB->b_lastv > 0) {
        c6_formation_ros2_xgemv_m(localB->b_lastv, localB->knt, Q, localB->i_l +
          6, Q, localB->i_l + 1, localB->work_cx, localB);
        c6_formation_ros2_xgerc_c(localB->b_lastv, localB->knt, -localB->
          tau_k[localB->d_i], localB->i_l + 1, localB->work_cx, Q, localB->i_l +
          6, localB);
      }

      Q[localB->i_l] = localB->atmp_m;
    } else {
      localB->tau_k[4] = 0.0;
    }
  }

  for (localB->d_i = 0; localB->d_i < 5; localB->d_i++) {
    for (localB->i_l = 0; localB->i_l <= localB->d_i; localB->i_l++) {
      R[localB->i_l + 5 * localB->d_i] = Q[5 * localB->d_i + localB->i_l];
    }

    for (localB->i_l = localB->d_i + 2; localB->i_l < 6; localB->i_l++) {
      R[(localB->i_l + 5 * localB->d_i) - 1] = 0.0;
    }

    localB->work_cx[localB->d_i] = 0.0;
  }

  for (localB->d_i = 4; localB->d_i >= 0; localB->d_i--) {
    localB->i_l = (localB->d_i * 5 + localB->d_i) + 6;
    if (localB->d_i + 1 < 5) {
      Q[localB->i_l - 6] = 1.0;
      if (localB->tau_k[localB->d_i] != 0.0) {
        localB->b_lastv = 5 - localB->d_i;
        localB->knt = localB->i_l - localB->d_i;
        while ((localB->b_lastv > 0) && (Q[localB->knt - 2] == 0.0)) {
          localB->b_lastv--;
          localB->knt--;
        }

        localB->knt = 4 - localB->d_i;
        exitg2 = false;
        while ((!exitg2) && (localB->knt > 0)) {
          localB->b_coltop = (localB->knt - 1) * 5 + localB->i_l;
          localB->f = localB->b_coltop;
          do {
            exitg1 = 0;
            if (localB->f <= (localB->b_coltop + localB->b_lastv) - 1) {
              if (Q[localB->f - 1] != 0.0) {
                exitg1 = 1;
              } else {
                localB->f++;
              }
            } else {
              localB->knt--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        localB->b_lastv = 0;
        localB->knt = 0;
      }

      if (localB->b_lastv > 0) {
        c6_formation_ros2_xgemv_m(localB->b_lastv, localB->knt, Q, localB->i_l,
          Q, localB->i_l - 5, localB->work_cx, localB);
        c6_formation_ros2_xgerc_c(localB->b_lastv, localB->knt, -localB->
          tau_k[localB->d_i], localB->i_l - 5, localB->work_cx, Q, localB->i_l,
          localB);
      }

      localB->b_lastv = (localB->i_l - localB->d_i) - 1;
      localB->knt = (((((localB->b_lastv - localB->i_l) + 5) / 2) << 1) +
                     localB->i_l) - 4;
      localB->b_coltop = localB->knt - 2;
      for (localB->f = localB->i_l - 4; localB->f <= localB->b_coltop; localB->f
           += 2) {
        tmp = _mm_loadu_pd(&Q[localB->f - 1]);
        _mm_storeu_pd(&Q[localB->f - 1], _mm_mul_pd(tmp, _mm_set1_pd
          (-localB->tau_k[localB->d_i])));
      }

      for (localB->f = localB->knt; localB->f <= localB->b_lastv; localB->f++) {
        Q[localB->f - 1] *= -localB->tau_k[localB->d_i];
      }
    }

    Q[localB->i_l - 6] = 1.0 - localB->tau_k[localB->d_i];
    for (localB->b_lastv = 0; localB->b_lastv < localB->d_i; localB->b_lastv++)
    {
      Q[(localB->i_l - localB->b_lastv) - 7] = 0.0;
    }
  }
}

//
// Output and update for atomic system:
//    '<S22>/CalculatePL'
//    '<S83>/CalculatePL'
//    '<S144>/CalculatePL'
//    '<S205>/CalculatePL'
//    '<S266>/CalculatePL'
//    '<S327>/CalculatePL'
//
void c6_formation_ros2::c6_formation_ros2_CalculatePL(const real_T rtu_Ak[25],
  const real_T rtu_Ck[25], const real_T rtu_Qsk[25], const real_T rtu_Rsk[25],
  const real_T rtu_Nk[25], boolean_T rtu_Enablek, const real_T rtu_Sk[25],
  real_T rty_Lk[25], real_T rty_Mk[25], real_T rty_Zsk[25], real_T rty_Sk1[25],
  B_CalculatePL_c6_formation_ro_T *localB)
{
  __m128d tmp;
  __m128d tmp_0;
  int32_T exitg1;
  boolean_T exitg2;

  // MATLAB Function: '<S26>/Discrete-Time SqrtKF - Calculate SLMZ'
  if (rtu_Enablek) {
    memcpy(&localB->yCovSqrt[0], &rtu_Sk[0], 25U * sizeof(real_T));
    c6_formation_ros2_qrFactor(rtu_Ck, localB->yCovSqrt, rtu_Rsk, localB);
    for (localB->jj = 0; localB->jj < 5; localB->jj++) {
      for (localB->j_k = 0; localB->j_k < 5; localB->j_k++) {
        localB->smax = 0.0;
        for (localB->iAcol = 0; localB->iAcol < 5; localB->iAcol++) {
          localB->smax += rtu_Sk[5 * localB->iAcol + localB->jj] * rtu_Sk[5 *
            localB->iAcol + localB->j_k];
        }

        localB->rtu_Sk[localB->jj + 5 * localB->j_k] = localB->smax;
      }
    }

    for (localB->jj = 0; localB->jj < 5; localB->jj++) {
      for (localB->j_k = 0; localB->j_k < 5; localB->j_k++) {
        localB->smax = 0.0;
        for (localB->iAcol = 0; localB->iAcol < 5; localB->iAcol++) {
          localB->smax += localB->rtu_Sk[5 * localB->iAcol + localB->jj] *
            rtu_Ck[5 * localB->iAcol + localB->j_k];
        }

        localB->Hnew[localB->jj + 5 * localB->j_k] = localB->smax;
      }
    }

    for (localB->jj = 0; localB->jj < 5; localB->jj++) {
      for (localB->j_k = 0; localB->j_k < 5; localB->j_k++) {
        localB->smax = 0.0;
        for (localB->iAcol = 0; localB->iAcol < 5; localB->iAcol++) {
          localB->smax += rtu_Ak[5 * localB->iAcol + localB->j_k] * localB->
            Hnew[5 * localB->jj + localB->iAcol];
        }

        localB->rtu_Ak[localB->jj + 5 * localB->j_k] = rtu_Nk[5 * localB->jj +
          localB->j_k] + localB->smax;
      }
    }

    c6_formation_ros2_linsolve(localB->yCovSqrt, localB->rtu_Ak, localB->l,
      localB);
    for (localB->jj = 0; localB->jj < 5; localB->jj++) {
      for (localB->j_k = 0; localB->j_k < 5; localB->j_k++) {
        localB->rtu_Ak[localB->j_k + 5 * localB->jj] = localB->yCovSqrt[5 *
          localB->j_k + localB->jj];
      }
    }

    c6_formation_ros2_linsolve_h(localB->rtu_Ak, localB->l, localB->a, localB);
    for (localB->jj = 0; localB->jj < 5; localB->jj++) {
      for (localB->j_k = 0; localB->j_k < 5; localB->j_k++) {
        rty_Mk[localB->j_k + 5 * localB->jj] = localB->a[5 * localB->j_k +
          localB->jj];
      }
    }

    for (localB->jj = 0; localB->jj < 5; localB->jj++) {
      for (localB->j_k = 0; localB->j_k < 5; localB->j_k++) {
        localB->rtu_Sk[localB->j_k + 5 * localB->jj] = localB->Hnew[5 *
          localB->j_k + localB->jj];
      }
    }

    c6_formation_ros2_linsolve(localB->yCovSqrt, localB->rtu_Sk, localB->l,
      localB);
    for (localB->jj = 0; localB->jj < 5; localB->jj++) {
      for (localB->j_k = 0; localB->j_k < 5; localB->j_k++) {
        localB->rtu_Ak[localB->j_k + 5 * localB->jj] = localB->yCovSqrt[5 *
          localB->j_k + localB->jj];
      }
    }

    c6_formation_ros2_linsolve_h(localB->rtu_Ak, localB->l, localB->a, localB);
    for (localB->jj = 0; localB->jj < 5; localB->jj++) {
      for (localB->j_k = 0; localB->j_k < 5; localB->j_k++) {
        rty_Lk[localB->j_k + 5 * localB->jj] = localB->a[5 * localB->j_k +
          localB->jj];
      }
    }

    memset(&localB->yCovSqrt[0], 0, 25U * sizeof(real_T));
    for (localB->i = 0; localB->i < 5; localB->i++) {
      localB->yCovSqrt[localB->i + 5 * localB->i] = 1.0;
    }

    for (localB->i = 0; localB->i < 25; localB->i++) {
      rty_Zsk[localB->i] = rtu_Sk[localB->i];
    }

    for (localB->jj = 0; localB->jj < 5; localB->jj++) {
      for (localB->j_k = 0; localB->j_k < 5; localB->j_k++) {
        localB->smax = 0.0;
        for (localB->iAcol = 0; localB->iAcol < 5; localB->iAcol++) {
          localB->smax += rty_Lk[5 * localB->iAcol + localB->jj] * rtu_Ck[5 *
            localB->j_k + localB->iAcol];
        }

        localB->jA = 5 * localB->j_k + localB->jj;
        localB->rtu_Ak[localB->jA] = localB->yCovSqrt[localB->jA] - localB->smax;
      }
    }

    for (localB->jj = 0; localB->jj < 5; localB->jj++) {
      for (localB->j_k = 0; localB->j_k < 5; localB->j_k++) {
        localB->smax = 0.0;
        for (localB->iAcol = 0; localB->iAcol < 5; localB->iAcol++) {
          localB->smax += rty_Lk[5 * localB->iAcol + localB->jj] * rtu_Rsk[5 *
            localB->j_k + localB->iAcol];
        }

        localB->Hnew[localB->jj + 5 * localB->j_k] = localB->smax;
      }
    }

    c6_formation_ros2_qrFactor(localB->rtu_Ak, rty_Zsk, localB->Hnew, localB);
    for (localB->jj = 0; localB->jj < 25; localB->jj++) {
      localB->Hnew[localB->jj] = rtu_Rsk[localB->jj];
    }

    memset(&localB->yCovSqrt[0], 0, 25U * sizeof(real_T));
    for (localB->jj = 0; localB->jj < 5; localB->jj++) {
      localB->ipiv[localB->jj] = static_cast<int8_T>(localB->jj + 1);
    }

    for (localB->i = 0; localB->i < 4; localB->i++) {
      localB->jj = localB->i * 6;
      localB->iAcol = 5 - localB->i;
      localB->jA = 0;
      localB->smax = fabs(localB->Hnew[localB->jj]);
      for (localB->j_k = 2; localB->j_k <= localB->iAcol; localB->j_k++) {
        localB->b_s_b = fabs(localB->Hnew[(localB->jj + localB->j_k) - 1]);
        if (localB->b_s_b > localB->smax) {
          localB->jA = localB->j_k - 1;
          localB->smax = localB->b_s_b;
        }
      }

      if (localB->Hnew[localB->jj + localB->jA] != 0.0) {
        if (localB->jA != 0) {
          localB->iAcol = localB->i + localB->jA;
          localB->ipiv[localB->i] = static_cast<int8_T>(localB->iAcol + 1);
          for (localB->j_k = 0; localB->j_k < 5; localB->j_k++) {
            localB->jA = localB->j_k * 5 + localB->i;
            localB->smax = localB->Hnew[localB->jA];
            localB->jBcol = localB->j_k * 5 + localB->iAcol;
            localB->Hnew[localB->jA] = localB->Hnew[localB->jBcol];
            localB->Hnew[localB->jBcol] = localB->smax;
          }
        }

        localB->iAcol = (localB->jj - localB->i) + 5;
        localB->jA = (((((localB->iAcol - localB->jj) - 1) / 2) << 1) +
                      localB->jj) + 2;
        localB->jBcol = localB->jA - 2;
        for (localB->j_k = localB->jj + 2; localB->j_k <= localB->jBcol;
             localB->j_k += 2) {
          tmp_0 = _mm_loadu_pd(&localB->Hnew[localB->j_k - 1]);
          _mm_storeu_pd(&localB->Hnew[localB->j_k - 1], _mm_div_pd(tmp_0,
            _mm_set1_pd(localB->Hnew[localB->jj])));
        }

        for (localB->j_k = localB->jA; localB->j_k <= localB->iAcol; localB->j_k
             ++) {
          localB->Hnew[localB->j_k - 1] /= localB->Hnew[localB->jj];
        }
      }

      localB->jA = localB->jj + 7;
      localB->jBcol = 3 - localB->i;
      for (localB->j_k = 0; localB->j_k <= localB->jBcol; localB->j_k++) {
        localB->smax = localB->Hnew[(localB->j_k * 5 + localB->jj) + 5];
        if (localB->smax != 0.0) {
          localB->kAcol = (localB->jA - localB->i) + 3;
          for (localB->iAcol = localB->jA; localB->iAcol <= localB->kAcol;
               localB->iAcol++) {
            localB->Hnew[localB->iAcol - 1] += localB->Hnew[((localB->jj +
              localB->iAcol) - localB->jA) + 1] * -localB->smax;
          }
        }

        localB->jA += 5;
      }
    }

    for (localB->jj = 0; localB->jj < 5; localB->jj++) {
      localB->b_p[localB->jj] = static_cast<int8_T>(localB->jj + 1);
    }

    if (localB->ipiv[0] > 1) {
      localB->i = localB->b_p[localB->ipiv[0] - 1];
      localB->b_p[localB->ipiv[0] - 1] = localB->b_p[0];
      localB->b_p[0] = static_cast<int8_T>(localB->i);
    }

    if (localB->ipiv[1] > 2) {
      localB->i = localB->b_p[localB->ipiv[1] - 1];
      localB->b_p[localB->ipiv[1] - 1] = localB->b_p[1];
      localB->b_p[1] = static_cast<int8_T>(localB->i);
    }

    if (localB->ipiv[2] > 3) {
      localB->i = localB->b_p[localB->ipiv[2] - 1];
      localB->b_p[localB->ipiv[2] - 1] = localB->b_p[2];
      localB->b_p[2] = static_cast<int8_T>(localB->i);
    }

    if (localB->ipiv[3] > 4) {
      localB->i = localB->b_p[localB->ipiv[3] - 1];
      localB->b_p[localB->ipiv[3] - 1] = localB->b_p[3];
      localB->b_p[3] = static_cast<int8_T>(localB->i);
    }

    for (localB->i = 0; localB->i < 5; localB->i++) {
      localB->jA = (localB->b_p[localB->i] - 1) * 5;
      localB->yCovSqrt[localB->i + localB->jA] = 1.0;
      for (localB->j_k = localB->i + 1; localB->j_k < 6; localB->j_k++) {
        localB->jj = (localB->jA + localB->j_k) - 1;
        if (localB->yCovSqrt[localB->jj] != 0.0) {
          for (localB->iAcol = localB->j_k + 1; localB->iAcol < 6; localB->iAcol
               ++) {
            localB->jBcol = (localB->jA + localB->iAcol) - 1;
            localB->yCovSqrt[localB->jBcol] -= localB->Hnew[((localB->j_k - 1) *
              5 + localB->iAcol) - 1] * localB->yCovSqrt[localB->jj];
          }
        }
      }
    }

    for (localB->i = 0; localB->i < 5; localB->i++) {
      localB->jBcol = 5 * localB->i;
      for (localB->j_k = 4; localB->j_k >= 0; localB->j_k--) {
        localB->kAcol = 5 * localB->j_k;
        localB->jj = localB->j_k + localB->jBcol;
        localB->smax = localB->yCovSqrt[localB->jj];
        if (localB->smax != 0.0) {
          localB->yCovSqrt[localB->jj] = localB->smax / localB->Hnew[localB->j_k
            + localB->kAcol];
          for (localB->iAcol = 0; localB->iAcol < localB->j_k; localB->iAcol++)
          {
            localB->jA = localB->iAcol + localB->jBcol;
            localB->yCovSqrt[localB->jA] -= localB->Hnew[localB->iAcol +
              localB->kAcol] * localB->yCovSqrt[localB->jj];
          }
        }
      }
    }

    for (localB->jj = 0; localB->jj < 5; localB->jj++) {
      for (localB->j_k = 0; localB->j_k < 5; localB->j_k++) {
        localB->smax = 0.0;
        for (localB->iAcol = 0; localB->iAcol < 5; localB->iAcol++) {
          localB->smax += rtu_Nk[5 * localB->iAcol + localB->jj] *
            localB->yCovSqrt[5 * localB->iAcol + localB->j_k];
        }

        localB->rtu_Sk[localB->jj + 5 * localB->j_k] = localB->smax;
      }
    }

    for (localB->jj = 0; localB->jj < 25; localB->jj++) {
      localB->l[localB->jj] = rty_Zsk[localB->jj];
    }

    for (localB->jj = 0; localB->jj < 5; localB->jj++) {
      for (localB->j_k = 0; localB->j_k < 5; localB->j_k++) {
        localB->smax = 0.0;
        for (localB->iAcol = 0; localB->iAcol < 5; localB->iAcol++) {
          localB->smax += localB->yCovSqrt[5 * localB->jj + localB->iAcol] *
            localB->yCovSqrt[5 * localB->j_k + localB->iAcol];
        }

        localB->rtu_Ak[localB->jj + 5 * localB->j_k] = localB->smax;
      }
    }

    for (localB->jj = 0; localB->jj < 5; localB->jj++) {
      for (localB->j_k = 0; localB->j_k < 5; localB->j_k++) {
        localB->smax = 0.0;
        for (localB->iAcol = 0; localB->iAcol < 5; localB->iAcol++) {
          localB->smax += rtu_Nk[5 * localB->iAcol + localB->jj] *
            localB->rtu_Ak[5 * localB->j_k + localB->iAcol];
        }

        localB->Hnew[localB->jj + 5 * localB->j_k] = localB->smax;
      }
    }

    for (localB->jj = 0; localB->jj < 5; localB->jj++) {
      for (localB->j_k = 0; localB->j_k < 5; localB->j_k++) {
        localB->smax = 0.0;
        for (localB->iAcol = 0; localB->iAcol < 5; localB->iAcol++) {
          localB->smax += localB->Hnew[5 * localB->iAcol + localB->jj] * rtu_Ck
            [5 * localB->j_k + localB->iAcol];
        }

        localB->i = 5 * localB->j_k + localB->jj;
        localB->rtu_Ak[localB->i] = rtu_Ak[localB->i] - localB->smax;
      }
    }

    c6_formation_ros2_qrFactor(localB->rtu_Ak, localB->l, rtu_Qsk, localB);
    for (localB->jj = 0; localB->jj < 5; localB->jj++) {
      for (localB->j_k = 0; localB->j_k < 5; localB->j_k++) {
        rty_Sk1[localB->j_k + 5 * localB->jj] = localB->l[5 * localB->j_k +
          localB->jj];
      }
    }

    for (localB->i = 0; localB->i < 5; localB->i++) {
      for (localB->jj = 0; localB->jj < 5; localB->jj++) {
        localB->iAcol = 3 - localB->jj;
        for (localB->j_k = 0; localB->j_k <= localB->iAcol; localB->j_k++) {
          rty_Sk1[((localB->jj + localB->j_k) + 5 * localB->jj) + 1] = 0.0;
        }
      }

      localB->p = 0;
      localB->errorCondition = false;
      for (localB->jj = 0; localB->jj < 5; localB->jj++) {
        if (!localB->errorCondition) {
          localB->errorCondition = (rty_Sk1[5 * localB->jj + localB->jj] == 0.0);
        }
      }

      if (localB->errorCondition) {
        localB->p = 2;
      } else {
        for (localB->jj = 0; localB->jj < 5; localB->jj++) {
          localB->x[localB->jj] = localB->rtu_Sk[5 * localB->i + localB->jj];
        }

        for (localB->jj = 0; localB->jj < 5; localB->jj++) {
          localB->iAcol = 5 * localB->jj;
          localB->smax = localB->x[localB->jj];
          for (localB->j_k = 0; localB->j_k < localB->jj; localB->j_k++) {
            localB->smax -= rty_Sk1[localB->j_k + localB->iAcol] * localB->
              x[localB->j_k];
          }

          localB->x[localB->jj] = localB->smax / rty_Sk1[localB->jj +
            localB->iAcol];
        }

        localB->smax = 0.0;
        localB->b_s_b = 3.3121686421112381E-170;
        for (localB->jj = 0; localB->jj < 5; localB->jj++) {
          localB->absxk = fabs(localB->x[localB->jj]);
          if (localB->absxk > localB->b_s_b) {
            localB->t = localB->b_s_b / localB->absxk;
            localB->smax = localB->smax * localB->t * localB->t + 1.0;
            localB->b_s_b = localB->absxk;
          } else {
            localB->t = localB->absxk / localB->b_s_b;
            localB->smax += localB->t * localB->t;
          }
        }

        localB->smax = localB->b_s_b * sqrt(localB->smax);
        if (localB->smax >= 1.0) {
          localB->p = 1;
        } else {
          localB->t = sqrt(1.0 - localB->smax * localB->smax);
          for (localB->jj = 4; localB->jj >= 0; localB->jj--) {
            localB->b_s_b = fabs(localB->t);
            localB->smax = localB->x[localB->jj];
            localB->absxk = fabs(localB->smax);
            if (localB->absxk == 0.0) {
              localB->c_c[localB->jj] = 1.0;
              localB->s[localB->jj] = 0.0;
            } else if (localB->b_s_b == 0.0) {
              localB->c_c[localB->jj] = 0.0;
              localB->s[localB->jj] = 1.0;
              localB->t = localB->smax;
            } else {
              localB->absxk += localB->b_s_b;
              localB->t /= localB->absxk;
              localB->smax /= localB->absxk;
              localB->b_s_b = fabs(localB->t);
              localB->rho = rt_hypotd_snf(localB->b_s_b, fabs(localB->smax));
              localB->c_c[localB->jj] = localB->b_s_b / localB->rho;
              localB->t /= localB->b_s_b;
              localB->s[localB->jj] = localB->t * localB->smax / localB->rho;
              localB->t *= localB->rho * localB->absxk;
            }

            localB->x[localB->jj] = 0.0;
          }

          for (localB->jj = 0; localB->jj < 5; localB->jj++) {
            for (localB->j_k = localB->jj + 1; localB->j_k >= 1; localB->j_k--)
            {
              localB->b_s_b = localB->s[localB->j_k - 1];
              localB->iAcol = (5 * localB->jj + localB->j_k) - 1;
              localB->absxk = rty_Sk1[localB->iAcol] * localB->b_s_b;
              localB->t = localB->c_c[localB->j_k - 1];
              localB->smax = localB->x[localB->jj];
              rty_Sk1[localB->iAcol] = rty_Sk1[localB->iAcol] * localB->t -
                localB->b_s_b * localB->smax;
              localB->x[localB->jj] = localB->t * localB->smax + localB->absxk;
            }
          }
        }
      }

      if (localB->p != 0) {
        for (localB->jj = 0; localB->jj < 5; localB->jj++) {
          for (localB->j_k = 0; localB->j_k < 5; localB->j_k++) {
            localB->smax = 0.0;
            for (localB->iAcol = 0; localB->iAcol < 5; localB->iAcol++) {
              localB->smax += rty_Sk1[5 * localB->jj + localB->iAcol] * rty_Sk1
                [5 * localB->j_k + localB->iAcol];
            }

            localB->yCovSqrt[localB->jj + 5 * localB->j_k] = localB->smax;
          }
        }

        for (localB->jj = 0; localB->jj < 5; localB->jj++) {
          for (localB->j_k = 0; localB->j_k <= 2; localB->j_k += 2) {
            tmp_0 = _mm_loadu_pd(&localB->rtu_Sk[5 * localB->i + localB->j_k]);
            _mm_storeu_pd(&localB->l[localB->j_k + 5 * localB->jj], _mm_mul_pd
                          (tmp_0, _mm_set1_pd(localB->rtu_Sk[5 * localB->i +
              localB->jj])));
          }

          for (localB->j_k = 4; localB->j_k < 5; localB->j_k++) {
            localB->l[localB->j_k + 5 * localB->jj] = localB->rtu_Sk[5 *
              localB->i + localB->j_k] * localB->rtu_Sk[5 * localB->i +
              localB->jj];
          }
        }

        for (localB->jj = 0; localB->jj <= 22; localB->jj += 2) {
          tmp_0 = _mm_loadu_pd(&localB->yCovSqrt[localB->jj]);
          tmp = _mm_loadu_pd(&localB->l[localB->jj]);
          _mm_storeu_pd(&localB->Hnew[localB->jj], _mm_sub_pd(tmp_0, tmp));
        }

        for (localB->jj = 24; localB->jj < 25; localB->jj++) {
          localB->Hnew[localB->jj] = localB->yCovSqrt[localB->jj] - localB->
            l[localB->jj];
        }

        localB->errorCondition = true;
        for (localB->jj = 0; localB->jj < 25; localB->jj++) {
          if (localB->errorCondition) {
            localB->smax = localB->Hnew[localB->jj];
            if (rtIsInf(localB->smax) || rtIsNaN(localB->smax)) {
              localB->errorCondition = false;
            }
          }
        }

        if (localB->errorCondition) {
          c6_formation_ros2_svd(localB->Hnew, localB->yCovSqrt, localB->s,
                                localB->a, localB);
        } else {
          for (localB->jj = 0; localB->jj < 5; localB->jj++) {
            localB->s[localB->jj] = (rtNaN);
          }

          for (localB->jj = 0; localB->jj < 25; localB->jj++) {
            localB->a[localB->jj] = (rtNaN);
          }
        }

        memset(&localB->yCovSqrt[0], 0, 25U * sizeof(real_T));
        for (localB->jj = 0; localB->jj < 5; localB->jj++) {
          localB->yCovSqrt[localB->jj + 5 * localB->jj] = localB->s[localB->jj];
        }

        for (localB->jj = 0; localB->jj <= 22; localB->jj += 2) {
          tmp_0 = _mm_loadu_pd(&localB->yCovSqrt[localB->jj]);
          _mm_storeu_pd(&localB->yCovSqrt[localB->jj], _mm_sqrt_pd(tmp_0));
        }

        for (localB->jj = 24; localB->jj < 25; localB->jj++) {
          localB->yCovSqrt[localB->jj] = sqrt(localB->yCovSqrt[localB->jj]);
        }

        for (localB->jj = 0; localB->jj < 5; localB->jj++) {
          for (localB->j_k = 0; localB->j_k < 5; localB->j_k++) {
            localB->iAcol = 5 * localB->j_k + localB->jj;
            rty_Sk1[localB->iAcol] = 0.0;
            for (localB->jA = 0; localB->jA < 5; localB->jA++) {
              rty_Sk1[localB->iAcol] += localB->a[5 * localB->jA + localB->j_k] *
                localB->yCovSqrt[5 * localB->jj + localB->jA];
            }
          }
        }

        localB->errorCondition = true;
        localB->jj = 0;
        exitg2 = false;
        while ((!exitg2) && (localB->jj < 5)) {
          localB->j_k = localB->jj + 1;
          do {
            exitg1 = 0;
            if (localB->j_k + 1 < 6) {
              if (!(rty_Sk1[5 * localB->jj + localB->j_k] == 0.0)) {
                localB->errorCondition = false;
                exitg1 = 1;
              } else {
                localB->j_k++;
              }
            } else {
              localB->jj++;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }

        if (!localB->errorCondition) {
          for (localB->jj = 0; localB->jj < 25; localB->jj++) {
            localB->Hnew[localB->jj] = rty_Sk1[localB->jj];
          }

          c6_formation_ros2_qr(localB->Hnew, localB->yCovSqrt, rty_Sk1, localB);
        }
      }
    }

    for (localB->jj = 0; localB->jj < 5; localB->jj++) {
      for (localB->j_k = 0; localB->j_k < 5; localB->j_k++) {
        localB->yCovSqrt[localB->j_k + 5 * localB->jj] = rty_Sk1[5 * localB->j_k
          + localB->jj];
      }
    }

    for (localB->jj = 0; localB->jj < 25; localB->jj++) {
      rty_Sk1[localB->jj] = localB->yCovSqrt[localB->jj];
    }
  } else {
    for (localB->i = 0; localB->i < 25; localB->i++) {
      rty_Mk[localB->i] = 0.0;
    }

    for (localB->i = 0; localB->i < 25; localB->i++) {
      rty_Lk[localB->i] = 0.0;
    }

    for (localB->i = 0; localB->i < 25; localB->i++) {
      rty_Zsk[localB->i] = rtu_Sk[localB->i];
    }

    for (localB->i = 0; localB->i < 25; localB->i++) {
      rty_Sk1[localB->i] = rtu_Sk[localB->i];
    }

    c6_formation_ros2_qrFactor(rtu_Ak, rty_Sk1, rtu_Qsk, localB);
  }

  // End of MATLAB Function: '<S26>/Discrete-Time SqrtKF - Calculate SLMZ'
}

//
// Output and update for atomic system:
//    '<S70>/SqrtUsedFcn'
//    '<S131>/SqrtUsedFcn'
//    '<S192>/SqrtUsedFcn'
//    '<S253>/SqrtUsedFcn'
//    '<S314>/SqrtUsedFcn'
//    '<S375>/SqrtUsedFcn'
//
void c6_formation_ros2::c6_formation_ros2_SqrtUsedFcn(const real_T rtu_u[25],
  boolean_T rtu_isSqrtUsed, real_T rty_P[25])
{
  for (int32_T i = 0; i < 5; i++) {
    for (int32_T i_0 = 0; i_0 < 5; i_0++) {
      real_T tmp;
      tmp = 0.0;
      for (int32_T i_1 = 0; i_1 < 5; i_1++) {
        tmp += rtu_u[5 * i_1 + i] * rtu_u[5 * i_1 + i_0];
      }

      if (rtu_isSqrtUsed) {
        rty_P[i + 5 * i_0] = tmp;
      } else {
        rty_P[i + 5 * i_0] = rtu_u[5 * i_0 + i];
      }
    }
  }
}

//
// System initialize for enable system:
//    '<S45>/MeasurementUpdate'
//    '<S106>/MeasurementUpdate'
//    '<S167>/MeasurementUpdate'
//    '<S228>/MeasurementUpdate'
//    '<S289>/MeasurementUpdate'
//    '<S350>/MeasurementUpdate'
//
void c6_formation_ros2::c6_forma_MeasurementUpdate_Init(real_T rty_Lykyhatkk1[5],
  P_MeasurementUpdate_c6_format_T *localP)
{
  // SystemInitialize for Outport: '<S72>/L*(y[k]-yhat[k|k-1])'
  for (int32_T i = 0; i < 5; i++) {
    rty_Lykyhatkk1[i] = localP->Lykyhatkk1_Y0;
  }

  // End of SystemInitialize for Outport: '<S72>/L*(y[k]-yhat[k|k-1])'
}

//
// Disable for enable system:
//    '<S45>/MeasurementUpdate'
//    '<S106>/MeasurementUpdate'
//    '<S167>/MeasurementUpdate'
//    '<S228>/MeasurementUpdate'
//    '<S289>/MeasurementUpdate'
//    '<S350>/MeasurementUpdate'
//
void c6_formation_ros2::c6_fo_MeasurementUpdate_Disable(real_T rty_Lykyhatkk1[5],
  DW_MeasurementUpdate_c6_forma_T *localDW, P_MeasurementUpdate_c6_format_T
  *localP)
{
  // Disable for Outport: '<S72>/L*(y[k]-yhat[k|k-1])'
  for (int32_T i = 0; i < 5; i++) {
    // Outputs for Enabled SubSystem: '<S45>/MeasurementUpdate' incorporates:
    //   EnablePort: '<S72>/Enable'

    rty_Lykyhatkk1[i] = localP->Lykyhatkk1_Y0;

    // End of Outputs for SubSystem: '<S45>/MeasurementUpdate'
  }

  // End of Disable for Outport: '<S72>/L*(y[k]-yhat[k|k-1])'
  localDW->MeasurementUpdate_MODE = false;
}

//
// Output and update for enable system:
//    '<S45>/MeasurementUpdate'
//    '<S106>/MeasurementUpdate'
//    '<S167>/MeasurementUpdate'
//    '<S228>/MeasurementUpdate'
//    '<S289>/MeasurementUpdate'
//    '<S350>/MeasurementUpdate'
//
void c6_formation_ros2::c6_formation__MeasurementUpdate(boolean_T rtu_Enable,
  const real_T rtu_Lk[25], const real_T rtu_yk[5], const real_T rtu_Ck[25],
  const real_T rtu_xhatkk1[5], const real_T rtu_Dk[5], real_T rtu_uk, real_T
  rty_Lykyhatkk1[5], DW_MeasurementUpdate_c6_forma_T *localDW,
  P_MeasurementUpdate_c6_format_T *localP)
{
  real_T rtu_yk_0[5];
  real_T rtu_Ck_0;
  int32_T i;
  int32_T i_0;

  // Outputs for Enabled SubSystem: '<S45>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S72>/Enable'

  if (rtu_Enable) {
    localDW->MeasurementUpdate_MODE = true;
    for (i = 0; i < 5; i++) {
      // Product: '<S72>/C[k]*xhat[k|k-1]'
      rtu_Ck_0 = 0.0;
      for (i_0 = 0; i_0 < 5; i_0++) {
        rtu_Ck_0 += rtu_Ck[5 * i_0 + i] * rtu_xhatkk1[i_0];
      }

      // Sum: '<S72>/Sum' incorporates:
      //   Product: '<S72>/C[k]*xhat[k|k-1]'
      //   Product: '<S72>/D[k]*u[k]'
      //   Sum: '<S72>/Add1'

      rtu_yk_0[i] = rtu_yk[i] - (rtu_Dk[i] * rtu_uk + rtu_Ck_0);
    }

    // Product: '<S72>/Product3'
    for (i = 0; i < 5; i++) {
      rtu_Ck_0 = 0.0;
      for (i_0 = 0; i_0 < 5; i_0++) {
        rtu_Ck_0 += rtu_Lk[5 * i_0 + i] * rtu_yk_0[i_0];
      }

      rty_Lykyhatkk1[i] = rtu_Ck_0;
    }

    // End of Product: '<S72>/Product3'
  } else if (localDW->MeasurementUpdate_MODE) {
    c6_fo_MeasurementUpdate_Disable(rty_Lykyhatkk1, localDW, localP);
  }

  // End of Outputs for SubSystem: '<S45>/MeasurementUpdate'
}

//
// Output and update for atomic system:
//    '<S22>/ReducedQRN'
//    '<S83>/ReducedQRN'
//    '<S144>/ReducedQRN'
//    '<S205>/ReducedQRN'
//    '<S266>/ReducedQRN'
//    '<S327>/ReducedQRN'
//
void c6_formation_ros2::c6_formation_ros2_ReducedQRN(real_T rty_Qbar[25], real_T
  rty_Rbar[25], real_T rty_Nbar[25], P_ReducedQRN_c6_formation_ros_T *localP)
{
  // Constant: '<S46>/Bbar_'
  memcpy(&rty_Nbar[0], &localP->Bbar_Value[0], 25U * sizeof(real_T));

  // Constant: '<S46>/Qbar_'
  memcpy(&rty_Qbar[0], &localP->Qbar_Value[0], 25U * sizeof(real_T));

  // Constant: '<S46>/Rbar_'
  memcpy(&rty_Rbar[0], &localP->Rbar_Value[0], 25U * sizeof(real_T));
}

//
// System initialize for enable system:
//    '<S52>/Enabled Subsystem'
//    '<S113>/Enabled Subsystem'
//    '<S174>/Enabled Subsystem'
//    '<S235>/Enabled Subsystem'
//    '<S296>/Enabled Subsystem'
//    '<S357>/Enabled Subsystem'
//
void c6_formation_ros2::c6_format_EnabledSubsystem_Init(real_T rty_deltax[5],
  P_EnabledSubsystem_c6_formati_T *localP)
{
  // SystemInitialize for Outport: '<S76>/deltax'
  for (int32_T i = 0; i < 5; i++) {
    rty_deltax[i] = localP->deltax_Y0;
  }

  // End of SystemInitialize for Outport: '<S76>/deltax'
}

//
// Disable for enable system:
//    '<S52>/Enabled Subsystem'
//    '<S113>/Enabled Subsystem'
//    '<S174>/Enabled Subsystem'
//    '<S235>/Enabled Subsystem'
//    '<S296>/Enabled Subsystem'
//    '<S357>/Enabled Subsystem'
//
void c6_formation_ros2::c6_for_EnabledSubsystem_Disable(real_T rty_deltax[5],
  DW_EnabledSubsystem_c6_format_T *localDW, P_EnabledSubsystem_c6_formati_T
  *localP)
{
  // Disable for Outport: '<S76>/deltax'
  for (int32_T i = 0; i < 5; i++) {
    // Outputs for Enabled SubSystem: '<S52>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S76>/Enable'

    rty_deltax[i] = localP->deltax_Y0;

    // End of Outputs for SubSystem: '<S52>/Enabled Subsystem'
  }

  // End of Disable for Outport: '<S76>/deltax'
  localDW->EnabledSubsystem_MODE = false;
}

//
// Output and update for enable system:
//    '<S52>/Enabled Subsystem'
//    '<S113>/Enabled Subsystem'
//    '<S174>/Enabled Subsystem'
//    '<S235>/Enabled Subsystem'
//    '<S296>/Enabled Subsystem'
//    '<S357>/Enabled Subsystem'
//
void c6_formation_ros2::c6_formation_r_EnabledSubsystem(boolean_T rtu_Enable,
  const real_T rtu_Mk[25], const real_T rtu_Ck[25], const real_T rtu_yk[5],
  const real_T rtu_xhatkk1[5], real_T rty_deltax[5],
  DW_EnabledSubsystem_c6_format_T *localDW, P_EnabledSubsystem_c6_formati_T
  *localP)
{
  real_T rtu_yk_0[5];
  real_T rty_deltax_0;
  int32_T i;
  int32_T i_0;

  // Outputs for Enabled SubSystem: '<S52>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S76>/Enable'

  if (rtu_Enable) {
    localDW->EnabledSubsystem_MODE = true;

    // Sum: '<S76>/Add1' incorporates:
    //   Product: '<S76>/Product'

    for (i = 0; i < 5; i++) {
      rty_deltax_0 = 0.0;
      for (i_0 = 0; i_0 < 5; i_0++) {
        rty_deltax_0 += rtu_Ck[5 * i_0 + i] * rtu_xhatkk1[i_0];
      }

      rtu_yk_0[i] = rtu_yk[i] - rty_deltax_0;
    }

    // End of Sum: '<S76>/Add1'

    // Product: '<S76>/Product2'
    for (i = 0; i < 5; i++) {
      rty_deltax_0 = 0.0;
      for (i_0 = 0; i_0 < 5; i_0++) {
        rty_deltax_0 += rtu_Mk[5 * i_0 + i] * rtu_yk_0[i_0];
      }

      rty_deltax[i] = rty_deltax_0;
    }

    // End of Product: '<S76>/Product2'
  } else if (localDW->EnabledSubsystem_MODE) {
    c6_for_EnabledSubsystem_Disable(rty_deltax, localDW, localP);
  }

  // End of Outputs for SubSystem: '<S52>/Enabled Subsystem'
}

//
// Output and update for atomic system:
//    '<S18>/kalmanM'
//    '<S79>/kalmanM'
//    '<S140>/kalmanM'
//    '<S201>/kalmanM'
//    '<S262>/kalmanM'
//    '<S323>/kalmanM'
//
void c6_formation_ros2::c6_formation_ros2_kalmanM(const real_T rtu_x[5], real_T
  rty_A[25], real_T rty_C[25], P_c6_formation_ros2_T *c6_formation_ros2_P)
{
  static const int8_T b[5] = { 0, 0, 0, 1, 0 };

  static const int8_T c[5] = { 0, 0, 0, 0, 1 };

  rty_A[0] = 1.0;
  rty_A[5] = 0.0;
  rty_A[10] = 0.0;
  rty_A[15] = c6_formation_ros2_P->sampleTime * cos(rtu_x[2]);
  rty_A[20] = 0.0;
  rty_A[1] = 0.0;
  rty_A[6] = 1.0;
  rty_A[11] = 0.0;
  rty_A[16] = c6_formation_ros2_P->sampleTime * sin(rtu_x[2]);
  rty_A[21] = 0.0;
  rty_A[2] = 0.0;
  rty_A[7] = 0.0;
  rty_A[12] = 1.0;
  rty_A[17] = 0.0;
  rty_A[22] = c6_formation_ros2_P->sampleTime;
  for (int32_T i = 0; i < 5; i++) {
    rty_A[5 * i + 3] = b[i];
    rty_A[5 * i + 4] = c[i];
  }

  memset(&rty_C[0], 0, 25U * sizeof(real_T));
  for (int32_T i = 0; i < 5; i++) {
    rty_C[i + 5 * i] = 1.0;
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(static_cast<real_T>(tmp), static_cast<real_T>(tmp_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

// Function for MATLAB Function: '<S18>/sensor2vCar'
void c6_formation_ros2::c6_formation_ros2_expand_atan2(const real_T a_data[],
  const int32_T *a_size, const real_T b_data[], const int32_T *b_size, real_T
  c_data[], int32_T *c_size)
{
  int8_T csz_idx_0;
  if (*b_size == 1) {
    csz_idx_0 = static_cast<int8_T>(*a_size);
  } else {
    csz_idx_0 = 0;
  }

  *c_size = csz_idx_0;
  if (csz_idx_0 != 0) {
    *c_size = 1;
    c_data[0] = rt_atan2d_snf(a_data[0], b_data[0]);
  }
}

void c6_formation_ros2::c6_formation_r_binary_expand_op(real_T in1[3], const
  int32_T in2_data[], const real_T in3_data[], const int32_T *in3_size, const
  real_T in4_data[], const int32_T *in4_size)
{
  int32_T loop_ub;
  loop_ub = *in4_size == 1 ? *in3_size : *in4_size;
  for (int32_T i = 0; i < loop_ub; i++) {
    in1[in2_data[0]] = -in3_data[0] * 2.0 * in4_data[0];
  }
}

//
// System initialize for atomic system:
//    '<S18>/sensor2vCar'
//    '<S79>/sensor2vCar'
//    '<S140>/sensor2vCar'
//    '<S201>/sensor2vCar'
//    '<S262>/sensor2vCar'
//    '<S323>/sensor2vCar'
//
void c6_formation_ros2::c6_formation_r_sensor2vCar_Init
  (DW_sensor2vCar_c6_formation_r_T *localDW)
{
  localDW->x0 = -10.0;
  localDW->y0 = -10.0;
  localDW->x0_init = -10.0;
  localDW->y0_init = -10.0;
}

//
// Output and update for atomic system:
//    '<S18>/sensor2vCar'
//    '<S79>/sensor2vCar'
//    '<S140>/sensor2vCar'
//    '<S201>/sensor2vCar'
//    '<S262>/sensor2vCar'
//    '<S323>/sensor2vCar'
//
void c6_formation_ros2::c6_formation_ros2_sensor2vCar(boolean_T rtu_poseNew,
  const SL_Bus_nav_msgs_Odometry *rtu_poseMsg, real_T *rty_x_init, real_T
  *rty_y_init, real_T *rty_yaw_init, real_T *rty_flag,
  B_sensor2vCar_c6_formation_ro_T *localB, DW_sensor2vCar_c6_formation_r_T
  *localDW)
{
  real_T b_idx_0;
  real_T eul_tmp;
  int32_T f_size_idx_0;
  int32_T flag;
  int32_T g_size_idx_0;
  int32_T i_size;
  int32_T tmp_data;
  int32_T trueCount;
  boolean_T rEQ0;
  if (rtu_poseNew) {
    if ((localDW->x0 == rtu_poseMsg->pose.pose.position.x) && (localDW->y0 ==
         rtu_poseMsg->pose.pose.position.y)) {
      flag = 1;
    } else {
      localDW->x0 = rtu_poseMsg->pose.pose.position.x;
      localDW->y0 = rtu_poseMsg->pose.pose.position.y;
      localB->b_b = 1.0 / sqrt(((rtu_poseMsg->pose.pose.orientation.w *
        rtu_poseMsg->pose.pose.orientation.w +
        rtu_poseMsg->pose.pose.orientation.x *
        rtu_poseMsg->pose.pose.orientation.x) +
        rtu_poseMsg->pose.pose.orientation.y *
        rtu_poseMsg->pose.pose.orientation.y) +
        rtu_poseMsg->pose.pose.orientation.z *
        rtu_poseMsg->pose.pose.orientation.z);
      localB->y_idx_0 = rtu_poseMsg->pose.pose.orientation.w * localB->b_b;
      localB->y_idx_1 = rtu_poseMsg->pose.pose.orientation.x * localB->b_b;
      localB->q = rtu_poseMsg->pose.pose.orientation.y * localB->b_b;
      localB->b_b *= rtu_poseMsg->pose.pose.orientation.z;
      localB->aSinInput = (localB->y_idx_1 * localB->b_b - localB->y_idx_0 *
                           localB->q) * -2.0;
      b_idx_0 = localB->aSinInput;
      if (localB->aSinInput >= 0.99999999999999778) {
        b_idx_0 = 1.0;
      }

      if (localB->aSinInput <= -0.99999999999999778) {
        b_idx_0 = -1.0;
      }

      localB->eul_tmp = localB->y_idx_0 * localB->y_idx_0;
      localB->eul_tmp_c = localB->y_idx_1 * localB->y_idx_1;
      localB->eul_tmp_k = localB->q * localB->q;
      eul_tmp = localB->b_b * localB->b_b;
      localB->eul[0] = rt_atan2d_snf((localB->y_idx_1 * localB->q +
        localB->y_idx_0 * localB->b_b) * 2.0, ((localB->eul_tmp +
        localB->eul_tmp_c) - localB->eul_tmp_k) - eul_tmp);
      localB->eul[1] = asin(b_idx_0);
      localB->eul[2] = rt_atan2d_snf((localB->q * localB->b_b + localB->y_idx_0 *
        localB->y_idx_1) * 2.0, ((localB->eul_tmp - localB->eul_tmp_c) -
        localB->eul_tmp_k) + eul_tmp);
      trueCount = 0;
      rEQ0 = ((localB->aSinInput >= 0.99999999999999778) || (localB->aSinInput <=
               -0.99999999999999778));
      if (rEQ0) {
        for (flag = 0; flag < 1; flag++) {
          trueCount++;
        }
      }

      f_size_idx_0 = trueCount;
      trueCount = 0;
      if (rEQ0) {
        for (flag = 0; flag < 1; flag++) {
          trueCount++;
        }
      }

      g_size_idx_0 = trueCount;
      trueCount = 0;
      if (rEQ0) {
        for (flag = 0; flag < 1; flag++) {
          trueCount++;
        }
      }

      if (f_size_idx_0 - 1 >= 0) {
        localB->x_data = b_idx_0;
      }

      for (flag = 0; flag < f_size_idx_0; flag++) {
        if (rtIsNaN(localB->x_data)) {
          localB->x_data = (rtNaN);
        } else if (localB->x_data < 0.0) {
          localB->x_data = -1.0;
        } else {
          localB->x_data = (localB->x_data > 0.0);
        }
      }

      if (g_size_idx_0 == trueCount) {
        i_size = g_size_idx_0;
        if (g_size_idx_0 - 1 >= 0) {
          localB->i_data = rt_atan2d_snf(localB->y_idx_1, localB->y_idx_0);
        }
      } else {
        if (g_size_idx_0 - 1 >= 0) {
          localB->y_data = localB->y_idx_1;
        }

        if (trueCount - 1 >= 0) {
          localB->y_data_m = localB->y_idx_0;
        }

        c6_formation_ros2_expand_atan2(&localB->y_data, &g_size_idx_0,
          &localB->y_data_m, &trueCount, &localB->i_data, &i_size);
      }

      if (rEQ0) {
        for (flag = 0; flag < 1; flag++) {
          tmp_data = 0;
        }
      }

      if (f_size_idx_0 == i_size) {
        if (f_size_idx_0 - 1 >= 0) {
          localB->eul[0] = -localB->x_data * 2.0 * localB->i_data;
        }
      } else {
        c6_formation_r_binary_expand_op(localB->eul, &tmp_data, &localB->x_data,
          &f_size_idx_0, &localB->i_data, &i_size);
      }

      localB->y_idx_0 = localB->eul[0] - localDW->yaw1;
      if (fabs(localB->y_idx_0) > 3.1415926535897931) {
        if (rtIsNaN(localB->y_idx_0 + 3.1415926535897931)) {
          localB->y_idx_1 = (rtNaN);
        } else if (rtIsInf(localB->y_idx_0 + 3.1415926535897931)) {
          localB->y_idx_1 = (rtNaN);
        } else if (localB->y_idx_0 + 3.1415926535897931 == 0.0) {
          localB->y_idx_1 = 0.0;
        } else {
          localB->y_idx_1 = fmod(localB->y_idx_0 + 3.1415926535897931,
            6.2831853071795862);
          rEQ0 = (localB->y_idx_1 == 0.0);
          if (!rEQ0) {
            localB->q = fabs((localB->y_idx_0 + 3.1415926535897931) /
                             6.2831853071795862);
            rEQ0 = !(fabs(localB->q - floor(localB->q + 0.5)) >
                     2.2204460492503131E-16 * localB->q);
          }

          if (rEQ0) {
            localB->y_idx_1 = 0.0;
          } else if (localB->y_idx_0 + 3.1415926535897931 < 0.0) {
            localB->y_idx_1 += 6.2831853071795862;
          }
        }

        if ((localB->y_idx_1 == 0.0) && (localB->y_idx_0 + 3.1415926535897931 >
             0.0)) {
          localB->y_idx_1 = 6.2831853071795862;
        }

        localB->y_idx_0 = localB->y_idx_1 - 3.1415926535897931;
      }

      localDW->yaw0 += localB->y_idx_0;
      localDW->yaw1 = localB->eul[0];
      flag = 0;
      localDW->x0_init = localDW->x0;
      localDW->y0_init = localDW->y0;
      localDW->yaw0_init = localDW->yaw0;
      localDW->fStart = 1.0;
    }
  } else {
    flag = (localDW->fStart != 0.0);
  }

  *rty_x_init = localDW->x0_init;
  *rty_y_init = localDW->y0_init;
  *rty_yaw_init = localDW->yaw0_init;
  *rty_flag = flag;
}

//
// Output and update for atomic system:
//    '<S18>/sensor2vCar4'
//    '<S79>/sensor2vCar4'
//    '<S140>/sensor2vCar4'
//    '<S201>/sensor2vCar4'
//    '<S262>/sensor2vCar4'
//    '<S323>/sensor2vCar4'
//
void c6_formation_ros2::c6_formation_ros2_sensor2vCar4(boolean_T rtu_VW_New,
  const SL_Bus_kkswarm_msgs_KKSwarmState *rtu_VW_Msg, real_T *rty_V, real_T
  *rty_W, DW_sensor2vCar4_c6_formation__T *localDW)
{
  if (rtu_VW_New) {
    localDW->v0 = rtu_VW_Msg->linear_speed;
    localDW->w0 = rtu_VW_Msg->angular_speed;
  }

  *rty_V = localDW->v0;
  *rty_W = localDW->w0;
}

// Function for Chart: '<Root>/Chart'
void c6_formation_ros2::c6_formation_ros2_vecnorm(const real_T x[12], real_T y[6])
{
  for (int32_T j = 0; j < 6; j++) {
    real_T b_y;
    real_T scale;
    int32_T ix0;
    ix0 = (j << 1) + 1;
    b_y = 0.0;
    scale = 3.3121686421112381E-170;
    for (int32_T k = ix0; k <= ix0 + 1; k++) {
      real_T absxk;
      absxk = fabs(x[k - 1]);
      if (absxk > scale) {
        real_T t;
        t = scale / absxk;
        b_y = b_y * t * t + 1.0;
        scale = absxk;
      } else {
        real_T t;
        t = absxk / scale;
        b_y += t * t;
      }
    }

    y[j] = scale * sqrt(b_y);
  }
}

// Function for Chart: '<Root>/Chart'
real_T c6_formation_ros2::c6_formation_ros2_angdiff(real_T x, real_T y)
{
  real_T delta;
  delta = y - x;
  if (fabs(delta) > 3.1415926535897931) {
    real_T thetaWrap;
    if (rtIsNaN(delta + 3.1415926535897931)) {
      thetaWrap = (rtNaN);
    } else if (rtIsInf(delta + 3.1415926535897931)) {
      thetaWrap = (rtNaN);
    } else if (delta + 3.1415926535897931 == 0.0) {
      thetaWrap = 0.0;
    } else {
      boolean_T rEQ0;
      thetaWrap = fmod(delta + 3.1415926535897931, 6.2831853071795862);
      rEQ0 = (thetaWrap == 0.0);
      if (!rEQ0) {
        real_T q;
        q = fabs((delta + 3.1415926535897931) / 6.2831853071795862);
        rEQ0 = !(fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q);
      }

      if (rEQ0) {
        thetaWrap = 0.0;
      } else if (delta + 3.1415926535897931 < 0.0) {
        thetaWrap += 6.2831853071795862;
      }
    }

    if ((thetaWrap == 0.0) && (delta + 3.1415926535897931 > 0.0)) {
      thetaWrap = 6.2831853071795862;
    }

    delta = thetaWrap - 3.1415926535897931;
  }

  return delta;
}

// Function for Chart: '<Root>/Chart'
real_T c6_formation_ros2::c6_formation_ros2_vecnorm_m(const real_T x[6])
{
  real_T scale;
  real_T y;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (int32_T k = 0; k < 6; k++) {
    real_T absxk;
    absxk = fabs(x[k]);
    if (absxk > scale) {
      real_T t;
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      real_T t;
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
real_T c6_formation_ros2::c6_formation_ros2_norm(const real_T x[2])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_form_modifyOverheadPhaseOne_
  (sIqAUiO7iN3zlnKzlJ0LdOE_c6_fo_T *obj)
{
  int32_T c;
  int32_T idxStartIneq;
  idxStartIneq = static_cast<uint8_T>(obj->sizes[0]);
  for (int32_T idx = 0; idx < idxStartIneq; idx++) {
    obj->ATwset[13 * idx + 12] = 0.0;
  }

  for (int32_T idx = 0; idx < 39; idx++) {
    obj->Aineq[13 * idx + 12] = -1.0;
  }

  obj->indexLB[obj->sizes[3] - 1] = 13;
  obj->lb[12] = obj->SLACK0;
  idxStartIneq = obj->isActiveIdx[2];
  c = obj->nActiveConstr;
  for (int32_T idx = idxStartIneq; idx <= c; idx++) {
    obj->ATwset[13 * (idx - 1) + 12] = -1.0;
  }

  if (obj->nWConstr[4] > 0) {
    idxStartIneq = static_cast<uint8_T>(obj->sizesNormal[4] + 1);
    for (int32_T idx = 0; idx < idxStartIneq; idx++) {
      obj->isActiveConstr[(obj->isActiveIdx[4] + idx) - 1] = false;
    }
  }

  obj->isActiveConstr[obj->isActiveIdx[4] - 2] = false;
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formation_ros_setProblemType
  (sIqAUiO7iN3zlnKzlJ0LdOE_c6_fo_T *obj, int32_T PROBLEM_TYPE)
{
  int32_T colOffsetATw;
  int32_T colOffsetAineq;
  int32_T i_tmp;
  int32_T idx;
  int32_T idx_lb;
  switch (PROBLEM_TYPE) {
   case 3:
    obj->nVar = 12;
    obj->mConstr = obj->mConstrOrig;
    if (obj->nWConstr[4] > 0) {
      idx_lb = static_cast<uint8_T>(obj->sizesNormal[4]);
      for (idx = 0; idx < idx_lb; idx++) {
        obj->isActiveConstr[(obj->isActiveIdxNormal[4] + idx) - 1] =
          obj->isActiveConstr[(obj->isActiveIdx[4] + idx) - 1];
      }
    }

    for (idx = 0; idx < 5; idx++) {
      obj->sizes[idx] = obj->sizesNormal[idx];
    }

    for (idx = 0; idx < 6; idx++) {
      obj->isActiveIdx[idx] = obj->isActiveIdxNormal[idx];
    }
    break;

   case 1:
    obj->nVar = 13;
    obj->mConstr = obj->mConstrOrig + 1;
    for (idx = 0; idx < 5; idx++) {
      obj->sizes[idx] = obj->sizesPhaseOne[idx];
    }

    for (idx = 0; idx < 6; idx++) {
      obj->isActiveIdx[idx] = obj->isActiveIdxPhaseOne[idx];
    }

    c6_form_modifyOverheadPhaseOne_(obj);
    break;

   case 2:
    obj->nVar = 12;
    obj->mConstr = 63;
    for (idx = 0; idx < 5; idx++) {
      obj->sizes[idx] = obj->sizesRegularized[idx];
    }

    if (obj->probType != 4) {
      for (idx = 0; idx < 39; idx++) {
        colOffsetAineq = 13 * idx;
        for (idx_lb = 13; idx_lb <= idx + 12; idx_lb++) {
          obj->Aineq[(idx_lb + colOffsetAineq) - 1] = 0.0;
        }

        obj->Aineq[(idx + colOffsetAineq) + 12] = -1.0;
      }

      idx_lb = 12;
      colOffsetAineq = obj->sizesNormal[3] + 1;
      colOffsetATw = obj->sizesRegularized[3];
      for (idx = colOffsetAineq; idx <= colOffsetATw; idx++) {
        idx_lb++;
        obj->indexLB[idx - 1] = idx_lb;
      }

      if (obj->nWConstr[4] > 0) {
        idx_lb = static_cast<uint8_T>(obj->sizesRegularized[4]);
        for (idx = 0; idx < idx_lb; idx++) {
          obj->isActiveConstr[obj->isActiveIdxRegularized[4] + idx] =
            obj->isActiveConstr[(obj->isActiveIdx[4] + idx) - 1];
        }
      }

      idx_lb = obj->isActiveIdx[4];
      colOffsetAineq = obj->isActiveIdxRegularized[4] - 1;
      if (idx_lb <= colOffsetAineq) {
        memset(&obj->isActiveConstr[idx_lb + -1], 0, static_cast<uint32_T>
               ((colOffsetAineq - idx_lb) + 1) * sizeof(boolean_T));
      }

      obj->lb[12] = 0.0;
      idx_lb = obj->isActiveIdx[2];
      colOffsetAineq = obj->nActiveConstr;
      for (idx = idx_lb; idx <= colOffsetAineq; idx++) {
        colOffsetATw = (idx - 1) * 13 - 1;
        if (obj->Wid[idx - 1] == 3) {
          i_tmp = obj->Wlocalidx[idx - 1];
          if (i_tmp + 11 >= 13) {
            memset(&obj->ATwset[colOffsetATw + 13], 0, static_cast<uint32_T>
                   ((((i_tmp + 11) + colOffsetATw) - colOffsetATw) - 12) *
                   sizeof(real_T));
          }

          obj->ATwset[(i_tmp + colOffsetATw) + 12] = -1.0;
          i_tmp += 13;
          if (i_tmp <= 12) {
            memset(&obj->ATwset[i_tmp + colOffsetATw], 0, static_cast<uint32_T>
                   (((colOffsetATw - i_tmp) - colOffsetATw) + 13) * sizeof
                   (real_T));
          }
        }
      }
    }

    for (idx = 0; idx < 6; idx++) {
      obj->isActiveIdx[idx] = obj->isActiveIdxRegularized[idx];
    }
    break;

   default:
    obj->nVar = 13;
    obj->mConstr = 64;
    for (idx = 0; idx < 5; idx++) {
      obj->sizes[idx] = obj->sizesRegPhaseOne[idx];
    }

    for (idx = 0; idx < 6; idx++) {
      obj->isActiveIdx[idx] = obj->isActiveIdxRegPhaseOne[idx];
    }

    c6_form_modifyOverheadPhaseOne_(obj);
    break;
  }

  obj->probType = PROBLEM_TYPE;
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
real_T c6_formation_ros2::c6_formation_ros2_xnrm2_p(int32_T n, const real_T x
  [832], int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      c6_formation_ros2_B.scale_g = 3.3121686421112381E-170;
      c6_formation_ros2_B.kend = (ix0 + n) - 1;
      for (c6_formation_ros2_B.k = ix0; c6_formation_ros2_B.k <=
           c6_formation_ros2_B.kend; c6_formation_ros2_B.k++) {
        c6_formation_ros2_B.absxk_g = fabs(x[c6_formation_ros2_B.k - 1]);
        if (c6_formation_ros2_B.absxk_g > c6_formation_ros2_B.scale_g) {
          c6_formation_ros2_B.t_m = c6_formation_ros2_B.scale_g /
            c6_formation_ros2_B.absxk_g;
          y = y * c6_formation_ros2_B.t_m * c6_formation_ros2_B.t_m + 1.0;
          c6_formation_ros2_B.scale_g = c6_formation_ros2_B.absxk_g;
        } else {
          c6_formation_ros2_B.t_m = c6_formation_ros2_B.absxk_g /
            c6_formation_ros2_B.scale_g;
          y += c6_formation_ros2_B.t_m * c6_formation_ros2_B.t_m;
        }
      }

      y = c6_formation_ros2_B.scale_g * sqrt(y);
    }
  }

  return y;
}

real_T c6_formation_ros2::c6_formation_ros2_rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  c6_formation_ros2_B.a_f = fabs(u0);
  c6_formation_ros2_B.b = fabs(u1);
  if (c6_formation_ros2_B.a_f < c6_formation_ros2_B.b) {
    c6_formation_ros2_B.a_f /= c6_formation_ros2_B.b;
    y = sqrt(c6_formation_ros2_B.a_f * c6_formation_ros2_B.a_f + 1.0) *
      c6_formation_ros2_B.b;
  } else if (c6_formation_ros2_B.a_f > c6_formation_ros2_B.b) {
    c6_formation_ros2_B.b /= c6_formation_ros2_B.a_f;
    y = sqrt(c6_formation_ros2_B.b * c6_formation_ros2_B.b + 1.0) *
      c6_formation_ros2_B.a_f;
  } else if (rtIsNaN(c6_formation_ros2_B.b)) {
    y = (rtNaN);
  } else {
    y = c6_formation_ros2_B.a_f * 1.4142135623730951;
  }

  return y;
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
real_T c6_formation_ros2::c6_formation_ros2_xzlarfg(int32_T n, real_T *alpha1,
  real_T x[832], int32_T ix0)
{
  __m128d tmp;
  real_T tau;
  tau = 0.0;
  if (n > 0) {
    c6_formation_ros2_B.xnorm = c6_formation_ros2_xnrm2_p(n - 1, x, ix0);
    if (c6_formation_ros2_B.xnorm != 0.0) {
      c6_formation_ros2_B.xnorm = c6_formation_ros2_rt_hypotd_snf(*alpha1,
        c6_formation_ros2_B.xnorm);
      if (*alpha1 >= 0.0) {
        c6_formation_ros2_B.xnorm = -c6_formation_ros2_B.xnorm;
      }

      if (fabs(c6_formation_ros2_B.xnorm) < 1.0020841800044864E-292) {
        c6_formation_ros2_B.knt = 0;
        c6_formation_ros2_B.scalarLB = (ix0 + n) - 2;
        do {
          c6_formation_ros2_B.knt++;
          c6_formation_ros2_B.vectorUB = ((((c6_formation_ros2_B.scalarLB - ix0)
            + 1) / 2) << 1) + ix0;
          c6_formation_ros2_B.vectorUB_tmp = c6_formation_ros2_B.vectorUB - 2;
          for (c6_formation_ros2_B.d_j = ix0; c6_formation_ros2_B.d_j <=
               c6_formation_ros2_B.vectorUB_tmp; c6_formation_ros2_B.d_j += 2) {
            tmp = _mm_loadu_pd(&x[c6_formation_ros2_B.d_j - 1]);
            _mm_storeu_pd(&x[c6_formation_ros2_B.d_j - 1], _mm_mul_pd(tmp,
              _mm_set1_pd(9.9792015476736E+291)));
          }

          for (c6_formation_ros2_B.d_j = c6_formation_ros2_B.vectorUB;
               c6_formation_ros2_B.d_j <= c6_formation_ros2_B.scalarLB;
               c6_formation_ros2_B.d_j++) {
            x[c6_formation_ros2_B.d_j - 1] *= 9.9792015476736E+291;
          }

          c6_formation_ros2_B.xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((fabs(c6_formation_ros2_B.xnorm) < 1.0020841800044864E-292) &&
                 (c6_formation_ros2_B.knt < 20));

        c6_formation_ros2_B.xnorm = c6_formation_ros2_rt_hypotd_snf(*alpha1,
          c6_formation_ros2_xnrm2_p(n - 1, x, ix0));
        if (*alpha1 >= 0.0) {
          c6_formation_ros2_B.xnorm = -c6_formation_ros2_B.xnorm;
        }

        tau = (c6_formation_ros2_B.xnorm - *alpha1) / c6_formation_ros2_B.xnorm;
        c6_formation_ros2_B.a = 1.0 / (*alpha1 - c6_formation_ros2_B.xnorm);
        for (c6_formation_ros2_B.d_j = ix0; c6_formation_ros2_B.d_j <=
             c6_formation_ros2_B.vectorUB_tmp; c6_formation_ros2_B.d_j += 2) {
          tmp = _mm_loadu_pd(&x[c6_formation_ros2_B.d_j - 1]);
          _mm_storeu_pd(&x[c6_formation_ros2_B.d_j - 1], _mm_mul_pd(tmp,
            _mm_set1_pd(c6_formation_ros2_B.a)));
        }

        for (c6_formation_ros2_B.d_j = c6_formation_ros2_B.vectorUB;
             c6_formation_ros2_B.d_j <= c6_formation_ros2_B.scalarLB;
             c6_formation_ros2_B.d_j++) {
          x[c6_formation_ros2_B.d_j - 1] *= c6_formation_ros2_B.a;
        }

        for (c6_formation_ros2_B.d_j = 0; c6_formation_ros2_B.d_j <
             c6_formation_ros2_B.knt; c6_formation_ros2_B.d_j++) {
          c6_formation_ros2_B.xnorm *= 1.0020841800044864E-292;
        }

        *alpha1 = c6_formation_ros2_B.xnorm;
      } else {
        tau = (c6_formation_ros2_B.xnorm - *alpha1) / c6_formation_ros2_B.xnorm;
        c6_formation_ros2_B.a = 1.0 / (*alpha1 - c6_formation_ros2_B.xnorm);
        c6_formation_ros2_B.d_j = (ix0 + n) - 2;
        c6_formation_ros2_B.scalarLB = ((((c6_formation_ros2_B.d_j - ix0) + 1) /
          2) << 1) + ix0;
        c6_formation_ros2_B.vectorUB = c6_formation_ros2_B.scalarLB - 2;
        for (c6_formation_ros2_B.knt = ix0; c6_formation_ros2_B.knt <=
             c6_formation_ros2_B.vectorUB; c6_formation_ros2_B.knt += 2) {
          tmp = _mm_loadu_pd(&x[c6_formation_ros2_B.knt - 1]);
          _mm_storeu_pd(&x[c6_formation_ros2_B.knt - 1], _mm_mul_pd(tmp,
            _mm_set1_pd(c6_formation_ros2_B.a)));
        }

        for (c6_formation_ros2_B.knt = c6_formation_ros2_B.scalarLB;
             c6_formation_ros2_B.knt <= c6_formation_ros2_B.d_j;
             c6_formation_ros2_B.knt++) {
          x[c6_formation_ros2_B.knt - 1] *= c6_formation_ros2_B.a;
        }

        *alpha1 = c6_formation_ros2_B.xnorm;
      }
    }
  }

  return tau;
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formation_ros2_xzlarf(int32_T m, int32_T n, int32_T
  iv0, real_T tau, real_T C[832], int32_T ic0, real_T work[64])
{
  if (tau != 0.0) {
    boolean_T exitg2;
    c6_formation_ros2_B.lastv = m;
    c6_formation_ros2_B.lastc_h = iv0 + m;
    while ((c6_formation_ros2_B.lastv > 0) && (C[c6_formation_ros2_B.lastc_h - 2]
            == 0.0)) {
      c6_formation_ros2_B.lastv--;
      c6_formation_ros2_B.lastc_h--;
    }

    c6_formation_ros2_B.lastc_h = n;
    exitg2 = false;
    while ((!exitg2) && (c6_formation_ros2_B.lastc_h > 0)) {
      int32_T exitg1;
      c6_formation_ros2_B.coltop_k = (c6_formation_ros2_B.lastc_h - 1) * 13 +
        ic0;
      c6_formation_ros2_B.b_ia = c6_formation_ros2_B.coltop_k;
      do {
        exitg1 = 0;
        if (c6_formation_ros2_B.b_ia <= (c6_formation_ros2_B.coltop_k +
             c6_formation_ros2_B.lastv) - 1) {
          if (C[c6_formation_ros2_B.b_ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            c6_formation_ros2_B.b_ia++;
          }
        } else {
          c6_formation_ros2_B.lastc_h--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    c6_formation_ros2_B.lastc_h--;
  } else {
    c6_formation_ros2_B.lastv = 0;
    c6_formation_ros2_B.lastc_h = -1;
  }

  if (c6_formation_ros2_B.lastv > 0) {
    if (c6_formation_ros2_B.lastc_h + 1 != 0) {
      if (c6_formation_ros2_B.lastc_h >= 0) {
        memset(&work[0], 0, static_cast<uint32_T>(c6_formation_ros2_B.lastc_h +
                1) * sizeof(real_T));
      }

      c6_formation_ros2_B.jA_p = 13 * c6_formation_ros2_B.lastc_h + ic0;
      for (c6_formation_ros2_B.coltop_k = ic0; c6_formation_ros2_B.coltop_k <=
           c6_formation_ros2_B.jA_p; c6_formation_ros2_B.coltop_k += 13) {
        c6_formation_ros2_B.c_j = 0.0;
        c6_formation_ros2_B.d_cs = (c6_formation_ros2_B.coltop_k +
          c6_formation_ros2_B.lastv) - 1;
        for (c6_formation_ros2_B.b_ia = c6_formation_ros2_B.coltop_k;
             c6_formation_ros2_B.b_ia <= c6_formation_ros2_B.d_cs;
             c6_formation_ros2_B.b_ia++) {
          c6_formation_ros2_B.c_j += C[((iv0 + c6_formation_ros2_B.b_ia) -
            c6_formation_ros2_B.coltop_k) - 1] * C[c6_formation_ros2_B.b_ia - 1];
        }

        c6_formation_ros2_B.b_ia = div_nde_s32_floor
          (c6_formation_ros2_B.coltop_k - ic0, 13);
        work[c6_formation_ros2_B.b_ia] += c6_formation_ros2_B.c_j;
      }
    }

    if (!(-tau == 0.0)) {
      c6_formation_ros2_B.jA_p = ic0;
      for (c6_formation_ros2_B.coltop_k = 0; c6_formation_ros2_B.coltop_k <=
           c6_formation_ros2_B.lastc_h; c6_formation_ros2_B.coltop_k++) {
        c6_formation_ros2_B.c_j = work[c6_formation_ros2_B.coltop_k];
        if (c6_formation_ros2_B.c_j != 0.0) {
          c6_formation_ros2_B.c_j *= -tau;
          c6_formation_ros2_B.d_cs = c6_formation_ros2_B.lastv +
            c6_formation_ros2_B.jA_p;
          for (c6_formation_ros2_B.b_ia = c6_formation_ros2_B.jA_p;
               c6_formation_ros2_B.b_ia < c6_formation_ros2_B.d_cs;
               c6_formation_ros2_B.b_ia++) {
            C[c6_formation_ros2_B.b_ia - 1] += C[((iv0 +
              c6_formation_ros2_B.b_ia) - c6_formation_ros2_B.jA_p) - 1] *
              c6_formation_ros2_B.c_j;
          }
        }

        c6_formation_ros2_B.jA_p += 13;
      }
    }
  }
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formation_ros2_qrf(real_T A[832], int32_T m, int32_T
  n, int32_T nfxd, real_T tau[13])
{
  memset(&c6_formation_ros2_B.work_m[0], 0, sizeof(real_T) << 6U);
  c6_formation_ros2_B.b_m = static_cast<uint8_T>(nfxd);
  for (c6_formation_ros2_B.i_m = 0; c6_formation_ros2_B.i_m <
       c6_formation_ros2_B.b_m; c6_formation_ros2_B.i_m++) {
    c6_formation_ros2_B.ii = c6_formation_ros2_B.i_m * 13 +
      c6_formation_ros2_B.i_m;
    c6_formation_ros2_B.mmi_c = m - c6_formation_ros2_B.i_m;
    if (c6_formation_ros2_B.i_m + 1 < m) {
      c6_formation_ros2_B.b_atmp = A[c6_formation_ros2_B.ii];
      c6_formation_ros2_B.tau = c6_formation_ros2_xzlarfg
        (c6_formation_ros2_B.mmi_c, &c6_formation_ros2_B.b_atmp, A,
         c6_formation_ros2_B.ii + 2);
      tau[c6_formation_ros2_B.i_m] = c6_formation_ros2_B.tau;
      A[c6_formation_ros2_B.ii] = c6_formation_ros2_B.b_atmp;
    } else {
      c6_formation_ros2_B.tau = 0.0;
      tau[c6_formation_ros2_B.i_m] = 0.0;
    }

    if (c6_formation_ros2_B.i_m + 1 < n) {
      c6_formation_ros2_B.b_atmp = A[c6_formation_ros2_B.ii];
      A[c6_formation_ros2_B.ii] = 1.0;
      c6_formation_ros2_xzlarf(c6_formation_ros2_B.mmi_c, (n -
        c6_formation_ros2_B.i_m) - 1, c6_formation_ros2_B.ii + 1,
        c6_formation_ros2_B.tau, A, c6_formation_ros2_B.ii + 14,
        c6_formation_ros2_B.work_m);
      A[c6_formation_ros2_B.ii] = c6_formation_ros2_B.b_atmp;
    }
  }
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formation_ros2_factorQRE
  (s2v85VDFdoXWosLJGoY94IG_c6_fo_T *obj, int32_T mrows, int32_T ncols)
{
  static const int32_T offsets[4] = { 0, 1, 2, 3 };

  if (mrows * ncols == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    obj->usedPivoting = true;
    obj->mrows = mrows;
    obj->ncols = ncols;
    if (mrows <= ncols) {
      c6_formation_ros2_B.u1 = mrows;
    } else {
      c6_formation_ros2_B.u1 = ncols;
    }

    obj->minRowCol = c6_formation_ros2_B.u1;
    memset(&obj->tau[0], 0, 13U * sizeof(real_T));
    if (c6_formation_ros2_B.u1 < 1) {
      c6_formation_ros2_B.nfxd = (ncols / 4) << 2;
      c6_formation_ros2_B.i_o = c6_formation_ros2_B.nfxd - 4;
      for (c6_formation_ros2_B.u1 = 0; c6_formation_ros2_B.u1 <=
           c6_formation_ros2_B.i_o; c6_formation_ros2_B.u1 += 4) {
        _mm_storeu_si128((__m128i *)&obj->jpvt[c6_formation_ros2_B.u1],
                         _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32
          (c6_formation_ros2_B.u1), _mm_loadu_si128((const __m128i *)&offsets[0])),
          _mm_set1_epi32(1)));
      }

      for (c6_formation_ros2_B.u1 = c6_formation_ros2_B.nfxd;
           c6_formation_ros2_B.u1 < ncols; c6_formation_ros2_B.u1++) {
        obj->jpvt[c6_formation_ros2_B.u1] = c6_formation_ros2_B.u1 + 1;
      }
    } else {
      c6_formation_ros2_B.nfxd = -1;
      for (c6_formation_ros2_B.i_o = 0; c6_formation_ros2_B.i_o < ncols;
           c6_formation_ros2_B.i_o++) {
        if (obj->jpvt[c6_formation_ros2_B.i_o] != 0) {
          c6_formation_ros2_B.nfxd++;
          if (c6_formation_ros2_B.i_o + 1 != c6_formation_ros2_B.nfxd + 1) {
            c6_formation_ros2_B.ix_i = c6_formation_ros2_B.i_o * 13;
            c6_formation_ros2_B.iy = c6_formation_ros2_B.nfxd * 13;
            for (c6_formation_ros2_B.mmi = 0; c6_formation_ros2_B.mmi < mrows;
                 c6_formation_ros2_B.mmi++) {
              c6_formation_ros2_B.temp_tmp_n = c6_formation_ros2_B.ix_i +
                c6_formation_ros2_B.mmi;
              c6_formation_ros2_B.temp = obj->QR[c6_formation_ros2_B.temp_tmp_n];
              c6_formation_ros2_B.itemp = c6_formation_ros2_B.iy +
                c6_formation_ros2_B.mmi;
              obj->QR[c6_formation_ros2_B.temp_tmp_n] = obj->
                QR[c6_formation_ros2_B.itemp];
              obj->QR[c6_formation_ros2_B.itemp] = c6_formation_ros2_B.temp;
            }

            obj->jpvt[c6_formation_ros2_B.i_o] = obj->
              jpvt[c6_formation_ros2_B.nfxd];
            obj->jpvt[c6_formation_ros2_B.nfxd] = c6_formation_ros2_B.i_o + 1;
          } else {
            obj->jpvt[c6_formation_ros2_B.i_o] = c6_formation_ros2_B.i_o + 1;
          }
        } else {
          obj->jpvt[c6_formation_ros2_B.i_o] = c6_formation_ros2_B.i_o + 1;
        }
      }

      if (c6_formation_ros2_B.nfxd + 1 <= c6_formation_ros2_B.u1) {
        c6_formation_ros2_B.nfxd++;
      } else {
        c6_formation_ros2_B.nfxd = c6_formation_ros2_B.u1;
      }

      memset(&obj->tau[0], 0, 13U * sizeof(real_T));
      c6_formation_ros2_qrf(obj->QR, mrows, ncols, c6_formation_ros2_B.nfxd,
                            obj->tau);
      if (c6_formation_ros2_B.nfxd < c6_formation_ros2_B.u1) {
        memset(&c6_formation_ros2_B.work[0], 0, sizeof(real_T) << 6U);
        memset(&c6_formation_ros2_B.vn1[0], 0, sizeof(real_T) << 6U);
        memset(&c6_formation_ros2_B.vn2[0], 0, sizeof(real_T) << 6U);
        for (c6_formation_ros2_B.i_o = c6_formation_ros2_B.nfxd + 1;
             c6_formation_ros2_B.i_o <= ncols; c6_formation_ros2_B.i_o++) {
          c6_formation_ros2_B.temp = c6_formation_ros2_xnrm2_p(mrows -
            c6_formation_ros2_B.nfxd, obj->QR, ((c6_formation_ros2_B.i_o - 1) *
            13 + c6_formation_ros2_B.nfxd) + 1);
          c6_formation_ros2_B.vn1[c6_formation_ros2_B.i_o - 1] =
            c6_formation_ros2_B.temp;
          c6_formation_ros2_B.vn2[c6_formation_ros2_B.i_o - 1] =
            c6_formation_ros2_B.temp;
        }

        for (c6_formation_ros2_B.i_o = c6_formation_ros2_B.nfxd + 1;
             c6_formation_ros2_B.i_o <= c6_formation_ros2_B.u1;
             c6_formation_ros2_B.i_o++) {
          c6_formation_ros2_B.temp_tmp_n = (c6_formation_ros2_B.i_o - 1) * 13;
          c6_formation_ros2_B.ix_i = (c6_formation_ros2_B.temp_tmp_n +
            c6_formation_ros2_B.i_o) - 1;
          c6_formation_ros2_B.iy = ncols - c6_formation_ros2_B.i_o;
          c6_formation_ros2_B.mmi = mrows - c6_formation_ros2_B.i_o;
          if (c6_formation_ros2_B.iy + 1 < 1) {
            c6_formation_ros2_B.pvt = -2;
          } else {
            c6_formation_ros2_B.pvt = -1;
            if (c6_formation_ros2_B.iy + 1 > 1) {
              c6_formation_ros2_B.temp = fabs
                (c6_formation_ros2_B.vn1[c6_formation_ros2_B.i_o - 1]);
              for (c6_formation_ros2_B.itemp = 2; c6_formation_ros2_B.itemp <=
                   c6_formation_ros2_B.iy + 1; c6_formation_ros2_B.itemp++) {
                c6_formation_ros2_B.s = fabs(c6_formation_ros2_B.vn1
                  [(c6_formation_ros2_B.i_o + c6_formation_ros2_B.itemp) - 2]);
                if (c6_formation_ros2_B.s > c6_formation_ros2_B.temp) {
                  c6_formation_ros2_B.pvt = c6_formation_ros2_B.itemp - 2;
                  c6_formation_ros2_B.temp = c6_formation_ros2_B.s;
                }
              }
            }
          }

          c6_formation_ros2_B.pvt += c6_formation_ros2_B.i_o;
          if (c6_formation_ros2_B.pvt + 1 != c6_formation_ros2_B.i_o) {
            c6_formation_ros2_B.c_ix = c6_formation_ros2_B.pvt * 13;
            for (c6_formation_ros2_B.c_k = 0; c6_formation_ros2_B.c_k < mrows;
                 c6_formation_ros2_B.c_k++) {
              c6_formation_ros2_B.b_temp_tmp_m = c6_formation_ros2_B.c_ix +
                c6_formation_ros2_B.c_k;
              c6_formation_ros2_B.temp = obj->
                QR[c6_formation_ros2_B.b_temp_tmp_m];
              c6_formation_ros2_B.itemp = c6_formation_ros2_B.temp_tmp_n +
                c6_formation_ros2_B.c_k;
              obj->QR[c6_formation_ros2_B.b_temp_tmp_m] = obj->
                QR[c6_formation_ros2_B.itemp];
              obj->QR[c6_formation_ros2_B.itemp] = c6_formation_ros2_B.temp;
            }

            c6_formation_ros2_B.itemp = obj->jpvt[c6_formation_ros2_B.pvt];
            obj->jpvt[c6_formation_ros2_B.pvt] = obj->
              jpvt[c6_formation_ros2_B.i_o - 1];
            obj->jpvt[c6_formation_ros2_B.i_o - 1] = c6_formation_ros2_B.itemp;
            c6_formation_ros2_B.vn1[c6_formation_ros2_B.pvt] =
              c6_formation_ros2_B.vn1[c6_formation_ros2_B.i_o - 1];
            c6_formation_ros2_B.vn2[c6_formation_ros2_B.pvt] =
              c6_formation_ros2_B.vn2[c6_formation_ros2_B.i_o - 1];
          }

          if (c6_formation_ros2_B.i_o < mrows) {
            c6_formation_ros2_B.temp = obj->QR[c6_formation_ros2_B.ix_i];
            obj->tau[c6_formation_ros2_B.i_o - 1] = c6_formation_ros2_xzlarfg
              (c6_formation_ros2_B.mmi + 1, &c6_formation_ros2_B.temp, obj->QR,
               c6_formation_ros2_B.ix_i + 2);
            obj->QR[c6_formation_ros2_B.ix_i] = c6_formation_ros2_B.temp;
          } else {
            obj->tau[c6_formation_ros2_B.i_o - 1] = 0.0;
          }

          if (c6_formation_ros2_B.i_o < ncols) {
            c6_formation_ros2_B.temp = obj->QR[c6_formation_ros2_B.ix_i];
            obj->QR[c6_formation_ros2_B.ix_i] = 1.0;
            c6_formation_ros2_xzlarf(c6_formation_ros2_B.mmi + 1,
              c6_formation_ros2_B.iy, c6_formation_ros2_B.ix_i + 1, obj->
              tau[c6_formation_ros2_B.i_o - 1], obj->QR,
              c6_formation_ros2_B.ix_i + 14, c6_formation_ros2_B.work);
            obj->QR[c6_formation_ros2_B.ix_i] = c6_formation_ros2_B.temp;
          }

          for (c6_formation_ros2_B.itemp = c6_formation_ros2_B.i_o + 1;
               c6_formation_ros2_B.itemp <= ncols; c6_formation_ros2_B.itemp++)
          {
            c6_formation_ros2_B.ix_i = (c6_formation_ros2_B.itemp - 1) * 13 +
              c6_formation_ros2_B.i_o;
            c6_formation_ros2_B.temp =
              c6_formation_ros2_B.vn1[c6_formation_ros2_B.itemp - 1];
            if (c6_formation_ros2_B.temp != 0.0) {
              c6_formation_ros2_B.s = fabs(obj->QR[c6_formation_ros2_B.ix_i - 1])
                / c6_formation_ros2_B.temp;
              c6_formation_ros2_B.s = 1.0 - c6_formation_ros2_B.s *
                c6_formation_ros2_B.s;
              if (c6_formation_ros2_B.s < 0.0) {
                c6_formation_ros2_B.s = 0.0;
              }

              c6_formation_ros2_B.temp2 = c6_formation_ros2_B.temp /
                c6_formation_ros2_B.vn2[c6_formation_ros2_B.itemp - 1];
              c6_formation_ros2_B.temp2 = c6_formation_ros2_B.temp2 *
                c6_formation_ros2_B.temp2 * c6_formation_ros2_B.s;
              if (c6_formation_ros2_B.temp2 <= 1.4901161193847656E-8) {
                if (c6_formation_ros2_B.i_o < mrows) {
                  c6_formation_ros2_B.temp = c6_formation_ros2_xnrm2_p
                    (c6_formation_ros2_B.mmi, obj->QR, c6_formation_ros2_B.ix_i
                     + 1);
                  c6_formation_ros2_B.vn1[c6_formation_ros2_B.itemp - 1] =
                    c6_formation_ros2_B.temp;
                  c6_formation_ros2_B.vn2[c6_formation_ros2_B.itemp - 1] =
                    c6_formation_ros2_B.temp;
                } else {
                  c6_formation_ros2_B.vn1[c6_formation_ros2_B.itemp - 1] = 0.0;
                  c6_formation_ros2_B.vn2[c6_formation_ros2_B.itemp - 1] = 0.0;
                }
              } else {
                c6_formation_ros2_B.vn1[c6_formation_ros2_B.itemp - 1] =
                  c6_formation_ros2_B.temp * sqrt(c6_formation_ros2_B.s);
              }
            }
          }
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formation_ros2_computeQ_
  (s2v85VDFdoXWosLJGoY94IG_c6_fo_T *obj, int32_T nrows)
{
  c6_formation_ros2_B.i_p = obj->minRowCol;
  for (c6_formation_ros2_B.idx_p = 0; c6_formation_ros2_B.idx_p <
       c6_formation_ros2_B.i_p; c6_formation_ros2_B.idx_p++) {
    c6_formation_ros2_B.iQR0 = 13 * c6_formation_ros2_B.idx_p +
      c6_formation_ros2_B.idx_p;
    c6_formation_ros2_B.ia = obj->mrows - c6_formation_ros2_B.idx_p;
    if (c6_formation_ros2_B.ia - 2 >= 0) {
      memcpy(&obj->Q[c6_formation_ros2_B.iQR0 + 1], &obj->
             QR[c6_formation_ros2_B.iQR0 + 1], static_cast<uint32_T>
             (((c6_formation_ros2_B.ia + c6_formation_ros2_B.iQR0) -
               c6_formation_ros2_B.iQR0) - 1) * sizeof(real_T));
    }
  }

  c6_formation_ros2_B.idx_p = obj->mrows;
  if (nrows >= 1) {
    for (c6_formation_ros2_B.itau = c6_formation_ros2_B.i_p;
         c6_formation_ros2_B.itau < nrows; c6_formation_ros2_B.itau++) {
      c6_formation_ros2_B.ia = c6_formation_ros2_B.itau * 13;
      memset(&obj->Q[c6_formation_ros2_B.ia], 0, static_cast<uint32_T>
             ((c6_formation_ros2_B.idx_p + c6_formation_ros2_B.ia) -
              c6_formation_ros2_B.ia) * sizeof(real_T));
      obj->Q[c6_formation_ros2_B.ia + c6_formation_ros2_B.itau] = 1.0;
    }

    c6_formation_ros2_B.itau = obj->minRowCol - 1;
    memset(&c6_formation_ros2_B.work_p[0], 0, 13U * sizeof(real_T));
    c6_formation_ros2_B.i_p = obj->minRowCol;
    while (c6_formation_ros2_B.i_p >= 1) {
      c6_formation_ros2_B.iQR0 = ((c6_formation_ros2_B.i_p - 1) * 13 +
        c6_formation_ros2_B.i_p) - 1;
      if (c6_formation_ros2_B.i_p < nrows) {
        obj->Q[c6_formation_ros2_B.iQR0] = 1.0;
        c6_formation_ros2_B.ia = c6_formation_ros2_B.idx_p -
          c6_formation_ros2_B.i_p;
        if (obj->tau[c6_formation_ros2_B.itau] != 0.0) {
          boolean_T exitg2;
          c6_formation_ros2_B.lastc = c6_formation_ros2_B.iQR0 +
            c6_formation_ros2_B.ia;
          while ((c6_formation_ros2_B.ia + 1 > 0) && (obj->
                  Q[c6_formation_ros2_B.lastc] == 0.0)) {
            c6_formation_ros2_B.ia--;
            c6_formation_ros2_B.lastc--;
          }

          c6_formation_ros2_B.lastc = nrows - c6_formation_ros2_B.i_p;
          exitg2 = false;
          while ((!exitg2) && (c6_formation_ros2_B.lastc > 0)) {
            int32_T exitg1;
            c6_formation_ros2_B.coltop = ((c6_formation_ros2_B.lastc - 1) * 13 +
              c6_formation_ros2_B.iQR0) + 14;
            c6_formation_ros2_B.c_ia = c6_formation_ros2_B.coltop;
            do {
              exitg1 = 0;
              if (c6_formation_ros2_B.c_ia <= c6_formation_ros2_B.coltop +
                  c6_formation_ros2_B.ia) {
                if (obj->Q[c6_formation_ros2_B.c_ia - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  c6_formation_ros2_B.c_ia++;
                }
              } else {
                c6_formation_ros2_B.lastc--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }

          c6_formation_ros2_B.lastc--;
        } else {
          c6_formation_ros2_B.ia = -1;
          c6_formation_ros2_B.lastc = -1;
        }

        if (c6_formation_ros2_B.ia + 1 > 0) {
          if (c6_formation_ros2_B.lastc + 1 != 0) {
            if (c6_formation_ros2_B.lastc >= 0) {
              memset(&c6_formation_ros2_B.work_p[0], 0, static_cast<uint32_T>
                     (c6_formation_ros2_B.lastc + 1) * sizeof(real_T));
            }

            c6_formation_ros2_B.c_ia = (13 * c6_formation_ros2_B.lastc +
              c6_formation_ros2_B.iQR0) + 14;
            for (c6_formation_ros2_B.coltop = c6_formation_ros2_B.iQR0 + 14;
                 c6_formation_ros2_B.coltop <= c6_formation_ros2_B.c_ia;
                 c6_formation_ros2_B.coltop += 13) {
              c6_formation_ros2_B.b_c = 0.0;
              c6_formation_ros2_B.f = c6_formation_ros2_B.coltop +
                c6_formation_ros2_B.ia;
              for (c6_formation_ros2_B.jA = c6_formation_ros2_B.coltop;
                   c6_formation_ros2_B.jA <= c6_formation_ros2_B.f;
                   c6_formation_ros2_B.jA++) {
                c6_formation_ros2_B.b_c += obj->Q[(c6_formation_ros2_B.iQR0 +
                  c6_formation_ros2_B.jA) - c6_formation_ros2_B.coltop] * obj->
                  Q[c6_formation_ros2_B.jA - 1];
              }

              c6_formation_ros2_B.jA = div_nde_s32_floor
                ((c6_formation_ros2_B.coltop - c6_formation_ros2_B.iQR0) - 14,
                 13);
              c6_formation_ros2_B.work_p[c6_formation_ros2_B.jA] +=
                c6_formation_ros2_B.b_c;
            }
          }

          if (!(-obj->tau[c6_formation_ros2_B.itau] == 0.0)) {
            c6_formation_ros2_B.jA = c6_formation_ros2_B.iQR0 + 14;
            for (c6_formation_ros2_B.coltop = 0; c6_formation_ros2_B.coltop <=
                 c6_formation_ros2_B.lastc; c6_formation_ros2_B.coltop++) {
              c6_formation_ros2_B.b_c =
                c6_formation_ros2_B.work_p[c6_formation_ros2_B.coltop];
              if (c6_formation_ros2_B.b_c != 0.0) {
                c6_formation_ros2_B.b_c *= -obj->tau[c6_formation_ros2_B.itau];
                c6_formation_ros2_B.f = c6_formation_ros2_B.ia +
                  c6_formation_ros2_B.jA;
                for (c6_formation_ros2_B.c_ia = c6_formation_ros2_B.jA;
                     c6_formation_ros2_B.c_ia <= c6_formation_ros2_B.f;
                     c6_formation_ros2_B.c_ia++) {
                  obj->Q[c6_formation_ros2_B.c_ia - 1] += obj->Q
                    [(c6_formation_ros2_B.iQR0 + c6_formation_ros2_B.c_ia) -
                    c6_formation_ros2_B.jA] * c6_formation_ros2_B.b_c;
                }
              }

              c6_formation_ros2_B.jA += 13;
            }
          }
        }
      }

      if (c6_formation_ros2_B.i_p < c6_formation_ros2_B.idx_p) {
        c6_formation_ros2_B.lastc = ((c6_formation_ros2_B.iQR0 +
          c6_formation_ros2_B.idx_p) - c6_formation_ros2_B.i_p) + 1;
        for (c6_formation_ros2_B.ia = c6_formation_ros2_B.iQR0 + 2;
             c6_formation_ros2_B.ia <= c6_formation_ros2_B.lastc;
             c6_formation_ros2_B.ia++) {
          obj->Q[c6_formation_ros2_B.ia - 1] *= -obj->
            tau[c6_formation_ros2_B.itau];
        }
      }

      obj->Q[c6_formation_ros2_B.iQR0] = 1.0 - obj->tau[c6_formation_ros2_B.itau];
      c6_formation_ros2_B.lastc = static_cast<uint8_T>(c6_formation_ros2_B.i_p -
        1);
      for (c6_formation_ros2_B.ia = 0; c6_formation_ros2_B.ia <
           c6_formation_ros2_B.lastc; c6_formation_ros2_B.ia++) {
        obj->Q[(c6_formation_ros2_B.iQR0 - c6_formation_ros2_B.ia) - 1] = 0.0;
      }

      c6_formation_ros2_B.itau--;
      c6_formation_ros2_B.i_p--;
    }
  }
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formation_ros2_countsort(int32_T x[64], int32_T xLen,
  int32_T workspace[64], int32_T xMin, int32_T xMax)
{
  if ((xLen > 1) && (xMax > xMin)) {
    int32_T b_tmp;
    int32_T idxEnd;
    int32_T idxFill;
    int32_T idxStart;
    int32_T maxOffset;
    b_tmp = xMax - xMin;
    if (b_tmp >= 0) {
      memset(&workspace[0], 0, static_cast<uint32_T>(b_tmp + 1) * sizeof(int32_T));
    }

    maxOffset = b_tmp - 1;
    for (b_tmp = 0; b_tmp < xLen; b_tmp++) {
      idxFill = x[b_tmp] - xMin;
      workspace[idxFill]++;
    }

    for (b_tmp = 2; b_tmp <= maxOffset + 2; b_tmp++) {
      workspace[b_tmp - 1] += workspace[b_tmp - 2];
    }

    idxStart = 1;
    idxEnd = workspace[0];
    for (b_tmp = 0; b_tmp <= maxOffset; b_tmp++) {
      for (idxFill = idxStart; idxFill <= idxEnd; idxFill++) {
        x[idxFill - 1] = b_tmp + xMin;
      }

      idxStart = workspace[b_tmp] + 1;
      idxEnd = workspace[b_tmp + 1];
    }

    for (maxOffset = idxStart; maxOffset <= idxEnd; maxOffset++) {
      x[maxOffset - 1] = xMax;
    }
  }
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formation_ros2_removeConstr
  (sIqAUiO7iN3zlnKzlJ0LdOE_c6_fo_T *obj, int32_T idx_global)
{
  int32_T TYPE_tmp;
  int32_T b;
  TYPE_tmp = obj->Wid[idx_global - 1] - 1;
  obj->isActiveConstr[(obj->isActiveIdx[TYPE_tmp] + obj->Wlocalidx[idx_global -
                       1]) - 2] = false;
  obj->Wid[idx_global - 1] = obj->Wid[obj->nActiveConstr - 1];
  obj->Wlocalidx[idx_global - 1] = obj->Wlocalidx[obj->nActiveConstr - 1];
  b = static_cast<uint8_T>(obj->nVar);
  for (int32_T idx = 0; idx < b; idx++) {
    obj->ATwset[idx + 13 * (idx_global - 1)] = obj->ATwset[(obj->nActiveConstr -
      1) * 13 + idx];
  }

  obj->bwset[idx_global - 1] = obj->bwset[obj->nActiveConstr - 1];
  obj->nActiveConstr--;
  obj->nWConstr[TYPE_tmp]--;
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formation_ros_removeEqConstr
  (sIqAUiO7iN3zlnKzlJ0LdOE_c6_fo_T *obj, int32_T idx_global)
{
  int32_T TYPE_tmp;
  int32_T b_tmp;
  int32_T idx;
  int32_T totalEq;
  totalEq = (obj->nWConstr[0] + obj->nWConstr[1]) - 1;
  if ((totalEq + 1 != 0) && (idx_global <= totalEq + 1)) {
    if ((totalEq + 1 == obj->nActiveConstr) || (totalEq + 1 == idx_global)) {
      obj->mEqRemoved++;
      c6_formation_ros2_removeConstr(obj, idx_global);
    } else {
      obj->mEqRemoved++;
      TYPE_tmp = obj->Wid[idx_global - 1] - 1;
      obj->isActiveConstr[(obj->isActiveIdx[TYPE_tmp] + obj->
                           Wlocalidx[idx_global - 1]) - 2] = false;
      obj->Wid[idx_global - 1] = obj->Wid[totalEq];
      obj->Wlocalidx[idx_global - 1] = obj->Wlocalidx[totalEq];
      b_tmp = static_cast<uint8_T>(obj->nVar);
      for (idx = 0; idx < b_tmp; idx++) {
        obj->ATwset[idx + 13 * (idx_global - 1)] = obj->ATwset[13 * totalEq +
          idx];
      }

      obj->bwset[idx_global - 1] = obj->bwset[totalEq];
      obj->Wid[totalEq] = obj->Wid[obj->nActiveConstr - 1];
      obj->Wlocalidx[totalEq] = obj->Wlocalidx[obj->nActiveConstr - 1];
      for (idx = 0; idx < b_tmp; idx++) {
        obj->ATwset[idx + 13 * totalEq] = obj->ATwset[(obj->nActiveConstr - 1) *
          13 + idx];
      }

      obj->bwset[totalEq] = obj->bwset[obj->nActiveConstr - 1];
      obj->nActiveConstr--;
      obj->nWConstr[TYPE_tmp]--;
    }
  }
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formati_RemoveDependentIneq_
  (sIqAUiO7iN3zlnKzlJ0LdOE_c6_fo_T *workingset, s2v85VDFdoXWosLJGoY94IG_c6_fo_T *
   qrmanager, sivq9bjImOLkQfehLigQhXG_c6_fo_T *memspace, real_T tolfactor)
{
  c6_formation_ros2_B.nActiveConstr_tmp = workingset->nActiveConstr;
  c6_formation_ros2_B.nFixedConstr = workingset->nWConstr[0] +
    workingset->nWConstr[1];
  c6_formation_ros2_B.nVar = workingset->nVar;
  if ((workingset->nWConstr[2] + workingset->nWConstr[3]) + workingset->
      nWConstr[4] > 0) {
    c6_formation_ros2_B.tol_f = tolfactor * static_cast<real_T>(workingset->nVar)
      * 2.2204460492503131E-16;
    for (c6_formation_ros2_B.nDepIneq = 0; c6_formation_ros2_B.nDepIneq <
         c6_formation_ros2_B.nFixedConstr; c6_formation_ros2_B.nDepIneq++) {
      qrmanager->jpvt[c6_formation_ros2_B.nDepIneq] = 1;
    }

    if (c6_formation_ros2_B.nFixedConstr + 1 <=
        c6_formation_ros2_B.nActiveConstr_tmp) {
      memset(&qrmanager->jpvt[c6_formation_ros2_B.nFixedConstr], 0, static_cast<
             uint32_T>(c6_formation_ros2_B.nActiveConstr_tmp -
                       c6_formation_ros2_B.nFixedConstr) * sizeof(int32_T));
    }

    for (c6_formation_ros2_B.nDepIneq = 0; c6_formation_ros2_B.nDepIneq <
         c6_formation_ros2_B.nActiveConstr_tmp; c6_formation_ros2_B.nDepIneq++)
    {
      c6_formation_ros2_B.iy0_tmp = 13 * c6_formation_ros2_B.nDepIneq;
      c6_formation_ros2_B.c_n = static_cast<uint8_T>(c6_formation_ros2_B.nVar);
      memcpy(&qrmanager->QR[c6_formation_ros2_B.iy0_tmp], &workingset->
             ATwset[c6_formation_ros2_B.iy0_tmp], static_cast<uint32_T>
             ((c6_formation_ros2_B.c_n + c6_formation_ros2_B.iy0_tmp) -
              c6_formation_ros2_B.iy0_tmp) * sizeof(real_T));
    }

    c6_formation_ros2_factorQRE(qrmanager, workingset->nVar,
      workingset->nActiveConstr);
    c6_formation_ros2_B.nDepIneq = 0;
    c6_formation_ros2_B.nActiveConstr_tmp = workingset->nActiveConstr - 1;
    while (c6_formation_ros2_B.nActiveConstr_tmp + 1 > c6_formation_ros2_B.nVar)
    {
      c6_formation_ros2_B.nDepIneq++;
      memspace->workspace_int[c6_formation_ros2_B.nDepIneq - 1] =
        qrmanager->jpvt[c6_formation_ros2_B.nActiveConstr_tmp];
      c6_formation_ros2_B.nActiveConstr_tmp--;
    }

    if (c6_formation_ros2_B.nActiveConstr_tmp + 1 <= workingset->nVar) {
      c6_formation_ros2_B.nVar = 13 * c6_formation_ros2_B.nActiveConstr_tmp +
        c6_formation_ros2_B.nActiveConstr_tmp;
      while ((c6_formation_ros2_B.nActiveConstr_tmp + 1 >
              c6_formation_ros2_B.nFixedConstr) && (fabs(qrmanager->
               QR[c6_formation_ros2_B.nVar]) < c6_formation_ros2_B.tol_f)) {
        c6_formation_ros2_B.nDepIneq++;
        memspace->workspace_int[c6_formation_ros2_B.nDepIneq - 1] =
          qrmanager->jpvt[c6_formation_ros2_B.nActiveConstr_tmp];
        c6_formation_ros2_B.nActiveConstr_tmp--;
        c6_formation_ros2_B.nVar -= 14;
      }
    }

    c6_formation_ros2_countsort(memspace->workspace_int,
      c6_formation_ros2_B.nDepIneq, memspace->workspace_sort,
      c6_formation_ros2_B.nFixedConstr + 1, workingset->nActiveConstr);
    for (c6_formation_ros2_B.nFixedConstr = c6_formation_ros2_B.nDepIneq;
         c6_formation_ros2_B.nFixedConstr >= 1; c6_formation_ros2_B.nFixedConstr
         --) {
      c6_formation_ros2_removeConstr(workingset, memspace->
        workspace_int[c6_formation_ros2_B.nFixedConstr - 1]);
    }
  }
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formation_ros2_factorQR
  (s2v85VDFdoXWosLJGoY94IG_c6_fo_T *obj, const real_T A[832], int32_T mrows,
   int32_T ncols)
{
  static const int32_T offsets[4] = { 0, 1, 2, 3 };

  boolean_T guard1;
  c6_formation_ros2_B.k_me = mrows * ncols;
  guard1 = false;
  if (c6_formation_ros2_B.k_me > 0) {
    for (c6_formation_ros2_B.i_mc = 0; c6_formation_ros2_B.i_mc < ncols;
         c6_formation_ros2_B.i_mc++) {
      c6_formation_ros2_B.ix0_tmp = 13 * c6_formation_ros2_B.i_mc;
      c6_formation_ros2_B.k_me = static_cast<uint8_T>(mrows);
      memcpy(&obj->QR[c6_formation_ros2_B.ix0_tmp],
             &A[c6_formation_ros2_B.ix0_tmp], static_cast<uint32_T>
             ((c6_formation_ros2_B.k_me + c6_formation_ros2_B.ix0_tmp) -
              c6_formation_ros2_B.ix0_tmp) * sizeof(real_T));
    }

    guard1 = true;
  } else if (c6_formation_ros2_B.k_me == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    guard1 = true;
  }

  if (guard1) {
    obj->usedPivoting = false;
    obj->mrows = mrows;
    obj->ncols = ncols;
    c6_formation_ros2_B.k_me = (ncols / 4) << 2;
    c6_formation_ros2_B.ix0_tmp = c6_formation_ros2_B.k_me - 4;
    for (c6_formation_ros2_B.i_mc = 0; c6_formation_ros2_B.i_mc <=
         c6_formation_ros2_B.ix0_tmp; c6_formation_ros2_B.i_mc += 4) {
      _mm_storeu_si128((__m128i *)&obj->jpvt[c6_formation_ros2_B.i_mc],
                       _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32
        (c6_formation_ros2_B.i_mc), _mm_loadu_si128((const __m128i *)&offsets[0])),
        _mm_set1_epi32(1)));
    }

    for (c6_formation_ros2_B.i_mc = c6_formation_ros2_B.k_me;
         c6_formation_ros2_B.i_mc < ncols; c6_formation_ros2_B.i_mc++) {
      obj->jpvt[c6_formation_ros2_B.i_mc] = c6_formation_ros2_B.i_mc + 1;
    }

    if (mrows <= ncols) {
      c6_formation_ros2_B.k_me = mrows;
    } else {
      c6_formation_ros2_B.k_me = ncols;
    }

    obj->minRowCol = c6_formation_ros2_B.k_me;
    memset(&obj->tau[0], 0, 13U * sizeof(real_T));
    if (c6_formation_ros2_B.k_me >= 1) {
      memset(&obj->tau[0], 0, 13U * sizeof(real_T));
      c6_formation_ros2_qrf(obj->QR, mrows, ncols, c6_formation_ros2_B.k_me,
                            obj->tau);
    }
  }
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
real_T c6_formation_ros2::c6_forma_maxConstraintViolation
  (sIqAUiO7iN3zlnKzlJ0LdOE_c6_fo_T *obj, const real_T x[832])
{
  real_T v;
  if (obj->probType == 2) {
    v = 0.0;
    for (c6_formation_ros2_B.k_e = 0; c6_formation_ros2_B.k_e < 39;
         c6_formation_ros2_B.k_e++) {
      obj->maxConstrWorkspace[c6_formation_ros2_B.k_e] = obj->
        bineq[c6_formation_ros2_B.k_e];
      obj->maxConstrWorkspace[c6_formation_ros2_B.k_e] =
        -obj->maxConstrWorkspace[c6_formation_ros2_B.k_e];
    }

    for (c6_formation_ros2_B.k_e = 0; c6_formation_ros2_B.k_e <= 494;
         c6_formation_ros2_B.k_e += 13) {
      c6_formation_ros2_B.b_c_a = 0.0;
      for (c6_formation_ros2_B.ia_h = c6_formation_ros2_B.k_e + 1;
           c6_formation_ros2_B.ia_h <= c6_formation_ros2_B.k_e + 12;
           c6_formation_ros2_B.ia_h++) {
        c6_formation_ros2_B.b_c_a += x[(c6_formation_ros2_B.ia_h -
          c6_formation_ros2_B.k_e) + 63] * obj->Aineq[c6_formation_ros2_B.ia_h -
          1];
      }

      c6_formation_ros2_B.ia_h = div_nde_s32_floor(c6_formation_ros2_B.k_e, 13);
      obj->maxConstrWorkspace[c6_formation_ros2_B.ia_h] +=
        c6_formation_ros2_B.b_c_a;
    }

    for (c6_formation_ros2_B.k_e = 0; c6_formation_ros2_B.k_e < 39;
         c6_formation_ros2_B.k_e++) {
      c6_formation_ros2_B.b_c_a = obj->
        maxConstrWorkspace[c6_formation_ros2_B.k_e] - x[c6_formation_ros2_B.k_e
        + 76];
      obj->maxConstrWorkspace[c6_formation_ros2_B.k_e] =
        c6_formation_ros2_B.b_c_a;
      if ((!(v >= c6_formation_ros2_B.b_c_a)) && (!rtIsNaN
           (c6_formation_ros2_B.b_c_a))) {
        v = c6_formation_ros2_B.b_c_a;
      }
    }
  } else {
    v = 0.0;
    for (c6_formation_ros2_B.k_e = 0; c6_formation_ros2_B.k_e < 39;
         c6_formation_ros2_B.k_e++) {
      obj->maxConstrWorkspace[c6_formation_ros2_B.k_e] = obj->
        bineq[c6_formation_ros2_B.k_e];
      obj->maxConstrWorkspace[c6_formation_ros2_B.k_e] =
        -obj->maxConstrWorkspace[c6_formation_ros2_B.k_e];
    }

    for (c6_formation_ros2_B.k_e = 0; c6_formation_ros2_B.k_e <= 494;
         c6_formation_ros2_B.k_e += 13) {
      c6_formation_ros2_B.b_c_a = 0.0;
      c6_formation_ros2_B.e_f = c6_formation_ros2_B.k_e + obj->nVar;
      for (c6_formation_ros2_B.ia_h = c6_formation_ros2_B.k_e + 1;
           c6_formation_ros2_B.ia_h <= c6_formation_ros2_B.e_f;
           c6_formation_ros2_B.ia_h++) {
        c6_formation_ros2_B.b_c_a += x[(c6_formation_ros2_B.ia_h -
          c6_formation_ros2_B.k_e) + 63] * obj->Aineq[c6_formation_ros2_B.ia_h -
          1];
      }

      c6_formation_ros2_B.ia_h = div_nde_s32_floor(c6_formation_ros2_B.k_e, 13);
      obj->maxConstrWorkspace[c6_formation_ros2_B.ia_h] +=
        c6_formation_ros2_B.b_c_a;
    }

    for (c6_formation_ros2_B.k_e = 0; c6_formation_ros2_B.k_e < 39;
         c6_formation_ros2_B.k_e++) {
      c6_formation_ros2_B.b_c_a = obj->
        maxConstrWorkspace[c6_formation_ros2_B.k_e];
      if ((!(v >= c6_formation_ros2_B.b_c_a)) && (!rtIsNaN
           (c6_formation_ros2_B.b_c_a))) {
        v = c6_formation_ros2_B.b_c_a;
      }
    }
  }

  if (obj->sizes[3] > 0) {
    c6_formation_ros2_B.ia_h = static_cast<uint8_T>(obj->sizes[3]);
    for (c6_formation_ros2_B.k_e = 0; c6_formation_ros2_B.k_e <
         c6_formation_ros2_B.ia_h; c6_formation_ros2_B.k_e++) {
      c6_formation_ros2_B.b_c_a = -x[obj->indexLB[c6_formation_ros2_B.k_e] + 63]
        - obj->lb[obj->indexLB[c6_formation_ros2_B.k_e] - 1];
      if ((!(v >= c6_formation_ros2_B.b_c_a)) && (!rtIsNaN
           (c6_formation_ros2_B.b_c_a))) {
        v = c6_formation_ros2_B.b_c_a;
      }
    }
  }

  if (obj->sizes[4] > 0) {
    c6_formation_ros2_B.ia_h = static_cast<uint8_T>(obj->sizes[4]);
    for (c6_formation_ros2_B.k_e = 0; c6_formation_ros2_B.k_e <
         c6_formation_ros2_B.ia_h; c6_formation_ros2_B.k_e++) {
      c6_formation_ros2_B.b_c_a = x[obj->indexUB[c6_formation_ros2_B.k_e] + 63]
        - obj->ub[obj->indexUB[c6_formation_ros2_B.k_e] - 1];
      if ((!(v >= c6_formation_ros2_B.b_c_a)) && (!rtIsNaN
           (c6_formation_ros2_B.b_c_a))) {
        v = c6_formation_ros2_B.b_c_a;
      }
    }
  }

  if (obj->sizes[0] > 0) {
    c6_formation_ros2_B.ia_h = static_cast<uint8_T>(obj->sizes[0]);
    for (c6_formation_ros2_B.k_e = 0; c6_formation_ros2_B.k_e <
         c6_formation_ros2_B.ia_h; c6_formation_ros2_B.k_e++) {
      c6_formation_ros2_B.b_c_a = fabs(x[obj->indexFixed[c6_formation_ros2_B.k_e]
        + 63] - obj->ub[obj->indexFixed[c6_formation_ros2_B.k_e] - 1]);
      if ((!(v >= c6_formation_ros2_B.b_c_a)) && (!rtIsNaN
           (c6_formation_ros2_B.b_c_a))) {
        v = c6_formation_ros2_B.b_c_a;
      }
    }
  }

  return v;
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
boolean_T c6_formation_ros2::c6_form_feasibleX0ForWorkingSet(real_T workspace
  [832], real_T xCurrent[13], sIqAUiO7iN3zlnKzlJ0LdOE_c6_fo_T *workingset,
  s2v85VDFdoXWosLJGoY94IG_c6_fo_T *qrmanager)
{
  __m128d tmp;
  __m128d tmp_0;
  boolean_T nonDegenerateWset;
  static const int32_T offsets[4] = { 0, 1, 2, 3 };

  int32_T exitg1;
  c6_formation_ros2_B.mWConstr_tmp_tmp = workingset->nActiveConstr - 1;
  c6_formation_ros2_B.nVar_tmp_tmp = workingset->nVar;
  nonDegenerateWset = true;
  if (workingset->nActiveConstr != 0) {
    for (c6_formation_ros2_B.idx = 0; c6_formation_ros2_B.idx <=
         c6_formation_ros2_B.mWConstr_tmp_tmp; c6_formation_ros2_B.idx++) {
      workspace[c6_formation_ros2_B.idx] = workingset->
        bwset[c6_formation_ros2_B.idx];
      workspace[c6_formation_ros2_B.idx + 64] = workingset->
        bwset[c6_formation_ros2_B.idx];
    }

    if (workingset->nActiveConstr != 0) {
      c6_formation_ros2_B.d_c = (workingset->nActiveConstr - 1) * 13 + 1;
      for (c6_formation_ros2_B.iac = 1; c6_formation_ros2_B.iac <=
           c6_formation_ros2_B.d_c; c6_formation_ros2_B.iac += 13) {
        c6_formation_ros2_B.c = 0.0;
        c6_formation_ros2_B.jBcol = (c6_formation_ros2_B.iac +
          c6_formation_ros2_B.nVar_tmp_tmp) - 1;
        for (c6_formation_ros2_B.idx = c6_formation_ros2_B.iac;
             c6_formation_ros2_B.idx <= c6_formation_ros2_B.jBcol;
             c6_formation_ros2_B.idx++) {
          c6_formation_ros2_B.c += workingset->ATwset[c6_formation_ros2_B.idx -
            1] * xCurrent[c6_formation_ros2_B.idx - c6_formation_ros2_B.iac];
        }

        c6_formation_ros2_B.idx = div_nde_s32_floor(c6_formation_ros2_B.iac - 1,
          13);
        workspace[c6_formation_ros2_B.idx] -= c6_formation_ros2_B.c;
      }
    }

    if (workingset->nActiveConstr >= workingset->nVar) {
      c6_formation_ros2_B.d_c = static_cast<uint8_T>(workingset->nVar);
      for (c6_formation_ros2_B.idx = 0; c6_formation_ros2_B.idx <
           c6_formation_ros2_B.d_c; c6_formation_ros2_B.idx++) {
        c6_formation_ros2_B.jBcol = 13 * c6_formation_ros2_B.idx;
        for (c6_formation_ros2_B.iac = 0; c6_formation_ros2_B.iac <=
             c6_formation_ros2_B.mWConstr_tmp_tmp; c6_formation_ros2_B.iac++) {
          qrmanager->QR[c6_formation_ros2_B.iac + c6_formation_ros2_B.jBcol] =
            workingset->ATwset[13 * c6_formation_ros2_B.iac +
            c6_formation_ros2_B.idx];
        }
      }

      qrmanager->usedPivoting = false;
      qrmanager->mrows = workingset->nActiveConstr;
      qrmanager->ncols = workingset->nVar;
      c6_formation_ros2_B.jBcol = (static_cast<uint8_T>(workingset->nVar) / 4) <<
        2;
      c6_formation_ros2_B.iAcol = c6_formation_ros2_B.jBcol - 4;
      for (c6_formation_ros2_B.idx = 0; c6_formation_ros2_B.idx <=
           c6_formation_ros2_B.iAcol; c6_formation_ros2_B.idx += 4) {
        _mm_storeu_si128((__m128i *)&qrmanager->jpvt[c6_formation_ros2_B.idx],
                         _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32
          (c6_formation_ros2_B.idx), _mm_loadu_si128((const __m128i *)&offsets[0])),
          _mm_set1_epi32(1)));
      }

      for (c6_formation_ros2_B.idx = c6_formation_ros2_B.jBcol;
           c6_formation_ros2_B.idx < c6_formation_ros2_B.d_c;
           c6_formation_ros2_B.idx++) {
        qrmanager->jpvt[c6_formation_ros2_B.idx] = c6_formation_ros2_B.idx + 1;
      }

      if (workingset->nActiveConstr <= workingset->nVar) {
        c6_formation_ros2_B.idx = workingset->nActiveConstr;
      } else {
        c6_formation_ros2_B.idx = workingset->nVar;
      }

      qrmanager->minRowCol = c6_formation_ros2_B.idx;
      memcpy(&c6_formation_ros2_B.B[0], &qrmanager->QR[0], 832U * sizeof(real_T));
      memset(&qrmanager->tau[0], 0, 13U * sizeof(real_T));
      if (c6_formation_ros2_B.idx >= 1) {
        memset(&qrmanager->tau[0], 0, 13U * sizeof(real_T));
        c6_formation_ros2_qrf(c6_formation_ros2_B.B, workingset->nActiveConstr,
                              workingset->nVar, c6_formation_ros2_B.idx,
                              qrmanager->tau);
      }

      memcpy(&qrmanager->QR[0], &c6_formation_ros2_B.B[0], 832U * sizeof(real_T));
      c6_formation_ros2_computeQ_(qrmanager, qrmanager->mrows);
      memcpy(&c6_formation_ros2_B.B[0], &workspace[0], 832U * sizeof(real_T));
      for (c6_formation_ros2_B.idx = 0; c6_formation_ros2_B.idx <= 64;
           c6_formation_ros2_B.idx += 64) {
        c6_formation_ros2_B.d_c = c6_formation_ros2_B.idx +
          c6_formation_ros2_B.nVar_tmp_tmp;
        for (c6_formation_ros2_B.iac = c6_formation_ros2_B.idx + 1;
             c6_formation_ros2_B.iac <= c6_formation_ros2_B.d_c;
             c6_formation_ros2_B.iac++) {
          workspace[c6_formation_ros2_B.iac - 1] = 0.0;
        }
      }

      c6_formation_ros2_B.jBcol = -1;
      for (c6_formation_ros2_B.idx = 0; c6_formation_ros2_B.idx <= 64;
           c6_formation_ros2_B.idx += 64) {
        c6_formation_ros2_B.iAcol = -1;
        c6_formation_ros2_B.br = c6_formation_ros2_B.idx +
          c6_formation_ros2_B.nVar_tmp_tmp;
        for (c6_formation_ros2_B.iac = c6_formation_ros2_B.idx + 1;
             c6_formation_ros2_B.iac <= c6_formation_ros2_B.br;
             c6_formation_ros2_B.iac++) {
          c6_formation_ros2_B.c = 0.0;
          for (c6_formation_ros2_B.d_c = 0; c6_formation_ros2_B.d_c <=
               c6_formation_ros2_B.mWConstr_tmp_tmp; c6_formation_ros2_B.d_c++)
          {
            c6_formation_ros2_B.c += qrmanager->Q[(c6_formation_ros2_B.d_c +
              c6_formation_ros2_B.iAcol) + 1] * c6_formation_ros2_B.B
              [(c6_formation_ros2_B.d_c + c6_formation_ros2_B.jBcol) + 1];
          }

          workspace[c6_formation_ros2_B.iac - 1] += c6_formation_ros2_B.c;
          c6_formation_ros2_B.iAcol += 13;
        }

        c6_formation_ros2_B.jBcol += 64;
      }

      for (c6_formation_ros2_B.mWConstr_tmp_tmp = 0;
           c6_formation_ros2_B.mWConstr_tmp_tmp < 2;
           c6_formation_ros2_B.mWConstr_tmp_tmp++) {
        c6_formation_ros2_B.iAcol = (c6_formation_ros2_B.mWConstr_tmp_tmp << 6)
          - 1;
        for (c6_formation_ros2_B.d_c = c6_formation_ros2_B.nVar_tmp_tmp;
             c6_formation_ros2_B.d_c >= 1; c6_formation_ros2_B.d_c--) {
          c6_formation_ros2_B.br = (c6_formation_ros2_B.d_c - 1) * 13;
          c6_formation_ros2_B.idx = c6_formation_ros2_B.d_c +
            c6_formation_ros2_B.iAcol;
          c6_formation_ros2_B.c = workspace[c6_formation_ros2_B.idx];
          if (c6_formation_ros2_B.c != 0.0) {
            workspace[c6_formation_ros2_B.idx] = c6_formation_ros2_B.c /
              qrmanager->QR[(c6_formation_ros2_B.d_c + c6_formation_ros2_B.br) -
              1];
            c6_formation_ros2_B.ar = static_cast<uint8_T>
              (c6_formation_ros2_B.d_c - 1);
            for (c6_formation_ros2_B.jBcol = 0; c6_formation_ros2_B.jBcol <
                 c6_formation_ros2_B.ar; c6_formation_ros2_B.jBcol++) {
              c6_formation_ros2_B.iac = (c6_formation_ros2_B.jBcol +
                c6_formation_ros2_B.iAcol) + 1;
              workspace[c6_formation_ros2_B.iac] -= qrmanager->
                QR[c6_formation_ros2_B.jBcol + c6_formation_ros2_B.br] *
                workspace[c6_formation_ros2_B.idx];
            }
          }
        }
      }
    } else {
      c6_formation_ros2_factorQR(qrmanager, workingset->ATwset, workingset->nVar,
        workingset->nActiveConstr);
      c6_formation_ros2_computeQ_(qrmanager, qrmanager->minRowCol);
      for (c6_formation_ros2_B.idx = 0; c6_formation_ros2_B.idx < 2;
           c6_formation_ros2_B.idx++) {
        c6_formation_ros2_B.jBcol = c6_formation_ros2_B.idx << 6;
        for (c6_formation_ros2_B.iac = 0; c6_formation_ros2_B.iac <=
             c6_formation_ros2_B.mWConstr_tmp_tmp; c6_formation_ros2_B.iac++) {
          c6_formation_ros2_B.iAcol = 13 * c6_formation_ros2_B.iac;
          c6_formation_ros2_B.br = c6_formation_ros2_B.iac +
            c6_formation_ros2_B.jBcol;
          c6_formation_ros2_B.c = workspace[c6_formation_ros2_B.br];
          c6_formation_ros2_B.ar = static_cast<uint8_T>(c6_formation_ros2_B.iac);
          for (c6_formation_ros2_B.d_c = 0; c6_formation_ros2_B.d_c <
               c6_formation_ros2_B.ar; c6_formation_ros2_B.d_c++) {
            c6_formation_ros2_B.c -= qrmanager->QR[c6_formation_ros2_B.d_c +
              c6_formation_ros2_B.iAcol] * workspace[c6_formation_ros2_B.d_c +
              c6_formation_ros2_B.jBcol];
          }

          workspace[c6_formation_ros2_B.br] = c6_formation_ros2_B.c /
            qrmanager->QR[c6_formation_ros2_B.iac + c6_formation_ros2_B.iAcol];
        }
      }

      memcpy(&c6_formation_ros2_B.B[0], &workspace[0], 832U * sizeof(real_T));
      for (c6_formation_ros2_B.idx = 0; c6_formation_ros2_B.idx <= 64;
           c6_formation_ros2_B.idx += 64) {
        c6_formation_ros2_B.d_c = c6_formation_ros2_B.idx +
          c6_formation_ros2_B.nVar_tmp_tmp;
        for (c6_formation_ros2_B.iac = c6_formation_ros2_B.idx + 1;
             c6_formation_ros2_B.iac <= c6_formation_ros2_B.d_c;
             c6_formation_ros2_B.iac++) {
          workspace[c6_formation_ros2_B.iac - 1] = 0.0;
        }
      }

      c6_formation_ros2_B.br = 1;
      for (c6_formation_ros2_B.idx = 0; c6_formation_ros2_B.idx <= 64;
           c6_formation_ros2_B.idx += 64) {
        c6_formation_ros2_B.ar = -1;
        c6_formation_ros2_B.h = c6_formation_ros2_B.br +
          c6_formation_ros2_B.mWConstr_tmp_tmp;
        for (c6_formation_ros2_B.iac = c6_formation_ros2_B.br;
             c6_formation_ros2_B.iac <= c6_formation_ros2_B.h;
             c6_formation_ros2_B.iac++) {
          c6_formation_ros2_B.l_c = c6_formation_ros2_B.idx +
            c6_formation_ros2_B.nVar_tmp_tmp;
          c6_formation_ros2_B.jBcol = ((((c6_formation_ros2_B.l_c -
            c6_formation_ros2_B.idx) / 2) << 1) + c6_formation_ros2_B.idx) + 1;
          c6_formation_ros2_B.iAcol = c6_formation_ros2_B.jBcol - 2;
          for (c6_formation_ros2_B.d_c = c6_formation_ros2_B.idx + 1;
               c6_formation_ros2_B.d_c <= c6_formation_ros2_B.iAcol;
               c6_formation_ros2_B.d_c += 2) {
            tmp = _mm_loadu_pd(&qrmanager->Q[(c6_formation_ros2_B.ar +
              c6_formation_ros2_B.d_c) - c6_formation_ros2_B.idx]);
            tmp_0 = _mm_loadu_pd(&workspace[c6_formation_ros2_B.d_c - 1]);
            _mm_storeu_pd(&workspace[c6_formation_ros2_B.d_c - 1], _mm_add_pd
                          (_mm_mul_pd(tmp, _mm_set1_pd
              (c6_formation_ros2_B.B[c6_formation_ros2_B.iac - 1])), tmp_0));
          }

          for (c6_formation_ros2_B.d_c = c6_formation_ros2_B.jBcol;
               c6_formation_ros2_B.d_c <= c6_formation_ros2_B.l_c;
               c6_formation_ros2_B.d_c++) {
            workspace[c6_formation_ros2_B.d_c - 1] += qrmanager->Q
              [(c6_formation_ros2_B.ar + c6_formation_ros2_B.d_c) -
              c6_formation_ros2_B.idx] *
              c6_formation_ros2_B.B[c6_formation_ros2_B.iac - 1];
          }

          c6_formation_ros2_B.ar += 13;
        }

        c6_formation_ros2_B.br += 64;
      }
    }

    c6_formation_ros2_B.mWConstr_tmp_tmp = 0;
    do {
      exitg1 = 0;
      if (c6_formation_ros2_B.mWConstr_tmp_tmp <= static_cast<uint8_T>
          (c6_formation_ros2_B.nVar_tmp_tmp) - 1) {
        if (rtIsInf(workspace[c6_formation_ros2_B.mWConstr_tmp_tmp]) || rtIsNaN
            (workspace[c6_formation_ros2_B.mWConstr_tmp_tmp])) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          c6_formation_ros2_B.c = workspace[c6_formation_ros2_B.mWConstr_tmp_tmp
            + 64];
          if (rtIsInf(c6_formation_ros2_B.c) || rtIsNaN(c6_formation_ros2_B.c))
          {
            nonDegenerateWset = false;
            exitg1 = 1;
          } else {
            c6_formation_ros2_B.mWConstr_tmp_tmp++;
          }
        }
      } else {
        c6_formation_ros2_B.jBcol = (c6_formation_ros2_B.nVar_tmp_tmp / 2) << 1;
        c6_formation_ros2_B.iAcol = c6_formation_ros2_B.jBcol - 2;
        for (c6_formation_ros2_B.mWConstr_tmp_tmp = 0;
             c6_formation_ros2_B.mWConstr_tmp_tmp <= c6_formation_ros2_B.iAcol;
             c6_formation_ros2_B.mWConstr_tmp_tmp += 2) {
          tmp = _mm_loadu_pd(&workspace[c6_formation_ros2_B.mWConstr_tmp_tmp]);
          tmp_0 = _mm_loadu_pd(&xCurrent[c6_formation_ros2_B.mWConstr_tmp_tmp]);
          _mm_storeu_pd(&workspace[c6_formation_ros2_B.mWConstr_tmp_tmp],
                        _mm_add_pd(tmp, tmp_0));
        }

        for (c6_formation_ros2_B.mWConstr_tmp_tmp = c6_formation_ros2_B.jBcol;
             c6_formation_ros2_B.mWConstr_tmp_tmp <
             c6_formation_ros2_B.nVar_tmp_tmp;
             c6_formation_ros2_B.mWConstr_tmp_tmp++) {
          workspace[c6_formation_ros2_B.mWConstr_tmp_tmp] +=
            xCurrent[c6_formation_ros2_B.mWConstr_tmp_tmp];
        }

        if (workingset->probType == 2) {
          c6_formation_ros2_B.c = 0.0;
          for (c6_formation_ros2_B.mWConstr_tmp_tmp = 0;
               c6_formation_ros2_B.mWConstr_tmp_tmp < 39;
               c6_formation_ros2_B.mWConstr_tmp_tmp++) {
            workingset->maxConstrWorkspace[c6_formation_ros2_B.mWConstr_tmp_tmp]
              = workingset->bineq[c6_formation_ros2_B.mWConstr_tmp_tmp];
            workingset->maxConstrWorkspace[c6_formation_ros2_B.mWConstr_tmp_tmp]
              = -workingset->
              maxConstrWorkspace[c6_formation_ros2_B.mWConstr_tmp_tmp];
          }

          for (c6_formation_ros2_B.mWConstr_tmp_tmp = 0;
               c6_formation_ros2_B.mWConstr_tmp_tmp <= 494;
               c6_formation_ros2_B.mWConstr_tmp_tmp += 13) {
            c6_formation_ros2_B.c_c = 0.0;
            for (c6_formation_ros2_B.idx = c6_formation_ros2_B.mWConstr_tmp_tmp
                 + 1; c6_formation_ros2_B.idx <=
                 c6_formation_ros2_B.mWConstr_tmp_tmp + 12;
                 c6_formation_ros2_B.idx++) {
              c6_formation_ros2_B.c_c += workspace[(c6_formation_ros2_B.idx -
                c6_formation_ros2_B.mWConstr_tmp_tmp) - 1] * workingset->
                Aineq[c6_formation_ros2_B.idx - 1];
            }

            c6_formation_ros2_B.idx = div_nde_s32_floor
              (c6_formation_ros2_B.mWConstr_tmp_tmp, 13);
            workingset->maxConstrWorkspace[c6_formation_ros2_B.idx] +=
              c6_formation_ros2_B.c_c;
          }

          for (c6_formation_ros2_B.mWConstr_tmp_tmp = 0;
               c6_formation_ros2_B.mWConstr_tmp_tmp < 39;
               c6_formation_ros2_B.mWConstr_tmp_tmp++) {
            c6_formation_ros2_B.c_c = workingset->
              maxConstrWorkspace[c6_formation_ros2_B.mWConstr_tmp_tmp] -
              workspace[c6_formation_ros2_B.mWConstr_tmp_tmp + 12];
            workingset->maxConstrWorkspace[c6_formation_ros2_B.mWConstr_tmp_tmp]
              = c6_formation_ros2_B.c_c;
            if ((!(c6_formation_ros2_B.c >= c6_formation_ros2_B.c_c)) &&
                (!rtIsNaN(c6_formation_ros2_B.c_c))) {
              c6_formation_ros2_B.c = c6_formation_ros2_B.c_c;
            }
          }
        } else {
          c6_formation_ros2_B.c = 0.0;
          for (c6_formation_ros2_B.mWConstr_tmp_tmp = 0;
               c6_formation_ros2_B.mWConstr_tmp_tmp < 39;
               c6_formation_ros2_B.mWConstr_tmp_tmp++) {
            workingset->maxConstrWorkspace[c6_formation_ros2_B.mWConstr_tmp_tmp]
              = workingset->bineq[c6_formation_ros2_B.mWConstr_tmp_tmp];
            workingset->maxConstrWorkspace[c6_formation_ros2_B.mWConstr_tmp_tmp]
              = -workingset->
              maxConstrWorkspace[c6_formation_ros2_B.mWConstr_tmp_tmp];
          }

          for (c6_formation_ros2_B.mWConstr_tmp_tmp = 0;
               c6_formation_ros2_B.mWConstr_tmp_tmp <= 494;
               c6_formation_ros2_B.mWConstr_tmp_tmp += 13) {
            c6_formation_ros2_B.c_c = 0.0;
            c6_formation_ros2_B.iac = c6_formation_ros2_B.mWConstr_tmp_tmp +
              workingset->nVar;
            for (c6_formation_ros2_B.idx = c6_formation_ros2_B.mWConstr_tmp_tmp
                 + 1; c6_formation_ros2_B.idx <= c6_formation_ros2_B.iac;
                 c6_formation_ros2_B.idx++) {
              c6_formation_ros2_B.c_c += workspace[(c6_formation_ros2_B.idx -
                c6_formation_ros2_B.mWConstr_tmp_tmp) - 1] * workingset->
                Aineq[c6_formation_ros2_B.idx - 1];
            }

            c6_formation_ros2_B.idx = div_nde_s32_floor
              (c6_formation_ros2_B.mWConstr_tmp_tmp, 13);
            workingset->maxConstrWorkspace[c6_formation_ros2_B.idx] +=
              c6_formation_ros2_B.c_c;
          }

          for (c6_formation_ros2_B.mWConstr_tmp_tmp = 0;
               c6_formation_ros2_B.mWConstr_tmp_tmp < 39;
               c6_formation_ros2_B.mWConstr_tmp_tmp++) {
            c6_formation_ros2_B.c_c = workingset->
              maxConstrWorkspace[c6_formation_ros2_B.mWConstr_tmp_tmp];
            if ((!(c6_formation_ros2_B.c >= c6_formation_ros2_B.c_c)) &&
                (!rtIsNaN(c6_formation_ros2_B.c_c))) {
              c6_formation_ros2_B.c = c6_formation_ros2_B.c_c;
            }
          }
        }

        if (workingset->sizes[3] > 0) {
          c6_formation_ros2_B.idx = static_cast<uint8_T>(workingset->sizes[3]);
          for (c6_formation_ros2_B.mWConstr_tmp_tmp = 0;
               c6_formation_ros2_B.mWConstr_tmp_tmp < c6_formation_ros2_B.idx;
               c6_formation_ros2_B.mWConstr_tmp_tmp++) {
            c6_formation_ros2_B.c_c = -workspace[workingset->
              indexLB[c6_formation_ros2_B.mWConstr_tmp_tmp] - 1] -
              workingset->lb[workingset->
              indexLB[c6_formation_ros2_B.mWConstr_tmp_tmp] - 1];
            if ((!(c6_formation_ros2_B.c >= c6_formation_ros2_B.c_c)) &&
                (!rtIsNaN(c6_formation_ros2_B.c_c))) {
              c6_formation_ros2_B.c = c6_formation_ros2_B.c_c;
            }
          }
        }

        if (workingset->sizes[4] > 0) {
          c6_formation_ros2_B.idx = static_cast<uint8_T>(workingset->sizes[4]);
          for (c6_formation_ros2_B.mWConstr_tmp_tmp = 0;
               c6_formation_ros2_B.mWConstr_tmp_tmp < c6_formation_ros2_B.idx;
               c6_formation_ros2_B.mWConstr_tmp_tmp++) {
            c6_formation_ros2_B.c_c = workspace[workingset->
              indexUB[c6_formation_ros2_B.mWConstr_tmp_tmp] - 1] -
              workingset->ub[workingset->
              indexUB[c6_formation_ros2_B.mWConstr_tmp_tmp] - 1];
            if ((!(c6_formation_ros2_B.c >= c6_formation_ros2_B.c_c)) &&
                (!rtIsNaN(c6_formation_ros2_B.c_c))) {
              c6_formation_ros2_B.c = c6_formation_ros2_B.c_c;
            }
          }
        }

        if (workingset->sizes[0] > 0) {
          c6_formation_ros2_B.idx = static_cast<uint8_T>(workingset->sizes[0]);
          for (c6_formation_ros2_B.mWConstr_tmp_tmp = 0;
               c6_formation_ros2_B.mWConstr_tmp_tmp < c6_formation_ros2_B.idx;
               c6_formation_ros2_B.mWConstr_tmp_tmp++) {
            c6_formation_ros2_B.c_c = fabs(workspace[workingset->
              indexFixed[c6_formation_ros2_B.mWConstr_tmp_tmp] - 1] -
              workingset->ub[workingset->
              indexFixed[c6_formation_ros2_B.mWConstr_tmp_tmp] - 1]);
            if ((!(c6_formation_ros2_B.c >= c6_formation_ros2_B.c_c)) &&
                (!rtIsNaN(c6_formation_ros2_B.c_c))) {
              c6_formation_ros2_B.c = c6_formation_ros2_B.c_c;
            }
          }
        }

        c6_formation_ros2_B.c_c = c6_forma_maxConstraintViolation(workingset,
          workspace);
        if ((c6_formation_ros2_B.c <= 2.2204460492503131E-16) ||
            (c6_formation_ros2_B.c < c6_formation_ros2_B.c_c)) {
          c6_formation_ros2_B.mWConstr_tmp_tmp = static_cast<uint8_T>
            (c6_formation_ros2_B.nVar_tmp_tmp);
          memcpy(&xCurrent[0], &workspace[0], static_cast<uint32_T>
                 (c6_formation_ros2_B.mWConstr_tmp_tmp) * sizeof(real_T));
        } else {
          c6_formation_ros2_B.mWConstr_tmp_tmp = static_cast<uint8_T>
            (c6_formation_ros2_B.nVar_tmp_tmp);
          memcpy(&xCurrent[0], &workspace[64], static_cast<uint32_T>
                 (c6_formation_ros2_B.mWConstr_tmp_tmp) * sizeof(real_T));
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return nonDegenerateWset;
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
real_T c6_formation_ros2::c6_for_maxConstraintViolation_n
  (sIqAUiO7iN3zlnKzlJ0LdOE_c6_fo_T *obj, const real_T x[13])
{
  real_T b_c;
  real_T v;
  int32_T ia;
  if (obj->probType == 2) {
    v = 0.0;
    for (int32_T k = 0; k < 39; k++) {
      obj->maxConstrWorkspace[k] = obj->bineq[k];
      obj->maxConstrWorkspace[k] = -obj->maxConstrWorkspace[k];
    }

    for (int32_T k = 0; k <= 494; k += 13) {
      b_c = 0.0;
      for (ia = k + 1; ia <= k + 12; ia++) {
        b_c += x[(ia - k) - 1] * obj->Aineq[ia - 1];
      }

      ia = div_nde_s32_floor(k, 13);
      obj->maxConstrWorkspace[ia] += b_c;
    }

    for (int32_T k = 0; k < 39; k++) {
      b_c = obj->maxConstrWorkspace[k] - x[12];
      obj->maxConstrWorkspace[k] = b_c;
      if ((!(v >= b_c)) && (!rtIsNaN(b_c))) {
        v = b_c;
      }
    }
  } else {
    v = 0.0;
    for (int32_T k = 0; k < 39; k++) {
      obj->maxConstrWorkspace[k] = obj->bineq[k];
      obj->maxConstrWorkspace[k] = -obj->maxConstrWorkspace[k];
    }

    for (int32_T k = 0; k <= 494; k += 13) {
      int32_T e;
      b_c = 0.0;
      e = k + obj->nVar;
      for (ia = k + 1; ia <= e; ia++) {
        b_c += x[(ia - k) - 1] * obj->Aineq[ia - 1];
      }

      ia = div_nde_s32_floor(k, 13);
      obj->maxConstrWorkspace[ia] += b_c;
    }

    for (int32_T k = 0; k < 39; k++) {
      b_c = obj->maxConstrWorkspace[k];
      if ((!(v >= b_c)) && (!rtIsNaN(b_c))) {
        v = b_c;
      }
    }
  }

  if (obj->sizes[3] > 0) {
    ia = static_cast<uint8_T>(obj->sizes[3]);
    for (int32_T k = 0; k < ia; k++) {
      b_c = -x[obj->indexLB[k] - 1] - obj->lb[obj->indexLB[k] - 1];
      if ((!(v >= b_c)) && (!rtIsNaN(b_c))) {
        v = b_c;
      }
    }
  }

  if (obj->sizes[4] > 0) {
    ia = static_cast<uint8_T>(obj->sizes[4]);
    for (int32_T k = 0; k < ia; k++) {
      b_c = x[obj->indexUB[k] - 1] - obj->ub[obj->indexUB[k] - 1];
      if ((!(v >= b_c)) && (!rtIsNaN(b_c))) {
        v = b_c;
      }
    }
  }

  if (obj->sizes[0] > 0) {
    ia = static_cast<uint8_T>(obj->sizes[0]);
    for (int32_T k = 0; k < ia; k++) {
      b_c = fabs(x[obj->indexFixed[k] - 1] - obj->ub[obj->indexFixed[k] - 1]);
      if ((!(v >= b_c)) && (!rtIsNaN(b_c))) {
        v = b_c;
      }
    }
  }

  return v;
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formation_PresolveWorkingSet
  (sCXYlwCFvxAmgJ1M2ooVQBD_c6_fo_T *solution, sivq9bjImOLkQfehLigQhXG_c6_fo_T
   *memspace, sIqAUiO7iN3zlnKzlJ0LdOE_c6_fo_T *workingset,
   s2v85VDFdoXWosLJGoY94IG_c6_fo_T *qrmanager)
{
  boolean_T exitg1;
  boolean_T guard1;
  solution->state = 82;
  qrmanager->ldq = 13;
  memset(&qrmanager->QR[0], 0, 832U * sizeof(real_T));
  memset(&qrmanager->Q[0], 0, 169U * sizeof(real_T));
  memset(&qrmanager->jpvt[0], 0, sizeof(int32_T) << 6U);
  qrmanager->mrows = 0;
  qrmanager->ncols = 0;
  memset(&qrmanager->tau[0], 0, 13U * sizeof(real_T));
  qrmanager->minRowCol = 0;
  qrmanager->usedPivoting = false;
  c6_formation_ros2_B.i_h = workingset->nWConstr[0];
  c6_formation_ros2_B.idx_row = 0;
  if (workingset->nWConstr[0] > 0) {
    c6_formation_ros2_B.idxStartIneq_e = static_cast<uint8_T>
      (workingset->nWConstr[0]);
    c6_formation_ros2_B.idxEndIneq_tmp = static_cast<uint8_T>(workingset->nVar);
    for (c6_formation_ros2_B.idx_row = 0; c6_formation_ros2_B.idx_row <
         c6_formation_ros2_B.idxStartIneq_e; c6_formation_ros2_B.idx_row++) {
      for (c6_formation_ros2_B.totalRank_o = 0; c6_formation_ros2_B.totalRank_o <
           c6_formation_ros2_B.idxEndIneq_tmp; c6_formation_ros2_B.totalRank_o++)
      {
        qrmanager->QR[c6_formation_ros2_B.idx_row + 13 *
          c6_formation_ros2_B.totalRank_o] = workingset->ATwset[13 *
          c6_formation_ros2_B.idx_row + c6_formation_ros2_B.totalRank_o];
      }
    }

    c6_formation_ros2_B.idx_row = workingset->nWConstr[0] - workingset->nVar;
    if (c6_formation_ros2_B.idx_row <= 0) {
      c6_formation_ros2_B.idx_row = 0;
    }

    memset(&qrmanager->jpvt[0], 0, static_cast<uint32_T>
           (c6_formation_ros2_B.idxEndIneq_tmp) * sizeof(int32_T));
    c6_formation_ros2_factorQRE(qrmanager, workingset->nWConstr[0],
      workingset->nVar);
    c6_formation_ros2_B.tol_e = 100.0 * static_cast<real_T>(workingset->nVar) *
      2.2204460492503131E-16;
    if (workingset->nVar <= workingset->nWConstr[0]) {
      c6_formation_ros2_B.totalRank_o = workingset->nVar;
    } else {
      c6_formation_ros2_B.totalRank_o = workingset->nWConstr[0];
    }

    c6_formation_ros2_B.totalRank_o += (c6_formation_ros2_B.totalRank_o - 1) *
      13;
    while ((c6_formation_ros2_B.totalRank_o > 0) && (fabs(qrmanager->
             QR[c6_formation_ros2_B.totalRank_o - 1]) <
            c6_formation_ros2_B.tol_e)) {
      c6_formation_ros2_B.totalRank_o -= 14;
      c6_formation_ros2_B.idx_row++;
    }

    if (c6_formation_ros2_B.idx_row > 0) {
      c6_formation_ros2_computeQ_(qrmanager, qrmanager->mrows);
      c6_formation_ros2_B.f_h = 0;
      exitg1 = false;
      while ((!exitg1) && (c6_formation_ros2_B.f_h <=
                           c6_formation_ros2_B.idx_row - 1)) {
        c6_formation_ros2_B.ix_l = ((c6_formation_ros2_B.i_h -
          c6_formation_ros2_B.f_h) - 1) * 13;
        c6_formation_ros2_B.qtb_b = 0.0;
        for (c6_formation_ros2_B.totalRank_o = 0;
             c6_formation_ros2_B.totalRank_o < c6_formation_ros2_B.i_h;
             c6_formation_ros2_B.totalRank_o++) {
          c6_formation_ros2_B.qtb_b += qrmanager->Q[c6_formation_ros2_B.ix_l +
            c6_formation_ros2_B.totalRank_o] * workingset->
            bwset[c6_formation_ros2_B.totalRank_o];
        }

        if (fabs(c6_formation_ros2_B.qtb_b) >= c6_formation_ros2_B.tol_e) {
          c6_formation_ros2_B.idx_row = -1;
          exitg1 = true;
        } else {
          c6_formation_ros2_B.f_h++;
        }
      }
    }

    if (c6_formation_ros2_B.idx_row > 0) {
      for (c6_formation_ros2_B.totalRank_o = 0; c6_formation_ros2_B.totalRank_o <
           c6_formation_ros2_B.idxStartIneq_e; c6_formation_ros2_B.totalRank_o++)
      {
        c6_formation_ros2_B.ix_l = 13 * c6_formation_ros2_B.totalRank_o;
        memcpy(&qrmanager->QR[c6_formation_ros2_B.ix_l], &workingset->
               ATwset[c6_formation_ros2_B.ix_l], static_cast<uint32_T>
               ((c6_formation_ros2_B.idxEndIneq_tmp + c6_formation_ros2_B.ix_l)
                - c6_formation_ros2_B.ix_l) * sizeof(real_T));
      }

      for (c6_formation_ros2_B.idxStartIneq_e = 0;
           c6_formation_ros2_B.idxStartIneq_e < c6_formation_ros2_B.i_h;
           c6_formation_ros2_B.idxStartIneq_e++) {
        qrmanager->jpvt[c6_formation_ros2_B.idxStartIneq_e] = 1;
      }

      c6_formation_ros2_B.totalRank_o = workingset->nWConstr[0] + 1;
      if (c6_formation_ros2_B.totalRank_o <= c6_formation_ros2_B.i_h) {
        memset(&qrmanager->jpvt[c6_formation_ros2_B.totalRank_o + -1], 0,
               static_cast<uint32_T>((c6_formation_ros2_B.i_h -
                 c6_formation_ros2_B.totalRank_o) + 1) * sizeof(int32_T));
      }

      c6_formation_ros2_factorQRE(qrmanager, workingset->nVar,
        workingset->nWConstr[0]);
      for (c6_formation_ros2_B.idxStartIneq_e = 0;
           c6_formation_ros2_B.idxStartIneq_e < c6_formation_ros2_B.idx_row;
           c6_formation_ros2_B.idxStartIneq_e++) {
        memspace->workspace_int[c6_formation_ros2_B.idxStartIneq_e] =
          qrmanager->jpvt[(c6_formation_ros2_B.i_h - c6_formation_ros2_B.idx_row)
          + c6_formation_ros2_B.idxStartIneq_e];
      }

      c6_formation_ros2_countsort(memspace->workspace_int,
        c6_formation_ros2_B.idx_row, memspace->workspace_sort, 1,
        workingset->nWConstr[0]);
      for (c6_formation_ros2_B.i_h = c6_formation_ros2_B.idx_row;
           c6_formation_ros2_B.i_h >= 1; c6_formation_ros2_B.i_h--) {
        c6_formation_ros_removeEqConstr(workingset, memspace->
          workspace_int[c6_formation_ros2_B.i_h - 1]);
      }
    }
  }

  if ((c6_formation_ros2_B.idx_row != -1) && (workingset->nActiveConstr <= 13))
  {
    c6_formati_RemoveDependentIneq_(workingset, qrmanager, memspace, 100.0);
    c6_formation_ros2_B.okWorkingSet_e = c6_form_feasibleX0ForWorkingSet
      (memspace->workspace_double, solution->xstar, workingset, qrmanager);
    guard1 = false;
    if (!c6_formation_ros2_B.okWorkingSet_e) {
      c6_formati_RemoveDependentIneq_(workingset, qrmanager, memspace, 1000.0);
      c6_formation_ros2_B.okWorkingSet_e = c6_form_feasibleX0ForWorkingSet
        (memspace->workspace_double, solution->xstar, workingset, qrmanager);
      if (!c6_formation_ros2_B.okWorkingSet_e) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (workingset->nWConstr[0] + workingset->nWConstr[1] == workingset->nVar)
      {
        c6_formation_ros2_B.tol_e = c6_for_maxConstraintViolation_n(workingset,
          solution->xstar);
        if (c6_formation_ros2_B.tol_e > 1.0E-8) {
          solution->state = -2;
        }
      }
    }
  } else {
    solution->state = -3;
    c6_formation_ros2_B.idx_row = workingset->nWConstr[0] + workingset->
      nWConstr[1];
    c6_formation_ros2_B.idxStartIneq_e = c6_formation_ros2_B.idx_row + 1;
    c6_formation_ros2_B.totalRank_o = workingset->nActiveConstr;
    for (c6_formation_ros2_B.i_h = c6_formation_ros2_B.idxStartIneq_e;
         c6_formation_ros2_B.i_h <= c6_formation_ros2_B.totalRank_o;
         c6_formation_ros2_B.i_h++) {
      workingset->isActiveConstr[(workingset->isActiveIdx[workingset->
        Wid[c6_formation_ros2_B.i_h - 1] - 1] + workingset->
        Wlocalidx[c6_formation_ros2_B.i_h - 1]) - 2] = false;
    }

    workingset->nWConstr[2] = 0;
    workingset->nWConstr[3] = 0;
    workingset->nWConstr[4] = 0;
    workingset->nActiveConstr = c6_formation_ros2_B.idx_row;
  }
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formation_ros2_linearForm_(boolean_T obj_hasLinear,
  int32_T obj_nvar, real_T workspace[832], const real_T f[12], const real_T x[13])
{
  int32_T beta1;
  static const int8_T h[144] = { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 };

  beta1 = 0;
  if (obj_hasLinear) {
    if (static_cast<uint8_T>(obj_nvar) - 1 >= 0) {
      memcpy(&workspace[0], &f[0], static_cast<uint8_T>(obj_nvar) * sizeof
             (real_T));
    }

    beta1 = 1;
  }

  if (obj_nvar != 0) {
    int32_T e;
    int32_T ix;
    if (beta1 != 1) {
      memset(&workspace[0], 0, static_cast<uint8_T>(obj_nvar) * sizeof(real_T));
    }

    ix = 0;
    e = (obj_nvar - 1) * obj_nvar + 1;
    for (beta1 = 1; obj_nvar < 0 ? beta1 >= e : beta1 <= e; beta1 += obj_nvar) {
      real_T c;
      int32_T g;
      c = 0.5 * x[ix];
      g = (beta1 + obj_nvar) - 1;
      for (int32_T b = beta1; b <= g; b++) {
        int32_T tmp;
        tmp = b - beta1;
        workspace[tmp] += static_cast<real_T>(h[b - 1]) * c;
      }

      ix++;
    }
  }
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
real_T c6_formation_ros2::c6_formation_ros2_computeFval(const
  sEFBi4FIsxLUzGhYLLdGc4E_c6_fo_T *obj, real_T workspace[832], const real_T f[12],
  const real_T x[13])
{
  real_T val;
  int32_T b;
  int32_T idx;
  int32_T scalarLB;
  int32_T vectorUB;
  switch (obj->objtype) {
   case 5:
    val = x[obj->nvar - 1] * obj->gammaScalar;
    break;

   case 3:
    c6_formation_ros2_linearForm_(obj->hasLinear, obj->nvar, workspace, f, x);
    val = 0.0;
    if (obj->nvar >= 1) {
      b = static_cast<uint8_T>(obj->nvar);
      for (idx = 0; idx < b; idx++) {
        val += x[idx] * workspace[idx];
      }
    }
    break;

   default:
    c6_formation_ros2_linearForm_(obj->hasLinear, obj->nvar, workspace, f, x);
    b = obj->nvar + 1;
    scalarLB = ((((12 - obj->nvar) / 2) << 1) + obj->nvar) + 1;
    vectorUB = scalarLB - 2;
    for (idx = b; idx <= vectorUB; idx += 2) {
      _mm_storeu_pd(&workspace[idx - 1], _mm_mul_pd(_mm_loadu_pd(&x[idx - 1]),
        _mm_set1_pd(0.0)));
    }

    for (idx = scalarLB; idx < 13; idx++) {
      workspace[idx - 1] = x[idx - 1] * 0.0;
    }

    val = 0.0;
    for (idx = 0; idx < 12; idx++) {
      val += x[idx] * workspace[idx];
    }
    break;
  }

  return val;
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formation_ros2_xgemv_e(int32_T m, int32_T n, int32_T
  lda, const real_T x[13], real_T y[12])
{
  static const int8_T e[144] = { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 };

  if ((m != 0) && (n != 0)) {
    c6_formation_ros2_B.b_e = static_cast<uint8_T>(m);
    memset(&y[0], 0, static_cast<uint32_T>(c6_formation_ros2_B.b_e) * sizeof
           (real_T));
    c6_formation_ros2_B.ix_j = 0;
    c6_formation_ros2_B.c_b = (n - 1) * lda + 1;
    for (c6_formation_ros2_B.b_iy_o = 1; lda < 0 ? c6_formation_ros2_B.b_iy_o >=
         c6_formation_ros2_B.c_b : c6_formation_ros2_B.b_iy_o <=
         c6_formation_ros2_B.c_b; c6_formation_ros2_B.b_iy_o += lda) {
      c6_formation_ros2_B.d_a = (c6_formation_ros2_B.b_iy_o + m) - 1;
      for (c6_formation_ros2_B.b_e = c6_formation_ros2_B.b_iy_o;
           c6_formation_ros2_B.b_e <= c6_formation_ros2_B.d_a;
           c6_formation_ros2_B.b_e++) {
        c6_formation_ros2_B.i_g2 = c6_formation_ros2_B.b_e -
          c6_formation_ros2_B.b_iy_o;
        y[c6_formation_ros2_B.i_g2] += static_cast<real_T>
          (e[c6_formation_ros2_B.b_e - 1]) * x[c6_formation_ros2_B.ix_j];
      }

      c6_formation_ros2_B.ix_j++;
    }
  }
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formatio_computeGrad_StoreHx
  (sEFBi4FIsxLUzGhYLLdGc4E_c6_fo_T *obj, const real_T f[12], const real_T x[13])
{
  __m128d tmp;
  switch (obj->objtype) {
   case 5:
    c6_formation_ros2_B.vectorUB_a = obj->nvar;
    if (c6_formation_ros2_B.vectorUB_a - 2 >= 0) {
      memset(&obj->grad[0], 0, static_cast<uint32_T>
             (c6_formation_ros2_B.vectorUB_a - 1) * sizeof(real_T));
    }

    obj->grad[obj->nvar - 1] = obj->gammaScalar;
    break;

   case 3:
    c6_formation_ros2_xgemv_e(obj->nvar, obj->nvar, obj->nvar, x, obj->Hx);
    c6_formation_ros2_B.vectorUB_a = static_cast<uint8_T>(obj->nvar);
    if (c6_formation_ros2_B.vectorUB_a - 1 >= 0) {
      memcpy(&obj->grad[0], &obj->Hx[0], static_cast<uint32_T>
             (c6_formation_ros2_B.vectorUB_a) * sizeof(real_T));
    }

    if (obj->hasLinear && (obj->nvar >= 1)) {
      c6_formation_ros2_B.b_ixlast = obj->nvar - 1;
      c6_formation_ros2_B.scalarLB_p = (obj->nvar / 2) << 1;
      c6_formation_ros2_B.vectorUB_a = c6_formation_ros2_B.scalarLB_p - 2;
      for (c6_formation_ros2_B.idx_px = 0; c6_formation_ros2_B.idx_px <=
           c6_formation_ros2_B.vectorUB_a; c6_formation_ros2_B.idx_px += 2) {
        tmp = _mm_loadu_pd(&obj->grad[c6_formation_ros2_B.idx_px]);
        _mm_storeu_pd(&obj->grad[c6_formation_ros2_B.idx_px], _mm_add_pd(tmp,
          _mm_loadu_pd(&f[c6_formation_ros2_B.idx_px])));
      }

      for (c6_formation_ros2_B.idx_px = c6_formation_ros2_B.scalarLB_p;
           c6_formation_ros2_B.idx_px <= c6_formation_ros2_B.b_ixlast;
           c6_formation_ros2_B.idx_px++) {
        obj->grad[c6_formation_ros2_B.idx_px] += f[c6_formation_ros2_B.idx_px];
      }
    }
    break;

   default:
    c6_formation_ros2_xgemv_e(obj->nvar, obj->nvar, obj->nvar, x, obj->Hx);
    c6_formation_ros2_B.b_ixlast = obj->nvar + 1;
    c6_formation_ros2_B.scalarLB_p = ((((12 - obj->nvar) / 2) << 1) + obj->nvar)
      + 1;
    c6_formation_ros2_B.vectorUB_a = c6_formation_ros2_B.scalarLB_p - 2;
    for (c6_formation_ros2_B.idx_px = c6_formation_ros2_B.b_ixlast;
         c6_formation_ros2_B.idx_px <= c6_formation_ros2_B.vectorUB_a;
         c6_formation_ros2_B.idx_px += 2) {
      _mm_storeu_pd(&obj->Hx[c6_formation_ros2_B.idx_px - 1], _mm_mul_pd
                    (_mm_loadu_pd(&x[c6_formation_ros2_B.idx_px - 1]),
                     _mm_set1_pd(0.0)));
    }

    for (c6_formation_ros2_B.idx_px = c6_formation_ros2_B.scalarLB_p;
         c6_formation_ros2_B.idx_px < 13; c6_formation_ros2_B.idx_px++) {
      obj->Hx[c6_formation_ros2_B.idx_px - 1] = x[c6_formation_ros2_B.idx_px - 1]
        * 0.0;
    }

    memcpy(&obj->grad[0], &obj->Hx[0], 12U * sizeof(real_T));
    if (obj->hasLinear && (obj->nvar >= 1)) {
      c6_formation_ros2_B.b_ixlast = obj->nvar - 1;
      c6_formation_ros2_B.scalarLB_p = (obj->nvar / 2) << 1;
      c6_formation_ros2_B.vectorUB_a = c6_formation_ros2_B.scalarLB_p - 2;
      for (c6_formation_ros2_B.idx_px = 0; c6_formation_ros2_B.idx_px <=
           c6_formation_ros2_B.vectorUB_a; c6_formation_ros2_B.idx_px += 2) {
        tmp = _mm_loadu_pd(&obj->grad[c6_formation_ros2_B.idx_px]);
        _mm_storeu_pd(&obj->grad[c6_formation_ros2_B.idx_px], _mm_add_pd(tmp,
          _mm_loadu_pd(&f[c6_formation_ros2_B.idx_px])));
      }

      for (c6_formation_ros2_B.idx_px = c6_formation_ros2_B.scalarLB_p;
           c6_formation_ros2_B.idx_px <= c6_formation_ros2_B.b_ixlast;
           c6_formation_ros2_B.idx_px++) {
        obj->grad[c6_formation_ros2_B.idx_px] += f[c6_formation_ros2_B.idx_px];
      }
    }
    break;
  }
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
real_T c6_formation_ros2::c6_formatio_computeFval_ReuseHx(const
  sEFBi4FIsxLUzGhYLLdGc4E_c6_fo_T *obj, real_T workspace[832], const real_T f[12],
  const real_T x[13])
{
  real_T val;
  switch (obj->objtype) {
   case 5:
    val = x[obj->nvar - 1] * obj->gammaScalar;
    break;

   case 3:
    {
      if (obj->hasLinear) {
        int32_T e;
        int32_T scalarLB;
        int32_T vectorUB;
        e = static_cast<uint8_T>(obj->nvar);
        scalarLB = (static_cast<uint8_T>(obj->nvar) / 2) << 1;
        vectorUB = scalarLB - 2;
        for (int32_T k = 0; k <= vectorUB; k += 2) {
          __m128d tmp;
          tmp = _mm_loadu_pd(&obj->Hx[k]);
          _mm_storeu_pd(&workspace[k], _mm_add_pd(_mm_mul_pd(_mm_set1_pd(0.5),
            tmp), _mm_loadu_pd(&f[k])));
        }

        for (int32_T k = scalarLB; k < e; k++) {
          workspace[k] = 0.5 * obj->Hx[k] + f[k];
        }

        val = 0.0;
        if (obj->nvar >= 1) {
          for (int32_T k = 0; k < e; k++) {
            val += x[k] * workspace[k];
          }
        }
      } else {
        val = 0.0;
        if (obj->nvar >= 1) {
          int32_T e;
          e = static_cast<uint8_T>(obj->nvar);
          for (int32_T k = 0; k < e; k++) {
            val += x[k] * obj->Hx[k];
          }
        }

        val *= 0.5;
      }
    }
    break;

   default:
    {
      if (obj->hasLinear) {
        int32_T e;
        if (static_cast<uint8_T>(obj->nvar) - 1 >= 0) {
          memcpy(&workspace[0], &f[0], static_cast<uint8_T>(obj->nvar) * sizeof
                 (real_T));
        }

        e = 11 - obj->nvar;
        for (int32_T k = 0; k <= e; k++) {
          workspace[obj->nvar + k] = 0.0;
        }

        val = 0.0;
        for (int32_T k = 0; k < 12; k++) {
          real_T workspace_0;
          workspace_0 = 0.5 * obj->Hx[k] + workspace[k];
          workspace[k] = workspace_0;
          val += x[k] * workspace_0;
        }
      } else {
        int32_T e;
        val = 0.0;
        for (int32_T k = 0; k < 12; k++) {
          val += x[k] * obj->Hx[k];
        }

        val *= 0.5;
        e = obj->nvar + 1;
        for (int32_T k = e; k < 13; k++) {
          val += x[k - 1] * 0.0;
        }
      }
    }
    break;
  }

  return val;
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formation_ros2_xrotg_a(real_T *a, real_T *b, real_T
  *c, real_T *s)
{
  c6_formation_ros2_B.roe = *b;
  c6_formation_ros2_B.absa = fabs(*a);
  c6_formation_ros2_B.absb = fabs(*b);
  if (c6_formation_ros2_B.absa > c6_formation_ros2_B.absb) {
    c6_formation_ros2_B.roe = *a;
  }

  c6_formation_ros2_B.scale_d = c6_formation_ros2_B.absa +
    c6_formation_ros2_B.absb;
  if (c6_formation_ros2_B.scale_d == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *a = 0.0;
    *b = 0.0;
  } else {
    c6_formation_ros2_B.ads = c6_formation_ros2_B.absa /
      c6_formation_ros2_B.scale_d;
    c6_formation_ros2_B.bds = c6_formation_ros2_B.absb /
      c6_formation_ros2_B.scale_d;
    c6_formation_ros2_B.scale_d *= sqrt(c6_formation_ros2_B.ads *
      c6_formation_ros2_B.ads + c6_formation_ros2_B.bds *
      c6_formation_ros2_B.bds);
    if (c6_formation_ros2_B.roe < 0.0) {
      c6_formation_ros2_B.scale_d = -c6_formation_ros2_B.scale_d;
    }

    *c = *a / c6_formation_ros2_B.scale_d;
    *s = *b / c6_formation_ros2_B.scale_d;
    if (c6_formation_ros2_B.absa > c6_formation_ros2_B.absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }

    *a = c6_formation_ros2_B.scale_d;
  }
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formation_r_deleteColMoveEnd
  (s2v85VDFdoXWosLJGoY94IG_c6_fo_T *obj, int32_T idx)
{
  if (obj->usedPivoting) {
    c6_formation_ros2_B.i_g = 1;
    while ((c6_formation_ros2_B.i_g <= obj->ncols) && (obj->
            jpvt[c6_formation_ros2_B.i_g - 1] != idx)) {
      c6_formation_ros2_B.i_g++;
    }

    idx = c6_formation_ros2_B.i_g;
  }

  if (idx >= obj->ncols) {
    obj->ncols--;
  } else {
    obj->jpvt[idx - 1] = obj->jpvt[obj->ncols - 1];
    c6_formation_ros2_B.QRk0 = obj->minRowCol;
    for (c6_formation_ros2_B.i_g = 0; c6_formation_ros2_B.i_g <
         c6_formation_ros2_B.QRk0; c6_formation_ros2_B.i_g++) {
      obj->QR[c6_formation_ros2_B.i_g + 13 * (idx - 1)] = obj->QR[(obj->ncols -
        1) * 13 + c6_formation_ros2_B.i_g];
    }

    obj->ncols--;
    if (obj->mrows <= obj->ncols) {
      obj->minRowCol = obj->mrows;
    } else {
      obj->minRowCol = obj->ncols;
    }

    if (idx < obj->mrows) {
      if (obj->mrows - 1 <= obj->ncols) {
        c6_formation_ros2_B.i_g = obj->mrows - 1;
      } else {
        c6_formation_ros2_B.i_g = obj->ncols;
      }

      c6_formation_ros2_B.k_c = c6_formation_ros2_B.i_g;
      c6_formation_ros2_B.idxRotGCol = (idx - 1) * 13;
      while (c6_formation_ros2_B.k_c >= idx) {
        c6_formation_ros2_B.QRk0 = c6_formation_ros2_B.k_c +
          c6_formation_ros2_B.idxRotGCol;
        c6_formation_ros2_B.b_temp = obj->QR[c6_formation_ros2_B.QRk0];
        c6_formation_ros2_xrotg_a(&obj->QR[c6_formation_ros2_B.QRk0 - 1],
          &c6_formation_ros2_B.b_temp, &c6_formation_ros2_B.c_c_d,
          &c6_formation_ros2_B.b_s);
        obj->QR[c6_formation_ros2_B.QRk0] = c6_formation_ros2_B.b_temp;
        c6_formation_ros2_B.e_k = (c6_formation_ros2_B.k_c - 1) * 13;
        obj->QR[c6_formation_ros2_B.k_c + c6_formation_ros2_B.e_k] = 0.0;
        c6_formation_ros2_B.QRk0 = 13 * idx + c6_formation_ros2_B.k_c;
        c6_formation_ros2_B.b_temp_tmp_l = obj->ncols - idx;
        if (c6_formation_ros2_B.b_temp_tmp_l >= 1) {
          for (c6_formation_ros2_B.b_n = 0; c6_formation_ros2_B.b_n <
               c6_formation_ros2_B.b_temp_tmp_l; c6_formation_ros2_B.b_n++) {
            c6_formation_ros2_B.temp_tmp_o = c6_formation_ros2_B.b_n * 13 +
              c6_formation_ros2_B.QRk0;
            c6_formation_ros2_B.b_temp_tmp = obj->
              QR[c6_formation_ros2_B.temp_tmp_o - 1];
            c6_formation_ros2_B.b_temp = c6_formation_ros2_B.b_temp_tmp *
              c6_formation_ros2_B.c_c_d + obj->QR[c6_formation_ros2_B.temp_tmp_o]
              * c6_formation_ros2_B.b_s;
            obj->QR[c6_formation_ros2_B.temp_tmp_o] = obj->
              QR[c6_formation_ros2_B.temp_tmp_o] * c6_formation_ros2_B.c_c_d -
              c6_formation_ros2_B.b_temp_tmp * c6_formation_ros2_B.b_s;
            obj->QR[c6_formation_ros2_B.temp_tmp_o - 1] =
              c6_formation_ros2_B.b_temp;
          }
        }

        c6_formation_ros2_B.b_n = obj->mrows;
        if (obj->mrows >= 1) {
          for (c6_formation_ros2_B.QRk0 = 0; c6_formation_ros2_B.QRk0 <
               c6_formation_ros2_B.b_n; c6_formation_ros2_B.QRk0++) {
            c6_formation_ros2_B.b_temp_tmp_l = c6_formation_ros2_B.e_k +
              c6_formation_ros2_B.QRk0;
            c6_formation_ros2_B.b_temp_tmp = obj->
              Q[c6_formation_ros2_B.b_temp_tmp_l + 13];
            c6_formation_ros2_B.b_temp = c6_formation_ros2_B.b_temp_tmp *
              c6_formation_ros2_B.b_s + obj->Q[c6_formation_ros2_B.b_temp_tmp_l]
              * c6_formation_ros2_B.c_c_d;
            obj->Q[c6_formation_ros2_B.b_temp_tmp_l + 13] =
              c6_formation_ros2_B.b_temp_tmp * c6_formation_ros2_B.c_c_d -
              obj->Q[c6_formation_ros2_B.b_temp_tmp_l] * c6_formation_ros2_B.b_s;
            obj->Q[c6_formation_ros2_B.b_temp_tmp_l] =
              c6_formation_ros2_B.b_temp;
          }
        }

        c6_formation_ros2_B.k_c--;
      }

      for (c6_formation_ros2_B.k_c = idx + 1; c6_formation_ros2_B.k_c <=
           c6_formation_ros2_B.i_g; c6_formation_ros2_B.k_c++) {
        c6_formation_ros2_B.idxRotGCol = (c6_formation_ros2_B.k_c - 1) * 13;
        c6_formation_ros2_B.QRk0 = c6_formation_ros2_B.k_c +
          c6_formation_ros2_B.idxRotGCol;
        c6_formation_ros2_B.b_temp = obj->QR[c6_formation_ros2_B.QRk0];
        c6_formation_ros2_xrotg_a(&obj->QR[c6_formation_ros2_B.QRk0 - 1],
          &c6_formation_ros2_B.b_temp, &c6_formation_ros2_B.c_c_d,
          &c6_formation_ros2_B.b_s);
        obj->QR[c6_formation_ros2_B.QRk0] = c6_formation_ros2_B.b_temp;
        c6_formation_ros2_B.QRk0 = c6_formation_ros2_B.k_c * 14;
        c6_formation_ros2_B.b_n = obj->ncols - c6_formation_ros2_B.k_c;
        if (c6_formation_ros2_B.b_n >= 1) {
          for (c6_formation_ros2_B.e_k = 0; c6_formation_ros2_B.e_k <
               c6_formation_ros2_B.b_n; c6_formation_ros2_B.e_k++) {
            c6_formation_ros2_B.b_temp_tmp_l = c6_formation_ros2_B.e_k * 13 +
              c6_formation_ros2_B.QRk0;
            c6_formation_ros2_B.b_temp_tmp = obj->
              QR[c6_formation_ros2_B.b_temp_tmp_l - 1];
            c6_formation_ros2_B.b_temp = c6_formation_ros2_B.b_temp_tmp *
              c6_formation_ros2_B.c_c_d + obj->
              QR[c6_formation_ros2_B.b_temp_tmp_l] * c6_formation_ros2_B.b_s;
            obj->QR[c6_formation_ros2_B.b_temp_tmp_l] = obj->
              QR[c6_formation_ros2_B.b_temp_tmp_l] * c6_formation_ros2_B.c_c_d -
              c6_formation_ros2_B.b_temp_tmp * c6_formation_ros2_B.b_s;
            obj->QR[c6_formation_ros2_B.b_temp_tmp_l - 1] =
              c6_formation_ros2_B.b_temp;
          }
        }

        c6_formation_ros2_B.e_k = obj->mrows;
        if (obj->mrows >= 1) {
          for (c6_formation_ros2_B.QRk0 = 0; c6_formation_ros2_B.QRk0 <
               c6_formation_ros2_B.e_k; c6_formation_ros2_B.QRk0++) {
            c6_formation_ros2_B.b_n = c6_formation_ros2_B.idxRotGCol +
              c6_formation_ros2_B.QRk0;
            c6_formation_ros2_B.b_temp_tmp = obj->Q[c6_formation_ros2_B.b_n + 13];
            c6_formation_ros2_B.b_temp = c6_formation_ros2_B.b_temp_tmp *
              c6_formation_ros2_B.b_s + obj->Q[c6_formation_ros2_B.b_n] *
              c6_formation_ros2_B.c_c_d;
            obj->Q[c6_formation_ros2_B.b_n + 13] =
              c6_formation_ros2_B.b_temp_tmp * c6_formation_ros2_B.c_c_d -
              obj->Q[c6_formation_ros2_B.b_n] * c6_formation_ros2_B.b_s;
            obj->Q[c6_formation_ros2_B.b_n] = c6_formation_ros2_B.b_temp;
          }
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formation_ros2_fullColLDL2_
  (snmmli8onVqbxLRLhWo5w6G_c6_fo_T *obj, int32_T NColsRemain, real_T REG_PRIMAL)
{
  for (c6_formation_ros2_B.lastDiag = 0; c6_formation_ros2_B.lastDiag <
       NColsRemain; c6_formation_ros2_B.lastDiag++) {
    c6_formation_ros2_B.LD_diagOffset = 14 * c6_formation_ros2_B.lastDiag;
    c6_formation_ros2_B.temp_d = obj->FMat[c6_formation_ros2_B.LD_diagOffset];
    if (fabs(c6_formation_ros2_B.temp_d) <= obj->regTol_) {
      c6_formation_ros2_B.temp_d += REG_PRIMAL;
      obj->FMat[c6_formation_ros2_B.LD_diagOffset] = c6_formation_ros2_B.temp_d;
    }

    c6_formation_ros2_B.alpha1 = -1.0 / c6_formation_ros2_B.temp_d;
    c6_formation_ros2_B.subMatrixDim = (NColsRemain -
      c6_formation_ros2_B.lastDiag) - 2;
    for (c6_formation_ros2_B.b_k = 0; c6_formation_ros2_B.b_k <=
         c6_formation_ros2_B.subMatrixDim; c6_formation_ros2_B.b_k++) {
      obj->workspace_[c6_formation_ros2_B.b_k] = obj->FMat
        [(c6_formation_ros2_B.LD_diagOffset + c6_formation_ros2_B.b_k) + 1];
    }

    if (!(c6_formation_ros2_B.alpha1 == 0.0)) {
      c6_formation_ros2_B.jA_l = c6_formation_ros2_B.LD_diagOffset + 15;
      for (c6_formation_ros2_B.b_k = 0; c6_formation_ros2_B.b_k <=
           c6_formation_ros2_B.subMatrixDim; c6_formation_ros2_B.b_k++) {
        c6_formation_ros2_B.temp_d = obj->workspace_[c6_formation_ros2_B.b_k];
        if (c6_formation_ros2_B.temp_d != 0.0) {
          c6_formation_ros2_B.temp_d *= c6_formation_ros2_B.alpha1;
          c6_formation_ros2_B.b_o = c6_formation_ros2_B.subMatrixDim +
            c6_formation_ros2_B.jA_l;
          for (c6_formation_ros2_B.ijA = c6_formation_ros2_B.jA_l;
               c6_formation_ros2_B.ijA <= c6_formation_ros2_B.b_o;
               c6_formation_ros2_B.ijA++) {
            obj->FMat[c6_formation_ros2_B.ijA - 1] += obj->
              workspace_[c6_formation_ros2_B.ijA - c6_formation_ros2_B.jA_l] *
              c6_formation_ros2_B.temp_d;
          }
        }

        c6_formation_ros2_B.jA_l += 13;
      }
    }

    c6_formation_ros2_B.alpha1 = 1.0 / obj->
      FMat[c6_formation_ros2_B.LD_diagOffset];
    c6_formation_ros2_B.b_k = c6_formation_ros2_B.LD_diagOffset +
      c6_formation_ros2_B.subMatrixDim;
    c6_formation_ros2_B.ijA = (((((c6_formation_ros2_B.b_k -
      c6_formation_ros2_B.LD_diagOffset) + 1) / 2) << 1) +
      c6_formation_ros2_B.LD_diagOffset) + 2;
    c6_formation_ros2_B.jA_l = c6_formation_ros2_B.ijA - 2;
    for (c6_formation_ros2_B.subMatrixDim = c6_formation_ros2_B.LD_diagOffset +
         2; c6_formation_ros2_B.subMatrixDim <= c6_formation_ros2_B.jA_l;
         c6_formation_ros2_B.subMatrixDim += 2) {
      __m128d tmp;
      tmp = _mm_loadu_pd(&obj->FMat[c6_formation_ros2_B.subMatrixDim - 1]);
      _mm_storeu_pd(&obj->FMat[c6_formation_ros2_B.subMatrixDim - 1], _mm_mul_pd
                    (tmp, _mm_set1_pd(c6_formation_ros2_B.alpha1)));
    }

    for (c6_formation_ros2_B.subMatrixDim = c6_formation_ros2_B.ijA;
         c6_formation_ros2_B.subMatrixDim <= c6_formation_ros2_B.b_k + 2;
         c6_formation_ros2_B.subMatrixDim++) {
      obj->FMat[c6_formation_ros2_B.subMatrixDim - 1] *=
        c6_formation_ros2_B.alpha1;
    }
  }

  c6_formation_ros2_B.lastDiag = (NColsRemain - 1) * 14;
  if (fabs(obj->FMat[c6_formation_ros2_B.lastDiag]) <= obj->regTol_) {
    obj->FMat[c6_formation_ros2_B.lastDiag] += REG_PRIMAL;
  }
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formation_ros2_xgemv_e4(int32_T m, int32_T n, const
  real_T A[169], int32_T ia0, const real_T x[832], real_T y[13])
{
  if (m != 0) {
    int32_T b;
    int32_T ix;
    memset(&y[0], 0, static_cast<uint32_T>(m) * sizeof(real_T));
    ix = 0;
    b = (n - 1) * 13 + ia0;
    for (int32_T b_iy = ia0; b_iy <= b; b_iy += 13) {
      int32_T c;
      c = (b_iy + m) - 1;
      for (int32_T ia = b_iy; ia <= c; ia++) {
        int32_T tmp;
        tmp = ia - b_iy;
        y[tmp] += A[ia - 1] * x[ix];
      }

      ix++;
    }
  }
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formation_ros_compute_deltax
  (sCXYlwCFvxAmgJ1M2ooVQBD_c6_fo_T *solution, sivq9bjImOLkQfehLigQhXG_c6_fo_T
   *memspace, const s2v85VDFdoXWosLJGoY94IG_c6_fo_T *qrmanager,
   snmmli8onVqbxLRLhWo5w6G_c6_fo_T *cholmanager, const
   sEFBi4FIsxLUzGhYLLdGc4E_c6_fo_T *objective)
{
  __m128d tmp;
  static const int8_T p[144] = { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 };

  int32_T exitg1;
  c6_formation_ros2_B.nVar_a = qrmanager->mrows - 1;
  c6_formation_ros2_B.mNull_tmp = qrmanager->mrows - qrmanager->ncols;
  if (c6_formation_ros2_B.mNull_tmp <= 0) {
    if (c6_formation_ros2_B.nVar_a >= 0) {
      memset(&solution->searchDir[0], 0, static_cast<uint32_T>
             (c6_formation_ros2_B.nVar_a + 1) * sizeof(real_T));
    }
  } else {
    c6_formation_ros2_B.nullStartIdx = (qrmanager->mrows / 2) << 1;
    c6_formation_ros2_B.nVars = c6_formation_ros2_B.nullStartIdx - 2;
    for (c6_formation_ros2_B.A_maxDiag_idx = 0;
         c6_formation_ros2_B.A_maxDiag_idx <= c6_formation_ros2_B.nVars;
         c6_formation_ros2_B.A_maxDiag_idx += 2) {
      tmp = _mm_loadu_pd(&objective->grad[c6_formation_ros2_B.A_maxDiag_idx]);
      _mm_storeu_pd(&solution->searchDir[c6_formation_ros2_B.A_maxDiag_idx],
                    _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
    }

    for (c6_formation_ros2_B.A_maxDiag_idx = c6_formation_ros2_B.nullStartIdx;
         c6_formation_ros2_B.A_maxDiag_idx <= c6_formation_ros2_B.nVar_a;
         c6_formation_ros2_B.A_maxDiag_idx++) {
      solution->searchDir[c6_formation_ros2_B.A_maxDiag_idx] = -objective->
        grad[c6_formation_ros2_B.A_maxDiag_idx];
    }

    if (qrmanager->ncols <= 0) {
      if (objective->objtype == 3) {
        c6_formation_ros2_B.temp_j = 1.4901161193847656E-6 * static_cast<real_T>
          (qrmanager->mrows);
        cholmanager->ndims = qrmanager->mrows;
        for (c6_formation_ros2_B.mNull_tmp = 0; c6_formation_ros2_B.mNull_tmp <=
             c6_formation_ros2_B.nVar_a; c6_formation_ros2_B.mNull_tmp++) {
          c6_formation_ros2_B.nullStartIdx = (c6_formation_ros2_B.nVar_a + 1) *
            c6_formation_ros2_B.mNull_tmp;
          c6_formation_ros2_B.nVars = 13 * c6_formation_ros2_B.mNull_tmp;
          for (c6_formation_ros2_B.A_maxDiag_idx = 0;
               c6_formation_ros2_B.A_maxDiag_idx <= c6_formation_ros2_B.nVar_a;
               c6_formation_ros2_B.A_maxDiag_idx++) {
            cholmanager->FMat[c6_formation_ros2_B.nVars +
              c6_formation_ros2_B.A_maxDiag_idx] =
              p[c6_formation_ros2_B.A_maxDiag_idx +
              c6_formation_ros2_B.nullStartIdx];
          }
        }

        if (qrmanager->mrows < 1) {
          c6_formation_ros2_B.A_maxDiag_idx = -1;
        } else {
          c6_formation_ros2_B.A_maxDiag_idx = 0;
          if (qrmanager->mrows > 1) {
            c6_formation_ros2_B.smax = fabs(cholmanager->FMat[0]);
            for (c6_formation_ros2_B.mNull_tmp = 2;
                 c6_formation_ros2_B.mNull_tmp <= c6_formation_ros2_B.nVar_a + 1;
                 c6_formation_ros2_B.mNull_tmp++) {
              c6_formation_ros2_B.s_l = fabs(cholmanager->FMat
                [(c6_formation_ros2_B.mNull_tmp - 1) * 14]);
              if (c6_formation_ros2_B.s_l > c6_formation_ros2_B.smax) {
                c6_formation_ros2_B.A_maxDiag_idx =
                  c6_formation_ros2_B.mNull_tmp - 1;
                c6_formation_ros2_B.smax = c6_formation_ros2_B.s_l;
              }
            }
          }
        }

        c6_formation_ros2_B.smax = fabs(cholmanager->FMat[13 *
          c6_formation_ros2_B.A_maxDiag_idx + c6_formation_ros2_B.A_maxDiag_idx])
          * 2.2204460492503131E-16;
        c6_formation_ros2_B.s_l = fabs(c6_formation_ros2_B.temp_j);
        if (c6_formation_ros2_B.smax >= c6_formation_ros2_B.s_l) {
          cholmanager->regTol_ = c6_formation_ros2_B.smax;
        } else {
          cholmanager->regTol_ = c6_formation_ros2_B.s_l;
        }

        c6_formation_ros2_fullColLDL2_(cholmanager, qrmanager->mrows,
          c6_formation_ros2_B.temp_j);
        if (cholmanager->ConvexCheck) {
          c6_formation_ros2_B.mNull_tmp = 0;
          do {
            exitg1 = 0;
            if (c6_formation_ros2_B.mNull_tmp <= c6_formation_ros2_B.nVar_a) {
              if (cholmanager->FMat[13 * c6_formation_ros2_B.mNull_tmp +
                  c6_formation_ros2_B.mNull_tmp] <= 0.0) {
                cholmanager->info = -c6_formation_ros2_B.mNull_tmp - 1;
                exitg1 = 1;
              } else {
                c6_formation_ros2_B.mNull_tmp++;
              }
            } else {
              cholmanager->ConvexCheck = false;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          c6_formation_ros2_B.A_maxDiag_idx = cholmanager->ndims - 1;
          if (cholmanager->ndims != 0) {
            for (c6_formation_ros2_B.mNull_tmp = 0;
                 c6_formation_ros2_B.mNull_tmp <=
                 c6_formation_ros2_B.A_maxDiag_idx;
                 c6_formation_ros2_B.mNull_tmp++) {
              c6_formation_ros2_B.nullStartIdx = c6_formation_ros2_B.mNull_tmp *
                13 + c6_formation_ros2_B.mNull_tmp;
              c6_formation_ros2_B.nVars = c6_formation_ros2_B.A_maxDiag_idx -
                c6_formation_ros2_B.mNull_tmp;
              for (c6_formation_ros2_B.nVar_a = 0; c6_formation_ros2_B.nVar_a <
                   c6_formation_ros2_B.nVars; c6_formation_ros2_B.nVar_a++) {
                c6_formation_ros2_B.b_A_maxDiag_idx =
                  (c6_formation_ros2_B.nVar_a + c6_formation_ros2_B.mNull_tmp) +
                  1;
                solution->searchDir[c6_formation_ros2_B.b_A_maxDiag_idx] -=
                  cholmanager->FMat[(c6_formation_ros2_B.nVar_a +
                                     c6_formation_ros2_B.nullStartIdx) + 1] *
                  solution->searchDir[c6_formation_ros2_B.mNull_tmp];
              }
            }
          }

          c6_formation_ros2_B.A_maxDiag_idx = cholmanager->ndims;
          for (c6_formation_ros2_B.mNull_tmp = 0; c6_formation_ros2_B.mNull_tmp <
               c6_formation_ros2_B.A_maxDiag_idx; c6_formation_ros2_B.mNull_tmp
               ++) {
            solution->searchDir[c6_formation_ros2_B.mNull_tmp] /=
              cholmanager->FMat[13 * c6_formation_ros2_B.mNull_tmp +
              c6_formation_ros2_B.mNull_tmp];
          }

          if (cholmanager->ndims != 0) {
            for (c6_formation_ros2_B.mNull_tmp =
                 c6_formation_ros2_B.A_maxDiag_idx;
                 c6_formation_ros2_B.mNull_tmp >= 1;
                 c6_formation_ros2_B.mNull_tmp--) {
              c6_formation_ros2_B.nullStartIdx = (c6_formation_ros2_B.mNull_tmp
                - 1) * 13;
              c6_formation_ros2_B.temp_j = solution->
                searchDir[c6_formation_ros2_B.mNull_tmp - 1];
              for (c6_formation_ros2_B.nVar_a =
                   c6_formation_ros2_B.A_maxDiag_idx; c6_formation_ros2_B.nVar_a
                   >= c6_formation_ros2_B.mNull_tmp + 1;
                   c6_formation_ros2_B.nVar_a--) {
                c6_formation_ros2_B.temp_j -= cholmanager->FMat
                  [(c6_formation_ros2_B.nullStartIdx +
                    c6_formation_ros2_B.nVar_a) - 1] * solution->
                  searchDir[c6_formation_ros2_B.nVar_a - 1];
              }

              solution->searchDir[c6_formation_ros2_B.mNull_tmp - 1] =
                c6_formation_ros2_B.temp_j;
            }
          }
        }
      }
    } else {
      c6_formation_ros2_B.A_maxDiag_idx = 13 * qrmanager->ncols;
      c6_formation_ros2_B.nullStartIdx = c6_formation_ros2_B.A_maxDiag_idx + 1;
      if (objective->objtype == 5) {
        for (c6_formation_ros2_B.nullStartIdx = 0;
             c6_formation_ros2_B.nullStartIdx < c6_formation_ros2_B.mNull_tmp;
             c6_formation_ros2_B.nullStartIdx++) {
          memspace->workspace_double[c6_formation_ros2_B.nullStartIdx] =
            -qrmanager->Q[(qrmanager->ncols + c6_formation_ros2_B.nullStartIdx) *
            13 + c6_formation_ros2_B.nVar_a];
        }

        c6_formation_ros2_xgemv_e4(qrmanager->mrows,
          c6_formation_ros2_B.mNull_tmp, qrmanager->Q,
          c6_formation_ros2_B.A_maxDiag_idx + 1, memspace->workspace_double,
          solution->searchDir);
      } else {
        if (objective->objtype == 3) {
          c6_formation_ros2_B.nVars = qrmanager->mrows;
          if ((qrmanager->mrows != 0) && (c6_formation_ros2_B.mNull_tmp != 0)) {
            c6_formation_ros2_B.br_e = c6_formation_ros2_B.A_maxDiag_idx;
            c6_formation_ros2_B.lastColC = (c6_formation_ros2_B.mNull_tmp - 1) <<
              6;
            for (c6_formation_ros2_B.b_A_maxDiag_idx = 0;
                 c6_formation_ros2_B.b_A_maxDiag_idx <=
                 c6_formation_ros2_B.lastColC;
                 c6_formation_ros2_B.b_A_maxDiag_idx += 64) {
              c6_formation_ros2_B.e_ix = c6_formation_ros2_B.b_A_maxDiag_idx +
                c6_formation_ros2_B.nVars;
              for (c6_formation_ros2_B.ic = c6_formation_ros2_B.b_A_maxDiag_idx
                   + 1; c6_formation_ros2_B.ic <= c6_formation_ros2_B.e_ix;
                   c6_formation_ros2_B.ic++) {
                memspace->workspace_double[c6_formation_ros2_B.ic - 1] = 0.0;
              }
            }

            for (c6_formation_ros2_B.b_A_maxDiag_idx = 0;
                 c6_formation_ros2_B.b_A_maxDiag_idx <=
                 c6_formation_ros2_B.lastColC;
                 c6_formation_ros2_B.b_A_maxDiag_idx += 64) {
              c6_formation_ros2_B.ar_a = -1;
              c6_formation_ros2_B.h_a = c6_formation_ros2_B.br_e +
                c6_formation_ros2_B.nVars;
              for (c6_formation_ros2_B.ic = c6_formation_ros2_B.br_e + 1;
                   c6_formation_ros2_B.ic <= c6_formation_ros2_B.h_a;
                   c6_formation_ros2_B.ic++) {
                c6_formation_ros2_B.i_i = c6_formation_ros2_B.b_A_maxDiag_idx +
                  c6_formation_ros2_B.nVars;
                for (c6_formation_ros2_B.e_ix =
                     c6_formation_ros2_B.b_A_maxDiag_idx + 1;
                     c6_formation_ros2_B.e_ix <= c6_formation_ros2_B.i_i;
                     c6_formation_ros2_B.e_ix++) {
                  memspace->workspace_double[c6_formation_ros2_B.e_ix - 1] +=
                    static_cast<real_T>(p[(c6_formation_ros2_B.ar_a +
                    c6_formation_ros2_B.e_ix) -
                                        c6_formation_ros2_B.b_A_maxDiag_idx]) *
                    qrmanager->Q[c6_formation_ros2_B.ic - 1];
                }

                c6_formation_ros2_B.ar_a += c6_formation_ros2_B.nVars;
              }

              c6_formation_ros2_B.br_e += 13;
            }
          }

          if (c6_formation_ros2_B.mNull_tmp != 0) {
            c6_formation_ros2_B.br_e = (c6_formation_ros2_B.mNull_tmp - 1) * 13;
            for (c6_formation_ros2_B.b_A_maxDiag_idx = 0;
                 c6_formation_ros2_B.b_A_maxDiag_idx <= c6_formation_ros2_B.br_e;
                 c6_formation_ros2_B.b_A_maxDiag_idx += 13) {
              c6_formation_ros2_B.e_ix = c6_formation_ros2_B.b_A_maxDiag_idx +
                c6_formation_ros2_B.mNull_tmp;
              for (c6_formation_ros2_B.ic = c6_formation_ros2_B.b_A_maxDiag_idx
                   + 1; c6_formation_ros2_B.ic <= c6_formation_ros2_B.e_ix;
                   c6_formation_ros2_B.ic++) {
                cholmanager->FMat[c6_formation_ros2_B.ic - 1] = 0.0;
              }
            }

            c6_formation_ros2_B.lastColC = -1;
            for (c6_formation_ros2_B.b_A_maxDiag_idx = 0;
                 c6_formation_ros2_B.b_A_maxDiag_idx <= c6_formation_ros2_B.br_e;
                 c6_formation_ros2_B.b_A_maxDiag_idx += 13) {
              c6_formation_ros2_B.ar_a = c6_formation_ros2_B.A_maxDiag_idx;
              c6_formation_ros2_B.h_a = c6_formation_ros2_B.b_A_maxDiag_idx +
                c6_formation_ros2_B.mNull_tmp;
              for (c6_formation_ros2_B.ic = c6_formation_ros2_B.b_A_maxDiag_idx
                   + 1; c6_formation_ros2_B.ic <= c6_formation_ros2_B.h_a;
                   c6_formation_ros2_B.ic++) {
                c6_formation_ros2_B.temp_j = 0.0;
                for (c6_formation_ros2_B.e_ix = 0; c6_formation_ros2_B.e_ix <
                     c6_formation_ros2_B.nVars; c6_formation_ros2_B.e_ix++) {
                  c6_formation_ros2_B.temp_j += memspace->workspace_double
                    [(c6_formation_ros2_B.e_ix + c6_formation_ros2_B.lastColC) +
                    1] * qrmanager->Q[c6_formation_ros2_B.e_ix +
                    c6_formation_ros2_B.ar_a];
                }

                cholmanager->FMat[c6_formation_ros2_B.ic - 1] +=
                  c6_formation_ros2_B.temp_j;
                c6_formation_ros2_B.ar_a += 13;
              }

              c6_formation_ros2_B.lastColC += 64;
            }
          }
        }

        c6_formation_ros2_B.temp_j = 1.4901161193847656E-6 * static_cast<real_T>
          (c6_formation_ros2_B.mNull_tmp);
        cholmanager->ndims = c6_formation_ros2_B.mNull_tmp;
        c6_formation_ros2_B.b_A_maxDiag_idx = 0;
        if (c6_formation_ros2_B.mNull_tmp > 1) {
          c6_formation_ros2_B.smax = fabs(cholmanager->FMat[0]);
          for (c6_formation_ros2_B.nVars = 2; c6_formation_ros2_B.nVars <=
               c6_formation_ros2_B.mNull_tmp; c6_formation_ros2_B.nVars++) {
            c6_formation_ros2_B.s_l = fabs(cholmanager->FMat
              [(c6_formation_ros2_B.nVars - 1) * 14]);
            if (c6_formation_ros2_B.s_l > c6_formation_ros2_B.smax) {
              c6_formation_ros2_B.b_A_maxDiag_idx = c6_formation_ros2_B.nVars -
                1;
              c6_formation_ros2_B.smax = c6_formation_ros2_B.s_l;
            }
          }
        }

        c6_formation_ros2_B.smax = fabs(cholmanager->FMat[13 *
          c6_formation_ros2_B.b_A_maxDiag_idx +
          c6_formation_ros2_B.b_A_maxDiag_idx]) * 2.2204460492503131E-16;
        if (c6_formation_ros2_B.smax >= c6_formation_ros2_B.temp_j) {
          cholmanager->regTol_ = c6_formation_ros2_B.smax;
        } else {
          cholmanager->regTol_ = c6_formation_ros2_B.temp_j;
        }

        c6_formation_ros2_fullColLDL2_(cholmanager,
          c6_formation_ros2_B.mNull_tmp, c6_formation_ros2_B.temp_j);
        if (cholmanager->ConvexCheck) {
          c6_formation_ros2_B.nVars = 0;
          do {
            exitg1 = 0;
            if (c6_formation_ros2_B.nVars <= c6_formation_ros2_B.mNull_tmp - 1)
            {
              if (cholmanager->FMat[13 * c6_formation_ros2_B.nVars +
                  c6_formation_ros2_B.nVars] <= 0.0) {
                cholmanager->info = -c6_formation_ros2_B.nVars - 1;
                exitg1 = 1;
              } else {
                c6_formation_ros2_B.nVars++;
              }
            } else {
              cholmanager->ConvexCheck = false;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          if (qrmanager->mrows != 0) {
            memset(&memspace->workspace_double[0], 0, static_cast<uint32_T>
                   (c6_formation_ros2_B.mNull_tmp) * sizeof(real_T));
            c6_formation_ros2_B.ic = ((c6_formation_ros2_B.mNull_tmp - 1) * 13 +
              c6_formation_ros2_B.A_maxDiag_idx) + 1;
            for (c6_formation_ros2_B.nVars = c6_formation_ros2_B.nullStartIdx;
                 c6_formation_ros2_B.nVars <= c6_formation_ros2_B.ic;
                 c6_formation_ros2_B.nVars += 13) {
              c6_formation_ros2_B.temp_j = 0.0;
              c6_formation_ros2_B.e_ix = c6_formation_ros2_B.nVars +
                c6_formation_ros2_B.nVar_a;
              for (c6_formation_ros2_B.b_A_maxDiag_idx =
                   c6_formation_ros2_B.nVars;
                   c6_formation_ros2_B.b_A_maxDiag_idx <=
                   c6_formation_ros2_B.e_ix; c6_formation_ros2_B.b_A_maxDiag_idx
                   ++) {
                c6_formation_ros2_B.temp_j += qrmanager->
                  Q[c6_formation_ros2_B.b_A_maxDiag_idx - 1] * objective->
                  grad[c6_formation_ros2_B.b_A_maxDiag_idx -
                  c6_formation_ros2_B.nVars];
              }

              c6_formation_ros2_B.b_A_maxDiag_idx = div_nde_s32_floor
                ((c6_formation_ros2_B.nVars - c6_formation_ros2_B.A_maxDiag_idx)
                 - 1, 13);
              memspace->workspace_double[c6_formation_ros2_B.b_A_maxDiag_idx] -=
                c6_formation_ros2_B.temp_j;
            }
          }

          c6_formation_ros2_B.nVars = cholmanager->ndims - 1;
          if (cholmanager->ndims != 0) {
            for (c6_formation_ros2_B.nVar_a = 0; c6_formation_ros2_B.nVar_a <=
                 c6_formation_ros2_B.nVars; c6_formation_ros2_B.nVar_a++) {
              c6_formation_ros2_B.b_A_maxDiag_idx = c6_formation_ros2_B.nVar_a *
                13 + c6_formation_ros2_B.nVar_a;
              c6_formation_ros2_B.ic = c6_formation_ros2_B.nVars -
                c6_formation_ros2_B.nVar_a;
              for (c6_formation_ros2_B.nullStartIdx = 0;
                   c6_formation_ros2_B.nullStartIdx < c6_formation_ros2_B.ic;
                   c6_formation_ros2_B.nullStartIdx++) {
                c6_formation_ros2_B.e_ix = (c6_formation_ros2_B.nullStartIdx +
                  c6_formation_ros2_B.nVar_a) + 1;
                memspace->workspace_double[c6_formation_ros2_B.e_ix] -=
                  cholmanager->FMat[(c6_formation_ros2_B.nullStartIdx +
                                     c6_formation_ros2_B.b_A_maxDiag_idx) + 1] *
                  memspace->workspace_double[c6_formation_ros2_B.nVar_a];
              }
            }
          }

          c6_formation_ros2_B.nVars = cholmanager->ndims;
          for (c6_formation_ros2_B.nVar_a = 0; c6_formation_ros2_B.nVar_a <
               c6_formation_ros2_B.nVars; c6_formation_ros2_B.nVar_a++) {
            memspace->workspace_double[c6_formation_ros2_B.nVar_a] /=
              cholmanager->FMat[13 * c6_formation_ros2_B.nVar_a +
              c6_formation_ros2_B.nVar_a];
          }

          if (cholmanager->ndims != 0) {
            for (c6_formation_ros2_B.nVar_a = c6_formation_ros2_B.nVars;
                 c6_formation_ros2_B.nVar_a >= 1; c6_formation_ros2_B.nVar_a--)
            {
              c6_formation_ros2_B.b_A_maxDiag_idx = (c6_formation_ros2_B.nVar_a
                - 1) * 13;
              c6_formation_ros2_B.temp_j = memspace->
                workspace_double[c6_formation_ros2_B.nVar_a - 1];
              for (c6_formation_ros2_B.nullStartIdx = c6_formation_ros2_B.nVars;
                   c6_formation_ros2_B.nullStartIdx >=
                   c6_formation_ros2_B.nVar_a + 1;
                   c6_formation_ros2_B.nullStartIdx--) {
                c6_formation_ros2_B.temp_j -= cholmanager->FMat
                  [(c6_formation_ros2_B.b_A_maxDiag_idx +
                    c6_formation_ros2_B.nullStartIdx) - 1] *
                  memspace->workspace_double[c6_formation_ros2_B.nullStartIdx -
                  1];
              }

              memspace->workspace_double[c6_formation_ros2_B.nVar_a - 1] =
                c6_formation_ros2_B.temp_j;
            }
          }

          c6_formation_ros2_xgemv_e4(qrmanager->mrows,
            c6_formation_ros2_B.mNull_tmp, qrmanager->Q,
            c6_formation_ros2_B.A_maxDiag_idx + 1, memspace->workspace_double,
            solution->searchDir);
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
real_T c6_formation_ros2::c6_formation_ros2_xnrm2_pu(int32_T n, const real_T x
  [13])
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[0]);
    } else {
      c6_formation_ros2_B.scale_h = 3.3121686421112381E-170;
      c6_formation_ros2_B.b_f = static_cast<uint8_T>(n);
      for (c6_formation_ros2_B.k_p = 0; c6_formation_ros2_B.k_p <
           c6_formation_ros2_B.b_f; c6_formation_ros2_B.k_p++) {
        c6_formation_ros2_B.absxk_b = fabs(x[c6_formation_ros2_B.k_p]);
        if (c6_formation_ros2_B.absxk_b > c6_formation_ros2_B.scale_h) {
          c6_formation_ros2_B.t_d = c6_formation_ros2_B.scale_h /
            c6_formation_ros2_B.absxk_b;
          y = y * c6_formation_ros2_B.t_d * c6_formation_ros2_B.t_d + 1.0;
          c6_formation_ros2_B.scale_h = c6_formation_ros2_B.absxk_b;
        } else {
          c6_formation_ros2_B.t_d = c6_formation_ros2_B.absxk_b /
            c6_formation_ros2_B.scale_h;
          y += c6_formation_ros2_B.t_d * c6_formation_ros2_B.t_d;
        }
      }

      y = c6_formation_ros2_B.scale_h * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formation_ros2_xgemv_e4g(int32_T m, const real_T A
  [507], const real_T x[13], real_T y[832])
{
  for (c6_formation_ros2_B.b_iy = 0; c6_formation_ros2_B.b_iy <= 36;
       c6_formation_ros2_B.b_iy += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&y[c6_formation_ros2_B.b_iy]);
    _mm_storeu_pd(&y[c6_formation_ros2_B.b_iy], _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
  }

  for (c6_formation_ros2_B.b_iy = 38; c6_formation_ros2_B.b_iy < 39;
       c6_formation_ros2_B.b_iy++) {
    y[c6_formation_ros2_B.b_iy] = -y[c6_formation_ros2_B.b_iy];
  }

  for (c6_formation_ros2_B.b_iy = 0; c6_formation_ros2_B.b_iy <= 494;
       c6_formation_ros2_B.b_iy += 13) {
    c6_formation_ros2_B.c_l = 0.0;
    c6_formation_ros2_B.b_i = c6_formation_ros2_B.b_iy + m;
    for (c6_formation_ros2_B.ia_ff = c6_formation_ros2_B.b_iy + 1;
         c6_formation_ros2_B.ia_ff <= c6_formation_ros2_B.b_i;
         c6_formation_ros2_B.ia_ff++) {
      c6_formation_ros2_B.c_l += x[(c6_formation_ros2_B.ia_ff -
        c6_formation_ros2_B.b_iy) - 1] * A[c6_formation_ros2_B.ia_ff - 1];
    }

    c6_formation_ros2_B.ia_ff = div_nde_s32_floor(c6_formation_ros2_B.b_iy, 13);
    y[c6_formation_ros2_B.ia_ff] += c6_formation_ros2_B.c_l;
  }
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formation_ros2_ratiotest(const real_T solution_xstar
  [13], const real_T solution_searchDir[13], real_T workspace[832], int32_T
  workingset_nVar, const real_T workingset_Aineq[507], const real_T
  workingset_bineq[39], const real_T workingset_lb[13], const real_T
  workingset_ub[13], const int32_T workingset_indexLB[13], const int32_T
  workingset_indexUB[13], const int32_T workingset_sizes[5], const int32_T
  workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[64],
  const int32_T workingset_nWConstr[5], real_T *toldelta, real_T *alpha,
  boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx)
{
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  c6_formation_ros2_B.p_max = 0.0;
  c6_formation_ros2_B.denomTol = 2.2204460492503131E-13 *
    c6_formation_ros2_xnrm2_pu(workingset_nVar, solution_searchDir);
  if (workingset_nWConstr[2] < 39) {
    memcpy(&workspace[0], &workingset_bineq[0], 39U * sizeof(real_T));
    c6_formation_ros2_xgemv_e4g(workingset_nVar, workingset_Aineq,
      solution_xstar, workspace);
    memset(&workspace[64], 0, 39U * sizeof(real_T));
    for (c6_formation_ros2_B.k_o = 0; c6_formation_ros2_B.k_o <= 494;
         c6_formation_ros2_B.k_o += 13) {
      c6_formation_ros2_B.b_c_g = 0.0;
      c6_formation_ros2_B.d_i = c6_formation_ros2_B.k_o + workingset_nVar;
      for (c6_formation_ros2_B.ia_f = c6_formation_ros2_B.k_o + 1;
           c6_formation_ros2_B.ia_f <= c6_formation_ros2_B.d_i;
           c6_formation_ros2_B.ia_f++) {
        c6_formation_ros2_B.b_c_g += solution_searchDir
          [(c6_formation_ros2_B.ia_f - c6_formation_ros2_B.k_o) - 1] *
          workingset_Aineq[c6_formation_ros2_B.ia_f - 1];
      }

      c6_formation_ros2_B.ia_f = div_nde_s32_floor(c6_formation_ros2_B.k_o, 13)
        + 64;
      workspace[c6_formation_ros2_B.ia_f] += c6_formation_ros2_B.b_c_g;
    }

    for (c6_formation_ros2_B.k_o = 0; c6_formation_ros2_B.k_o < 39;
         c6_formation_ros2_B.k_o++) {
      c6_formation_ros2_B.workspace = workspace[c6_formation_ros2_B.k_o + 64];
      if ((c6_formation_ros2_B.workspace > c6_formation_ros2_B.denomTol) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[2] +
            c6_formation_ros2_B.k_o) - 1])) {
        c6_formation_ros2_B.phaseOneCorrectionX =
          workspace[c6_formation_ros2_B.k_o];
        c6_formation_ros2_B.b_c_g = fabs(c6_formation_ros2_B.phaseOneCorrectionX
          - *toldelta);
        c6_formation_ros2_B.phaseOneCorrectionP = (1.0E-8 -
          c6_formation_ros2_B.phaseOneCorrectionX) + *toldelta;
        if ((c6_formation_ros2_B.b_c_g <=
             c6_formation_ros2_B.phaseOneCorrectionP) || rtIsNaN
            (c6_formation_ros2_B.phaseOneCorrectionP)) {
          c6_formation_ros2_B.phaseOneCorrectionP = c6_formation_ros2_B.b_c_g;
        }

        c6_formation_ros2_B.b_c_g = c6_formation_ros2_B.phaseOneCorrectionP /
          c6_formation_ros2_B.workspace;
        if ((c6_formation_ros2_B.b_c_g <= *alpha) && (fabs
             (c6_formation_ros2_B.workspace) > c6_formation_ros2_B.p_max)) {
          *alpha = c6_formation_ros2_B.b_c_g;
          *constrType = 3;
          *constrIdx = c6_formation_ros2_B.k_o + 1;
          *newBlocking = true;
        }

        c6_formation_ros2_B.b_c_g = fabs(c6_formation_ros2_B.phaseOneCorrectionX);
        if ((!(c6_formation_ros2_B.b_c_g <= 1.0E-8 -
               c6_formation_ros2_B.phaseOneCorrectionX)) && (!rtIsNaN(1.0E-8 -
              c6_formation_ros2_B.phaseOneCorrectionX))) {
          c6_formation_ros2_B.b_c_g = 1.0E-8 -
            c6_formation_ros2_B.phaseOneCorrectionX;
        }

        c6_formation_ros2_B.b_c_g /= c6_formation_ros2_B.workspace;
        if (c6_formation_ros2_B.b_c_g < *alpha) {
          *alpha = c6_formation_ros2_B.b_c_g;
          *constrType = 3;
          *constrIdx = c6_formation_ros2_B.k_o + 1;
          *newBlocking = true;
          c6_formation_ros2_B.p_max = fabs(c6_formation_ros2_B.workspace);
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    c6_formation_ros2_B.phaseOneCorrectionX = solution_xstar[workingset_nVar - 1]
      * 0.0;
    c6_formation_ros2_B.phaseOneCorrectionP = solution_searchDir[workingset_nVar
      - 1] * 0.0;
    c6_formation_ros2_B.ia_f = workingset_sizes[3];
    for (c6_formation_ros2_B.k_o = 0; c6_formation_ros2_B.k_o <=
         c6_formation_ros2_B.ia_f - 2; c6_formation_ros2_B.k_o++) {
      c6_formation_ros2_B.d_i = workingset_indexLB[c6_formation_ros2_B.k_o];
      c6_formation_ros2_B.pk_corrected =
        -solution_searchDir[c6_formation_ros2_B.d_i - 1] -
        c6_formation_ros2_B.phaseOneCorrectionP;
      if ((c6_formation_ros2_B.pk_corrected > c6_formation_ros2_B.denomTol) && (
           !workingset_isActiveConstr[(workingset_isActiveIdx[3] +
            c6_formation_ros2_B.k_o) - 1])) {
        c6_formation_ros2_B.workspace = -solution_xstar[c6_formation_ros2_B.d_i
          - 1] - workingset_lb[c6_formation_ros2_B.d_i - 1];
        c6_formation_ros2_B.ratio = (c6_formation_ros2_B.workspace - *toldelta)
          - c6_formation_ros2_B.phaseOneCorrectionX;
        c6_formation_ros2_B.b_c_g = fabs(c6_formation_ros2_B.ratio);
        if ((!(c6_formation_ros2_B.b_c_g <= 1.0E-8 - c6_formation_ros2_B.ratio))
            && (!rtIsNaN(1.0E-8 - c6_formation_ros2_B.ratio))) {
          c6_formation_ros2_B.b_c_g = 1.0E-8 - c6_formation_ros2_B.ratio;
        }

        c6_formation_ros2_B.b_c_g /= c6_formation_ros2_B.pk_corrected;
        if ((c6_formation_ros2_B.b_c_g <= *alpha) && (fabs
             (c6_formation_ros2_B.pk_corrected) > c6_formation_ros2_B.p_max)) {
          *alpha = c6_formation_ros2_B.b_c_g;
          *constrType = 4;
          *constrIdx = c6_formation_ros2_B.k_o + 1;
          *newBlocking = true;
        }

        c6_formation_ros2_B.ratio = c6_formation_ros2_B.workspace -
          c6_formation_ros2_B.phaseOneCorrectionX;
        c6_formation_ros2_B.b_c_g = fabs(c6_formation_ros2_B.ratio);
        if ((!(c6_formation_ros2_B.b_c_g <= 1.0E-8 - c6_formation_ros2_B.ratio))
            && (!rtIsNaN(1.0E-8 - c6_formation_ros2_B.ratio))) {
          c6_formation_ros2_B.b_c_g = 1.0E-8 - c6_formation_ros2_B.ratio;
        }

        c6_formation_ros2_B.b_c_g /= c6_formation_ros2_B.pk_corrected;
        if (c6_formation_ros2_B.b_c_g < *alpha) {
          *alpha = c6_formation_ros2_B.b_c_g;
          *constrType = 4;
          *constrIdx = c6_formation_ros2_B.k_o + 1;
          *newBlocking = true;
          c6_formation_ros2_B.p_max = fabs(c6_formation_ros2_B.pk_corrected);
        }
      }
    }

    c6_formation_ros2_B.ia_f = workingset_indexLB[workingset_sizes[3] - 1] - 1;
    c6_formation_ros2_B.phaseOneCorrectionX =
      solution_searchDir[c6_formation_ros2_B.ia_f];
    if ((-c6_formation_ros2_B.phaseOneCorrectionX > c6_formation_ros2_B.denomTol)
        && (!workingset_isActiveConstr[(workingset_isActiveIdx[3] +
          workingset_sizes[3]) - 2])) {
      c6_formation_ros2_B.workspace = -solution_xstar[c6_formation_ros2_B.ia_f]
        - workingset_lb[c6_formation_ros2_B.ia_f];
      c6_formation_ros2_B.ratio = c6_formation_ros2_B.workspace - *toldelta;
      c6_formation_ros2_B.b_c_g = fabs(c6_formation_ros2_B.ratio);
      if ((!(c6_formation_ros2_B.b_c_g <= 1.0E-8 - c6_formation_ros2_B.ratio)) &&
          (!rtIsNaN(1.0E-8 - c6_formation_ros2_B.ratio))) {
        c6_formation_ros2_B.b_c_g = 1.0E-8 - c6_formation_ros2_B.ratio;
      }

      c6_formation_ros2_B.b_c_g /= -c6_formation_ros2_B.phaseOneCorrectionX;
      if ((c6_formation_ros2_B.b_c_g <= *alpha) && (fabs
           (c6_formation_ros2_B.phaseOneCorrectionX) > c6_formation_ros2_B.p_max))
      {
        *alpha = c6_formation_ros2_B.b_c_g;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }

      c6_formation_ros2_B.b_c_g = fabs(c6_formation_ros2_B.workspace);
      if ((!(c6_formation_ros2_B.b_c_g <= 1.0E-8 - c6_formation_ros2_B.workspace))
          && (!rtIsNaN(1.0E-8 - c6_formation_ros2_B.workspace))) {
        c6_formation_ros2_B.b_c_g = 1.0E-8 - c6_formation_ros2_B.workspace;
      }

      c6_formation_ros2_B.b_c_g /= -c6_formation_ros2_B.phaseOneCorrectionX;
      if (c6_formation_ros2_B.b_c_g < *alpha) {
        *alpha = c6_formation_ros2_B.b_c_g;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
        c6_formation_ros2_B.p_max = fabs(c6_formation_ros2_B.phaseOneCorrectionX);
      }
    }
  }

  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    c6_formation_ros2_B.phaseOneCorrectionX = solution_xstar[workingset_nVar - 1]
      * 0.0;
    c6_formation_ros2_B.phaseOneCorrectionP = solution_searchDir[workingset_nVar
      - 1] * 0.0;
    c6_formation_ros2_B.ia_f = static_cast<uint8_T>(workingset_sizes[4]);
    for (c6_formation_ros2_B.k_o = 0; c6_formation_ros2_B.k_o <
         c6_formation_ros2_B.ia_f; c6_formation_ros2_B.k_o++) {
      c6_formation_ros2_B.d_i = workingset_indexUB[c6_formation_ros2_B.k_o];
      c6_formation_ros2_B.pk_corrected =
        solution_searchDir[c6_formation_ros2_B.d_i - 1] -
        c6_formation_ros2_B.phaseOneCorrectionP;
      if ((c6_formation_ros2_B.pk_corrected > c6_formation_ros2_B.denomTol) && (
           !workingset_isActiveConstr[(workingset_isActiveIdx[4] +
            c6_formation_ros2_B.k_o) - 1])) {
        c6_formation_ros2_B.workspace = solution_xstar[c6_formation_ros2_B.d_i -
          1] - workingset_ub[c6_formation_ros2_B.d_i - 1];
        c6_formation_ros2_B.ratio = (c6_formation_ros2_B.workspace - *toldelta)
          - c6_formation_ros2_B.phaseOneCorrectionX;
        c6_formation_ros2_B.b_c_g = fabs(c6_formation_ros2_B.ratio);
        if ((!(c6_formation_ros2_B.b_c_g <= 1.0E-8 - c6_formation_ros2_B.ratio))
            && (!rtIsNaN(1.0E-8 - c6_formation_ros2_B.ratio))) {
          c6_formation_ros2_B.b_c_g = 1.0E-8 - c6_formation_ros2_B.ratio;
        }

        c6_formation_ros2_B.b_c_g /= c6_formation_ros2_B.pk_corrected;
        if ((c6_formation_ros2_B.b_c_g <= *alpha) && (fabs
             (c6_formation_ros2_B.pk_corrected) > c6_formation_ros2_B.p_max)) {
          *alpha = c6_formation_ros2_B.b_c_g;
          *constrType = 5;
          *constrIdx = c6_formation_ros2_B.k_o + 1;
          *newBlocking = true;
        }

        c6_formation_ros2_B.ratio = c6_formation_ros2_B.workspace -
          c6_formation_ros2_B.phaseOneCorrectionX;
        c6_formation_ros2_B.b_c_g = fabs(c6_formation_ros2_B.ratio);
        if ((!(c6_formation_ros2_B.b_c_g <= 1.0E-8 - c6_formation_ros2_B.ratio))
            && (!rtIsNaN(1.0E-8 - c6_formation_ros2_B.ratio))) {
          c6_formation_ros2_B.b_c_g = 1.0E-8 - c6_formation_ros2_B.ratio;
        }

        c6_formation_ros2_B.b_c_g /= c6_formation_ros2_B.pk_corrected;
        if (c6_formation_ros2_B.b_c_g < *alpha) {
          *alpha = c6_formation_ros2_B.b_c_g;
          *constrType = 5;
          *constrIdx = c6_formation_ros2_B.k_o + 1;
          *newBlocking = true;
          c6_formation_ros2_B.p_max = fabs(c6_formation_ros2_B.pk_corrected);
        }
      }
    }
  }

  *toldelta += 6.608625846508183E-7;
  if (c6_formation_ros2_B.p_max > 0.0) {
    c6_formation_ros2_B.phaseOneCorrectionP = 6.608625846508183E-7 /
      c6_formation_ros2_B.p_max;
    if (!(*alpha >= c6_formation_ros2_B.phaseOneCorrectionP)) {
      *alpha = c6_formation_ros2_B.phaseOneCorrectionP;
    }
  }

  *newBlocking = (((!*newBlocking) || (!(*alpha > 1.0))) && (*newBlocking));
  if (!(*alpha <= 1.0)) {
    *alpha = 1.0;
  }
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formation__feasibleratiotest(const real_T
  solution_xstar[13], const real_T solution_searchDir[13], real_T workspace[832],
  int32_T workingset_nVar, const real_T workingset_Aineq[507], const real_T
  workingset_bineq[39], const real_T workingset_lb[13], const real_T
  workingset_ub[13], const int32_T workingset_indexLB[13], const int32_T
  workingset_indexUB[13], const int32_T workingset_sizes[5], const int32_T
  workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[64],
  const int32_T workingset_nWConstr[5], boolean_T isPhaseOne, real_T *alpha,
  boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx)
{
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  c6_formation_ros2_B.denomTol_l = 2.2204460492503131E-13 *
    c6_formation_ros2_xnrm2_pu(workingset_nVar, solution_searchDir);
  if (workingset_nWConstr[2] < 39) {
    memcpy(&workspace[0], &workingset_bineq[0], 39U * sizeof(real_T));
    c6_formation_ros2_xgemv_e4g(workingset_nVar, workingset_Aineq,
      solution_xstar, workspace);
    memset(&workspace[64], 0, 39U * sizeof(real_T));
    for (c6_formation_ros2_B.k_m = 0; c6_formation_ros2_B.k_m <= 494;
         c6_formation_ros2_B.k_m += 13) {
      c6_formation_ros2_B.b_c_l = 0.0;
      c6_formation_ros2_B.d_m = c6_formation_ros2_B.k_m + workingset_nVar;
      for (c6_formation_ros2_B.ia_c = c6_formation_ros2_B.k_m + 1;
           c6_formation_ros2_B.ia_c <= c6_formation_ros2_B.d_m;
           c6_formation_ros2_B.ia_c++) {
        c6_formation_ros2_B.b_c_l += solution_searchDir
          [(c6_formation_ros2_B.ia_c - c6_formation_ros2_B.k_m) - 1] *
          workingset_Aineq[c6_formation_ros2_B.ia_c - 1];
      }

      c6_formation_ros2_B.ia_c = div_nde_s32_floor(c6_formation_ros2_B.k_m, 13)
        + 64;
      workspace[c6_formation_ros2_B.ia_c] += c6_formation_ros2_B.b_c_l;
    }

    for (c6_formation_ros2_B.k_m = 0; c6_formation_ros2_B.k_m < 39;
         c6_formation_ros2_B.k_m++) {
      c6_formation_ros2_B.phaseOneCorrectionX_o =
        workspace[c6_formation_ros2_B.k_m + 64];
      if ((c6_formation_ros2_B.phaseOneCorrectionX_o >
           c6_formation_ros2_B.denomTol_l) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[2] + c6_formation_ros2_B.k_m) - 1])) {
        c6_formation_ros2_B.phaseOneCorrectionP_b =
          workspace[c6_formation_ros2_B.k_m];
        c6_formation_ros2_B.b_c_l = fabs
          (c6_formation_ros2_B.phaseOneCorrectionP_b);
        if ((!(c6_formation_ros2_B.b_c_l <= 1.0E-8 -
               c6_formation_ros2_B.phaseOneCorrectionP_b)) && (!rtIsNaN(1.0E-8 -
              c6_formation_ros2_B.phaseOneCorrectionP_b))) {
          c6_formation_ros2_B.b_c_l = 1.0E-8 -
            c6_formation_ros2_B.phaseOneCorrectionP_b;
        }

        c6_formation_ros2_B.b_c_l /= c6_formation_ros2_B.phaseOneCorrectionX_o;
        if (c6_formation_ros2_B.b_c_l < *alpha) {
          *alpha = c6_formation_ros2_B.b_c_l;
          *constrType = 3;
          *constrIdx = c6_formation_ros2_B.k_m + 1;
          *newBlocking = true;
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    c6_formation_ros2_B.phaseOneCorrectionX_o = solution_xstar[workingset_nVar -
      1] * static_cast<real_T>(isPhaseOne);
    c6_formation_ros2_B.phaseOneCorrectionP_b =
      solution_searchDir[workingset_nVar - 1] * static_cast<real_T>(isPhaseOne);
    c6_formation_ros2_B.ia_c = workingset_sizes[3];
    for (c6_formation_ros2_B.k_m = 0; c6_formation_ros2_B.k_m <=
         c6_formation_ros2_B.ia_c - 2; c6_formation_ros2_B.k_m++) {
      c6_formation_ros2_B.d_m = workingset_indexLB[c6_formation_ros2_B.k_m];
      c6_formation_ros2_B.pk_corrected_n =
        -solution_searchDir[c6_formation_ros2_B.d_m - 1] -
        c6_formation_ros2_B.phaseOneCorrectionP_b;
      if ((c6_formation_ros2_B.pk_corrected_n > c6_formation_ros2_B.denomTol_l) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[3] +
            c6_formation_ros2_B.k_m) - 1])) {
        c6_formation_ros2_B.ratio_b = (-solution_xstar[c6_formation_ros2_B.d_m -
          1] - workingset_lb[c6_formation_ros2_B.d_m - 1]) -
          c6_formation_ros2_B.phaseOneCorrectionX_o;
        c6_formation_ros2_B.b_c_l = fabs(c6_formation_ros2_B.ratio_b);
        if ((!(c6_formation_ros2_B.b_c_l <= 1.0E-8 - c6_formation_ros2_B.ratio_b))
            && (!rtIsNaN(1.0E-8 - c6_formation_ros2_B.ratio_b))) {
          c6_formation_ros2_B.b_c_l = 1.0E-8 - c6_formation_ros2_B.ratio_b;
        }

        c6_formation_ros2_B.b_c_l /= c6_formation_ros2_B.pk_corrected_n;
        if (c6_formation_ros2_B.b_c_l < *alpha) {
          *alpha = c6_formation_ros2_B.b_c_l;
          *constrType = 4;
          *constrIdx = c6_formation_ros2_B.k_m + 1;
          *newBlocking = true;
        }
      }
    }

    c6_formation_ros2_B.ia_c = workingset_indexLB[workingset_sizes[3] - 1] - 1;
    c6_formation_ros2_B.phaseOneCorrectionX_o =
      -solution_searchDir[c6_formation_ros2_B.ia_c];
    if ((c6_formation_ros2_B.phaseOneCorrectionX_o >
         c6_formation_ros2_B.denomTol_l) && (!workingset_isActiveConstr
         [(workingset_isActiveIdx[3] + workingset_sizes[3]) - 2])) {
      c6_formation_ros2_B.ratio_b = -solution_xstar[c6_formation_ros2_B.ia_c] -
        workingset_lb[c6_formation_ros2_B.ia_c];
      c6_formation_ros2_B.b_c_l = fabs(c6_formation_ros2_B.ratio_b);
      if ((!(c6_formation_ros2_B.b_c_l <= 1.0E-8 - c6_formation_ros2_B.ratio_b))
          && (!rtIsNaN(1.0E-8 - c6_formation_ros2_B.ratio_b))) {
        c6_formation_ros2_B.b_c_l = 1.0E-8 - c6_formation_ros2_B.ratio_b;
      }

      c6_formation_ros2_B.b_c_l /= c6_formation_ros2_B.phaseOneCorrectionX_o;
      if (c6_formation_ros2_B.b_c_l < *alpha) {
        *alpha = c6_formation_ros2_B.b_c_l;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }
    }
  }

  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    c6_formation_ros2_B.phaseOneCorrectionX_o = solution_xstar[workingset_nVar -
      1] * static_cast<real_T>(isPhaseOne);
    c6_formation_ros2_B.phaseOneCorrectionP_b =
      solution_searchDir[workingset_nVar - 1] * static_cast<real_T>(isPhaseOne);
    c6_formation_ros2_B.ia_c = static_cast<uint8_T>(workingset_sizes[4]);
    for (c6_formation_ros2_B.k_m = 0; c6_formation_ros2_B.k_m <
         c6_formation_ros2_B.ia_c; c6_formation_ros2_B.k_m++) {
      c6_formation_ros2_B.d_m = workingset_indexUB[c6_formation_ros2_B.k_m];
      c6_formation_ros2_B.pk_corrected_n =
        solution_searchDir[c6_formation_ros2_B.d_m - 1] -
        c6_formation_ros2_B.phaseOneCorrectionP_b;
      if ((c6_formation_ros2_B.pk_corrected_n > c6_formation_ros2_B.denomTol_l) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[4] +
            c6_formation_ros2_B.k_m) - 1])) {
        c6_formation_ros2_B.ratio_b = (solution_xstar[c6_formation_ros2_B.d_m -
          1] - workingset_ub[c6_formation_ros2_B.d_m - 1]) -
          c6_formation_ros2_B.phaseOneCorrectionX_o;
        c6_formation_ros2_B.b_c_l = fabs(c6_formation_ros2_B.ratio_b);
        if ((!(c6_formation_ros2_B.b_c_l <= 1.0E-8 - c6_formation_ros2_B.ratio_b))
            && (!rtIsNaN(1.0E-8 - c6_formation_ros2_B.ratio_b))) {
          c6_formation_ros2_B.b_c_l = 1.0E-8 - c6_formation_ros2_B.ratio_b;
        }

        c6_formation_ros2_B.b_c_l /= c6_formation_ros2_B.pk_corrected_n;
        if (c6_formation_ros2_B.b_c_l < *alpha) {
          *alpha = c6_formation_ros2_B.b_c_l;
          *constrType = 5;
          *constrIdx = c6_formation_ros2_B.k_m + 1;
          *newBlocking = true;
        }
      }
    }
  }

  if (!isPhaseOne) {
    *newBlocking = (((!*newBlocking) || (!(*alpha > 1.0))) && (*newBlocking));
    if (!(*alpha <= 1.0)) {
      *alpha = 1.0;
    }
  }
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_f_addBoundToActiveSetMatrix_
  (sIqAUiO7iN3zlnKzlJ0LdOE_c6_fo_T *obj, int32_T TYPE, int32_T idx_local)
{
  int32_T colOffset;
  int32_T idx_bnd_local;
  obj->nWConstr[TYPE - 1]++;
  obj->isActiveConstr[(obj->isActiveIdx[TYPE - 1] + idx_local) - 2] = true;
  obj->nActiveConstr++;
  obj->Wid[obj->nActiveConstr - 1] = TYPE;
  obj->Wlocalidx[obj->nActiveConstr - 1] = idx_local;
  colOffset = (obj->nActiveConstr - 1) * 13 - 1;
  if (TYPE == 5) {
    idx_bnd_local = obj->indexUB[idx_local - 1];
    obj->bwset[obj->nActiveConstr - 1] = obj->ub[idx_bnd_local - 1];
  } else {
    idx_bnd_local = obj->indexLB[idx_local - 1];
    obj->bwset[obj->nActiveConstr - 1] = obj->lb[idx_bnd_local - 1];
  }

  if (static_cast<uint8_T>(idx_bnd_local - 1) - 1 >= 0) {
    memset(&obj->ATwset[colOffset + 1], 0, static_cast<uint32_T>
           ((static_cast<uint8_T>(idx_bnd_local - 1) + colOffset) - colOffset) *
           sizeof(real_T));
  }

  obj->ATwset[idx_bnd_local + colOffset] = static_cast<real_T>(TYPE == 5) * 2.0
    - 1.0;
  if (idx_bnd_local + 1 <= obj->nVar) {
    memset(&obj->ATwset[(idx_bnd_local + colOffset) + 1], 0,
           static_cast<uint32_T>(((obj->nVar + colOffset) - idx_bnd_local) -
            colOffset) * sizeof(real_T));
  }

  switch (obj->probType) {
   case 3:
   case 2:
    break;

   default:
    obj->ATwset[obj->nVar + colOffset] = -1.0;
    break;
  }
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formation_ros_compute_lambda(real_T workspace[832],
  sCXYlwCFvxAmgJ1M2ooVQBD_c6_fo_T *solution, const
  sEFBi4FIsxLUzGhYLLdGc4E_c6_fo_T *objective, const
  s2v85VDFdoXWosLJGoY94IG_c6_fo_T *qrmanager)
{
  int32_T nActiveConstr_tmp_tmp;
  nActiveConstr_tmp_tmp = qrmanager->ncols;
  if (qrmanager->ncols > 0) {
    real_T c;
    int32_T b_idx;
    int32_T idxQR;
    boolean_T guard1;
    guard1 = false;
    if (objective->objtype != 4) {
      boolean_T nonDegenerate;
      c = 100.0 * static_cast<real_T>(qrmanager->mrows) * 2.2204460492503131E-16;
      nonDegenerate = ((qrmanager->mrows > 0) && (qrmanager->ncols > 0));
      if (nonDegenerate) {
        boolean_T guard2;
        b_idx = qrmanager->ncols;
        guard2 = false;
        if (qrmanager->mrows < qrmanager->ncols) {
          idxQR = (qrmanager->ncols - 1) * 13 + qrmanager->mrows;
          while ((b_idx > qrmanager->mrows) && (fabs(qrmanager->QR[idxQR - 1]) >=
                  c)) {
            b_idx--;
            idxQR -= 13;
          }

          nonDegenerate = (b_idx == qrmanager->mrows);
          if (!nonDegenerate) {
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          idxQR = (b_idx - 1) * 13 + b_idx;
          while ((b_idx >= 1) && (fabs(qrmanager->QR[idxQR - 1]) >= c)) {
            b_idx--;
            idxQR -= 14;
          }

          nonDegenerate = (b_idx == 0);
        }
      }

      if (!nonDegenerate) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      int32_T b_ix;
      int32_T jjA;
      if (qrmanager->mrows != 0) {
        memset(&workspace[0], 0, static_cast<uint32_T>(qrmanager->ncols) *
               sizeof(real_T));
        jjA = (qrmanager->ncols - 1) * 13 + 1;
        for (b_idx = 1; b_idx <= jjA; b_idx += 13) {
          c = 0.0;
          b_ix = (b_idx + qrmanager->mrows) - 1;
          for (idxQR = b_idx; idxQR <= b_ix; idxQR++) {
            c += qrmanager->Q[idxQR - 1] * objective->grad[idxQR - b_idx];
          }

          idxQR = div_nde_s32_floor(b_idx - 1, 13);
          workspace[idxQR] += c;
        }
      }

      for (b_idx = nActiveConstr_tmp_tmp; b_idx >= 1; b_idx--) {
        jjA = ((b_idx - 1) * 13 + b_idx) - 2;
        workspace[b_idx - 1] /= qrmanager->QR[jjA + 1];
        for (idxQR = 0; idxQR <= b_idx - 2; idxQR++) {
          b_ix = (b_idx - idxQR) - 2;
          workspace[b_ix] -= workspace[b_idx - 1] * qrmanager->QR[jjA - idxQR];
        }
      }

      idxQR = (qrmanager->ncols / 2) << 1;
      jjA = idxQR - 2;
      for (b_idx = 0; b_idx <= jjA; b_idx += 2) {
        __m128d tmp;
        tmp = _mm_loadu_pd(&workspace[b_idx]);
        _mm_storeu_pd(&solution->lambda[b_idx], _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
      }

      for (b_idx = idxQR; b_idx < nActiveConstr_tmp_tmp; b_idx++) {
        solution->lambda[b_idx] = -workspace[b_idx];
      }
    }
  }
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formation_ros2_iterate(const real_T f[12],
  sCXYlwCFvxAmgJ1M2ooVQBD_c6_fo_T *solution, sivq9bjImOLkQfehLigQhXG_c6_fo_T
  *memspace, sIqAUiO7iN3zlnKzlJ0LdOE_c6_fo_T *workingset,
  s2v85VDFdoXWosLJGoY94IG_c6_fo_T *qrmanager, snmmli8onVqbxLRLhWo5w6G_c6_fo_T
  *cholmanager, sEFBi4FIsxLUzGhYLLdGc4E_c6_fo_T *objective, real_T
  options_ObjectiveLimit, real_T options_StepTolerance, int32_T
  runTimeOptions_MaxIterations, real_T runTimeOptions_ConstrRelTolFact, real_T
  runTimeOptions_ProbRelTolFactor, boolean_T runTimeOptions_RemainFeasible)
{
  __m128d tmp;
  __m128d tmp_0;
  int32_T exitg1;
  boolean_T guard1;
  c6_formation_ros2_B.subProblemChanged = true;
  c6_formation_ros2_B.updateFval = true;
  c6_formation_ros2_B.activeSetChangeID = 0;
  c6_formation_ros2_B.TYPE = objective->objtype;
  c6_formation_ros2_B.tolDelta = 6.7434957617430445E-7;
  c6_formation_ros2_B.nVar_h = workingset->nVar;
  c6_formation_ros2_B.globalActiveConstrIdx = 0;
  c6_formatio_computeGrad_StoreHx(objective, f, solution->xstar);
  solution->fstar = c6_formatio_computeFval_ReuseHx(objective,
    memspace->workspace_double, f, solution->xstar);
  if (solution->iterations < runTimeOptions_MaxIterations) {
    solution->state = -5;
  } else {
    solution->state = 0;
  }

  memset(&solution->lambda[0], 0, sizeof(real_T) << 6U);
  do {
    exitg1 = 0;
    if (solution->state == -5) {
      guard1 = false;
      if (c6_formation_ros2_B.subProblemChanged) {
        switch (c6_formation_ros2_B.activeSetChangeID) {
         case 1:
          c6_formation_ros2_B.Qk0 = (workingset->nActiveConstr - 1) * 13;
          if (qrmanager->mrows <= qrmanager->ncols + 1) {
            qrmanager->minRowCol = qrmanager->mrows;
          } else {
            qrmanager->minRowCol = qrmanager->ncols + 1;
          }

          c6_formation_ros2_B.iy0 = 13 * qrmanager->ncols;
          if (qrmanager->mrows != 0) {
            c6_formation_ros2_B.iyend = c6_formation_ros2_B.iy0 +
              qrmanager->mrows;
            if (c6_formation_ros2_B.iy0 + 1 <= c6_formation_ros2_B.iyend) {
              memset(&qrmanager->QR[c6_formation_ros2_B.iy0], 0,
                     static_cast<uint32_T>(c6_formation_ros2_B.iyend -
                      c6_formation_ros2_B.iy0) * sizeof(real_T));
            }

            c6_formation_ros2_B.l = (qrmanager->mrows - 1) * 13 + 1;
            for (c6_formation_ros2_B.localActiveConstrIdx = 1;
                 c6_formation_ros2_B.localActiveConstrIdx <=
                 c6_formation_ros2_B.l; c6_formation_ros2_B.localActiveConstrIdx
                 += 13) {
              c6_formation_ros2_B.normDelta = 0.0;
              c6_formation_ros2_B.m = (c6_formation_ros2_B.localActiveConstrIdx
                + qrmanager->mrows) - 1;
              for (c6_formation_ros2_B.iyend =
                   c6_formation_ros2_B.localActiveConstrIdx;
                   c6_formation_ros2_B.iyend <= c6_formation_ros2_B.m;
                   c6_formation_ros2_B.iyend++) {
                c6_formation_ros2_B.normDelta += workingset->ATwset
                  [(c6_formation_ros2_B.Qk0 + c6_formation_ros2_B.iyend) -
                  c6_formation_ros2_B.localActiveConstrIdx] * qrmanager->
                  Q[c6_formation_ros2_B.iyend - 1];
              }

              c6_formation_ros2_B.iyend = div_nde_s32_floor
                (c6_formation_ros2_B.localActiveConstrIdx - 1, 13) +
                c6_formation_ros2_B.iy0;
              qrmanager->QR[c6_formation_ros2_B.iyend] +=
                c6_formation_ros2_B.normDelta;
            }
          }

          qrmanager->ncols++;
          qrmanager->jpvt[qrmanager->ncols - 1] = qrmanager->ncols;
          c6_formation_ros2_B.iyend = qrmanager->mrows - 2;
          while (c6_formation_ros2_B.iyend + 2 > qrmanager->ncols) {
            c6_formation_ros2_B.localActiveConstrIdx = (qrmanager->ncols - 1) *
              13 + c6_formation_ros2_B.iyend;
            c6_formation_ros2_B.temp_p = qrmanager->
              QR[c6_formation_ros2_B.localActiveConstrIdx + 1];
            c6_formation_ros2_xrotg_a(&qrmanager->
              QR[c6_formation_ros2_B.localActiveConstrIdx],
              &c6_formation_ros2_B.temp_p, &c6_formation_ros2_B.normDelta,
              &c6_formation_ros2_B.s_n);
            qrmanager->QR[c6_formation_ros2_B.localActiveConstrIdx + 1] =
              c6_formation_ros2_B.temp_p;
            c6_formation_ros2_B.Qk0 = 13 * c6_formation_ros2_B.iyend;
            c6_formation_ros2_B.iy0 = qrmanager->mrows;
            if (qrmanager->mrows >= 1) {
              for (c6_formation_ros2_B.localActiveConstrIdx = 0;
                   c6_formation_ros2_B.localActiveConstrIdx <
                   c6_formation_ros2_B.iy0;
                   c6_formation_ros2_B.localActiveConstrIdx++) {
                c6_formation_ros2_B.l = c6_formation_ros2_B.Qk0 +
                  c6_formation_ros2_B.localActiveConstrIdx;
                c6_formation_ros2_B.temp_tmp = qrmanager->
                  Q[c6_formation_ros2_B.l + 13];
                c6_formation_ros2_B.temp_p = c6_formation_ros2_B.temp_tmp *
                  c6_formation_ros2_B.s_n + qrmanager->Q[c6_formation_ros2_B.l] *
                  c6_formation_ros2_B.normDelta;
                qrmanager->Q[c6_formation_ros2_B.l + 13] =
                  c6_formation_ros2_B.temp_tmp * c6_formation_ros2_B.normDelta -
                  qrmanager->Q[c6_formation_ros2_B.l] * c6_formation_ros2_B.s_n;
                qrmanager->Q[c6_formation_ros2_B.l] = c6_formation_ros2_B.temp_p;
              }
            }

            c6_formation_ros2_B.iyend--;
          }
          break;

         case -1:
          c6_formation_r_deleteColMoveEnd(qrmanager,
            c6_formation_ros2_B.globalActiveConstrIdx);
          break;

         default:
          c6_formation_ros2_factorQR(qrmanager, workingset->ATwset,
            c6_formation_ros2_B.nVar_h, workingset->nActiveConstr);
          c6_formation_ros2_computeQ_(qrmanager, qrmanager->mrows);
          break;
        }

        c6_formation_ros_compute_deltax(solution, memspace, qrmanager,
          cholmanager, objective);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          c6_formation_ros2_B.normDelta = c6_formation_ros2_xnrm2_pu
            (c6_formation_ros2_B.nVar_h, solution->searchDir);
          guard1 = true;
        }
      } else {
        c6_formation_ros2_B.iyend = static_cast<uint8_T>
          (c6_formation_ros2_B.nVar_h);
        memset(&solution->searchDir[0], 0, static_cast<uint32_T>
               (c6_formation_ros2_B.iyend) * sizeof(real_T));
        c6_formation_ros2_B.normDelta = 0.0;
        guard1 = true;
      }

      if (guard1) {
        if ((!c6_formation_ros2_B.subProblemChanged) ||
            (c6_formation_ros2_B.normDelta < options_StepTolerance) ||
            (workingset->nActiveConstr >= c6_formation_ros2_B.nVar_h)) {
          c6_formation_ros_compute_lambda(memspace->workspace_double, solution,
            objective, qrmanager);
          if ((solution->state != -7) || (workingset->nActiveConstr >
               c6_formation_ros2_B.nVar_h)) {
            c6_formation_ros2_B.iyend = 0;
            c6_formation_ros2_B.normDelta = 0.0 *
              runTimeOptions_ProbRelTolFactor * static_cast<real_T>
              (c6_formation_ros2_B.TYPE != 5);
            c6_formation_ros2_B.Qk0 = (workingset->nWConstr[0] +
              workingset->nWConstr[1]) + 1;
            c6_formation_ros2_B.iy0 = workingset->nActiveConstr;
            for (c6_formation_ros2_B.localActiveConstrIdx =
                 c6_formation_ros2_B.Qk0;
                 c6_formation_ros2_B.localActiveConstrIdx <=
                 c6_formation_ros2_B.iy0;
                 c6_formation_ros2_B.localActiveConstrIdx++) {
              c6_formation_ros2_B.s_n = solution->
                lambda[c6_formation_ros2_B.localActiveConstrIdx - 1];
              if (c6_formation_ros2_B.s_n < c6_formation_ros2_B.normDelta) {
                c6_formation_ros2_B.normDelta = c6_formation_ros2_B.s_n;
                c6_formation_ros2_B.iyend =
                  c6_formation_ros2_B.localActiveConstrIdx;
              }
            }

            if (c6_formation_ros2_B.iyend == 0) {
              solution->state = 1;
            } else {
              c6_formation_ros2_B.activeSetChangeID = -1;
              c6_formation_ros2_B.globalActiveConstrIdx =
                c6_formation_ros2_B.iyend;
              c6_formation_ros2_B.subProblemChanged = true;
              c6_formation_ros2_removeConstr(workingset,
                c6_formation_ros2_B.iyend);
              solution->lambda[c6_formation_ros2_B.iyend - 1] = 0.0;
            }
          } else {
            c6_formation_ros2_B.iyend = workingset->nActiveConstr;
            c6_formation_ros2_B.activeSetChangeID = 0;
            c6_formation_ros2_B.globalActiveConstrIdx =
              workingset->nActiveConstr;
            c6_formation_ros2_B.subProblemChanged = true;
            c6_formation_ros2_removeConstr(workingset, workingset->nActiveConstr);
            solution->lambda[c6_formation_ros2_B.iyend - 1] = 0.0;
          }

          c6_formation_ros2_B.updateFval = false;
        } else {
          c6_formation_ros2_B.updateFval = (c6_formation_ros2_B.TYPE == 5);
          if (c6_formation_ros2_B.updateFval || runTimeOptions_RemainFeasible) {
            c6_formation__feasibleratiotest(solution->xstar, solution->searchDir,
              memspace->workspace_double, workingset->nVar, workingset->Aineq,
              workingset->bineq, workingset->lb, workingset->ub,
              workingset->indexLB, workingset->indexUB, workingset->sizes,
              workingset->isActiveIdx, workingset->isActiveConstr,
              workingset->nWConstr, c6_formation_ros2_B.updateFval,
              &c6_formation_ros2_B.normDelta, &c6_formation_ros2_B.newBlocking,
              &c6_formation_ros2_B.iyend,
              &c6_formation_ros2_B.localActiveConstrIdx);
          } else {
            c6_formation_ros2_ratiotest(solution->xstar, solution->searchDir,
              memspace->workspace_double, workingset->nVar, workingset->Aineq,
              workingset->bineq, workingset->lb, workingset->ub,
              workingset->indexLB, workingset->indexUB, workingset->sizes,
              workingset->isActiveIdx, workingset->isActiveConstr,
              workingset->nWConstr, &c6_formation_ros2_B.tolDelta,
              &c6_formation_ros2_B.normDelta, &c6_formation_ros2_B.newBlocking,
              &c6_formation_ros2_B.iyend,
              &c6_formation_ros2_B.localActiveConstrIdx);
          }

          if (c6_formation_ros2_B.newBlocking) {
            switch (c6_formation_ros2_B.iyend) {
             case 3:
              workingset->nWConstr[2]++;
              workingset->isActiveConstr[(workingset->isActiveIdx[2] +
                c6_formation_ros2_B.localActiveConstrIdx) - 2] = true;
              workingset->nActiveConstr++;
              workingset->Wid[workingset->nActiveConstr - 1] = 3;
              workingset->Wlocalidx[workingset->nActiveConstr - 1] =
                c6_formation_ros2_B.localActiveConstrIdx;
              c6_formation_ros2_B.iyend =
                (c6_formation_ros2_B.localActiveConstrIdx - 1) * 13;
              c6_formation_ros2_B.Qk0 = (workingset->nActiveConstr - 1) * 13;
              c6_formation_ros2_B.iy0 = workingset->nVar - 1;
              for (c6_formation_ros2_B.activeSetChangeID = 0;
                   c6_formation_ros2_B.activeSetChangeID <=
                   c6_formation_ros2_B.iy0;
                   c6_formation_ros2_B.activeSetChangeID++) {
                workingset->ATwset[c6_formation_ros2_B.Qk0 +
                  c6_formation_ros2_B.activeSetChangeID] = workingset->
                  Aineq[c6_formation_ros2_B.iyend +
                  c6_formation_ros2_B.activeSetChangeID];
              }

              workingset->bwset[workingset->nActiveConstr - 1] =
                workingset->bineq[c6_formation_ros2_B.localActiveConstrIdx - 1];
              break;

             case 4:
              c6_f_addBoundToActiveSetMatrix_(workingset, 4,
                c6_formation_ros2_B.localActiveConstrIdx);
              break;

             default:
              c6_f_addBoundToActiveSetMatrix_(workingset, 5,
                c6_formation_ros2_B.localActiveConstrIdx);
              break;
            }

            c6_formation_ros2_B.activeSetChangeID = 1;
          } else {
            if (objective->objtype == 5) {
              if (c6_formation_ros2_xnrm2_pu(objective->nvar,
                   solution->searchDir) > 100.0 * static_cast<real_T>
                  (objective->nvar) * 1.4901161193847656E-8) {
                solution->state = 3;
              } else {
                solution->state = 4;
              }
            }

            c6_formation_ros2_B.subProblemChanged = false;
            if (workingset->nActiveConstr == 0) {
              solution->state = 1;
            }
          }

          if (!(c6_formation_ros2_B.normDelta == 0.0)) {
            c6_formation_ros2_B.iyend = (c6_formation_ros2_B.nVar_h / 2) << 1;
            c6_formation_ros2_B.Qk0 = c6_formation_ros2_B.iyend - 2;
            for (c6_formation_ros2_B.localActiveConstrIdx = 0;
                 c6_formation_ros2_B.localActiveConstrIdx <=
                 c6_formation_ros2_B.Qk0;
                 c6_formation_ros2_B.localActiveConstrIdx += 2) {
              tmp = _mm_loadu_pd(&solution->
                                 searchDir[c6_formation_ros2_B.localActiveConstrIdx]);
              tmp_0 = _mm_loadu_pd(&solution->
                                   xstar[c6_formation_ros2_B.localActiveConstrIdx]);
              _mm_storeu_pd(&solution->
                            xstar[c6_formation_ros2_B.localActiveConstrIdx],
                            _mm_add_pd(_mm_mul_pd(_mm_set1_pd
                (c6_formation_ros2_B.normDelta), tmp), tmp_0));
            }

            for (c6_formation_ros2_B.localActiveConstrIdx =
                 c6_formation_ros2_B.iyend;
                 c6_formation_ros2_B.localActiveConstrIdx <
                 c6_formation_ros2_B.nVar_h;
                 c6_formation_ros2_B.localActiveConstrIdx++) {
              solution->xstar[c6_formation_ros2_B.localActiveConstrIdx] +=
                c6_formation_ros2_B.normDelta * solution->
                searchDir[c6_formation_ros2_B.localActiveConstrIdx];
            }
          }

          c6_formatio_computeGrad_StoreHx(objective, f, solution->xstar);
          c6_formation_ros2_B.updateFval = true;
        }

        solution->iterations++;
        if ((solution->iterations >= runTimeOptions_MaxIterations) &&
            ((solution->state != 1) || (objective->objtype == 5))) {
          solution->state = 0;
        }

        if (solution->iterations - solution->iterations / 50 * 50 == 0) {
          solution->maxConstr = c6_for_maxConstraintViolation_n(workingset,
            solution->xstar);
          c6_formation_ros2_B.normDelta = solution->maxConstr;
          if (objective->objtype == 5) {
            c6_formation_ros2_B.normDelta = solution->maxConstr -
              solution->xstar[objective->nvar - 1];
          }

          if (c6_formation_ros2_B.normDelta > 1.0E-8 *
              runTimeOptions_ConstrRelTolFact) {
            c6_formation_ros2_B.iyend = static_cast<uint8_T>(objective->nvar);
            if (c6_formation_ros2_B.iyend - 1 >= 0) {
              memcpy(&solution->searchDir[0], &solution->xstar[0], static_cast<
                     uint32_T>(c6_formation_ros2_B.iyend) * sizeof(real_T));
            }

            c6_formation_ros2_B.newBlocking = c6_form_feasibleX0ForWorkingSet
              (memspace->workspace_double, solution->searchDir, workingset,
               qrmanager);
            if ((!c6_formation_ros2_B.newBlocking) && (solution->state != 0)) {
              solution->state = -2;
            }

            c6_formation_ros2_B.activeSetChangeID = 0;
            c6_formation_ros2_B.normDelta = c6_for_maxConstraintViolation_n
              (workingset, solution->searchDir);
            if (c6_formation_ros2_B.normDelta < solution->maxConstr) {
              if (c6_formation_ros2_B.iyend - 1 >= 0) {
                memcpy(&solution->xstar[0], &solution->searchDir[0],
                       static_cast<uint32_T>(c6_formation_ros2_B.iyend) * sizeof
                       (real_T));
              }

              solution->maxConstr = c6_formation_ros2_B.normDelta;
            }
          }
        }

        if (c6_formation_ros2_B.updateFval && (options_ObjectiveLimit >
             (rtMinusInf))) {
          solution->fstar = c6_formatio_computeFval_ReuseHx(objective,
            memspace->workspace_double, f, solution->xstar);
          if ((solution->fstar < options_ObjectiveLimit) && ((solution->state !=
                0) || (objective->objtype != 5))) {
            solution->state = 2;
          }
        }
      }
    } else {
      if (!c6_formation_ros2_B.updateFval) {
        solution->fstar = c6_formatio_computeFval_ReuseHx(objective,
          memspace->workspace_double, f, solution->xstar);
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formati_PresolveWorkingSet_p
  (sCXYlwCFvxAmgJ1M2ooVQBD_c6_fo_T *solution, sivq9bjImOLkQfehLigQhXG_c6_fo_T
   *memspace, sIqAUiO7iN3zlnKzlJ0LdOE_c6_fo_T *workingset,
   s2v85VDFdoXWosLJGoY94IG_c6_fo_T *qrmanager)
{
  boolean_T exitg1;
  boolean_T guard1;
  solution->state = 82;
  c6_formation_ros2_B.mWorkingFixed = workingset->nWConstr[0];
  c6_formation_ros2_B.mTotalWorkingEq_tmp_tmp = workingset->nWConstr[0] +
    workingset->nWConstr[1];
  c6_formation_ros2_B.idxStartIneq_o = 0;
  if (c6_formation_ros2_B.mTotalWorkingEq_tmp_tmp > 0) {
    c6_formation_ros2_B.c_tmp_tmp = static_cast<uint8_T>(workingset->nVar);
    for (c6_formation_ros2_B.idxStartIneq_o = 0;
         c6_formation_ros2_B.idxStartIneq_o <
         c6_formation_ros2_B.mTotalWorkingEq_tmp_tmp;
         c6_formation_ros2_B.idxStartIneq_o++) {
      for (c6_formation_ros2_B.totalRank = 0; c6_formation_ros2_B.totalRank <
           c6_formation_ros2_B.c_tmp_tmp; c6_formation_ros2_B.totalRank++) {
        qrmanager->QR[c6_formation_ros2_B.idxStartIneq_o + 13 *
          c6_formation_ros2_B.totalRank] = workingset->ATwset[13 *
          c6_formation_ros2_B.idxStartIneq_o + c6_formation_ros2_B.totalRank];
      }
    }

    c6_formation_ros2_B.idxStartIneq_o =
      c6_formation_ros2_B.mTotalWorkingEq_tmp_tmp - workingset->nVar;
    if (c6_formation_ros2_B.idxStartIneq_o <= 0) {
      c6_formation_ros2_B.idxStartIneq_o = 0;
    }

    memset(&qrmanager->jpvt[0], 0, static_cast<uint32_T>
           (c6_formation_ros2_B.c_tmp_tmp) * sizeof(int32_T));
    c6_formation_ros2_factorQRE(qrmanager,
      c6_formation_ros2_B.mTotalWorkingEq_tmp_tmp, workingset->nVar);
    c6_formation_ros2_B.tol = 100.0 * static_cast<real_T>(workingset->nVar) *
      2.2204460492503131E-16;
    if (workingset->nVar <= c6_formation_ros2_B.mTotalWorkingEq_tmp_tmp) {
      c6_formation_ros2_B.totalRank = workingset->nVar;
    } else {
      c6_formation_ros2_B.totalRank =
        c6_formation_ros2_B.mTotalWorkingEq_tmp_tmp;
    }

    c6_formation_ros2_B.totalRank += (c6_formation_ros2_B.totalRank - 1) * 13;
    while ((c6_formation_ros2_B.totalRank > 0) && (fabs(qrmanager->
             QR[c6_formation_ros2_B.totalRank - 1]) < c6_formation_ros2_B.tol))
    {
      c6_formation_ros2_B.totalRank -= 14;
      c6_formation_ros2_B.idxStartIneq_o++;
    }

    if (c6_formation_ros2_B.idxStartIneq_o > 0) {
      c6_formation_ros2_computeQ_(qrmanager, qrmanager->mrows);
      c6_formation_ros2_B.d = 0;
      exitg1 = false;
      while ((!exitg1) && (c6_formation_ros2_B.d <=
                           c6_formation_ros2_B.idxStartIneq_o - 1)) {
        c6_formation_ros2_B.ix = ((c6_formation_ros2_B.mTotalWorkingEq_tmp_tmp -
          c6_formation_ros2_B.d) - 1) * 13;
        c6_formation_ros2_B.qtb = 0.0;
        for (c6_formation_ros2_B.totalRank = 0; c6_formation_ros2_B.totalRank <
             c6_formation_ros2_B.mTotalWorkingEq_tmp_tmp;
             c6_formation_ros2_B.totalRank++) {
          c6_formation_ros2_B.qtb += qrmanager->Q[c6_formation_ros2_B.ix +
            c6_formation_ros2_B.totalRank] * workingset->
            bwset[c6_formation_ros2_B.totalRank];
        }

        if (fabs(c6_formation_ros2_B.qtb) >= c6_formation_ros2_B.tol) {
          c6_formation_ros2_B.idxStartIneq_o = -1;
          exitg1 = true;
        } else {
          c6_formation_ros2_B.d++;
        }
      }
    }

    if (c6_formation_ros2_B.idxStartIneq_o > 0) {
      for (c6_formation_ros2_B.totalRank = 0; c6_formation_ros2_B.totalRank <
           c6_formation_ros2_B.mTotalWorkingEq_tmp_tmp;
           c6_formation_ros2_B.totalRank++) {
        c6_formation_ros2_B.ix = 13 * c6_formation_ros2_B.totalRank;
        memcpy(&qrmanager->QR[c6_formation_ros2_B.ix], &workingset->
               ATwset[c6_formation_ros2_B.ix], static_cast<uint32_T>
               ((c6_formation_ros2_B.c_tmp_tmp + c6_formation_ros2_B.ix) -
                c6_formation_ros2_B.ix) * sizeof(real_T));
      }

      for (c6_formation_ros2_B.totalRank = 0; c6_formation_ros2_B.totalRank <
           c6_formation_ros2_B.mWorkingFixed; c6_formation_ros2_B.totalRank++) {
        qrmanager->jpvt[c6_formation_ros2_B.totalRank] = 1;
      }

      c6_formation_ros2_B.totalRank = workingset->nWConstr[0] + 1;
      if (c6_formation_ros2_B.totalRank <=
          c6_formation_ros2_B.mTotalWorkingEq_tmp_tmp) {
        memset(&qrmanager->jpvt[c6_formation_ros2_B.totalRank + -1], 0,
               static_cast<uint32_T>
               ((c6_formation_ros2_B.mTotalWorkingEq_tmp_tmp -
                 c6_formation_ros2_B.totalRank) + 1) * sizeof(int32_T));
      }

      c6_formation_ros2_factorQRE(qrmanager, workingset->nVar,
        c6_formation_ros2_B.mTotalWorkingEq_tmp_tmp);
      for (c6_formation_ros2_B.mWorkingFixed = 0;
           c6_formation_ros2_B.mWorkingFixed <
           c6_formation_ros2_B.idxStartIneq_o; c6_formation_ros2_B.mWorkingFixed
           ++) {
        memspace->workspace_int[c6_formation_ros2_B.mWorkingFixed] =
          qrmanager->jpvt[(c6_formation_ros2_B.mTotalWorkingEq_tmp_tmp -
                           c6_formation_ros2_B.idxStartIneq_o) +
          c6_formation_ros2_B.mWorkingFixed];
      }

      c6_formation_ros2_countsort(memspace->workspace_int,
        c6_formation_ros2_B.idxStartIneq_o, memspace->workspace_sort, 1,
        c6_formation_ros2_B.mTotalWorkingEq_tmp_tmp);
      for (c6_formation_ros2_B.totalRank = c6_formation_ros2_B.idxStartIneq_o;
           c6_formation_ros2_B.totalRank >= 1; c6_formation_ros2_B.totalRank--)
      {
        c6_formation_ros_removeEqConstr(workingset, memspace->
          workspace_int[c6_formation_ros2_B.totalRank - 1]);
      }
    }
  }

  if ((c6_formation_ros2_B.idxStartIneq_o != -1) && (workingset->nActiveConstr <=
       13)) {
    c6_formati_RemoveDependentIneq_(workingset, qrmanager, memspace, 100.0);
    c6_formation_ros2_B.okWorkingSet = c6_form_feasibleX0ForWorkingSet
      (memspace->workspace_double, solution->xstar, workingset, qrmanager);
    guard1 = false;
    if (!c6_formation_ros2_B.okWorkingSet) {
      c6_formati_RemoveDependentIneq_(workingset, qrmanager, memspace, 1000.0);
      c6_formation_ros2_B.okWorkingSet = c6_form_feasibleX0ForWorkingSet
        (memspace->workspace_double, solution->xstar, workingset, qrmanager);
      if (!c6_formation_ros2_B.okWorkingSet) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (workingset->nWConstr[0] + workingset->nWConstr[1] == workingset->nVar)
      {
        c6_formation_ros2_B.tol = c6_for_maxConstraintViolation_n(workingset,
          solution->xstar);
        if (c6_formation_ros2_B.tol > 1.0E-8) {
          solution->state = -2;
        }
      }
    }
  } else {
    solution->state = -3;
    c6_formation_ros2_B.idxStartIneq_o = (workingset->nWConstr[0] +
      workingset->nWConstr[1]) + 1;
    c6_formation_ros2_B.mWorkingFixed = workingset->nActiveConstr;
    for (c6_formation_ros2_B.totalRank = c6_formation_ros2_B.idxStartIneq_o;
         c6_formation_ros2_B.totalRank <= c6_formation_ros2_B.mWorkingFixed;
         c6_formation_ros2_B.totalRank++) {
      workingset->isActiveConstr[(workingset->isActiveIdx[workingset->
        Wid[c6_formation_ros2_B.totalRank - 1] - 1] + workingset->
        Wlocalidx[c6_formation_ros2_B.totalRank - 1]) - 2] = false;
    }

    workingset->nWConstr[2] = 0;
    workingset->nWConstr[3] = 0;
    workingset->nWConstr[4] = 0;
    workingset->nActiveConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  }
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formati_computeFirstOrderOpt
  (sCXYlwCFvxAmgJ1M2ooVQBD_c6_fo_T *solution, const
   sEFBi4FIsxLUzGhYLLdGc4E_c6_fo_T *objective, int32_T workingset_nVar, const
   real_T workingset_ATwset[832], int32_T workingset_nActiveConstr, real_T
   workspace[832])
{
  real_T smax;
  int32_T idxmax;
  memcpy(&workspace[0], &objective->grad[0], static_cast<uint8_T>
         (workingset_nVar) * sizeof(real_T));
  if (workingset_nActiveConstr != 0) {
    int32_T c;
    int32_T ix;
    ix = 0;
    c = (workingset_nActiveConstr - 1) * 13 + 1;
    for (int32_T k = 1; k <= c; k += 13) {
      int32_T d;
      d = (k + workingset_nVar) - 1;
      for (idxmax = k; idxmax <= d; idxmax++) {
        int32_T tmp;
        tmp = idxmax - k;
        workspace[tmp] += workingset_ATwset[idxmax - 1] * solution->lambda[ix];
      }

      ix++;
    }
  }

  idxmax = 1;
  smax = fabs(workspace[0]);
  for (int32_T k = 2; k <= workingset_nVar; k++) {
    real_T s;
    s = fabs(workspace[k - 1]);
    if (s > smax) {
      idxmax = k;
      smax = s;
    }
  }

  solution->firstorderopt = fabs(workspace[idxmax - 1]);
}

// Function for MATLAB Function: '<S3>/uni_barrier_cert'
void c6_formation_ros2::c6_formation_ros2_driver(const real_T f[12],
  sCXYlwCFvxAmgJ1M2ooVQBD_c6_fo_T *solution, sivq9bjImOLkQfehLigQhXG_c6_fo_T
  *memspace, sIqAUiO7iN3zlnKzlJ0LdOE_c6_fo_T *workingset,
  snmmli8onVqbxLRLhWo5w6G_c6_fo_T *cholmanager, int32_T
  runTimeOptions_MaxIterations, real_T runTimeOptions_ConstrRelTolFact, real_T
  runTimeOptions_ProbRelTolFactor, s2v85VDFdoXWosLJGoY94IG_c6_fo_T *qrmanager,
  sEFBi4FIsxLUzGhYLLdGc4E_c6_fo_T *objective)
{
  static const char_T j_SolverName[8] = { 'q', 'u', 'a', 'd', 'p', 'r', 'o', 'g'
  };

  static const char_T l[128] = { '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\a', '\b', '\t', '\n', '\v', '\f', '\r', '\x0e', '\x0f', '\x10',
    '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19',
    '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!', '\"', '#', '$',
    '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'a', 'b',
    'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
    'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']', '^', '_', '`',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~',
    '\x7f' };

  int32_T exitg2;
  boolean_T exitg1;
  boolean_T guard1;
  memset(&objective->grad[0], 0, 13U * sizeof(real_T));
  memset(&objective->Hx[0], 0, 12U * sizeof(real_T));
  objective->hasLinear = true;
  objective->nvar = 12;
  objective->maxVar = 13;
  objective->beta = 0.0;
  objective->rho = 0.0;
  objective->objtype = 3;
  objective->prev_objtype = 3;
  objective->prev_nvar = 0;
  objective->prev_hasLinear = false;
  objective->gammaScalar = 0.0;
  solution->iterations = 0;
  c6_formation_ros2_B.b_mConstr_tmp = workingset->nVar;
  c6_formation_ros2_B.idxStartIneq = static_cast<uint8_T>(workingset->sizes[0]);
  for (c6_formation_ros2_B.i_j = 0; c6_formation_ros2_B.i_j <
       c6_formation_ros2_B.idxStartIneq; c6_formation_ros2_B.i_j++) {
    solution->xstar[workingset->indexFixed[c6_formation_ros2_B.i_j] - 1] =
      workingset->ub[workingset->indexFixed[c6_formation_ros2_B.i_j] - 1];
  }

  c6_formation_ros2_B.idxStartIneq = static_cast<uint8_T>(workingset->sizes[3]);
  for (c6_formation_ros2_B.i_j = 0; c6_formation_ros2_B.i_j <
       c6_formation_ros2_B.idxStartIneq; c6_formation_ros2_B.i_j++) {
    if (workingset->isActiveConstr[(workingset->isActiveIdx[3] +
         c6_formation_ros2_B.i_j) - 1]) {
      solution->xstar[workingset->indexLB[c6_formation_ros2_B.i_j] - 1] =
        -workingset->lb[workingset->indexLB[c6_formation_ros2_B.i_j] - 1];
    }
  }

  c6_formation_ros2_B.idxStartIneq = static_cast<uint8_T>(workingset->sizes[4]);
  for (c6_formation_ros2_B.i_j = 0; c6_formation_ros2_B.i_j <
       c6_formation_ros2_B.idxStartIneq; c6_formation_ros2_B.i_j++) {
    if (workingset->isActiveConstr[(workingset->isActiveIdx[4] +
         c6_formation_ros2_B.i_j) - 1]) {
      solution->xstar[workingset->indexUB[c6_formation_ros2_B.i_j] - 1] =
        workingset->ub[workingset->indexUB[c6_formation_ros2_B.i_j] - 1];
    }
  }

  c6_formation_PresolveWorkingSet(solution, memspace, workingset, qrmanager);
  for (c6_formation_ros2_B.i_j = 0; c6_formation_ros2_B.i_j < 8;
       c6_formation_ros2_B.i_j++) {
    c6_formation_ros2_B.options.SolverName[c6_formation_ros2_B.i_j] =
      j_SolverName[c6_formation_ros2_B.i_j];
  }

  if (solution->state >= 0) {
    solution->iterations = 0;
    solution->maxConstr = c6_for_maxConstraintViolation_n(workingset,
      solution->xstar);
    guard1 = false;
    if (solution->maxConstr > 1.0E-8 * runTimeOptions_ConstrRelTolFact) {
      solution->xstar[12] = solution->maxConstr + 1.0;
      c6_formation_ros2_B.b_workingset = *workingset;
      c6_formation_ros_setProblemType(&c6_formation_ros2_B.b_workingset, 1);
      c6_formation_ros2_B.idxStartIneq =
        (c6_formation_ros2_B.b_workingset.nWConstr[0] +
         c6_formation_ros2_B.b_workingset.nWConstr[1]) + 1;
      c6_formation_ros2_B.idxEndIneq =
        c6_formation_ros2_B.b_workingset.nActiveConstr;
      for (c6_formation_ros2_B.i_j = c6_formation_ros2_B.idxStartIneq;
           c6_formation_ros2_B.i_j <= c6_formation_ros2_B.idxEndIneq;
           c6_formation_ros2_B.i_j++) {
        c6_formation_ros2_B.b_workingset.isActiveConstr
          [(c6_formation_ros2_B.b_workingset.isActiveIdx[c6_formation_ros2_B.b_workingset.Wid
            [c6_formation_ros2_B.i_j - 1] - 1] +
            c6_formation_ros2_B.b_workingset.Wlocalidx[c6_formation_ros2_B.i_j -
            1]) - 2] = false;
      }

      c6_formation_ros2_B.b_workingset.nWConstr[2] = 0;
      c6_formation_ros2_B.b_workingset.nWConstr[3] = 0;
      c6_formation_ros2_B.b_workingset.nWConstr[4] = 0;
      c6_formation_ros2_B.b_workingset.nActiveConstr =
        c6_formation_ros2_B.b_workingset.nWConstr[0] +
        c6_formation_ros2_B.b_workingset.nWConstr[1];
      objective->prev_objtype = 3;
      objective->prev_nvar = 12;
      objective->prev_hasLinear = true;
      objective->objtype = 5;
      objective->nvar = 13;
      objective->gammaScalar = 1.0;
      objective->hasLinear = true;
      solution->fstar = c6_formation_ros2_computeFval(objective,
        memspace->workspace_double, f, solution->xstar);
      solution->state = 5;
      c6_formation_ros2_iterate(f, solution, memspace,
        &c6_formation_ros2_B.b_workingset, qrmanager, cholmanager, objective,
        1.0E-8 * runTimeOptions_ConstrRelTolFact, 1.4901161193847657E-10,
        runTimeOptions_MaxIterations, runTimeOptions_ConstrRelTolFact,
        runTimeOptions_ProbRelTolFactor, true);
      if (c6_formation_ros2_B.b_workingset.isActiveConstr
          [(c6_formation_ros2_B.b_workingset.isActiveIdx[3] +
            c6_formation_ros2_B.b_workingset.sizes[3]) - 2]) {
        c6_formation_ros2_B.i_j = c6_formation_ros2_B.b_workingset.sizes[0];
        exitg1 = false;
        while ((!exitg1) && (c6_formation_ros2_B.i_j + 1 <=
                             c6_formation_ros2_B.b_workingset.nActiveConstr)) {
          if ((c6_formation_ros2_B.b_workingset.Wid[c6_formation_ros2_B.i_j] ==
               4) &&
              (c6_formation_ros2_B.b_workingset.Wlocalidx[c6_formation_ros2_B.i_j]
               == c6_formation_ros2_B.b_workingset.sizes[3])) {
            c6_formation_ros2_removeConstr(&c6_formation_ros2_B.b_workingset,
              c6_formation_ros2_B.i_j + 1);
            exitg1 = true;
          } else {
            c6_formation_ros2_B.i_j++;
          }
        }
      }

      c6_formation_ros2_B.i_j = c6_formation_ros2_B.b_workingset.nActiveConstr;
      while ((c6_formation_ros2_B.i_j > c6_formation_ros2_B.b_workingset.sizes[0])
             && (c6_formation_ros2_B.i_j > workingset->nVar)) {
        c6_formation_ros2_removeConstr(&c6_formation_ros2_B.b_workingset,
          c6_formation_ros2_B.i_j);
        c6_formation_ros2_B.i_j--;
      }

      solution->maxConstr = solution->xstar[12];
      c6_formation_ros_setProblemType(&c6_formation_ros2_B.b_workingset, 3);
      objective->objtype = objective->prev_objtype;
      objective->nvar = objective->prev_nvar;
      objective->hasLinear = objective->prev_hasLinear;
      *workingset = c6_formation_ros2_B.b_workingset;
      if (solution->state == 0) {
      } else {
        solution->maxConstr = c6_for_maxConstraintViolation_n
          (&c6_formation_ros2_B.b_workingset, solution->xstar);
        *workingset = c6_formation_ros2_B.b_workingset;
        if (solution->maxConstr > 1.0E-8 * runTimeOptions_ConstrRelTolFact) {
          memset(&solution->lambda[0], 0, sizeof(real_T) << 6U);
          solution->fstar = c6_formation_ros2_computeFval(objective,
            memspace->workspace_double, f, solution->xstar);
          solution->state = -2;
        } else {
          if (solution->maxConstr > 0.0) {
            c6_formation_ros2_B.i_j = static_cast<uint8_T>
              (c6_formation_ros2_B.b_mConstr_tmp);
            if (c6_formation_ros2_B.i_j - 1 >= 0) {
              memcpy(&solution->searchDir[0], &solution->xstar[0],
                     static_cast<uint32_T>(c6_formation_ros2_B.i_j) * sizeof
                     (real_T));
            }

            c6_formati_PresolveWorkingSet_p(solution, memspace,
              &c6_formation_ros2_B.b_workingset, qrmanager);
            *workingset = c6_formation_ros2_B.b_workingset;
            c6_formation_ros2_B.maxConstr_new = c6_for_maxConstraintViolation_n
              (workingset, solution->xstar);
            if (c6_formation_ros2_B.maxConstr_new >= solution->maxConstr) {
              solution->maxConstr = c6_formation_ros2_B.maxConstr_new;
              if (c6_formation_ros2_B.i_j - 1 >= 0) {
                memcpy(&solution->xstar[0], &solution->searchDir[0],
                       static_cast<uint32_T>(c6_formation_ros2_B.i_j) * sizeof
                       (real_T));
              }
            }
          }

          guard1 = true;
        }
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      c6_formation_ros2_iterate(f, solution, memspace, workingset, qrmanager,
        cholmanager, objective, -1.0E+20, 1.0E-8, runTimeOptions_MaxIterations,
        runTimeOptions_ConstrRelTolFact, runTimeOptions_ProbRelTolFactor, true);
      c6_formation_ros2_B.b_bool = false;
      c6_formation_ros2_B.i_j = 0;
      do {
        exitg2 = 0;
        if (c6_formation_ros2_B.i_j < 8) {
          if (l[static_cast<int32_T>
              (c6_formation_ros2_B.options.SolverName[c6_formation_ros2_B.i_j])]
              != l[static_cast<int32_T>(j_SolverName[c6_formation_ros2_B.i_j])])
          {
            exitg2 = 1;
          } else {
            c6_formation_ros2_B.i_j++;
          }
        } else {
          c6_formation_ros2_B.b_bool = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);

      if (c6_formation_ros2_B.b_bool && (solution->state != -6)) {
        solution->maxConstr = c6_for_maxConstraintViolation_n(workingset,
          solution->xstar);
        c6_formati_computeFirstOrderOpt(solution, objective, workingset->nVar,
          workingset->ATwset, workingset->nActiveConstr,
          memspace->workspace_double);
        while ((solution->iterations < runTimeOptions_MaxIterations) &&
               ((solution->state == -7) || ((solution->state == 1) &&
                 ((solution->maxConstr > 1.0E-8 *
                   runTimeOptions_ConstrRelTolFact) || (solution->firstorderopt >
                   1.0E-8 * runTimeOptions_ProbRelTolFactor))))) {
          c6_form_feasibleX0ForWorkingSet(memspace->workspace_double,
            solution->xstar, workingset, qrmanager);
          c6_formati_PresolveWorkingSet_p(solution, memspace, workingset,
            qrmanager);
          c6_formation_ros2_B.idxStartIneq = workingset->probType;
          c6_formation_ros2_B.b_mConstr_tmp = workingset->nVar;
          solution->xstar[12] = solution->maxConstr + 1.0;
          if (workingset->probType == 3) {
            c6_formation_ros2_B.i_j = 1;
          } else {
            c6_formation_ros2_B.i_j = 4;
          }

          c6_formation_ros_setProblemType(workingset, c6_formation_ros2_B.i_j);
          c6_formation_ros2_B.idxEndIneq = workingset->nWConstr[0] +
            workingset->nWConstr[1];
          c6_formation_ros2_B.b_idxStartIneq = c6_formation_ros2_B.idxEndIneq +
            1;
          c6_formation_ros2_B.b_idxEndIneq = workingset->nActiveConstr;
          for (c6_formation_ros2_B.i_j = c6_formation_ros2_B.b_idxStartIneq;
               c6_formation_ros2_B.i_j <= c6_formation_ros2_B.b_idxEndIneq;
               c6_formation_ros2_B.i_j++) {
            workingset->isActiveConstr[(workingset->isActiveIdx[workingset->
              Wid[c6_formation_ros2_B.i_j - 1] - 1] + workingset->
              Wlocalidx[c6_formation_ros2_B.i_j - 1]) - 2] = false;
          }

          workingset->nWConstr[2] = 0;
          workingset->nWConstr[3] = 0;
          workingset->nWConstr[4] = 0;
          workingset->nActiveConstr = c6_formation_ros2_B.idxEndIneq;
          objective->prev_objtype = objective->objtype;
          objective->prev_nvar = objective->nvar;
          objective->prev_hasLinear = objective->hasLinear;
          objective->objtype = 5;
          objective->nvar = 13;
          objective->gammaScalar = 1.0;
          objective->hasLinear = true;
          solution->fstar = c6_formation_ros2_computeFval(objective,
            memspace->workspace_double, f, solution->xstar);
          solution->state = 5;
          c6_formation_ros2_iterate(f, solution, memspace, workingset, qrmanager,
            cholmanager, objective, 1.0E-8 * runTimeOptions_ConstrRelTolFact,
            1.4901161193847657E-10, runTimeOptions_MaxIterations,
            runTimeOptions_ConstrRelTolFact, runTimeOptions_ProbRelTolFactor,
            false);
          if (workingset->isActiveConstr[(workingset->isActiveIdx[3] +
               workingset->sizes[3]) - 2]) {
            c6_formation_ros2_B.i_j = workingset->sizes[0];
            exitg1 = false;
            while ((!exitg1) && (c6_formation_ros2_B.i_j + 1 <=
                                 workingset->nActiveConstr)) {
              if ((workingset->Wid[c6_formation_ros2_B.i_j] == 4) &&
                  (workingset->Wlocalidx[c6_formation_ros2_B.i_j] ==
                   workingset->sizes[3])) {
                c6_formation_ros2_removeConstr(workingset,
                  c6_formation_ros2_B.i_j + 1);
                exitg1 = true;
              } else {
                c6_formation_ros2_B.i_j++;
              }
            }
          }

          c6_formation_ros2_B.i_j = workingset->nActiveConstr;
          while ((c6_formation_ros2_B.i_j > workingset->sizes[0]) &&
                 (c6_formation_ros2_B.i_j > c6_formation_ros2_B.b_mConstr_tmp))
          {
            c6_formation_ros2_removeConstr(workingset, c6_formation_ros2_B.i_j);
            c6_formation_ros2_B.i_j--;
          }

          solution->maxConstr = solution->xstar[12];
          c6_formation_ros_setProblemType(workingset,
            c6_formation_ros2_B.idxStartIneq);
          objective->objtype = objective->prev_objtype;
          objective->nvar = objective->prev_nvar;
          objective->hasLinear = objective->prev_hasLinear;
          c6_formation_ros2_iterate(f, solution, memspace, workingset, qrmanager,
            cholmanager, objective, -1.0E+20, 1.0E-8,
            runTimeOptions_MaxIterations, runTimeOptions_ConstrRelTolFact,
            runTimeOptions_ProbRelTolFactor, false);
          solution->maxConstr = c6_for_maxConstraintViolation_n(workingset,
            solution->xstar);
          c6_formati_computeFirstOrderOpt(solution, objective, workingset->nVar,
            workingset->ATwset, workingset->nActiveConstr,
            memspace->workspace_double);
        }
      }
    }
  }
}

void c6_formation_ros2::c6_formation_r_SystemCore_setup
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[14];
  static const char_T tmp[13] = { '/', 'r', 'o', 'b', 'o', 't', '_', '1', '/',
    'p', 'o', 's', 'e' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 13; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[13] = '\x00';
  Sub_c6_formation_ros2_16753.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void c6_formation_ros2::c6_formation_SystemCore_setup_a
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[14];
  static const char_T tmp[13] = { '/', 'r', 'o', 'b', 'o', 't', '_', '1', '/',
    'c', 'o', 'm', 'm' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 13; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[13] = '\x00';
  Sub_c6_formation_ros2_16754.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void c6_formation_ros2::c6_formatio_SystemCore_setup_aa
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[14];
  static const char_T tmp[13] = { '/', 'r', 'o', 'b', 'o', 't', '_', '2', '/',
    'p', 'o', 's', 'e' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 13; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[13] = '\x00';
  Sub_c6_formation_ros2_16981.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void c6_formation_ros2::c6_formati_SystemCore_setup_aao
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[14];
  static const char_T tmp[13] = { '/', 'r', 'o', 'b', 'o', 't', '_', '2', '/',
    'c', 'o', 'm', 'm' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 13; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[13] = '\x00';
  Sub_c6_formation_ros2_16982.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void c6_formation_ros2::c6_format_SystemCore_setup_aaoo
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[14];
  static const char_T tmp[13] = { '/', 'r', 'o', 'b', 'o', 't', '_', '3', '/',
    'p', 'o', 's', 'e' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 13; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[13] = '\x00';
  Sub_c6_formation_ros2_17026.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void c6_formation_ros2::c6_forma_SystemCore_setup_aaoow
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[14];
  static const char_T tmp[13] = { '/', 'r', 'o', 'b', 'o', 't', '_', '3', '/',
    'c', 'o', 'm', 'm' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 13; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[13] = '\x00';
  Sub_c6_formation_ros2_17027.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void c6_formation_ros2::c6_form_SystemCore_setup_aaoowe
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[14];
  static const char_T tmp[13] = { '/', 'r', 'o', 'b', 'o', 't', '_', '4', '/',
    'p', 'o', 's', 'e' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 13; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[13] = '\x00';
  Sub_c6_formation_ros2_17071.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void c6_formation_ros2::c6_for_SystemCore_setup_aaoowep
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[14];
  static const char_T tmp[13] = { '/', 'r', 'o', 'b', 'o', 't', '_', '4', '/',
    'c', 'o', 'm', 'm' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 13; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[13] = '\x00';
  Sub_c6_formation_ros2_17072.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void c6_formation_ros2::c6_fo_SystemCore_setup_aaoowepy
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[14];
  static const char_T tmp[13] = { '/', 'r', 'o', 'b', 'o', 't', '_', '5', '/',
    'p', 'o', 's', 'e' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 13; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[13] = '\x00';
  Sub_c6_formation_ros2_17116.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void c6_formation_ros2::c6_f_SystemCore_setup_aaoowepyy
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[14];
  static const char_T tmp[13] = { '/', 'r', 'o', 'b', 'o', 't', '_', '5', '/',
    'c', 'o', 'm', 'm' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 13; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[13] = '\x00';
  Sub_c6_formation_ros2_17117.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void c6_formation_ros2::c6__SystemCore_setup_aaoowepyyp
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[14];
  static const char_T tmp[13] = { '/', 'r', 'o', 'b', 'o', 't', '_', '6', '/',
    'p', 'o', 's', 'e' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 13; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[13] = '\x00';
  Sub_c6_formation_ros2_17161.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void c6_formation_ros2::c6_SystemCore_setup_aaoowepyypb
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[14];
  static const char_T tmp[13] = { '/', 'r', 'o', 'b', 'o', 't', '_', '6', '/',
    'c', 'o', 'm', 'm' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 13; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[13] = '\x00';
  Sub_c6_formation_ros2_17162.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void c6_formation_ros2::c_SystemCore_setup_aaoowepyypbp
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[17];
  static const char_T tmp[16] = { '/', 'r', 'o', 'b', 'o', 't', '_', '1', '/',
    'c', 'm', 'd', '_', 'v', 'e', 'l' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 16; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[16] = '\x00';
  Pub_c6_formation_ros2_16722.createPublisher(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void c6_formation_ros2::SystemCore_setup_aaoowepyypbpz
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[17];
  static const char_T tmp[16] = { '/', 'r', 'o', 'b', 'o', 't', '_', '2', '/',
    'c', 'm', 'd', '_', 'v', 'e', 'l' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 16; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[16] = '\x00';
  Pub_c6_formation_ros2_16728.createPublisher(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void c6_formation_ros2::SystemCore_setup_aaoowepyypbpz2
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[17];
  static const char_T tmp[16] = { '/', 'r', 'o', 'b', 'o', 't', '_', '3', '/',
    'c', 'm', 'd', '_', 'v', 'e', 'l' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 16; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[16] = '\x00';
  Pub_c6_formation_ros2_16734.createPublisher(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void c6_formation_ros2::SystemCore_setu_aaoowepyypbpz2d
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[17];
  static const char_T tmp[16] = { '/', 'r', 'o', 'b', 'o', 't', '_', '4', '/',
    'c', 'm', 'd', '_', 'v', 'e', 'l' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 16; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[16] = '\x00';
  Pub_c6_formation_ros2_16740.createPublisher(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void c6_formation_ros2::c6_formation_SystemCore_setup_j
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[17];
  static const char_T tmp[16] = { '/', 'r', 'o', 'b', 'o', 't', '_', '5', '/',
    'c', 'm', 'd', '_', 'v', 'e', 'l' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 16; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[16] = '\x00';
  Pub_c6_formation_ros2_16746.createPublisher(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void c6_formation_ros2::c6_formation_SystemCore_setup_p
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[17];
  static const char_T tmp[16] = { '/', 'r', 'o', 'b', 'o', 't', '_', '6', '/',
    'c', 'm', 'd', '_', 'v', 'e', 'l' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 16; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[16] = '\x00';
  Pub_c6_formation_ros2_16752.createPublisher(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

// Model step function
void c6_formation_ros2::step()
{
  __m128d tmp;
  __m128d tmp_0;
  __m128d tmp_1;
  static const real_T wpSanKai[18] = { 1.0, 0.6, 1.4, 0.2, 1.0, 1.8, 1.8, 1.8,
    1.8, 1.8, 1.4, 1.8, 1.5707963267948966, 1.5707963267948966,
    1.5707963267948966, 1.5707963267948966, 1.5707963267948966,
    1.5707963267948966 };

  static const real_T ab[18] = { 1.0, 0.85, 1.15, 0.7, 1.0, 1.3, 1.3, 1.0, 1.0,
    0.7, 0.7, 0.7, 1.5707963267948966, 1.5707963267948966, 1.5707963267948966,
    1.5707963267948966, 1.5707963267948966, 1.5707963267948966 };

  static const real_T wplieDui[18] = { 1.8, 1.4, 1.0, 0.6, 0.2, 0.2, 0.2, 0.2,
    0.2, 0.2, 0.2, 0.6, 0.0, -1.5707963267948966, -1.5707963267948966,
    -1.5707963267948966, -1.5707963267948966, -1.5707963267948966 };

  static const real_T bb[18] = { 1.4, 1.2, 1.0, 1.0, 0.8, 0.6, 1.4, 1.0, 0.6,
    1.4, 1.0, 0.6, 1.5707963267948966, 1.5707963267948966, 1.5707963267948966,
    -1.5707963267948966, -1.5707963267948966, -1.5707963267948966 };

  static const real_T cb[18] = { 0.2, 1.0, 1.8, 0.2, 1.0, 1.8, 1.8, 1.8, 1.8,
    0.2, 0.2, 0.2, 3.1415926535897931, 3.1415926535897931, 3.1415926535897931,
    0.0, 0.0, 0.0 };

  static const real_T db[18] = { 0.6, 0.8, 1.0, 1.0, 1.2, 1.4, 0.6, 1.0, 1.4,
    0.6, 1.0, 1.4, -1.5707963267948966, -1.5707963267948966, -1.5707963267948966,
    1.5707963267948966, 1.5707963267948966, 1.5707963267948966 };

  static const real_T eb[18] = { 1.8, 1.0, 0.2, 1.8, 1.0, 0.2, 0.2, 0.2, 0.2,
    1.8, 1.8, 1.8, 0.0, 0.0, 0.0, -3.1415926535897931, -3.1415926535897931,
    -3.1415926535897931 };

  static const real_T wpFengChao[18] = { 1.0, 0.85, 1.15, 0.7, 1.0, 1.3, 1.3,
    1.0, 1.0, 0.7, 0.7, 0.7, 1.5707963267948966, 3.1415926535897931, 0.0,
    1.5707963267948966, 1.5707963267948966, 1.5707963267948966 };

  static const real_T wpCircle[36] = { 1.8, 1.6928203230275511,
    1.4000000000000001, 1.0, 0.60000000000000009, 0.30717967697244897,
    0.19999999999999996, 0.30717967697244908, 0.59999999999999964,
    0.99999999999999989, 1.4000000000000001, 1.6928203230275507, 1.0, 1.4,
    1.6928203230275509, 1.8, 1.6928203230275511, 1.4, 1.0, 0.59999999999999987,
    0.30717967697244919, 0.19999999999999996, 0.30717967697244908,
    0.59999999999999964, 1.5707963267948966, 2.0943951023931953,
    2.617993877991494, 3.1415926535897931, 3.6651914291880918,
    4.1887902047863914, 4.71238898038469, 5.2359877559829888, 5.7595865315812871,
    6.2831853071795862, 6.8067840827778854, 7.3303828583761836 };

  static const real_T hb[12] = { 1.0, 0.6, 1.4, 0.2, 1.0, 1.8, 1.8, 1.8, 1.8,
    1.8, 1.4, 1.8 };

  static const real_T gb[12] = { 1.8, 1.4, 1.0, 0.6, 0.2, 0.2, 0.2, 0.2, 0.2,
    0.2, 0.2, 0.6 };

  static const real_T ib[15] = { 1.6928203230275507, 1.4000000000000001,
    0.99999999999999989, 0.59999999999999964, 0.30717967697244908,
    0.59999999999999964, 0.30717967697244908, 0.19999999999999996,
    0.30717967697244919, 0.59999999999999987, 7.3303828583761836,
    6.8067840827778854, 6.2831853071795862, 5.7595865315812871,
    5.2359877559829888 };

  static const real_T fb[12] = { 1.0, 0.85, 1.15, 0.7, 1.0, 1.3, 1.3, 1.0, 1.0,
    0.7, 0.7, 0.7 };

  static const real_T kb[9] = { 1.6928203230275507, 1.4000000000000001,
    0.99999999999999989, 0.59999999999999964, 0.30717967697244908,
    0.19999999999999996, 7.3303828583761836, 6.8067840827778854,
    6.2831853071795862 };

  static const real_T jb[12] = { 1.6928203230275507, 1.4000000000000001,
    0.99999999999999989, 0.59999999999999964, 0.59999999999999964,
    0.30717967697244908, 0.19999999999999996, 0.30717967697244919,
    7.3303828583761836, 6.8067840827778854, 6.2831853071795862,
    5.7595865315812871 };

  static const real_T lb[6] = { 1.6928203230275507, 1.4000000000000001,
    0.59999999999999964, 0.30717967697244908, 7.3303828583761836,
    6.8067840827778854 };

  static const int8_T H[144] = { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 };

  boolean_T exitg1;
  boolean_T guard1;

  // Outputs for Atomic SubSystem: '<S22>/ReducedQRN'
  c6_formation_ros2_ReducedQRN(c6_formation_ros2_B.M_p, c6_formation_ros2_B.L_ps,
    c6_formation_ros2_B.SNew_j, &c6_formation_ros2_P.ReducedQRN);

  // End of Outputs for SubSystem: '<S22>/ReducedQRN'

  // MATLAB Function: '<S18>/kalmanM' incorporates:
  //   Memory: '<S18>/Memory2'

  c6_formation_ros2_kalmanM(c6_formation_ros2_DW.Memory2_PreviousInput,
    c6_formation_ros2_B.A_b, c6_formation_ros2_B.C, &c6_formation_ros2_P);

  // Delay: '<S22>/MemoryP' incorporates:
  //   Constant: '<S22>/P0'

  if (c6_formation_ros2_DW.icLoad) {
    memcpy(&c6_formation_ros2_DW.MemoryP_DSTATE[0],
           &c6_formation_ros2_P.P0_Value[0], 25U * sizeof(real_T));
  }

  // Outputs for Atomic SubSystem: '<S22>/CalculatePL'
  // Constant: '<S22>/Enable' incorporates:
  //   Delay: '<S22>/MemoryP'

  c6_formation_ros2_CalculatePL(c6_formation_ros2_B.A_b, c6_formation_ros2_B.C,
    c6_formation_ros2_B.M_p, c6_formation_ros2_B.L_ps,
    c6_formation_ros2_B.SNew_j, c6_formation_ros2_P.Enable_Value,
    c6_formation_ros2_DW.MemoryP_DSTATE, c6_formation_ros2_B.M,
    c6_formation_ros2_B.L, c6_formation_ros2_B.C_b, c6_formation_ros2_B.SNew,
    &c6_formation_ros2_B.CalculatePL);

  // End of Outputs for SubSystem: '<S22>/CalculatePL'

  // MATLAB Function: '<S70>/SqrtUsedFcn' incorporates:
  //   Constant: '<S70>/isSqrtUsed'

  c6_formation_ros2_SqrtUsedFcn(c6_formation_ros2_B.C_b,
    c6_formation_ros2_P.isSqrtUsed_Value, c6_formation_ros2_B.M_p);

  // Outputs for Atomic SubSystem: '<S83>/ReducedQRN'
  c6_formation_ros2_ReducedQRN(c6_formation_ros2_B.M_g, c6_formation_ros2_B.L_pd,
    c6_formation_ros2_B.SNew_f, &c6_formation_ros2_P.ReducedQRN_b);

  // End of Outputs for SubSystem: '<S83>/ReducedQRN'

  // MATLAB Function: '<S79>/kalmanM' incorporates:
  //   Memory: '<S79>/Memory2'

  c6_formation_ros2_kalmanM(c6_formation_ros2_DW.Memory2_PreviousInput_p,
    c6_formation_ros2_B.A_jk, c6_formation_ros2_B.C_b, &c6_formation_ros2_P);

  // Delay: '<S83>/MemoryP' incorporates:
  //   Constant: '<S83>/P0'

  if (c6_formation_ros2_DW.icLoad_o) {
    memcpy(&c6_formation_ros2_DW.MemoryP_DSTATE_c[0],
           &c6_formation_ros2_P.P0_Value_k[0], 25U * sizeof(real_T));
  }

  // Outputs for Atomic SubSystem: '<S83>/CalculatePL'
  // Constant: '<S83>/Enable' incorporates:
  //   Delay: '<S83>/MemoryP'

  c6_formation_ros2_CalculatePL(c6_formation_ros2_B.A_jk,
    c6_formation_ros2_B.C_b, c6_formation_ros2_B.M_g, c6_formation_ros2_B.L_pd,
    c6_formation_ros2_B.SNew_f, c6_formation_ros2_P.Enable_Value_n,
    c6_formation_ros2_DW.MemoryP_DSTATE_c, c6_formation_ros2_B.M_p,
    c6_formation_ros2_B.L_ps, c6_formation_ros2_B.C_lk,
    c6_formation_ros2_B.SNew_j, &c6_formation_ros2_B.CalculatePL_b);

  // End of Outputs for SubSystem: '<S83>/CalculatePL'

  // MATLAB Function: '<S131>/SqrtUsedFcn' incorporates:
  //   Constant: '<S131>/isSqrtUsed'

  c6_formation_ros2_SqrtUsedFcn(c6_formation_ros2_B.C_lk,
    c6_formation_ros2_P.isSqrtUsed_Value_f, c6_formation_ros2_B.SNew_f);

  // Outputs for Atomic SubSystem: '<S144>/ReducedQRN'
  c6_formation_ros2_ReducedQRN(c6_formation_ros2_B.M_f, c6_formation_ros2_B.L_p,
    c6_formation_ros2_B.SNew_mo, &c6_formation_ros2_P.ReducedQRN_k);

  // End of Outputs for SubSystem: '<S144>/ReducedQRN'

  // MATLAB Function: '<S140>/kalmanM' incorporates:
  //   Memory: '<S140>/Memory2'

  c6_formation_ros2_kalmanM(c6_formation_ros2_DW.Memory2_PreviousInput_d,
    c6_formation_ros2_B.A_j, c6_formation_ros2_B.C_lk, &c6_formation_ros2_P);

  // Delay: '<S144>/MemoryP' incorporates:
  //   Constant: '<S144>/P0'

  if (c6_formation_ros2_DW.icLoad_g) {
    memcpy(&c6_formation_ros2_DW.MemoryP_DSTATE_k[0],
           &c6_formation_ros2_P.P0_Value_b[0], 25U * sizeof(real_T));
  }

  // Outputs for Atomic SubSystem: '<S144>/CalculatePL'
  // Constant: '<S144>/Enable' incorporates:
  //   Delay: '<S144>/MemoryP'

  c6_formation_ros2_CalculatePL(c6_formation_ros2_B.A_j,
    c6_formation_ros2_B.C_lk, c6_formation_ros2_B.M_f, c6_formation_ros2_B.L_p,
    c6_formation_ros2_B.SNew_mo, c6_formation_ros2_P.Enable_Value_l,
    c6_formation_ros2_DW.MemoryP_DSTATE_k, c6_formation_ros2_B.M_g,
    c6_formation_ros2_B.L_pd, c6_formation_ros2_B.C_m,
    c6_formation_ros2_B.SNew_f, &c6_formation_ros2_B.CalculatePL_n);

  // End of Outputs for SubSystem: '<S144>/CalculatePL'

  // MATLAB Function: '<S192>/SqrtUsedFcn' incorporates:
  //   Constant: '<S192>/isSqrtUsed'

  c6_formation_ros2_SqrtUsedFcn(c6_formation_ros2_B.C_m,
    c6_formation_ros2_P.isSqrtUsed_Value_m, c6_formation_ros2_B.SNew_mo);

  // Outputs for Atomic SubSystem: '<S205>/ReducedQRN'
  c6_formation_ros2_ReducedQRN(c6_formation_ros2_B.M_a, c6_formation_ros2_B.L_l,
    c6_formation_ros2_B.SNew_m, &c6_formation_ros2_P.ReducedQRN_h);

  // End of Outputs for SubSystem: '<S205>/ReducedQRN'

  // MATLAB Function: '<S201>/kalmanM' incorporates:
  //   Memory: '<S201>/Memory2'

  c6_formation_ros2_kalmanM(c6_formation_ros2_DW.Memory2_PreviousInput_e,
    c6_formation_ros2_B.A_a, c6_formation_ros2_B.C_m, &c6_formation_ros2_P);

  // Delay: '<S205>/MemoryP' incorporates:
  //   Constant: '<S205>/P0'

  if (c6_formation_ros2_DW.icLoad_a) {
    memcpy(&c6_formation_ros2_DW.MemoryP_DSTATE_i[0],
           &c6_formation_ros2_P.P0_Value_h[0], 25U * sizeof(real_T));
  }

  // Outputs for Atomic SubSystem: '<S205>/CalculatePL'
  // Constant: '<S205>/Enable' incorporates:
  //   Delay: '<S205>/MemoryP'

  c6_formation_ros2_CalculatePL(c6_formation_ros2_B.A_a, c6_formation_ros2_B.C_m,
    c6_formation_ros2_B.M_a, c6_formation_ros2_B.L_l, c6_formation_ros2_B.SNew_m,
    c6_formation_ros2_P.Enable_Value_k, c6_formation_ros2_DW.MemoryP_DSTATE_i,
    c6_formation_ros2_B.M_f, c6_formation_ros2_B.L_p, c6_formation_ros2_B.C_l,
    c6_formation_ros2_B.SNew_mo, &c6_formation_ros2_B.CalculatePL_d);

  // End of Outputs for SubSystem: '<S205>/CalculatePL'

  // MATLAB Function: '<S253>/SqrtUsedFcn' incorporates:
  //   Constant: '<S253>/isSqrtUsed'

  c6_formation_ros2_SqrtUsedFcn(c6_formation_ros2_B.C_l,
    c6_formation_ros2_P.isSqrtUsed_Value_n, c6_formation_ros2_B.SNew_m);

  // Outputs for Atomic SubSystem: '<S266>/ReducedQRN'
  c6_formation_ros2_ReducedQRN(c6_formation_ros2_B.Zs, c6_formation_ros2_B.M_e,
    c6_formation_ros2_B.SNew_c, &c6_formation_ros2_P.ReducedQRN_i);

  // End of Outputs for SubSystem: '<S266>/ReducedQRN'

  // MATLAB Function: '<S262>/kalmanM' incorporates:
  //   Memory: '<S262>/Memory2'

  c6_formation_ros2_kalmanM(c6_formation_ros2_DW.Memory2_PreviousInput_k,
    c6_formation_ros2_B.A, c6_formation_ros2_B.C_l, &c6_formation_ros2_P);

  // Delay: '<S266>/MemoryP' incorporates:
  //   Constant: '<S266>/P0'

  if (c6_formation_ros2_DW.icLoad_d) {
    memcpy(&c6_formation_ros2_DW.MemoryP_DSTATE_n[0],
           &c6_formation_ros2_P.P0_Value_o[0], 25U * sizeof(real_T));
  }

  // Outputs for Atomic SubSystem: '<S266>/CalculatePL'
  // Constant: '<S266>/Enable' incorporates:
  //   Delay: '<S266>/MemoryP'

  c6_formation_ros2_CalculatePL(c6_formation_ros2_B.A, c6_formation_ros2_B.C_l,
    c6_formation_ros2_B.Zs, c6_formation_ros2_B.M_e, c6_formation_ros2_B.SNew_c,
    c6_formation_ros2_P.Enable_Value_ng, c6_formation_ros2_DW.MemoryP_DSTATE_n,
    c6_formation_ros2_B.M_a, c6_formation_ros2_B.L_l, c6_formation_ros2_B.L_a,
    c6_formation_ros2_B.SNew_m, &c6_formation_ros2_B.CalculatePL_k);

  // End of Outputs for SubSystem: '<S266>/CalculatePL'

  // MATLAB Function: '<S314>/SqrtUsedFcn' incorporates:
  //   Constant: '<S314>/isSqrtUsed'

  c6_formation_ros2_SqrtUsedFcn(c6_formation_ros2_B.L_a,
    c6_formation_ros2_P.isSqrtUsed_Value_k, c6_formation_ros2_B.SNew_c);

  // Outputs for Atomic SubSystem: '<S327>/ReducedQRN'
  c6_formation_ros2_ReducedQRN(c6_formation_ros2_B.Qbar_,
    c6_formation_ros2_B.Rbar_, c6_formation_ros2_B.Saturation,
    &c6_formation_ros2_P.ReducedQRN_n);

  // End of Outputs for SubSystem: '<S327>/ReducedQRN'

  // MATLAB Function: '<S323>/kalmanM' incorporates:
  //   Memory: '<S323>/Memory2'

  c6_formation_ros2_kalmanM(c6_formation_ros2_DW.Memory2_PreviousInput_o,
    c6_formation_ros2_B.Akxhatkk1, c6_formation_ros2_B.Bkuk,
    &c6_formation_ros2_P);

  // Delay: '<S327>/MemoryP' incorporates:
  //   Constant: '<S327>/P0'

  if (c6_formation_ros2_DW.icLoad_dm) {
    memcpy(&c6_formation_ros2_DW.MemoryP_DSTATE_b[0],
           &c6_formation_ros2_P.P0_Value_l[0], 25U * sizeof(real_T));
  }

  // Outputs for Atomic SubSystem: '<S327>/CalculatePL'
  // Constant: '<S327>/Enable' incorporates:
  //   Delay: '<S327>/MemoryP'

  c6_formation_ros2_CalculatePL(c6_formation_ros2_B.Akxhatkk1,
    c6_formation_ros2_B.Bkuk, c6_formation_ros2_B.Qbar_,
    c6_formation_ros2_B.Rbar_, c6_formation_ros2_B.Saturation,
    c6_formation_ros2_P.Enable_Value_kj, c6_formation_ros2_DW.MemoryP_DSTATE_b,
    c6_formation_ros2_B.M_e, c6_formation_ros2_B.L_a, c6_formation_ros2_B.Zs,
    c6_formation_ros2_B.SNew_c, &c6_formation_ros2_B.CalculatePL_l);

  // End of Outputs for SubSystem: '<S327>/CalculatePL'

  // MATLAB Function: '<S375>/SqrtUsedFcn' incorporates:
  //   Constant: '<S375>/isSqrtUsed'

  c6_formation_ros2_SqrtUsedFcn(c6_formation_ros2_B.Zs,
    c6_formation_ros2_P.isSqrtUsed_Value_c, c6_formation_ros2_B.Qbar_);

  // Delay: '<S22>/MemoryX' incorporates:
  //   Constant: '<S22>/X0'

  if (c6_formation_ros2_DW.icLoad_k) {
    for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i < 5;
         c6_formation_ros2_B.i++) {
      c6_formation_ros2_DW.MemoryX_DSTATE[c6_formation_ros2_B.i] =
        c6_formation_ros2_P.X0_Value[c6_formation_ros2_B.i];
    }
  }

  // MATLABSystem: '<S16>/SourceBlock'
  c6_formation_ros2_B.b_varargout_1 =
    Sub_c6_formation_ros2_16753.getLatestMessage
    (&c6_formation_ros2_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S16>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S19>/Enable'

  if (c6_formation_ros2_B.b_varargout_1) {
    // SignalConversion generated from: '<S19>/In1'
    c6_formation_ros2_B.In1_pk = c6_formation_ros2_B.b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S16>/Enabled Subsystem'

  // MATLAB Function: '<S18>/sensor2vCar' incorporates:
  //   MATLABSystem: '<S16>/SourceBlock'

  c6_formation_ros2_sensor2vCar(c6_formation_ros2_B.b_varargout_1,
    &c6_formation_ros2_B.In1_pk, &c6_formation_ros2_B.W_o,
    &c6_formation_ros2_B.V_e, &c6_formation_ros2_B.flag_p,
    &c6_formation_ros2_B.flag, &c6_formation_ros2_B.sf_sensor2vCar,
    &c6_formation_ros2_DW.sf_sensor2vCar);

  // DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
  if ((c6_formation_ros2_B.flag <= 0.0) &&
      (c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRese == 1)) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_DSTATE =
      c6_formation_ros2_P.DiscreteTimeIntegrator_IC;
  }

  // Reshape: '<S22>/Reshapey' incorporates:
  //   DiscreteIntegrator: '<S21>/Discrete-Time Integrator'
  //   Sum: '<S18>/Sum'

  c6_formation_ros2_B.Reshapey[0] = c6_formation_ros2_B.W_o +
    c6_formation_ros2_DW.DiscreteTimeIntegrator_DSTATE;

  // DiscreteIntegrator: '<S21>/Discrete-Time Integrator1'
  if ((c6_formation_ros2_B.flag <= 0.0) &&
      (c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevRes == 1)) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_DSTATE =
      c6_formation_ros2_P.DiscreteTimeIntegrator1_IC;
  }

  // Reshape: '<S22>/Reshapey' incorporates:
  //   DiscreteIntegrator: '<S21>/Discrete-Time Integrator1'
  //   Sum: '<S18>/Sum1'

  c6_formation_ros2_B.Reshapey[1] = c6_formation_ros2_B.V_e +
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_DSTATE;

  // MATLABSystem: '<S17>/SourceBlock'
  c6_formation_ros2_B.b_varargout_1 =
    Sub_c6_formation_ros2_16754.getLatestMessage
    (&c6_formation_ros2_B.b_varargout_2_b);

  // Outputs for Enabled SubSystem: '<S17>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S20>/Enable'

  if (c6_formation_ros2_B.b_varargout_1) {
    // SignalConversion generated from: '<S20>/In1'
    c6_formation_ros2_B.In1_g = c6_formation_ros2_B.b_varargout_2_b;
  }

  // End of Outputs for SubSystem: '<S17>/Enabled Subsystem'

  // MATLAB Function: '<S18>/sensor2vCar4' incorporates:
  //   MATLABSystem: '<S17>/SourceBlock'

  c6_formation_ros2_sensor2vCar4(c6_formation_ros2_B.b_varargout_1,
    &c6_formation_ros2_B.In1_g, &c6_formation_ros2_B.V_e,
    &c6_formation_ros2_B.W_o, &c6_formation_ros2_DW.sf_sensor2vCar4);

  // DiscreteIntegrator: '<S21>/Discrete-Time Integrator2'
  if ((c6_formation_ros2_B.flag <= 0.0) &&
      (c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevRes == 1)) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_DSTATE =
      c6_formation_ros2_P.DiscreteTimeIntegrator2_IC;
  }

  // DiscreteIntegrator: '<S21>/Discrete-Time Integrator2'
  c6_formation_ros2_DW.DiscreteTimeIntegrator2_DSTATE +=
    c6_formation_ros2_P.DiscreteTimeIntegrator2_gainval *
    c6_formation_ros2_B.W_o;

  // Sum: '<S21>/Sum2'
  c6_formation_ros2_B.cospsi =
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_DSTATE +
    c6_formation_ros2_B.flag_p;

  // Reshape: '<S22>/Reshapey'
  c6_formation_ros2_B.Reshapey[2] = c6_formation_ros2_B.cospsi;
  c6_formation_ros2_B.Reshapey[3] = c6_formation_ros2_B.V_e;
  c6_formation_ros2_B.Reshapey[4] = c6_formation_ros2_B.W_o;

  // Outputs for Enabled SubSystem: '<S52>/Enabled Subsystem'
  // Constant: '<S22>/Enable' incorporates:
  //   Delay: '<S22>/MemoryX'

  c6_formation_r_EnabledSubsystem(c6_formation_ros2_P.Enable_Value,
    c6_formation_ros2_B.M, c6_formation_ros2_B.C, c6_formation_ros2_B.Reshapey,
    c6_formation_ros2_DW.MemoryX_DSTATE, c6_formation_ros2_B.Product2_o,
    &c6_formation_ros2_DW.EnabledSubsystem_e,
    &c6_formation_ros2_P.EnabledSubsystem_e);

  // End of Outputs for SubSystem: '<S52>/Enabled Subsystem'
  for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i <= 2;
       c6_formation_ros2_B.i += 2) {
    // Sum: '<S52>/Add'
    tmp_0 = _mm_loadu_pd(&c6_formation_ros2_B.Product2_o[c6_formation_ros2_B.i]);

    // Delay: '<S22>/MemoryX' incorporates:
    //   Sum: '<S52>/Add'

    tmp_1 = _mm_loadu_pd
      (&c6_formation_ros2_DW.MemoryX_DSTATE[c6_formation_ros2_B.i]);

    // Sum: '<S52>/Add'
    _mm_storeu_pd
      (&c6_formation_ros2_DW.Memory2_PreviousInput[c6_formation_ros2_B.i],
       _mm_add_pd(tmp_0, tmp_1));
  }

  // Sum: '<S52>/Add' incorporates:
  //   Delay: '<S22>/MemoryX'

  for (c6_formation_ros2_B.i = 4; c6_formation_ros2_B.i < 5;
       c6_formation_ros2_B.i++) {
    c6_formation_ros2_DW.Memory2_PreviousInput[c6_formation_ros2_B.i] =
      c6_formation_ros2_B.Product2_o[c6_formation_ros2_B.i] +
      c6_formation_ros2_DW.MemoryX_DSTATE[c6_formation_ros2_B.i];
  }

  // Delay: '<S83>/MemoryX' incorporates:
  //   Constant: '<S83>/X0'

  if (c6_formation_ros2_DW.icLoad_j) {
    for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i < 5;
         c6_formation_ros2_B.i++) {
      c6_formation_ros2_DW.MemoryX_DSTATE_o[c6_formation_ros2_B.i] =
        c6_formation_ros2_P.X0_Value_p[c6_formation_ros2_B.i];
    }
  }

  // MATLABSystem: '<S77>/SourceBlock'
  c6_formation_ros2_B.b_varargout_1 =
    Sub_c6_formation_ros2_16981.getLatestMessage
    (&c6_formation_ros2_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S77>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S80>/Enable'

  if (c6_formation_ros2_B.b_varargout_1) {
    // SignalConversion generated from: '<S80>/In1'
    c6_formation_ros2_B.In1_m = c6_formation_ros2_B.b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S77>/Enabled Subsystem'

  // MATLAB Function: '<S79>/sensor2vCar' incorporates:
  //   MATLABSystem: '<S77>/SourceBlock'

  c6_formation_ros2_sensor2vCar(c6_formation_ros2_B.b_varargout_1,
    &c6_formation_ros2_B.In1_m, &c6_formation_ros2_B.W_g,
    &c6_formation_ros2_B.V_d, &c6_formation_ros2_B.flag_f,
    &c6_formation_ros2_B.flag_p, &c6_formation_ros2_B.sf_sensor2vCar_d,
    &c6_formation_ros2_DW.sf_sensor2vCar_d);

  // DiscreteIntegrator: '<S82>/Discrete-Time Integrator'
  if ((c6_formation_ros2_B.flag_p <= 0.0) &&
      (c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_e == 1)) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_DSTATE_p =
      c6_formation_ros2_P.DiscreteTimeIntegrator_IC_d;
  }

  // Reshape: '<S83>/Reshapey' incorporates:
  //   DiscreteIntegrator: '<S82>/Discrete-Time Integrator'
  //   Sum: '<S79>/Sum'

  c6_formation_ros2_B.Reshapey_b[0] = c6_formation_ros2_B.W_g +
    c6_formation_ros2_DW.DiscreteTimeIntegrator_DSTATE_p;

  // DiscreteIntegrator: '<S82>/Discrete-Time Integrator1'
  if ((c6_formation_ros2_B.flag_p <= 0.0) &&
      (c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_p == 1)) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_DSTAT_b =
      c6_formation_ros2_P.DiscreteTimeIntegrator1_IC_g;
  }

  // Reshape: '<S83>/Reshapey' incorporates:
  //   DiscreteIntegrator: '<S82>/Discrete-Time Integrator1'
  //   Sum: '<S79>/Sum1'

  c6_formation_ros2_B.Reshapey_b[1] = c6_formation_ros2_B.V_d +
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_DSTAT_b;

  // MATLABSystem: '<S78>/SourceBlock'
  c6_formation_ros2_B.b_varargout_1 =
    Sub_c6_formation_ros2_16982.getLatestMessage
    (&c6_formation_ros2_B.b_varargout_2_b);

  // Outputs for Enabled SubSystem: '<S78>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S81>/Enable'

  if (c6_formation_ros2_B.b_varargout_1) {
    // SignalConversion generated from: '<S81>/In1'
    c6_formation_ros2_B.In1_b = c6_formation_ros2_B.b_varargout_2_b;
  }

  // End of Outputs for SubSystem: '<S78>/Enabled Subsystem'

  // MATLAB Function: '<S79>/sensor2vCar4' incorporates:
  //   MATLABSystem: '<S78>/SourceBlock'

  c6_formation_ros2_sensor2vCar4(c6_formation_ros2_B.b_varargout_1,
    &c6_formation_ros2_B.In1_b, &c6_formation_ros2_B.V_d,
    &c6_formation_ros2_B.W_g, &c6_formation_ros2_DW.sf_sensor2vCar4_f);

  // DiscreteIntegrator: '<S82>/Discrete-Time Integrator2'
  if ((c6_formation_ros2_B.flag_p <= 0.0) &&
      (c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevR_l == 1)) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_DSTAT_o =
      c6_formation_ros2_P.DiscreteTimeIntegrator2_IC_a;
  }

  // DiscreteIntegrator: '<S82>/Discrete-Time Integrator2'
  c6_formation_ros2_DW.DiscreteTimeIntegrator2_DSTAT_o +=
    c6_formation_ros2_P.DiscreteTimeIntegrator2_gainv_j *
    c6_formation_ros2_B.W_g;

  // Sum: '<S82>/Sum2'
  c6_formation_ros2_B.cospsi_k =
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_DSTAT_o +
    c6_formation_ros2_B.flag_f;

  // Reshape: '<S83>/Reshapey'
  c6_formation_ros2_B.Reshapey_b[2] = c6_formation_ros2_B.cospsi_k;
  c6_formation_ros2_B.Reshapey_b[3] = c6_formation_ros2_B.V_d;
  c6_formation_ros2_B.Reshapey_b[4] = c6_formation_ros2_B.W_g;

  // Outputs for Enabled SubSystem: '<S113>/Enabled Subsystem'
  // Constant: '<S83>/Enable' incorporates:
  //   Delay: '<S83>/MemoryX'

  c6_formation_r_EnabledSubsystem(c6_formation_ros2_P.Enable_Value_n,
    c6_formation_ros2_B.M_p, c6_formation_ros2_B.C_b,
    c6_formation_ros2_B.Reshapey_b, c6_formation_ros2_DW.MemoryX_DSTATE_o,
    c6_formation_ros2_B.Product2_g, &c6_formation_ros2_DW.EnabledSubsystem_h,
    &c6_formation_ros2_P.EnabledSubsystem_h);

  // End of Outputs for SubSystem: '<S113>/Enabled Subsystem'
  for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i <= 2;
       c6_formation_ros2_B.i += 2) {
    // Sum: '<S113>/Add'
    tmp_0 = _mm_loadu_pd(&c6_formation_ros2_B.Product2_g[c6_formation_ros2_B.i]);

    // Delay: '<S83>/MemoryX' incorporates:
    //   Sum: '<S113>/Add'

    tmp_1 = _mm_loadu_pd
      (&c6_formation_ros2_DW.MemoryX_DSTATE_o[c6_formation_ros2_B.i]);

    // Sum: '<S113>/Add'
    _mm_storeu_pd
      (&c6_formation_ros2_DW.Memory2_PreviousInput_p[c6_formation_ros2_B.i],
       _mm_add_pd(tmp_0, tmp_1));
  }

  // Sum: '<S113>/Add' incorporates:
  //   Delay: '<S83>/MemoryX'

  for (c6_formation_ros2_B.i = 4; c6_formation_ros2_B.i < 5;
       c6_formation_ros2_B.i++) {
    c6_formation_ros2_DW.Memory2_PreviousInput_p[c6_formation_ros2_B.i] =
      c6_formation_ros2_B.Product2_g[c6_formation_ros2_B.i] +
      c6_formation_ros2_DW.MemoryX_DSTATE_o[c6_formation_ros2_B.i];
  }

  // Delay: '<S144>/MemoryX' incorporates:
  //   Constant: '<S144>/X0'

  if (c6_formation_ros2_DW.icLoad_p) {
    for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i < 5;
         c6_formation_ros2_B.i++) {
      c6_formation_ros2_DW.MemoryX_DSTATE_h[c6_formation_ros2_B.i] =
        c6_formation_ros2_P.X0_Value_c[c6_formation_ros2_B.i];
    }
  }

  // MATLABSystem: '<S138>/SourceBlock'
  c6_formation_ros2_B.b_varargout_1 =
    Sub_c6_formation_ros2_17026.getLatestMessage
    (&c6_formation_ros2_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S138>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S141>/Enable'

  if (c6_formation_ros2_B.b_varargout_1) {
    // SignalConversion generated from: '<S141>/In1'
    c6_formation_ros2_B.In1_p = c6_formation_ros2_B.b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S138>/Enabled Subsystem'

  // MATLAB Function: '<S140>/sensor2vCar' incorporates:
  //   MATLABSystem: '<S138>/SourceBlock'

  c6_formation_ros2_sensor2vCar(c6_formation_ros2_B.b_varargout_1,
    &c6_formation_ros2_B.In1_p, &c6_formation_ros2_B.W_f,
    &c6_formation_ros2_B.V_k, &c6_formation_ros2_B.flag_j,
    &c6_formation_ros2_B.flag_f, &c6_formation_ros2_B.sf_sensor2vCar_i,
    &c6_formation_ros2_DW.sf_sensor2vCar_i);

  // DiscreteIntegrator: '<S143>/Discrete-Time Integrator'
  if ((c6_formation_ros2_B.flag_f <= 0.0) &&
      (c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_o == 1)) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_DSTATE_a =
      c6_formation_ros2_P.DiscreteTimeIntegrator_IC_n;
  }

  // Reshape: '<S144>/Reshapey' incorporates:
  //   DiscreteIntegrator: '<S143>/Discrete-Time Integrator'
  //   Sum: '<S140>/Sum'

  c6_formation_ros2_B.Reshapey_o[0] = c6_formation_ros2_B.W_f +
    c6_formation_ros2_DW.DiscreteTimeIntegrator_DSTATE_a;

  // DiscreteIntegrator: '<S143>/Discrete-Time Integrator1'
  if ((c6_formation_ros2_B.flag_f <= 0.0) &&
      (c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_f == 1)) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_DSTAT_h =
      c6_formation_ros2_P.DiscreteTimeIntegrator1_IC_n;
  }

  // Reshape: '<S144>/Reshapey' incorporates:
  //   DiscreteIntegrator: '<S143>/Discrete-Time Integrator1'
  //   Sum: '<S140>/Sum1'

  c6_formation_ros2_B.Reshapey_o[1] = c6_formation_ros2_B.V_k +
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_DSTAT_h;

  // MATLABSystem: '<S139>/SourceBlock'
  c6_formation_ros2_B.b_varargout_1 =
    Sub_c6_formation_ros2_17027.getLatestMessage
    (&c6_formation_ros2_B.b_varargout_2_b);

  // Outputs for Enabled SubSystem: '<S139>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S142>/Enable'

  if (c6_formation_ros2_B.b_varargout_1) {
    // SignalConversion generated from: '<S142>/In1'
    c6_formation_ros2_B.In1_k = c6_formation_ros2_B.b_varargout_2_b;
  }

  // End of Outputs for SubSystem: '<S139>/Enabled Subsystem'

  // MATLAB Function: '<S140>/sensor2vCar4' incorporates:
  //   MATLABSystem: '<S139>/SourceBlock'

  c6_formation_ros2_sensor2vCar4(c6_formation_ros2_B.b_varargout_1,
    &c6_formation_ros2_B.In1_k, &c6_formation_ros2_B.V_k,
    &c6_formation_ros2_B.W_f, &c6_formation_ros2_DW.sf_sensor2vCar4_m);

  // DiscreteIntegrator: '<S143>/Discrete-Time Integrator2'
  if ((c6_formation_ros2_B.flag_f <= 0.0) &&
      (c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevR_h == 1)) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_DSTAT_f =
      c6_formation_ros2_P.DiscreteTimeIntegrator2_IC_o;
  }

  // DiscreteIntegrator: '<S143>/Discrete-Time Integrator2'
  c6_formation_ros2_DW.DiscreteTimeIntegrator2_DSTAT_f +=
    c6_formation_ros2_P.DiscreteTimeIntegrator2_gainv_c *
    c6_formation_ros2_B.W_f;

  // Sum: '<S143>/Sum2'
  c6_formation_ros2_B.cospsi_c =
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_DSTAT_f +
    c6_formation_ros2_B.flag_j;

  // Reshape: '<S144>/Reshapey'
  c6_formation_ros2_B.Reshapey_o[2] = c6_formation_ros2_B.cospsi_c;
  c6_formation_ros2_B.Reshapey_o[3] = c6_formation_ros2_B.V_k;
  c6_formation_ros2_B.Reshapey_o[4] = c6_formation_ros2_B.W_f;

  // Outputs for Enabled SubSystem: '<S174>/Enabled Subsystem'
  // Constant: '<S144>/Enable' incorporates:
  //   Delay: '<S144>/MemoryX'

  c6_formation_r_EnabledSubsystem(c6_formation_ros2_P.Enable_Value_l,
    c6_formation_ros2_B.M_g, c6_formation_ros2_B.C_lk,
    c6_formation_ros2_B.Reshapey_o, c6_formation_ros2_DW.MemoryX_DSTATE_h,
    c6_formation_ros2_B.Product2_kr, &c6_formation_ros2_DW.EnabledSubsystem_lu,
    &c6_formation_ros2_P.EnabledSubsystem_lu);

  // End of Outputs for SubSystem: '<S174>/Enabled Subsystem'
  for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i <= 2;
       c6_formation_ros2_B.i += 2) {
    // Sum: '<S174>/Add'
    tmp_0 = _mm_loadu_pd(&c6_formation_ros2_B.Product2_kr[c6_formation_ros2_B.i]);

    // Delay: '<S144>/MemoryX' incorporates:
    //   Sum: '<S174>/Add'

    tmp_1 = _mm_loadu_pd
      (&c6_formation_ros2_DW.MemoryX_DSTATE_h[c6_formation_ros2_B.i]);

    // Sum: '<S174>/Add'
    _mm_storeu_pd
      (&c6_formation_ros2_DW.Memory2_PreviousInput_d[c6_formation_ros2_B.i],
       _mm_add_pd(tmp_0, tmp_1));
  }

  // Sum: '<S174>/Add' incorporates:
  //   Delay: '<S144>/MemoryX'

  for (c6_formation_ros2_B.i = 4; c6_formation_ros2_B.i < 5;
       c6_formation_ros2_B.i++) {
    c6_formation_ros2_DW.Memory2_PreviousInput_d[c6_formation_ros2_B.i] =
      c6_formation_ros2_B.Product2_kr[c6_formation_ros2_B.i] +
      c6_formation_ros2_DW.MemoryX_DSTATE_h[c6_formation_ros2_B.i];
  }

  // Delay: '<S205>/MemoryX' incorporates:
  //   Constant: '<S205>/X0'

  if (c6_formation_ros2_DW.icLoad_ko) {
    for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i < 5;
         c6_formation_ros2_B.i++) {
      c6_formation_ros2_DW.MemoryX_DSTATE_e[c6_formation_ros2_B.i] =
        c6_formation_ros2_P.X0_Value_l[c6_formation_ros2_B.i];
    }
  }

  // MATLABSystem: '<S199>/SourceBlock'
  c6_formation_ros2_B.b_varargout_1 =
    Sub_c6_formation_ros2_17071.getLatestMessage
    (&c6_formation_ros2_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S199>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S202>/Enable'

  if (c6_formation_ros2_B.b_varargout_1) {
    // SignalConversion generated from: '<S202>/In1'
    c6_formation_ros2_B.In1_a = c6_formation_ros2_B.b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S199>/Enabled Subsystem'

  // MATLAB Function: '<S201>/sensor2vCar' incorporates:
  //   MATLABSystem: '<S199>/SourceBlock'

  c6_formation_ros2_sensor2vCar(c6_formation_ros2_B.b_varargout_1,
    &c6_formation_ros2_B.In1_a, &c6_formation_ros2_B.W_i,
    &c6_formation_ros2_B.V_n, &c6_formation_ros2_B.flag_n,
    &c6_formation_ros2_B.flag_j, &c6_formation_ros2_B.sf_sensor2vCar_i3,
    &c6_formation_ros2_DW.sf_sensor2vCar_i3);

  // DiscreteIntegrator: '<S204>/Discrete-Time Integrator'
  if ((c6_formation_ros2_B.flag_j <= 0.0) &&
      (c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_g == 1)) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_DSTATE_l =
      c6_formation_ros2_P.DiscreteTimeIntegrator_IC_p;
  }

  // Reshape: '<S205>/Reshapey' incorporates:
  //   DiscreteIntegrator: '<S204>/Discrete-Time Integrator'
  //   Sum: '<S201>/Sum'

  c6_formation_ros2_B.Reshapey_i[0] = c6_formation_ros2_B.W_i +
    c6_formation_ros2_DW.DiscreteTimeIntegrator_DSTATE_l;

  // DiscreteIntegrator: '<S204>/Discrete-Time Integrator1'
  if ((c6_formation_ros2_B.flag_j <= 0.0) &&
      (c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_c == 1)) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_DSTAT_j =
      c6_formation_ros2_P.DiscreteTimeIntegrator1_IC_o;
  }

  // Reshape: '<S205>/Reshapey' incorporates:
  //   DiscreteIntegrator: '<S204>/Discrete-Time Integrator1'
  //   Sum: '<S201>/Sum1'

  c6_formation_ros2_B.Reshapey_i[1] = c6_formation_ros2_B.V_n +
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_DSTAT_j;

  // MATLABSystem: '<S200>/SourceBlock'
  c6_formation_ros2_B.b_varargout_1 =
    Sub_c6_formation_ros2_17072.getLatestMessage
    (&c6_formation_ros2_B.b_varargout_2_b);

  // Outputs for Enabled SubSystem: '<S200>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S203>/Enable'

  if (c6_formation_ros2_B.b_varargout_1) {
    // SignalConversion generated from: '<S203>/In1'
    c6_formation_ros2_B.In1_l = c6_formation_ros2_B.b_varargout_2_b;
  }

  // End of Outputs for SubSystem: '<S200>/Enabled Subsystem'

  // MATLAB Function: '<S201>/sensor2vCar4' incorporates:
  //   MATLABSystem: '<S200>/SourceBlock'

  c6_formation_ros2_sensor2vCar4(c6_formation_ros2_B.b_varargout_1,
    &c6_formation_ros2_B.In1_l, &c6_formation_ros2_B.V_n,
    &c6_formation_ros2_B.W_i, &c6_formation_ros2_DW.sf_sensor2vCar4_g);

  // DiscreteIntegrator: '<S204>/Discrete-Time Integrator2'
  if ((c6_formation_ros2_B.flag_j <= 0.0) &&
      (c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevR_j == 1)) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_DSTAT_g =
      c6_formation_ros2_P.DiscreteTimeIntegrator2_IC_k;
  }

  // DiscreteIntegrator: '<S204>/Discrete-Time Integrator2'
  c6_formation_ros2_DW.DiscreteTimeIntegrator2_DSTAT_g +=
    c6_formation_ros2_P.DiscreteTimeIntegrator2_gain_cr *
    c6_formation_ros2_B.W_i;

  // Sum: '<S204>/Sum2'
  c6_formation_ros2_B.cospsi_p =
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_DSTAT_g +
    c6_formation_ros2_B.flag_n;

  // Reshape: '<S205>/Reshapey'
  c6_formation_ros2_B.Reshapey_i[2] = c6_formation_ros2_B.cospsi_p;
  c6_formation_ros2_B.Reshapey_i[3] = c6_formation_ros2_B.V_n;
  c6_formation_ros2_B.Reshapey_i[4] = c6_formation_ros2_B.W_i;

  // Outputs for Enabled SubSystem: '<S235>/Enabled Subsystem'
  // Constant: '<S205>/Enable' incorporates:
  //   Delay: '<S205>/MemoryX'

  c6_formation_r_EnabledSubsystem(c6_formation_ros2_P.Enable_Value_k,
    c6_formation_ros2_B.M_f, c6_formation_ros2_B.C_m,
    c6_formation_ros2_B.Reshapey_i, c6_formation_ros2_DW.MemoryX_DSTATE_e,
    c6_formation_ros2_B.Product2_k, &c6_formation_ros2_DW.EnabledSubsystem_m,
    &c6_formation_ros2_P.EnabledSubsystem_m);

  // End of Outputs for SubSystem: '<S235>/Enabled Subsystem'
  for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i <= 2;
       c6_formation_ros2_B.i += 2) {
    // Sum: '<S235>/Add'
    tmp_0 = _mm_loadu_pd(&c6_formation_ros2_B.Product2_k[c6_formation_ros2_B.i]);

    // Delay: '<S205>/MemoryX' incorporates:
    //   Sum: '<S235>/Add'

    tmp_1 = _mm_loadu_pd
      (&c6_formation_ros2_DW.MemoryX_DSTATE_e[c6_formation_ros2_B.i]);

    // Sum: '<S235>/Add'
    _mm_storeu_pd
      (&c6_formation_ros2_DW.Memory2_PreviousInput_e[c6_formation_ros2_B.i],
       _mm_add_pd(tmp_0, tmp_1));
  }

  // Sum: '<S235>/Add' incorporates:
  //   Delay: '<S205>/MemoryX'

  for (c6_formation_ros2_B.i = 4; c6_formation_ros2_B.i < 5;
       c6_formation_ros2_B.i++) {
    c6_formation_ros2_DW.Memory2_PreviousInput_e[c6_formation_ros2_B.i] =
      c6_formation_ros2_B.Product2_k[c6_formation_ros2_B.i] +
      c6_formation_ros2_DW.MemoryX_DSTATE_e[c6_formation_ros2_B.i];
  }

  // Delay: '<S266>/MemoryX' incorporates:
  //   Constant: '<S266>/X0'

  if (c6_formation_ros2_DW.icLoad_f) {
    for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i < 5;
         c6_formation_ros2_B.i++) {
      c6_formation_ros2_DW.MemoryX_DSTATE_p[c6_formation_ros2_B.i] =
        c6_formation_ros2_P.X0_Value_e[c6_formation_ros2_B.i];
    }
  }

  // MATLABSystem: '<S260>/SourceBlock'
  c6_formation_ros2_B.b_varargout_1 =
    Sub_c6_formation_ros2_17116.getLatestMessage
    (&c6_formation_ros2_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S260>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S263>/Enable'

  if (c6_formation_ros2_B.b_varargout_1) {
    // SignalConversion generated from: '<S263>/In1'
    c6_formation_ros2_B.In1_j = c6_formation_ros2_B.b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S260>/Enabled Subsystem'

  // MATLAB Function: '<S262>/sensor2vCar' incorporates:
  //   MATLABSystem: '<S260>/SourceBlock'

  c6_formation_ros2_sensor2vCar(c6_formation_ros2_B.b_varargout_1,
    &c6_formation_ros2_B.In1_j, &c6_formation_ros2_B.W_a,
    &c6_formation_ros2_B.V_a, &c6_formation_ros2_B.flag_b,
    &c6_formation_ros2_B.flag_n, &c6_formation_ros2_B.sf_sensor2vCar_c,
    &c6_formation_ros2_DW.sf_sensor2vCar_c);

  // DiscreteIntegrator: '<S265>/Discrete-Time Integrator'
  if ((c6_formation_ros2_B.flag_n <= 0.0) &&
      (c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_h == 1)) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_DSTATE_c =
      c6_formation_ros2_P.DiscreteTimeIntegrator_IC_f;
  }

  // Reshape: '<S266>/Reshapey' incorporates:
  //   DiscreteIntegrator: '<S265>/Discrete-Time Integrator'
  //   Sum: '<S262>/Sum'

  c6_formation_ros2_B.Reshapey_p[0] = c6_formation_ros2_B.W_a +
    c6_formation_ros2_DW.DiscreteTimeIntegrator_DSTATE_c;

  // DiscreteIntegrator: '<S265>/Discrete-Time Integrator1'
  if ((c6_formation_ros2_B.flag_n <= 0.0) &&
      (c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_o == 1)) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_DSTAT_c =
      c6_formation_ros2_P.DiscreteTimeIntegrator1_IC_p;
  }

  // Reshape: '<S266>/Reshapey' incorporates:
  //   DiscreteIntegrator: '<S265>/Discrete-Time Integrator1'
  //   Sum: '<S262>/Sum1'

  c6_formation_ros2_B.Reshapey_p[1] = c6_formation_ros2_B.V_a +
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_DSTAT_c;

  // MATLABSystem: '<S261>/SourceBlock'
  c6_formation_ros2_B.b_varargout_1 =
    Sub_c6_formation_ros2_17117.getLatestMessage
    (&c6_formation_ros2_B.b_varargout_2_b);

  // Outputs for Enabled SubSystem: '<S261>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S264>/Enable'

  if (c6_formation_ros2_B.b_varargout_1) {
    // SignalConversion generated from: '<S264>/In1'
    c6_formation_ros2_B.In1_d = c6_formation_ros2_B.b_varargout_2_b;
  }

  // End of Outputs for SubSystem: '<S261>/Enabled Subsystem'

  // MATLAB Function: '<S262>/sensor2vCar4' incorporates:
  //   MATLABSystem: '<S261>/SourceBlock'

  c6_formation_ros2_sensor2vCar4(c6_formation_ros2_B.b_varargout_1,
    &c6_formation_ros2_B.In1_d, &c6_formation_ros2_B.V_a,
    &c6_formation_ros2_B.W_a, &c6_formation_ros2_DW.sf_sensor2vCar4_d);

  // DiscreteIntegrator: '<S265>/Discrete-Time Integrator2'
  if ((c6_formation_ros2_B.flag_n <= 0.0) &&
      (c6_formation_ros2_DW.DiscreteTimeIntegrator2_Prev_hx == 1)) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_DSTAT_i =
      c6_formation_ros2_P.DiscreteTimeIntegrator2_IC_f;
  }

  // DiscreteIntegrator: '<S265>/Discrete-Time Integrator2'
  c6_formation_ros2_DW.DiscreteTimeIntegrator2_DSTAT_i +=
    c6_formation_ros2_P.DiscreteTimeIntegrator2_gainv_a *
    c6_formation_ros2_B.W_a;

  // Sum: '<S265>/Sum2'
  c6_formation_ros2_B.cospsi_b =
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_DSTAT_i +
    c6_formation_ros2_B.flag_b;

  // Reshape: '<S266>/Reshapey'
  c6_formation_ros2_B.Reshapey_p[2] = c6_formation_ros2_B.cospsi_b;
  c6_formation_ros2_B.Reshapey_p[3] = c6_formation_ros2_B.V_a;
  c6_formation_ros2_B.Reshapey_p[4] = c6_formation_ros2_B.W_a;

  // Outputs for Enabled SubSystem: '<S296>/Enabled Subsystem'
  // Constant: '<S266>/Enable' incorporates:
  //   Delay: '<S266>/MemoryX'

  c6_formation_r_EnabledSubsystem(c6_formation_ros2_P.Enable_Value_ng,
    c6_formation_ros2_B.M_a, c6_formation_ros2_B.C_l,
    c6_formation_ros2_B.Reshapey_p, c6_formation_ros2_DW.MemoryX_DSTATE_p,
    c6_formation_ros2_B.Product2_a, &c6_formation_ros2_DW.EnabledSubsystem_li,
    &c6_formation_ros2_P.EnabledSubsystem_li);

  // End of Outputs for SubSystem: '<S296>/Enabled Subsystem'
  for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i <= 2;
       c6_formation_ros2_B.i += 2) {
    // Sum: '<S296>/Add'
    tmp_0 = _mm_loadu_pd(&c6_formation_ros2_B.Product2_a[c6_formation_ros2_B.i]);

    // Delay: '<S266>/MemoryX' incorporates:
    //   Sum: '<S296>/Add'

    tmp_1 = _mm_loadu_pd
      (&c6_formation_ros2_DW.MemoryX_DSTATE_p[c6_formation_ros2_B.i]);

    // Sum: '<S296>/Add'
    _mm_storeu_pd
      (&c6_formation_ros2_DW.Memory2_PreviousInput_k[c6_formation_ros2_B.i],
       _mm_add_pd(tmp_0, tmp_1));
  }

  // Sum: '<S296>/Add' incorporates:
  //   Delay: '<S266>/MemoryX'

  for (c6_formation_ros2_B.i = 4; c6_formation_ros2_B.i < 5;
       c6_formation_ros2_B.i++) {
    c6_formation_ros2_DW.Memory2_PreviousInput_k[c6_formation_ros2_B.i] =
      c6_formation_ros2_B.Product2_a[c6_formation_ros2_B.i] +
      c6_formation_ros2_DW.MemoryX_DSTATE_p[c6_formation_ros2_B.i];
  }

  // Delay: '<S327>/MemoryX' incorporates:
  //   Constant: '<S327>/X0'

  if (c6_formation_ros2_DW.icLoad_n) {
    for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i < 5;
         c6_formation_ros2_B.i++) {
      c6_formation_ros2_DW.MemoryX_DSTATE_j[c6_formation_ros2_B.i] =
        c6_formation_ros2_P.X0_Value_o[c6_formation_ros2_B.i];
    }
  }

  // MATLABSystem: '<S321>/SourceBlock'
  c6_formation_ros2_B.b_varargout_1 =
    Sub_c6_formation_ros2_17161.getLatestMessage
    (&c6_formation_ros2_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S321>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S324>/Enable'

  if (c6_formation_ros2_B.b_varargout_1) {
    // SignalConversion generated from: '<S324>/In1'
    c6_formation_ros2_B.In1 = c6_formation_ros2_B.b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S321>/Enabled Subsystem'

  // MATLAB Function: '<S323>/sensor2vCar' incorporates:
  //   MATLABSystem: '<S321>/SourceBlock'

  c6_formation_ros2_sensor2vCar(c6_formation_ros2_B.b_varargout_1,
    &c6_formation_ros2_B.In1, &c6_formation_ros2_B.W, &c6_formation_ros2_B.V,
    &c6_formation_ros2_B.sintheta_o, &c6_formation_ros2_B.flag_b,
    &c6_formation_ros2_B.sf_sensor2vCar_e,
    &c6_formation_ros2_DW.sf_sensor2vCar_e);

  // DiscreteIntegrator: '<S326>/Discrete-Time Integrator'
  if ((c6_formation_ros2_B.flag_b <= 0.0) &&
      (c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_b == 1)) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_DSTATE_j =
      c6_formation_ros2_P.DiscreteTimeIntegrator_IC_h;
  }

  // Reshape: '<S327>/Reshapey' incorporates:
  //   DiscreteIntegrator: '<S326>/Discrete-Time Integrator'
  //   Sum: '<S323>/Sum'

  c6_formation_ros2_B.Reshapey_m[0] = c6_formation_ros2_B.W +
    c6_formation_ros2_DW.DiscreteTimeIntegrator_DSTATE_j;

  // DiscreteIntegrator: '<S326>/Discrete-Time Integrator1'
  if ((c6_formation_ros2_B.flag_b <= 0.0) &&
      (c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_n == 1)) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_DSTAT_i =
      c6_formation_ros2_P.DiscreteTimeIntegrator1_IC_e;
  }

  // Reshape: '<S327>/Reshapey' incorporates:
  //   DiscreteIntegrator: '<S326>/Discrete-Time Integrator1'
  //   Sum: '<S323>/Sum1'

  c6_formation_ros2_B.Reshapey_m[1] = c6_formation_ros2_B.V +
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_DSTAT_i;

  // MATLABSystem: '<S322>/SourceBlock'
  c6_formation_ros2_B.b_varargout_1 =
    Sub_c6_formation_ros2_17162.getLatestMessage
    (&c6_formation_ros2_B.b_varargout_2_b);

  // Outputs for Enabled SubSystem: '<S322>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S325>/Enable'

  if (c6_formation_ros2_B.b_varargout_1) {
    // SignalConversion generated from: '<S325>/In1'
    c6_formation_ros2_B.In1_c = c6_formation_ros2_B.b_varargout_2_b;
  }

  // End of Outputs for SubSystem: '<S322>/Enabled Subsystem'

  // MATLAB Function: '<S323>/sensor2vCar4' incorporates:
  //   MATLABSystem: '<S322>/SourceBlock'

  c6_formation_ros2_sensor2vCar4(c6_formation_ros2_B.b_varargout_1,
    &c6_formation_ros2_B.In1_c, &c6_formation_ros2_B.V, &c6_formation_ros2_B.W,
    &c6_formation_ros2_DW.sf_sensor2vCar4_e);

  // DiscreteIntegrator: '<S326>/Discrete-Time Integrator2'
  if ((c6_formation_ros2_B.flag_b <= 0.0) &&
      (c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevR_p == 1)) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_DSTA_fb =
      c6_formation_ros2_P.DiscreteTimeIntegrator2_IC_p;
  }

  // DiscreteIntegrator: '<S326>/Discrete-Time Integrator2'
  c6_formation_ros2_DW.DiscreteTimeIntegrator2_DSTA_fb +=
    c6_formation_ros2_P.DiscreteTimeIntegrator2_gainv_m * c6_formation_ros2_B.W;

  // Sum: '<S326>/Sum2'
  c6_formation_ros2_B.sintheta_o +=
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_DSTA_fb;

  // Reshape: '<S327>/Reshapey'
  c6_formation_ros2_B.Reshapey_m[2] = c6_formation_ros2_B.sintheta_o;
  c6_formation_ros2_B.Reshapey_m[3] = c6_formation_ros2_B.V;
  c6_formation_ros2_B.Reshapey_m[4] = c6_formation_ros2_B.W;

  // Outputs for Enabled SubSystem: '<S357>/Enabled Subsystem'
  // Constant: '<S327>/Enable' incorporates:
  //   Delay: '<S327>/MemoryX'

  c6_formation_r_EnabledSubsystem(c6_formation_ros2_P.Enable_Value_kj,
    c6_formation_ros2_B.M_e, c6_formation_ros2_B.Bkuk,
    c6_formation_ros2_B.Reshapey_m, c6_formation_ros2_DW.MemoryX_DSTATE_j,
    c6_formation_ros2_B.Product2, &c6_formation_ros2_DW.EnabledSubsystem_o,
    &c6_formation_ros2_P.EnabledSubsystem_o);

  // End of Outputs for SubSystem: '<S357>/Enabled Subsystem'
  for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i <= 2;
       c6_formation_ros2_B.i += 2) {
    // Sum: '<S357>/Add'
    tmp_0 = _mm_loadu_pd(&c6_formation_ros2_B.Product2[c6_formation_ros2_B.i]);

    // Delay: '<S327>/MemoryX' incorporates:
    //   Sum: '<S357>/Add'

    tmp_1 = _mm_loadu_pd
      (&c6_formation_ros2_DW.MemoryX_DSTATE_j[c6_formation_ros2_B.i]);

    // Sum: '<S357>/Add'
    _mm_storeu_pd
      (&c6_formation_ros2_DW.Memory2_PreviousInput_o[c6_formation_ros2_B.i],
       _mm_add_pd(tmp_0, tmp_1));
  }

  // Sum: '<S357>/Add' incorporates:
  //   Delay: '<S327>/MemoryX'

  for (c6_formation_ros2_B.i = 4; c6_formation_ros2_B.i < 5;
       c6_formation_ros2_B.i++) {
    c6_formation_ros2_DW.Memory2_PreviousInput_o[c6_formation_ros2_B.i] =
      c6_formation_ros2_B.Product2[c6_formation_ros2_B.i] +
      c6_formation_ros2_DW.MemoryX_DSTATE_j[c6_formation_ros2_B.i];
  }

  // Reshape: '<Root>/Reshape1'
  c6_formation_ros2_B.dv[0] = c6_formation_ros2_DW.Memory2_PreviousInput[0];
  c6_formation_ros2_B.dv[3] = c6_formation_ros2_DW.Memory2_PreviousInput_p[0];
  c6_formation_ros2_B.dv[6] = c6_formation_ros2_DW.Memory2_PreviousInput_d[0];
  c6_formation_ros2_B.dv[9] = c6_formation_ros2_DW.Memory2_PreviousInput_e[0];
  c6_formation_ros2_B.dv[12] = c6_formation_ros2_DW.Memory2_PreviousInput_k[0];
  c6_formation_ros2_B.dv[15] = c6_formation_ros2_DW.Memory2_PreviousInput_o[0];
  c6_formation_ros2_B.dv[1] = c6_formation_ros2_DW.Memory2_PreviousInput[1];
  c6_formation_ros2_B.dv[4] = c6_formation_ros2_DW.Memory2_PreviousInput_p[1];
  c6_formation_ros2_B.dv[7] = c6_formation_ros2_DW.Memory2_PreviousInput_d[1];
  c6_formation_ros2_B.dv[10] = c6_formation_ros2_DW.Memory2_PreviousInput_e[1];
  c6_formation_ros2_B.dv[13] = c6_formation_ros2_DW.Memory2_PreviousInput_k[1];
  c6_formation_ros2_B.dv[16] = c6_formation_ros2_DW.Memory2_PreviousInput_o[1];
  c6_formation_ros2_B.dv[2] = c6_formation_ros2_DW.Memory2_PreviousInput[2];
  c6_formation_ros2_B.dv[5] = c6_formation_ros2_DW.Memory2_PreviousInput_p[2];
  c6_formation_ros2_B.dv[8] = c6_formation_ros2_DW.Memory2_PreviousInput_d[2];
  c6_formation_ros2_B.dv[11] = c6_formation_ros2_DW.Memory2_PreviousInput_e[2];
  c6_formation_ros2_B.dv[14] = c6_formation_ros2_DW.Memory2_PreviousInput_k[2];
  c6_formation_ros2_B.dv[17] = c6_formation_ros2_DW.Memory2_PreviousInput_o[2];

  // Math: '<Root>/Math Function1'
  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       6; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart] =
      c6_formation_ros2_B.dv[3 * c6_formation_ros2_B.idxFillStart];
    c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart + 6] =
      c6_formation_ros2_B.dv[3 * c6_formation_ros2_B.idxFillStart + 1];
    c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart + 12] =
      c6_formation_ros2_B.dv[3 * c6_formation_ros2_B.idxFillStart + 2];
  }

  // End of Math: '<Root>/Math Function1'

  // Chart: '<Root>/Chart' incorporates:
  //   Math: '<Root>/Math Function1'

  if (c6_formation_ros2_DW.is_active_c39_c6_formation_ros2 == 0U) {
    c6_formation_ros2_DW.is_active_c39_c6_formation_ros2 = 1U;
    c6_formation_ros2_DW.is_c39_c6_formation_ros2 = c6_formation_ros2_IN_Init;
    c6_formation_ros2_DW.state = 1.0;
    memcpy(&c6_formation_ros2_B.wp[0], &ab[0], 18U * sizeof(real_T));
  } else if (c6_formation_ros2_DW.is_c39_c6_formation_ros2 ==
             c6_formation_IN_DuiXingBianHuan) {
    if (c6_formation_ros2_DW.state == 1.0) {
      c6_formation_ros2_DW.is_DuiXingBianHuan = c6_formation_ros2_IN_SanKai;
      memcpy(&c6_formation_ros2_B.wp[0], &wpSanKai[0], 18U * sizeof(real_T));
      for (c6_formation_ros2_B.idxFillStart = 0;
           c6_formation_ros2_B.idxFillStart < 6;
           c6_formation_ros2_B.idxFillStart++) {
        c6_formation_ros2_B.wpCircle_tmp = c6_formation_ros2_B.idxFillStart << 1;
        c6_formation_ros2_B.Uvw[c6_formation_ros2_B.wpCircle_tmp] =
          c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart] -
          hb[c6_formation_ros2_B.idxFillStart];
        c6_formation_ros2_B.Uvw[c6_formation_ros2_B.wpCircle_tmp + 1] =
          c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart + 6]
          - hb[c6_formation_ros2_B.idxFillStart + 6];
      }

      c6_formation_ros2_vecnorm(c6_formation_ros2_B.Uvw,
        c6_formation_ros2_B.dists);
      c6_formation_ros2_B.b_varargout_1 = true;
      c6_formation_ros2_B.idxFillStart = 0;
      exitg1 = false;
      while ((!exitg1) && (c6_formation_ros2_B.idxFillStart < 6)) {
        if (!(c6_formation_ros2_B.dists[c6_formation_ros2_B.idxFillStart] <
              c6_formation_ros2_P.end_dis)) {
          c6_formation_ros2_B.b_varargout_1 = false;
          exitg1 = true;
        } else {
          c6_formation_ros2_B.idxFillStart++;
        }
      }

      if (c6_formation_ros2_B.b_varargout_1) {
        for (c6_formation_ros2_B.idxFillStart = 0;
             c6_formation_ros2_B.idxFillStart < 6;
             c6_formation_ros2_B.idxFillStart++) {
          c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart] =
            c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart];
          c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 6] =
            c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart +
            6];
        }

        for (c6_formation_ros2_B.idxFillStart = 0;
             c6_formation_ros2_B.idxFillStart < 6;
             c6_formation_ros2_B.idxFillStart++) {
          c6_formation_ros2_B.scale =
            c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart +
            12];
          if (fabs(c6_formation_ros2_angdiff
                   (c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 12],
                    c6_formation_ros2_B.scale)) < c6_formation_ros2_P.end_ang) {
            c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 12] =
              c6_formation_ros2_B.scale;
          }
        }

        for (c6_formation_ros2_B.idxFillStart = 0;
             c6_formation_ros2_B.idxFillStart <= 4;
             c6_formation_ros2_B.idxFillStart += 2) {
          tmp_0 = _mm_loadu_pd
            (&c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart
             + 12]);
          tmp_1 = _mm_loadu_pd
            (&c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 12]);
          _mm_storeu_pd
            (&c6_formation_ros2_B.dists[c6_formation_ros2_B.idxFillStart],
             _mm_sub_pd(tmp_0, tmp_1));
        }

        if (c6_formation_ros2_vecnorm_m(c6_formation_ros2_B.dists) <
            c6_formation_ros2_P.end_ang) {
          if (c6_formation_ros2_DW.t0 < 3.0) {
            c6_formation_ros2_DW.t0 += 0.1;
          } else {
            c6_formation_ros2_DW.state = 2.0;
            c6_formation_ros2_DW.t0 = 0.0;
          }
        }
      }
    } else if (c6_formation_ros2_DW.state == 2.0) {
      c6_formation_ros2_DW.is_DuiXingBianHuan = c6_formation_ros2_IN_LieDui;
      memcpy(&c6_formation_ros2_B.wp[0], &wplieDui[0], 18U * sizeof(real_T));
      for (c6_formation_ros2_B.idxFillStart = 0;
           c6_formation_ros2_B.idxFillStart < 6;
           c6_formation_ros2_B.idxFillStart++) {
        c6_formation_ros2_B.wpCircle_tmp = c6_formation_ros2_B.idxFillStart << 1;
        c6_formation_ros2_B.Uvw[c6_formation_ros2_B.wpCircle_tmp] =
          c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart] -
          gb[c6_formation_ros2_B.idxFillStart];
        c6_formation_ros2_B.Uvw[c6_formation_ros2_B.wpCircle_tmp + 1] =
          c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart + 6]
          - gb[c6_formation_ros2_B.idxFillStart + 6];
      }

      c6_formation_ros2_vecnorm(c6_formation_ros2_B.Uvw,
        c6_formation_ros2_B.dists);
      c6_formation_ros2_B.b_varargout_1 = true;
      c6_formation_ros2_B.idxFillStart = 0;
      exitg1 = false;
      while ((!exitg1) && (c6_formation_ros2_B.idxFillStart < 6)) {
        if (!(c6_formation_ros2_B.dists[c6_formation_ros2_B.idxFillStart] <
              c6_formation_ros2_P.end_dis)) {
          c6_formation_ros2_B.b_varargout_1 = false;
          exitg1 = true;
        } else {
          c6_formation_ros2_B.idxFillStart++;
        }
      }

      if (c6_formation_ros2_B.b_varargout_1) {
        for (c6_formation_ros2_B.idxFillStart = 0;
             c6_formation_ros2_B.idxFillStart < 6;
             c6_formation_ros2_B.idxFillStart++) {
          c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart] =
            c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart];
          c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 6] =
            c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart +
            6];
        }

        for (c6_formation_ros2_B.idxFillStart = 0;
             c6_formation_ros2_B.idxFillStart < 6;
             c6_formation_ros2_B.idxFillStart++) {
          c6_formation_ros2_B.scale =
            c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart +
            12];
          if (fabs(c6_formation_ros2_angdiff
                   (c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 12],
                    c6_formation_ros2_B.scale)) < c6_formation_ros2_P.end_ang) {
            c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 12] =
              c6_formation_ros2_B.scale;
          }
        }

        for (c6_formation_ros2_B.idxFillStart = 0;
             c6_formation_ros2_B.idxFillStart <= 4;
             c6_formation_ros2_B.idxFillStart += 2) {
          tmp_0 = _mm_loadu_pd
            (&c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart
             + 12]);
          tmp_1 = _mm_loadu_pd
            (&c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 12]);
          _mm_storeu_pd
            (&c6_formation_ros2_B.dists[c6_formation_ros2_B.idxFillStart],
             _mm_sub_pd(tmp_0, tmp_1));
        }

        if (c6_formation_ros2_vecnorm_m(c6_formation_ros2_B.dists) <
            c6_formation_ros2_P.end_ang) {
          if (c6_formation_ros2_DW.t0_c < 3.0) {
            c6_formation_ros2_DW.t0_c += 0.1;
          } else {
            c6_formation_ros2_DW.state = 3.0;
            c6_formation_ros2_DW.t0_c = 0.0;
          }
        }
      }
    } else if (c6_formation_ros2_DW.state == 4.0) {
      c6_formation_ros2_DW.is_DuiXingBianHuan = c6_formation_ros2_IN_DuiDao;
      switch (static_cast<int32_T>(c6_formation_ros2_DW.iflag)) {
       case 0:
        memcpy(&c6_formation_ros2_B.wp[0], &cb[0], 18U * sizeof(real_T));
        break;

       case 1:
        memcpy(&c6_formation_ros2_B.wp[0], &db[0], 18U * sizeof(real_T));
        break;

       case 2:
        memcpy(&c6_formation_ros2_B.wp[0], &eb[0], 18U * sizeof(real_T));
        break;

       default:
        memcpy(&c6_formation_ros2_B.wp[0], &bb[0], 18U * sizeof(real_T));
        break;
      }

      for (c6_formation_ros2_B.idxFillStart = 0;
           c6_formation_ros2_B.idxFillStart < 6;
           c6_formation_ros2_B.idxFillStart++) {
        c6_formation_ros2_B.wpCircle_tmp = c6_formation_ros2_B.idxFillStart << 1;
        c6_formation_ros2_B.Uvw[c6_formation_ros2_B.wpCircle_tmp] =
          c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart] -
          c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart];
        c6_formation_ros2_B.Uvw[c6_formation_ros2_B.wpCircle_tmp + 1] =
          c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart + 6]
          - c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 6];
      }

      c6_formation_ros2_vecnorm(c6_formation_ros2_B.Uvw,
        c6_formation_ros2_B.dists);
      c6_formation_ros2_B.b_varargout_1 = true;
      c6_formation_ros2_B.idxFillStart = 0;
      exitg1 = false;
      while ((!exitg1) && (c6_formation_ros2_B.idxFillStart < 6)) {
        if (!(c6_formation_ros2_B.dists[c6_formation_ros2_B.idxFillStart] <
              c6_formation_ros2_P.end_dis)) {
          c6_formation_ros2_B.b_varargout_1 = false;
          exitg1 = true;
        } else {
          c6_formation_ros2_B.idxFillStart++;
        }
      }

      if (c6_formation_ros2_B.b_varargout_1) {
        for (c6_formation_ros2_B.idxFillStart = 0;
             c6_formation_ros2_B.idxFillStart < 6;
             c6_formation_ros2_B.idxFillStart++) {
          c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart] =
            c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart];
          c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 6] =
            c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart +
            6];
        }

        for (c6_formation_ros2_B.idxFillStart = 0;
             c6_formation_ros2_B.idxFillStart < 6;
             c6_formation_ros2_B.idxFillStart++) {
          c6_formation_ros2_B.scale =
            c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart +
            12];
          if (fabs(c6_formation_ros2_angdiff
                   (c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 12],
                    c6_formation_ros2_B.scale)) < c6_formation_ros2_P.end_ang) {
            c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 12] =
              c6_formation_ros2_B.scale;
          }
        }

        for (c6_formation_ros2_B.idxFillStart = 0;
             c6_formation_ros2_B.idxFillStart <= 4;
             c6_formation_ros2_B.idxFillStart += 2) {
          tmp_0 = _mm_loadu_pd
            (&c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart
             + 12]);
          tmp_1 = _mm_loadu_pd
            (&c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 12]);
          _mm_storeu_pd
            (&c6_formation_ros2_B.dists[c6_formation_ros2_B.idxFillStart],
             _mm_sub_pd(tmp_0, tmp_1));
        }

        if (c6_formation_ros2_vecnorm_m(c6_formation_ros2_B.dists) <
            c6_formation_ros2_P.end_ang) {
          c6_formation_ros2_DW.iflag++;
          if (c6_formation_ros2_DW.iflag > 3.0) {
            c6_formation_ros2_DW.iflag = 0.0;
            c6_formation_ros2_DW.inum_g++;
          }
        }
      }

      if ((c6_formation_ros2_DW.inum_g == 3.0) && (c6_formation_ros2_DW.iflag ==
           1.0)) {
        c6_formation_ros2_DW.state = 5.0;
        c6_formation_ros2_DW.inum_g = 1.0;
        c6_formation_ros2_DW.iflag = 2.0;
      }
    } else if (c6_formation_ros2_DW.state == 3.0) {
      c6_formation_ros2_DW.is_DuiXingBianHuan = c6_formation_ros2_IN_Circle;
      switch (static_cast<int32_T>(c6_formation_ros2_DW.idx)) {
       case 1:
        for (c6_formation_ros2_B.idxFillStart = 0;
             c6_formation_ros2_B.idxFillStart < 3;
             c6_formation_ros2_B.idxFillStart++) {
          c6_formation_ros2_B.wp[6 * c6_formation_ros2_B.idxFillStart] =
            wpCircle[(12 * c6_formation_ros2_B.idxFillStart +
                      static_cast<int32_T>(c6_formation_ros2_DW.idx)) - 1];
          for (c6_formation_ros2_B.wpCircle_tmp = 0;
               c6_formation_ros2_B.wpCircle_tmp < 5;
               c6_formation_ros2_B.wpCircle_tmp++) {
            c6_formation_ros2_B.wp[(c6_formation_ros2_B.wpCircle_tmp + 6 *
              c6_formation_ros2_B.idxFillStart) + 1] = ib[5 *
              c6_formation_ros2_B.idxFillStart +
              c6_formation_ros2_B.wpCircle_tmp];
          }
        }
        break;

       case 2:
        if (c6_formation_ros2_DW.idx < 1.0) {
          c6_formation_ros2_B.i = 0;
          c6_formation_ros2_B.colPos = 1;
          c6_formation_ros2_B.idxFillStart = -1;
        } else {
          c6_formation_ros2_B.i = static_cast<int32_T>(c6_formation_ros2_DW.idx)
            - 1;
          c6_formation_ros2_B.colPos = -1;
          c6_formation_ros2_B.idxFillStart = 0;
        }

        c6_formation_ros2_B.b_j = div_s32(c6_formation_ros2_B.idxFillStart -
          c6_formation_ros2_B.i, c6_formation_ros2_B.colPos);
        for (c6_formation_ros2_B.idxFillStart = 0;
             c6_formation_ros2_B.idxFillStart < 3;
             c6_formation_ros2_B.idxFillStart++) {
          for (c6_formation_ros2_B.wpCircle_tmp = 0;
               c6_formation_ros2_B.wpCircle_tmp <= c6_formation_ros2_B.b_j;
               c6_formation_ros2_B.wpCircle_tmp++) {
            c6_formation_ros2_B.wpCircle_data[c6_formation_ros2_B.wpCircle_tmp +
              (c6_formation_ros2_B.b_j + 5) * c6_formation_ros2_B.idxFillStart] =
              wpCircle[(c6_formation_ros2_B.colPos *
                        c6_formation_ros2_B.wpCircle_tmp + c6_formation_ros2_B.i)
              + 12 * c6_formation_ros2_B.idxFillStart];
          }

          c6_formation_ros2_B.wpCircle_tmp = c6_formation_ros2_B.idxFillStart <<
            2;
          c6_formation_ros2_B.wpCircle_data[(c6_formation_ros2_B.b_j +
            (c6_formation_ros2_B.b_j + 5) * c6_formation_ros2_B.idxFillStart) +
            1] = jb[c6_formation_ros2_B.wpCircle_tmp];
          c6_formation_ros2_B.g = (c6_formation_ros2_B.b_j + 5) *
            c6_formation_ros2_B.idxFillStart;
          c6_formation_ros2_B.wpCircle_data[(c6_formation_ros2_B.b_j +
            c6_formation_ros2_B.g) + 2] = jb[c6_formation_ros2_B.wpCircle_tmp +
            1];
          c6_formation_ros2_B.wpCircle_data[(c6_formation_ros2_B.b_j +
            c6_formation_ros2_B.g) + 3] = jb[c6_formation_ros2_B.wpCircle_tmp +
            2];
          c6_formation_ros2_B.wpCircle_data[(c6_formation_ros2_B.b_j +
            c6_formation_ros2_B.g) + 4] = jb[c6_formation_ros2_B.wpCircle_tmp +
            3];
        }

        memcpy(&c6_formation_ros2_B.wp[0], &c6_formation_ros2_B.wpCircle_data[0],
               18U * sizeof(real_T));
        break;

       case 3:
        if (c6_formation_ros2_DW.idx < 1.0) {
          c6_formation_ros2_B.i = 0;
          c6_formation_ros2_B.colPos = 1;
          c6_formation_ros2_B.idxFillStart = -1;
        } else {
          c6_formation_ros2_B.i = static_cast<int32_T>(c6_formation_ros2_DW.idx)
            - 1;
          c6_formation_ros2_B.colPos = -1;
          c6_formation_ros2_B.idxFillStart = 0;
        }

        c6_formation_ros2_B.b_j = div_s32(c6_formation_ros2_B.idxFillStart -
          c6_formation_ros2_B.i, c6_formation_ros2_B.colPos);
        for (c6_formation_ros2_B.idxFillStart = 0;
             c6_formation_ros2_B.idxFillStart < 3;
             c6_formation_ros2_B.idxFillStart++) {
          for (c6_formation_ros2_B.wpCircle_tmp = 0;
               c6_formation_ros2_B.wpCircle_tmp <= c6_formation_ros2_B.b_j;
               c6_formation_ros2_B.wpCircle_tmp++) {
            c6_formation_ros2_B.wpCircle_data_c[c6_formation_ros2_B.wpCircle_tmp
              + (c6_formation_ros2_B.b_j + 4) * c6_formation_ros2_B.idxFillStart]
              = wpCircle[(c6_formation_ros2_B.colPos *
                          c6_formation_ros2_B.wpCircle_tmp +
                          c6_formation_ros2_B.i) + 12 *
              c6_formation_ros2_B.idxFillStart];
          }

          c6_formation_ros2_B.wpCircle_data_c[(c6_formation_ros2_B.b_j +
            (c6_formation_ros2_B.b_j + 4) * c6_formation_ros2_B.idxFillStart) +
            1] = kb[3 * c6_formation_ros2_B.idxFillStart];
          c6_formation_ros2_B.wpCircle_data_c[(c6_formation_ros2_B.b_j +
            (c6_formation_ros2_B.b_j + 4) * c6_formation_ros2_B.idxFillStart) +
            2] = kb[3 * c6_formation_ros2_B.idxFillStart + 1];
          c6_formation_ros2_B.wpCircle_data_c[(c6_formation_ros2_B.b_j +
            (c6_formation_ros2_B.b_j + 4) * c6_formation_ros2_B.idxFillStart) +
            3] = kb[3 * c6_formation_ros2_B.idxFillStart + 2];
        }

        memcpy(&c6_formation_ros2_B.wp[0], &c6_formation_ros2_B.wpCircle_data_c
               [0], 18U * sizeof(real_T));
        break;

       case 4:
        if (c6_formation_ros2_DW.idx < 1.0) {
          c6_formation_ros2_B.i = 0;
          c6_formation_ros2_B.colPos = 1;
          c6_formation_ros2_B.idxFillStart = -1;
        } else {
          c6_formation_ros2_B.i = static_cast<int32_T>(c6_formation_ros2_DW.idx)
            - 1;
          c6_formation_ros2_B.colPos = -1;
          c6_formation_ros2_B.idxFillStart = 0;
        }

        c6_formation_ros2_B.b_j = div_s32(c6_formation_ros2_B.idxFillStart -
          c6_formation_ros2_B.i, c6_formation_ros2_B.colPos);
        for (c6_formation_ros2_B.idxFillStart = 0;
             c6_formation_ros2_B.idxFillStart < 3;
             c6_formation_ros2_B.idxFillStart++) {
          for (c6_formation_ros2_B.wpCircle_tmp = 0;
               c6_formation_ros2_B.wpCircle_tmp <= c6_formation_ros2_B.b_j;
               c6_formation_ros2_B.wpCircle_tmp++) {
            c6_formation_ros2_B.wpCircle_data_k[c6_formation_ros2_B.wpCircle_tmp
              + (c6_formation_ros2_B.b_j + 3) * c6_formation_ros2_B.idxFillStart]
              = wpCircle[(c6_formation_ros2_B.colPos *
                          c6_formation_ros2_B.wpCircle_tmp +
                          c6_formation_ros2_B.i) + 12 *
              c6_formation_ros2_B.idxFillStart];
          }

          c6_formation_ros2_B.wpCircle_tmp = c6_formation_ros2_B.idxFillStart <<
            1;
          c6_formation_ros2_B.wpCircle_data_k[(c6_formation_ros2_B.b_j +
            (c6_formation_ros2_B.b_j + 3) * c6_formation_ros2_B.idxFillStart) +
            1] = lb[c6_formation_ros2_B.wpCircle_tmp];
          c6_formation_ros2_B.wpCircle_data_k[(c6_formation_ros2_B.b_j +
            (c6_formation_ros2_B.b_j + 3) * c6_formation_ros2_B.idxFillStart) +
            2] = lb[c6_formation_ros2_B.wpCircle_tmp + 1];
        }

        memcpy(&c6_formation_ros2_B.wp[0], &c6_formation_ros2_B.wpCircle_data_k
               [0], 18U * sizeof(real_T));
        break;

       case 5:
        if (c6_formation_ros2_DW.idx < 1.0) {
          c6_formation_ros2_B.i = 0;
          c6_formation_ros2_B.colPos = 1;
          c6_formation_ros2_B.idxFillStart = -1;
        } else {
          c6_formation_ros2_B.i = static_cast<int32_T>(c6_formation_ros2_DW.idx)
            - 1;
          c6_formation_ros2_B.colPos = -1;
          c6_formation_ros2_B.idxFillStart = 0;
        }

        c6_formation_ros2_B.b_j = div_s32(c6_formation_ros2_B.idxFillStart -
          c6_formation_ros2_B.i, c6_formation_ros2_B.colPos);
        for (c6_formation_ros2_B.idxFillStart = 0;
             c6_formation_ros2_B.idxFillStart < 3;
             c6_formation_ros2_B.idxFillStart++) {
          for (c6_formation_ros2_B.wpCircle_tmp = 0;
               c6_formation_ros2_B.wpCircle_tmp <= c6_formation_ros2_B.b_j;
               c6_formation_ros2_B.wpCircle_tmp++) {
            c6_formation_ros2_B.wpCircle_data_cx[c6_formation_ros2_B.wpCircle_tmp
              + (c6_formation_ros2_B.b_j + 2) * c6_formation_ros2_B.idxFillStart]
              = wpCircle[(c6_formation_ros2_B.colPos *
                          c6_formation_ros2_B.wpCircle_tmp +
                          c6_formation_ros2_B.i) + 12 *
              c6_formation_ros2_B.idxFillStart];
          }
        }

        c6_formation_ros2_B.wpCircle_data_cx[c6_formation_ros2_B.b_j + 1] =
          1.6928203230275507;
        c6_formation_ros2_B.wpCircle_data_cx[(c6_formation_ros2_B.b_j +
          c6_formation_ros2_B.b_j) + 3] = 0.59999999999999964;
        c6_formation_ros2_B.wpCircle_data_cx[(c6_formation_ros2_B.b_j +
          ((c6_formation_ros2_B.b_j + 2) << 1)) + 1] = 7.3303828583761836;
        memcpy(&c6_formation_ros2_B.wp[0],
               &c6_formation_ros2_B.wpCircle_data_cx[0], 18U * sizeof(real_T));
        break;

       default:
        for (c6_formation_ros2_B.idxFillStart = 0;
             c6_formation_ros2_B.idxFillStart < 3;
             c6_formation_ros2_B.idxFillStart++) {
          for (c6_formation_ros2_B.wpCircle_tmp = 0;
               c6_formation_ros2_B.wpCircle_tmp < 6;
               c6_formation_ros2_B.wpCircle_tmp++) {
            c6_formation_ros2_B.wp[c6_formation_ros2_B.wpCircle_tmp + 6 *
              c6_formation_ros2_B.idxFillStart] = wpCircle[(static_cast<int32_T>
              (c6_formation_ros2_DW.idx - static_cast<real_T>
               (c6_formation_ros2_B.wpCircle_tmp)) + 12 *
              c6_formation_ros2_B.idxFillStart) - 1];
          }
        }
        break;
      }

      if (!(c6_formation_ros2_DW.istart != 0.0)) {
        for (c6_formation_ros2_B.idxFillStart = 0;
             c6_formation_ros2_B.idxFillStart < 6;
             c6_formation_ros2_B.idxFillStart++) {
          c6_formation_ros2_B.wpCircle_tmp = c6_formation_ros2_B.idxFillStart <<
            1;
          c6_formation_ros2_B.Uvw[c6_formation_ros2_B.wpCircle_tmp] =
            c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart]
            - c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart];
          c6_formation_ros2_B.Uvw[c6_formation_ros2_B.wpCircle_tmp + 1] =
            c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart +
            6] - c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 6];
        }

        c6_formation_ros2_vecnorm(c6_formation_ros2_B.Uvw,
          c6_formation_ros2_B.dists);
        c6_formation_ros2_B.b_varargout_1 = true;
        c6_formation_ros2_B.idxFillStart = 0;
        exitg1 = false;
        while ((!exitg1) && (c6_formation_ros2_B.idxFillStart < 6)) {
          if (!(c6_formation_ros2_B.dists[c6_formation_ros2_B.idxFillStart] <
                c6_formation_ros2_P.end_dis)) {
            c6_formation_ros2_B.b_varargout_1 = false;
            exitg1 = true;
          } else {
            c6_formation_ros2_B.idxFillStart++;
          }
        }

        if (c6_formation_ros2_B.b_varargout_1) {
          for (c6_formation_ros2_B.idxFillStart = 0;
               c6_formation_ros2_B.idxFillStart < 6;
               c6_formation_ros2_B.idxFillStart++) {
            c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart] =
              c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart];
            c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 6] =
              c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart
              + 6];
          }

          for (c6_formation_ros2_B.idxFillStart = 0;
               c6_formation_ros2_B.idxFillStart < 6;
               c6_formation_ros2_B.idxFillStart++) {
            c6_formation_ros2_B.scale =
              c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart
              + 12];
            if (fabs(c6_formation_ros2_angdiff
                     (c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart +
                      12], c6_formation_ros2_B.scale)) <
                c6_formation_ros2_P.end_ang) {
              c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 12] =
                c6_formation_ros2_B.scale;
            }
          }

          for (c6_formation_ros2_B.idxFillStart = 0;
               c6_formation_ros2_B.idxFillStart <= 4;
               c6_formation_ros2_B.idxFillStart += 2) {
            tmp_0 = _mm_loadu_pd
              (&c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart
               + 12]);
            tmp_1 = _mm_loadu_pd
              (&c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 12]);
            _mm_storeu_pd
              (&c6_formation_ros2_B.dists[c6_formation_ros2_B.idxFillStart],
               _mm_sub_pd(tmp_0, tmp_1));
          }

          if (c6_formation_ros2_vecnorm_m(c6_formation_ros2_B.dists) <
              c6_formation_ros2_P.end_ang) {
            c6_formation_ros2_DW.istart = 1.0;
            c6_formation_ros2_DW.idx++;
            if (c6_formation_ros2_DW.idx > 12.0) {
              c6_formation_ros2_DW.idx = 1.0;
              c6_formation_ros2_DW.inum++;
            }
          }
        }
      } else {
        c6_formation_ros2_B.scale = 3.3121686421112381E-170;
        c6_formation_ros2_B.absxk = fabs(c6_formation_ros2_B.wp[0] -
          c6_formation_ros2_B.MathFunction1[0]);
        if (c6_formation_ros2_B.absxk > 3.3121686421112381E-170) {
          c6_formation_ros2_B.t = 1.0;
          c6_formation_ros2_B.scale = c6_formation_ros2_B.absxk;
        } else {
          c6_formation_ros2_B.b_t = c6_formation_ros2_B.absxk /
            3.3121686421112381E-170;
          c6_formation_ros2_B.t = c6_formation_ros2_B.b_t *
            c6_formation_ros2_B.b_t;
        }

        c6_formation_ros2_B.absxk = fabs(c6_formation_ros2_B.wp[6] -
          c6_formation_ros2_B.MathFunction1[6]);
        if (c6_formation_ros2_B.absxk > c6_formation_ros2_B.scale) {
          c6_formation_ros2_B.b_t = c6_formation_ros2_B.scale /
            c6_formation_ros2_B.absxk;
          c6_formation_ros2_B.t = c6_formation_ros2_B.t *
            c6_formation_ros2_B.b_t * c6_formation_ros2_B.b_t + 1.0;
          c6_formation_ros2_B.scale = c6_formation_ros2_B.absxk;
        } else {
          c6_formation_ros2_B.b_t = c6_formation_ros2_B.absxk /
            c6_formation_ros2_B.scale;
          c6_formation_ros2_B.t += c6_formation_ros2_B.b_t *
            c6_formation_ros2_B.b_t;
        }

        c6_formation_ros2_B.t = c6_formation_ros2_B.scale * sqrt
          (c6_formation_ros2_B.t);
        if (c6_formation_ros2_B.t < c6_formation_ros2_P.end_dis) {
          c6_formation_ros2_DW.idx++;
          if (c6_formation_ros2_DW.idx > 12.0) {
            c6_formation_ros2_DW.idx = 1.0;
            c6_formation_ros2_DW.inum++;
          }
        }
      }

      if ((c6_formation_ros2_DW.inum == 2.0) && (c6_formation_ros2_DW.idx ==
           10.0)) {
        c6_formation_ros2_DW.state = 4.0;
        c6_formation_ros2_DW.idx = 2.0;
        c6_formation_ros2_DW.inum = 1.0;
        c6_formation_ros2_DW.istart = 0.0;
      }
    } else if (c6_formation_ros2_DW.state == 5.0) {
      c6_formation_ros2_DW.is_DuiXingBianHuan = c6_formation_ros2_IN_FengCao;
      memcpy(&c6_formation_ros2_B.wp[0], &wpFengChao[0], 18U * sizeof(real_T));
      for (c6_formation_ros2_B.idxFillStart = 0;
           c6_formation_ros2_B.idxFillStart < 6;
           c6_formation_ros2_B.idxFillStart++) {
        c6_formation_ros2_B.wpCircle_tmp = c6_formation_ros2_B.idxFillStart << 1;
        c6_formation_ros2_B.Uvw[c6_formation_ros2_B.wpCircle_tmp] =
          c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart] -
          fb[c6_formation_ros2_B.idxFillStart];
        c6_formation_ros2_B.Uvw[c6_formation_ros2_B.wpCircle_tmp + 1] =
          c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart + 6]
          - fb[c6_formation_ros2_B.idxFillStart + 6];
      }

      c6_formation_ros2_vecnorm(c6_formation_ros2_B.Uvw,
        c6_formation_ros2_B.dists);
      c6_formation_ros2_B.b_varargout_1 = true;
      c6_formation_ros2_B.idxFillStart = 0;
      exitg1 = false;
      while ((!exitg1) && (c6_formation_ros2_B.idxFillStart < 6)) {
        if (!(c6_formation_ros2_B.dists[c6_formation_ros2_B.idxFillStart] <
              c6_formation_ros2_P.end_dis)) {
          c6_formation_ros2_B.b_varargout_1 = false;
          exitg1 = true;
        } else {
          c6_formation_ros2_B.idxFillStart++;
        }
      }

      if (c6_formation_ros2_B.b_varargout_1) {
        for (c6_formation_ros2_B.idxFillStart = 0;
             c6_formation_ros2_B.idxFillStart < 6;
             c6_formation_ros2_B.idxFillStart++) {
          c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart] =
            c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart];
          c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 6] =
            c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart +
            6];
        }

        for (c6_formation_ros2_B.idxFillStart = 0;
             c6_formation_ros2_B.idxFillStart < 6;
             c6_formation_ros2_B.idxFillStart++) {
          c6_formation_ros2_B.scale =
            c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart +
            12];
          if (fabs(c6_formation_ros2_angdiff
                   (c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 12],
                    c6_formation_ros2_B.scale)) < c6_formation_ros2_P.end_ang) {
            c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 12] =
              c6_formation_ros2_B.scale;
          }
        }

        for (c6_formation_ros2_B.idxFillStart = 0;
             c6_formation_ros2_B.idxFillStart <= 4;
             c6_formation_ros2_B.idxFillStart += 2) {
          tmp_0 = _mm_loadu_pd
            (&c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart
             + 12]);
          tmp_1 = _mm_loadu_pd
            (&c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 12]);
          _mm_storeu_pd
            (&c6_formation_ros2_B.dists[c6_formation_ros2_B.idxFillStart],
             _mm_sub_pd(tmp_0, tmp_1));
        }

        if (c6_formation_ros2_vecnorm_m(c6_formation_ros2_B.dists) <
            c6_formation_ros2_P.end_ang) {
          if (c6_formation_ros2_DW.t0_p < 3.0) {
            c6_formation_ros2_DW.t0_p += 0.1;
          } else {
            c6_formation_ros2_DW.state = 1.0;
            c6_formation_ros2_DW.t0_p = 0.0;
          }
        }
      }
    } else {
      switch (c6_formation_ros2_DW.is_DuiXingBianHuan) {
       case c6_formation_ros2_IN_Circle:
        switch (static_cast<int32_T>(c6_formation_ros2_DW.idx)) {
         case 1:
          for (c6_formation_ros2_B.idxFillStart = 0;
               c6_formation_ros2_B.idxFillStart < 3;
               c6_formation_ros2_B.idxFillStart++) {
            c6_formation_ros2_B.wp[6 * c6_formation_ros2_B.idxFillStart] =
              wpCircle[(12 * c6_formation_ros2_B.idxFillStart +
                        static_cast<int32_T>(c6_formation_ros2_DW.idx)) - 1];
            for (c6_formation_ros2_B.wpCircle_tmp = 0;
                 c6_formation_ros2_B.wpCircle_tmp < 5;
                 c6_formation_ros2_B.wpCircle_tmp++) {
              c6_formation_ros2_B.wp[(c6_formation_ros2_B.wpCircle_tmp + 6 *
                c6_formation_ros2_B.idxFillStart) + 1] = ib[5 *
                c6_formation_ros2_B.idxFillStart +
                c6_formation_ros2_B.wpCircle_tmp];
            }
          }
          break;

         case 2:
          if (c6_formation_ros2_DW.idx < 1.0) {
            c6_formation_ros2_B.colPos = 0;
            c6_formation_ros2_B.i = 1;
            c6_formation_ros2_B.b_j = -1;
          } else {
            c6_formation_ros2_B.colPos = static_cast<int32_T>
              (c6_formation_ros2_DW.idx) - 1;
            c6_formation_ros2_B.i = -1;
            c6_formation_ros2_B.b_j = 0;
          }

          c6_formation_ros2_B.b_j = div_s32(c6_formation_ros2_B.b_j -
            c6_formation_ros2_B.colPos, c6_formation_ros2_B.i);
          for (c6_formation_ros2_B.idxFillStart = 0;
               c6_formation_ros2_B.idxFillStart < 3;
               c6_formation_ros2_B.idxFillStart++) {
            for (c6_formation_ros2_B.wpCircle_tmp = 0;
                 c6_formation_ros2_B.wpCircle_tmp <= c6_formation_ros2_B.b_j;
                 c6_formation_ros2_B.wpCircle_tmp++) {
              c6_formation_ros2_B.wpCircle_data[c6_formation_ros2_B.wpCircle_tmp
                + (c6_formation_ros2_B.b_j + 5) *
                c6_formation_ros2_B.idxFillStart] = wpCircle
                [(c6_formation_ros2_B.i * c6_formation_ros2_B.wpCircle_tmp +
                  c6_formation_ros2_B.colPos) + 12 *
                c6_formation_ros2_B.idxFillStart];
            }

            c6_formation_ros2_B.wpCircle_tmp = c6_formation_ros2_B.idxFillStart <<
              2;
            c6_formation_ros2_B.wpCircle_data[(c6_formation_ros2_B.b_j +
              (c6_formation_ros2_B.b_j + 5) * c6_formation_ros2_B.idxFillStart)
              + 1] = jb[c6_formation_ros2_B.wpCircle_tmp];
            c6_formation_ros2_B.wpCircle_data[(c6_formation_ros2_B.b_j +
              (c6_formation_ros2_B.b_j + 5) * c6_formation_ros2_B.idxFillStart)
              + 2] = jb[c6_formation_ros2_B.wpCircle_tmp + 1];
            c6_formation_ros2_B.wpCircle_data[(c6_formation_ros2_B.b_j +
              (c6_formation_ros2_B.b_j + 5) * c6_formation_ros2_B.idxFillStart)
              + 3] = jb[c6_formation_ros2_B.wpCircle_tmp + 2];
            c6_formation_ros2_B.wpCircle_data[(c6_formation_ros2_B.b_j +
              (c6_formation_ros2_B.b_j + 5) * c6_formation_ros2_B.idxFillStart)
              + 4] = jb[c6_formation_ros2_B.wpCircle_tmp + 3];
          }

          memcpy(&c6_formation_ros2_B.wp[0], &c6_formation_ros2_B.wpCircle_data
                 [0], 18U * sizeof(real_T));
          break;

         case 3:
          if (c6_formation_ros2_DW.idx < 1.0) {
            c6_formation_ros2_B.g = 0;
            c6_formation_ros2_B.i = 1;
            c6_formation_ros2_B.e = -1;
          } else {
            c6_formation_ros2_B.g = static_cast<int32_T>
              (c6_formation_ros2_DW.idx) - 1;
            c6_formation_ros2_B.i = -1;
            c6_formation_ros2_B.e = 0;
          }

          c6_formation_ros2_B.b_j = div_s32(c6_formation_ros2_B.e -
            c6_formation_ros2_B.g, c6_formation_ros2_B.i);
          for (c6_formation_ros2_B.idxFillStart = 0;
               c6_formation_ros2_B.idxFillStart < 3;
               c6_formation_ros2_B.idxFillStart++) {
            for (c6_formation_ros2_B.wpCircle_tmp = 0;
                 c6_formation_ros2_B.wpCircle_tmp <= c6_formation_ros2_B.b_j;
                 c6_formation_ros2_B.wpCircle_tmp++) {
              c6_formation_ros2_B.wpCircle_data_c[c6_formation_ros2_B.wpCircle_tmp
                + (c6_formation_ros2_B.b_j + 4) *
                c6_formation_ros2_B.idxFillStart] = wpCircle
                [(c6_formation_ros2_B.i * c6_formation_ros2_B.wpCircle_tmp +
                  c6_formation_ros2_B.g) + 12 * c6_formation_ros2_B.idxFillStart];
            }

            c6_formation_ros2_B.wpCircle_data_c[(c6_formation_ros2_B.b_j +
              (c6_formation_ros2_B.b_j + 4) * c6_formation_ros2_B.idxFillStart)
              + 1] = kb[3 * c6_formation_ros2_B.idxFillStart];
            c6_formation_ros2_B.wpCircle_data_c[(c6_formation_ros2_B.b_j +
              (c6_formation_ros2_B.b_j + 4) * c6_formation_ros2_B.idxFillStart)
              + 2] = kb[3 * c6_formation_ros2_B.idxFillStart + 1];
            c6_formation_ros2_B.wpCircle_data_c[(c6_formation_ros2_B.b_j +
              (c6_formation_ros2_B.b_j + 4) * c6_formation_ros2_B.idxFillStart)
              + 3] = kb[3 * c6_formation_ros2_B.idxFillStart + 2];
          }

          memcpy(&c6_formation_ros2_B.wp[0],
                 &c6_formation_ros2_B.wpCircle_data_c[0], 18U * sizeof(real_T));
          break;

         case 4:
          if (c6_formation_ros2_DW.idx < 1.0) {
            c6_formation_ros2_B.colPos = 0;
            c6_formation_ros2_B.i = 1;
            c6_formation_ros2_B.idxFillStart = -1;
          } else {
            c6_formation_ros2_B.colPos = static_cast<int32_T>
              (c6_formation_ros2_DW.idx) - 1;
            c6_formation_ros2_B.i = -1;
            c6_formation_ros2_B.idxFillStart = 0;
          }

          c6_formation_ros2_B.b_j = div_s32(c6_formation_ros2_B.idxFillStart -
            c6_formation_ros2_B.colPos, c6_formation_ros2_B.i);
          for (c6_formation_ros2_B.idxFillStart = 0;
               c6_formation_ros2_B.idxFillStart < 3;
               c6_formation_ros2_B.idxFillStart++) {
            for (c6_formation_ros2_B.wpCircle_tmp = 0;
                 c6_formation_ros2_B.wpCircle_tmp <= c6_formation_ros2_B.b_j;
                 c6_formation_ros2_B.wpCircle_tmp++) {
              c6_formation_ros2_B.wpCircle_data_k[c6_formation_ros2_B.wpCircle_tmp
                + (c6_formation_ros2_B.b_j + 3) *
                c6_formation_ros2_B.idxFillStart] = wpCircle
                [(c6_formation_ros2_B.i * c6_formation_ros2_B.wpCircle_tmp +
                  c6_formation_ros2_B.colPos) + 12 *
                c6_formation_ros2_B.idxFillStart];
            }

            c6_formation_ros2_B.wpCircle_tmp = c6_formation_ros2_B.idxFillStart <<
              1;
            c6_formation_ros2_B.wpCircle_data_k[(c6_formation_ros2_B.b_j +
              (c6_formation_ros2_B.b_j + 3) * c6_formation_ros2_B.idxFillStart)
              + 1] = lb[c6_formation_ros2_B.wpCircle_tmp];
            c6_formation_ros2_B.wpCircle_data_k[(c6_formation_ros2_B.b_j +
              (c6_formation_ros2_B.b_j + 3) * c6_formation_ros2_B.idxFillStart)
              + 2] = lb[c6_formation_ros2_B.wpCircle_tmp + 1];
          }

          memcpy(&c6_formation_ros2_B.wp[0],
                 &c6_formation_ros2_B.wpCircle_data_k[0], 18U * sizeof(real_T));
          break;

         case 5:
          if (c6_formation_ros2_DW.idx < 1.0) {
            c6_formation_ros2_B.i = 0;
            c6_formation_ros2_B.e = 1;
            c6_formation_ros2_B.wpCircle_tmp = -1;
          } else {
            c6_formation_ros2_B.i = static_cast<int32_T>
              (c6_formation_ros2_DW.idx) - 1;
            c6_formation_ros2_B.e = -1;
            c6_formation_ros2_B.wpCircle_tmp = 0;
          }

          c6_formation_ros2_B.b_j = div_s32(c6_formation_ros2_B.wpCircle_tmp -
            c6_formation_ros2_B.i, c6_formation_ros2_B.e);
          for (c6_formation_ros2_B.idxFillStart = 0;
               c6_formation_ros2_B.idxFillStart < 3;
               c6_formation_ros2_B.idxFillStart++) {
            for (c6_formation_ros2_B.wpCircle_tmp = 0;
                 c6_formation_ros2_B.wpCircle_tmp <= c6_formation_ros2_B.b_j;
                 c6_formation_ros2_B.wpCircle_tmp++) {
              c6_formation_ros2_B.wpCircle_data_cx[c6_formation_ros2_B.wpCircle_tmp
                + (c6_formation_ros2_B.b_j + 2) *
                c6_formation_ros2_B.idxFillStart] = wpCircle
                [(c6_formation_ros2_B.e * c6_formation_ros2_B.wpCircle_tmp +
                  c6_formation_ros2_B.i) + 12 * c6_formation_ros2_B.idxFillStart];
            }
          }

          c6_formation_ros2_B.wpCircle_data_cx[c6_formation_ros2_B.b_j + 1] =
            1.6928203230275507;
          c6_formation_ros2_B.wpCircle_data_cx[(c6_formation_ros2_B.b_j +
            c6_formation_ros2_B.b_j) + 3] = 0.59999999999999964;
          c6_formation_ros2_B.wpCircle_data_cx[(c6_formation_ros2_B.b_j +
            ((c6_formation_ros2_B.b_j + 2) << 1)) + 1] = 7.3303828583761836;
          memcpy(&c6_formation_ros2_B.wp[0],
                 &c6_formation_ros2_B.wpCircle_data_cx[0], 18U * sizeof(real_T));
          break;

         default:
          for (c6_formation_ros2_B.idxFillStart = 0;
               c6_formation_ros2_B.idxFillStart < 3;
               c6_formation_ros2_B.idxFillStart++) {
            for (c6_formation_ros2_B.wpCircle_tmp = 0;
                 c6_formation_ros2_B.wpCircle_tmp < 6;
                 c6_formation_ros2_B.wpCircle_tmp++) {
              c6_formation_ros2_B.wp[c6_formation_ros2_B.wpCircle_tmp + 6 *
                c6_formation_ros2_B.idxFillStart] = wpCircle
                [(static_cast<int32_T>(c6_formation_ros2_DW.idx -
                   static_cast<real_T>(c6_formation_ros2_B.wpCircle_tmp)) + 12 *
                  c6_formation_ros2_B.idxFillStart) - 1];
            }
          }
          break;
        }

        if (!(c6_formation_ros2_DW.istart != 0.0)) {
          for (c6_formation_ros2_B.idxFillStart = 0;
               c6_formation_ros2_B.idxFillStart < 6;
               c6_formation_ros2_B.idxFillStart++) {
            c6_formation_ros2_B.wpCircle_tmp = c6_formation_ros2_B.idxFillStart <<
              1;
            c6_formation_ros2_B.Uvw[c6_formation_ros2_B.wpCircle_tmp] =
              c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart]
              - c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart];
            c6_formation_ros2_B.Uvw[c6_formation_ros2_B.wpCircle_tmp + 1] =
              c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart
              + 6] - c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 6];
          }

          c6_formation_ros2_vecnorm(c6_formation_ros2_B.Uvw,
            c6_formation_ros2_B.dists);
          c6_formation_ros2_B.b_varargout_1 = true;
          c6_formation_ros2_B.idxFillStart = 0;
          exitg1 = false;
          while ((!exitg1) && (c6_formation_ros2_B.idxFillStart < 6)) {
            if (!(c6_formation_ros2_B.dists[c6_formation_ros2_B.idxFillStart] <
                  c6_formation_ros2_P.end_dis)) {
              c6_formation_ros2_B.b_varargout_1 = false;
              exitg1 = true;
            } else {
              c6_formation_ros2_B.idxFillStart++;
            }
          }

          if (c6_formation_ros2_B.b_varargout_1) {
            for (c6_formation_ros2_B.idxFillStart = 0;
                 c6_formation_ros2_B.idxFillStart < 6;
                 c6_formation_ros2_B.idxFillStart++) {
              c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart] =
                c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart];
              c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 6] =
                c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart
                + 6];
            }

            for (c6_formation_ros2_B.idxFillStart = 0;
                 c6_formation_ros2_B.idxFillStart < 6;
                 c6_formation_ros2_B.idxFillStart++) {
              c6_formation_ros2_B.scale =
                c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart
                + 12];
              if (fabs(c6_formation_ros2_angdiff
                       (c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart
                        + 12], c6_formation_ros2_B.scale)) <
                  c6_formation_ros2_P.end_ang) {
                c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 12] =
                  c6_formation_ros2_B.scale;
              }
            }

            for (c6_formation_ros2_B.idxFillStart = 0;
                 c6_formation_ros2_B.idxFillStart <= 4;
                 c6_formation_ros2_B.idxFillStart += 2) {
              tmp_0 = _mm_loadu_pd
                (&c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart
                 + 12]);
              tmp_1 = _mm_loadu_pd
                (&c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 12]);
              _mm_storeu_pd
                (&c6_formation_ros2_B.dists[c6_formation_ros2_B.idxFillStart],
                 _mm_sub_pd(tmp_0, tmp_1));
            }

            if (c6_formation_ros2_vecnorm_m(c6_formation_ros2_B.dists) <
                c6_formation_ros2_P.end_ang) {
              c6_formation_ros2_DW.istart = 1.0;
              c6_formation_ros2_DW.idx++;
              if (c6_formation_ros2_DW.idx > 12.0) {
                c6_formation_ros2_DW.idx = 1.0;
                c6_formation_ros2_DW.inum++;
              }
            }
          }
        } else {
          c6_formation_ros2_B.scale = 3.3121686421112381E-170;
          c6_formation_ros2_B.absxk = fabs(c6_formation_ros2_B.wp[0] -
            c6_formation_ros2_B.MathFunction1[0]);
          if (c6_formation_ros2_B.absxk > 3.3121686421112381E-170) {
            c6_formation_ros2_B.t = 1.0;
            c6_formation_ros2_B.scale = c6_formation_ros2_B.absxk;
          } else {
            c6_formation_ros2_B.b_t = c6_formation_ros2_B.absxk /
              3.3121686421112381E-170;
            c6_formation_ros2_B.t = c6_formation_ros2_B.b_t *
              c6_formation_ros2_B.b_t;
          }

          c6_formation_ros2_B.absxk = fabs(c6_formation_ros2_B.wp[6] -
            c6_formation_ros2_B.MathFunction1[6]);
          if (c6_formation_ros2_B.absxk > c6_formation_ros2_B.scale) {
            c6_formation_ros2_B.b_t = c6_formation_ros2_B.scale /
              c6_formation_ros2_B.absxk;
            c6_formation_ros2_B.t = c6_formation_ros2_B.t *
              c6_formation_ros2_B.b_t * c6_formation_ros2_B.b_t + 1.0;
            c6_formation_ros2_B.scale = c6_formation_ros2_B.absxk;
          } else {
            c6_formation_ros2_B.b_t = c6_formation_ros2_B.absxk /
              c6_formation_ros2_B.scale;
            c6_formation_ros2_B.t += c6_formation_ros2_B.b_t *
              c6_formation_ros2_B.b_t;
          }

          c6_formation_ros2_B.t = c6_formation_ros2_B.scale * sqrt
            (c6_formation_ros2_B.t);
          if (c6_formation_ros2_B.t < c6_formation_ros2_P.end_dis) {
            c6_formation_ros2_DW.idx++;
            if (c6_formation_ros2_DW.idx > 12.0) {
              c6_formation_ros2_DW.idx = 1.0;
              c6_formation_ros2_DW.inum++;
            }
          }
        }

        if ((c6_formation_ros2_DW.inum == 2.0) && (c6_formation_ros2_DW.idx ==
             10.0)) {
          c6_formation_ros2_DW.state = 4.0;
          c6_formation_ros2_DW.idx = 2.0;
          c6_formation_ros2_DW.inum = 1.0;
          c6_formation_ros2_DW.istart = 0.0;
        } else {
          c6_formation_ros2_DW.state = 3.0;
        }
        break;

       case c6_formation_ros2_IN_DuiDao:
        switch (static_cast<int32_T>(c6_formation_ros2_DW.iflag)) {
         case 0:
          memcpy(&c6_formation_ros2_B.wp[0], &cb[0], 18U * sizeof(real_T));
          break;

         case 1:
          memcpy(&c6_formation_ros2_B.wp[0], &db[0], 18U * sizeof(real_T));
          break;

         case 2:
          memcpy(&c6_formation_ros2_B.wp[0], &eb[0], 18U * sizeof(real_T));
          break;

         default:
          memcpy(&c6_formation_ros2_B.wp[0], &bb[0], 18U * sizeof(real_T));
          break;
        }

        for (c6_formation_ros2_B.idxFillStart = 0;
             c6_formation_ros2_B.idxFillStart < 6;
             c6_formation_ros2_B.idxFillStart++) {
          c6_formation_ros2_B.wpCircle_tmp = c6_formation_ros2_B.idxFillStart <<
            1;
          c6_formation_ros2_B.Uvw[c6_formation_ros2_B.wpCircle_tmp] =
            c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart]
            - c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart];
          c6_formation_ros2_B.Uvw[c6_formation_ros2_B.wpCircle_tmp + 1] =
            c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart +
            6] - c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 6];
        }

        c6_formation_ros2_vecnorm(c6_formation_ros2_B.Uvw,
          c6_formation_ros2_B.dists);
        c6_formation_ros2_B.b_varargout_1 = true;
        c6_formation_ros2_B.idxFillStart = 0;
        exitg1 = false;
        while ((!exitg1) && (c6_formation_ros2_B.idxFillStart < 6)) {
          if (!(c6_formation_ros2_B.dists[c6_formation_ros2_B.idxFillStart] <
                c6_formation_ros2_P.end_dis)) {
            c6_formation_ros2_B.b_varargout_1 = false;
            exitg1 = true;
          } else {
            c6_formation_ros2_B.idxFillStart++;
          }
        }

        if (c6_formation_ros2_B.b_varargout_1) {
          for (c6_formation_ros2_B.idxFillStart = 0;
               c6_formation_ros2_B.idxFillStart < 6;
               c6_formation_ros2_B.idxFillStart++) {
            c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart] =
              c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart];
            c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 6] =
              c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart
              + 6];
          }

          for (c6_formation_ros2_B.idxFillStart = 0;
               c6_formation_ros2_B.idxFillStart < 6;
               c6_formation_ros2_B.idxFillStart++) {
            c6_formation_ros2_B.scale =
              c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart
              + 12];
            if (fabs(c6_formation_ros2_angdiff
                     (c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart +
                      12], c6_formation_ros2_B.scale)) <
                c6_formation_ros2_P.end_ang) {
              c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 12] =
                c6_formation_ros2_B.scale;
            }
          }

          for (c6_formation_ros2_B.idxFillStart = 0;
               c6_formation_ros2_B.idxFillStart <= 4;
               c6_formation_ros2_B.idxFillStart += 2) {
            tmp_0 = _mm_loadu_pd
              (&c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart
               + 12]);
            tmp_1 = _mm_loadu_pd
              (&c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 12]);
            _mm_storeu_pd
              (&c6_formation_ros2_B.dists[c6_formation_ros2_B.idxFillStart],
               _mm_sub_pd(tmp_0, tmp_1));
          }

          if (c6_formation_ros2_vecnorm_m(c6_formation_ros2_B.dists) <
              c6_formation_ros2_P.end_ang) {
            c6_formation_ros2_DW.iflag++;
            if (c6_formation_ros2_DW.iflag > 3.0) {
              c6_formation_ros2_DW.iflag = 0.0;
              c6_formation_ros2_DW.inum_g++;
            }
          }
        }

        if ((c6_formation_ros2_DW.inum_g == 3.0) && (c6_formation_ros2_DW.iflag ==
             1.0)) {
          c6_formation_ros2_DW.state = 5.0;
          c6_formation_ros2_DW.inum_g = 1.0;
          c6_formation_ros2_DW.iflag = 2.0;
        } else {
          c6_formation_ros2_DW.state = 4.0;
        }
        break;

       case c6_formation_ros2_IN_FengCao:
        memcpy(&c6_formation_ros2_B.wp[0], &wpFengChao[0], 18U * sizeof(real_T));
        for (c6_formation_ros2_B.idxFillStart = 0;
             c6_formation_ros2_B.idxFillStart < 6;
             c6_formation_ros2_B.idxFillStart++) {
          c6_formation_ros2_B.wpCircle_tmp = c6_formation_ros2_B.idxFillStart <<
            1;
          c6_formation_ros2_B.Uvw[c6_formation_ros2_B.wpCircle_tmp] =
            c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart]
            - fb[c6_formation_ros2_B.idxFillStart];
          c6_formation_ros2_B.Uvw[c6_formation_ros2_B.wpCircle_tmp + 1] =
            c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart +
            6] - fb[c6_formation_ros2_B.idxFillStart + 6];
        }

        c6_formation_ros2_vecnorm(c6_formation_ros2_B.Uvw,
          c6_formation_ros2_B.dists);
        c6_formation_ros2_B.b_varargout_1 = true;
        c6_formation_ros2_B.idxFillStart = 0;
        exitg1 = false;
        while ((!exitg1) && (c6_formation_ros2_B.idxFillStart < 6)) {
          if (!(c6_formation_ros2_B.dists[c6_formation_ros2_B.idxFillStart] <
                c6_formation_ros2_P.end_dis)) {
            c6_formation_ros2_B.b_varargout_1 = false;
            exitg1 = true;
          } else {
            c6_formation_ros2_B.idxFillStart++;
          }
        }

        if (c6_formation_ros2_B.b_varargout_1) {
          for (c6_formation_ros2_B.idxFillStart = 0;
               c6_formation_ros2_B.idxFillStart < 6;
               c6_formation_ros2_B.idxFillStart++) {
            c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart] =
              c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart];
            c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 6] =
              c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart
              + 6];
          }

          for (c6_formation_ros2_B.g = 0; c6_formation_ros2_B.g < 6;
               c6_formation_ros2_B.g++) {
            c6_formation_ros2_B.scale =
              c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.g + 12];
            if (fabs(c6_formation_ros2_angdiff
                     (c6_formation_ros2_B.wp[c6_formation_ros2_B.g + 12],
                      c6_formation_ros2_B.scale)) < c6_formation_ros2_P.end_ang)
            {
              c6_formation_ros2_B.wp[c6_formation_ros2_B.g + 12] =
                c6_formation_ros2_B.scale;
            }
          }

          for (c6_formation_ros2_B.idxFillStart = 0;
               c6_formation_ros2_B.idxFillStart <= 4;
               c6_formation_ros2_B.idxFillStart += 2) {
            tmp_0 = _mm_loadu_pd
              (&c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart
               + 12]);
            tmp_1 = _mm_loadu_pd
              (&c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 12]);
            _mm_storeu_pd
              (&c6_formation_ros2_B.dists[c6_formation_ros2_B.idxFillStart],
               _mm_sub_pd(tmp_0, tmp_1));
          }

          if (c6_formation_ros2_vecnorm_m(c6_formation_ros2_B.dists) <
              c6_formation_ros2_P.end_ang) {
            if (c6_formation_ros2_DW.t0_p < 3.0) {
              c6_formation_ros2_DW.state = 5.0;
              c6_formation_ros2_DW.t0_p += 0.1;
            } else {
              c6_formation_ros2_DW.state = 1.0;
              c6_formation_ros2_DW.t0_p = 0.0;
            }
          } else {
            c6_formation_ros2_DW.state = 5.0;
          }
        } else {
          c6_formation_ros2_DW.state = 5.0;
        }
        break;

       case c6_formation_ros2_IN_LieDui:
        memcpy(&c6_formation_ros2_B.wp[0], &wplieDui[0], 18U * sizeof(real_T));
        for (c6_formation_ros2_B.idxFillStart = 0;
             c6_formation_ros2_B.idxFillStart < 6;
             c6_formation_ros2_B.idxFillStart++) {
          c6_formation_ros2_B.wpCircle_tmp = c6_formation_ros2_B.idxFillStart <<
            1;
          c6_formation_ros2_B.Uvw[c6_formation_ros2_B.wpCircle_tmp] =
            c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart]
            - gb[c6_formation_ros2_B.idxFillStart];
          c6_formation_ros2_B.Uvw[c6_formation_ros2_B.wpCircle_tmp + 1] =
            c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart +
            6] - gb[c6_formation_ros2_B.idxFillStart + 6];
        }

        c6_formation_ros2_vecnorm(c6_formation_ros2_B.Uvw,
          c6_formation_ros2_B.dists);
        c6_formation_ros2_B.b_varargout_1 = true;
        c6_formation_ros2_B.idxFillStart = 0;
        exitg1 = false;
        while ((!exitg1) && (c6_formation_ros2_B.idxFillStart < 6)) {
          if (!(c6_formation_ros2_B.dists[c6_formation_ros2_B.idxFillStart] <
                c6_formation_ros2_P.end_dis)) {
            c6_formation_ros2_B.b_varargout_1 = false;
            exitg1 = true;
          } else {
            c6_formation_ros2_B.idxFillStart++;
          }
        }

        if (c6_formation_ros2_B.b_varargout_1) {
          for (c6_formation_ros2_B.idxFillStart = 0;
               c6_formation_ros2_B.idxFillStart < 6;
               c6_formation_ros2_B.idxFillStart++) {
            c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart] =
              c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart];
            c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 6] =
              c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart
              + 6];
          }

          for (c6_formation_ros2_B.idxFillStart = 0;
               c6_formation_ros2_B.idxFillStart < 6;
               c6_formation_ros2_B.idxFillStart++) {
            c6_formation_ros2_B.scale =
              c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart
              + 12];
            if (fabs(c6_formation_ros2_angdiff
                     (c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart +
                      12], c6_formation_ros2_B.scale)) <
                c6_formation_ros2_P.end_ang) {
              c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 12] =
                c6_formation_ros2_B.scale;
            }
          }

          for (c6_formation_ros2_B.idxFillStart = 0;
               c6_formation_ros2_B.idxFillStart <= 4;
               c6_formation_ros2_B.idxFillStart += 2) {
            tmp_0 = _mm_loadu_pd
              (&c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart
               + 12]);
            tmp_1 = _mm_loadu_pd
              (&c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 12]);
            _mm_storeu_pd
              (&c6_formation_ros2_B.dists[c6_formation_ros2_B.idxFillStart],
               _mm_sub_pd(tmp_0, tmp_1));
          }

          if (c6_formation_ros2_vecnorm_m(c6_formation_ros2_B.dists) <
              c6_formation_ros2_P.end_ang) {
            if (c6_formation_ros2_DW.t0_c < 3.0) {
              c6_formation_ros2_DW.state = 2.0;
              c6_formation_ros2_DW.t0_c += 0.1;
            } else {
              c6_formation_ros2_DW.state = 3.0;
              c6_formation_ros2_DW.t0_c = 0.0;
            }
          } else {
            c6_formation_ros2_DW.state = 2.0;
          }
        } else {
          c6_formation_ros2_DW.state = 2.0;
        }
        break;

       case c6_formation_ros2_IN_SanKai:
        memcpy(&c6_formation_ros2_B.wp[0], &wpSanKai[0], 18U * sizeof(real_T));
        for (c6_formation_ros2_B.idxFillStart = 0;
             c6_formation_ros2_B.idxFillStart < 6;
             c6_formation_ros2_B.idxFillStart++) {
          c6_formation_ros2_B.wpCircle_tmp = c6_formation_ros2_B.idxFillStart <<
            1;
          c6_formation_ros2_B.Uvw[c6_formation_ros2_B.wpCircle_tmp] =
            c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart]
            - hb[c6_formation_ros2_B.idxFillStart];
          c6_formation_ros2_B.Uvw[c6_formation_ros2_B.wpCircle_tmp + 1] =
            c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart +
            6] - hb[c6_formation_ros2_B.idxFillStart + 6];
        }

        c6_formation_ros2_vecnorm(c6_formation_ros2_B.Uvw,
          c6_formation_ros2_B.dists);
        c6_formation_ros2_B.b_varargout_1 = true;
        c6_formation_ros2_B.idxFillStart = 0;
        exitg1 = false;
        while ((!exitg1) && (c6_formation_ros2_B.idxFillStart < 6)) {
          if (!(c6_formation_ros2_B.dists[c6_formation_ros2_B.idxFillStart] <
                c6_formation_ros2_P.end_dis)) {
            c6_formation_ros2_B.b_varargout_1 = false;
            exitg1 = true;
          } else {
            c6_formation_ros2_B.idxFillStart++;
          }
        }

        if (c6_formation_ros2_B.b_varargout_1) {
          for (c6_formation_ros2_B.idxFillStart = 0;
               c6_formation_ros2_B.idxFillStart < 6;
               c6_formation_ros2_B.idxFillStart++) {
            c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart] =
              c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart];
            c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 6] =
              c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart
              + 6];
          }

          for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i < 6;
               c6_formation_ros2_B.i++) {
            c6_formation_ros2_B.scale =
              c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.i + 12];
            if (fabs(c6_formation_ros2_angdiff
                     (c6_formation_ros2_B.wp[c6_formation_ros2_B.i + 12],
                      c6_formation_ros2_B.scale)) < c6_formation_ros2_P.end_ang)
            {
              c6_formation_ros2_B.wp[c6_formation_ros2_B.i + 12] =
                c6_formation_ros2_B.scale;
            }
          }

          for (c6_formation_ros2_B.idxFillStart = 0;
               c6_formation_ros2_B.idxFillStart <= 4;
               c6_formation_ros2_B.idxFillStart += 2) {
            tmp_0 = _mm_loadu_pd
              (&c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.idxFillStart
               + 12]);
            tmp_1 = _mm_loadu_pd
              (&c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 12]);
            _mm_storeu_pd
              (&c6_formation_ros2_B.dists[c6_formation_ros2_B.idxFillStart],
               _mm_sub_pd(tmp_0, tmp_1));
          }

          if (c6_formation_ros2_vecnorm_m(c6_formation_ros2_B.dists) <
              c6_formation_ros2_P.end_ang) {
            if (c6_formation_ros2_DW.t0 < 3.0) {
              c6_formation_ros2_DW.state = 1.0;
              c6_formation_ros2_DW.t0 += 0.1;
            } else {
              c6_formation_ros2_DW.state = 2.0;
              c6_formation_ros2_DW.t0 = 0.0;
            }
          } else {
            c6_formation_ros2_DW.state = 1.0;
          }
        } else {
          c6_formation_ros2_DW.state = 1.0;
        }
        break;

       default:
        // case IN_default:
        break;
      }
    }
  } else {
    // case IN_Init:
    c6_formation_ros2_DW.is_c39_c6_formation_ros2 =
      c6_formation_IN_DuiXingBianHuan;
    c6_formation_ros2_DW.is_DuiXingBianHuan = c6_formation_ros2_IN_default;
  }

  // End of Chart: '<Root>/Chart'

  // Reshape: '<S3>/Reshape1'
  c6_formation_ros2_B.Reshape1[0] = c6_formation_ros2_DW.Memory2_PreviousInput[0];
  c6_formation_ros2_B.Reshape1[3] =
    c6_formation_ros2_DW.Memory2_PreviousInput_p[0];
  c6_formation_ros2_B.Reshape1[6] =
    c6_formation_ros2_DW.Memory2_PreviousInput_d[0];
  c6_formation_ros2_B.Reshape1[9] =
    c6_formation_ros2_DW.Memory2_PreviousInput_e[0];
  c6_formation_ros2_B.Reshape1[12] =
    c6_formation_ros2_DW.Memory2_PreviousInput_k[0];
  c6_formation_ros2_B.Reshape1[15] =
    c6_formation_ros2_DW.Memory2_PreviousInput_o[0];
  c6_formation_ros2_B.Reshape1[1] = c6_formation_ros2_DW.Memory2_PreviousInput[1];
  c6_formation_ros2_B.Reshape1[4] =
    c6_formation_ros2_DW.Memory2_PreviousInput_p[1];
  c6_formation_ros2_B.Reshape1[7] =
    c6_formation_ros2_DW.Memory2_PreviousInput_d[1];
  c6_formation_ros2_B.Reshape1[10] =
    c6_formation_ros2_DW.Memory2_PreviousInput_e[1];
  c6_formation_ros2_B.Reshape1[13] =
    c6_formation_ros2_DW.Memory2_PreviousInput_k[1];
  c6_formation_ros2_B.Reshape1[16] =
    c6_formation_ros2_DW.Memory2_PreviousInput_o[1];
  c6_formation_ros2_B.Reshape1[2] = c6_formation_ros2_DW.Memory2_PreviousInput[2];
  c6_formation_ros2_B.Reshape1[5] =
    c6_formation_ros2_DW.Memory2_PreviousInput_p[2];
  c6_formation_ros2_B.Reshape1[8] =
    c6_formation_ros2_DW.Memory2_PreviousInput_d[2];
  c6_formation_ros2_B.Reshape1[11] =
    c6_formation_ros2_DW.Memory2_PreviousInput_e[2];
  c6_formation_ros2_B.Reshape1[14] =
    c6_formation_ros2_DW.Memory2_PreviousInput_k[2];
  c6_formation_ros2_B.Reshape1[17] =
    c6_formation_ros2_DW.Memory2_PreviousInput_o[2];
  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       6; c6_formation_ros2_B.idxFillStart++) {
    // Math: '<Root>/Math Function' incorporates:
    //   MATLAB Function: '<S3>/uni_barrier_cert'

    c6_formation_ros2_B.scale =
      c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart];
    c6_formation_ros2_B.MathFunction1[3 * c6_formation_ros2_B.idxFillStart] =
      c6_formation_ros2_B.scale;
    c6_formation_ros2_B.absxk =
      c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 6];
    c6_formation_ros2_B.wpCircle_tmp = 3 * c6_formation_ros2_B.idxFillStart + 1;
    c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.wpCircle_tmp] =
      c6_formation_ros2_B.absxk;
    c6_formation_ros2_B.MathFunction1[3 * c6_formation_ros2_B.idxFillStart + 2] =
      c6_formation_ros2_B.wp[c6_formation_ros2_B.idxFillStart + 12];

    // MATLAB Function: '<S3>/uni_barrier_cert' incorporates:
    //   Reshape: '<S3>/Reshape1'

    c6_formation_ros2_B.b_j = c6_formation_ros2_B.idxFillStart << 1;
    c6_formation_ros2_B.Uvw[c6_formation_ros2_B.b_j] = c6_formation_ros2_B.scale
      - c6_formation_ros2_B.Reshape1[3 * c6_formation_ros2_B.idxFillStart];
    c6_formation_ros2_B.Uvw[c6_formation_ros2_B.b_j + 1] =
      c6_formation_ros2_B.absxk -
      c6_formation_ros2_B.Reshape1[c6_formation_ros2_B.wpCircle_tmp];
  }

  // MATLAB Function: '<S3>/uni_barrier_cert'
  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       6; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.wpCircle_tmp = c6_formation_ros2_B.idxFillStart << 1;
    c6_formation_ros2_B.scale =
      c6_formation_ros2_B.Uvw[c6_formation_ros2_B.wpCircle_tmp + 1];
    c6_formation_ros2_B.absxk =
      c6_formation_ros2_B.Uvw[c6_formation_ros2_B.wpCircle_tmp];
    c6_formation_ros2_B.Uxy[c6_formation_ros2_B.wpCircle_tmp] =
      c6_formation_ros2_B.scale * 0.0 + c6_formation_ros2_B.absxk *
      c6_formation_ros2_P.x_vel_gain;
    c6_formation_ros2_B.Uxy[c6_formation_ros2_B.wpCircle_tmp + 1] =
      c6_formation_ros2_B.scale * c6_formation_ros2_P.y_vel_gain +
      c6_formation_ros2_B.absxk * 0.0;
  }

  for (c6_formation_ros2_B.wpCircle_tmp = 0; c6_formation_ros2_B.wpCircle_tmp <
       6; c6_formation_ros2_B.wpCircle_tmp++) {
    c6_formation_ros2_B.b_j = (c6_formation_ros2_B.wpCircle_tmp << 1) + 1;
    c6_formation_ros2_B.b_t = 0.0;
    c6_formation_ros2_B.scale = 3.3121686421112381E-170;
    for (c6_formation_ros2_B.idxFillStart = c6_formation_ros2_B.b_j;
         c6_formation_ros2_B.idxFillStart <= c6_formation_ros2_B.b_j + 1;
         c6_formation_ros2_B.idxFillStart++) {
      c6_formation_ros2_B.absxk = fabs
        (c6_formation_ros2_B.Uxy[c6_formation_ros2_B.idxFillStart - 1]);
      if (c6_formation_ros2_B.absxk > c6_formation_ros2_B.scale) {
        c6_formation_ros2_B.t = c6_formation_ros2_B.scale /
          c6_formation_ros2_B.absxk;
        c6_formation_ros2_B.b_t = c6_formation_ros2_B.b_t *
          c6_formation_ros2_B.t * c6_formation_ros2_B.t + 1.0;
        c6_formation_ros2_B.scale = c6_formation_ros2_B.absxk;
      } else {
        c6_formation_ros2_B.t = c6_formation_ros2_B.absxk /
          c6_formation_ros2_B.scale;
        c6_formation_ros2_B.b_t += c6_formation_ros2_B.t * c6_formation_ros2_B.t;
      }
    }

    c6_formation_ros2_B.dists[c6_formation_ros2_B.wpCircle_tmp] =
      c6_formation_ros2_B.scale * sqrt(c6_formation_ros2_B.b_t);
  }

  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       6; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.to_normalize[c6_formation_ros2_B.idxFillStart] =
      (c6_formation_ros2_B.dists[c6_formation_ros2_B.idxFillStart] >
       c6_formation_ros2_P.velocity_magnitude_limit);
  }

  c6_formation_ros2_B.idxFillStart = 0;
  for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i < 6;
       c6_formation_ros2_B.i++) {
    // MATLAB Function: '<S3>/uni_barrier_cert'
    if (c6_formation_ros2_B.to_normalize[c6_formation_ros2_B.i]) {
      c6_formation_ros2_B.idxFillStart++;
    }
  }

  // MATLAB Function: '<S3>/uni_barrier_cert' incorporates:
  //   Reshape: '<S3>/Reshape1'

  if (c6_formation_ros2_B.idxFillStart != 0) {
    c6_formation_ros2_B.idxFillStart = 0;
    for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i < 6;
         c6_formation_ros2_B.i++) {
      if (c6_formation_ros2_B.to_normalize[c6_formation_ros2_B.i]) {
        c6_formation_ros2_B.idxFillStart++;
      }
    }

    c6_formation_ros2_B.colPos = c6_formation_ros2_B.idxFillStart;
    c6_formation_ros2_B.idxFillStart = 0;
    for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i < 6;
         c6_formation_ros2_B.i++) {
      if (c6_formation_ros2_B.to_normalize[c6_formation_ros2_B.i]) {
        c6_formation_ros2_B.tmp_data[c6_formation_ros2_B.idxFillStart] =
          static_cast<int8_T>(c6_formation_ros2_B.i);
        c6_formation_ros2_B.idxFillStart++;
      }
    }

    for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
         c6_formation_ros2_B.colPos; c6_formation_ros2_B.idxFillStart++) {
      c6_formation_ros2_B.wpCircle_tmp =
        c6_formation_ros2_B.tmp_data[c6_formation_ros2_B.idxFillStart];
      c6_formation_ros2_B.i = c6_formation_ros2_B.wpCircle_tmp << 1;
      c6_formation_ros2_B.Uvw[c6_formation_ros2_B.idxFillStart << 1] =
        c6_formation_ros2_B.Uxy[c6_formation_ros2_B.i] *
        c6_formation_ros2_P.velocity_magnitude_limit /
        c6_formation_ros2_B.dists[c6_formation_ros2_B.wpCircle_tmp];
      c6_formation_ros2_B.Uvw[1 + (c6_formation_ros2_B.idxFillStart << 1)] =
        c6_formation_ros2_B.Uxy[c6_formation_ros2_B.i + 1] *
        c6_formation_ros2_P.velocity_magnitude_limit /
        c6_formation_ros2_B.dists[c6_formation_ros2_B.wpCircle_tmp];
    }

    for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
         c6_formation_ros2_B.colPos; c6_formation_ros2_B.idxFillStart++) {
      c6_formation_ros2_B.wpCircle_tmp =
        c6_formation_ros2_B.tmp_data[c6_formation_ros2_B.idxFillStart] << 1;
      c6_formation_ros2_B.Uxy[c6_formation_ros2_B.wpCircle_tmp] =
        c6_formation_ros2_B.Uvw[c6_formation_ros2_B.idxFillStart << 1];
      c6_formation_ros2_B.Uxy[c6_formation_ros2_B.wpCircle_tmp + 1] =
        c6_formation_ros2_B.Uvw[(c6_formation_ros2_B.idxFillStart << 1) + 1];
    }
  }

  memset(&c6_formation_ros2_B.Aineq[0], 0, 468U * sizeof(real_T));
  memset(&c6_formation_ros2_B.b_x[0], 0, 39U * sizeof(real_T));
  c6_formation_ros2_B.scale = 1.0;
  for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i < 5;
       c6_formation_ros2_B.i++) {
    c6_formation_ros2_B.b_j = 4 - c6_formation_ros2_B.i;
    c6_formation_ros2_B.idxFillStart = (c6_formation_ros2_B.i + 1) << 1;
    for (c6_formation_ros2_B.g = 0; c6_formation_ros2_B.g <=
         c6_formation_ros2_B.b_j; c6_formation_ros2_B.g++) {
      c6_formation_ros2_B.colPos = c6_formation_ros2_B.i + c6_formation_ros2_B.g;
      c6_formation_ros2_B.wpCircle_tmp = (c6_formation_ros2_B.colPos + 1) * 3;
      c6_formation_ros2_B.b_x_c[0] = c6_formation_ros2_B.Reshape1[3 *
        c6_formation_ros2_B.i] -
        c6_formation_ros2_B.Reshape1[c6_formation_ros2_B.wpCircle_tmp];
      c6_formation_ros2_B.b_x_c[1] = c6_formation_ros2_B.Reshape1[3 *
        c6_formation_ros2_B.i + 1] -
        c6_formation_ros2_B.Reshape1[c6_formation_ros2_B.wpCircle_tmp + 1];
      c6_formation_ros2_B.absxk = c6_formation_ros2_norm
        (c6_formation_ros2_B.b_x_c);
      c6_formation_ros2_B.absxk = c6_formation_ros2_B.absxk *
        c6_formation_ros2_B.absxk - c6_formation_ros2_P.safety_radius *
        c6_formation_ros2_P.safety_radius;
      c6_formation_ros2_B.e = static_cast<int32_T>(c6_formation_ros2_B.scale +
        static_cast<real_T>(c6_formation_ros2_B.g));
      c6_formation_ros2_B.Aineq[(c6_formation_ros2_B.e + 39 *
        (c6_formation_ros2_B.idxFillStart - 2)) - 1] = -2.0 *
        c6_formation_ros2_B.b_x_c[0];
      c6_formation_ros2_B.Aineq[(c6_formation_ros2_B.e + 39 *
        (c6_formation_ros2_B.idxFillStart - 1)) - 1] = -2.0 *
        c6_formation_ros2_B.b_x_c[1];
      c6_formation_ros2_B.wpCircle_tmp = (c6_formation_ros2_B.colPos + 2) << 1;
      c6_formation_ros2_B.Aineq[(c6_formation_ros2_B.e + 39 *
        (c6_formation_ros2_B.wpCircle_tmp - 2)) - 1] = 2.0 *
        c6_formation_ros2_B.b_x_c[0];
      c6_formation_ros2_B.Aineq[(c6_formation_ros2_B.e + 39 *
        (c6_formation_ros2_B.wpCircle_tmp - 1)) - 1] = 2.0 *
        c6_formation_ros2_B.b_x_c[1];
      if (c6_formation_ros2_B.absxk < 0.0) {
        c6_formation_ros2_B.b_x[c6_formation_ros2_B.e - 1] = 100.0 *
          c6_formation_ros2_P.gamma * rt_powd_snf(c6_formation_ros2_B.absxk, 3.0);
      } else {
        c6_formation_ros2_B.b_x[c6_formation_ros2_B.e - 1] =
          c6_formation_ros2_P.gamma * rt_powd_snf(c6_formation_ros2_B.absxk, 3.0);
      }
    }

    c6_formation_ros2_B.scale += static_cast<real_T>(4 - c6_formation_ros2_B.i)
      + 1.0;
  }

  for (c6_formation_ros2_B.wpCircle_tmp = 0; c6_formation_ros2_B.wpCircle_tmp <
       6; c6_formation_ros2_B.wpCircle_tmp++) {
    c6_formation_ros2_B.idxFillStart = (c6_formation_ros2_B.wpCircle_tmp + 1) <<
      1;
    c6_formation_ros2_B.b_t = static_cast<real_T>
      (c6_formation_ros2_B.wpCircle_tmp) * 4.0 + c6_formation_ros2_B.scale;
    c6_formation_ros2_B.b_j = (c6_formation_ros2_B.idxFillStart - 2) * 39;
    c6_formation_ros2_B.Aineq[(static_cast<int32_T>(c6_formation_ros2_B.b_t) +
      c6_formation_ros2_B.b_j) - 1] = 0.0;
    c6_formation_ros2_B.idxFillStart = (c6_formation_ros2_B.idxFillStart - 1) *
      39;
    c6_formation_ros2_B.Aineq[(static_cast<int32_T>(c6_formation_ros2_B.b_t) +
      c6_formation_ros2_B.idxFillStart) - 1] = 1.0;
    c6_formation_ros2_B.absxk = c6_formation_ros2_B.Reshape1[3 *
      c6_formation_ros2_B.wpCircle_tmp + 1];
    c6_formation_ros2_B.t = 2.15 - c6_formation_ros2_P.safety_radius / 2.0;
    c6_formation_ros2_B.b_x[static_cast<int32_T>(c6_formation_ros2_B.b_t) - 1] =
      rt_powd_snf(c6_formation_ros2_B.t - c6_formation_ros2_B.absxk, 3.0) * (0.4
      * c6_formation_ros2_P.gamma);
    c6_formation_ros2_B.Aineq[(static_cast<int32_T>(c6_formation_ros2_B.b_t +
      1.0) + c6_formation_ros2_B.b_j) - 1] = 0.0;
    c6_formation_ros2_B.Aineq[(static_cast<int32_T>(c6_formation_ros2_B.b_t +
      1.0) + c6_formation_ros2_B.idxFillStart) - 1] = -1.0;
    c6_formation_ros2_B.usinpsi_k = 0.15 - c6_formation_ros2_P.safety_radius /
      2.0;
    c6_formation_ros2_B.b_x[static_cast<int32_T>(c6_formation_ros2_B.b_t + 1.0)
      - 1] = rt_powd_snf(c6_formation_ros2_B.usinpsi_k +
                         c6_formation_ros2_B.absxk, 3.0) * (0.4 *
      c6_formation_ros2_P.gamma);
    c6_formation_ros2_B.Aineq[(static_cast<int32_T>((c6_formation_ros2_B.b_t +
      1.0) + 1.0) + c6_formation_ros2_B.b_j) - 1] = 1.0;
    c6_formation_ros2_B.Aineq[(static_cast<int32_T>((c6_formation_ros2_B.b_t +
      1.0) + 1.0) + c6_formation_ros2_B.idxFillStart) - 1] = 0.0;
    c6_formation_ros2_B.absxk = c6_formation_ros2_B.Reshape1[3 *
      c6_formation_ros2_B.wpCircle_tmp];
    c6_formation_ros2_B.b_x[static_cast<int32_T>((c6_formation_ros2_B.b_t + 1.0)
      + 1.0) - 1] = rt_powd_snf(c6_formation_ros2_B.t -
      c6_formation_ros2_B.absxk, 3.0) * (0.4 * c6_formation_ros2_P.gamma);
    c6_formation_ros2_B.Aineq[(static_cast<int32_T>(((c6_formation_ros2_B.b_t +
      1.0) + 1.0) + 1.0) + c6_formation_ros2_B.b_j) - 1] = -1.0;
    c6_formation_ros2_B.Aineq[(static_cast<int32_T>(((c6_formation_ros2_B.b_t +
      1.0) + 1.0) + 1.0) + c6_formation_ros2_B.idxFillStart) - 1] = 0.0;
    c6_formation_ros2_B.b_x[static_cast<int32_T>(((c6_formation_ros2_B.b_t + 1.0)
      + 1.0) + 1.0) - 1] = rt_powd_snf(c6_formation_ros2_B.usinpsi_k +
      c6_formation_ros2_B.absxk, 3.0) * (0.4 * c6_formation_ros2_P.gamma);
  }

  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <=
       10; c6_formation_ros2_B.idxFillStart += 2) {
    // MATLAB Function: '<S3>/uni_barrier_cert'
    tmp_0 = _mm_loadu_pd
      (&c6_formation_ros2_B.Uxy[c6_formation_ros2_B.idxFillStart]);
    _mm_storeu_pd(&c6_formation_ros2_B.Uvw[c6_formation_ros2_B.idxFillStart],
                  _mm_mul_pd(_mm_set1_pd(-2.0), tmp_0));
  }

  // MATLAB Function: '<S3>/uni_barrier_cert' incorporates:
  //   Math: '<Root>/Math Function'
  //   Reshape: '<S3>/Reshape1'

  c6_formation_ros2_B.solution.fstar = 0.0;
  c6_formation_ros2_B.solution.firstorderopt = 0.0;
  memset(&c6_formation_ros2_B.solution.lambda[0], 0, sizeof(real_T) << 6U);
  c6_formation_ros2_B.solution.state = 0;
  c6_formation_ros2_B.solution.maxConstr = 0.0;
  c6_formation_ros2_B.solution.iterations = 0;
  memset(&c6_formation_ros2_B.solution.searchDir[0], 0, 13U * sizeof(real_T));
  memcpy(&c6_formation_ros2_B.solution.xstar[0], &c6_formation_ros2_B.Uxy[0],
         12U * sizeof(real_T));
  c6_formation_ros2_B.CholRegManager.ldm = 13;
  c6_formation_ros2_B.CholRegManager.ndims = 0;
  c6_formation_ros2_B.CholRegManager.info = 0;
  c6_formation_ros2_B.CholRegManager.ConvexCheck = true;
  c6_formation_ros2_B.CholRegManager.regTol_ = 0.0;
  c6_formation_ros2_B.CholRegManager.scaleFactor = 100.0;
  c6_formation_ros2_B.WorkingSet.nVar = 12;
  c6_formation_ros2_B.WorkingSet.nVarOrig = 12;
  c6_formation_ros2_B.WorkingSet.nVarMax = 13;
  c6_formation_ros2_B.WorkingSet.ldA = 13;
  memset(&c6_formation_ros2_B.WorkingSet.Aineq[0], 0, 507U * sizeof(real_T));
  memset(&c6_formation_ros2_B.WorkingSet.bineq[0], 0, 39U * sizeof(real_T));
  memset(&c6_formation_ros2_B.WorkingSet.lb[0], 0, 13U * sizeof(real_T));
  memset(&c6_formation_ros2_B.WorkingSet.ub[0], 0, 13U * sizeof(real_T));
  c6_formation_ros2_B.WorkingSet.mEqRemoved = 0;
  memset(&c6_formation_ros2_B.WorkingSet.ATwset[0], 0, 832U * sizeof(real_T));
  c6_formation_ros2_B.WorkingSet.nActiveConstr = 0;
  memset(&c6_formation_ros2_B.WorkingSet.bwset[0], 0, sizeof(real_T) << 6U);
  memset(&c6_formation_ros2_B.WorkingSet.maxConstrWorkspace[0], 0, sizeof(real_T)
         << 6U);
  memset(&c6_formation_ros2_B.WorkingSet.isActiveConstr[0], 0, sizeof(boolean_T)
         << 6U);
  memset(&c6_formation_ros2_B.WorkingSet.Wid[0], 0, sizeof(int32_T) << 6U);
  memset(&c6_formation_ros2_B.WorkingSet.Wlocalidx[0], 0, sizeof(int32_T) << 6U);
  for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i < 5;
       c6_formation_ros2_B.i++) {
    c6_formation_ros2_B.WorkingSet.nWConstr[c6_formation_ros2_B.i] = 0;
  }

  c6_formation_ros2_B.WorkingSet.probType = 3;
  c6_formation_ros2_B.WorkingSet.SLACK0 = 1.0E-5;
  for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i < 13;
       c6_formation_ros2_B.i++) {
    c6_formation_ros2_B.WorkingSet.indexLB[c6_formation_ros2_B.i] = 0;
    c6_formation_ros2_B.WorkingSet.indexUB[c6_formation_ros2_B.i] = 0;
    c6_formation_ros2_B.WorkingSet.indexFixed[c6_formation_ros2_B.i] = 0;
  }

  c6_formation_ros2_B.wpCircle_tmp = 39;
  c6_formation_ros2_B.b_j = 0;
  c6_formation_ros2_B.i = 0;
  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       12; c6_formation_ros2_B.idxFillStart++) {
    guard1 = false;
    if ((!rtIsInf(-c6_formation_ros2_P.velocity_magnitude_limit)) && (!rtIsNaN
         (-c6_formation_ros2_P.velocity_magnitude_limit))) {
      if (fabs(-c6_formation_ros2_P.velocity_magnitude_limit -
               c6_formation_ros2_P.velocity_magnitude_limit) < 1.0E-8) {
        c6_formation_ros2_B.i++;
        c6_formation_ros2_B.WorkingSet.indexFixed[c6_formation_ros2_B.i - 1] =
          c6_formation_ros2_B.idxFillStart + 1;
      } else {
        c6_formation_ros2_B.wpCircle_tmp++;
        c6_formation_ros2_B.WorkingSet.indexLB[c6_formation_ros2_B.wpCircle_tmp
          - 40] = c6_formation_ros2_B.idxFillStart + 1;
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if ((!rtIsInf(c6_formation_ros2_P.velocity_magnitude_limit)) && (!rtIsNaN
           (c6_formation_ros2_P.velocity_magnitude_limit))) {
        c6_formation_ros2_B.b_j++;
        c6_formation_ros2_B.WorkingSet.indexUB[c6_formation_ros2_B.b_j - 1] =
          c6_formation_ros2_B.idxFillStart + 1;
      }
    }
  }

  c6_formation_ros2_B.idxFillStart = (c6_formation_ros2_B.wpCircle_tmp +
    c6_formation_ros2_B.b_j) + c6_formation_ros2_B.i;
  c6_formation_ros2_B.WorkingSet.mConstr = c6_formation_ros2_B.idxFillStart;
  c6_formation_ros2_B.WorkingSet.mConstrOrig = c6_formation_ros2_B.idxFillStart;
  c6_formation_ros2_B.WorkingSet.mConstrMax = 64;
  c6_formation_ros2_B.WorkingSet.sizes[0] = c6_formation_ros2_B.i;
  c6_formation_ros2_B.WorkingSet.sizes[1] = 0;
  c6_formation_ros2_B.WorkingSet.sizes[2] = 39;
  c6_formation_ros2_B.WorkingSet.sizes[3] = c6_formation_ros2_B.wpCircle_tmp -
    39;
  c6_formation_ros2_B.WorkingSet.sizes[4] = c6_formation_ros2_B.b_j;
  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       5; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.WorkingSet.sizesNormal[c6_formation_ros2_B.idxFillStart]
      = c6_formation_ros2_B.WorkingSet.sizes[c6_formation_ros2_B.idxFillStart];
  }

  c6_formation_ros2_B.WorkingSet.sizesPhaseOne[0] = c6_formation_ros2_B.i;
  c6_formation_ros2_B.WorkingSet.sizesPhaseOne[1] = 0;
  c6_formation_ros2_B.WorkingSet.sizesPhaseOne[2] = 39;
  c6_formation_ros2_B.WorkingSet.sizesPhaseOne[3] =
    c6_formation_ros2_B.wpCircle_tmp - 38;
  c6_formation_ros2_B.WorkingSet.sizesPhaseOne[4] = c6_formation_ros2_B.b_j;
  c6_formation_ros2_B.WorkingSet.sizesRegularized[0] = c6_formation_ros2_B.i;
  c6_formation_ros2_B.WorkingSet.sizesRegularized[1] = 0;
  c6_formation_ros2_B.WorkingSet.sizesRegularized[2] = 39;
  c6_formation_ros2_B.WorkingSet.sizesRegularized[3] =
    c6_formation_ros2_B.wpCircle_tmp;
  c6_formation_ros2_B.WorkingSet.sizesRegularized[4] = c6_formation_ros2_B.b_j;
  c6_formation_ros2_B.WorkingSet.sizesRegPhaseOne[0] = c6_formation_ros2_B.i;
  c6_formation_ros2_B.WorkingSet.sizesRegPhaseOne[1] = 0;
  c6_formation_ros2_B.WorkingSet.sizesRegPhaseOne[2] = 39;
  c6_formation_ros2_B.WorkingSet.sizesRegPhaseOne[3] =
    c6_formation_ros2_B.wpCircle_tmp + 1;
  c6_formation_ros2_B.WorkingSet.sizesRegPhaseOne[4] = c6_formation_ros2_B.b_j;
  c6_formation_ros2_B.WorkingSet.isActiveIdxNormal[0] = 1;
  c6_formation_ros2_B.WorkingSet.isActiveIdxNormal[1] = c6_formation_ros2_B.i;
  c6_formation_ros2_B.WorkingSet.isActiveIdxNormal[2] = 0;
  c6_formation_ros2_B.WorkingSet.isActiveIdxNormal[3] = 39;
  c6_formation_ros2_B.WorkingSet.isActiveIdxNormal[4] =
    c6_formation_ros2_B.wpCircle_tmp - 39;
  c6_formation_ros2_B.WorkingSet.isActiveIdxNormal[5] = c6_formation_ros2_B.b_j;
  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       6; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[c6_formation_ros2_B.idxFillStart]
      =
      c6_formation_ros2_B.WorkingSet.isActiveIdxNormal[c6_formation_ros2_B.idxFillStart];
  }

  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       5; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[c6_formation_ros2_B.idxFillStart
      + 1] +=
      c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[c6_formation_ros2_B.idxFillStart];
  }

  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       6; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.WorkingSet.isActiveIdx[c6_formation_ros2_B.idxFillStart]
      =
      c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[c6_formation_ros2_B.idxFillStart];
  }

  c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
  c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[1] =
    c6_formation_ros2_B.i;
  c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
  c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[3] = 39;
  c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[4] =
    c6_formation_ros2_B.wpCircle_tmp - 38;
  c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[5] =
    c6_formation_ros2_B.b_j;
  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       5; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.WorkingSet.isActiveIdxNormal[c6_formation_ros2_B.idxFillStart
      + 1] +=
      c6_formation_ros2_B.WorkingSet.isActiveIdxNormal[c6_formation_ros2_B.idxFillStart];
    c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[c6_formation_ros2_B.idxFillStart
      + 1] +=
      c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[c6_formation_ros2_B.idxFillStart];
  }

  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       6; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.WorkingSet.isActiveIdxPhaseOne[c6_formation_ros2_B.idxFillStart]
      =
      c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[c6_formation_ros2_B.idxFillStart];
  }

  c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
  c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[1] =
    c6_formation_ros2_B.i;
  c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
  c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[3] = 39;
  c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[4] =
    c6_formation_ros2_B.wpCircle_tmp;
  c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[5] =
    c6_formation_ros2_B.b_j;
  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       5; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[c6_formation_ros2_B.idxFillStart
      + 1] +=
      c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[c6_formation_ros2_B.idxFillStart];
  }

  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       6; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.WorkingSet.isActiveIdxRegularized[c6_formation_ros2_B.idxFillStart]
      =
      c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[c6_formation_ros2_B.idxFillStart];
  }

  c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
  c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[1] =
    c6_formation_ros2_B.i;
  c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
  c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[3] = 39;
  c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[4] =
    c6_formation_ros2_B.wpCircle_tmp + 1;
  c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[5] =
    c6_formation_ros2_B.b_j;
  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       5; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[c6_formation_ros2_B.idxFillStart
      + 1] +=
      c6_formation_ros2_B.WorkingSet.isActiveIdxRegPhaseOne[c6_formation_ros2_B.idxFillStart];
  }

  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       12; c6_formation_ros2_B.idxFillStart++) {
    for (c6_formation_ros2_B.colPos = 0; c6_formation_ros2_B.colPos < 39;
         c6_formation_ros2_B.colPos++) {
      c6_formation_ros2_B.WorkingSet.Aineq[c6_formation_ros2_B.idxFillStart + 13
        * c6_formation_ros2_B.colPos] = c6_formation_ros2_B.Aineq[39 *
        c6_formation_ros2_B.idxFillStart + c6_formation_ros2_B.colPos];
    }
  }

  memcpy(&c6_formation_ros2_B.WorkingSet.bineq[0], &c6_formation_ros2_B.b_x[0],
         39U * sizeof(real_T));
  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       12; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.WorkingSet.lb[c6_formation_ros2_B.idxFillStart] =
      c6_formation_ros2_P.velocity_magnitude_limit;
  }

  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       12; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.WorkingSet.ub[c6_formation_ros2_B.idxFillStart] =
      c6_formation_ros2_P.velocity_magnitude_limit;
  }

  c6_formation_ros_setProblemType(&c6_formation_ros2_B.WorkingSet, 3);
  c6_formation_ros2_B.idxFillStart = c6_formation_ros2_B.WorkingSet.isActiveIdx
    [2];
  for (c6_formation_ros2_B.colPos = c6_formation_ros2_B.idxFillStart;
       c6_formation_ros2_B.colPos < 65; c6_formation_ros2_B.colPos++) {
    c6_formation_ros2_B.WorkingSet.isActiveConstr[c6_formation_ros2_B.colPos - 1]
      = false;
  }

  c6_formation_ros2_B.WorkingSet.nWConstr[0] =
    c6_formation_ros2_B.WorkingSet.sizes[0];
  c6_formation_ros2_B.WorkingSet.nWConstr[1] = 0;
  c6_formation_ros2_B.WorkingSet.nWConstr[2] = 0;
  c6_formation_ros2_B.WorkingSet.nWConstr[3] = 0;
  c6_formation_ros2_B.WorkingSet.nWConstr[4] = 0;
  c6_formation_ros2_B.WorkingSet.nActiveConstr =
    c6_formation_ros2_B.WorkingSet.nWConstr[0];
  c6_formation_ros2_B.colPos = static_cast<uint8_T>
    (c6_formation_ros2_B.WorkingSet.sizes[0]);
  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       c6_formation_ros2_B.colPos; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.WorkingSet.Wid[c6_formation_ros2_B.idxFillStart] = 1;
    c6_formation_ros2_B.WorkingSet.Wlocalidx[c6_formation_ros2_B.idxFillStart] =
      c6_formation_ros2_B.idxFillStart + 1;
    c6_formation_ros2_B.WorkingSet.isActiveConstr[c6_formation_ros2_B.idxFillStart]
      = true;
    c6_formation_ros2_B.colOffsetATw = 13 * c6_formation_ros2_B.idxFillStart;
    c6_formation_ros2_B.e =
      c6_formation_ros2_B.WorkingSet.indexFixed[c6_formation_ros2_B.idxFillStart];
    if (c6_formation_ros2_B.e - 2 >= 0) {
      memset
        (&c6_formation_ros2_B.WorkingSet.ATwset[c6_formation_ros2_B.colOffsetATw],
         0, static_cast<uint32_T>(((c6_formation_ros2_B.e +
            c6_formation_ros2_B.colOffsetATw) - c6_formation_ros2_B.colOffsetATw)
          - 1) * sizeof(real_T));
    }

    c6_formation_ros2_B.WorkingSet.ATwset
      [(c6_formation_ros2_B.WorkingSet.indexFixed[c6_formation_ros2_B.idxFillStart]
        + c6_formation_ros2_B.colOffsetATw) - 1] = 1.0;
    c6_formation_ros2_B.g =
      c6_formation_ros2_B.WorkingSet.indexFixed[c6_formation_ros2_B.idxFillStart]
      + 1;
    c6_formation_ros2_B.e = c6_formation_ros2_B.WorkingSet.nVar;
    if (c6_formation_ros2_B.g <= c6_formation_ros2_B.e) {
      memset(&c6_formation_ros2_B.WorkingSet.ATwset[(c6_formation_ros2_B.g +
              c6_formation_ros2_B.colOffsetATw) + -1], 0, static_cast<uint32_T>
             ((((c6_formation_ros2_B.e + c6_formation_ros2_B.colOffsetATw) -
                c6_formation_ros2_B.g) - c6_formation_ros2_B.colOffsetATw) + 1) *
             sizeof(real_T));
    }

    c6_formation_ros2_B.WorkingSet.bwset[c6_formation_ros2_B.idxFillStart] =
      c6_formation_ros2_B.WorkingSet.ub[c6_formation_ros2_B.WorkingSet.indexFixed
      [c6_formation_ros2_B.idxFillStart] - 1];
  }

  c6_formation_ros2_B.WorkingSet.SLACK0 = 0.0;
  c6_formation_ros2_B.scale = 1.0;
  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       39; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.absxk = 0.0;
    c6_formation_ros2_B.colPos = 13 * c6_formation_ros2_B.idxFillStart;
    for (c6_formation_ros2_B.g = 0; c6_formation_ros2_B.g < 12;
         c6_formation_ros2_B.g++) {
      c6_formation_ros2_B.absxk += fabs
        (c6_formation_ros2_B.WorkingSet.Aineq[c6_formation_ros2_B.g +
         c6_formation_ros2_B.colPos]);
    }

    if ((!(c6_formation_ros2_B.scale >= c6_formation_ros2_B.absxk)) && (!rtIsNaN
         (c6_formation_ros2_B.absxk))) {
      c6_formation_ros2_B.scale = c6_formation_ros2_B.absxk;
    }
  }

  c6_formation_ros2_B.b_t = 0.0;
  c6_formation_ros2_B.t = 0.0;
  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       12; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.absxk = 0.0;
    for (c6_formation_ros2_B.colPos = 0; c6_formation_ros2_B.colPos < 12;
         c6_formation_ros2_B.colPos++) {
      c6_formation_ros2_B.absxk += static_cast<real_T>(H[12 *
        c6_formation_ros2_B.idxFillStart + c6_formation_ros2_B.colPos]);
    }

    if (!(c6_formation_ros2_B.b_t >= c6_formation_ros2_B.absxk)) {
      c6_formation_ros2_B.b_t = c6_formation_ros2_B.absxk;
    }

    c6_formation_ros2_B.absxk = fabs
      (c6_formation_ros2_B.Uvw[c6_formation_ros2_B.idxFillStart]);
    if ((!(c6_formation_ros2_B.t >= c6_formation_ros2_B.absxk)) && (!rtIsNaN
         (c6_formation_ros2_B.absxk))) {
      c6_formation_ros2_B.t = c6_formation_ros2_B.absxk;
    }
  }

  if (c6_formation_ros2_B.scale >= c6_formation_ros2_B.t) {
    c6_formation_ros2_B.t = c6_formation_ros2_B.scale;
  }

  if (c6_formation_ros2_B.t >= c6_formation_ros2_B.b_t) {
    c6_formation_ros2_B.b_t = c6_formation_ros2_B.t;
  }

  c6_formation_ros2_driver(c6_formation_ros2_B.Uvw,
    &c6_formation_ros2_B.solution, &c6_formation_ros2_B.memspace,
    &c6_formation_ros2_B.WorkingSet, &c6_formation_ros2_B.CholRegManager, 10 *
    (((c6_formation_ros2_B.i + c6_formation_ros2_B.wpCircle_tmp) +
      c6_formation_ros2_B.b_j) + 12), c6_formation_ros2_B.scale,
    c6_formation_ros2_B.b_t, &c6_formation_ros2_B.QRManager,
    &c6_formation_ros2_B.QPObjective);
  memcpy(&c6_formation_ros2_B.Uxy[0], &c6_formation_ros2_B.solution.xstar[0],
         12U * sizeof(real_T));
  if (c6_formation_ros2_B.solution.state <= 0) {
    c6_formation_ros2_computeFval(&c6_formation_ros2_B.QPObjective,
      c6_formation_ros2_B.memspace.workspace_double, c6_formation_ros2_B.Uvw,
      c6_formation_ros2_B.solution.xstar);
  }

  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       6; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.absxk = c6_formation_ros2_B.Reshape1[3 *
      c6_formation_ros2_B.idxFillStart + 2];
    c6_formation_ros2_B.scale = sin(c6_formation_ros2_B.absxk);
    c6_formation_ros2_B.absxk = cos(c6_formation_ros2_B.absxk);
    c6_formation_ros2_B.wpCircle_tmp = c6_formation_ros2_B.idxFillStart << 1;
    c6_formation_ros2_B.b_t =
      c6_formation_ros2_B.Uxy[c6_formation_ros2_B.wpCircle_tmp + 1];
    c6_formation_ros2_B.t =
      c6_formation_ros2_B.Uxy[c6_formation_ros2_B.wpCircle_tmp];
    c6_formation_ros2_B.Uvw[c6_formation_ros2_B.wpCircle_tmp] =
      c6_formation_ros2_P.lvg * c6_formation_ros2_B.scale *
      c6_formation_ros2_B.b_t + c6_formation_ros2_P.lvg *
      c6_formation_ros2_B.absxk * c6_formation_ros2_B.t;
    c6_formation_ros2_B.Uvw[c6_formation_ros2_B.wpCircle_tmp + 1] =
      rt_atan2d_snf(c6_formation_ros2_B.b_t * c6_formation_ros2_B.absxk +
                    c6_formation_ros2_B.t * -c6_formation_ros2_B.scale,
                    c6_formation_ros2_B.b_t * c6_formation_ros2_B.scale +
                    c6_formation_ros2_B.t * c6_formation_ros2_B.absxk) *
      c6_formation_ros2_P.avl / 1.5707963267948966;
  }

  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       6; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.b_x_c[0] = c6_formation_ros2_B.MathFunction1[3 *
      c6_formation_ros2_B.idxFillStart] - c6_formation_ros2_B.Reshape1[3 *
      c6_formation_ros2_B.idxFillStart];
    c6_formation_ros2_B.wpCircle_tmp = 3 * c6_formation_ros2_B.idxFillStart + 1;
    c6_formation_ros2_B.b_x_c[1] =
      c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.wpCircle_tmp] -
      c6_formation_ros2_B.Reshape1[c6_formation_ros2_B.wpCircle_tmp];
    if (c6_formation_ros2_norm(c6_formation_ros2_B.b_x_c) <
        c6_formation_ros2_P.end_dis) {
      c6_formation_ros2_B.wpCircle_tmp = 3 * c6_formation_ros2_B.idxFillStart +
        2;
      c6_formation_ros2_B.t = c6_formation_ros2_angdiff
        (c6_formation_ros2_B.MathFunction1[c6_formation_ros2_B.wpCircle_tmp],
         c6_formation_ros2_B.Reshape1[c6_formation_ros2_B.wpCircle_tmp]);
      if (fabs(c6_formation_ros2_B.t) > 0.8 * c6_formation_ros2_P.end_ang) {
        c6_formation_ros2_B.Uvw[(c6_formation_ros2_B.idxFillStart << 1) + 1] =
          -c6_formation_ros2_B.t;
      }
    }
  }

  // Saturate: '<S3>/Saturation'
  for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i < 12;
       c6_formation_ros2_B.i++) {
    c6_formation_ros2_B.scale = c6_formation_ros2_B.Uvw[c6_formation_ros2_B.i];

    // Saturate: '<S3>/Saturation'
    c6_formation_ros2_B.absxk =
      c6_formation_ros2_P.Saturation_LowerSat[c6_formation_ros2_B.i];
    c6_formation_ros2_B.b_t =
      c6_formation_ros2_P.Saturation_UpperSat[c6_formation_ros2_B.i];
    if (c6_formation_ros2_B.scale > c6_formation_ros2_B.b_t) {
      c6_formation_ros2_B.Saturation[c6_formation_ros2_B.i] =
        c6_formation_ros2_B.b_t;
    } else if (c6_formation_ros2_B.scale < c6_formation_ros2_B.absxk) {
      c6_formation_ros2_B.Saturation[c6_formation_ros2_B.i] =
        c6_formation_ros2_B.absxk;
    } else {
      c6_formation_ros2_B.Saturation[c6_formation_ros2_B.i] =
        c6_formation_ros2_B.scale;
    }
  }

  // End of Saturate: '<S3>/Saturation'

  // Outputs for Enabled SubSystem: '<S350>/MeasurementUpdate'
  // Constant: '<S327>/Enable' incorporates:
  //   Constant: '<S327>/D'
  //   Constant: '<S327>/u'
  //   Delay: '<S327>/MemoryX'

  c6_formation__MeasurementUpdate(c6_formation_ros2_P.Enable_Value_kj,
    c6_formation_ros2_B.L_a, c6_formation_ros2_B.Reshapey_m,
    c6_formation_ros2_B.Bkuk, c6_formation_ros2_DW.MemoryX_DSTATE_j,
    c6_formation_ros2_P.D_Value, c6_formation_ros2_P.u_Value,
    c6_formation_ros2_B.Product3, &c6_formation_ros2_DW.MeasurementUpdate_ek,
    &c6_formation_ros2_P.MeasurementUpdate_ek);

  // End of Outputs for SubSystem: '<S350>/MeasurementUpdate'

  // Product: '<S350>/A[k]*xhat[k|k-1]' incorporates:
  //   Delay: '<S327>/MemoryX'
  //   Product: '<S45>/A[k]*xhat[k|k-1]'

  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       5; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.scale = 0.0;
    for (c6_formation_ros2_B.wpCircle_tmp = 0; c6_formation_ros2_B.wpCircle_tmp <
         5; c6_formation_ros2_B.wpCircle_tmp++) {
      c6_formation_ros2_B.scale += c6_formation_ros2_B.Akxhatkk1[5 *
        c6_formation_ros2_B.wpCircle_tmp + c6_formation_ros2_B.idxFillStart] *
        c6_formation_ros2_DW.MemoryX_DSTATE_j[c6_formation_ros2_B.wpCircle_tmp];
    }

    c6_formation_ros2_B.Bkuk[c6_formation_ros2_B.idxFillStart] =
      c6_formation_ros2_B.scale;
  }

  // End of Product: '<S350>/A[k]*xhat[k|k-1]'
  for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i <= 2;
       c6_formation_ros2_B.i += 2) {
    // Product: '<S350>/B[k]*u[k]' incorporates:
    //   Constant: '<S327>/B'
    //   Constant: '<S327>/u'

    _mm_storeu_pd(&c6_formation_ros2_B.Akxhatkk1[c6_formation_ros2_B.i],
                  _mm_mul_pd(_mm_loadu_pd
      (&c6_formation_ros2_P.B_Value[c6_formation_ros2_B.i]), _mm_set1_pd
      (c6_formation_ros2_P.u_Value)));
  }

  // Product: '<S350>/B[k]*u[k]' incorporates:
  //   Constant: '<S327>/B'
  //   Constant: '<S327>/u'

  for (c6_formation_ros2_B.i = 4; c6_formation_ros2_B.i < 5;
       c6_formation_ros2_B.i++) {
    c6_formation_ros2_B.Akxhatkk1[c6_formation_ros2_B.i] =
      c6_formation_ros2_P.B_Value[c6_formation_ros2_B.i] *
      c6_formation_ros2_P.u_Value;
  }

  for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i <= 2;
       c6_formation_ros2_B.i += 2) {
    // Sum: '<S350>/Add' incorporates:
    //   Delay: '<S327>/MemoryX'
    //   Product: '<S377>/Product3'

    tmp_0 = _mm_loadu_pd(&c6_formation_ros2_B.Akxhatkk1[c6_formation_ros2_B.i]);
    tmp_1 = _mm_loadu_pd(&c6_formation_ros2_B.Bkuk[c6_formation_ros2_B.i]);
    tmp = _mm_loadu_pd(&c6_formation_ros2_B.Product3[c6_formation_ros2_B.i]);

    // Update for Delay: '<S327>/MemoryX'
    _mm_storeu_pd(&c6_formation_ros2_DW.MemoryX_DSTATE_j[c6_formation_ros2_B.i],
                  _mm_add_pd(_mm_add_pd(tmp_0, tmp_1), tmp));
  }

  for (c6_formation_ros2_B.i = 4; c6_formation_ros2_B.i < 5;
       c6_formation_ros2_B.i++) {
    // Update for Delay: '<S327>/MemoryX' incorporates:
    //   Product: '<S377>/Product3'
    //   Sum: '<S350>/Add'

    c6_formation_ros2_DW.MemoryX_DSTATE_j[c6_formation_ros2_B.i] =
      (c6_formation_ros2_B.Akxhatkk1[c6_formation_ros2_B.i] +
       c6_formation_ros2_B.Bkuk[c6_formation_ros2_B.i]) +
      c6_formation_ros2_B.Product3[c6_formation_ros2_B.i];
  }

  // Outputs for Enabled SubSystem: '<S289>/MeasurementUpdate'
  // Constant: '<S266>/Enable' incorporates:
  //   Constant: '<S266>/D'
  //   Constant: '<S266>/u'
  //   Delay: '<S266>/MemoryX'

  c6_formation__MeasurementUpdate(c6_formation_ros2_P.Enable_Value_ng,
    c6_formation_ros2_B.L_l, c6_formation_ros2_B.Reshapey_p,
    c6_formation_ros2_B.C_l, c6_formation_ros2_DW.MemoryX_DSTATE_p,
    c6_formation_ros2_P.D_Value_h, c6_formation_ros2_P.u_Value_i,
    c6_formation_ros2_B.Product3_g, &c6_formation_ros2_DW.MeasurementUpdate_c,
    &c6_formation_ros2_P.MeasurementUpdate_c);

  // End of Outputs for SubSystem: '<S289>/MeasurementUpdate'

  // Product: '<S289>/A[k]*xhat[k|k-1]' incorporates:
  //   Delay: '<S266>/MemoryX'

  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       5; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.scale = 0.0;
    for (c6_formation_ros2_B.wpCircle_tmp = 0; c6_formation_ros2_B.wpCircle_tmp <
         5; c6_formation_ros2_B.wpCircle_tmp++) {
      c6_formation_ros2_B.scale += c6_formation_ros2_B.A[5 *
        c6_formation_ros2_B.wpCircle_tmp + c6_formation_ros2_B.idxFillStart] *
        c6_formation_ros2_DW.MemoryX_DSTATE_p[c6_formation_ros2_B.wpCircle_tmp];
    }

    c6_formation_ros2_B.Akxhatkk1[c6_formation_ros2_B.idxFillStart] =
      c6_formation_ros2_B.scale;
  }

  // End of Product: '<S289>/A[k]*xhat[k|k-1]'
  for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i <= 2;
       c6_formation_ros2_B.i += 2) {
    // Product: '<S289>/B[k]*u[k]' incorporates:
    //   Constant: '<S266>/B'
    //   Constant: '<S266>/u'

    _mm_storeu_pd(&c6_formation_ros2_B.Bkuk[c6_formation_ros2_B.i], _mm_mul_pd
                  (_mm_loadu_pd
                   (&c6_formation_ros2_P.B_Value_n[c6_formation_ros2_B.i]),
                   _mm_set1_pd(c6_formation_ros2_P.u_Value_i)));
  }

  // Product: '<S289>/B[k]*u[k]' incorporates:
  //   Constant: '<S266>/B'
  //   Constant: '<S266>/u'

  for (c6_formation_ros2_B.i = 4; c6_formation_ros2_B.i < 5;
       c6_formation_ros2_B.i++) {
    c6_formation_ros2_B.Bkuk[c6_formation_ros2_B.i] =
      c6_formation_ros2_P.B_Value_n[c6_formation_ros2_B.i] *
      c6_formation_ros2_P.u_Value_i;
  }

  for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i <= 2;
       c6_formation_ros2_B.i += 2) {
    // Sum: '<S289>/Add' incorporates:
    //   Delay: '<S266>/MemoryX'
    //   Product: '<S316>/Product3'

    tmp_0 = _mm_loadu_pd(&c6_formation_ros2_B.Bkuk[c6_formation_ros2_B.i]);
    tmp_1 = _mm_loadu_pd(&c6_formation_ros2_B.Akxhatkk1[c6_formation_ros2_B.i]);
    tmp = _mm_loadu_pd(&c6_formation_ros2_B.Product3_g[c6_formation_ros2_B.i]);

    // Update for Delay: '<S266>/MemoryX'
    _mm_storeu_pd(&c6_formation_ros2_DW.MemoryX_DSTATE_p[c6_formation_ros2_B.i],
                  _mm_add_pd(_mm_add_pd(tmp_0, tmp_1), tmp));
  }

  for (c6_formation_ros2_B.i = 4; c6_formation_ros2_B.i < 5;
       c6_formation_ros2_B.i++) {
    // Update for Delay: '<S266>/MemoryX' incorporates:
    //   Product: '<S316>/Product3'
    //   Sum: '<S289>/Add'

    c6_formation_ros2_DW.MemoryX_DSTATE_p[c6_formation_ros2_B.i] =
      (c6_formation_ros2_B.Bkuk[c6_formation_ros2_B.i] +
       c6_formation_ros2_B.Akxhatkk1[c6_formation_ros2_B.i]) +
      c6_formation_ros2_B.Product3_g[c6_formation_ros2_B.i];
  }

  // Outputs for Enabled SubSystem: '<S228>/MeasurementUpdate'
  // Constant: '<S205>/Enable' incorporates:
  //   Constant: '<S205>/D'
  //   Constant: '<S205>/u'
  //   Delay: '<S205>/MemoryX'

  c6_formation__MeasurementUpdate(c6_formation_ros2_P.Enable_Value_k,
    c6_formation_ros2_B.L_p, c6_formation_ros2_B.Reshapey_i,
    c6_formation_ros2_B.C_m, c6_formation_ros2_DW.MemoryX_DSTATE_e,
    c6_formation_ros2_P.D_Value_a, c6_formation_ros2_P.u_Value_j,
    c6_formation_ros2_B.Product3_e, &c6_formation_ros2_DW.MeasurementUpdate_e,
    &c6_formation_ros2_P.MeasurementUpdate_e);

  // End of Outputs for SubSystem: '<S228>/MeasurementUpdate'

  // Product: '<S228>/A[k]*xhat[k|k-1]' incorporates:
  //   Delay: '<S205>/MemoryX'

  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       5; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.scale = 0.0;
    for (c6_formation_ros2_B.wpCircle_tmp = 0; c6_formation_ros2_B.wpCircle_tmp <
         5; c6_formation_ros2_B.wpCircle_tmp++) {
      c6_formation_ros2_B.scale += c6_formation_ros2_B.A_a[5 *
        c6_formation_ros2_B.wpCircle_tmp + c6_formation_ros2_B.idxFillStart] *
        c6_formation_ros2_DW.MemoryX_DSTATE_e[c6_formation_ros2_B.wpCircle_tmp];
    }

    c6_formation_ros2_B.Akxhatkk1[c6_formation_ros2_B.idxFillStart] =
      c6_formation_ros2_B.scale;
  }

  // End of Product: '<S228>/A[k]*xhat[k|k-1]'
  for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i <= 2;
       c6_formation_ros2_B.i += 2) {
    // Product: '<S228>/B[k]*u[k]' incorporates:
    //   Constant: '<S205>/B'
    //   Constant: '<S205>/u'

    _mm_storeu_pd(&c6_formation_ros2_B.Bkuk[c6_formation_ros2_B.i], _mm_mul_pd
                  (_mm_loadu_pd
                   (&c6_formation_ros2_P.B_Value_l[c6_formation_ros2_B.i]),
                   _mm_set1_pd(c6_formation_ros2_P.u_Value_j)));
  }

  // Product: '<S228>/B[k]*u[k]' incorporates:
  //   Constant: '<S205>/B'
  //   Constant: '<S205>/u'

  for (c6_formation_ros2_B.i = 4; c6_formation_ros2_B.i < 5;
       c6_formation_ros2_B.i++) {
    c6_formation_ros2_B.Bkuk[c6_formation_ros2_B.i] =
      c6_formation_ros2_P.B_Value_l[c6_formation_ros2_B.i] *
      c6_formation_ros2_P.u_Value_j;
  }

  for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i <= 2;
       c6_formation_ros2_B.i += 2) {
    // Sum: '<S228>/Add' incorporates:
    //   Delay: '<S205>/MemoryX'
    //   Product: '<S255>/Product3'

    tmp_0 = _mm_loadu_pd(&c6_formation_ros2_B.Bkuk[c6_formation_ros2_B.i]);
    tmp_1 = _mm_loadu_pd(&c6_formation_ros2_B.Akxhatkk1[c6_formation_ros2_B.i]);
    tmp = _mm_loadu_pd(&c6_formation_ros2_B.Product3_e[c6_formation_ros2_B.i]);

    // Update for Delay: '<S205>/MemoryX'
    _mm_storeu_pd(&c6_formation_ros2_DW.MemoryX_DSTATE_e[c6_formation_ros2_B.i],
                  _mm_add_pd(_mm_add_pd(tmp_0, tmp_1), tmp));
  }

  for (c6_formation_ros2_B.i = 4; c6_formation_ros2_B.i < 5;
       c6_formation_ros2_B.i++) {
    // Update for Delay: '<S205>/MemoryX' incorporates:
    //   Product: '<S255>/Product3'
    //   Sum: '<S228>/Add'

    c6_formation_ros2_DW.MemoryX_DSTATE_e[c6_formation_ros2_B.i] =
      (c6_formation_ros2_B.Bkuk[c6_formation_ros2_B.i] +
       c6_formation_ros2_B.Akxhatkk1[c6_formation_ros2_B.i]) +
      c6_formation_ros2_B.Product3_e[c6_formation_ros2_B.i];
  }

  // Outputs for Enabled SubSystem: '<S167>/MeasurementUpdate'
  // Constant: '<S144>/Enable' incorporates:
  //   Constant: '<S144>/D'
  //   Constant: '<S144>/u'
  //   Delay: '<S144>/MemoryX'

  c6_formation__MeasurementUpdate(c6_formation_ros2_P.Enable_Value_l,
    c6_formation_ros2_B.L_pd, c6_formation_ros2_B.Reshapey_o,
    c6_formation_ros2_B.C_lk, c6_formation_ros2_DW.MemoryX_DSTATE_h,
    c6_formation_ros2_P.D_Value_e, c6_formation_ros2_P.u_Value_jy,
    c6_formation_ros2_B.Product3_k, &c6_formation_ros2_DW.MeasurementUpdate_i,
    &c6_formation_ros2_P.MeasurementUpdate_i);

  // End of Outputs for SubSystem: '<S167>/MeasurementUpdate'

  // Product: '<S167>/A[k]*xhat[k|k-1]' incorporates:
  //   Delay: '<S144>/MemoryX'

  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       5; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.scale = 0.0;
    for (c6_formation_ros2_B.wpCircle_tmp = 0; c6_formation_ros2_B.wpCircle_tmp <
         5; c6_formation_ros2_B.wpCircle_tmp++) {
      c6_formation_ros2_B.scale += c6_formation_ros2_B.A_j[5 *
        c6_formation_ros2_B.wpCircle_tmp + c6_formation_ros2_B.idxFillStart] *
        c6_formation_ros2_DW.MemoryX_DSTATE_h[c6_formation_ros2_B.wpCircle_tmp];
    }

    c6_formation_ros2_B.Akxhatkk1[c6_formation_ros2_B.idxFillStart] =
      c6_formation_ros2_B.scale;
  }

  // End of Product: '<S167>/A[k]*xhat[k|k-1]'
  for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i <= 2;
       c6_formation_ros2_B.i += 2) {
    // Product: '<S167>/B[k]*u[k]' incorporates:
    //   Constant: '<S144>/B'
    //   Constant: '<S144>/u'

    _mm_storeu_pd(&c6_formation_ros2_B.Bkuk[c6_formation_ros2_B.i], _mm_mul_pd
                  (_mm_loadu_pd
                   (&c6_formation_ros2_P.B_Value_i[c6_formation_ros2_B.i]),
                   _mm_set1_pd(c6_formation_ros2_P.u_Value_jy)));
  }

  // Product: '<S167>/B[k]*u[k]' incorporates:
  //   Constant: '<S144>/B'
  //   Constant: '<S144>/u'

  for (c6_formation_ros2_B.i = 4; c6_formation_ros2_B.i < 5;
       c6_formation_ros2_B.i++) {
    c6_formation_ros2_B.Bkuk[c6_formation_ros2_B.i] =
      c6_formation_ros2_P.B_Value_i[c6_formation_ros2_B.i] *
      c6_formation_ros2_P.u_Value_jy;
  }

  for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i <= 2;
       c6_formation_ros2_B.i += 2) {
    // Sum: '<S167>/Add' incorporates:
    //   Delay: '<S144>/MemoryX'
    //   Product: '<S194>/Product3'

    tmp_0 = _mm_loadu_pd(&c6_formation_ros2_B.Bkuk[c6_formation_ros2_B.i]);
    tmp_1 = _mm_loadu_pd(&c6_formation_ros2_B.Akxhatkk1[c6_formation_ros2_B.i]);
    tmp = _mm_loadu_pd(&c6_formation_ros2_B.Product3_k[c6_formation_ros2_B.i]);

    // Update for Delay: '<S144>/MemoryX'
    _mm_storeu_pd(&c6_formation_ros2_DW.MemoryX_DSTATE_h[c6_formation_ros2_B.i],
                  _mm_add_pd(_mm_add_pd(tmp_0, tmp_1), tmp));
  }

  for (c6_formation_ros2_B.i = 4; c6_formation_ros2_B.i < 5;
       c6_formation_ros2_B.i++) {
    // Update for Delay: '<S144>/MemoryX' incorporates:
    //   Product: '<S194>/Product3'
    //   Sum: '<S167>/Add'

    c6_formation_ros2_DW.MemoryX_DSTATE_h[c6_formation_ros2_B.i] =
      (c6_formation_ros2_B.Bkuk[c6_formation_ros2_B.i] +
       c6_formation_ros2_B.Akxhatkk1[c6_formation_ros2_B.i]) +
      c6_formation_ros2_B.Product3_k[c6_formation_ros2_B.i];
  }

  // Outputs for Enabled SubSystem: '<S106>/MeasurementUpdate'
  // Constant: '<S83>/Enable' incorporates:
  //   Constant: '<S83>/D'
  //   Constant: '<S83>/u'
  //   Delay: '<S83>/MemoryX'

  c6_formation__MeasurementUpdate(c6_formation_ros2_P.Enable_Value_n,
    c6_formation_ros2_B.L_ps, c6_formation_ros2_B.Reshapey_b,
    c6_formation_ros2_B.C_b, c6_formation_ros2_DW.MemoryX_DSTATE_o,
    c6_formation_ros2_P.D_Value_m, c6_formation_ros2_P.u_Value_l,
    c6_formation_ros2_B.Product3_ex, &c6_formation_ros2_DW.MeasurementUpdate_o,
    &c6_formation_ros2_P.MeasurementUpdate_o);

  // End of Outputs for SubSystem: '<S106>/MeasurementUpdate'

  // Product: '<S106>/A[k]*xhat[k|k-1]' incorporates:
  //   Delay: '<S83>/MemoryX'

  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       5; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.scale = 0.0;
    for (c6_formation_ros2_B.wpCircle_tmp = 0; c6_formation_ros2_B.wpCircle_tmp <
         5; c6_formation_ros2_B.wpCircle_tmp++) {
      c6_formation_ros2_B.scale += c6_formation_ros2_B.A_jk[5 *
        c6_formation_ros2_B.wpCircle_tmp + c6_formation_ros2_B.idxFillStart] *
        c6_formation_ros2_DW.MemoryX_DSTATE_o[c6_formation_ros2_B.wpCircle_tmp];
    }

    c6_formation_ros2_B.Akxhatkk1[c6_formation_ros2_B.idxFillStart] =
      c6_formation_ros2_B.scale;
  }

  // End of Product: '<S106>/A[k]*xhat[k|k-1]'
  for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i <= 2;
       c6_formation_ros2_B.i += 2) {
    // Product: '<S106>/B[k]*u[k]' incorporates:
    //   Constant: '<S83>/B'
    //   Constant: '<S83>/u'

    _mm_storeu_pd(&c6_formation_ros2_B.Bkuk[c6_formation_ros2_B.i], _mm_mul_pd
                  (_mm_loadu_pd
                   (&c6_formation_ros2_P.B_Value_j[c6_formation_ros2_B.i]),
                   _mm_set1_pd(c6_formation_ros2_P.u_Value_l)));
  }

  // Product: '<S106>/B[k]*u[k]' incorporates:
  //   Constant: '<S83>/B'
  //   Constant: '<S83>/u'

  for (c6_formation_ros2_B.i = 4; c6_formation_ros2_B.i < 5;
       c6_formation_ros2_B.i++) {
    c6_formation_ros2_B.Bkuk[c6_formation_ros2_B.i] =
      c6_formation_ros2_P.B_Value_j[c6_formation_ros2_B.i] *
      c6_formation_ros2_P.u_Value_l;
  }

  for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i <= 2;
       c6_formation_ros2_B.i += 2) {
    // Sum: '<S106>/Add' incorporates:
    //   Delay: '<S83>/MemoryX'
    //   Product: '<S133>/Product3'

    tmp_0 = _mm_loadu_pd(&c6_formation_ros2_B.Bkuk[c6_formation_ros2_B.i]);
    tmp_1 = _mm_loadu_pd(&c6_formation_ros2_B.Akxhatkk1[c6_formation_ros2_B.i]);
    tmp = _mm_loadu_pd(&c6_formation_ros2_B.Product3_ex[c6_formation_ros2_B.i]);

    // Update for Delay: '<S83>/MemoryX'
    _mm_storeu_pd(&c6_formation_ros2_DW.MemoryX_DSTATE_o[c6_formation_ros2_B.i],
                  _mm_add_pd(_mm_add_pd(tmp_0, tmp_1), tmp));
  }

  for (c6_formation_ros2_B.i = 4; c6_formation_ros2_B.i < 5;
       c6_formation_ros2_B.i++) {
    // Update for Delay: '<S83>/MemoryX' incorporates:
    //   Product: '<S133>/Product3'
    //   Sum: '<S106>/Add'

    c6_formation_ros2_DW.MemoryX_DSTATE_o[c6_formation_ros2_B.i] =
      (c6_formation_ros2_B.Bkuk[c6_formation_ros2_B.i] +
       c6_formation_ros2_B.Akxhatkk1[c6_formation_ros2_B.i]) +
      c6_formation_ros2_B.Product3_ex[c6_formation_ros2_B.i];
  }

  // Outputs for Enabled SubSystem: '<S45>/MeasurementUpdate'
  // Constant: '<S22>/Enable' incorporates:
  //   Constant: '<S22>/D'
  //   Constant: '<S22>/u'
  //   Delay: '<S22>/MemoryX'

  c6_formation__MeasurementUpdate(c6_formation_ros2_P.Enable_Value,
    c6_formation_ros2_B.L, c6_formation_ros2_B.Reshapey, c6_formation_ros2_B.C,
    c6_formation_ros2_DW.MemoryX_DSTATE, c6_formation_ros2_P.D_Value_c,
    c6_formation_ros2_P.u_Value_i4, c6_formation_ros2_B.Product3_c,
    &c6_formation_ros2_DW.MeasurementUpdate,
    &c6_formation_ros2_P.MeasurementUpdate);

  // End of Outputs for SubSystem: '<S45>/MeasurementUpdate'

  // Product: '<S45>/A[k]*xhat[k|k-1]' incorporates:
  //   Delay: '<S22>/MemoryX'

  for (c6_formation_ros2_B.idxFillStart = 0; c6_formation_ros2_B.idxFillStart <
       5; c6_formation_ros2_B.idxFillStart++) {
    c6_formation_ros2_B.scale = 0.0;
    for (c6_formation_ros2_B.wpCircle_tmp = 0; c6_formation_ros2_B.wpCircle_tmp <
         5; c6_formation_ros2_B.wpCircle_tmp++) {
      c6_formation_ros2_B.scale += c6_formation_ros2_B.A_b[5 *
        c6_formation_ros2_B.wpCircle_tmp + c6_formation_ros2_B.idxFillStart] *
        c6_formation_ros2_DW.MemoryX_DSTATE[c6_formation_ros2_B.wpCircle_tmp];
    }

    c6_formation_ros2_B.Akxhatkk1[c6_formation_ros2_B.idxFillStart] =
      c6_formation_ros2_B.scale;
  }

  // End of Product: '<S45>/A[k]*xhat[k|k-1]'
  for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i <= 2;
       c6_formation_ros2_B.i += 2) {
    // Product: '<S45>/B[k]*u[k]' incorporates:
    //   Constant: '<S22>/B'
    //   Constant: '<S22>/u'

    _mm_storeu_pd(&c6_formation_ros2_B.Bkuk[c6_formation_ros2_B.i], _mm_mul_pd
                  (_mm_loadu_pd
                   (&c6_formation_ros2_P.B_Value_o[c6_formation_ros2_B.i]),
                   _mm_set1_pd(c6_formation_ros2_P.u_Value_i4)));
  }

  // Product: '<S45>/B[k]*u[k]' incorporates:
  //   Constant: '<S22>/B'
  //   Constant: '<S22>/u'

  for (c6_formation_ros2_B.i = 4; c6_formation_ros2_B.i < 5;
       c6_formation_ros2_B.i++) {
    c6_formation_ros2_B.Bkuk[c6_formation_ros2_B.i] =
      c6_formation_ros2_P.B_Value_o[c6_formation_ros2_B.i] *
      c6_formation_ros2_P.u_Value_i4;
  }

  // BusAssignment: '<S10>/Bus Assignment1' incorporates:
  //   Constant: '<S382>/Constant'
  //   Gain: '<S2>/Gain'

  c6_formation_ros2_B.BusAssignment1 = c6_formation_ros2_P.Constant_Value_m;
  c6_formation_ros2_B.BusAssignment1.linear.x = c6_formation_ros2_B.Saturation[0];
  c6_formation_ros2_B.BusAssignment1.angular.z = c6_formation_ros2_P.ks *
    c6_formation_ros2_B.Saturation[1];

  // MATLABSystem: '<S383>/SinkBlock'
  Pub_c6_formation_ros2_16722.publish(&c6_formation_ros2_B.BusAssignment1);

  // BusAssignment: '<S11>/Bus Assignment1' incorporates:
  //   Constant: '<S384>/Constant'
  //   Gain: '<S2>/Gain1'

  c6_formation_ros2_B.BusAssignment1 = c6_formation_ros2_P.Constant_Value_kl;
  c6_formation_ros2_B.BusAssignment1.linear.x = c6_formation_ros2_B.Saturation[2];
  c6_formation_ros2_B.BusAssignment1.angular.z = c6_formation_ros2_P.ks *
    c6_formation_ros2_B.Saturation[3];

  // MATLABSystem: '<S385>/SinkBlock'
  Pub_c6_formation_ros2_16728.publish(&c6_formation_ros2_B.BusAssignment1);

  // BusAssignment: '<S12>/Bus Assignment1' incorporates:
  //   Constant: '<S386>/Constant'
  //   Gain: '<S2>/Gain2'

  c6_formation_ros2_B.BusAssignment1 = c6_formation_ros2_P.Constant_Value_f;
  c6_formation_ros2_B.BusAssignment1.linear.x = c6_formation_ros2_B.Saturation[4];
  c6_formation_ros2_B.BusAssignment1.angular.z = c6_formation_ros2_P.ks *
    c6_formation_ros2_B.Saturation[5];

  // MATLABSystem: '<S387>/SinkBlock'
  Pub_c6_formation_ros2_16734.publish(&c6_formation_ros2_B.BusAssignment1);

  // BusAssignment: '<S13>/Bus Assignment1' incorporates:
  //   Constant: '<S388>/Constant'
  //   Gain: '<S2>/Gain3'

  c6_formation_ros2_B.BusAssignment1 = c6_formation_ros2_P.Constant_Value_o;
  c6_formation_ros2_B.BusAssignment1.linear.x = c6_formation_ros2_B.Saturation[6];
  c6_formation_ros2_B.BusAssignment1.angular.z = c6_formation_ros2_P.ks *
    c6_formation_ros2_B.Saturation[7];

  // MATLABSystem: '<S389>/SinkBlock'
  Pub_c6_formation_ros2_16740.publish(&c6_formation_ros2_B.BusAssignment1);

  // BusAssignment: '<S14>/Bus Assignment1' incorporates:
  //   Constant: '<S390>/Constant'
  //   Gain: '<S2>/Gain4'

  c6_formation_ros2_B.BusAssignment1 = c6_formation_ros2_P.Constant_Value_ht;
  c6_formation_ros2_B.BusAssignment1.linear.x = c6_formation_ros2_B.Saturation[8];
  c6_formation_ros2_B.BusAssignment1.angular.z = c6_formation_ros2_P.ks *
    c6_formation_ros2_B.Saturation[9];

  // MATLABSystem: '<S391>/SinkBlock'
  Pub_c6_formation_ros2_16746.publish(&c6_formation_ros2_B.BusAssignment1);

  // BusAssignment: '<S15>/Bus Assignment1' incorporates:
  //   Constant: '<S392>/Constant'
  //   Gain: '<S2>/Gain5'

  c6_formation_ros2_B.BusAssignment1 = c6_formation_ros2_P.Constant_Value_hj;
  c6_formation_ros2_B.BusAssignment1.linear.x = c6_formation_ros2_B.Saturation
    [10];
  c6_formation_ros2_B.BusAssignment1.angular.z = c6_formation_ros2_P.ks *
    c6_formation_ros2_B.Saturation[11];

  // MATLABSystem: '<S393>/SinkBlock'
  Pub_c6_formation_ros2_16752.publish(&c6_formation_ros2_B.BusAssignment1);

  // Trigonometry: '<S326>/sin(theta)'
  c6_formation_ros2_B.scale = sin(c6_formation_ros2_B.sintheta_o);

  // Trigonometry: '<S326>/cos(psi)'
  c6_formation_ros2_B.sintheta_o = cos(c6_formation_ros2_B.sintheta_o);

  // Product: '<S326>/u cos(psi)'
  c6_formation_ros2_B.absxk = c6_formation_ros2_B.sintheta_o *
    c6_formation_ros2_B.V;

  // Product: '<S326>/a w cos(psi)' incorporates:
  //   Constant: '<S326>/Constant'

  c6_formation_ros2_B.b_t = c6_formation_ros2_B.sintheta_o *
    c6_formation_ros2_B.W * c6_formation_ros2_P.Constant_Value_fe;

  // Trigonometry: '<S265>/sin(theta)'
  c6_formation_ros2_B.sintheta_o = sin(c6_formation_ros2_B.cospsi_b);

  // Product: '<S265>/a w sin(psi)' incorporates:
  //   Constant: '<S265>/Constant'

  c6_formation_ros2_B.t = c6_formation_ros2_P.Constant_Value_i *
    c6_formation_ros2_B.W_a * c6_formation_ros2_B.sintheta_o;

  // Trigonometry: '<S265>/cos(psi)'
  c6_formation_ros2_B.cospsi_b = cos(c6_formation_ros2_B.cospsi_b);

  // Product: '<S265>/u sin(psi)'
  c6_formation_ros2_B.usinpsi_k = c6_formation_ros2_B.sintheta_o *
    c6_formation_ros2_B.V_a;

  // Trigonometry: '<S204>/sin(theta)'
  c6_formation_ros2_B.sintheta_o = sin(c6_formation_ros2_B.cospsi_p);

  // Product: '<S204>/a w sin(psi)' incorporates:
  //   Constant: '<S204>/Constant'

  c6_formation_ros2_B.awsinpsi_l = c6_formation_ros2_P.Constant_Value_pn *
    c6_formation_ros2_B.W_i * c6_formation_ros2_B.sintheta_o;

  // Trigonometry: '<S204>/cos(psi)'
  c6_formation_ros2_B.cospsi_p = cos(c6_formation_ros2_B.cospsi_p);

  // Product: '<S204>/u sin(psi)'
  c6_formation_ros2_B.usinpsi_i = c6_formation_ros2_B.sintheta_o *
    c6_formation_ros2_B.V_n;

  // Trigonometry: '<S143>/sin(theta)'
  c6_formation_ros2_B.sintheta_o = sin(c6_formation_ros2_B.cospsi_c);

  // Product: '<S143>/a w sin(psi)' incorporates:
  //   Constant: '<S143>/Constant'

  c6_formation_ros2_B.awsinpsi_k = c6_formation_ros2_P.Constant_Value_b *
    c6_formation_ros2_B.W_f * c6_formation_ros2_B.sintheta_o;

  // Trigonometry: '<S143>/cos(psi)'
  c6_formation_ros2_B.cospsi_c = cos(c6_formation_ros2_B.cospsi_c);

  // Product: '<S143>/u sin(psi)'
  c6_formation_ros2_B.usinpsi_n = c6_formation_ros2_B.sintheta_o *
    c6_formation_ros2_B.V_k;

  // Trigonometry: '<S82>/sin(theta)'
  c6_formation_ros2_B.sintheta_o = sin(c6_formation_ros2_B.cospsi_k);

  // Product: '<S82>/a w sin(psi)' incorporates:
  //   Constant: '<S82>/Constant'

  c6_formation_ros2_B.awsinpsi_j = c6_formation_ros2_P.Constant_Value_gx *
    c6_formation_ros2_B.W_g * c6_formation_ros2_B.sintheta_o;

  // Trigonometry: '<S82>/cos(psi)'
  c6_formation_ros2_B.cospsi_k = cos(c6_formation_ros2_B.cospsi_k);

  // Product: '<S82>/u sin(psi)'
  c6_formation_ros2_B.usinpsi_f = c6_formation_ros2_B.sintheta_o *
    c6_formation_ros2_B.V_d;

  // Trigonometry: '<S21>/sin(theta)'
  c6_formation_ros2_B.sintheta_o = sin(c6_formation_ros2_B.cospsi);

  // Trigonometry: '<S21>/cos(psi)'
  c6_formation_ros2_B.cospsi = cos(c6_formation_ros2_B.cospsi);

  // Update for Delay: '<S22>/MemoryP'
  c6_formation_ros2_DW.icLoad = false;

  // Update for Delay: '<S83>/MemoryP'
  c6_formation_ros2_DW.icLoad_o = false;

  // Update for Delay: '<S144>/MemoryP'
  c6_formation_ros2_DW.icLoad_g = false;

  // Update for Delay: '<S205>/MemoryP'
  c6_formation_ros2_DW.icLoad_a = false;

  // Update for Delay: '<S266>/MemoryP'
  c6_formation_ros2_DW.icLoad_d = false;

  // Update for Delay: '<S327>/MemoryP'
  c6_formation_ros2_DW.icLoad_dm = false;

  // Update for Delay: '<S22>/MemoryP'
  memcpy(&c6_formation_ros2_DW.MemoryP_DSTATE[0], &c6_formation_ros2_B.SNew[0],
         25U * sizeof(real_T));

  // Update for Delay: '<S83>/MemoryP'
  memcpy(&c6_formation_ros2_DW.MemoryP_DSTATE_c[0], &c6_formation_ros2_B.SNew_j
         [0], 25U * sizeof(real_T));

  // Update for Delay: '<S144>/MemoryP'
  memcpy(&c6_formation_ros2_DW.MemoryP_DSTATE_k[0], &c6_formation_ros2_B.SNew_f
         [0], 25U * sizeof(real_T));

  // Update for Delay: '<S205>/MemoryP'
  memcpy(&c6_formation_ros2_DW.MemoryP_DSTATE_i[0],
         &c6_formation_ros2_B.SNew_mo[0], 25U * sizeof(real_T));

  // Update for Delay: '<S266>/MemoryP'
  memcpy(&c6_formation_ros2_DW.MemoryP_DSTATE_n[0], &c6_formation_ros2_B.SNew_m
         [0], 25U * sizeof(real_T));

  // Update for Delay: '<S327>/MemoryP'
  memcpy(&c6_formation_ros2_DW.MemoryP_DSTATE_b[0], &c6_formation_ros2_B.SNew_c
         [0], 25U * sizeof(real_T));

  // Update for Delay: '<S22>/MemoryX'
  c6_formation_ros2_DW.icLoad_k = false;
  for (c6_formation_ros2_B.i = 0; c6_formation_ros2_B.i <= 2;
       c6_formation_ros2_B.i += 2) {
    // Sum: '<S45>/Add' incorporates:
    //   Delay: '<S22>/MemoryX'
    //   Product: '<S72>/Product3'

    tmp_0 = _mm_loadu_pd(&c6_formation_ros2_B.Bkuk[c6_formation_ros2_B.i]);
    tmp_1 = _mm_loadu_pd(&c6_formation_ros2_B.Akxhatkk1[c6_formation_ros2_B.i]);
    tmp = _mm_loadu_pd(&c6_formation_ros2_B.Product3_c[c6_formation_ros2_B.i]);

    // Update for Delay: '<S22>/MemoryX'
    _mm_storeu_pd(&c6_formation_ros2_DW.MemoryX_DSTATE[c6_formation_ros2_B.i],
                  _mm_add_pd(_mm_add_pd(tmp_0, tmp_1), tmp));
  }

  // Update for Delay: '<S22>/MemoryX' incorporates:
  //   Product: '<S72>/Product3'
  //   Sum: '<S45>/Add'

  for (c6_formation_ros2_B.i = 4; c6_formation_ros2_B.i < 5;
       c6_formation_ros2_B.i++) {
    c6_formation_ros2_DW.MemoryX_DSTATE[c6_formation_ros2_B.i] =
      (c6_formation_ros2_B.Bkuk[c6_formation_ros2_B.i] +
       c6_formation_ros2_B.Akxhatkk1[c6_formation_ros2_B.i]) +
      c6_formation_ros2_B.Product3_c[c6_formation_ros2_B.i];
  }

  // Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S21>/Constant'
  //   Product: '<S21>/a w sin(psi)'
  //   Product: '<S21>/u cos(psi)'
  //   Sum: '<S21>/Sum'

  c6_formation_ros2_DW.DiscreteTimeIntegrator_DSTATE +=
    (c6_formation_ros2_B.cospsi * c6_formation_ros2_B.V_e -
     c6_formation_ros2_P.Constant_Value_jm * c6_formation_ros2_B.W_o *
     c6_formation_ros2_B.sintheta_o) *
    c6_formation_ros2_P.DiscreteTimeIntegrator_gainval;
  if (c6_formation_ros2_B.flag > 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRese = 1;
  } else if (c6_formation_ros2_B.flag < 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRese = -1;
  } else if (c6_formation_ros2_B.flag == 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRese = 0;
  } else {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRese = 2;
  }

  // End of Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator'

  // Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator1' incorporates:
  //   Constant: '<S21>/Constant'
  //   Product: '<S21>/a w cos(psi)'
  //   Product: '<S21>/u sin(psi)'
  //   Sum: '<S21>/Sum1'

  c6_formation_ros2_DW.DiscreteTimeIntegrator1_DSTATE +=
    (c6_formation_ros2_B.cospsi * c6_formation_ros2_B.W_o *
     c6_formation_ros2_P.Constant_Value_jm + c6_formation_ros2_B.sintheta_o *
     c6_formation_ros2_B.V_e) *
    c6_formation_ros2_P.DiscreteTimeIntegrator1_gainval;
  if (c6_formation_ros2_B.flag > 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevRes = 1;
  } else if (c6_formation_ros2_B.flag < 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevRes = -1;
  } else if (c6_formation_ros2_B.flag == 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevRes = 0;
  } else {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevRes = 2;
  }

  // End of Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator1'

  // Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator2'
  if (c6_formation_ros2_B.flag > 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevRes = 1;
  } else if (c6_formation_ros2_B.flag < 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevRes = -1;
  } else if (c6_formation_ros2_B.flag == 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevRes = 0;
  } else {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevRes = 2;
  }

  // End of Update for DiscreteIntegrator: '<S21>/Discrete-Time Integrator2'

  // Update for Delay: '<S83>/MemoryX'
  c6_formation_ros2_DW.icLoad_j = false;

  // Update for DiscreteIntegrator: '<S82>/Discrete-Time Integrator' incorporates:
  //   Product: '<S82>/u cos(psi)'
  //   Sum: '<S82>/Sum'

  c6_formation_ros2_DW.DiscreteTimeIntegrator_DSTATE_p +=
    (c6_formation_ros2_B.cospsi_k * c6_formation_ros2_B.V_d -
     c6_formation_ros2_B.awsinpsi_j) *
    c6_formation_ros2_P.DiscreteTimeIntegrator_gainva_b;
  if (c6_formation_ros2_B.flag_p > 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_e = 1;
  } else if (c6_formation_ros2_B.flag_p < 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_e = -1;
  } else if (c6_formation_ros2_B.flag_p == 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_e = 0;
  } else {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_e = 2;
  }

  // End of Update for DiscreteIntegrator: '<S82>/Discrete-Time Integrator'

  // Update for DiscreteIntegrator: '<S82>/Discrete-Time Integrator1' incorporates:
  //   Constant: '<S82>/Constant'
  //   Product: '<S82>/a w cos(psi)'
  //   Sum: '<S82>/Sum1'

  c6_formation_ros2_DW.DiscreteTimeIntegrator1_DSTAT_b +=
    (c6_formation_ros2_B.cospsi_k * c6_formation_ros2_B.W_g *
     c6_formation_ros2_P.Constant_Value_gx + c6_formation_ros2_B.usinpsi_f) *
    c6_formation_ros2_P.DiscreteTimeIntegrator1_gainv_a;
  if (c6_formation_ros2_B.flag_p > 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_p = 1;
  } else if (c6_formation_ros2_B.flag_p < 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_p = -1;
  } else if (c6_formation_ros2_B.flag_p == 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_p = 0;
  } else {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_p = 2;
  }

  // End of Update for DiscreteIntegrator: '<S82>/Discrete-Time Integrator1'

  // Update for DiscreteIntegrator: '<S82>/Discrete-Time Integrator2'
  if (c6_formation_ros2_B.flag_p > 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevR_l = 1;
  } else if (c6_formation_ros2_B.flag_p < 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevR_l = -1;
  } else if (c6_formation_ros2_B.flag_p == 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevR_l = 0;
  } else {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevR_l = 2;
  }

  // End of Update for DiscreteIntegrator: '<S82>/Discrete-Time Integrator2'

  // Update for Delay: '<S144>/MemoryX'
  c6_formation_ros2_DW.icLoad_p = false;

  // Update for DiscreteIntegrator: '<S143>/Discrete-Time Integrator' incorporates:
  //   Product: '<S143>/u cos(psi)'
  //   Sum: '<S143>/Sum'

  c6_formation_ros2_DW.DiscreteTimeIntegrator_DSTATE_a +=
    (c6_formation_ros2_B.cospsi_c * c6_formation_ros2_B.V_k -
     c6_formation_ros2_B.awsinpsi_k) *
    c6_formation_ros2_P.DiscreteTimeIntegrator_gainva_l;
  if (c6_formation_ros2_B.flag_f > 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_o = 1;
  } else if (c6_formation_ros2_B.flag_f < 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_o = -1;
  } else if (c6_formation_ros2_B.flag_f == 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_o = 0;
  } else {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_o = 2;
  }

  // End of Update for DiscreteIntegrator: '<S143>/Discrete-Time Integrator'

  // Update for DiscreteIntegrator: '<S143>/Discrete-Time Integrator1' incorporates:
  //   Constant: '<S143>/Constant'
  //   Product: '<S143>/a w cos(psi)'
  //   Sum: '<S143>/Sum1'

  c6_formation_ros2_DW.DiscreteTimeIntegrator1_DSTAT_h +=
    (c6_formation_ros2_B.cospsi_c * c6_formation_ros2_B.W_f *
     c6_formation_ros2_P.Constant_Value_b + c6_formation_ros2_B.usinpsi_n) *
    c6_formation_ros2_P.DiscreteTimeIntegrator1_gainv_m;
  if (c6_formation_ros2_B.flag_f > 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_f = 1;
  } else if (c6_formation_ros2_B.flag_f < 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_f = -1;
  } else if (c6_formation_ros2_B.flag_f == 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_f = 0;
  } else {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_f = 2;
  }

  // End of Update for DiscreteIntegrator: '<S143>/Discrete-Time Integrator1'

  // Update for DiscreteIntegrator: '<S143>/Discrete-Time Integrator2'
  if (c6_formation_ros2_B.flag_f > 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevR_h = 1;
  } else if (c6_formation_ros2_B.flag_f < 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevR_h = -1;
  } else if (c6_formation_ros2_B.flag_f == 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevR_h = 0;
  } else {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevR_h = 2;
  }

  // End of Update for DiscreteIntegrator: '<S143>/Discrete-Time Integrator2'

  // Update for Delay: '<S205>/MemoryX'
  c6_formation_ros2_DW.icLoad_ko = false;

  // Update for DiscreteIntegrator: '<S204>/Discrete-Time Integrator' incorporates:
  //   Product: '<S204>/u cos(psi)'
  //   Sum: '<S204>/Sum'

  c6_formation_ros2_DW.DiscreteTimeIntegrator_DSTATE_l +=
    (c6_formation_ros2_B.cospsi_p * c6_formation_ros2_B.V_n -
     c6_formation_ros2_B.awsinpsi_l) *
    c6_formation_ros2_P.DiscreteTimeIntegrator_gainva_i;
  if (c6_formation_ros2_B.flag_j > 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_g = 1;
  } else if (c6_formation_ros2_B.flag_j < 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_g = -1;
  } else if (c6_formation_ros2_B.flag_j == 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_g = 0;
  } else {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_g = 2;
  }

  // End of Update for DiscreteIntegrator: '<S204>/Discrete-Time Integrator'

  // Update for DiscreteIntegrator: '<S204>/Discrete-Time Integrator1' incorporates:
  //   Constant: '<S204>/Constant'
  //   Product: '<S204>/a w cos(psi)'
  //   Sum: '<S204>/Sum1'

  c6_formation_ros2_DW.DiscreteTimeIntegrator1_DSTAT_j +=
    (c6_formation_ros2_B.cospsi_p * c6_formation_ros2_B.W_i *
     c6_formation_ros2_P.Constant_Value_pn + c6_formation_ros2_B.usinpsi_i) *
    c6_formation_ros2_P.DiscreteTimeIntegrator1_gainv_n;
  if (c6_formation_ros2_B.flag_j > 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_c = 1;
  } else if (c6_formation_ros2_B.flag_j < 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_c = -1;
  } else if (c6_formation_ros2_B.flag_j == 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_c = 0;
  } else {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_c = 2;
  }

  // End of Update for DiscreteIntegrator: '<S204>/Discrete-Time Integrator1'

  // Update for DiscreteIntegrator: '<S204>/Discrete-Time Integrator2'
  if (c6_formation_ros2_B.flag_j > 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevR_j = 1;
  } else if (c6_formation_ros2_B.flag_j < 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevR_j = -1;
  } else if (c6_formation_ros2_B.flag_j == 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevR_j = 0;
  } else {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevR_j = 2;
  }

  // End of Update for DiscreteIntegrator: '<S204>/Discrete-Time Integrator2'

  // Update for Delay: '<S266>/MemoryX'
  c6_formation_ros2_DW.icLoad_f = false;

  // Update for DiscreteIntegrator: '<S265>/Discrete-Time Integrator' incorporates:
  //   Product: '<S265>/u cos(psi)'
  //   Sum: '<S265>/Sum'

  c6_formation_ros2_DW.DiscreteTimeIntegrator_DSTATE_c +=
    (c6_formation_ros2_B.cospsi_b * c6_formation_ros2_B.V_a -
     c6_formation_ros2_B.t) *
    c6_formation_ros2_P.DiscreteTimeIntegrator_gainv_ii;
  if (c6_formation_ros2_B.flag_n > 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_h = 1;
  } else if (c6_formation_ros2_B.flag_n < 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_h = -1;
  } else if (c6_formation_ros2_B.flag_n == 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_h = 0;
  } else {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_h = 2;
  }

  // End of Update for DiscreteIntegrator: '<S265>/Discrete-Time Integrator'

  // Update for DiscreteIntegrator: '<S265>/Discrete-Time Integrator1' incorporates:
  //   Constant: '<S265>/Constant'
  //   Product: '<S265>/a w cos(psi)'
  //   Sum: '<S265>/Sum1'

  c6_formation_ros2_DW.DiscreteTimeIntegrator1_DSTAT_c +=
    (c6_formation_ros2_B.cospsi_b * c6_formation_ros2_B.W_a *
     c6_formation_ros2_P.Constant_Value_i + c6_formation_ros2_B.usinpsi_k) *
    c6_formation_ros2_P.DiscreteTimeIntegrator1_gainv_e;
  if (c6_formation_ros2_B.flag_n > 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_o = 1;
  } else if (c6_formation_ros2_B.flag_n < 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_o = -1;
  } else if (c6_formation_ros2_B.flag_n == 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_o = 0;
  } else {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_o = 2;
  }

  // End of Update for DiscreteIntegrator: '<S265>/Discrete-Time Integrator1'

  // Update for DiscreteIntegrator: '<S265>/Discrete-Time Integrator2'
  if (c6_formation_ros2_B.flag_n > 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_Prev_hx = 1;
  } else if (c6_formation_ros2_B.flag_n < 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_Prev_hx = -1;
  } else if (c6_formation_ros2_B.flag_n == 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_Prev_hx = 0;
  } else {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_Prev_hx = 2;
  }

  // End of Update for DiscreteIntegrator: '<S265>/Discrete-Time Integrator2'

  // Update for Delay: '<S327>/MemoryX'
  c6_formation_ros2_DW.icLoad_n = false;

  // Update for DiscreteIntegrator: '<S326>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S326>/Constant'
  //   Product: '<S326>/a w sin(psi)'
  //   Sum: '<S326>/Sum'

  c6_formation_ros2_DW.DiscreteTimeIntegrator_DSTATE_j +=
    (c6_formation_ros2_B.absxk - c6_formation_ros2_P.Constant_Value_fe *
     c6_formation_ros2_B.W * c6_formation_ros2_B.scale) *
    c6_formation_ros2_P.DiscreteTimeIntegrator_gainva_a;
  if (c6_formation_ros2_B.flag_b > 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_b = 1;
  } else if (c6_formation_ros2_B.flag_b < 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_b = -1;
  } else if (c6_formation_ros2_B.flag_b == 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_b = 0;
  } else {
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_b = 2;
  }

  // End of Update for DiscreteIntegrator: '<S326>/Discrete-Time Integrator'

  // Update for DiscreteIntegrator: '<S326>/Discrete-Time Integrator1' incorporates:
  //   Product: '<S326>/u sin(psi)'
  //   Sum: '<S326>/Sum1'

  c6_formation_ros2_DW.DiscreteTimeIntegrator1_DSTAT_i +=
    (c6_formation_ros2_B.scale * c6_formation_ros2_B.V + c6_formation_ros2_B.b_t)
    * c6_formation_ros2_P.DiscreteTimeIntegrator1_gainv_d;
  if (c6_formation_ros2_B.flag_b > 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_n = 1;
  } else if (c6_formation_ros2_B.flag_b < 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_n = -1;
  } else if (c6_formation_ros2_B.flag_b == 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_n = 0;
  } else {
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_n = 2;
  }

  // End of Update for DiscreteIntegrator: '<S326>/Discrete-Time Integrator1'

  // Update for DiscreteIntegrator: '<S326>/Discrete-Time Integrator2'
  if (c6_formation_ros2_B.flag_b > 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevR_p = 1;
  } else if (c6_formation_ros2_B.flag_b < 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevR_p = -1;
  } else if (c6_formation_ros2_B.flag_b == 0.0) {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevR_p = 0;
  } else {
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevR_p = 2;
  }

  // End of Update for DiscreteIntegrator: '<S326>/Discrete-Time Integrator2'
}

// Model initialize function
void c6_formation_ros2::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int32_T i;

    // InitializeConditions for Delay: '<S22>/MemoryP'
    c6_formation_ros2_DW.icLoad = true;

    // InitializeConditions for Delay: '<S83>/MemoryP'
    c6_formation_ros2_DW.icLoad_o = true;

    // InitializeConditions for Delay: '<S144>/MemoryP'
    c6_formation_ros2_DW.icLoad_g = true;

    // InitializeConditions for Delay: '<S205>/MemoryP'
    c6_formation_ros2_DW.icLoad_a = true;

    // InitializeConditions for Delay: '<S266>/MemoryP'
    c6_formation_ros2_DW.icLoad_d = true;
    for (i = 0; i < 5; i++) {
      // InitializeConditions for Memory: '<S18>/Memory2' incorporates:
      //   Sum: '<S52>/Add'

      c6_formation_ros2_DW.Memory2_PreviousInput[i] =
        c6_formation_ros2_P.Memory2_InitialCondition;

      // InitializeConditions for Memory: '<S79>/Memory2' incorporates:
      //   Sum: '<S113>/Add'

      c6_formation_ros2_DW.Memory2_PreviousInput_p[i] =
        c6_formation_ros2_P.Memory2_InitialCondition_p;

      // InitializeConditions for Memory: '<S140>/Memory2' incorporates:
      //   Sum: '<S174>/Add'

      c6_formation_ros2_DW.Memory2_PreviousInput_d[i] =
        c6_formation_ros2_P.Memory2_InitialCondition_a;

      // InitializeConditions for Memory: '<S201>/Memory2' incorporates:
      //   Sum: '<S235>/Add'

      c6_formation_ros2_DW.Memory2_PreviousInput_e[i] =
        c6_formation_ros2_P.Memory2_InitialCondition_g;

      // InitializeConditions for Memory: '<S262>/Memory2' incorporates:
      //   Sum: '<S296>/Add'

      c6_formation_ros2_DW.Memory2_PreviousInput_k[i] =
        c6_formation_ros2_P.Memory2_InitialCondition_m;

      // InitializeConditions for Memory: '<S323>/Memory2' incorporates:
      //   Sum: '<S357>/Add'

      c6_formation_ros2_DW.Memory2_PreviousInput_o[i] =
        c6_formation_ros2_P.Memory2_InitialCondition_l;
    }

    // InitializeConditions for Delay: '<S327>/MemoryP'
    c6_formation_ros2_DW.icLoad_dm = true;

    // InitializeConditions for Delay: '<S22>/MemoryX'
    c6_formation_ros2_DW.icLoad_k = true;

    // InitializeConditions for DiscreteIntegrator: '<S21>/Discrete-Time Integrator' 
    c6_formation_ros2_DW.DiscreteTimeIntegrator_DSTATE =
      c6_formation_ros2_P.DiscreteTimeIntegrator_IC;
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRese = 2;

    // InitializeConditions for DiscreteIntegrator: '<S21>/Discrete-Time Integrator1' 
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_DSTATE =
      c6_formation_ros2_P.DiscreteTimeIntegrator1_IC;
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevRes = 2;

    // InitializeConditions for DiscreteIntegrator: '<S21>/Discrete-Time Integrator2' 
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_DSTATE =
      c6_formation_ros2_P.DiscreteTimeIntegrator2_IC;
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevRes = 2;

    // InitializeConditions for Delay: '<S83>/MemoryX'
    c6_formation_ros2_DW.icLoad_j = true;

    // InitializeConditions for DiscreteIntegrator: '<S82>/Discrete-Time Integrator' 
    c6_formation_ros2_DW.DiscreteTimeIntegrator_DSTATE_p =
      c6_formation_ros2_P.DiscreteTimeIntegrator_IC_d;
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_e = 2;

    // InitializeConditions for DiscreteIntegrator: '<S82>/Discrete-Time Integrator1' 
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_DSTAT_b =
      c6_formation_ros2_P.DiscreteTimeIntegrator1_IC_g;
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_p = 2;

    // InitializeConditions for DiscreteIntegrator: '<S82>/Discrete-Time Integrator2' 
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_DSTAT_o =
      c6_formation_ros2_P.DiscreteTimeIntegrator2_IC_a;
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevR_l = 2;

    // InitializeConditions for Delay: '<S144>/MemoryX'
    c6_formation_ros2_DW.icLoad_p = true;

    // InitializeConditions for DiscreteIntegrator: '<S143>/Discrete-Time Integrator' 
    c6_formation_ros2_DW.DiscreteTimeIntegrator_DSTATE_a =
      c6_formation_ros2_P.DiscreteTimeIntegrator_IC_n;
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_o = 2;

    // InitializeConditions for DiscreteIntegrator: '<S143>/Discrete-Time Integrator1' 
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_DSTAT_h =
      c6_formation_ros2_P.DiscreteTimeIntegrator1_IC_n;
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_f = 2;

    // InitializeConditions for DiscreteIntegrator: '<S143>/Discrete-Time Integrator2' 
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_DSTAT_f =
      c6_formation_ros2_P.DiscreteTimeIntegrator2_IC_o;
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevR_h = 2;

    // InitializeConditions for Delay: '<S205>/MemoryX'
    c6_formation_ros2_DW.icLoad_ko = true;

    // InitializeConditions for DiscreteIntegrator: '<S204>/Discrete-Time Integrator' 
    c6_formation_ros2_DW.DiscreteTimeIntegrator_DSTATE_l =
      c6_formation_ros2_P.DiscreteTimeIntegrator_IC_p;
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_g = 2;

    // InitializeConditions for DiscreteIntegrator: '<S204>/Discrete-Time Integrator1' 
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_DSTAT_j =
      c6_formation_ros2_P.DiscreteTimeIntegrator1_IC_o;
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_c = 2;

    // InitializeConditions for DiscreteIntegrator: '<S204>/Discrete-Time Integrator2' 
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_DSTAT_g =
      c6_formation_ros2_P.DiscreteTimeIntegrator2_IC_k;
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevR_j = 2;

    // InitializeConditions for Delay: '<S266>/MemoryX'
    c6_formation_ros2_DW.icLoad_f = true;

    // InitializeConditions for DiscreteIntegrator: '<S265>/Discrete-Time Integrator' 
    c6_formation_ros2_DW.DiscreteTimeIntegrator_DSTATE_c =
      c6_formation_ros2_P.DiscreteTimeIntegrator_IC_f;
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_h = 2;

    // InitializeConditions for DiscreteIntegrator: '<S265>/Discrete-Time Integrator1' 
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_DSTAT_c =
      c6_formation_ros2_P.DiscreteTimeIntegrator1_IC_p;
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_o = 2;

    // InitializeConditions for DiscreteIntegrator: '<S265>/Discrete-Time Integrator2' 
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_DSTAT_i =
      c6_formation_ros2_P.DiscreteTimeIntegrator2_IC_f;
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_Prev_hx = 2;

    // InitializeConditions for Delay: '<S327>/MemoryX'
    c6_formation_ros2_DW.icLoad_n = true;

    // InitializeConditions for DiscreteIntegrator: '<S326>/Discrete-Time Integrator' 
    c6_formation_ros2_DW.DiscreteTimeIntegrator_DSTATE_j =
      c6_formation_ros2_P.DiscreteTimeIntegrator_IC_h;
    c6_formation_ros2_DW.DiscreteTimeIntegrator_PrevRe_b = 2;

    // InitializeConditions for DiscreteIntegrator: '<S326>/Discrete-Time Integrator1' 
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_DSTAT_i =
      c6_formation_ros2_P.DiscreteTimeIntegrator1_IC_e;
    c6_formation_ros2_DW.DiscreteTimeIntegrator1_PrevR_n = 2;

    // InitializeConditions for DiscreteIntegrator: '<S326>/Discrete-Time Integrator2' 
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_DSTA_fb =
      c6_formation_ros2_P.DiscreteTimeIntegrator2_IC_p;
    c6_formation_ros2_DW.DiscreteTimeIntegrator2_PrevR_p = 2;

    // SystemInitialize for Enabled SubSystem: '<S16>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S19>/In1' incorporates:
    //   Outport: '<S19>/Out1'

    c6_formation_ros2_B.In1_pk = c6_formation_ros2_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S16>/Enabled Subsystem'

    // SystemInitialize for MATLAB Function: '<S18>/sensor2vCar'
    c6_formation_r_sensor2vCar_Init(&c6_formation_ros2_DW.sf_sensor2vCar);

    // SystemInitialize for Enabled SubSystem: '<S17>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S20>/In1' incorporates:
    //   Outport: '<S20>/Out1'

    c6_formation_ros2_B.In1_g = c6_formation_ros2_P.Out1_Y0_n;

    // End of SystemInitialize for SubSystem: '<S17>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S52>/Enabled Subsystem'
    c6_format_EnabledSubsystem_Init(c6_formation_ros2_B.Product2_o,
      &c6_formation_ros2_P.EnabledSubsystem_e);

    // End of SystemInitialize for SubSystem: '<S52>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S77>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S80>/In1' incorporates:
    //   Outport: '<S80>/Out1'

    c6_formation_ros2_B.In1_m = c6_formation_ros2_P.Out1_Y0_m;

    // End of SystemInitialize for SubSystem: '<S77>/Enabled Subsystem'

    // SystemInitialize for MATLAB Function: '<S79>/sensor2vCar'
    c6_formation_r_sensor2vCar_Init(&c6_formation_ros2_DW.sf_sensor2vCar_d);

    // SystemInitialize for Enabled SubSystem: '<S78>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S81>/In1' incorporates:
    //   Outport: '<S81>/Out1'

    c6_formation_ros2_B.In1_b = c6_formation_ros2_P.Out1_Y0_ny;

    // End of SystemInitialize for SubSystem: '<S78>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S113>/Enabled Subsystem'
    c6_format_EnabledSubsystem_Init(c6_formation_ros2_B.Product2_g,
      &c6_formation_ros2_P.EnabledSubsystem_h);

    // End of SystemInitialize for SubSystem: '<S113>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S138>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S141>/In1' incorporates:
    //   Outport: '<S141>/Out1'

    c6_formation_ros2_B.In1_p = c6_formation_ros2_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S138>/Enabled Subsystem'

    // SystemInitialize for MATLAB Function: '<S140>/sensor2vCar'
    c6_formation_r_sensor2vCar_Init(&c6_formation_ros2_DW.sf_sensor2vCar_i);

    // SystemInitialize for Enabled SubSystem: '<S139>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S142>/In1' incorporates:
    //   Outport: '<S142>/Out1'

    c6_formation_ros2_B.In1_k = c6_formation_ros2_P.Out1_Y0_l;

    // End of SystemInitialize for SubSystem: '<S139>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S174>/Enabled Subsystem'
    c6_format_EnabledSubsystem_Init(c6_formation_ros2_B.Product2_kr,
      &c6_formation_ros2_P.EnabledSubsystem_lu);

    // End of SystemInitialize for SubSystem: '<S174>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S199>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S202>/In1' incorporates:
    //   Outport: '<S202>/Out1'

    c6_formation_ros2_B.In1_a = c6_formation_ros2_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S199>/Enabled Subsystem'

    // SystemInitialize for MATLAB Function: '<S201>/sensor2vCar'
    c6_formation_r_sensor2vCar_Init(&c6_formation_ros2_DW.sf_sensor2vCar_i3);

    // SystemInitialize for Enabled SubSystem: '<S200>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S203>/In1' incorporates:
    //   Outport: '<S203>/Out1'

    c6_formation_ros2_B.In1_l = c6_formation_ros2_P.Out1_Y0_b;

    // End of SystemInitialize for SubSystem: '<S200>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S235>/Enabled Subsystem'
    c6_format_EnabledSubsystem_Init(c6_formation_ros2_B.Product2_k,
      &c6_formation_ros2_P.EnabledSubsystem_m);

    // End of SystemInitialize for SubSystem: '<S235>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S260>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S263>/In1' incorporates:
    //   Outport: '<S263>/Out1'

    c6_formation_ros2_B.In1_j = c6_formation_ros2_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S260>/Enabled Subsystem'

    // SystemInitialize for MATLAB Function: '<S262>/sensor2vCar'
    c6_formation_r_sensor2vCar_Init(&c6_formation_ros2_DW.sf_sensor2vCar_c);

    // SystemInitialize for Enabled SubSystem: '<S261>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S264>/In1' incorporates:
    //   Outport: '<S264>/Out1'

    c6_formation_ros2_B.In1_d = c6_formation_ros2_P.Out1_Y0_fo;

    // End of SystemInitialize for SubSystem: '<S261>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S296>/Enabled Subsystem'
    c6_format_EnabledSubsystem_Init(c6_formation_ros2_B.Product2_a,
      &c6_formation_ros2_P.EnabledSubsystem_li);

    // End of SystemInitialize for SubSystem: '<S296>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S321>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S324>/In1' incorporates:
    //   Outport: '<S324>/Out1'

    c6_formation_ros2_B.In1 = c6_formation_ros2_P.Out1_Y0_f;

    // End of SystemInitialize for SubSystem: '<S321>/Enabled Subsystem'

    // SystemInitialize for MATLAB Function: '<S323>/sensor2vCar'
    c6_formation_r_sensor2vCar_Init(&c6_formation_ros2_DW.sf_sensor2vCar_e);

    // SystemInitialize for Enabled SubSystem: '<S322>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S325>/In1' incorporates:
    //   Outport: '<S325>/Out1'

    c6_formation_ros2_B.In1_c = c6_formation_ros2_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S322>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S357>/Enabled Subsystem'
    c6_format_EnabledSubsystem_Init(c6_formation_ros2_B.Product2,
      &c6_formation_ros2_P.EnabledSubsystem_o);

    // End of SystemInitialize for SubSystem: '<S357>/Enabled Subsystem'

    // SystemInitialize for Chart: '<Root>/Chart'
    c6_formation_ros2_DW.idx = 2.0;
    c6_formation_ros2_DW.inum = 1.0;
    c6_formation_ros2_DW.inum_g = 1.0;
    c6_formation_ros2_DW.iflag = 2.0;

    // SystemInitialize for Enabled SubSystem: '<S350>/MeasurementUpdate'
    c6_forma_MeasurementUpdate_Init(c6_formation_ros2_B.Product3,
      &c6_formation_ros2_P.MeasurementUpdate_ek);

    // End of SystemInitialize for SubSystem: '<S350>/MeasurementUpdate'

    // SystemInitialize for Enabled SubSystem: '<S289>/MeasurementUpdate'
    c6_forma_MeasurementUpdate_Init(c6_formation_ros2_B.Product3_g,
      &c6_formation_ros2_P.MeasurementUpdate_c);

    // End of SystemInitialize for SubSystem: '<S289>/MeasurementUpdate'

    // SystemInitialize for Enabled SubSystem: '<S228>/MeasurementUpdate'
    c6_forma_MeasurementUpdate_Init(c6_formation_ros2_B.Product3_e,
      &c6_formation_ros2_P.MeasurementUpdate_e);

    // End of SystemInitialize for SubSystem: '<S228>/MeasurementUpdate'

    // SystemInitialize for Enabled SubSystem: '<S167>/MeasurementUpdate'
    c6_forma_MeasurementUpdate_Init(c6_formation_ros2_B.Product3_k,
      &c6_formation_ros2_P.MeasurementUpdate_i);

    // End of SystemInitialize for SubSystem: '<S167>/MeasurementUpdate'

    // SystemInitialize for Enabled SubSystem: '<S106>/MeasurementUpdate'
    c6_forma_MeasurementUpdate_Init(c6_formation_ros2_B.Product3_ex,
      &c6_formation_ros2_P.MeasurementUpdate_o);

    // End of SystemInitialize for SubSystem: '<S106>/MeasurementUpdate'

    // SystemInitialize for Enabled SubSystem: '<S45>/MeasurementUpdate'
    c6_forma_MeasurementUpdate_Init(c6_formation_ros2_B.Product3_c,
      &c6_formation_ros2_P.MeasurementUpdate);

    // End of SystemInitialize for SubSystem: '<S45>/MeasurementUpdate'

    // Start for MATLABSystem: '<S16>/SourceBlock'
    c6_formation_ros2_DW.obj_go.isInitialized = 0;
    c6_formation_ros2_DW.obj_go.matlabCodegenIsDeleted = false;
    c6_formation_r_SystemCore_setup(&c6_formation_ros2_DW.obj_go);

    // Start for MATLABSystem: '<S17>/SourceBlock'
    c6_formation_ros2_DW.obj_g.isInitialized = 0;
    c6_formation_ros2_DW.obj_g.matlabCodegenIsDeleted = false;
    c6_formation_SystemCore_setup_a(&c6_formation_ros2_DW.obj_g);

    // Start for MATLABSystem: '<S77>/SourceBlock'
    c6_formation_ros2_DW.obj_m.isInitialized = 0;
    c6_formation_ros2_DW.obj_m.matlabCodegenIsDeleted = false;
    c6_formatio_SystemCore_setup_aa(&c6_formation_ros2_DW.obj_m);

    // Start for MATLABSystem: '<S78>/SourceBlock'
    c6_formation_ros2_DW.obj_n.isInitialized = 0;
    c6_formation_ros2_DW.obj_n.matlabCodegenIsDeleted = false;
    c6_formati_SystemCore_setup_aao(&c6_formation_ros2_DW.obj_n);

    // Start for MATLABSystem: '<S138>/SourceBlock'
    c6_formation_ros2_DW.obj_id.isInitialized = 0;
    c6_formation_ros2_DW.obj_id.matlabCodegenIsDeleted = false;
    c6_format_SystemCore_setup_aaoo(&c6_formation_ros2_DW.obj_id);

    // Start for MATLABSystem: '<S139>/SourceBlock'
    c6_formation_ros2_DW.obj_ix.isInitialized = 0;
    c6_formation_ros2_DW.obj_ix.matlabCodegenIsDeleted = false;
    c6_forma_SystemCore_setup_aaoow(&c6_formation_ros2_DW.obj_ix);

    // Start for MATLABSystem: '<S199>/SourceBlock'
    c6_formation_ros2_DW.obj_it.isInitialized = 0;
    c6_formation_ros2_DW.obj_it.matlabCodegenIsDeleted = false;
    c6_form_SystemCore_setup_aaoowe(&c6_formation_ros2_DW.obj_it);

    // Start for MATLABSystem: '<S200>/SourceBlock'
    c6_formation_ros2_DW.obj_i.isInitialized = 0;
    c6_formation_ros2_DW.obj_i.matlabCodegenIsDeleted = false;
    c6_for_SystemCore_setup_aaoowep(&c6_formation_ros2_DW.obj_i);

    // Start for MATLABSystem: '<S260>/SourceBlock'
    c6_formation_ros2_DW.obj_lw.isInitialized = 0;
    c6_formation_ros2_DW.obj_lw.matlabCodegenIsDeleted = false;
    c6_fo_SystemCore_setup_aaoowepy(&c6_formation_ros2_DW.obj_lw);

    // Start for MATLABSystem: '<S261>/SourceBlock'
    c6_formation_ros2_DW.obj_l.isInitialized = 0;
    c6_formation_ros2_DW.obj_l.matlabCodegenIsDeleted = false;
    c6_f_SystemCore_setup_aaoowepyy(&c6_formation_ros2_DW.obj_l);

    // Start for MATLABSystem: '<S321>/SourceBlock'
    c6_formation_ros2_DW.obj_b.isInitialized = 0;
    c6_formation_ros2_DW.obj_b.matlabCodegenIsDeleted = false;
    c6__SystemCore_setup_aaoowepyyp(&c6_formation_ros2_DW.obj_b);

    // Start for MATLABSystem: '<S322>/SourceBlock'
    c6_formation_ros2_DW.obj.isInitialized = 0;
    c6_formation_ros2_DW.obj.matlabCodegenIsDeleted = false;
    c6_SystemCore_setup_aaoowepyypb(&c6_formation_ros2_DW.obj);

    // Start for MATLABSystem: '<S383>/SinkBlock'
    c6_formation_ros2_DW.obj_bh.isInitialized = 0;
    c6_formation_ros2_DW.obj_bh.matlabCodegenIsDeleted = false;
    c_SystemCore_setup_aaoowepyypbp(&c6_formation_ros2_DW.obj_bh);

    // Start for MATLABSystem: '<S385>/SinkBlock'
    c6_formation_ros2_DW.obj_et.isInitialized = 0;
    c6_formation_ros2_DW.obj_et.matlabCodegenIsDeleted = false;
    SystemCore_setup_aaoowepyypbpz(&c6_formation_ros2_DW.obj_et);

    // Start for MATLABSystem: '<S387>/SinkBlock'
    c6_formation_ros2_DW.obj_k.isInitialized = 0;
    c6_formation_ros2_DW.obj_k.matlabCodegenIsDeleted = false;
    SystemCore_setup_aaoowepyypbpz2(&c6_formation_ros2_DW.obj_k);

    // Start for MATLABSystem: '<S389>/SinkBlock'
    c6_formation_ros2_DW.obj_l3.isInitialized = 0;
    c6_formation_ros2_DW.obj_l3.matlabCodegenIsDeleted = false;
    SystemCore_setu_aaoowepyypbpz2d(&c6_formation_ros2_DW.obj_l3);

    // Start for MATLABSystem: '<S391>/SinkBlock'
    c6_formation_ros2_DW.obj_f.isInitialized = 0;
    c6_formation_ros2_DW.obj_f.matlabCodegenIsDeleted = false;
    c6_formation_SystemCore_setup_j(&c6_formation_ros2_DW.obj_f);

    // Start for MATLABSystem: '<S393>/SinkBlock'
    c6_formation_ros2_DW.obj_e.isInitialized = 0;
    c6_formation_ros2_DW.obj_e.matlabCodegenIsDeleted = false;
    c6_formation_SystemCore_setup_p(&c6_formation_ros2_DW.obj_e);
  }
}

// Model terminate function
void c6_formation_ros2::terminate()
{
  // Terminate for MATLABSystem: '<S16>/SourceBlock'
  if (!c6_formation_ros2_DW.obj_go.matlabCodegenIsDeleted) {
    c6_formation_ros2_DW.obj_go.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S16>/SourceBlock'

  // Terminate for MATLABSystem: '<S17>/SourceBlock'
  if (!c6_formation_ros2_DW.obj_g.matlabCodegenIsDeleted) {
    c6_formation_ros2_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S17>/SourceBlock'

  // Terminate for MATLABSystem: '<S77>/SourceBlock'
  if (!c6_formation_ros2_DW.obj_m.matlabCodegenIsDeleted) {
    c6_formation_ros2_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S77>/SourceBlock'

  // Terminate for MATLABSystem: '<S78>/SourceBlock'
  if (!c6_formation_ros2_DW.obj_n.matlabCodegenIsDeleted) {
    c6_formation_ros2_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S78>/SourceBlock'

  // Terminate for MATLABSystem: '<S138>/SourceBlock'
  if (!c6_formation_ros2_DW.obj_id.matlabCodegenIsDeleted) {
    c6_formation_ros2_DW.obj_id.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S138>/SourceBlock'

  // Terminate for MATLABSystem: '<S139>/SourceBlock'
  if (!c6_formation_ros2_DW.obj_ix.matlabCodegenIsDeleted) {
    c6_formation_ros2_DW.obj_ix.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S139>/SourceBlock'

  // Terminate for MATLABSystem: '<S199>/SourceBlock'
  if (!c6_formation_ros2_DW.obj_it.matlabCodegenIsDeleted) {
    c6_formation_ros2_DW.obj_it.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S199>/SourceBlock'

  // Terminate for MATLABSystem: '<S200>/SourceBlock'
  if (!c6_formation_ros2_DW.obj_i.matlabCodegenIsDeleted) {
    c6_formation_ros2_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S200>/SourceBlock'

  // Terminate for MATLABSystem: '<S260>/SourceBlock'
  if (!c6_formation_ros2_DW.obj_lw.matlabCodegenIsDeleted) {
    c6_formation_ros2_DW.obj_lw.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S260>/SourceBlock'

  // Terminate for MATLABSystem: '<S261>/SourceBlock'
  if (!c6_formation_ros2_DW.obj_l.matlabCodegenIsDeleted) {
    c6_formation_ros2_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S261>/SourceBlock'

  // Terminate for MATLABSystem: '<S321>/SourceBlock'
  if (!c6_formation_ros2_DW.obj_b.matlabCodegenIsDeleted) {
    c6_formation_ros2_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S321>/SourceBlock'

  // Terminate for MATLABSystem: '<S322>/SourceBlock'
  if (!c6_formation_ros2_DW.obj.matlabCodegenIsDeleted) {
    c6_formation_ros2_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S322>/SourceBlock'

  // Terminate for MATLABSystem: '<S383>/SinkBlock'
  if (!c6_formation_ros2_DW.obj_bh.matlabCodegenIsDeleted) {
    c6_formation_ros2_DW.obj_bh.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S383>/SinkBlock'

  // Terminate for MATLABSystem: '<S385>/SinkBlock'
  if (!c6_formation_ros2_DW.obj_et.matlabCodegenIsDeleted) {
    c6_formation_ros2_DW.obj_et.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S385>/SinkBlock'

  // Terminate for MATLABSystem: '<S387>/SinkBlock'
  if (!c6_formation_ros2_DW.obj_k.matlabCodegenIsDeleted) {
    c6_formation_ros2_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S387>/SinkBlock'

  // Terminate for MATLABSystem: '<S389>/SinkBlock'
  if (!c6_formation_ros2_DW.obj_l3.matlabCodegenIsDeleted) {
    c6_formation_ros2_DW.obj_l3.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S389>/SinkBlock'

  // Terminate for MATLABSystem: '<S391>/SinkBlock'
  if (!c6_formation_ros2_DW.obj_f.matlabCodegenIsDeleted) {
    c6_formation_ros2_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S391>/SinkBlock'

  // Terminate for MATLABSystem: '<S393>/SinkBlock'
  if (!c6_formation_ros2_DW.obj_e.matlabCodegenIsDeleted) {
    c6_formation_ros2_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S393>/SinkBlock'
}

// Constructor
c6_formation_ros2::c6_formation_ros2() :
  c6_formation_ros2_B(),
  c6_formation_ros2_DW(),
  c6_formation_ros2_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
c6_formation_ros2::~c6_formation_ros2()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_c6_formation_ros2_T * c6_formation_ros2::getRTM()
{
  return (&c6_formation_ros2_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
