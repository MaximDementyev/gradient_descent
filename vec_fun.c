#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"list.h"

#define accuracy_derivative 0.00000001

double decart_norm(struct Vector coord){
	double result = sqrt(coord.x*coord.x+coord.y*coord.y+coord.z*coord.z);
	return result;
}

double function_vec(struct Vector coord){
	double result = function (coord.x, coord.y, coord.z);
	return result;
}

struct Vector sum_vec (struct Vector vec1, struct Vector vec2){
	vec1.x = vec1.x + vec2.x;
	vec1.y = vec1.y + vec2.y;
	vec1.z = vec1.z + vec2.z;
	return vec1;
}

struct Vector multiply_vec(struct Vector vec, double alpha){
	vec.x = alpha * vec.x;
	vec.y = alpha * vec.y;
	vec.z = alpha * vec.z;
	return vec;
}

struct Vector minus(struct Vector vec){
	vec.x=-vec.x;
	vec.y=-vec.y;
	vec.z=-vec.z;
	return vec;
}

double derivative (struct Vector coord,struct Vector ungrad){
	double result = (function_vec(sum_vec(coord,multiply_vec(ungrad,accuracy_derivative)))-function_vec(coord))/accuracy_derivative;
	return result;
}

struct Vector gradient(struct Vector coord, int flag_direction){
	struct Vector grad;
	//printf("%d",flag_direction);
	switch (flag_direction){
		case 1:	grad.x = (function(coord.x+accuracy_derivative,coord.y,coord.z)-function(coord.x-accuracy_derivative,coord.y,coord.z))/2/accuracy_derivative;
			grad.y = (function(coord.x,coord.y+accuracy_derivative,coord.z)-function(coord.x,coord.y-accuracy_derivative,coord.z))/2/accuracy_derivative;
			grad.z = (function(coord.x,coord.y,coord.z+accuracy_derivative)-function(coord.x,coord.y,coord.z-accuracy_derivative))/2/accuracy_derivative;
//printf("!");
			break;
		case 2: grad = Newton_method(coord);
	}
	return grad;
}

