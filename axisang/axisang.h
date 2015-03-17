#ifndef github_com_kranfix_odometry_axisang_axisang_h
#define github_com_kranfix_odometry_axisang_axisang_h

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "../vector/vector.h"

/* Definition of a Axis-Angle */
typedef struct kfxAxisang_t {
  // a = ( alpha, n(x,y,z) )
  float a;
  kfxVec_Union(n);
} kfxQuat_t;


// Math with another quaternion
void kfxAxisang_normalize(kfxAxisang_t * ao, kfxMat3_t * ai, int * err);

#ifdef __cplusplus
};
#endif // __cplusplus

#endif // github_com_kranfix_odometry_axisang_h
