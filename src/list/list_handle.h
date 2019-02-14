// Fight for your dream, Barney

// All List handle functions

#ifndef LEETCODE_LIST_HANDLE_H__
#define LEETCODE_LIST_HANDLE_H__

#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL){}
};


// 1->2->3->4->5->NULL

ListNode* reverseList(ListNode* head) {

  ListNode *tail = NULL;
  while (head) {
    ListNode *p = head->next;
    head->next = tail;
    tail = head;
    head = p;
  }

  return tail;
}

void reversePrintList(ListNode *head) {

  if (!head->next) {
    return;
  }
  reversePrintList(head->next);
  cout << head->val << "->";
}

void deleteSingleNode(ListNode * first, ListNode *pos) {

  if (!first) {
    return;
  }
  if (!pos) {
    return;
  }

  pos->val = pos->next->val;
  pos->next = pos->next->next;
  delete pos->next;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

  ListNode *result = new ListNode(0);
  ListNode *first = result;
  while (l1 && l2) {
    int up = result->val + l1->val + l2->val;
    result->val = up % 10;
    result->next = new ListNode(up/10);
    result = result->next;
    l1 = l1->next;
    l2 = l2->next;
  }
  while (l1) {
    int up = (l1->val + result->val);
    result->val = up % 10;
    result->next = new ListNode(up / 10);
    result = result->next;
    l1 = l1->next;
  }
  while (l2) {
    int up = (l2->val + result->val);
    result->val = up % 10;
    result->next = new ListNode(up /10 );
    result = result->next;
    l2 = l2->next;
  }

  if (result->val == 0) {
    ListNode *delete_node = first;
    while (delete_node->next != result) {
      delete_node = delete_node->next;
    }
    delete_node->next = NULL;
    delete result;
  }

  return first;

}

// 2*(a+b) = a + b + n*(b+c)
// a = (n-1)*(b+c) + c
ListNode *detectCycle(ListNode *head) {
  if (!head) {
    return NULL;
  }
  ListNode *fast = head->next;
  ListNode *slow = head;
  while (fast != slow && fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
  }
  if (!fast || !fast->next) return NULL;
  slow = head;
  // correct the encounter place index
  fast = fast->next;
  while (fast != slow) {
    fast = fast->next;
    slow = slow->next;
  }
  return fast;
}

bool hasCycle(ListNode *head) {
  if (!head) {
    return false;
  }
  ListNode *fast = head->next;
  ListNode *slow = head;
  while (fast != slow && fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
  }
  if (!fast || !fast->next) return false;
  return true;
}

// 1->2->3
// 2->4

// 1->
// 2->
// 2->
// 3->4
// 2->3->4
//
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

  if (!l1 && !l2) return NULL;
  if (!l1) return l2;
  if (!l2) return l1;

  if (l1->val < l2->val) {
    l1->next = mergeTwoLists(l1->next, l2);
    return l1;
  } else {
    l2->next = mergeTwoLists(l1, l2->next);
    return l2;
  }

}

ListNode* mergeKLists(vector<ListNode*>& lists) {

  int n = lists.size();
  if (n == 0) {
    return NULL;
  }
  while (n > 1) {
    int k = (n+1)/2;
    for (int i = 0; i < n/2; i++) {
      lists[i] = mergeTwoLists(lists[i], lists[i+k]);
    }
    n = k;
  }
  return lists[0];
}

void ListTestMain() {

  int x[] = {2, 0, -4};
  ListNode *head = new ListNode(3);
  ListNode *first = head;
  for (int i = 0; i < 3; i ++) {
    ListNode *p = new ListNode(x[i]);
    head->next = p;
    head = p;
  }
  head->next = first->next;

  //ListNode *r = detectCycle(first);
  //reversePrintList(first);

  ListNode *head1 = new ListNode(1);
  ListNode *first1 = head1;
  int x1[] = {3, 4};
  for (int i = 0; i < 2; ++i) {
    head1->next = new ListNode(x1[i]);
    head1 = head1->next;
  }

  ListNode *head2 = new ListNode(1);
  ListNode *first2 = head2;
  int x2[] = {2, 3};
  for (int i = 0; i < 2; ++ i) {
    head2->next = new ListNode(x2[i]);
    head2 = head2->next;
  }

  ListNode *k = mergeTwoLists(first1, first2);

}



#endif //LIST_HANDLE_H
