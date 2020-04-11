/***************************************************************************
 *            blahoo_wrapper.h
 *
 *  Fri Apr 22 02:29:13 2005
 *  Copyright  2005  hutts
 *  none
 ****************************************************************************/

#ifndef _BLAHOO_WRAPPER

#define _BLAHOO_WRAPPER

#include <iostream>
//#include <stdio.h>

template <typename Base_Struct, class WrapperSubclass>
class BlahooWrapper
{	//This class contains an embedded static base structure which it 'wraps'.  The class contains no virtual/overridable
	//functions or members and therefore has no virtual table and a pointer to the base structure can also be cast
	//to a wrapper object.
	
	//private local type definitions for this template scope only
//	typedef class BlahooWrapper<Base_Struct, WrapperSubclass> Wrapper;

	typedef void (*void_hook_func)(Base_Struct*);
	typedef void (*set_void_hook_func)(Base_Struct*, void_hook_func);
	typedef void (*void_base_func)(Base_Struct*);
	typedef void (WrapperSubclass::*void_class_func)();
	
//	private: //Private variables
			
protected: //Constructors are protected so as to only allow deriving classes to create wrappers

	//Protected Variables

	Base_Struct base_struct; //Static Base Struct Embedded in Wrapper Object	

protected:	
	//Protected Functions
	
/*	void callBaseFunction(base_func base_func, set_void_hook_func set_func, void_hook_func wrapper_hook_func);
		//Calls the given function pointer for the base struct object contained in this wrapper object.
		//Before calling the function, the set hook function is called to set the hook function to NULL,
		//to force the default function behaviour.  Following the call to the true base function, the 
		//set hook function is called once again to instate the given wrapper hook function */
	
	void callVoidBaseFunction(void_base_func base_func, set_void_hook_func set_func, void_hook_func wrapper_hook_func)
	{	//Calls the given function pointer for the base struct object contained in this wrapper object.
		//Before calling the function, the set hook function is called to set the hook function to NULL,
		//to force the default function behaviour.  Following the call to the true base function, the 
		//set hook function is called once again to instate the given wrapper hook function
		set_func(&base_struct, NULL); //Set the base struct hook func to NULL
		base_func(&base_struct); //Call the base func, using the address of the encapsulated object
		set_func(&base_struct, wrapper_hook_func); //Replace the base hook func with the given pointer to wrapper hook
	}
	
	static WrapperSubclass *castBasePointer(Base_Struct *base_pointer)
	{	//Given the pointer of a base object contained within a class object extending BlahooWrapper,
		//locates and returns a pointer to the encompassing subclass object which derives from BlahooWrapper.
		typedef BlahooWrapper<Base_Struct, WrapperSubclass> Wrapper;
		
		//Brutally cast the base struct pointer as a pointer to a parent Wrapper class object pointer
		Wrapper *wrapper_pointer = (Wrapper*) base_pointer;
		//statically cast parent Wrapper to a child subclass object pointer
		WrapperSubclass *new_pointer = static_cast<WrapperSubclass*>(wrapper_pointer); 
		if (!new_pointer)
			std::cout << "static_cast failed\n";
	
		return new_pointer; //Return pointer to subclass object
	}
	
