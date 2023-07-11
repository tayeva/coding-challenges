/*
You are given an array of k linked-lists lists,
each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

struct Compare {
  bool operator()(const ListNode *a, const ListNode *b) const {
    return a->val > b->val;
  }
};

ListNode *merge_k_lists(vector<ListNode *> &lists) {
  priority_queue<ListNode *, vector<ListNode *>, Compare> heap;
  for (ListNode *list : lists) {
    if (list)
      heap.push(list);
  }
  ListNode dummy_head(0);
  ListNode *tail = &dummy_head;
  while (!heap.empty()) {
    ListNode *node = heap.top();
    heap.pop();
    tail->next = node;
    tail = tail->next;
    if (node->next)
      heap.push(node->next);
  }
  return dummy_head.next;
}

void print_list(ListNode *head) {
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  // Initial list: 1 4 5 2 3 3 2 6
  ListNode list1(1);
  list1.next = new ListNode(4);
  list1.next->next = new ListNode(5);
  ListNode list2(1);
  list2.next = new ListNode(3);
  list2.next->next = new ListNode(3);
  ListNode list3(2);
  list3.next = new ListNode(6);
  vector<ListNode *> lists = {&list1, &list2, &list3};
  ListNode *mergedList = merge_k_lists(lists);
  print_list(mergedList);
  // Should print: 1 1 2 3 3 4 5 6
  return EXIT_SUCCESS;
}
