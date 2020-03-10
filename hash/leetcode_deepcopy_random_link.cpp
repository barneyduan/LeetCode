// practice make perfect :)
// Author: Duan Lian

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
  int val;
  Node *next;
  Node *random;

  Node(int v) : val(v), next(nullptr), random(nullptr) {}
};

class MySolution {
 public:
  // Write your code there...
  Node *copyRandomList(Node *head) {
    if (head == nullptr) return head;

    unordered_map<Node *, int> head_map;
    unordered_map<int, Node *> new_map;
    head_map[nullptr] = -1;
    new_map[-1] = nullptr;
    int index = 0;

    Node *temp = head;
    Node *new_head = new Node(temp->val);
    Node *new_temp = new_head;

    head_map[temp] = index;
    new_map[index] = new_head;

    while (temp->next) {
      index++;
      temp = temp->next;
      new_temp->next = new Node(temp->val);
      head_map[temp] = index;
      new_temp = new_temp->next;
      new_map[index] = new_temp;
    }

    temp = head;
    new_temp = new_head;
    int random_index = 0;

    while (temp) {
      random_index = head_map[temp->random];
      new_temp->random = new_map[random_index];
      temp = temp->next;
      new_temp = new_temp->next;
    }
    return new_head;
  }
};



