/* 
 * Name: dl_list.cpp
 * Author: Jisook Kim
 * Description: This class for your doubly-linked list
 */

#include "dl_list.h"

// Constructor
DLList::DLList()
: head_(NULL), tail_(NULL), size_(0) {
}

// Destructor
// Calls the Clear() Function
DLList::~DLList() {
  Clear();
}

// Named GetSize. Returns the size of the list. const function.
unsigned int DLList::GetSize() const {
  return size_;
}

/*
 * Named PushFront. 
 * Has one parameter, an integer to add to the list. 
 * Creates a DLNode with the contents of the parameter and adds
 * that node to the front of the list.
 */
void DLList::PushFront(int new_content) {
  DLNode* new_node = new DLNode;
  new_node->SetContents(new_content);
  // if list is empty, point tail to the new node
  if (head_ == NULL) {
    tail_ = new_node;
  } else {
  // head points back to new node
  head_->SetPrevious(new_node);
  }
  // new node points to where head is pointing to
  new_node->SetNext(head_);
  // head point to new node
  head_ = new_node;

  size_++;
}

/*
 * Named PushBack. 
 * Has one parameter, an integer to add to the list. 
 * Creates a DLNode with the contents of the parameter and adds that
 * node to the end of the list.
 */
void DLList::PushBack(int new_content) {
  if (head_ == NULL) {
    PushFront(new_content);
  } else {
    DLNode* new_node = new DLNode;
    new_node->SetContents(new_content);

    // new tail points back to old tail
    new_node->SetPrevious(tail_);
    // point the tail node to the new node
    tail_->SetNext(new_node);
    // point the tail to the new node
    tail_ = new_node;
    size_++;
  }
}

/*
 * Named GetFront. 
 * Returns the integer value of the node at the beginning of the list. 
 * const function. Output "List Empty" to
 * standard error output if the list is empty and return 0.
 */
int DLList::GetFront() const {
  if (head_ == NULL) {
    std::cerr << "List Empty";
    return 0;
  }
  return head_->GetContents();
}

/*
 * Named GetBack. 
 * Returns the integer value of the node at the end of the list. 
 * const function. Output "List Empty" to standard error output 
 * if the list is empty and return 0.
 */
int DLList::GetBack() const {
  if (head_ == NULL) {
    std::cerr << "List Empty";
    return 0;
  }
  return tail_->GetContents();
}

/*
 * Named PopFront. Removes the first node in the list. 
 * Output "List Empty" to standard error output 
 * if the list was already empty.
 */
void DLList::PopFront() {
  if (head_ == NULL) {
    std::cerr << "List Empty";
  } else {
    // create a temporary pointer to where head is pointing to
    DLNode* temp = head_;
    // point head to the next node in the list
    head_ = head_->GetNext();
    delete temp;  // delete the first node
    // if one node, head becomes NULL so tail should be NULL
    if (head_ == NULL)
      tail_ = NULL;
    else
      head_->SetPrevious(NULL);
    size_--;
  }
}

/*
 * Named PopBack. Removes the last node in the list. 
 * Output "List Empty" to standard error output 
 * if the list was already empty.
 */
void DLList::PopBack() {
//  std::cout << size_ << std::endl;
  if (head_ == NULL) {
    std::cerr << "List Empty";
  } else {
    // one node exists
    if (head_->GetNext() == NULL) {
      PopFront();
    } else {
      // goal: point the previous node of tail to NULL
      // create a temp of DLNode pointing to previous node of tail
      DLNode* temp = tail_;
      tail_ = tail_->GetPrevious();
      delete temp;
      tail_->SetNext(NULL);

      size_--;
    }
  }
}

/*
 * Named RemoveFirst. Has one parameter, an integer to find. 
 * If the value is found, remove that node from the list. 
 * Will only remove the first node that matches the value. 
 * If the value is not found, 
 * output "Not Found" to standard error output.
 */
void DLList::RemoveFirst(int find) {
  if (head_ == NULL) {
    std::cerr << "Not Found";
  } else {
    // create a trailer and it of DLNode pointing to head
    DLNode* it = head_;
    DLNode* trailer = head_;
    // loop until find the value(parameter)
    while (it != NULL && it->GetContents() != find) {
      // trailer catches up it
      trailer = it;
      it = it->GetNext();
    }

    if (it == NULL) {
      std::cerr << "Not Found";
    } else if (it == head_) {
      PopFront();
    } else if (it == tail_) {
      PopBack();
    } else {  // remove the value in the middle node
      // set it next node points back to trailer
      (it->GetNext())->SetPrevious(trailer);
      // remove item in the middle of list
      trailer->SetNext(it->GetNext());
      delete it;
      size_--;
    }
  }
}

