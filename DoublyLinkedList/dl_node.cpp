/* 
 * Name: dl_node.cpp
 * Author: Jisook Kim
 * Description: a single node in the DLList
 */

#include "dl_node.h"

// constructor
DLNode::DLNode()
: content_(0), prev_node_(NULL), next_node_(NULL) {
}

// destructor
DLNode::~DLNode() {
}

void DLNode::SetContents(int content) {
  content_ = content;
}


void DLNode::SetNext(DLNode* nextnode) {
  next_node_ = nextnode;
}

void DLNode::SetPrevious(DLNode* prevnode) {
  prev_node_ = prevnode;
}

int DLNode::GetContents() {
  return content_;
}

DLNode* DLNode::GetNext() const {
  return next_node_;
}

DLNode* DLNode::GetPrevious() const {
  return prev_node_;
}
