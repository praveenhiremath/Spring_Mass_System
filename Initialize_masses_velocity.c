#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void Initialize_masses_velocity(int Ny,int Nx,double Vx_initial[Ny][Nx],double Vy_initial[Ny][Nx],double Vz_initial[Ny][Nx],double Vx_New[Ny][Nx],double Vy_New[Ny][Nx],double Vz_New[Ny][Nx],double Fx_initial[Ny][Nx],double Fy_initial[Ny][Nx],double Fz_initial[Ny][Nx])
{

int i,j;
//Initializing velocities and forces at t=0 to 0
for(i=0;i<Ny;i++){
for(j=0;j<Nx;j++){
Vx_initial[i][j]=0;
Vy_initial[i][j]=0;
Vz_initial[i][j]=0;
Fx_initial[i][j]=0;
Fy_initial[i][j]=0;
Fz_initial[i][j]=0;

 }
 }

printf("Initial velocity of masses in X direction\n");

for(i=0;i<Ny;i++){
for(j=0;j<Nx;j++){       
printf("%lf\t",Vx_initial[i][j]);
}
printf("\n");
}

printf("Initial velocity of masses in Y direction\n");

for(i=0;i<Ny;i++){
for(j=0;j<Nx;j++){       
printf("%lf\t",Vy_initial[i][j]);
}
printf("\n");
}

printf("Initial velocity of masses in Z direction\n");

for(i=0;i<Ny;i++){
for(j=0;j<Nx;j++){       
printf("%lf\t",Vz_initial[i][j]);
}
printf("\n");
}

}
