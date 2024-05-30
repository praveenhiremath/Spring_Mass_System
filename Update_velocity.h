#ifndef UPDATE_VELOCITY_H_INCLUDE
#define UPDATE_VELOCITY_H_INCLUDE

void Update_velocity(int Ny,int Nx,int t,int Totaltime,double Dt,double BMass,double Vx_New[Ny][Nx],double Vy_New[Ny][Nx],double Vz_New[Ny][Nx],double Vx_initial[Ny][Nx],double Vy_initial[Ny][Nx],double Vz_initial[Ny][Nx],double Fx_initial[Ny][Nx],double Fy_initial[Ny][Nx],double Fz_initial[Ny][Nx],double Fx_update[Ny][Nx],double Fy_update[Ny][Nx],double Fz_update[Ny][Nx]);
#endif
