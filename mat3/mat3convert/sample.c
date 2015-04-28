#include <stdio.h>
#include "mat3convert.h"
#include <math.h>

void print_mat3(kfxMat3_t * m);
void print_axisang(kfxAxisang_t * a);
void print_quat(kfxQuat_t * q);

int main() {
    kfxMat3_t m = {
             .r0={2., 3., -1.}, 
             .r1={4.0, -3, 2.0},
             .r2={2.0, 4.0, 2.0}
        };
    kfxQuat_t q;
    kfxAxisang_t a;
    kfxRpy_t rpy;


    // Printing variable "a" and "b"
    printf("q = ");
    kfxMat3_2Quat(&m, &q);
    print_quat(&q);
    printf("\n");

    // Math with another quaternion
    printf("rpy = ");
    kfxMat3_2Rpy(&m, &rpy);
    printf("\n");

    // Math with a scalar
    printf("a = ");
    kfxMat3_2Axisang(&m, &a);
    print_mat3(&m);   printf("\n");

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

void print_axisang(kfxAxisang_t * a) {
  printf("\t{%2.4f, {%2.4f, %2.4f, %2.4f}}\n", a->a, a->x, a->n.y, a->n.z);
}

void print_quat(kfxQuat_t * q) {
  printf("{%2.1f, %2.1f, %2.1f, %2.1f}\n", q->w, q->x, q->y, q->z);
}

