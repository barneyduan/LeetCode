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

struct HashNode {
  int value;
  HashNode *next;

  HashNode(int v = 0) : value(v), next(nullptr) {}
};

HashNode* AddNewNode(HashNode *head, int value) {
  if (head == nullptr) {
    return new HashNode(value);
  }
  HashNode *temp = head;
  while (temp->next != nullptr) {
    if (temp->value != value) {
      temp = temp->next;
    } else {
      return head;
    }
  }
  if (temp->value != value) {
    temp->next = new HashNode(value);
  }
  return head;
}

HashNode* DeleteNode(HashNode *head, int value) {
  if (head == nullptr) return head;
  if (head->value == value) {
    HashNode *temp = head->next;
    head->next = nullptr;
    delete head;
    return temp;
  }
  HashNode *pre = head;
  while (pre->next) {
    if (pre->next->value == value) {
      HashNode *temp = pre->next;
      pre->next = temp->next;
      temp->next = nullptr;
      delete temp;
      break;
    }
    pre = pre->next;
  }
  return head;
}

bool ContainNode(HashNode *head, int value) {
  if (head == nullptr) return false;
  while (head) {
    if (head->value == value) {
      return true;
    }
    head = head->next;
  }
  return false;
}

HashNode* DeleteHead(HashNode *head) {
  if (head == nullptr) {
    return head;
  }
  HashNode* pre = head->next;
  head->next = nullptr;
  delete head;
  return pre;
}

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() : hash_(769, nullptr) {

    }

    ~MyHashSet() {
      for (auto i : hash_) {
        while (i != nullptr) {
          i = DeleteHead(i);
        }
      }
    }

    void add(int key) {
      size_t index = key % hash_size;
      HashNode *head = hash_[index];
      hash_[index] = AddNewNode(head, key);
    }

    void remove(int key) {
      size_t index = key % hash_size;
      HashNode *head = hash_[index];
      hash_[index] = DeleteNode(head, key);
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
      return ContainNode(hash_[key % hash_size], key);
    }

private:
  std::vector<HashNode*> hash_;
  const size_t hash_size = 769;
};

struct HashNode2 {
  int v;
  HashNode2 *left;
  HashNode2 *right;

  HashNode2(int value) : v(value), left(nullptr), right(nullptr) {}
};

bool ContainNode(HashNode2 *root, int value) {
  if (root == nullptr) return false;

  if (root->v == value) {
    return true;
  } else if (root->v < value) {
    return ContainNode(root->right, value);
  } else {
    return ContainNode(root->left, value);
  }
}

HashNode2* AddNewNode(HashNode2 *root, int value) {
  if (root == nullptr) {
    return new HashNode2(value);
  }

  if (root->v < value) {
    root->right = AddNewNode(root->right, value);
  } else {
    root->left = AddNewNode(root->left, value);
  }
  return root;
}

HashNode2 *DeleteNode(HashNode2 *root, int value) {
  if (root == nullptr) {
    return root;
  }

  if (root->v < value) {
    root->right = DeleteNode(root->right, value);
  } else if (root->v > value) {
    root->left = DeleteNode(root->left, value);
  } else {
    if (root->left == nullptr) {
      HashNode2 *temp = root->right;
      delete root;
      return temp;
    } else if (root->right == nullptr) {
      HashNode2 *temp = root->left;
      delete root;
      return temp;
    } else {
      HashNode2 *temp = root->right;
      HashNode2 *pre_temp = root;
      while (temp->left) {
        pre_temp = temp;
        temp = temp->left;
      }

      root->v = temp->v;
      if (pre_temp == root) {
        pre_temp->right = DeleteNode(temp, temp->v);
      } else {
        pre_temp->left = DeleteNode(temp, temp->v);
      }
    }
  }
  return root;
}

HashNode2 *DeleteNode2(HashNode2 *root, int value) {
  if (root == nullptr) {
    return root;
  }
  if (root->v < value) {
    root->right = DeleteNode(root->right, value);
  } else if (root->v > value) {
    root->left = DeleteNode(root->left, value);
  } else {
    if (root->left == nullptr) {
      HashNode2 *temp = root->right;
      delete root;
      return temp;
    } else if (root->right == nullptr) {
      HashNode2 *temp = root->left;
      delete root;
      return temp;
    } else {
      HashNode2 *temp = root->right;
      while (temp->left) {
        temp = temp->left;
      }
      swap(root->v, temp->v);
      root->right = DeleteNode(root->right, value);
      return root;
    }
  }
}

int main() {
  MyHashSet *obj = new MyHashSet();
  obj->add(2);
  obj->add(2);
  obj->remove(2);
  cout << obj->contains(2);
  return 0;
}

class MySolution {
 public:
  // Write your code there...

};