	static void destructorHook(Base_Struct *base_pointer)
	{	//This function is used as a hook from the static C struct object destroy function pointer to call
		//the destructor for the wrapper class object
		std::cout << "BlahooWrapper::destructorHook - Calling delete\n";
		std::cout.flush();
		delete(castBasePointer(base_pointer));
	}
	
	
	template <void_class_func void_function>
	static void voidFunctionHook(Base_Struct *base_pointer)
	{	//Given a pointer of a base struct object, calls a member function of the encompassing
		//subclass object extending BlahooWrapper.
		//Templated function creates instances for each member function of the deriving subclass.
		WrapperSubclass *subclass_pointer = castBasePointer(base_pointer);  //Get pointer to subclass object
		(subclass_pointer->*void_function)();  //Call the function in the subclass
		std::cout << "BlahooWrapper::voidFunctionHook()\n";
		std::cout.flush();
	}
	
	
	template <typename ret_type, ret_type (WrapperSubclass::*class_func)() >
	static ret_type functionHook(Base_Struct *base_pointer)
	{	//Given a pointer of a base struct object, calls a member function of the encompassing
		//subclass object extending BlahooWrapper.
		//Templated function creates instances for each member function of the deriving subclass.
		WrapperSubclass *subclass_pointer = castBasePointer(base_pointer);  //Get pointer to subclass object
		return (subclass_pointer->*class_func)();  //Call the function in the subclass
	}
	
/*	static void_base_func wrapit(void_class_func void_function)
	{
		return (void_base_func)(&voidFunctionHook<void_function, int>);
	} */
		
		
};	

template <typename Base_Struct, typename return_type, class WrapperSubclass>
class BlahooWrapperFunction
{	// Base Abstract Class which all function wrapper type classes are derived from
	//friend class BlahooWrapper<Base_Struct>; //Only Blahoo Wrapper member funcs can instantiate an object instance
	typedef return_type (*base_function)(Base_Struct*);
	typedef return_type (*hook_function)(Base_Struct*, void*);
	typedef void (*set_hook_function)(Base_Struct*, hook_function, void*);
	typedef return_type (WrapperSubclass::*member_function)();
	
	private:
		static return_type empty_base_func(Base_Struct *base_struct)
		{	// This function should not be invoked, but it will be if some class member function uses call_base_func()
			//	from a function wrapper	class obj which is bound to a base hook, but does not have a corresponding
			//	static struct function.  */
			std::cout << "BlahooWrapperFunction::empty_base_func() - THIS FUNCTION SHOULD NOT BE CALLED\n";		
		}
	
		static return_type WrapperHookFunction_call(Base_Struct *base_struct)
		{
			//This is the static hook function which will be used for the base C callback routine function pointer.
			//	The function essentially ignores the first struct pointer argument (which is there to match the callback format)
			//	and extracts the class object pointer and member function pointer from the func_wrapper object pointer */	
			std::cout << "BlahooWrapperFunction::WrapperHookFunction_call() - THIS FUNCTION SHOULD NOT BE CALLED\n";		
		}
		
		static void destructor_hook(Base_Struct *base_struct, void *subclass_object)
		{	// This function is used as a hook from the static C struct object destroy function pointer to call
			//	the destructor for the wrapper class object
			delete((WrapperSubclass*)subclass_object);			
			//That's all folks
		}
		
	protected: //All following class members are protected, as they need to be inherited by the deriving Wrapper Function classes
		WrapperSubclass *wrapper_class_obj; //instance object to use
		member_function member_func;			//pointer to class member func
		set_hook_function set_hook_func;		//pointer to the function used to set hook function pointer in base struct
		base_function base_func;					//pointer to the struct related function that this wrapper binds to
		Base_Struct *base_struct;					//pointer to the base object the parent wrapper is bound to
	
		BlahooWrapperFunction(base_function bf, set_hook_function shf, WrapperSubclass *subclass_obj, member_function m_function)
		{
			//Constructor function to create a new wrapper function object
			wrapper_class_obj = subclass_obj;
			member_func = m_function;
			set_hook_func=shf;  //Set pointer to the function which sets the callback hook in the base struct
			if (bf)
				base_func = bf;  //Set the pointer to the static base function which operates on the base struct
			else
				base_func = empty_base_func;
			base_struct = &subclass_obj->base_struct;
		} //End Constructor
		
	public:
		
		return_type call_base_func() {};
			/* Clears the custom function and data pointer in the base struct and calls a static C function to operate upon
				base struct obj.  Once base function call is complete, the hook function pointer is restored and
				the result of the base function returned as per normal. */
			
};


#endif
