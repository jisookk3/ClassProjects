/*
 * Name        : bst_treet.tpp
 * Author      : Jisook Kim
 * Description : Definition for templated class
 */


// [ Private helper functions ]

// Clear entire contents of the tree, free all memory
// Post Order: clear left -> clear right -> clear root
template <typename T>
void BSTreeT<T>::Clear(BSTNodeT<T>*& sub_root) {
  if (sub_root != NULL) {
    Clear(sub_root->GetLeft());
    Clear(sub_root->GetRight());
    delete sub_root;
    sub_root = NULL;
    size_--;
  }
}

/* If the value is already in the tree just increment that node's count.
Returns the count of the value in the node. i.e. 
returns 1 the first time the value is added to the tree. 
Returns 2 the second time the value is added, 3 the third time, etc.
*/
template <typename T>
unsigned int BSTreeT<T>::Insert(T in, BSTNodeT<T>*& sub_root) {
  // check if the value exist in the tree
  if (sub_root == NULL) {
    sub_root = new BSTNodeT<T>(in); // insert into tree
    size_++;
    sub_root->IncrementCount();
    return sub_root->GetCount();
  } else if (in < sub_root->GetContents()) {  // small value, then go left
    return Insert(in, sub_root->GetLeft());
  } else if (in > sub_root->GetContents()) {  // large value, then go right
    return Insert(in, sub_root->GetRight());
  } else {  // same value, then increment count
    sub_root->IncrementCount();
    return sub_root->GetCount();
  }
}

// Searches your tree for a particular value. 
// If found returns true, else returns false
template <typename T>
bool BSTreeT<T>::Exists(T value, BSTNodeT<T>*& sub_root) {
  if (sub_root == NULL) {
    return false; // not found
  } else if (sub_root->GetContents() == value) {
    // found the value, YES!
    return true;
  } else if (sub_root->GetContents() > value) {
    // small value, then go left
    return Exists(value, sub_root->GetLeft());
  } else {
    // large value, then go right
    return Exists(value, sub_root->GetRight());
  }
}


/*
 * Searches your tree for a particular value and decrements the corresponding count. 
 * If the current count is 1
 * remove the node instead of decrementing the count. 
 * Returns the current count of the value in the tree, 
 * 0 if it was just removed, and -1 if it doesn't exist in the tree.
*/
template <typename T>
int BSTreeT<T>::Remove(T value, BSTNodeT<T>*& sub_root) {
  if (sub_root == NULL) {
    // not exist value
    return -1;
  } 

  else if (sub_root->GetContents() == value) {
    // Once we found the value, check already exist in the tree
    if (sub_root->GetCount() != 1) {
      // NOT remove. just return decrement
      sub_root->DecrementCount();
      return sub_root->GetCount();
    } 

    else {
      // Remove the value!!!
      // Now, determine if no ch, one Left ch, one Right ch, or 2 ch
      if (sub_root->GetLeft() == NULL && sub_root->GetRight() == NULL) {
        // NO children
        delete sub_root;
        sub_root = NULL;
      } else if (sub_root->GetLeft() != NULL && sub_root->GetRight() == NULL) {
        // ONE LEFT child
        // create temp
        BSTNodeT<T>* temp = sub_root;
        // sub_root points to left child
        sub_root = sub_root->GetLeft();
        delete temp;
      } else if (sub_root->GetLeft() == NULL && sub_root->GetRight() != NULL) {
        // ONE RIGHT Child
        BSTNodeT<T>* temp = sub_root;
        sub_root = sub_root->GetRight();
        delete temp;
      } else {
        // TWO Children //
        // find the minimum value in the right subtree
        // Replace value of the node to be removed with this value
        // copy min value to the node to be removed
        sub_root->GetContents() = FindMin(sub_root->GetRight());
        // delete the node of min value
        Remove(sub_root->GetContents(), sub_root->GetRight());
        size_++;
      }
        size_--;
        return 0; // Completed Remove!!!

    } // END of remove value

  }   // END of found value


  // keep Search (traverse) the tree
  else if (sub_root->GetContents() > value) {
  // if small, go left
    return Remove(value, sub_root->GetLeft());
  } else {
    // if large, go right
    return Remove(value, sub_root->GetRight());
  }
  
}


// Searches for a particular value. 
// Returns a pointer to the node if found otherwise returns NULL.
template <typename T>
BSTNodeT<T>* BSTreeT<T>::Get(T value, BSTNodeT<T>*& sub_root) {
  // check if the value exist in the tree
  if (sub_root == NULL) {
    return NULL;  // not found
  } else if (sub_root->GetContents() == value) {
    // found the value, then return the pointer to the node!
    return sub_root;
  } else if (sub_root->GetContents() > value) {
    // small value, then go left
    return Get(value, sub_root->GetLeft());
  } else {
    // large value, then go right
    return Get(value, sub_root->GetRight());
  }
}

// In Order: go left -> root -> right
template <typename T>
string BSTreeT<T>::ToStringForwards(BSTNodeT<T>* sub_root) {
  stringstream ss;
  if (sub_root != NULL) {
    ss << ToStringForwards(sub_root->GetLeft());
    // check if more values exist
    if (sub_root->GetLeft() != NULL)
      ss << ", ";

    ss << sub_root->GetContents();

    if (sub_root->GetRight() != NULL)
      ss << ", ";

    return ss.str() + ToStringForwards(sub_root->GetRight());
  }
  return ss.str();
}

// backwards: right -> root -> left
template <typename T>
string BSTreeT<T>::ToStringBackwards(BSTNodeT<T>* sub_root) {
  stringstream ss;
  if(sub_root != NULL) {
    ss << ToStringBackwards(sub_root->GetRight());
    
    if (sub_root->GetRight() != NULL)
      ss << ", ";
      
    ss << sub_root->GetContents();
    
    if (sub_root->GetLeft() != NULL)
      ss << ", ";

    return ss.str() + ToStringBackwards(sub_root->GetLeft());
  }
  return ss.str();
}

