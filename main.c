//Assignment 1: Implementation of lattice of masses linked by springs
//Matriculation number: 57955
//Praveenkumar Hiremath
//Computational Material Science



#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"Initialize_masses_position.h"
#include"Initialize_masses_velocity.h"
#include"Define_bc.h"
#include"Build_neigh_list.h"
#include"Calculate_force.h"
#include"Update_position.h"
#include"External_load.h"
#include"Update_velocity.h"
#include"Save_force.h"



int main()
{
// Variable declaration
int i,j,k,l,Nx,Ny,TM,IM,Lx,Ly,t;
FILE *out=fopen("out.dat","w");      // file containing the output datas

printf("Enter the number of masses in X and Y Directions\n");
scanf("%d %d",&Nx,&Ny);


TM=(Nx*Ny);
IM=TM;

printf("Total number of masses:%d\n",TM);
printf("Number of masses for which neighbouring list is to be created:%d\n",IM);


// Variable declaration
double KSpring,BMass;
double PosXOld[Ny][Nx],PosYOld[Ny][Nx],PosZOld[Ny][Nx];
double PosXNew[Ny][Nx],PosYNew[Ny][Nx],PosZNew[Ny][Nx];
double NeighX[IM][4],NeighY[IM][4],NeighZ[IM][4];
double Neigh_Left_X[Ny][Nx],Neigh_Bottom_X[Ny][Nx],Neigh_Right_X[Ny][Nx],Neigh_Top_X[Ny][Nx];//arrays for X Coordinates of Neighbouring masses 
double Neigh_Left_Y[Ny][Nx],Neigh_Bottom_Y[Ny][Nx],Neigh_Right_Y[Ny][Nx],Neigh_Top_Y[Ny][Nx];//arrays for Y Coordinates of Neighbouring masses 
double Neigh_Left_Z[Ny][Nx],Neigh_Bottom_Z[Ny][Nx],Neigh_Right_Z[Ny][Nx],Neigh_Top_Z[Ny][Nx];//arrays for Z Coordinates of Neighbouring masses 
double BOUNC_X[Ny][Nx],BOUNC_Y[Ny][Nx];//Representing boundary conditions
double Vx_initial[Ny][Nx],Vy_initial[Ny][Nx],Vz_initial[Ny][Nx],Vx_New[Ny][Nx],Vy_New[Ny][Nx],Vz_New[Ny][Nx];
int Totaltime;//"Totaltime" is the total time for which the system is observed.
double F_external,Fx_initial[Ny][Nx],Fy_initial[Ny][Nx],Fz_initial[Ny][Nx],Fx_update[Ny][Nx],Fy_update[Ny][Nx],Fz_update[Ny][Nx];
double Time,Dt;//Dt is the incremental time or timestep.


printf("Enter the distance between masses in X and Y Directions\n");
scanf("%d %d",&Lx,&Ly);

printf("Enter external Force: F\n");
scanf("%lf",&F_external);

printf("Enter Spring constant: F\n");
scanf("%lf",&KSpring);

printf("Enter Ball Mass: \n");
scanf("%lf",&BMass);

printf("Enter timestep: Dt\n");
scanf("%lf",&Dt);

printf("Enter totaltime: Totaltime\n");
scanf("%d",&Totaltime);

//Below I tried to call input file. But it was not successful
/*FILE *out=fopen("out.dat","w");      // file containing the output datas
FILE *input;
input=fopen("Input.dat","r");
fscanf(input,"%d %d %d %d %lf %lf %d %lf %lf\n", &Nx, &Ny, &Lx, &Ly, &BMass, &KSpring, &Totaltime,&dt,&F_external); */

//Array Initialization
PosZOld[Ny][Nx]=0.0;

//pointers to arrays. Memory allocation
//Tried to allocate memory but couldnt succeed.

/*double **PosXOld,**PosYOld,**PosZOld;
double **PosXNew,**PosYNew,**PosZNew;
double **NeighX,**NeighY,**NeighZ;
double **Neigh_Left_X,**Neigh_Bottom_X,**Neigh_Right_X,**Neigh_Top_X;
double **Neigh_Left_Y,**Neigh_Bottom_Y,**Neigh_Right_Y,**Neigh_Top_Y;
double **Neigh_Left_Z,**Neigh_Bottom_Z,**Neigh_Right_Z,**Neigh_Top_Z;
double **BOUNC_X,**BOUNC_Y;
double **Vx_initial,**Vy_initial,**Vz_initial;
double **Vx_New,**Vy_New,**Vz_New;
double **Fx_initial,**Fy_initial,**Fz_initial,**Fx_update,**Fy_update,**Fz_update;


  PosXOld = (double **) malloc(sizeof(double *) *Ny);
  PosYOld = (double **) malloc(sizeof(double *) * Ny);
  PosZOld = (double **) malloc(sizeof(double *) * Ny);
  NeighX = (double **) malloc(sizeof(double *) * Ny);
  NeighY = (double **) malloc(sizeof(double *) * Ny);
  NeighZ = (double **) malloc(sizeof(double *) * Ny);
  Neigh_Left_X = (double **) malloc(sizeof(double *) * Ny);
  Neigh_Bottom_X = (double **) malloc(sizeof(double *) * Ny);
  Neigh_Right_X = (double **) malloc(sizeof(double *) * Ny);
  Neigh_Top_X = (double **) malloc(sizeof(double *) * Ny);
  Neigh_Left_Y = (double **) malloc(sizeof(double *) * Ny);
  Neigh_Bottom_Y = (double **) malloc(sizeof(double *) * Ny);
  Neigh_Right_Y = (double **) malloc(sizeof(double *) * Ny);
  Neigh_Top_Y = (double **) malloc(sizeof(double *) * Ny);
  Neigh_Left_Z = (double **) malloc(sizeof(double *) * Ny);
  Neigh_Bottom_Z = (double **) malloc(sizeof(double *) * Ny);
  Neigh_Right_Z = (double **) malloc(sizeof(double *) * Ny);
  Neigh_Top_Z = (double **) malloc(sizeof(double *) * Ny);
  BOUNC_X = (double **) malloc(sizeof(double *) * Ny);
  BOUNC_Y = (double **) malloc(sizeof(double *) * Ny);
  Vx_initial = (double **) malloc(sizeof(double *) * Ny);
  Vy_initial = (double **) malloc(sizeof(double *) * Ny);
  Vz_initial = (double **) malloc(sizeof(double *) * Ny);
  Vx_New = (double **) malloc(sizeof(double *) * Ny);
  Vy_New = (double **) malloc(sizeof(double *) * Ny);
  Vz_New = (double **) malloc(sizeof(double *) * Ny);
  Fx_initial = (double **) malloc(sizeof(double *) * Ny);
  Fy_initial= (double **) malloc(sizeof(double *) * Ny);
  Fz_initial= (double **) malloc(sizeof(double *) * Ny);
  Fx_update= (double **) malloc(sizeof(double *) * Ny);
  Fy_update= (double **) malloc(sizeof(double *) * Ny);
  Fz_update= (double **) malloc(sizeof(double *) * Ny);



  for(i=0; i<Ny; i++)
  {
  PosXOld[i] = (double *) malloc(sizeof(double ) * Nx);
  PosYOld[i] = (double *) malloc(sizeof(double ) * Nx);
  PosZOld[i] = (double *) malloc(sizeof(double ) * Nx);
  NeighX[i] = (double *) malloc(sizeof(double ) * Nx);
  NeighY[i] = (double *) malloc(sizeof(double ) * Nx);
  NeighZ[i] = (double *) malloc(sizeof(double ) * Nx);
  Neigh_Left_X[i] = (double *) malloc(sizeof(double ) * Nx);
  Neigh_Bottom_X[i] = (double *) malloc(sizeof(double ) * Nx);
  Neigh_Right_X[i] = (double *) malloc(sizeof(double ) * Nx);
  Neigh_Top_X[i] = (double *) malloc(sizeof(double ) * Nx);
  Neigh_Left_Y[i] = (double *) malloc(sizeof(double ) * Nx);
  Neigh_Bottom_Y[i] = (double *) malloc(sizeof(double ) * Nx);
  Neigh_Right_Y[i] = (double *) malloc(sizeof(double ) * Nx);
  Neigh_Top_Y[i] = (double *) malloc(sizeof(double ) * Nx);
  Neigh_Left_Z[i] = (double **) malloc(sizeof(double *) * Nx);
  Neigh_Bottom_Z[i] = (double **) malloc(sizeof(double *) * Nx);
  Neigh_Right_Z[i] = (double **) malloc(sizeof(double *) * Nx);
  Neigh_Top_Z[i] = (double **) malloc(sizeof(double *) * Nx);
  BOUNC_X[i] = (double *) malloc(sizeof(double ) * Nx);
  BOUNC_Y[i] = (double *) malloc(sizeof(double ) * Nx);
  Vx_initial[i] = (double *) malloc(sizeof(double ) * Nx);
  Vy_initial[i] = (double *) malloc(sizeof(double ) * Nx);
  Vz_initial[i] = (double *) malloc(sizeof(double ) * Nx);
  Vx_New[i] = (double *) malloc(sizeof(double ) * Nx);
  Vy_New[i] = (double *) malloc(sizeof(double ) * Nx);
  Vz_New[i] = (double *) malloc(sizeof(double ) * Nx);
  Fx_initial[i] = (double *) malloc(sizeof(double ) * Nx);
  Fy_initial[i]= (double *) malloc(sizeof(double ) * Nx);
  Fz_initial[i]= (double *) malloc(sizeof(double ) * Nx);
  Fx_update[i]= (double *) malloc(sizeof(double ) * Nx);
  Fy_update[i]= (double *) malloc(sizeof(double ) * Nx);
  Fz_update[i]= (double *) malloc(sizeof(double ) * Nx);
  }
*/


Initialize_masses_position(Nx,Ny,PosXOld,PosYOld,PosZOld,TM,IM,Lx,Ly);//Function for initial mass positions

Initialize_masses_velocity(Ny,Nx,Vx_initial,Vy_initial,Vz_initial,Vx_New,Vy_New,Vz_New,Fx_initial,Fy_initial,Fz_initial);//Function for initial velocity

Define_bc(Nx,Ny,PosXOld,PosYOld,PosZOld,BOUNC_X,BOUNC_Y,Lx,Ly);//Boundary condition

Build_neigh_list(Nx,Ny,IM,PosXOld,PosYOld,PosZOld,NeighX,NeighY,NeighZ,Neigh_Left_X,Neigh_Bottom_X,Neigh_Right_X,Neigh_Top_X,Neigh_Left_Y,Neigh_Bottom_Y,Neigh_Right_Y,Neigh_Top_Y,Neigh_Left_Z,Neigh_Bottom_Z,Neigh_Right_Z,Neigh_Top_Z);


Calculate_force(Nx,Ny,t,Totaltime,KSpring,Neigh_Left_X,Neigh_Bottom_X,Neigh_Right_X,Neigh_Top_X,Neigh_Left_Y,Neigh_Bottom_Y,Neigh_Right_Y,Neigh_Top_Y,Neigh_Left_Z,Neigh_Bottom_Z,Neigh_Right_Z,Neigh_Top_Z,Fx_initial,Fy_initial,Fz_initial,Fx_update,Fy_update,Fz_update,PosXOld, PosYOld,PosZOld);

//Time loop running till the given totaltime
for(t=1;t<=Totaltime;t++)
{

Update_position(Nx,Ny,Dt,BMass,PosXOld,PosYOld,PosZOld,PosXNew,PosYNew,PosZNew,Vx_initial,Vy_initial,Vz_initial,Fx_initial,Fy_initial,Fz_initial);

External_load(Nx,Ny,t,Totaltime,F_external,Fx_initial,Fy_initial,Fz_initial);

Calculate_force(Nx,Ny,t,Totaltime,KSpring,Neigh_Left_X,Neigh_Bottom_X,Neigh_Right_X,Neigh_Top_X,Neigh_Left_Y,Neigh_Bottom_Y,Neigh_Right_Y,Neigh_Top_Y,Neigh_Left_Z,Neigh_Bottom_Z,Neigh_Right_Z,Neigh_Top_Z,Fx_initial,Fy_initial,Fz_initial,Fx_update,Fy_update,Fz_update,PosXOld, PosYOld,PosZOld);


Update_velocity(Ny,Nx,t,Totaltime,Dt,BMass,Vx_New,Vy_New,Vz_New,Vx_initial,Vy_initial,Vz_initial,Fx_initial,Fy_initial,Fz_initial,Fx_update,Fy_update,Fz_update);

Save_force(Nx,Ny,PosXOld,PosZOld,PosZOld,Fx_initial,Fy_initial,Fz_initial,Fx_update,Fy_update,Fz_update);

for(i=0;i<Ny;i++)
{ for(j=0;j<Nx;j++)
  {
printf("X coordinates of masses at time %d : %lf\n",t,PosXOld[i][j]);
printf("Y coordinates of masses at time %d : %lf\n",t,PosYOld[i][j]);
printf("Z coordinates of masses at time %d : %lf\n",t,PosZOld[i][j]);

  }
}
//To write in output file.Here at a particular time, in the beginning 1st row mass positions followed by subsequent row mass positions are stored ie at i=0,for all j,then i=1 and for all j and so on
for(i=0;i<Ny;i++)
{ for(j=0;j<Nx;j++)
  {
fprintf(out,"X coordinates of masses at time %d : %lf\n",t,PosXOld[i][j]);
fprintf(out,"Y coordinates of masses at time %d : %lf\n",t,PosYOld[i][j]);
fprintf(out,"Z coordinates of masses at time %d : %lf\n",t,PosZOld[i][j]);

  }
}

}
return 0;
}
