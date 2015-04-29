#ifndef github_com_kranfix_odometry_quaternion_quatconvert_quatconvert_h
#define github_com_kranfix_odometry_quaternion_quatconvert_quatconvert_h

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "../../vector/vector.h"
#include "../quaternion.h"
#include "../../mat3/mat3.h"
#include "../../rpy/rpy.h"
#include "../../axisang/axisang.h"

// Tranformade Quat
void kfxQuat_2Mat3(kfxQuat_t * q, kfxMat3_t * m);
void kfxQuat_2Rpy(kfxQuat_t * q, kfxRpy_t * rpy);
void kfxQuat_2Axisang(kfxQuat_t * q, kfxAxisang_t * axis);

#ifdef __cplusplus
};
#endif // __cplusplus

#endif//github_com_kranfix_odometry_quaternion_quatconvert_quatconvert_h
