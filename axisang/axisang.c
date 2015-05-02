#ifndef github_com_kranfix_odometry_axisang_axisang_c
#define github_com_kranfix_odometry_axisang_axisang_c

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <math.h>
#include "../vector/vector.h"
#include "axisang.h"

// Normalize Axis-ang vector
void kfxAxisang_normalize(kfxAxisang_t * ao, kfxAxisang_t * ai, int * err){
  float ai_mod = sqrt(kfxVec_dot(&ai->n, &ai->n));
  if(ai_mod == 0) {
    *err = 1;
    return;
  }
	ao->a = ai->a;
  ao->x = ai->x / ai_mod;
  ao->y = ai->y / ai_mod;
  ao->z = ai->z / ai_mod;
  *err = 0;
}

#ifdef __cplusplus
};
#endif // __cplusplus

#endif // github_com_kranfix_odometry_axisang_axisang_c
