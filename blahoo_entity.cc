#include <string.h>

#include <blah/blah_entity.h>

#include "blahoo_entity_object.h"
#include "blahoo_entity.h"

static void junk(Blah_Entity *p) { std::cout << "JUNK\n"; std::cout.flush(); }

BlahooEntity::BlahooEntity(char *name, int type)
{
//	typedef int (*int_hook_func)(Blah_Entity*);
	//constructs a new plain entity without objects, positioned at origin
	std::cout << "BlahooEntity(name, type): creating new entity " <<  name << "\n";
	
	Blah_Entity_init(&base_struct, name, type, 0); //Initialise base structure
	
	//Wrap move function in base struct to defined member function move()
	Blah_Entity_set_move_function(&base_struct, junk); //voidFunctionHook<&BlahooEntity::move>);
	//Wrap destroy function in base struct to inherited destructor hook
	Blah_Entity_set_destroy_function(&base_struct, destructorHook);
	
//	int_hook_func ihf = functionHook<int, &BlahooEntity::getType>;
} 

BlahooEntity::~BlahooEntity()
{	//destroys entity class object 
	std::cout << "~BlahooEntity() destructor\n";
	std::cout.flush();
	Blah_Entity_disable(&base_struct); //perform entity object disable on base object
}  

Blah_Entity_Object *BlahooEntity::addObject(Blah_Object *object)
{
	//Adds the given object to the specified entity.  Implicitly creates an entity
	//object structure and adds to the entity's collection of objects, returning
	//a pointer to the newly created entity_object structure
	return Blah_Entity_add_object(&base_struct, object);
}

blah_bool BlahooEntity::checkCollisionEntity(Blah_Entity *other_entity, Blah_Point *impact)
{
	return Blah_Entity_check_collision_entity(&base_struct, other_entity, impact);
}

void BlahooEntity::collision(BlahooEntity *other_entity)
{	//controls collision with another entity
	//fprintf(stderr,"BlahooEntity base collision func\n");
}

float BlahooEntity::distanceEntity(Blah_Entity *other_entity)
{
	return Blah_Entity_distance_entity(&base_struct, other_entity);
}

void BlahooEntity::draw()
{	//Draws entity in 3d space
	//fprintf(stderr,"entity::draw, for entity name '%s'\n",base_struct->name);
	//fprintf(stderr,"draw() : draw func wrapper pointer is %p\n",draw_func_wrapper);
	std::cout << "about to draw entity: " ;//<< base_struct.name << "\n";
	callVoidBaseFunction(Blah_Entity_draw, Blah_Entity_set_draw_function, voidFunctionHook<&BlahooEntity::draw>);
}

void BlahooEntity::getAxisX(Blah_Vector *v)
{
	memcpy(v,&base_struct.axis_x,sizeof(Blah_Vector));
}

void BlahooEntity::getAxisY(Blah_Vector *v)
{
	memcpy(v,&base_struct.axis_y,sizeof(Blah_Vector));
}

void BlahooEntity::getAxisZ(Blah_Vector *v)
{
	memcpy(v,&base_struct.axis_z,sizeof(Blah_Vector));
}

Blah_Entity *BlahooEntity::getEntity()
{
	//Returns pointer to the base entity struct
	//fprintf(stderr,"getEntity() : name is %s, draw func wrapper pointer is %p\n",base_struct->name,draw_func_wrapper);
	return &base_struct; //return (Blah_Entity*)wrapper_struct;
}

void BlahooEntity::getLocation(Blah_Point *p)
{
	//Stores the entity's 3D location coords in x,y & z
	//fprintf(stderr,"getLocation() : name is %s,draw func wrapper pointer is %p\n",base_struct->name,draw_func_wrapper);
	Blah_Entity_get_location(&base_struct,p);	//Blah_Entity_get_location(entity, p);
	//fprintf(stderr,"getLocation() : name is %s,draw func wrapper pointer is %p\n",base_struct->name,draw_func_wrapper);
}

int BlahooEntity::getType()
{
	//returns entity type
	//fprintf(stderr,"getType() : draw func wrapper pointer is %p\n",draw_func_wrapper);
	return Blah_Entity_get_type(&base_struct);
}

void BlahooEntity::getVelocity(Blah_Vector *v)
{
	Blah_Entity_get_velocity(&base_struct, v);
}

