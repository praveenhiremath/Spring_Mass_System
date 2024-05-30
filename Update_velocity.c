#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void Update_velocity(int Ny,int Nx,int t,int Totaltime,double Dt,double BMass,double Vx_New[Ny][Nx],double Vy_New[Ny][Nx],double Vz_New[Ny][Nx],double Vx_initial[Ny][Nx],double Vy_initial[Ny][Nx],double Vz_initial[Ny][Nx],double Fx_initial[Ny][Nx],double Fy_initial[Ny][Nx],double Fz_initial[Ny][Nx],double Fx_update[Ny][Nx],double Fy_update[Ny][Nx],double Fz_update[Ny][Nx])

{
int i,j;
for(i=0;i<Ny;i++)
{
  for(j=0;j<Nx;j++)
  {
   Vx_New[i][j]=Vx_initial[i][j]+(0.5*Dt*(Fx_initial[i][j]+Fx_update[i][j])/BMass);
  }
}

}
