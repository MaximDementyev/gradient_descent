#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"list.h"
 
struct Vector coord;

double function(double x, double y, double z){
	double result = 10*(x-1)*(x-1)+0.1*y*y+z*z;   //our function
	return result;
}
// function
	//coord = crushing_step_method(coord,epsilon,flag_direction);
	//coord = golden_section_method(coord,epsilon,flag_direction);
	//coord = bust_method(coord,epsilon,flag_direction);
	//coord = tangent_method(coord,epsilon,flag_direction);
	//flag_direction = 1 - gradient; 2 matrix of second derivative
int main(void){
	double epsilon;
	double betta;
	printf ("please, enter begining point x y z\n");
	scanf("%lf %lf %lf",&coord.x,&coord.y,&coord.z);
	printf ("please, enter accuracy of find min of function\n");
	scanf ("%lf",&epsilon);
	if (epsilon<=0){
		printf ("uncorrect epsilon");
		return 0;
	}
	coord = bisection_method(coord,sqrt(epsilon),1);
	printf ("cpmplite first method, result is %lf %lf %lf\n",coord.x,coord.y,coord.z);
	coord = crushing_step_method(coord,epsilon,2);
	printf ("cpmplite second method, result is %lf %lf %lf\n",coord.x,coord.y,coord.z);
	return 0;
}


