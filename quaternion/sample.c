#include <stdio.h>
#include "quaternion.h"
#include <math.h>

void print_quat();

int main() {
    kfxQuat_t a = {3.0, 4.0, 6.0, 1.0};
    kfxQuat_t b = {.w= 2., .V= {3., -1., 1.0} };
    kfxQuat_t c;

    // Printing variable "a" and "b"
    printf("a = {3.0, 4.0, 6.0, 1.0}\n");
    printf("b = {2.0, 3.0, -1., 1.0}\n\n");

    // TEST MATH WITH ANOTHER QUATERNION
    //**************************************
    // Test for kfxQuat_sum
    kfxQuat_sum(&c, &a, &b);
    printf("a + b = ");
    print_quat(&c);
	
    // Test for kfxQuat_sub
    kfxQuat_sub(&c, &a, &b);
    printf("a - b = ");
    print_quat(&c);

    // Test for kfxQuat_mul
    kfxQuat_mul(&c, &a, &b);
    printf("a * b = ");
    print_quat(&c);

    // MATH WHIT A SCALAR
    //**************************************
    // Test for kfxQuat_mulS
    kfxQuat_mulS(&c, &a, 0.5);
    printf("a * 0.5 = ");
    print_quat(&c);

    kfxQuat_divS(&c, &a, 2);
    printf("a / 2 = ");
    print_quat(&c);

    // QUATERNION OPERATIONS
    //**************************************
    // Test for kfxQuat_conj
    kfxQuat_conj(&c, &a);
    printf("conjugate (a) = ");
    print_quat(&c);

    // Test for kfxQuat_inv
    kfxQuat_inv(&c, &a);
    printf("inverse (a) = ");
    print_quat(&c);

    // Test for kfxQuat_modSq
    float sq = kfxQuat_modSq(&a);
    printf("module (a) = %2.3f\n", sq);

    // COMPARE QUATERNIONS
    //**************************************
    // Test for kfxQuat_cmp
    int true_or_false = kfxQuat_cmp(&a, &b);
    printf("compare ( a, b ) : %d\n", true_or_false);

    printf("\n");

    return 0;
}

void print_quat(kfxQuat_t * q) {
    printf("{%2.1f, %2.1f, %2.1f, %2.1f}\n", q->w, q->x, q->y, q->z);
}
