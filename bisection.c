#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"list.h"

#define accuracy_derivative 0.00000001

struct Vector bisection_method (struct Vector coord,double epsilon, int flag_direction){
	struct Vector pref_coord;
	int pos = 1;
	pref_coord=coord;
	coord = bisection(coord,epsilon,flag_direction);
	//printf ("\n !!! %lf %lf %lf    pref %lf %lf %lf\n",coord.x,coord.y,coord.z,pref_coord.x,pref_coord.y,pref_coord.z);
	
	while ((decart_norm(sum_vec(coord,minus(pref_coord))) > epsilon) || (fabs(function_vec(coord)-function_vec(pref_coord)) > epsilon) || (decart_norm(gradient(coord,1)) > epsilon)){
		pos++;
		pref_coord=coord;
		coord = bisection(coord,epsilon,flag_direction);
		//printf ("\n !!! %lf %lf %lf    pref %lf %lf %lf\n",coord.x,coord.y,coord.z,pref_coord.x,pref_coord.y,pref_coord.z);
	}
	printf("pos = %d\n",pos);
	return coord;
}


struct Vector bisection (struct Vector coord, double epsilon, int flag_direction){
	struct Vector ungrad;
	double a=0,b=1,betta = 0.001,value_c,value_d;
	ungrad = minus(gradient(coord, flag_direction));
	
	while (b-a > epsilon){
		if (function_vec(sum_vec(coord,multiply_vec(ungrad,(b+a)/2-betta))) < function_vec(sum_vec(coord,multiply_vec(ungrad,(b+a)/2+betta)))) 
			b = (b+a)/2;
		else
			a = (b+a)/2;
	}
	coord = sum_vec(coord,multiply_vec(ungrad,b));
	return coord;
}
