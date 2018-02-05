/*
 * Name        : [Coding assignment 3] string_list.h
 * Author      : Jisook Kim
 * Description : 
 * Data manager class. Contains a dynamic array of dynamic strings
 * Create a String List application
 * Create a StringList class that will create dynamic instances of strings and 
 * store them into a dynamic array.
 */

#ifndef KIM_STRING_LIST_H_
#define KIM_STRING_LIST_H_

#include <iostream>
#include <sstream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::ostream;

/*
 * You will create a String List application. 
 * You will create a StringList class that will create dynamic instances of strings and 
 * store them into a dynamic array. 
 * You will also create a StringUI class that will implement your StringList class.
 */

class StringList {
 public:
  // Constructor: Creates a dynamic array of 25 elements (string pointers)
  // and initializes the elements to NULL
  StringList();

  // Destructor: Frees the memory for all dynamic strings
  // Frees the memory for the dynamic string* array
  ~StringList();

  /* Add 10 items
   * If there is room in the array,
   * add the new dynamic string to the first available spot (i.e. the current size). 
   * If the array is full, increase capacity by 10 and then add the item.
   * @param - a dynamic instance of a string, i.e. the type is string*
   */
  void AddItem(string* add_item);

  /* Delete the location of item
   * Location is zero-indexed. 
   * After you delete the item you will need to pack your array 
   * (shift all items "down" so there are no empty slots between items). 
   * If the location is not valid, do nothing.
   * @param - an integer of the location to delete.
   */
  void DeleteItem(unsigned int location_del);

  /* Get item
   * This function will return a pointer to the string requested.
   * If the location is not valid, return NULL.
   * @param - an integer of the location to retrieve the string.
   */
  string* GetItem(unsigned int location_get);

  /* This functions will get the current size of the list
   * @return int - the current size of the list 
   * (number of items present).
   */
  unsigned int GetSize();

  /* This function will get a maximum capacity of dynamic array of string
   * @return int - the current maximum capacity 
   * of the list (number of slots).
   */
  unsigned int GetCapacity();

  /* Sorts the array by lexicographic ordering, case-insensitive. 
   * You will need to use one of the sorting algorithms lectured in class.
   */
  void Sort();

  /* Returns a string containing all strings in the list, 
   * separated by a ` the ` is usually located above the tab key.
   */ 
  string ToFile();

/* Overloaded Friend operator<<
 * Outputs a numbered list of all strings present in the list.
 */
  friend ostream& operator <<(ostream &out, StringList &list);

 private:
/* Private Member Function 1:
 * Increases the capacity of the array by 10. Should be called by
 * AddItem at the appropriate time.
 */
  void inc_array() {
    // create a bigger array (adding 10 to current size)
    string **temp = new string* [max_capa_ + 10];

    // copy pointer to the bigger array
    for (unsigned int i = 0; i < max_capa_; i++) {
      temp[i] = list_[i];
    }
    // delete the old array
    delete[] list_;
    // set dangling pointers to NULL ???? how??

    // point to the new array
    list_ = temp;
    // increase the capacity
    max_capa_ += 10;
  }

/* Private Member Function 2:
 * Compacts the array to get rid of an empty spot in the array. Should
 * be called by DeleteItem at the appropriate time.
 * @param - an integer of the location to delete.
 */
  void del_array(unsigned int location_del) {
    // delete the item of the location
    delete list_[location_del];
    // shift all items down
    for (unsigned int i = location_del; i < current_size_ - 1; i++) {
      list_[i] = list_[i + 1];
    }
    // make the last(empty) item to NULL
    list_[current_size_ - 1] = NULL;
    current_size_--;
  }

/* Private Member Function 3:
 * Helper for Sort to uppercase or lowercase a string
 * to easily compare strings of differing cases.
 * @param - a string we will make lowercase.
 * @return string - string converted to lowercase
 */
  string ToLower(string str) {
  // convert a string to lowercase
  for (unsigned int i = 0; i < str.length(); i++)
    str.at(i) = tolower(str.at(i));
  return str;
  }

 /*  
 * Private Data Members: 
 * - A dynamic array of string*s
 * - An unsigned integer to hold the maximum capacity of your list
 * - An unsigned integer to hold the current size of your list
 */
  string **list_;
  unsigned int max_capa_;
  unsigned int current_size_;
};

#endif
