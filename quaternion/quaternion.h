/*
https://github.com/fheavr/Quaternion/blob/master/includes/Camera.h
https://github.com/fheavr/Quaternion/blob/master/includes/Quaternion.h
https://github.com/fheavr/Quaternion/blob/master/includes/Vector.h
https://github.com/fheavr/Quaternion/blob/master/src/Camera.cpp
https://github.com/fheavr/Quaternion/blob/master/src/Quaternion.cpp
https://github.com/fheavr/Quaternion/blob/master/src/Vector.cpp

*/
#ifndef github_com_kranfix_odometry_quaternion_quaternion_h
#define github_com_kranfix_odometry_quaternion_quaternion_h

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "../vector/vector.h"

/* Definition of a Quaternion */
typedef struct kfxQuat_t {
  // q = w + xi + yj + zk
  float w;
  kfxVec_Union(V);
} kfxQuat_t;

// Math with another quaternion
void kfxQuat_sum(kfxQuat_t * q, kfxQuat_t * ql, kfxQuat_t * qr);
void kfxQuat_sub(kfxQuat_t * q, kfxQuat_t * ql, kfxQuat_t * qr);
void kfxQuat_mul(kfxQuat_t * q, kfxQuat_t * ql, kfxQuat_t * qr);
  
// Math with a scalar
void kfxQuat_mulS(kfxQuat_t * q, kfxQuat_t * ql, float num);
void kfxQuat_divS(kfxQuat_t * q, kfxQuat_t * ql, float num);

// Compare quaternions
int kfxQuat_cmp(kfxQuat_t * ql, kfxQuat_t * qr);

// Operations like a 4 dimension vector
float kfxQuat_dot(kfxQuat_t * ql, kfxQuat_t * qr);
  
// Quaternion operations
void kfxQuat_conj(kfxQuat_t * q, kfxQuat_t * ql);  // Conjugate
void kfxQuat_inv(kfxQuat_t * q, kfxQuat_t * ql);   // Inverse
float kfxQuat_mod(kfxQuat_t * q);      // Modulus

float kfxQuat_modSq(kfxQuat_t *q);

#ifdef __cplusplus
};
#endif // __cplusplus

#endif // github_com_kranfix_odometry_quarternion_quaternion_h
