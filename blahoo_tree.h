/* blah_tree.h - Implements a binary tree structure.
	Tree structure maintains the pointer to the first Blah_Tree_Element structure */

#ifndef _BLAHOO_TREE

#define _BLAHOO_TREE

#include <blah/blah.h>

#include "blahoo_list.h"

/* Structure Definitions */

typedef class BlahooTreeElement : private BlahooWrapper<Blah_Tree_Element, BlahooTreeElement>
{
	//defines a simple element structure to hold a pointer to tree data
	
	/* Element Function Prototypes */
	
	public:
		
		BlahooTreeElement(char *key, void *data);
			//Constructor - Creates a new tree element 

		void call_function(blah_tree_element_func *function);
		
		void call_with_arg(blah_tree_element_func_1arg *function, void *arg);

		blah_bool call_arg_return_bool(blah_tree_element_bool_func_1arg *function, void *arg); 

		void *search(blah_tree_search_func *search_function, void *arg);
			//Performs a linear recursive search from location of given element in tree.
			//Calls search_function for each element of the tree in sort order, using the
			//element's data as the argument and 'arg' as a second argument.  Returns the data
			//pointer of the first element for which search_function returns BLAH_TRUE, or
			//NULL if no match;

} BlahooTreeElement;

typedef class BlahooTree : private BlahooWrapper<Blah_Tree, BlahooTree>
{
	/* Tree Function Prototypes */
		
	public:
		BlahooTree(char *name);	//creates new empty tree

		blah_bool remove_element(char *key);
			//Removes element with given key from tree.  Does not free data pointed to by tree element.
			//Returns zero if error
	
		blah_bool insert_element(char *key, void *data);
			//Inserts a new element into the tree, with given key and data pointer
	
		void call_function(void *function); 
			//Calls function for each element, using data pointer as argument to given function 
	
		void call_with_arg(void *function, void *arg); 
			//Calls function for each element, using data pointer as argument to given function

		void init(char *name);
			//Sets the name of the tree, and first element pointer to NULL
	
		Blah_Tree_Element *find_element(char *key);
			//Finds tree element with given key
			
		void *search(blah_tree_search_func *search_function, void *arg);
			//Calls search_function for each element of the tree in sort order, using the
			//element's data as the argument and 'arg' as second.  Returns the data pointer
			//of the first element for which search_function returns BLAH_TRUE,
			//or NULL if no match;

		~BlahooTree();
			//Destructor function
			
		void destroy_elements(); 
			//clears all memory allocated for elements and data but does not destroy basic tree header
	
		void remove_all();
			//removes all elements but retains empty tree structure.  Does not free data
		
} BlahooTree;



#endif
