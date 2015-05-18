#ifndef github_com_kranfix_odometry_mat3_mat3convert_mat3convert_h
#define github_com_kranfix_odometry_mat3_mat3convert_mat3convert_h

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "../../quaternion/quaternion.h"
#include "../../axisang/axisang.h"
#include "../../rpy/rpy.h"
#include "../mat3.h"

// Tranformade Mat3
void kfxMat3_2Quat(kfxMat3_t * m, kfxQuat_t * q);
void kfxMat3_2Rpy(kfxMat3_t * m, kfxRpy_t * rpy);
void kfxMat3_2Axisang(kfxMat3_t * m, kfxAxisang_t * axis);

#ifdef __cplusplus
};
#endif // __cplusplus

#endif // github_com_kranfix_odometry_mat3_mat3convert_mat3convert_h
