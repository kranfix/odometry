#ifndef github_com_kranfix_odometry_quaternion_quaternion_c
#define github_com_kranfix_odometry_quaternion_quaternion_c

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "../quaternion.h"
#include <math.h>

// Math with another quaternion
void kfxQuat_sum(kfxQuat_t * q, kfxQuat_t * ql, kfxQuat_t * qr) {
  q->w = ql->w + qr->w;
  q->x = ql->x + qr->x;
  q->y = ql->y + qr->y;
  q->z = qr->z + qr->z;
}

void kfxQuat_sub(kfxQuat_t * q, kfxQuat_t * ql, kfxQuat_t * qr) {
  q->w = ql->w - qr->w;
  q->x = ql->x - qr->x;
  q->y = ql->y - qr->y;
  q->z = qr->z - qr->z;
}

void kfxQuat_mul(kfxQuat_t * q, kfxQuat_t * ql, kfxQuat_t * qr){
  kfxQuat_t temp = {
    .w = ql->w * qr->w - ql->x * qr->x - ql->y * qr->y - ql->z * qr->z,
    .x = ql->w * qr->x + ql->x * qr->w + ql->y * qr->z - ql->z * qr->y,
    .y = ql->w * qr->y - ql->x * qr->z + ql->y * qr->w + ql->z * qr->x,
    .z = ql->w * qr->z + ql->x * qr->y - ql->y * qr->x + ql->z * qr->w
  };
  q->w = temp.w;
  q->x = temp.x;
  q->y = temp.y;
  q->z = temp.z;
}
  
// Math with a scalar
void kfxQuat_mulS(kfxQuat_t * q, kfxQuat_t * ql, float num){
  q->w = ql->w * num;
  q->x = ql->w * num;
  q->y = ql->y * num;
  q->z = ql->z * num;
}
void kfxQuat_divS(kfxQuat_t * q, kfxQuat_t * ql, float num){
  q->w = ql->w / num;
  q->x = ql->w / num;
  q->y = ql->y / num;
  q->z = ql->z / num;
}

// Quaternion operations
void kfxQuat_conj(kfxQuat_t * q, kfxQuat_t * ql) {
  q->w = ql->w;
  q->x = -ql->x;
  q->y = -ql->y;
  q->z = -ql->z;
}

void kfxQuat_inv(kfxQuat_t * q, kfxQuat_t * ql) {
  float mag = kfxQuat_modSq(ql);
  q->w = ql->w / mag;
  q->x = -ql->x / mag;
  q->y = -ql->y / mag;
  q->z = -ql->z / mag;
}

float kfxQuat_mod(kfxQuat_t * q) {
  return sqrt(kfxQuat_modSq(q));
}

// Compare Quaternions
int kfxQuat_cmp(kfxQuat_t * ql, kfxQuat_t * qr) {
  return (ql->w == qr->w) && (ql->x == qr->x) &&
         (ql->y == qr->y) && (ql->z == qr->z);
}

#ifdef __cplusplus
};
#endif // __cplusplus

#endif // github_com_kranfix_odometry_quaternion_quarternion_c
