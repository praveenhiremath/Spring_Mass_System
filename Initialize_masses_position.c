#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void Initialize_masses_position(int Nx,int Ny,double PosXOld[Ny][Nx],double PosYOld[Ny][Nx],double PosZOld[Ny][Nx],int TM,int IM,int Lx,int Ly)
{

int i,j,k,l;

printf("Total number of masses:%d \n",TM);//TM=Tota number of masses=IM

printf("Number of masses for which neighbouring list is to be created:%d\n",IM);

//Calculating positions
for(i=0;i<Ny;i++){
for(j=0;j<Nx;j++){
PosXOld[i][j]=Lx*j;
PosYOld[i][j]=Ly*i;
PosZOld[i][j]=0;
}
}

for(i=0;i<Ny;i++){
for(j=0;j<Nx;j++){       
printf("X Coordinates of PosXOld[%d][%d]:%lf\t",i,j,PosXOld[i][j]);
}
printf("\n");
}

for(i=0;i<Ny;i++){
for(j=0;j<Nx;j++){       
printf("Y Coordinates of PosYOld[%d][%d]:%lf\t",i,j,PosYOld[i][j]);
}
printf("\n");
}

}
