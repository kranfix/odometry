#ifndef github_com_kranfix_odometry_mat3_mat3_c
#define github_com_kranfix_odometry_mat3_mat3_c

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <math.h>
#include "mat3.h"

// Math with another quaternion
void kfxMat3_sum(kfxMat3_t * m, kfxMat3_t * ml, kfxMat3_t * mr){
  int i, j;
  for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
      m->r[i].e[j] = ml->r[i].e[j] + mr->r[i].e[j];
    }
  }
}

void kfxMat3_sub(kfxMat3_t * m, kfxMat3_t * ml, kfxMat3_t * mr){
  int i, j;
  for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
      m->r[i].e[j] = ml->r[i].e[j] - mr->r[i].e[j];
    }
  }
}

void kfxMat3_mul(kfxMat3_t * m, kfxMat3_t * ml, kfxMat3_t * mr) {
  kfxMat3_t temp;
  int i, j;
  for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
      temp.r[i].e[j] = ml->r[i].x * mr->r0.e[j] +
                    ml->r[i].y * mr->r1.e[j] +
                    ml->r[i].z * mr->r2.e[j]; 
    }
  }
  *m = temp;
}
  
// Math with a scalar
void kfxMat3_mulS(kfxMat3_t * m, kfxMat3_t * ml, float num){
  int i, j;
  for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
      m->r[i].e[j] = ml->r[i].e[j] * num;
    }
  }
}

void kfxMat3_divS(kfxMat3_t * m, kfxMat3_t * ml, float num) {
  int i, j;
  for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
      m->r[i].e[j] = ml->r[i].e[j] / num;
    }
  }
}

// Math with vector colum
void kfxMat3_mulVec(kfxVec_t * Vo, kfxMat3_t * m, kfxVec_t * Vi){
  Vo->x = kfxVec_dot(&(m->r0.r),Vi);
  Vo->y = kfxVec_dot(&m->r1.r,Vi);
  Vo->z = kfxVec_dot(&m->r2.r,Vi);
}

// Compare quaternions
int kfxMat3_cmp(kfxMat3_t * ml, kfxMat3_t * mr) {
  int i = 0, j = 0;
  for( ; i < 3; i++) {
    for( ; j < 3; j++) {
      if(ml->r[i].e[j] != mr->r[i].e[j])
        return 0;
    }
  }
  return 1;
}

// Matrix Inverse
void kfxMat3_inv(kfxMat3_t * mo, kfxMat3_t * mi) {
  *mo = *mi;
}

// Matrix determinant
float kfxMat3_det(kfxMat3_t * m) {
  return 0;
}

#ifdef __cplusplus
};
#endif // __cplusplus

#endif // github_com_kranfix_odometry_mat3_mat3_c
