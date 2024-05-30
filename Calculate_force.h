#ifndef CALCUATE_FORCE_H_INCLUDE
#define CALCUATE_FORCE_H_INCLUDE

void Calculate_force(int Nx,int Ny,int t,int Totaltime,double KSpring,double Neigh_Left_X[Ny][Nx],double Neigh_Bottom_X[Ny][Nx],double Neigh_Right_X[Ny][Nx],double Neigh_Top_X[Ny][Nx],double Neigh_Left_Y[Ny][Nx],double Neigh_Bottom_Y[Ny][Nx],double Neigh_Right_Y[Ny][Nx],double Neigh_Top_Y[Ny][Nx],double Neigh_Left_Z[Ny][Nx],double Neigh_Bottom_Z[Ny][Nx],double Neigh_Right_Z[Ny][Nx],double Neigh_Top_Z[Ny][Nx],double Fx_initial[Ny][Nx],double Fy_initial[Ny][Nx],double Fz_initial[Ny][Nx],double Fx_update[Ny][Nx],double Fy_update[Ny][Nx],double Fz_update[Ny][Nx],double PosXOld[Ny][Nx],double PosYOld[Ny][Nx],double PosZOld[Ny][Nx]);
#endif
