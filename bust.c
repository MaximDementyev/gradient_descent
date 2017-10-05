#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"list.h"

#define accuracy_derivative 0.00000001

struct Vector bust_method (struct Vector coord,double epsilon, int flag_direction){
	struct Vector pref_coord;
	int pos = 1;
	pref_coord=coord;
	coord = bust(coord,flag_direction);
	//printf ("\n !!! %lf %lf %lf    pref %lf %lf %lf\n",coord.x,coord.y,coord.z,pref_coord.x,pref_coord.y,pref_coord.z);
	
	while ((decart_norm(sum_vec(coord,minus(pref_coord))) > epsilon) || (fabs(function_vec(coord)-function_vec(pref_coord)) > epsilon) || (decart_norm(gradient(coord,1)) > epsilon)){
		pos++;
		pref_coord=coord;
		coord = bust(coord,flag_direction);
		//printf ("\n !!! %lf %lf %lf    pref %lf %lf %lf\n",coord.x,coord.y,coord.z,pref_coord.x,pref_coord.y,pref_coord.z);
	}
	printf("pos = %d\n",pos);
	return coord;
}

struct Vector bust (struct Vector coord, int flag_direction){
	struct Vector ungrad;
	double betta = 0.0001, lambda = 0.5, crushing = 100.0, min_value, value, min_pos=1.0, pos=1.0;

	ungrad= minus(gradient(coord, flag_direction));
	min_value = function_vec(coord);
	while (pos <= crushing){
		value = function_vec (sum_vec(coord,multiply_vec(ungrad,betta*pos/crushing)));
		if (value <= min_value){
			min_pos = pos;
			min_value = value;
		}
		pos=pos+1;
	}
	coord = sum_vec(coord,multiply_vec(ungrad,betta*min_pos/crushing));

	return coord;
}
