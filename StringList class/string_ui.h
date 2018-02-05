/*
 * Name        : string_ui.h
 * Author      : Jisook Kim
 * Description : 
 * Contains the Menus and all other UI Operations. 
 * All input and output from this program must happen in the UI
 */ 

#ifndef KIM_STRING_UI_H_
#define KIM_STRING_UI_H_

#include "CinReader.h"
#include "string_list.h"

#include <iostream>
#include <sstream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::stringstream;

class StringUI {
 public:
  // constructor: Allocates memory for the StringList object
  StringUI();
  
  // destructor: 
  // Frees the memory associated with the dynamic StringList object
  ~StringUI();
 
 /* Member Function 1: Menu
 * Contains all of the options specified above. 
 * All options may be contained in this function, 
 * but it would be better to make private member helper functions 
 * to help out the Menu function.
 */
 void Menu();
 
 
 private:

/* Private Data Members:
 * An instance of CinReader
 * A dynamic instance of StringList
 */
  CinReader reader_;
  StringList *list_;
};

#endif
