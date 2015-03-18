#ifndef github_com_kranfix_odometry_mat3_mat3_h
#define github_com_kranfix_odometry_mat3_mat3_h

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "../vector/vector.h"

/* Definition of row */
typedef union _kfxRow3_t {
  float e[3];
  kfxVec_Union(r, x, y, z);
} _kfxRow3_t;

/* Definition of a 3 orderMatrix */
typedef union kfxMat3_t {
  struct {_kfxRow3_t r0, r1, r2; };
  _kfxRow3_t r[3];
} kfxMat3_t;

// Math with another quaternion
void kfxMat3_sum(kfxMat3_t * m, kfxMat3_t * ml, kfxMat3_t * mr);
void kfxMat3_sub(kfxMat3_t * m, kfxMat3_t * ml, kfxMat3_t * mr);
void kfxMat3_mul(kfxMat3_t * m, kfxMat3_t * ml, kfxMat3_t * mr);
  
// Math with a scalar
void kfxMat3_mulS(kfxMat3_t * m, kfxMat3_t * ml, float num);
int kfxMat3_divS(kfxMat3_t * m, kfxMat3_t * ml, float num);

// Math with vector colum
void kfxMat3_mulVec(kfxVec_t * Vo, kfxMat3_t * m, kfxVec_t * Vi);

// Compare quaternions
int kfxMat3_cmp(kfxMat3_t * ml, kfxMat3_t * mr);

// Matrix Inverse
int kfxMat3_inv(kfxMat3_t * mo, kfxMat3_t * mi);

// Matrix determinant
float kfxMat3_det(kfxMat3_t * m);

#ifdef __cplusplus
};
#endif // __cplusplus

#endif // github_com_kranfix_odometry_mat3_mat3_h
