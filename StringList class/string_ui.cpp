/*
 * Name        : string_ui.cpp
 * Author      : Jisook Kim
 * Description : Contains the Menus and all other UI Operations. 
 * All input and output from this program must happen in the UI
 */

#include "string_ui.h"

// constructor: Allocates memory for the StringList object
StringUI::StringUI() {
  list_ = new StringList;
}

// destructor
StringUI::~StringUI() {
  delete list_;
  list_ = NULL;  // need???
}

void StringUI::Menu() {
  int choice = 0;
  int location = 0;

// Menu selection
  while (choice != 7) {
    cout << "\n=== Dynamic array string UI ===\n";
    cout << "1: Create a new string" << endl;
    cout << "2: Edit a string" << endl;
    cout << "3: Delete a string" << endl;
    cout << "4: View all strings" << endl;
    cout << "5: View specific string" << endl;
    cout << "6: Delete all strings" << endl;
    cout << "7: Quit program\n\n";

    cout << "=== Select the number: ";
    // menu choice limit 1 to 7
    choice = reader_.readInt(1, 7);

    string str;
    string *temp;
    switch (choice) {
      case 1:  // Create a new string
        // get a string from a user and add it to the list
        cout << "Enter a string: ";
        str = reader_.readString();
        list_->AddItem(new string(str));
        break;

      case 2:  // Edit a string
        // get the location where the string is, get a string from a user
        cout << "Enter the index of array to EDIT:";
        // up to current size
        location = reader_.readInt(0, list_->GetSize()-1);
        // *list_->GetItem(reader_.readInt(0, list_->GetSize()-1))
        // = reader_.readString();
        temp = list_->GetItem(location);  // a pointer to the string

        cout << "Enter a string: ";
        *temp = reader_.readString();
        break;

      case 3:  // Delete a string
        cout << "Enter the index of array to DELETE: ";
        location = reader_.readInt(0, list_->GetSize()-1);
        list_->DeleteItem(location);
        break;

      case 4:  // View all strings
        cout << *list_;
        break;

      case 5:  // View specific string
        cout << "Enter the index of the array to VIEW: ";
        location = reader_.readInt(0, list_->GetSize()-1);
        cout << *list_->GetItem(location) << endl;
        break;

      case 6:  // Delete all strings
        delete list_;
        list_ = new StringList;  // for the next string creating(=constructor)
        break;

      default:  // quit the program
        break;
    }
  }
}
