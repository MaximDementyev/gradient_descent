#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"list.h"

#define accuracy_derivative 0.00000001

struct Vector golden_section_method (struct Vector coord,double epsilon, int flag_direction){
	struct Vector pref_coord;
	int pos = 1;
	pref_coord=coord;
	coord = golden_section(coord,epsilon,flag_direction);
	//printf ("\n !!! %lf %lf %lf    pref %lf %lf %lf\n",coord.x,coord.y,coord.z,pref_coord.x,pref_coord.y,pref_coord.z);
	
	while ((decart_norm(sum_vec(coord,minus(pref_coord))) > epsilon) || (fabs(function_vec(coord)-function_vec(pref_coord)) > epsilon) || (decart_norm(gradient(coord,1)) > epsilon)){
		pos++;
		pref_coord=coord;
		coord = golden_section(coord,epsilon,flag_direction);
		//printf ("\n !!! %lf %lf %lf    pref %lf %lf %lf\n",coord.x,coord.y,coord.z,pref_coord.x,pref_coord.y,pref_coord.z);
	}
	printf("pos = %d\n",pos);
	return coord;
}


struct Vector golden_section (struct Vector coord, double epsilon, int flag_direction){
	struct Vector ungrad;
	double a=0,b=1,c,value_c,d,value_d,r=(3-sqrt(5))/2;
	ungrad= minus(gradient(coord, flag_direction));

	c = a+r*(b-a);
	d = b-r*(b-a);
	
	value_c = function_vec(sum_vec(coord,multiply_vec(ungrad,c)));
	value_d = function_vec(sum_vec(coord,multiply_vec(ungrad,d)));
	while (b-a > epsilon){	
		if (value_c < value_d){
			b = d;
			c = a+r*(b-a);
			d = c;
			value_d = value_c;
			value_c = function_vec(sum_vec(coord,multiply_vec(ungrad,c)));
		}else{
			a = c;
			c = d;
			d = b-r*(b-a);
			value_c = value_d;
			value_d = function_vec(sum_vec(coord,multiply_vec(ungrad,d)));
		}
	}
	coord = sum_vec(coord,multiply_vec(ungrad,b));
	return coord;
}

