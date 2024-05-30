#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void External_load(int Nx,int Ny,int t,int Totaltime,double F_external,double Fx_initial[Ny][Nx],double Fy_initial[Ny][Nx],double Fz_initial[Ny][Nx])
{

int i,j,Mass;
if(t<(0.3*Totaltime))
{
if((Nx%2)==1){
Mass=((Nx+1)/2);

for(i=1;i<(Ny-1);i++){
for(j=1;j<(Nx-1);j++){

if(((j)==(Mass-1)) && ((i==1) || (i==(Nx-2)))){  
Fx_initial[i][j]=Fx_initial[i][j];
Fy_initial[i][j]=Fy_initial[i][j]; 
Fz_initial[i][j]=Fz_initial[i][j]+F_external;
}
 else {
  Fx_initial[i][j]=Fx_initial[i][j];
  Fy_initial[i][j]=Fy_initial[i][j];
  Fz_initial[i][j]=Fz_initial[i][j];
   }
  }
 }
  
i=1;
j=(Mass-1);
printf("External Load acting on [%d][%d] mass=%lf \n",i,j,Fz_initial[i][j]);
i=(Nx-2);
printf("External Load acting on [%d][%d] mass=%lf \n",i,j,Fz_initial[i][j]);
}

else{
Mass=(Nx/2);

for(i=1;i<(Ny-1);i++) {
for(j=1;j<(Nx-1);j++) {

   if(((j)==(Mass+1)) && ((i==1) || (i==(Nx-2)))) {
   Fx_initial[i][j]=Fx_initial[i][j];
   Fy_initial[i][j]=Fy_initial[i][j]; 
   Fz_initial[i][j]=Fz_initial[i][j]+F_external;
  }
   else{
   Fx_initial[i][j]=Fx_initial[i][j];
  Fy_initial[i][j]=Fy_initial[i][j];
  Fz_initial[i][j]=Fz_initial[i][j];
       }
  }
 }
i=1;
j=(Mass+1);
printf("External Load acting on [%d][%d] mass=%lf \n",i,j,Fz_initial[i][j]);
i=(Nx-2);
printf("External Load acting on [%d][%d] mass=%lf \n",i,j,Fz_initial[i][j]);
 }

}

}
