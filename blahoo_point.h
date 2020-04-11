/* blahoo_point.h */

#ifndef _BLAHOO_POINT

#define _BLAHOO_POINT

#include <blah/blah_quaternion.h>

#include "blahoo_wrapper.h"

/* Forward Declarations For Convenience */

struct Blah_Matrix;
class BlahooVector;
	
/* Class structure declarations */

typedef class BlahooPoint : private BlahooWrapper<Blah_Point, BlahooPoint>{
	//A simple point in 3D space, represented by 3 coordinates
	private:
	
	public:
		/* Function Prototypes */

		BlahooPoint(float x, float y, float z);
			//Constructor - creates a new point class - quite simple
		
		~BlahooPoint();
			//Destructor - destroys class object		
	
		void set(float x, float y, float z); 
			//sets coordinates of point structure

		void deltaPoint(BlahooPoint *other_point, class BlahooVector *vector);
			//Stores a delta vector from this point to other_point in *vector

		float distancePoint(BlahooPoint *other_point); 
			//Returns true distance from this point to other_point

		void translateByVector(class BlahooVector *vector);
			//Adds vector to point coordinates

		void translateByQuaternion(Blah_Quaternion *quat);
			//translates a point by a rotation about an arbitrary axis, represented by a quaternion

		void multiplyMatrix(struct Blah_Matrix *matrix);
			//Multiplies point coordinates by a given matrix

		void scale(float scale_factor);
			//Multiplies each coordinate of the point by scale_factor

		void rotateAxis(BlahooVector *axis, float angle);
			//Translates the point position by rotation of a given angle (in rads) around an 
			//abitrary axis as represented by given quaternion

} BlahooPoint;

#endif
