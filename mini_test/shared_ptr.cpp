// Practice make perfect :)
// Duan Lian

#include <iostream>
#include <memory>
#include <map>

using namespace std;

class C {
 public:
  C() {}
  ~C() { cout << "destruct c..." << endl; }
};

class B {
 public:
  B() { c_ = new C(); }
  ~B() { cout << "destruct b..." << endl; }
  void Close() {
    if (c_) {
      delete c_;
      c_ = nullptr;
    }
  }

 private:
  C* c_;
};

class A {
 public:
  A(int v) : v_(v), v2_(new B) {}
  ~A() { cout << "destruct: " << v_ << endl; }

 private:
  int v_;
  std::unique_ptr<B> v2_;
};

int main() {
  std::map<int, shared_ptr<A>> map_;
  if (true) {
    shared_ptr<A> ptr1(new A(1));
    cout << "1: " << ptr1.use_count() << endl;  // count: 1
    map_.insert(pair<int, shared_ptr<A>>(1, ptr1));
    cout << "2: " << ptr1.use_count() << endl;  // count: 2
  }
  auto it = map_.find(1);
  cout << "3: " << it->second.use_count() << endl;  // count: 1

  if (true) {
    auto it2 = it->second;
    cout << "4: " << it2.use_count() << endl;  // count: 2
  }
  cout << "5: " << it->second.use_count() << endl;  // count: 1
  map_.erase(it);  // count: 0
  cout << "end" << endl;
  return 0;
}
