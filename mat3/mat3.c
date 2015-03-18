#ifndef github_com_kranfix_odometry_mat3_mat3_c
#define github_com_kranfix_odometry_mat3_mat3_c

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <math.h>
#include "mat3.h"

// Math with another quaternion
void kfxMat3_sum(kfxMat3_t * m, kfxMat3_t * ml, kfxMat3_t * mr){
  int i;
  for(i = 0; i < 3; i++) {
    kfxVec_sub(&m->r[i].r, &ml->r[i].r, &mr->r[i].r);
  }
}

void kfxMat3_sub(kfxMat3_t * m, kfxMat3_t * ml, kfxMat3_t * mr){
  int i;
  for(i = 0; i < 3; i++) {
    kfxVec_sub(&m->r[i].r, &ml->r[i].r, &mr->r[i].r);
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
  int i;
  for(i = 0; i < 3; i++) {
    kfxVec_mul(&m->r[i].r, &m->r[i].r, num);
  }
}

int kfxMat3_divS(kfxMat3_t * m, kfxMat3_t * ml, float num) {
  int i = 0;
  if(num == 0) return 1;
  float temp = 1/num;
  for( ; i < 3; i++) {
    kfxVec_mul(&m->r[i].r, &m->r[i].r, temp);
  }
  return 1;
}

// Math with vector colum
void kfxMat3_mulVec(kfxVec_t * Vo, kfxMat3_t * m, kfxVec_t * Vi){
  Vo->x = kfxVec_dot(&m->r0.r, Vi);
  Vo->y = kfxVec_dot(&m->r1.r, Vi);
  Vo->z = kfxVec_dot(&m->r2.r, Vi);
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

int kfxMat3_inv(kfxMat3_t * mo, kfxMat3_t * mi) {
  float det = kfxMat3_det(mi);
  if(det == 0) {
    return 1;
  }
  *mo = (kfxMat3_t){
    .r0 = { (mi->r1.y * mi->r2.z - mi->r1.z * mi->r2.y)/det,
            (mi->r1.z * mi->r2.x - mi->r1.x * mi->r2.z)/det,
            (mi->r1.x * mi->r2.y - mi->r1.y * mi->r2.x)/det
          },
    .r1 = { (mi->r2.y * mi->r0.z - mi->r2.z * mi->r0.y)/det,
            (mi->r2.z * mi->r0.x - mi->r2.x * mi->r0.z)/det,
            (mi->r2.x * mi->r0.y - mi->r2.y * mi->r0.x)/det
          },
    .r2 = { (mi->r0.y * mi->r1.z - mi->r0.z * mi->r1.y)/det,
            (mi->r0.z * mi->r1.x - mi->r0.x * mi->r1.z)/det,
            (mi->r0.x * mi->r1.y - mi->r0.y * mi->r1.x)/det
          }
  };
  return 0;
}

// Matrix determinant
float kfxMat3_det(kfxMat3_t * m) {
  float d = m->r0.x * (m->r1.y * m->r2.z - m->r1.z * m->r2.y);
  d += m->r0.y * (m->r1.z * m->r2.x - m->r1.x * m->r2.z);
  d += m->r0.z * (m->r1.x * m->r2.y - m->r1.y * m->r2.x);
  return d;
}

#ifdef __cplusplus
};
#endif // __cplusplus

#endif // github_com_kranfix_odometry_mat3_mat3_c
