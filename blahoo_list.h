/* blahoo_list.h - Implements a doubly linked list class structure.
	List structure maintains the pointer to the first Blah_List_Element structure */

#ifndef _BLAHOO_LIST

#define _BLAHOO_LIST

#include <blah/blah.h>

#include "blahoo_wrapper.h"

/* Structure Definitions */

typedef class BlahooListElement : private BlahooWrapper<Blah_List_Element, BlahooListElement>
{	//defines a simple element structure to hold a pointer to list data
	private:
		
			BlahooListElement(Blah_List_Element *base_struct);
			//Creates a list element class object from a list element struct
			//Note that supplied base structure pointer is embedded into new element object
			//Do not destroy the original structure supplied in the argument
	
	public:
		template <typename data_pointer> BlahooListElement(data_pointer *data); 
			//Creates a new list element //FIXME

		void call_function(blah_list_element_func function);
		
		void call_function(blah_list_element_func_1arg function, void *arg);
				
		blah_bool call_arg_return_bool(blah_list_search_func function, void *arg);

} BlahooListElement;

typedef class BlahooList : private BlahooWrapper<Blah_List, BlahooList>
{
	public:
		BlahooList(char *list_name);
			//Creates a new empty list object with given name
	
		BlahooList(); 
			//Creates a new empty list object without a name (set to empty string)
			
		~BlahooList();
			//Clears all memory occupied by list and elements
			//FIXME
		template <typename data_pointer> //FIXME change to class?
		blah_bool remove_element(data_pointer *data);
			//Removes element with given data from list.
			//Does not free data pointed to by list element.
			//Returns BLAH_FALSE if error */
		
		template <typename data_pointer> 
		data_pointer *pop_element();
			//Removes first element from list and returns data pointer
		
		template <typename data_pointer> 
		void append_element(data_pointer *data);
			//Appends a new element to the end of the list with given data ptr
	
		template <typename data_pointer> 
		void insert_element(data_pointer *data);
			//Inserts a new element at the beginning of the list with given data ptr

		void call_function(blah_list_element_func function);
			//Function Blah_List_call_function:
			//Calls function for each element, using data pointer as argument
			//to given function
		
		template <typename data_pointer> 
		void call_function(blah_list_element_func_1arg function, data_pointer *arg);
			//Calls function for each element, using data pointer as argument
			//to given function
	
		void init(char *name);
			//Sets the name of the list, and all element pointers to NULL
		
		template <typename data_pointer> 		
		BlahooListElement *find_element(data_pointer *data);
			//Finds list element with given data */

		void destroy_elements();
			//clears all memory allocated for elements and data but does not destroy basic list header
	
		void remove_all();
			//removes all elements but retains empty list structure.  Does not free data
	
		template <typename data_pointer, typename arg_pointer> 
		data_pointer *search(blah_list_search_func search_function, arg_pointer *arg);
			//Calls search_function for each element of the list, using the element's data
			//as the first argument and 'arg' as second.  Returns the data pointer of the first element for which
			//search_function returns BLAH_TRUE, or NULL if no match;

		void sort(blah_list_sort_func compare_function);
			//Performs a linear sort of the list, using the supplied function to compare two elements.
			//compare_function is called as comp((void*)elem1->data,(void*)elem2->data).
			//compare_function should behave like strcmp() and return a value smaller than 0
			//if elem1->data < elem2->data, return 0 if equal, or > 0 if elem1->data > elem2->data
	
		void set_destroy_element_function(blah_list_element_dest_func function);
			//Sets the function pointer to the given function used to destroy element data
			//contained in elements of this list
	
		blah_pointerstring create_pointerstring();
			//Returns an allocated array of pointers to the data contained in each of the
			//list elements, in the order they occur.  The last element of the return array
			//is a NULL pointer to signify the end.
	
} BlahooList;

#endif
