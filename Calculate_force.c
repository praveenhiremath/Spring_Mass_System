#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void Calculate_force(int Nx,int Ny,int t,int Totaltime,double KSpring,double Neigh_Left_X[Ny][Nx],double Neigh_Bottom_X[Ny][Nx],double Neigh_Right_X[Ny][Nx],double Neigh_Top_X[Ny][Nx],double Neigh_Left_Y[Ny][Nx],double Neigh_Bottom_Y[Ny][Nx],double Neigh_Right_Y[Ny][Nx],double Neigh_Top_Y[Ny][Nx],double Neigh_Left_Z[Ny][Nx],double Neigh_Bottom_Z[Ny][Nx],double Neigh_Right_Z[Ny][Nx],double Neigh_Top_Z[Ny][Nx],double Fx_initial[Ny][Nx],double Fy_initial[Ny][Nx],double Fz_initial[Ny][Nx],double Fx_update[Ny][Nx],double Fy_update[Ny][Nx],double Fz_update[Ny][Nx],double PosXOld[Ny][Nx],double PosYOld[Ny][Nx],double PosZOld[Ny][Nx])

{

int i,j;
//Neglecting the boundary masses
for(i=1;i<(Ny-1);i++)
{
 for(j=1;j<(Nx-1);j++)
  {
//Fx_update[i][j]=Fx_initial[i][j]-(KSpring*(4(PosXOld[i][j])-(Neigh_Left_X[i][j]+Neigh_Bottom_X[i][j]+Neigh_Right_X[i][j]+Neigh_Top_X[i][j])));
Fx_update[i][j]=Fx_initial[i][j]-KSpring*((PosXOld[i][j]-Neigh_Left_X[i][j])+(PosXOld[i][j]-Neigh_Bottom_X[i][j])+(PosXOld[i][j]-Neigh_Right_X[i][j])+(PosXOld[i][j]-Neigh_Top_X[i][j]));
//Fx[t][i][j]=Fx_update[i][j];


//Fy_update[i][j]=Fy_initial[i][j]-(KSpring*(4(PosYOld[i][j])-(Neigh_Left_Y[i][j]+Neigh_Bottom_Y[i][j]+Neigh_Right_Y[i][j]+Neigh_Top_Y[i][j])));
Fy_update[i][j]=Fy_initial[i][j]-KSpring*((PosYOld[i][j]-Neigh_Left_Y[i][j])+(PosYOld[i][j]-Neigh_Bottom_Y[i][j])+(PosYOld[i][j]-Neigh_Right_Y[i][j])+(PosYOld[i][j]-Neigh_Top_Y[i][j]));
//Fy[t][i][j]=Fy_update[i][j];


//Fz_update[i][j]=Fz_initial[i][j]-(KSpring*(4(PosZOld[i][j])-(Neigh_Left_Z[i][j]+Neigh_Bottom_Z[i][j]+Neigh_Right_Z[i][j]+Neigh_Top_Z[i][j])));
Fz_update[i][j]=Fz_initial[i][j]-KSpring*((PosZOld[i][j]-Neigh_Left_Z[i][j])+(PosZOld[i][j]-Neigh_Bottom_Z[i][j])+(PosZOld[i][j]-Neigh_Right_Z[i][j])+(PosZOld[i][j]-Neigh_Top_Z[i][j]));
//Fz[t][i][j]=Fz_update[i][j];

  }

}

}
