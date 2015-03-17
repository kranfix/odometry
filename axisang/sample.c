#include <stdio.h>
#include "axisang.h"
#include <math.h>

void print_axisang(kfxAxisang_t * m);

int main() {
    kfxAxisang_t ai = {1.5, .n={3.0, 4.0, 6.0}};
    kfxAxisang_t ao;

    // Inputs
    printf("a = ");
    print_axisang(&ai);	

    // Normalize
    int err;
    kfxAxisang_normalize(&ao, &ai, &err);
    printf("nomalize(a) = ");
    print_axisang(&ao);	
    printf("err: %d\n", err);

    return 0;
}

void print_axisang(kfxAxisang_t * a) {
    printf("\t{%2.4f, {%2.4f, %2.4f, %2.4f}}\n", a->a, a->x, a->n.y, a->n.z);
}
