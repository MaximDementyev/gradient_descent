#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"list.h"

#define accuracy_derivative 0.00000001


struct Vector tangent_method (struct Vector coord,double epsilon,int flag_direction){
	struct Vector pref_coord;
	int pos = 1;
	pref_coord=coord;
	coord = tangent(coord,epsilon,flag_direction);
	//printf ("\n !!! %lf %lf %lf    pref %lf %lf %lf\n",coord.x,coord.y,coord.z,pref_coord.x,pref_coord.y,pref_coord.z);
	
	while ((decart_norm(sum_vec(coord,minus(pref_coord))) > epsilon) || (fabs(function_vec(coord)-function_vec(pref_coord)) > epsilon) || (decart_norm(gradient(coord,1)) > epsilon)){
		pos++;
		pref_coord=coord;
		coord = tangent(coord,epsilon,flag_direction);
		//printf ("\n !!! %lf %lf %lf    pref %lf %lf %lf\n",coord.x,coord.y,coord.z,pref_coord.x,pref_coord.y,pref_coord.z);
	}
	printf("pos = %d\n",pos);
	return coord;
}

struct Vector tangent (struct Vector coord,double epsilon, int flag_direction){
	struct Vector ungrad, coord1;
	double betta = 0.1, cn = betta,an=0,bn=betta;
	ungrad = minus(gradient(coord, flag_direction));
	//printf ("ungrad= %lf %lf %lf\n",ungrad.x,ungrad.y,ungrad.z);
	coord1=sum_vec(coord,multiply_vec(ungrad,betta));
	//printf ("\n\nfirst point = %lf %lf %lf\n",coord.x,coord.y,coord.z);
	//printf ("second point = %lf %lf %lf\n",coord1.x,coord1.y,coord1.z);
	while (fabs(derivative(sum_vec(coord,multiply_vec(ungrad,cn)),ungrad)) >= epsilon){
		//printf ("first point = %lf %lf %lf\n",coord.x,coord.y,coord.z);
		//printf ("second point = %lf %lf %lf\n",coord1.x,coord1.y,coord1.z);
		//printf("cn = %lf\n",cn);
		if ((derivative(coord,ungrad) < 0 && derivative(coord1,ungrad) > 0) || (derivative(coord,ungrad) > 0 && derivative(coord1,ungrad) < 0)){
			cn = (function_vec(coord)-function_vec(coord1)+derivative(coord1,ungrad)*bn-derivative(coord,ungrad)*an)/(derivative(coord1,ungrad)-(derivative(coord,ungrad)));
			
			if (derivative(sum_vec(coord,multiply_vec(ungrad,cn)),ungrad) < 0){
				coord = sum_vec(coord,multiply_vec(ungrad,cn-an));	
				an=cn;
				//printf ("an = %lf\n",an);
			}else{
				coord1 = sum_vec(coord,multiply_vec(ungrad,cn-an));
				bn=cn;
				//printf ("bn = %lf, an = %lf\n",bn,an);
			}
		}else{
			coord = coord1;
			ungrad= minus(gradient(coord, flag_direction));
			coord1 = sum_vec(coord,multiply_vec(ungrad,cn));
		}
		//printf("\n\n");
	}
	coord = sum_vec(coord,multiply_vec(ungrad,cn));
	return coord;
}
