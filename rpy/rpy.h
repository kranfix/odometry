#ifndef github_com_kranfix_odometry_rpy_rpy_h
#define github_com_kranfix_odometry_rpy_rpy_h

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "../vector/vector.h"

/* Definition of a Axis-Angle */
typedef struct kfxRpy_t {
  float r, p, y;
} kfxRpy_t;


#ifdef __cplusplus
};
#endif // __cplusplus

#endif // github_com_kranfix_odometry_rpy_rpy_h
