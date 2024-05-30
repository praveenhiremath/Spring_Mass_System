#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void Update_position(int Nx,int Ny,double Dt,double BMass,double PosXOld[Ny][Nx],double PosYOld[Ny][Nx],double PosZOld[Ny][Nx],double PosXNew[Ny][Nx],double PosYNew[Ny][Nx],double PosZNew[Ny][Nx],double Vx_initial[Ny][Nx],double Vy_initial[Ny][Nx],double Vz_initial[Ny][Nx],double Fx_initial[Ny][Nx],double Fy_initial[Ny][Nx],double Fz_initial[Ny][Nx])

{

int i,j;
for(i=1;i<(Ny-1);i++)
{
for(j=1;j<(Nx-1);j++)
  {
   PosXNew[i][j]=PosXOld[i][j]+Vx_initial[i][j]+((0.5*Fx_initial[i][j]*Dt*Dt)/BMass);
   PosXOld[i][j]=PosXNew[i][j];//Storing New positions in Old position array
   PosYNew[i][j]=PosYOld[i][j]+Vy_initial[i][j]+((0.5*Fy_initial[i][j]*Dt*Dt)/BMass);
   PosYOld[i][j]=PosYNew[i][j];//Storing New positions in Old position array
   PosZNew[i][j]=PosZOld[i][j]+Vz_initial[i][j]+((0.5*Fz_initial[i][j]*Dt*Dt)/BMass);
   PosZOld[i][j]=PosZNew[i][j]; //Storing New positions in Old position array
  }
}

}
