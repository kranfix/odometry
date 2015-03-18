#ifndef github_com_kranfix_odometry_rpy_rpyconvert_rpyconvert_h
#define github_com_kranfix_odometry_rpy_rpyconvert_rpyconvert_h

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "../../vector/vector.h"
#include "../../quaternion/quaternion.h"
#include "../../mat3/mat3.h"
#include "../../axisang/axisang.h"
#include "../rpy.h"

// TRANSFORMADE ROLL-PITCH-YAW
void kfxRpy_2Mat3(kfxRpy_t * rpy, kfxMat3_t * m);
void kfxRpy_2Quat(kfxRpy_t * rpy, kfxQuat_t * q);
void kfxRpy_2Axisang(kfxRpy_t * rpy, kfxAxisang_t * axis);

#ifdef __cplusplus
};
#endif // __cplusplus

#endif // github_com_kranfix_odometry_rpy_rpyconvert_rpyconvert_h
