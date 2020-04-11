/* blahoo_vector.h 
	C++ Class built around static Blah_Vector struct */

#ifndef _BLAHOO_VECTOR

#define _BLAHOO_VECTOR

/* Include directives */

#include <blah/blah.h>

#include "blahoo_wrapper.h"

/* Forward Declarations */

struct Blah_Matrix;

/* Class Definition */

typedef class BlahooVector : private BlahooWrapper<Blah_Vector, BlahooVector>{
	//A vector is a simple structure with x,y, and z values
	friend class BlahooPoint;
	
	public:
		BlahooVector(float x, float y, float z); //Constructor, creates new vector class obj

		~BlahooVector(); //Destructor, destroys class object instance
	
		void set(float x, float y, float z); //Sets the x,y, and z values of a vector

		void normalise();

		void scale(float scale_factor);	//Scales the magnitude of the vector by scale_factor

		void multiplyMatrix(struct Blah_Matrix *matrix);

		void sprintf(char *dest);

		float getMagnitude();

		void setMagnitude(float mag);

		void addVector(BlahooVector *other_vector);	//Adds other_vector to this vector object

		void invert();	//transforms a vector to its inverse (multiplies by -1)

		void crossProduct(BlahooVector *other_vector,	BlahooVector *result);
			//Calculates the cross product of other_vector and current vector and stores in
			//BlahooVector object pointed to by result

} Blahoo_Vector;

#endif
