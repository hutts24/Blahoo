/* blahoo_entity_object.cc
	An entity object is an object constituting all or part of an entity.
	Entity objects have a reference to an underlying geometric object	*/
	
#include "blahoo_entity_object.h"

BlahooEntityObject::BlahooEntityObject (char *name, Blah_Object *object_ptr) : BlahooWrapper<Blah_Entity_Object, BlahooEntityObject>(Blah_Entity_Object_new(name, object_ptr))
{ 	//Create a new entity object using supplied name and object pointer.
	//Alloc a new entity object data structure and return pointer.
	//Defaults position to 0,0,0, visible True.
}

void BlahooEntityObject::set_position(float x, float y, float z)
{
	//Alters entity object's position, relative to parent entity center.
	Blah_Entity_Object_set_position(base_struct, x,y,z);
}

void BlahooEntityObject::draw()
{ 
	//Draw structure in scene
	Blah_Entity_Object_draw(base_struct);
}
	
void BlahooEntityObject::set_draw_function(blah_entity_object_draw_func *function)
{ 
	//set pointer for draw function used by given entity object
	Blah_Entity_Object_set_draw_function(base_struct, function);
}
	
BlahooEntityObject::~BlahooEntityObject()
{	//Destroys an entity object class instance.  Frees memory occupied by entity object
	//structure and also destroys the referenced base object.
	Blah_Entity_Object_destroy(base_struct);
}
	
void BlahooEntityObject::set_visible(blah_bool vis_flag)
{
	//Sets the visibility flag of the entity object to the value given by vis_flag
	//Tue will make the object visible and drawn as part of the parent entity,
	//False will make it invisible
	Blah_Entity_Object_set_visible(base_struct, vis_flag);
}
	
blah_bool BlahooEntityObject::is_visible()
{
	//Returns TRUE if the entity_object is visible, else FALSE
	return Blah_Entity_Object_is_visible(base_struct);
}
	
blah_bool BlahooEntityObject::check_collision(Blah_Entity_Object *other_entity_object,
 Blah_Point *impact_1, Blah_Point *impact_2)
{
	//Checks if obejct_1 and object_2 are colliding and stores point of
	//contact in 'impact'
	return Blah_Entity_Object_check_collision(base_struct, other_entity_object, impact_1, impact_2);
}
	
float BlahooEntityObject::distance_Entity_Object(Blah_Entity_Object *other_entity_object)
{
	//Returns true distance to specified entity object
	return Blah_Entity_Object_distance_Object(base_struct, other_entity_object);
}
	
void BlahooEntityObject::delta_Entity_Object(Blah_Entity_Object *other_entity_object, Blah_Vector *delta)
{
	//Returns a vector from object_1 to object_2
	Blah_Entity_Object_delta_Entity_Object(base_struct, other_entity_object, delta);
}
