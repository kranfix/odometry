#ifndef github_com_kranfix_odometry_quaternion_quatconvert_quatconvert_c
#define github_com_kranfix_odometry_quaternion_quatconvert_quatconvert_c

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "quatconvert.h"
#include <math.h>

// TRANSFORMADE QUATERNION
void kfxQuat_2Axisang(kfxQuat_t * q, kfxAxisang_t * axis){
  ////////// AXIS //////////
  axis->a = 2*acos(q->w);
  axis->x = 2*asin(q->x);
  axis->y = 2*asin(q->y);
  axis->z = 2*asin(q->z);
}

void kfxQuat_2Mat3(kfxQuat_t * q, kfxMat3_t * m){
  kfxAxisang_t axis;
  kfxQuat_2Axisang(q,&axis);

  float ca = (1-cos(axis.a));
  float sa = sin(axis.a);
  float n1 = axis.x;
  float n2 = axis.y;
  float n3 = axis.z;
  float n12 = axis.x * axis.y;
  float n13 = axis.x * axis.z;
  float n23 = axis.y * axis.z;
  float n11 = pow(axis.x, 2);
  float n22 = pow(axis.y, 2);
  float n33 = pow(axis.x, 2);

  ////////// MATRIX //////////
  m->r[0].e[0] = 1 - ca*(n22 + n33);
  m->r[0].e[1] = -n3 * sa + n12 * ca;
  m->r[0].e[2] = n2 * sa + n13 * ca;
  m->r[1].e[0] = n3 * sa + n12 * ca;
  m->r[1].e[1] = 1 - ca*(n11 + n33);
  m->r[1].e[2] = -n1*sa + n2*n3*ca;
  m->r[2].e[0] = -n2*sa + n1*n3*ca;
  m->r[2].e[1] = n1*sa+n2*n3*ca;
  m->r[2].e[2] = 1 - ca*(n11 + n22);	
}

void kfxQuat_2Rpy(kfxQuat_t * q, kfxRpy_t * rpy){
  kfxAxisang_t axis;
  axis.a = 2*acos(q->w);
  axis.x = 2*asin(q->x);
  axis.y = 2*asin(q->y);
  axis.z = 2*asin(q->z);

  float ca = (1-cos(axis.a));
  float sa = sin(axis.a);
  float n1 = axis.x;
  float n2 = axis.y;
  float n3 = axis.z;

  kfxMat3_t m;
  
  m.r[1].e[0] = n3 * sa + n1 * n2 * ca;
  m.r[2].e[0] = -n2 * sa + n1 * n3 * ca;
  m.r[2].e[1] = n1 * sa + n2 * n3 * ca;
 
  ////////// RPY //////////
  rpy->p = -asin(m.r[2].e[0]);	
					
  float cp = cos(rpy->p);		
					
  rpy->r = asin(m.r[2].e[1]/cp);	
  rpy->y = asin(m.r[1].e[0]/cp);	
}

#ifdef __cplusplus
};
#endif // __cplusplus

#endif//github_com_kranfix_odometry_quaternion_quatconvert_quatconvert_c

