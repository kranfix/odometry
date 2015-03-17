#include <stdio.h>
#include "mat3.h"
#include <math.h>

void print_mat3(kfxMat3_t * m);
void print_vec(kfxVec_t * v);

int main() {
    kfxVec_t vi = {3.0, 4.0, 6.0};
    kfxMat3_t a = {
             .r0={2., 3., -1.}, 
             .r1={4.0, -3, 2.0},
             .r2={2.0, 4.0, 2.0}
        };
    kfxMat3_t b = {
             .r0={3., -4., -5.}, 
             .r1={-1.0, 2, 4},
             .r2={2.0, 1.0, 0.}
        };
    kfxMat3_t c;
    kfxVec_t vo;

    // Printing variable "a" and "b"
    printf("a = ");   print_mat3(&a);
    printf("b = ");   print_mat3(&b);
    printf("\n");

    // Math with another quaternion
    printf("c = a + b\n");
    kfxMat3_sum(&c, &a, &b);
    print_mat3(&c);   printf("\n");

    printf("c = a - b\n");
    kfxMat3_sub(&c, &a, &b);
    print_mat3(&c);   printf("\n");

    printf("c = a * b\n");
    kfxMat3_mul(&c, &a, &b);
    print_mat3(&c);   printf("\n");

    // Math with a scalar
    printf("c = a * 0.5\n");
    kfxMat3_mulS(&c, &a, 0.5);
    print_mat3(&c);   printf("\n");

    printf("c = a / 2.0\n");
    kfxMat3_divS(&c, &a, 2);
    print_mat3(&c);   printf("\n");

    // Math with vector colum
    printf("c = a * vi\n");
    kfxMat3_mulVec(&vo, &a, &vi);
    print_vec(&vo); printf("\n");

    // Compare quaternions
    printf("compare ( a, a ) : %d\n", kfxMat3_cmp(&a, &a));
    printf("compare ( a, b ) : %d\n\n", kfxMat3_cmp(&a, &b));

    // Matrix Inverse
    printf("c = inv(a)\n");
    kfxMat3_inv(&c, &a);
    print_mat3(&c);   printf("\n");

    // Matrix determinant
    float det = kfxMat3_det(&a);
    printf("det(a) = %f\n", det);
	
    printf("\n");

    return 0;
}

void print_mat3(kfxMat3_t * m) {
    printf("\t{%2.1f, %2.1f, %2.1f}\n", m->r0.x, m->r0.y, m->r0.z);
    printf("\t{%2.1f, %2.1f, %2.1f}\n",
           m->r[1].x, m->r[1].y, m->r[1].e[2]);
    printf("\t{%2.1f, %2.1f, %2.1f}\n",
           m->r[2].e[0], m->r2.e[1], m->r[2].z);
}

void print_vec(kfxVec_t * v) {
    printf("\t{%2.1f, %2.1f, %2.1f}\n", v->x, v->y, v->z);
}
