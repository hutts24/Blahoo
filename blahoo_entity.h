/***************************************************************************
 *            blahoo_entity.h
 *
 *  Sat May 22 14:47:23 2004
 *  Copyright  2004  hutts
 *  none
 ****************************************************************************/

#ifndef _BLAHOO_ENTITY

#define _BLAHOO_ENTITY

#include <blah/blah.h>

#include "blahoo_list.h"
#include "blahoo_entity_object.h"
#include "blahoo_wrapper.h"

/* Forward declarations for convenience */

typedef class BlahooEntity BlahooEntity;

typedef class BlahooEntityEvent : protected BlahooWrapper<Blah_Entity_Event, BlahooEntityEvent>
{
	friend class BlahooEntity;
	
	private:
	
	public:
		virtual ~BlahooEntityEvent();
			//Destructor function - can be overridden
	
		BlahooEntityEvent(char *name, BlahooEntity *sender);
			//Constructor to create new entity event class obj given name and sender	
	
		virtual blah_bool eventFunction(BlahooEntity *recipient);	
			//Function to execute effect of event upon recipient entity

} BlahooEntityEvent;




typedef class BlahooEntity : protected BlahooWrapper<Blah_Entity, BlahooEntity>
{
	friend class BlahooEntityEvent;	
	
	public:
		BlahooEntity(char *name, int type);
			//constructs a new plain entity without objects, positioned at origin
	
		virtual ~BlahooEntity();
			//destroys entity //FIXME
			
		Blah_Entity_Object *addObject(Blah_Object *object);
			//Adds the given object to the specified entity.  Implicitly creates an entity
			//object structure and adds to the entity's collection of objects, returning
			//a pointer to the newly created entity_object structure
	
		blah_bool checkCollisionEntity(Blah_Entity *other_entity, Blah_Point *impact);
	
		virtual void collision(BlahooEntity *other_entity);
			//controls collisions with an other entity	
	
		virtual void draw();
			//controls rendering of entity
	
		float distanceEntity(Blah_Entity *other_entity);
	
		//Get functions to inspect properties
		void getAxisX(Blah_Vector *v);
			//Returns X axis in the form of a vector
			
		void getAxisY(Blah_Vector *v);
			//Returns Y axis in the form of a vector
			
		void getAxisZ(Blah_Vector *v);
	
		Blah_Entity *getEntity();
			//Returns void data pointer to entity's own allocated data buffer	
		
		void getLocation(Blah_Point *p);
			//Stores the entity's 3D location coords in x,y & z
		
		int getType();
			//returns entity type
		
		void getVelocity(Blah_Vector *v);
		
		virtual void move();
			//controls movement of entity
	
		void rotateEuler(float x, float y, float z);
		
		//Set functions to alter properties
	
		virtual void setActiveCollision(blah_bool flag);
	
		void setLocation(float x, float y, float z);
			//Sets entity's location in 3D space given 3 coordinates
		
		void setRotationAxisX(float x);
		
		void setRotationAxisY(float y);		
		
		void setType(int type);
		
		void setVelocity(float x, float y, float z);
		
					
		/* Event Related Functions */

		void sendEvent(BlahooEntityEvent *event);
			//Sends an event to this entity
		
} BlahooEntity;

#endif
