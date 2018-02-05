/*
 * Name        : bst_treet.h (Templated class)
 * Author      : Jisook Kim
 * Description : a binary search tree to hold Templated nodes
 */

#ifndef BS_TREET_H_
#define BS_TREET_H_

#include "bst_nodet.h"

#include <iostream>
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

template <typename T>
class BSTreeT {
 public:
  // Constructor: Initializes root to NULL and your node count to 0
  BSTreeT()
    : root_(NULL), size_(0) {
  }

  // Destructor: Calls the Clear Function
  ~BSTreeT() {
    Clear();
  }

  // Member Function 1: Named GetSize.
  // Returns the number of nodes in the tree. const
  unsigned int GetSize() const {
    return size_;
  }

  // Member Function 2: Named Clear.
  // Deletes all nodes in the tree. (Frees the Memory)
  // helper function in private member functions
  void Clear() {
    Clear(root_);
  }

  /*
  Member Function 3: Named Insert. 
  Has a parameter which is the value to add.
  If the value is already in the tree just increment that node's count.
  Returns the count of the value in the node. i.e. 
  returns 1 the first time the value is added to the tree. 
  Returns 2 the second time the value is added, 3 the third time, etc. 
  */
  unsigned int Insert(T value) {
    return Insert(value, root_);
  }

  /* Member Function 4: Named Exists. 
   * Searches your tree for a particular value. 
   * If found returns true, else returns false
   */
  bool Exists(T value) {
    return Exists(value, root_);
  }

  /* Member Function 5: Named Remove. 
   * Searches your tree for a particular value and decrements the corresponding count. 
   * If the current count is 1
   * remove the node instead of decrementing the count. 
   * Returns the current count of the value in the tree, 
   * 0 if it was just removed, and -1 if it doesn't exist in the tree.
   */
  int Remove(T value) {
    return Remove(value, root_);
  }

  // Member Function 6: Named Get. Searches for a particular value.
  // Returns a pointer to the node if found otherwise returns NULL.
  BSTNodeT<T>* Get(T value) {
    return Get(value, root_);
  }

  /* Member Function 7: Named ToStringForwards. 
   * Outputs the contents of the nodes in the tree (in order) 
   * as a comma separated list ("hello", "goodbye", etc). 
   * If the list is empty return the empty string.
   */
  string ToStringForwards() {
    return ToStringForwards(root_);
  }

  /* Member Function 8: Named ToStringBackwards. 
   * Outputs the contents of the nodes in the tree (in backwards order) 
   * as a comma separated list ("goodbye", "hello", etc). 
   * If the list is empty return the empty string.
   */
  string ToStringBackwards() {
    return ToStringBackwards(root_);
  }

  int FindMin(BSTNodeT<T>* sub_root) const {
    if (sub_root->GetLeft() != NULL)
      return FindMin(sub_root->GetLeft());
    return sub_root->GetContents();  // return min value
  }


 private:
  void Clear(BSTNodeT<T>*& sub_root);

  unsigned int Insert(T in, BSTNodeT<T>*& sub_root);

  bool Exists(T value, BSTNodeT<T>*& sub_root);

  int Remove(T value, BSTNodeT<T>*& sub_root);

  BSTNodeT<T>* Get(T value, BSTNodeT<T>*& sub_root);

  string ToStringForwards(BSTNodeT<T>* sub_root);

  string ToStringBackwards(BSTNodeT<T>* sub_root);


  /* Private members
   * Root pointer to the first node.
   * Size to hold how many nodes are in your tree.
   */
  BSTNodeT<T>* root_;
  unsigned int size_;
};

#include "bs_treet.tpp"

#endif
