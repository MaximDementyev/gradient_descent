#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"list.h"

#define t 0.00001

struct Vector Newton_method (struct Vector point){
	int i,j;
	double matrix[3][3], inverse_matrix[3][3], grad_matr[3], det_matrix=0,x,y,z;
	struct Vector grad = gradient(point,1);
	struct Vector napravlenie;
	x=point.x;
	y=point.y;
	z=point.z;
	
	grad_matr[0]=grad.x;
	grad_matr[1]=grad.y;
	grad_matr[2]=grad.z;

	matrix[0][0]=(function(x+2*t,y,z)-2*function(x,y,z)+function(x-2*t,y,z))/(4*t*t);
	matrix[0][1]=(function(x+t,y+t,z)-function(x+t,y-t,z)-function(x-t,y+t,z)+function(x-t,y-t,z))/(4*t*t);
	matrix[0][2]=(function(x+t,y,z+t)-function(x+t,y,z-t)-function(x-t,y,z+t)+function(x-t,y,z-t))/(4*t*t);
	matrix[1][0]=matrix[0][1];
	matrix[1][1]=(function(x,y+2*t,z)-2*function(x,y,z)+function(x,y-2*t,z))/(4*t*t);
	matrix[1][2]=(function(x,y+t,z+t)-function(x,y-t,z+t)-function(x,y+t,z-t)+function(x,y-t,z-t))/(4*t*t);
	matrix[2][0]=matrix[0][2];
	matrix[2][1]=matrix[1][2];
	matrix[2][2]=(function(x,y,z+2*t)-2*function(x,y,z)+function(x,y,z-2*t))/(4*t*t);

	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			inverse_matrix[i][j]=matrix[(i+1)%3][(j+1)%3]*matrix[(i+2)%3][(j+2)%3]-matrix[(i+1)%3][(j+2)%3]*matrix[(i+2)%3][(j+1)%3];

	for(i=0;i<3;i++)
		det_matrix=det_matrix+matrix[i][0]*inverse_matrix[i][0];

	/*for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			inverse_matrix[i][j]=inverse_matrix[i][j]/det_matrix;*/

	for(i=0;i<3;i++){
		napravlenie.x=napravlenie.x+inverse_matrix[0][i]*grad_matr[i];
		napravlenie.y=napravlenie.y+inverse_matrix[1][i]*grad_matr[i];
		napravlenie.z=napravlenie.z+inverse_matrix[2][i]*grad_matr[i];
	}
	return napravlenie;
}


