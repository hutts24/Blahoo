/***************************************************************************
 *            blahoo_vector.cc
 *
 *  Wed Feb  1 08:01:10 2006
 *  Copyright  2006  User
 *  Email
 ****************************************************************************/

#include <malloc.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

#include <blah/blah.h>

#include "blahoo_vector.h"

/* Function Declarations */

BlahooVector::BlahooVector(float x, float y, float z) {
	//Constructor, creates new vector class obj
	set(x,y,z);
}

BlahooVector::~BlahooVector() {
	//Destructor, destroys class object instance
}

void BlahooVector::set(float x, float y, float z) {
	//Sets the x,y, and z values of a vector
	Blah_Vector_set(&base_struct, x, y, z);
}

void BlahooVector::normalise() {
	Blah_Vector_normalise(&base_struct);
}	

void BlahooVector::scale(float scale_factor) {
	//Scales the magnitude of the vector by scale_factor
	Blah_Vector_scale(&base_struct, scale_factor);
}

void BlahooVector::multiplyMatrix(struct Blah_Matrix *matrix) {
	Blah_Vector_multiply_matrix(&base_struct, matrix);
}

void BlahooVector::sprintf(char *dest) {
	Blah_Vector_sprintf(dest, &base_struct);
}

float BlahooVector::getMagnitude() {
	return Blah_Vector_get_magnitude(&base_struct);
}

void BlahooVector::setMagnitude(float mag) {
	Blah_Vector_set_magnitude(&base_struct, mag);
}

void BlahooVector::addVector(BlahooVector *other_vector) {
	//Adds other_vector to this vector object
	Blah_Vector_add_vector(&base_struct, &other_vector->base_struct);
}

void BlahooVector::invert() {
	//transforms a vector to its inverse (multiplies by -1)
	Blah_Vector_invert(&base_struct);
}

void BlahooVector::crossProduct(BlahooVector *other_vector,	BlahooVector *result) {
	//Calculates the cross product of other_vector and current vector and stores in
	//BlahooVector object pointed to by result
	blah_vector_cross_product(&base_struct, &other_vector->base_struct, &result->base_struct);
}
