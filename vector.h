#ifndef github_com_kranfix_odometry_vector_h
#define github_com_kranfix_odometry_vector_h

#ifdef _cplusplus
extern "C" {
#endif // _cplusplus

typedef struct kfxVec_t {float x, y, z; } kfxVec_t;

// Dot and Cross product
float kfcVec_dot(kfxVec_t * vl, kfxVec_t * vr);
void kfcVec_cross(kfxVec_t * v, kfxVec_t * vl, kfxVec_t * vr);

// Sum between 2 vectors
void kfxVec_sum(kfxVec_t *v, kfxVec_t * vl, kfxVec_t * vr);

// Scale a Vector
void kfxVec_mul(kfxVec_t * v, kfxVec_t * vl, float num);

#ifdef _cplusplus
}
#endif // _cplusplus

#endif // github_com_kranfix_odometry_vector_h
