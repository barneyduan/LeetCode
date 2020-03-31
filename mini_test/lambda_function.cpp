// Practice make perfect :)
// Duan Lian

#include <iostream>
#include <functional>
#include <unordered_map>

using namespace std;

class A {
 public:
  A(int a) : a_(a) {}
  virtual ~A() = default;

  using Func = std::function<void(int)>;
  void RegisterFunc(int i, Func func) {
    func_[i] = std::move(func);
  }

  void Print(int k, int v) {
    auto it = func_.find(k);
    if (it != func_.end()) {
      it->second(v);
    }
  }

 private:
  int a_;
  std::unordered_map<int, Func> func_;
};

class B : public A {
 public:
  B(int b = 0) : A(b-1), b_(b) {
    RegisterFunc(1, [=](int v) {
      cout << "b: " << b << endl;
      cout << v << endl;
    });
  }

 private:
  int b_;
};

int main() {
  int v = std::stoi("2");
  B b(v);
  b.Print(1, 3);
  // stdout:
  // b: 2
  // 3
  return 0;
}


/*
 * NOTE(lianduan): lambda capture:
 * None: capture nothing
 * =: capture local variable, by value
 * &: capture local variable, by reference
 * this: capture class variable
 * a: capture local variable a, by value
 * &a, capture local variable a, by reference
 * =, &a, capture local variable a by reference, and other by value
 */
