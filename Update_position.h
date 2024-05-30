#ifndef UPDATE_POSITION_H_INCLUDE
#define UPDATE_POSITION_H_INCLUDE

void Update_position(int Nx,int Ny,double Dt,double BMass,double PosXOld[Ny][Nx],double PosYOld[Ny][Nx],double PosZOld[Ny][Nx],double PosXNew[Ny][Nx],double PosYNew[Ny][Nx],double PosZNew[Ny][Nx],double Vx_initial[Ny][Nx],double Vy_initial[Ny][Nx],double Vz_initial[Ny][Nx],double Fx_initial[Ny][Nx],double Fy_initial[Ny][Nx],double Fz_initial[Ny][Nx]);
#endif
