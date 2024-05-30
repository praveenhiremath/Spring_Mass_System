#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void Define_bc(int Nx,int Ny,double PosXOld[Ny][Nx],double PosYOld[Ny][Nx],double PosZOld[Ny][Nx],double BOUNC_X[Ny][Nx],double BOUNC_Y[Ny][Nx],int Lx,int Ly)

{

//Boundary conditions assigning

int i,j,k,l;
k=0;
i=0;

while(i<=(Ny-1)){ 
j=0;

while(j<=(Nx-1)){

if((i==0) && (j==0)){  //First mass
  BOUNC_X[i][j]=0;
  BOUNC_Y[i][j]=0;
}
   
 else if((i==0) && (j!=0)){  //1st row masses
 BOUNC_X[i][j]=0;
 BOUNC_Y[i][j]=0;
}

 else if((i==0) && (j==(Nx-1))){    //last mass in 1st row
  BOUNC_X[i][j]=0;
  BOUNC_Y[i][j]=0;
}
   
 else if((i!=0) && (j==(Nx-1))){   //last column
  BOUNC_X[i][j]=0;
  BOUNC_Y[i][j]=0;
}
   
 else if((i==(Ny-1)) && (j==(Nx-1))){  //last row
  BOUNC_X[i][j]=0;
  BOUNC_Y[i][j]=0;
}
	 
 else if((i==(Ny-1)) && (j!=0)){    //last row
  BOUNC_X[i][j]=0;
  BOUNC_Y[i][j]=0;
} 
  
 else if((i==(Ny-1)) && (j==0)){   //1st column
  BOUNC_X[i][j]=0;
  BOUNC_Y[i][j]=0;
}
	
 else if(((i!=(Ny-1)) && (i!=0)) && (j==0)){ //1st column
  BOUNC_X[i][j]=0;
  BOUNC_Y[i][j]=0;
}
   
 else{
 BOUNC_X[i][j]=PosXOld[i][j];
 BOUNC_Y[i][j]=PosYOld[i][j]; 
}

j++;
}
i++;

}

printf("Boundary conditions X displacement\n");

for(i=0;i<Ny;i++){
for(j=0;j<Nx;j++){       
printf("%lf\t",BOUNC_X[i][j]);
}
printf("\n");
}

printf("Boundary conditions Y displacement\n");

for(i=0;i<Ny;i++){
for(j=0;j<Nx;j++){       
printf("%lf\t",BOUNC_Y[i][j]);
}
printf("\n");
}

}
