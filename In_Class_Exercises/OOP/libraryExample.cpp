#include <iostream>
#include <string>
#include <list>
#include <cassert>

using namespace std;

/*
class Library {
private:
  list<Items *> contents;
  list<LibraryUser *> users;
public:
  
};
*/

class Items;

class LibraryUser {
private:
  string name;
  int itemsBorrowedCount;
  Items *itemsBorrowed[3];
public:
  LibraryUser(string _name) : name(_name) { 
    itemsBorrowedCount = 0;
    for (int n=0; n<3; n++)
      itemsBorrowed[n] = NULL;
  }
  bool borrowItem(Items *item, int days);
};

class Items {
protected:
  string title;
  int location;
  LibraryUser *borrowedBy;
public:
  Items(string _title, int _location) : title(_title), location(_location) {
    borrowedBy = NULL;
  }
  LibraryUser *getBorrower() const {
    return borrowedBy;
  }
  void setBorrower(LibraryUser *user) {
    borrowedBy = user;
  }
  virtual int getLoanPeriod() const = 0;
};

class Book : public Items {
private:
  int loanPeriod;
public:
  Book(string _title, int _location, int _lp) : Items(_title, _location) {
    loanPeriod = _lp;
      }
  int getLoanPeriod() const {
    return loanPeriod;
  }
};

class Periodical : public Items {
private:
  static int loanPeriod;
public:
  Periodical(string _title, int _location) : Items(_title, _location) {
  }
  int getLoanPeriod() const {
    return loanPeriod;
  }
  static void setLoanPeriod(int lp) {
    loanPeriod = lp;
  }
};

bool LibraryUser::borrowItem(Items *item, int days) {
  //    if (item == NULL)
  //      return false;
    assert(item != NULL);
    if (item-> getBorrower() != NULL ) {
      cout << "item already on loan" << endl;
      return false;
    }
    if (itemsBorrowedCount >= 3) {
      cout << "you've already borrowed too many items" << endl;
      return false;
    }
    if (days > item->getLoanPeriod()) {
      cout << "request days greater than maximum loan period" << endl;
      return false;
    }
    item->setBorrower(this);
    bool success = false;
    for (int n=0; n<3;n++) {
      if (itemsBorrowed[n] == NULL) {
	itemsBorrowed[n] = item;
	success = true;
        break;
      }
    }      
    if (!success) {
      cout << "records corrupted!" << endl;
      return false;
    }
    itemsBorrowedCount++;
    return true;
  }

int Periodical::loanPeriod = 5;

int main() {

  LibraryUser georgia("Georgia"), ali("Ali");

  Periodical::setLoanPeriod(7);

  Book cppwt("C++ Without Tears", 1, 10);
  Book hhtic("Hitchhikers Guide to IC", 2, 13);

  Periodical atwww80("Around...", 3);
  Periodical tmuqt("20m Under the Queen's Tower", 4);

  georgia.borrowItem(&cppwt, 7);

  return 0;
}
