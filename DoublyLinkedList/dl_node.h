/* 
 * Name: dl_node.h
 * Author: Jisook Kim
 * Description: a single node in the DLList
 */

#ifndef DL_NODE_KIM_H_
#define DL_NODE_KIM_H_

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class DLNode {
 public:
  /* Constructor
   * No parametersSets the integer to 0
   * Sets the previous node to NULLSets the next pointer to NULL
   */
  DLNode();

  // destructor
  ~DLNode();

  /* Mutator 1: SetContents
   * Has one integer parameter. 
   * Sets the internal integer to the given parameter's value.
   */
  void SetContents(int content);

  /* Mutator 2: SetNext. 
   * Has one parameter which is a pointer to a DLNode. 
   * Sets the internal next pointer to the given parameter's value.
   */
  void SetNext(DLNode* nextnode);

  /* Mutator 3: SetPrevious
   * Has one parameter which is a pointer to a DLNode. 
   * Sets the internal previous pointer to the given parameter's value.
   */
  void SetPrevious(DLNode* prevnode);

  /* Mutator 4
   * Named GetContents. Returns the value of the internal integer.
   * const function.
   */
  int GetContents();

  /* Accessor 1: GetNext
   * Returns the pointer to the next node. const function.
  */
  DLNode* GetNext() const;

  /* Accessor 2: GetPrevious. 
   * Returns the pointer to the previous node. const function.
   */
  DLNode* GetPrevious() const;


 private:
  int content_;
  DLNode* prev_node_;
  DLNode* next_node_;
};

#endif
