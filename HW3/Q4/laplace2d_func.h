#ifndef MY_2D_LAPLACE_SOLVER_H_
#define MY_2D_LAPLACE_SOLVER_H_

struct Grid2D {
    int Nx;
    int Ny;
    double tol;   // convergence tolerance 
    double omega; // successive over-relaxation parameter, 1.5
    double **field[2]; // 3D array field[time][x][y]
};

typedef struct Grid2D grid;  // grid is a shortcut to struct Grid2D

// Function declarations
void get_input(grid *grid2d, int argc, char **argv);
void init_domain(grid *grid2d);
void update_domain(grid *grid2d);
void free_domain(grid *grid2d);

#endif
