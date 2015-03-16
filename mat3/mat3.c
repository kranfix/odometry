#ifndef github_com_kranfix_odometry_mat3_mat3_c
#define github_com_kranfix_odometry_mat3_mat3_c

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <math.h>
#include "mat3.h"

/* Definition of a 3 orderMatrix */
typedef union kfxMat3_t {
  struct {_kfxRow3_t r0, r1, r2; };
  _kfxRow3_t r[3];
} kfxMat3_t;

// Math with another quaternion
void kfxMat3_sum(kfxMat3_t * m, kfxMat3_t * ml, kfxMat3_t * mr){
  *m = *ml;
}

void kfxMat3_sub(kfxMat3_t * m, kfxMat3_t * ml, kfxMat3_t * mr){
  *m = *ml;
}

void kfxMat3_mul(kfxMat3_t * m, kfxMat3_t * ml, kfxMat3_t * mr) {
  *m = *ml;
}
  
// Math with a scalar
void kfxMat3_mulS(kfxMat3_t * m, kfxQuat_t * ml, float num){
  *m = *ml;
}

void kfxMat3_divS(kfxMat3_t * m, kfxQuat_t * ml, float num) {
  *m = *ml;
}

// Math with vector colum
void kfxMat3_mulVec(kfxVec_t * Vo, kfxMat3_t * m, kfxVec_t * Vi){
  *Vo = *Vi;
}

// Compare quaternions
int kfxMat3_cmp(kfxMat3_t * ml, kfxMat3_t * mr) {
  return 0;
}

// Matrix Inverse
void kfxMat3_inv(kfxMat3_t * mo, kfxMat3 * mi) {
  *mo = *mi
}

// Matrix determinant
float kfxMat3_det(kfxMat3_t * m) {
  return 0;
}

#ifdef __cplusplus
};
#endif // __cplusplus

#endif // github_com_kranfix_odometry_mat3_mat3_c
