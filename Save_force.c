#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void Save_force(int Nx,int Ny,double PosXOld[Ny][Nx],double PosYOld[Ny][Nx],double PosZOld[Ny][Nx],double Fx_initial[Ny][Nx],double Fy_initial[Ny][Nx],double Fz_initial[Ny][Nx],double Fx_update[Ny][Nx],double Fy_update[Ny][Nx],double Fz_update[Ny][Nx])
{
int i,j;
for(i=0;i<Ny;i++){
for(j=0;j<Nx;j++){       
printf("Fx_initial= %lf\n",Fx_initial[i][j]);
Fx_initial[i][j]=Fx_update[i][j];
printf("Updated Fx_initial=%lf\n",Fx_initial[i][j]);

printf("Fy_initial= %lf\n",Fy_initial[i][j]);
Fy_initial[i][j]=Fy_update[i][j];
printf("Updated Fy_initial=%lf\n",Fy_initial[i][j]);

printf("Fz_initial= %lf\n",Fz_initial[i][j]);
Fz_initial[i][j]=Fz_update[i][j];
printf("Updated Fz_initial=%lf\n",Fz_initial[i][j]);
}

}



}

