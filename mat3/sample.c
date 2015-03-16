#include <stdio.h>
#include "mat3.h"
#include <math.h>

void print_mat3();

int main() {
    kfxVec_t vi = {3.0, 4.0, 6.0};
    kfxMat3_t a = {
             {2., 3., -1.}, 
             {4.0, -3, 2.0},
             {2.0, 4.0, 2.0}
        };
    kfxMat3_t b = {
             {3., -4., -5.}, 
             {-1.0, 2, 4},
             {2.0, 1.0, 0.}
        };
    kfxMat3_t c;
    kfxVec_t vo;

    // Printing variable "a" and "b"
    printf("a = ");   print_mat3(a);
    printf("b = ");   print_mat3(b):


    // Math with another quaternion
    printf("c = a + b\n");
    kfxMat3_sum(&c, &a, &b);
    printf_mat3(c);   printf("\n");

    printf("c = a - b\n");
    kfxMat3_sub(&c, &a, &b);
    printf("\n");

    printf("c = a * b\n");
    kfxMat3_mul(&c, &a, &b);
    printf_mat3(c);   printf("\n");

    // Math with a scalar
    printf("c = a * 0.5\n");
    kfxMat3_mulS(&c, &a, 0.5);
    printf_mat3(c);   printf("\n");

    printf("c = a / 2.0\n");
    kfxMat3_divS(&c, &a, 2);
    printf_mat3(c);   printf("\n");

    // Math with vector colum
    kfxMat3_mulVec(&vo, &a, &vi);

    // Compare quaternions
    int true_or_false =  kfxMat3_cmp(&a, &b);
    printf("compare ( a, b ) : %d\n", true_or_false);

    // Matrix Inverse
    kfxMat3_inv(&c, &a);


    // Matrix determinant
    float det = kfxMat3_det(&a);
	
    printf("\n");

    return 0;
}

void print_mat3(kfxMat3_t * m) {
    printf("{%2.1f, %2.1f, %2.1f, %2.1f}\n", q->w, q->x, q->y, q->z);
}
