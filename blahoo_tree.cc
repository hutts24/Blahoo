/* blahoo_tree.cc - Implements a binary tree structure.
	Tree structure maintains the pointer to the first Blah_Tree_Element structure
	FIXME!!! */

#include "blahoo_tree.h"

/* Element Function Declarations */
	
BlahooTreeElement::BlahooTreeElement(char *key, void *data) : BlahooWrapper<Blah_Tree_Element, BlahooTreeElement>(Blah_Tree_Element_new(key,data))
{
	//Constructor - Creates a new tree element 
}

void BlahooTreeElement::call_function(blah_tree_element_func *function)
{
	return;
}
		
void BlahooTreeElement::call_with_arg(blah_tree_element_func_1arg *function, void *arg)
{
	return;
}

blah_bool BlahooTreeElement::call_arg_return_bool(blah_tree_element_bool_func_1arg *function, void *arg)
{
	return BLAH_TRUE;
}

void *BlahooTreeElement::search(blah_tree_search_func *search_function, void *arg)
{	//Performs a linear recursive search from location of given element in tree.
	//Calls search_function for each element of the tree in sort order, using the
	//element's data as the argument and 'arg' as a second argument.  Returns the data
	//pointer of the first element for which search_function returns BLAH_TRUE, or
	//NULL if no match;
	return arg;
}


/* Tree Function Declarations */
		
BlahooTree::BlahooTree(char *name) : BlahooWrapper<Blah_Tree, BlahooTree>(Blah_Tree_new((char*)name))
{
	//creates new empty tree
}

blah_bool BlahooTree::remove_element(char *key)
{
	//Removes element with given key from tree.  Does not free data pointed to by tree element.
	//Returns zero if error
	return BLAH_TRUE;
}

blah_bool BlahooTree::insert_element(char *key, void *data)
{
	//Inserts a new element into the tree, with given key and data pointer
	return BLAH_TRUE;
}

void BlahooTree::call_function(void *function)
{	//Calls function for each element, using data pointer as argument to given function 
	return;
}

void BlahooTree::call_with_arg(void *function, void *arg)
{	//Calls function for each element, using data pointer as argument to given function
	return;
}

void BlahooTree::init(char *name)
{	//Sets the name of the tree, and first element pointer to NULL
	return;
}

Blah_Tree_Element *BlahooTree::find_element(char *key)
{	//Finds tree element with given key
	return (Blah_Tree_Element*)1;
}

void *BlahooTree::search(blah_tree_search_func *search_function, void *arg)
{	//Calls search_function for each element of the tree in sort order, using the
	//element's data as the argument and 'arg' as second.  Returns the data pointer
	//of the first element for which search_function returns BLAH_TRUE,
	//or NULL if no match;
	return arg;
}

BlahooTree::~BlahooTree()
{	//Destructor function
	return;
}

void BlahooTree::destroy_elements()
{	//clears all memory allocated for elements and data but does not destroy basic tree header
	return;
}

void BlahooTree::remove_all()
{	//removes all elements but retains empty tree structure.  Does not free data
	return;
}
