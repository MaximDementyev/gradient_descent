#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"list.h"

#define accuracy_derivative 0.00000001


struct Vector crushing_step_method (struct Vector coord,double epsilon, int flag_direction){
	struct Vector pref_coord;
	int pos = 1;
	pref_coord=coord;
	coord = crushing_step(coord,flag_direction);
	//printf ("\n !!! %lf %lf %lf    pref %lf %lf %lf\n",coord.x,coord.y,coord.z,pref_coord.x,pref_coord.y,pref_coord.z);
	
	while ((decart_norm(sum_vec(coord,minus(pref_coord))) > epsilon) || (fabs(function_vec(coord)-function_vec(pref_coord)) > epsilon) || (decart_norm(gradient(coord,1)) > epsilon)){
		pos++;
		pref_coord=coord;
		coord = crushing_step(coord,flag_direction);
		//printf ("\n !!! %lf %lf %lf    pref %lf %lf %lf\n",coord.x,coord.y,coord.z,pref_coord.x,pref_coord.y,pref_coord.z);
	}
	printf("pos = %d\n",pos);
	return coord;
}


struct Vector crushing_step (struct Vector coord, int flag_direction){
	struct Vector ungrad;
	double betta = 0.000001, alpha = betta, lambda = 0.5;
	ungrad= minus(gradient(coord, flag_direction));

	//printf ("ungrad%lf %lf %lf\n", ungrad.x, ungrad.y, ungrad.z);
	
	if (function_vec(sum_vec(coord,multiply_vec(ungrad,alpha)))<function_vec(coord)){
		alpha = alpha/lambda;
		while (function_vec(sum_vec(coord,multiply_vec(ungrad,alpha)))<function_vec(sum_vec(coord,multiply_vec(ungrad,betta)))){
			betta = alpha;
			alpha = betta/lambda;
		}
	}else{
		alpha=betta*lambda;
		while (function_vec(sum_vec(coord,multiply_vec(ungrad,alpha)))>function_vec(coord)){
			betta = alpha;
			alpha = betta*lambda;
		}
	}
	coord = sum_vec(coord,multiply_vec(ungrad,betta));
	return coord;
}

