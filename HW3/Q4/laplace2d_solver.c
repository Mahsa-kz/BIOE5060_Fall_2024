#include <stdio.h>
#include "laplace2d_func.h"

int main(int argc, char **argv) {
    grid domain;

    get_input(&domain, argc, argv);
    init_domain(&domain);
    update_domain(&domain);
    free_domain(&domain);

    return 0;
}
