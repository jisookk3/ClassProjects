/* 
 * Name: dl_list.h
 * Author: Jisook Kim
 * Description: This class for your doubly-linked list
 */

#ifndef KIM_DL_LIST_H_
#define KIM_DL_LIST_H_

#include "dl_node.h"

#include <iostream>
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
using std::cout;
using std::endl;

class DLList {
 public:
  // Constructor
  DLList();

  // Destructor
  // Calls the Clear() Function
  ~DLList();

  // Named GetSize. Returns the size of the list. const function.
  unsigned int GetSize() const;

  /*
   * Named PushFront. 
   * Has one parameter, an integer to add to the list. 
   * Creates a DLNode with the contents of the parameter and adds
   * that node to the front of the list.
   */
  void PushFront(int new_content);

  /*
   * Named PushBack. 
   * Has one parameter, an integer to add to the list. 
   * Creates a DLNode with the contents of the parameter and adds that
   * node to the end of the list.
   */
  void PushBack(int new_content);

  /*
   * Named GetFront. 
   * Returns the integer value of the node at the beginning of the list. 
   * const function. Output "List Empty" to
   * standard error output if the list is empty and return 0.
   */
  int GetFront() const;

  /*
   * Named GetBack. 
   * Returns the integer value of the node at the end of the list. 
   * const function. Output "List Empty" to standard error output 
   * if the list is empty and return 0.
   */
  int GetBack() const;

  /*
   * Named PopFront. Removes the first node in the list. 
   * Output "List Empty" to standard error output 
   * if the list was already empty.
   */
  void PopFront();

  /*
   * Named PopBack. Removes the last node in the list. 
   * Output "List Empty" to standard error output 
   * if the list was already empty.
   */
  void PopBack();

  /*
   * Named RemoveFirst. Has one parameter, an integer to find. 
   * If the value is found, remove that node from the list. 
   * Will only remove the first node that matches the value. 
   * If the value is not found, 
   * output "Not Found" to standard error output.
   */
  void RemoveFirst(int find);

  /*
   * Named RemoveAll. Has one parameter, an integer to find. 
   * If the value is found, remove that node from the list. 
   * Will remove all nodes that match the value. 
   * If the value is not found, output "Not Found" 
   * to standard error output.
   */
  void RemoveAll(int find);

  /*
   * Named Exists. Has one parameter, an integer to find. 
   * If the value is found, return true, else return false.
   */
  bool Exists(int find);

  /*
   * Named Clear. 
   * Clears all nodes from the list, 
   * resets the size to 0 and head and tail to NULL.
   */
  void Clear();

  /*
   * Named ToStringForwards. 
   * Outputs the contents of the list as a comma separated list 
   * ("1, 2, 3, etc") starting at the first node and ending 
   * at the last node. If the list is empty return the empty string 
   * and output "List Empty" to standard error output.
   */
  string ToStringForwards();

  /*
   * Named ToStringBackwards. 
   * Outputs the contents of the list as a comma separated list 
   * ("1, 2, 3, etc") starting at the last node and ending 
   * at the first node. 
   * If the list is empty return the empty string and 
   * output "List Empty" to standard error output.
   */
  string ToStringBackwards();


  /* Private Members:
   * The size of your list
   * Pointer to the head node
   * Pointer to the tail node
   */
 private:
  DLNode* head_;
  DLNode* tail_;
  unsigned int size_;
};

#endif
