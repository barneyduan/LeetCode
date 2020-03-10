// Practice make perfect :)
// Duan Lian

#include <iostream>
#include <string>

using namespace std;

class A {
 public:
  void move_copy(string &&str) {
    // str is still a lvalue
    // if we want use move_constructor of string, it should
    // call again std::move()
    str_ = std::move(str);
  }

  void move_copy2(string &&str) {
    // copy constructor
    str_ = str;
  }

 private:
  string str_;
};

int main() {
  A a;
  if (true) {
    string str = "a";
    a.move_copy(std::move(str)); // str no longer exist
    cout << str << endl;

    str = "b";
    /* a.move_copy(str); */
    // lvalue can't bind to a rvalue reference, this is not universal reference.
    cout << str << endl;

    str = "c";
    a.move_copy2(std::move(str));
    cout << str << endl; // this will call copy constructor

    str = "d";
    /* a.move_copy2(str); */
    cout << str << endl;
  }
  return 0;
}
