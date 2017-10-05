#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <assert.h>

struct Vector{
	double x;
	double y;
	double z;
};


double function_vec(struct Vector coord);
double function(double x, double y, double z);


struct Vector sum_vec (struct Vector vec1, struct Vector vec2);
struct Vector minus(struct Vector vec);
struct Vector multiply_vec(struct Vector vec, double alpha);
struct Vector partial_derivative(struct Vector coord);
double decart_norm(struct Vector coord);
struct Vector gradient (struct Vector coord, int flag_direction);
struct Vector Newton_method (struct Vector point);
double derivative (struct Vector coord,struct Vector grad);

struct Vector crushing_step (struct Vector coord, int flag_direction);
struct Vector crushing_step_method (struct Vector coord,double epsilon, int flag_direction);

struct Vector bisection_method (struct Vector coord,double epsilon, int flag_direction);
struct Vector bisection (struct Vector coord, double epsilon, int flag_direction);

struct Vector bust (struct Vector coord, int flag_direction);
struct Vector bust_method (struct Vector coord,double epsilon, int flag_direction);

struct Vector golden_section (struct Vector coord,double epsilon, int flag_direction);
struct Vector golden_section_method (struct Vector coord,double epsilon, int flag_direction);

struct Vector tangent (struct Vector coord,double epsilon, int flag_direction);
struct Vector tangent_method (struct Vector coord,double epsilon, int flag_direction);

#endif
