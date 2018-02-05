/*
 * Name        : [Coding assignment 3] string_list.cpp
 * Author      : Jisook Kim
 * Description : Create a StringList class that will create 
 *  dynamic instances of strings and store them into a dynamic array. 
 */

#include "string_list.h"

// constructor
StringList::StringList() {
  // creates a dynamic array of 25 elements (string pointers)
  list_ = new string*[25];
  // initializes the elements to NULL
  for (int i = 0; i < 25; i++)
    list_[i] = NULL;
  max_capa_ = 25;
  current_size_ = 0;
}

// Destructor: Frees the memory for all dynamic strings
// Frees the memory for the dynamic string* array
StringList::~StringList() {
  // First delete all of our dynamic StringList objects
  for (unsigned int i = 0; i < current_size_; i++)
    delete list_[i];
  // Then delete the dynamic list_ array
  delete[] list_;
}

void StringList::AddItem(string* add_item) {
  // if the memory is full, increase 10 dynamic array
  if (current_size_ == max_capa_) {
    inc_array();
  }
  // store the item to the array and increase current size
  list_[current_size_] = add_item;
  current_size_++;
}

/* Delete the location of item
 * Has one parameter, an integer of the location to delete. 
 * Location is zero-indexed. 
 * After you delete the item you will need to pack your array 
 * (shift all items "down" so there are no empty slots between items). 
 * If the location is not valid, do nothing.
 */
void StringList::DeleteItem(unsigned int location_del) {
  // if the location exists, delete the item
  if (location_del < current_size_) {
    // shift all items to down
    // Compacts the array to get rid of an empty spot in the array
    del_array(location_del);
  }  // if not found, do nothing
}

/* Get item
 * Has one parameter, an integer of the location to retrieve the string. 
 * This function will return a pointer to the string requested. 
 * If the location is not valid, return NULL.
 */
string* StringList::GetItem(unsigned int location_get) {
  // if the location exists, return the item
  if (location_get < current_size_) {
    return list_[location_get];
  }
  return NULL;
}

unsigned int StringList::GetSize() {
  return current_size_;
}

unsigned int StringList::GetCapacity() {
  return max_capa_;
}

/* Sorts the array by lexicographic ordering, case-insensitive. 
 * You will need to use one of the sorting algorithms lectured in class.
 */
void StringList::Sort() {
  string swap;
  // bubble sort
  for (unsigned int i = current_size_-1; i >= 1; i--) {
    for (unsigned int j = 0; j <= i-1; j++) {
      if (ToLower(*list_[j]) > ToLower(*list_[j+1])) {
        // Swap if it is not in order
        swap = *list_[j];
        *list_[j] = *list_[j+1];
        *list_[j+1] = swap;
      }
    }
  }
}

/* Returns a string containing all strings in the list, 
 * separated by a ` the ` is usually located above the tab key.
 */ 
string StringList::ToFile() {
  stringstream ss;
  string all_string;
  // check if it's empty
  if (current_size_ == 0)
    return all_string;

  for (unsigned int i = 0; i < current_size_ - 1; i++)
    ss << *list_[i] << '`';  // dereference
  ss << *list_[current_size_ - 1];
  all_string = ss.str();
  return all_string;
}

/* Overloaded Friend operator<<
 * Outputs a numbered list of all strings present in the list.
 */
ostream& operator <<(ostream &out, StringList &list) {
  for (unsigned int i = 0; i < list.current_size_; i++)
    out << i + 1 << ": " << *list.list_[i] << endl;
  return out;
}
