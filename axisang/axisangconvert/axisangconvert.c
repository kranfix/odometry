#ifndef github_com_kranfix_odometry_axisang_axisangconvert_axisangconvert_c
#define github_com_kranfix_odometry_axisang_axisangconvert_axisangconvert_c

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "axisangconvert.h"
#include <math.h>

// TRANSFORMADE AXIS-ANGLE

void kfxAxisang_2Quat(kfxAxisang_t * axis, kfxQuat_t * q){
  float sa = sin(axis->a/2);
	
  ////////// QUATERNION //////////
  q->w = cos(axis->a/2);
  q->x = sa * axis->x;
  q->y = sa * axis->y;
  q->z = sa * axis->z;
}

void kfxAxisang_2Rpy(kfxAxisang_t * axis, kfxRpy_t * rpy){
  ///////// RPY //////////
  kfxQuat_t q;
  kfxAxisang_2Quat(axis, &q);
  kfxQuat_2Rpy(&q, rpy);	
}

void kfxAxisang_2Mat3(kfxAxisang_t * axis, kfxMat3_t * m){
  float ca = (1-cos(axis->a));
  float sa = sin(axis->a);
  float n1 = axis->x;
  float n2 = axis->y;
  float n3 = axis->z;
  float n12 = (axis->x)*(axis->y);
  float n13 = (axis->x)*(axis->z);
  float n23 = (axis->y)*(axis->z);
  float n11 = pow(n1,2);
  float n22 = pow(n2,2);
  float n33 = pow(n3,2);

  ////////// MATRIX //////////
  m->r[0].e[0] = 1 - ca * (n22 + n33);
  m->r[0].e[1] = n12 * ca - n3 * sa;
  m->r[0].e[2] = n2 * sa + n13 * ca;
  m->r[1].e[0] = n3 * sa + n12 * ca;
  m->r[1].e[1] = 1 - ca*(n22 + n33);
  m->r[1].e[2] = n23 * ca - n1 * sa;
  m->r[2].e[0] = n13 * ca - n2 * sa;
  m->r[2].e[1] = n1 * sa + n23 * ca;
  m->r[2].e[2] = 1 - ca * (n11 + n22);	
}


#ifdef __cplusplus
};
#endif // __cplusplus

#endif//github_com_kranfix_odometry_axisang_axisangconvert_axisangconvert_c
