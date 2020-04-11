/* blahoo_list.cc - Implements a doubly linked list class structure.
	List structure maintains the pointer to the first Blah_List_Element structure */

#include <blah/blah.h>
#include <string.h>

#include "blahoo_list.h"

/* List Element Function Definitions */

/* Private Functions */
/* BlahooListElement::BlahooListElement(Blah_List_Element *elem_struct) {
	//Creates a list element class object from a list element struct
	Blah_List_Element_init(&base_struct, elem_struct);
} */

/* Public Functions */

template <typename data_pointer> 
BlahooListElement::BlahooListElement(const data_pointer *data) {
	//Constructor - Creates a new list element
	Blah_List_Element_init(&base_struct, (void*)data);
}

void BlahooListElement::call_function(blah_list_element_func function) {
	Blah_List_Element_call_function(&base_struct, function);
}
		
void BlahooListElement::call_function(blah_list_element_func_1arg function, void *arg) {
	Blah_List_Element_call_with_arg(&base_struct, function, arg);
}
		
blah_bool BlahooListElement::call_arg_return_bool(blah_list_search_func function, void *arg) {
	return Blah_List_Element_call_arg_return_bool(&base_struct, function, arg);
}			

/* List Function Declarations */

BlahooList::BlahooList(const char *list_name) {
	//Creates a new empty list object with given name
	Blah_List_init(&base_struct, (char*)list_name);
}

BlahooList::BlahooList() {
	//Creates a new empty list object without a name (set to empty string)
	Blah_List_init(&base_struct, "");
}
	
BlahooList::~BlahooList() {
	//Clears all memory occupied by list and elements
	Blah_List_destroy_elements(&base_struct); 
}

template <typename data_pointer> 
blah_bool BlahooList::remove_element(const data_pointer *data) {
	//Removes element with given data from list.
	//Does not free data pointed to by list element.
	//Returns BLAH_FALSE if error */
	return Blah_List_remove_element(&base_struct, (void*)data);
}

template <typename data_pointer> 
data_pointer *BlahooList::pop_element() {
	//Removes first element from list and returns data pointer
	return Blah_List_pop_element(&base_struct);
}
	

template <typename data_pointer> 
void BlahooList::append_element(const data_pointer *data) {
	//Appends a new element to the end of the list with given data ptr
	Blah_List_append_element(&base_struct, (void*)data);
}
	
template <typename data_pointer> 
void BlahooList::insert_element(const data_pointer *data) {	
	//Inserts a new element at the beginning of the list with given data ptr
	Blah_List_insert_element(&base_struct, (void*)data);
}

void BlahooList::call_function(blah_list_element_func function) {
	//Function Blah_List_call_function:
	//Calls function for each element, using data pointer as argument
	//to given function
	Blah_List_call_function(&base_struct, function);
}

template <typename data_pointer> 
void BlahooList::call_function(blah_list_element_func_1arg function, const data_pointer *arg) {
	//Calls function for each element, using data pointer as argument
	//to given function
	Blah_List_call_with_arg(&base_struct, function, (void*)arg);
}
	
void BlahooList::init(const char *name) {
	//Sets the name of the list, and all element pointers to NULL
	Blah_List_init(&base_struct, (char*)name);
}
	
template <typename data_pointer> 		
BlahooListElement *BlahooList::find_element(const data_pointer *data) {
	//Finds list element with given data
	return Blah_List_find_element(&base_struct, (void*)data);
}
		
void BlahooList::destroy_elements() { 
	//clears all memory allocated for elements and data but does not destroy basic list header
	Blah_List_destroy_elements(&base_struct);
}
	
void BlahooList::remove_all() {
	//removes all elements but retains empty list structure.  Does not free data
	Blah_List_remove_all(&base_struct);
}
	
template <typename data_pointer, typename arg_pointer> 
data_pointer *BlahooList::search(blah_list_search_func search_function, const arg_pointer *arg) {
	//Calls search_function for each element of the list, using the element's data
	//as the first argument and 'arg' as second.  Returns the data pointer of the first element for which
	//search_function returns BLAH_TRUE, or NULL if no match;
	return Blah_List_search(&base_struct, search_function, (void*)arg);
}

void BlahooList::sort(blah_list_sort_func compare_function) {
	//Performs a linear sort of the list, using the supplied function to compare two elements.
	//compare_function is called as comp((void*)elem1->data,(void*)elem2->data).
	//compare_function should behave like strcmp() and return a value smaller than 0
	//if elem1->data < elem2->data, return 0 if equal, or > 0 if elem1->data > elem2->data
	Blah_List_sort(&base_struct, compare_function);
}

void BlahooList::set_destroy_element_function(blah_list_element_dest_func function) {
	//Sets the function pointer to the given function used to destroy element data
	//contained in elements of this list
	Blah_List_set_destroy_element_function(&base_struct, function);
}
	
blah_pointerstring BlahooList::create_pointerstring() {
	//Returns an allocated array of pointers to the data contained in each of the
	//list elements, in the order they occur.  The last element of the return array
	//is a NULL pointer to signify the end.
	return Blah_List_create_pointerstring(&base_struct);
}
