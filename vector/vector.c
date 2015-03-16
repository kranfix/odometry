#ifndef github_com_kranfix_odometry_vector_vector_c
#define github_com_kranfix_odometry_vector_vector_c

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "vector.h"

// Dot and Cross product
float kfxVec_dot(kfxVec_t * vl, kfxVec_t * vr) {
  return vl->x * vr->x + vl->y * vr->y + vl->z * vr->z;
}

void kfxVec_cross(kfxVec_t * v, kfxVec_t * vl, kfxVec_t * vr) {
  kfxVec_t temp = {
    .x = vl->y * vr->z - vl->z * vr->y,
    .y = vl->z * vr->x - vl->x * vr->z,
    .z = vl->x * vr->y - vl->y * vr->x
  };
  v->x = temp.x;
  v->y = temp.y;
  v->z = temp.z;
}

// Sum and sub between 2 vectors
void kfxVec_sum(kfxVec_t *v, kfxVec_t * vl, kfxVec_t * vr) {
  v->x = vl->x + vr->x;
  v->y = vl->y + vr->y;
  v->z = vl->z + vr->z;
}

void kfxVec_sub(kfxVec_t *v, kfxVec_t * vl, kfxVec_t * vr) {
  v->x = vl->x - vr->x;
  v->y = vl->y - vr->y;
  v->z = vl->z - vr->z;
}

// Scale a Vector
void kfxVec_mul(kfxVec_t * v, kfxVec_t * vl, float num) {
  v->x = vl->x * num;
  v->y = vl->y * num;
  v->z = vl->z * num;
}

#ifdef _cplusplus
}
#endif // _cplusplus

#endif // github_com_kranfix_odometry_vector_vector_h