/*
 * Named RemoveAll. Has one parameter, an integer to find. 
 * If the value is found, remove that node from the list. 
 * Will remove all nodes that match the value. 
 * If the value is not found, output "Not Found" 
 * to standard error output.
 */
void DLList::RemoveAll(int find) {
  if (head_ == NULL) {
    std::cerr << "Not Found";
  } else {
    // create a trailer and it of DLNode pointing to head
    DLNode* it = head_;
    DLNode* trailer = head_;
    // check flag if finding done or not
    bool ck_find = true;

    // loop until find the value(parameter)
    while (ck_find == true) {
      // try to find the value
      while (it != NULL && it->GetContents() != find) {
        // trailer catches up it
        trailer = it;
        it = it->GetNext();
      }

      if (it == NULL) {
        std::cerr << "Not Found";
        ck_find = false;
      } else if (it == head_) {
        PopFront();
        // Luke: We just deleted the iterator, so set it to head_
        it = head_;
      } else if (it == tail_) {
        PopBack();
        // Luke: We're done now
        ck_find = false;
      } else {
        // set it next node points back to trailer
        (it->GetNext())->SetPrevious(trailer);
        // remove item in the middle of list
        trailer->SetNext(it->GetNext());
        // Luke: Need a temp pointer
        DLNode* temp = it->GetPrevious();
        delete it;
        // Luke: At this point your iterator is pointing to garbage, as we deleted it.
        it = temp;
        size_--;
      }
    }  // end while(ck_find == true)
  }  // end else (head != NULL)
}

/*
 * Named Exists. Has one parameter, an integer to find. 
 * If the value is found, return true, else return false.
 */
bool DLList::Exists(int find) {
  if (head_ == NULL)
    return false;

  // create a trailer and it of DLNode pointing to head
  DLNode* it = head_;
  // loop until find the value(parameter)
  while (it != NULL && it->GetContents() != find) {
    it = it->GetNext();
  }
  if (it == NULL)
    return false;
  return true;
}

/*
 * Named Clear. 
 * Clears all nodes from the list, 
 * resets the size to 0 and head and tail to NULL.
 */
void DLList::Clear() {
  // Create an iterator pointer and point it to where head is pointing
  DLNode* it = head_;
  while (it != NULL) {
    // Head points to the next node
    head_ = head_->GetNext();
    // Delete what the iterator is pointing to
    delete it;
    // Iterator points to the next node (i.e. where head is pointing to)
    it = head_;
    // At the end set the size of the list to zero
    size_--;
  }
  head_ = NULL;
  tail_ = NULL;
}

/*
 * Named ToStringForwards. 
 * Outputs the contents of the list as a comma separated list 
 * ("1, 2, 3, etc") starting at the first node and ending 
 * at the last node. If the list is empty return the empty string 
 * and output "List Empty" to standard error output.
 */
string DLList::ToStringForwards() {
  stringstream ss;
  string str;
  DLNode* it = head_;
  // empty list check
  if (it == NULL)
    std::cerr << "List Empty";

  while (it != NULL) {
    ss << it->GetContents();
    if (it->GetNext() != NULL)
      ss << ", ";
    it = it->GetNext();
  }
  str = ss.str();
  //std::cout << str << std::endl;
  return str;
}

/*
 * Named ToStringBackwards. 
 * Outputs the contents of the list as a comma separated list 
 * ("1, 2, 3, etc") starting at the last node and ending 
 * at the first node. 
 * If the list is empty return the empty string and 
 * output "List Empty" to standard error output.
 */
string DLList::ToStringBackwards() {
  stringstream ss;
  string str;
  DLNode* it = tail_;
  // empty list check
  if (it == NULL)
    std::cerr << "List Empty";

  while (it != NULL) {
    ss << it->GetContents();
    if (it->GetPrevious() != NULL)
      ss << ", ";
    it = it->GetPrevious();
  }
  str = ss.str();
 // std::cout << str << std::endl;
  return str;
}