void BlahooEntity::move()
{	//controls movement of entity
	std::cout << "BlahooEntity::move() - nothing is going to happen\n"; //Default function does nothing
	std::cout.flush();
}

void BlahooEntity::rotateEuler(float x, float y, float z)
{
	//fprintf(stderr,"rotateEuler() : draw func wrapper pointer is %p\n",draw_func_wrapper);
	Blah_Entity_rotate_euler(&base_struct, x,y,z);
}

void BlahooEntity::setActiveCollision(blah_bool flag)
{
	Blah_Entity_set_active_collision(&base_struct, flag);
}

void BlahooEntity::setLocation(float x, float y, float z)
{
	//Sets entity's location in 3D space given 3 coordinates
	//fprintf(stderr,"setLocation() : name is %s, draw func wrapper pointer is %p\n",base_struct->name,draw_func_wrapper);
	Blah_Entity_set_location(&base_struct, x,y,z);//Blah_Entity_set_location(entity, x,y,z);
	//fprintf(stderr,"setLocation() : name is %s, draw func wrapper pointer is %p\n",base_struct->name,draw_func_wrapper);
}

void BlahooEntity::setRotationAxisX(float x)
{
	//fprintf(stderr,"setRotationAxisX : name is %s, draw func wrapper pointer is %p\n",base_struct->name,draw_func_wrapper);
	Blah_Entity_set_rotation_axis_x(&base_struct, x);
	//fprintf(stderr,"setRotationAxisX : name is %s, draw func wrapper pointer is %p\n",base_struct->name,draw_func_wrapper);
}

void BlahooEntity::setRotationAxisY(float y)
{
	Blah_Entity_set_rotation_axis_y(&base_struct, y);
}

void BlahooEntity::setType(int type)
{
	//fprintf(stderr,"setType() : draw func wrapper pointer is %p\n",draw_func_wrapper);
	Blah_Entity_set_type(&base_struct, type);
}

void BlahooEntity::setVelocity(float x, float y, float z)
{
	//fprintf(stderr,"setVelocity() : name is %s, draw func wrapper pointer is %p\n",base_struct->name,draw_func_wrapper);
	Blah_Entity_set_velocity(&base_struct, x,y,z); //Blah_Entity_set_velocity(entity, x,y,z);
	//fprintf(stderr,"setVelocity() : name is %s, draw func wrapper pointer is %p\n",base_struct->name,draw_func_wrapper);
}
		

/* Event Related Functions */

static blah_bool entity_event_function_hook(Blah_Entity *entity, Blah_Entity_Event *event)
{
	//fprintf(stderr,"event_fucntion_hook\n");
	return ((BlahooEntityEvent*)(Blah_Entity_Event_get_data(event)))->eventFunction((BlahooEntity*)entity->entity_data);
}

BlahooEntityEvent::BlahooEntityEvent(char *name, BlahooEntity *sender)
{
	//Constructor to create new entity event class obj given name and sender	
	//base_struct = Blah_Entity_Event_new(name, sender ? sender->base_struct : NULL, entity_event_function_hook, 0);
	Blah_Entity_Event_init(&base_struct, name, sender ? &sender->base_struct : NULL,  entity_event_function_hook, 0);
	//entity_event->event_data = this;
	//Use the entity data pointer to point to new class obj
	//entity_event->destroy_function = event_destroy_function_hook;
	base_struct.destroy_function = destructorHook;
	//Hook into the destroy function of the base event struct to call C++ hook
}

BlahooEntityEvent::~BlahooEntityEvent()
{
	//entity_event->event_data = NULL; //Clear class obj pointer no longer needed
	base_struct.destroy_function = NULL;
	//Remove the pointer to this hook function to prevent recursive call
	Blah_Entity_Event_destroy(&base_struct); //Call normal destroy function
}

void BlahooEntity::sendEvent(BlahooEntityEvent *event)
{
	//Sends an event to this entity
	Blah_Entity_send_event(&base_struct, &event->base_struct); 
	//Call standard blah function with pointer to struct embedded inside class obj
}

blah_bool BlahooEntityEvent::eventFunction(BlahooEntity *recipient)
{	
	//Function to execute effect of event upon recipient entity
	//fprintf(stderr,"Calling C++ event_function\n");
	return BLAH_TRUE;
}
