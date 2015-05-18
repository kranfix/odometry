#include <stdio.h>
#include "quatconvert.h"
#include <math.h>

void print_mat3(kfxMat3_t * m);
void print_axisang(kfxAxisang_t * a);
void print_quat(kfxQuat_t * q);
void print_rpy(kfxRpy_t * r);

int main() {
  kfxQuat_t q = {0.8201, 0.3369, 0.4292, 0.172477};
  kfxQuat_divS(&q, &q, kfxQuat_mod(&q));
  kfxMat3_t m;
  kfxAxisang_t a;
  kfxRpy_t rpy;

  // Printing variable "a" and "b"
  printf("m = ");
  kfxQuat_2Mat3(&q, &m);
  print_mat3(&m);   printf("\n");

  // Math with another quaternion
  printf("rpy = ");
  kfxQuat_2Rpy(&q, &rpy);
  print_rpy(&rpy);  printf("\n");

  // Math with a scalar
  printf("a = ");
  kfxQuat_2Axisang(&q, &a);
  print_axisang(&a);   printf("\n");

  printf("\n");

  return 0;
}

void print_mat3(kfxMat3_t * m) {
  char s[] = "\t{%2.1f, %2.1f, %2.1f}\n";
  printf(s, m->r0.x, m->r0.y, m->r0.z);
  printf(s, m->r[1].x, m->r[1].y, m->r[1].e[2]);
  printf(s, m->r[2].e[0], m->r2.e[1], m->r[2].z);
}

void print_axisang(kfxAxisang_t * a) {
  printf("\t{%2.4f, {%2.4f, %2.4f, %2.4f}}\n", a->a, a->x, a->n.y, a->n.z);
}

void print_quat(kfxQuat_t * q) {
  printf("{%2.1f, %2.1f, %2.1f, %2.1f}\n", q->w, q->x, q->y, q->z);
}

void print_rpy(kfxRpy_t * r) {
  printf("{%2.4f, %2.4f, %2.4f}\n", r->r, r->p, r->y);
}
