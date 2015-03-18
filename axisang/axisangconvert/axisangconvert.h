#ifndef github_com_kranfix_odometry_axisang_axisangconvert_axisangconvert_h
#define github_com_kranfix_odometry_axisang_axisangconvert_axisangconvert_h

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "../../vector/vector.h"
#include "../../quaternion/quaternion.h"
#include "../../mat3/mat3.h"
#include "../axisang/axisang.h"

// Tranformade Axisang
void kfxAxisang_2Quat(kfxAxisang_t * axis, kfxQuat_t * q);
void kfxAxisang_2Rpy(kfxAxisang_t * axis, kfxRpy_t * rpy);
void kfxAxisang_2Mat3(kfxAxisang_t * axis, kfxMat3_t * m);

#ifdef __cplusplus
};
#endif // __cplusplus

#endif//github_com_kranfix_odometry_axisang_axisangconvert_axisangconvert_h
