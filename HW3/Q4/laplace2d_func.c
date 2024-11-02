#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "laplace2d_func.h"

#define ABS(x) (((x)>0)?(x):-(x))

void get_input(grid *grid2d, int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s Nx Ny tol omega\n", argv[0]);
        exit(1);
    }
    
    grid2d->Nx = atoi(argv[1]);
    grid2d->Ny = atoi(argv[2]);
    grid2d->tol = atof(argv[3]);
    grid2d->omega = atof(argv[4]);
}

void init_domain(grid *grid2d) {
    int Nx = grid2d->Nx;
    int Ny = grid2d->Ny;

    for (int t = 0; t < 2; t++) {
        grid2d->field[t] = (double **)malloc(Nx * sizeof(double *));
        for (int x = 0; x < Nx; x++) {
            grid2d->field[t][x] = (double *)calloc(Ny, sizeof(double));
        }
        for (int y = 0; y < Ny; y++) {
            grid2d->field[t][0][y] = 1.0;
        }
    }
}

void update_domain(grid *grid2d) {
    int Nx = grid2d->Nx;
    int Ny = grid2d->Ny;
    double tol = grid2d->tol;
    double omega = grid2d->omega;
    double delta;
    int counter = 0;
    int tk0, tk1;

    do {
        delta = 0.0;
        tk0 = counter % 2;
        tk1 = !tk0;

        for (int x = 1; x < Nx - 1; x++) {
            for (int y = 1; y < Ny - 1; y++) {
                double new_value = (grid2d->field[tk0][x - 1][y] +
                                    grid2d->field[tk0][x + 1][y] +
                                    grid2d->field[tk0][x][y - 1] +
                                    grid2d->field[tk0][x][y + 1]) * 0.25;
                grid2d->field[tk1][x][y] = grid2d->field[tk0][x][y] + omega * (new_value - grid2d->field[tk0][x][y]);
                delta += ABS(grid2d->field[tk1][x][y] - grid2d->field[tk0][x][y]);
            }
        }
        counter++;
        if (counter % 1000 == 0) {
            printf("Iteration %d, delta = %f\n", counter, delta);
        }
    } while (delta > tol);
}

void free_domain(grid *grid2d) {
    for (int t = 0; t < 2; t++) {
        for (int x = 0; x < grid2d->Nx; x++) {
            free(grid2d->field[t][x]);
        }
        free(grid2d->field[t]);
    }
}
