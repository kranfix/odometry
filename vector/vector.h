#ifndef github_com_kranfix_odometry_vector_vector_h
#define github_com_kranfix_odometry_vector_vector_h

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef struct kfxVec_t {float x, y, z; } kfxVec_t;

#define kfxVec_Union(vecname) union{   \
      struct {float x, y, z; };        \
      kfxVec_t vecname;                \
    };


// Dot and Cross product
float kfxVec_dot(kfxVec_t * vl, kfxVec_t * vr);
void kfxVec_cross(kfxVec_t * v, kfxVec_t * vl, kfxVec_t * vr);

// Sum and sub between 2 vectors
void kfxVec_sum(kfxVec_t *v, kfxVec_t * vl, kfxVec_t * vr);
void kfxVec_sub(kfxVec_t *v, kfxVec_t * vl, kfxVec_t * vr);

// Scale a Vector
void kfxVec_mul(kfxVec_t * v, kfxVec_t * vl, float num);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // github_com_kranfix_odometry_vector_vector_h
