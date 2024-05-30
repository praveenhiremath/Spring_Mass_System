#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void Build_neigh_list(int Nx,int Ny,int IM,double PosXOld[Ny][Nx],double PosYOld[Ny][Nx],double PosZOld[Ny][Nx],double NeighX[IM][4],double NeighY[IM][4],double NeighZ[IM][4],double Neigh_Left_X[Ny][Nx],double Neigh_Bottom_X[Ny][Nx],double Neigh_Right_X[Ny][Nx],double Neigh_Top_X[Ny][Nx],double Neigh_Left_Y[Ny][Nx],double Neigh_Bottom_Y[Ny][Nx],double Neigh_Right_Y[Ny][Nx],double Neigh_Top_Y[Ny][Nx],double Neigh_Left_Z[Ny][Nx],double Neigh_Bottom_Z[Ny][Nx],double Neigh_Right_Z[Ny][Nx],double Neigh_Top_Z[Ny][Nx])
{

int i,j,k,l;
k=0;
i=0;

while(i<=(Ny-1)){ 
j=0;

while(j<=(Nx-1)){

if((i==0) && (j==0)){
  NeighX[k][0]= 0;
  NeighX[k][1]= PosXOld[i+1][j];
  NeighX[k][2]= PosXOld[i][j+1];
  NeighX[k][3]= 0;

     NeighY[k][0]= 0;
     NeighY[k][1]= PosYOld[i+1][j];
     NeighY[k][2]= PosYOld[i][j+1];
     NeighY[k][3]= 0;

     NeighZ[k][0]= 0;
     NeighZ[k][1]= PosZOld[i+1][j];
     NeighZ[k][2]= PosZOld[i][j+1];
     NeighZ[k][3]= 0;
   }
   
 else if((i==0) && (j!=0)){
    NeighX[k][0]= PosXOld[i][j-1];
    NeighX[k][1]= PosXOld[i+1][j];
    NeighX[k][2]= PosXOld[i][j+1];
    NeighX[k][3]= 0;

    NeighY[k][0]= PosYOld[i][j-1];
    NeighY[k][1]= PosYOld[i+1][j];
    NeighY[k][2]= PosYOld[i][j+1];
    NeighY[k][3]= 0;
 
    NeighZ[k][0]= PosZOld[i][j-1];
    NeighZ[k][1]= PosZOld[i+1][j];
    NeighZ[k][2]= PosZOld[i][j+1];
    NeighZ[k][3]= 0;
   }

 else if((i==0) && (j==(Nx-1))){
  
     NeighX[k][0]= PosXOld[i][j-1];
     NeighX[k][1]= PosXOld[i+1][j];
     NeighX[k][2]= 0;
     NeighX[k][3]= 0;

     NeighY[k][0]= PosYOld[i][j-1];
     NeighY[k][1]= PosYOld[i+1][j];
     NeighY[k][2]= 0;
     NeighY[k][3]= 0;

     NeighZ[k][0]= PosZOld[i][j-1];
     NeighZ[k][1]= PosZOld[i+1][j];
     NeighZ[k][2]= 0;
     NeighZ[k][3]= 0;
   }
   
 else if((i!=0) && (j==(Nx-1))){
     NeighX[k][0]= PosXOld[i][j-1];
     NeighX[k][1]= PosXOld[i+1][j];
     NeighX[k][2]= 0;
     NeighX[k][3]= PosXOld[i-1][j];

     NeighY[k][0]= PosYOld[i][j-1];
     NeighY[k][1]= PosYOld[i+1][j];
     NeighY[k][2]= 0;
     NeighY[k][3]= PosYOld[i-1][j];

     NeighZ[k][0]= PosZOld[i][j-1];
     NeighZ[k][1]= PosZOld[i+1][j];
     NeighZ[k][2]= 0;
     NeighZ[k][3]= PosZOld[i-1][j];
   }
   
 else if((i==(Ny-1)) && (j==(Nx-1))){
      NeighX[k][0]= PosXOld[i][j-1];
      NeighX[k][1]= 0;
      NeighX[k][2]= 0;
      NeighX[k][3]= PosXOld[i-1][j];

      NeighY[k][0]= PosYOld[i][j-1];
      NeighY[k][1]= 0;
      NeighY[k][2]= 0;
      NeighY[k][3]= PosYOld[i-1][j];

      NeighZ[k][0]= PosZOld[i][j-1];
      NeighZ[k][1]= 0;
      NeighZ[k][2]= 0;
      NeighZ[k][3]= PosZOld[i-1][j];
     }
	 
 else if((i==(Ny-1)) && (j!=0)){
   NeighX[k][0]= PosXOld[i][j-1];
   NeighX[k][1]= 0;
   NeighX[k][2]= PosXOld[i][j+1];
   NeighX[k][3]= PosXOld[i-1][j];

   NeighY[k][0]= PosYOld[i][j-1];
   NeighY[k][1]= 0;
   NeighY[k][2]= PosYOld[i][j+1];
   NeighY[k][3]= PosYOld[i-1][j];

   NeighZ[k][0]= PosZOld[i][j-1];
   NeighZ[k][1]= 0;
   NeighZ[k][2]= PosZOld[i][j+1];
   NeighZ[k][3]= PosZOld[i-1][j];
  } 
  
 else if((i==(Ny-1)) && (j==0)){
    NeighX[k][0]= 0;
     NeighX[k][1]= 0;
     NeighX[k][2]= PosXOld[i][j+1];
     NeighX[k][3]= PosXOld[i-1][j];

     NeighY[k][0]= 0;
     NeighY[k][1]= 0;
     NeighY[k][2]= PosYOld[i][j+1];
     NeighY[k][3]= PosYOld[i-1][j];

     NeighZ[k][0]= 0;
     NeighZ[k][1]= 0;
     NeighZ[k][2]= PosZOld[i][j+1];
     NeighZ[k][3]= PosZOld[i-1][j];
    }
	
 else if(((i!=(Ny-1)) && (i!=0)) && (j==0)){
     NeighX[k][0]= 0;
     NeighX[k][1]= PosXOld[i+1][j];
     NeighX[k][2]= PosXOld[i][j+1];
     NeighX[k][3]= PosXOld[i-1][j];

     NeighY[k][0]= 0;
     NeighY[k][1]= PosYOld[i+1][j];
     NeighY[k][2]= PosYOld[i][j+1];
     NeighY[k][3]= PosYOld[i-1][j];

     NeighZ[k][0]= 0;
     NeighZ[k][1]= PosZOld[i+1][j];
     NeighZ[k][2]= PosZOld[i][j+1];
     NeighZ[k][3]= PosZOld[i-1][j];
   }
   
 else {
	
    NeighX[k][0]= PosXOld[i][j-1];
    NeighX[k][1]= PosXOld[i+1][j];
    NeighX[k][2]= PosXOld[i][j+1];
    NeighX[k][3]= PosXOld[i-1][j];

    NeighY[k][0]= PosYOld[i][j-1];
    NeighY[k][1]= PosYOld[i+1][j];
    NeighY[k][2]= PosYOld[i][j+1];
    NeighY[k][3]= PosYOld[i-1][j];

    NeighZ[k][0]= PosZOld[i][j-1];
    NeighZ[k][1]= PosZOld[i+1][j];
    NeighZ[k][2]= PosZOld[i][j+1];
    NeighZ[k][3]= PosZOld[i-1][j]; 
   }

k++;
j++;
}
i++;
}


for(k=0;k<IM;k++){
printf("X Coordinate of Neighbours in the order Left,Bottom,Right,Top:\n");
for(l=0;l<4;l++){       
printf("%lf\t",NeighX[k][l]);
}
printf("\n");
}


for(k=0;k<IM;k++){
printf("Y Coordinate of Neighbours in the order Left,Bottom,Right,Top::\n");
for(l=0;l<4;l++){       
printf("%lf\t",NeighY[k][l]);
}
printf("\n");
}


//Copying X Coordinates of Neighbours into new arrays 
k=0;
for(i=0;i<Ny;i++){ 
l=0;
for(j=0;j<Nx;j++){
Neigh_Left_X[i][j]=NeighX[k][l];
l++;
Neigh_Bottom_X[i][j]=NeighX[k][l];
l++;
Neigh_Right_X[i][j]=NeighX[k][l];
l++;
Neigh_Top_X[i][j]=NeighX[k][l];
l=0;
k++;
}
}


//Copying Y Coordinates of Neighbours into new arrays
k=0;
for(i=0;i<Ny;i++){ 
l=0;
for(j=0;j<Nx;j++){
Neigh_Left_Y[i][j]=NeighY[k][l];
l++;
Neigh_Bottom_Y[i][j]=NeighY[k][l];
l++;
Neigh_Right_Y[i][j]=NeighY[k][l];
l++;
Neigh_Top_Y[i][j]=NeighY[k][l];
l=0;
k++;
}
}


//Copying Y Coordinates of Neighbours into new arrays
k=0;
for(i=0;i<Ny;i++){ 
l=0;
for(j=0;j<Nx;j++){
Neigh_Left_Z[i][j]=NeighZ[k][l];
l++;
Neigh_Bottom_Z[i][j]=NeighZ[k][l];
l++;
Neigh_Right_Z[i][j]=NeighZ[k][l];
l++;
Neigh_Top_Z[i][j]=NeighZ[k][l];
l=0;
k++;
}
}

//Printing neighbouring list
printf("X coordinates of neighbours\n");
for(i=0;i<Ny;i++)
{
for(j=0;j<Ny;j++)
{
printf("%lf %lf %lf %lf\n",Neigh_Left_X[i][j],Neigh_Bottom_X[i][j],Neigh_Right_X[i][j],Neigh_Top_X[i][j]);
}
}

printf("Y coordinates of neighbours\n");
for(i=0;i<Ny;i++)
{
for(j=0;j<Ny;j++)
{
printf("%lf %lf %lf %lf\n",Neigh_Left_Y[i][j],Neigh_Bottom_Y[i][j],Neigh_Right_Y[i][j],Neigh_Top_Y[i][j]);
}
}


}
