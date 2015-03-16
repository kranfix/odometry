#include <stdio.h>
#include "vector.h"

void print_vec();

int main() {
    kfxVec_t a = {3.0, 4.0, 6.0};
    kfxVec_t b = {2., 3., -1.};
    kfxVec_t c;

    // Printing variable "a" and "b"
    printf("a = {3.0, 4.0, 6.0}\n");
    printf("b = {2.0, 3.0, -1.}\n\n");

    // Test for kfxVec_dot
    float dot = kfxVec_dot(&a, &b);
    printf("a . b = %2.1f\n", dot);   

    // Test for kfxVec_cross();
    kfxVec_cross(&c,&a,&b);
    printf("a x b = ");
    print_vec(&c);

    // Test for kfxVec_sum
    kfxVec_sum(&c, &a, &b);
    printf("a + b = ");
    print_vec(&c);

    // Test for kfxVec_sum
    kfxVec_sub(&c, &a, &b);
    printf("a - b = ");
    print_vec(&c);

    // Test for kfxVec_mul
    kfxVec_mul(&c, &a, 0.5);
    printf("a * 0.5 = ");
    print_vec(&c);

    printf("\n");

    return 0;
}

void print_vec(kfxVec_t * v) {
    printf("{%2.1f, %2.1f, %2.1f}\n", v->x, v->y, v->z);
}
