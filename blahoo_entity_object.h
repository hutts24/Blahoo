/* blahoo_entity_object.h
	An entity object is an object constituting all or part of an entity.
	Entity objects have a reference to an underlying geometric object	*/

#ifndef _BLAHOO_ENTITY_OBJECT

#define _BLAHOO_ENTITY_OBJECT

#include <blah/blah.h>

#include "blahoo_wrapper.h"

/* Forward Structure Declarations */

struct Blah_Entity;
	
/* Data Structure definitions */

typedef class BlahooEntityObject : private BlahooWrapper<Blah_Entity_Object, BlahooEntityObject>
{	//represents an object constituting an entity part
	private:
		Blah_Entity_Object object;
	public:
		
	BlahooEntityObject (char *name, Blah_Object *object_ptr);
		//Create a new entity object using supplied name and object pointer.
		//Alloc a new entity object data structure and return pointer.
		//Returns NULL on failure.  Defaults position to 0,0,0, visible True.
	
	void set_position(float x, float y, float z);
		//Alters entity object's position, relative to parent entity center.
	
	void draw();
		//Draw structure in scene
		
	void set_draw_function(blah_entity_object_draw_func *function);
		//set pointer for draw function used by given entity object
	
	~BlahooEntityObject();
		//Destroys an entity object class instance.  Frees memory occupied by entity object
		//structure and also destroys the referenced base object.
		
	void set_visible(blah_bool vis_flag);
		//Sets the visibility flag of the entity object to the value given by vis_flag
		//Tue will make the object visible and drawn as part of the parent entity,
		//False will make it invisible
		
	blah_bool is_visible();
		//Returns TRUE if the entity_object is visible, else FALSE

	blah_bool check_collision(Blah_Entity_Object *other_entity_object, Blah_Point *impact_1, Blah_Point *impact_2);
		//Checks if obejct_1 and object_2 are colliding and stores point of
		//contact in 'impact'
		
	float distance_Entity_Object(Blah_Entity_Object *other_entity_object);
		//Returns true distance to specified entity object
	
	void delta_Entity_Object(Blah_Entity_Object *other_entity_object, Blah_Vector *delta);
		//Returns a vector from object_1 to object_2
} BlahooEntityObject;

#endif
