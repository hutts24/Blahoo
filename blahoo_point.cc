/* blahoo_point.c */

#include <malloc.h>

#include <blah/blah.h>

#include "blahoo_point.h"
#include "blahoo_vector.h"

/* Constructors/Destructors */

BlahooPoint::BlahooPoint(float x, float y, float z) : BlahooWrapper<Blah_Point, BlahooPoint>(Blah_Point_new(x, y, z))
{	//Creates a new point structure - very simple
}

BlahooPoint::~BlahooPoint()
{	//Destructor.  Destroys class object
	free(base_struct);  //No destroy function for Blah_Point.  Use free() instead
}

/* Function Declarations */

void BlahooPoint::deltaPoint(BlahooPoint *other_point, BlahooVector *vector)
{	//Stores the delta vector from this point to other point in *vector
	Blah_Point_delta_point(base_struct, other_point->base_struct, vector->base_struct);
}

float BlahooPoint::distancePoint(BlahooPoint *other_point)
{	//Distance from a to b
	return Blah_Point_distance_point(base_struct, other_point->base_struct);
}

void BlahooPoint::multiplyMatrix(Blah_Matrix *matrix)
{	//Multiplies point coordinates by a given matrix
	Blah_Point_multiply_matrix(base_struct, matrix);
}

void BlahooPoint::rotateAxis(BlahooVector *axis, float angle)
{	//Translates a point position by rotation of a given angle (in rads) around an 
	//abitrary axis as represented by given quaternion
	Blah_Point_rotate_axis(base_struct, axis->base_struct, angle);
}

void BlahooPoint::scale(float scale_factor)
{	//Multiplies each coordinate of the point by scale_factor
	Blah_Point_scale(base_struct, scale_factor);
}

void BlahooPoint::set(float x, float y, float z)
{	//sets coordinates of point structure - nothing much new here
	Blah_Point_set(base_struct, x,y,z); //Call base point structure func to set coordinates of new point
}

void BlahooPoint::translateByQuaternion(Blah_Quaternion *quat)
{	//translates a point by a rotation about an arbitrary axis, represented by a quaternion
	Blah_Point_translate_by_quaternion(base_struct, quat);
}

void BlahooPoint::translateByVector(BlahooVector *vector)
{	//Adds x,y,z values of vector to x,y,z values of point
	Blah_Point_translate_by_vector(base_struct, vector->base_struct);
}
