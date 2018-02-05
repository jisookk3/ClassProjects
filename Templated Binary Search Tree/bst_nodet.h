/*
 * Name        : bst_nodet.h (Templated class)
 * Author      : Jisook Kim
 * Description : a single node in the BSTreeT
 */

#ifndef BST_NODET_H_
#define BST_NODET_H_

#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;


template <typename T>
class BSTNodeT {
 public:
  // constructor 1: no parameters
  BSTNodeT() {
    contents_ = T();
    count_ = 0;
    left_ch_ = NULL;
    right_ch_ = NULL;
  }

  /* Constructor 2 (overloaded constructor)
   * One templated parameter for contents
   * Sets the templated contents to the parameter
   */
  BSTNodeT(const T &content) {
    contents_ = content;
    count_ = 0;
    left_ch_ = NULL;
    right_ch_ = NULL;
  }

// Destructor: Sets left and right child to NULL
  ~BSTNodeT() {
    left_ch_ = NULL;
    right_ch_ = NULL;
  }

  /* Mutator 1: SetContents
   * Has one templated parameter
   * Sets the contents to the given parameter's value.
   */
  void SetContents(T &content) {
    contents_ = content;
  }

  /* Mutator 2: SetLeft
   * Has one parameter which is a pointer to a BSTNodeT
   * Sets the internal left pointer to the given parameter's value.
   */
  void SetLeft(BSTNodeT *leftchild) {
    left_ch_ = leftchild;
  }

  /* Mutator 3: SetRight
   * Has one parameter which is a pointer to a BSTNodeT
   * Sets the internal right pointer to the given parameter's value.
   */
  void SetRight(BSTNodeT *rightchild) {
    right_ch_ = rightchild;
  }

  // IncrementCount. Increments the count by 1
  void IncrementCount() {
    count_++;
  }

  // DecrementCount. Decrements the count by 1
  void DecrementCount() {
    count_--;
  }

  /* Accessor 1: GetContents
   * Returns the value of the templated contents. const function.
   */
  T GetContents() const {
    return contents_;
  }

  T& GetContents() {
    return contents_;
  }

  /* Accessor 2: GetLeft
   * Returns a pointer by reference to the left node.
   */
  BSTNodeT*& GetLeft() {
    return left_ch_;
  }

  /* Accessor 3: GetRight
   * Returns a pointer by reference to the right node.
   */  
  BSTNodeT*& GetRight() {
    return right_ch_;
  }

  // Accessor 4: GetCount. Returns the count
  unsigned int GetCount() {
    return count_;
  }


 private:
  // a templated data type for the contents of the node
  T contents_;
  // An unsigned int to hold a count of how many times the contents
  // has been added
  unsigned int count_;

  // A pointer to the left child
  BSTNodeT *left_ch_;
  // A pointer to the right child
  BSTNodeT *right_ch_;
};


#endif
