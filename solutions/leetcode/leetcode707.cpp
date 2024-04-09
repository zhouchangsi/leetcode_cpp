#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/design-linked-list/solutions/288354/cdan-lian-biao-shi-xian-xiang-xi-zhu-shi-by-carlsu/
class MyLinkedList {
 public:
  // 定义链表节点结构体
  struct LinkedNode {
    int val;
    LinkedNode* next;
    LinkedNode(int val) : val(val), next(nullptr) {}
  };

  // 初始化链表
  MyLinkedList() {
    dummy_ = new LinkedNode(0);
    size_ = 0;
  }

  // 获取到第index个节点数值，如果index是非法数值直接返回-1，
  // 注意index是从0开始的，第0个节点就是头结点
  int get(int index) {
    if (index > (size_ - 1) || index < 0) {
      return -1;
    }
    LinkedNode* cur = dummy_->next;
    while (index--) {  // 如果--index 就会陷入死循环
      cur = cur->next;
    }
    return cur->val;
  }

  // 在链表最前面插入一个节点，插入完成后，新插入的节点为链表的新的头结点
  void addAtHead(int val) {
    LinkedNode* new_head = new LinkedNode(val);
    new_head->next = dummy_->next;
    dummy_->next = new_head;
    size_++;
  }

  // 在链表最后面添加一个节点
  void addAtTail(int val) {
    LinkedNode* new_tail = new LinkedNode(val);
    LinkedNode* cur = dummy_;
    while (cur->next) {
      cur = cur->next;
    }
    cur->next = new_tail;
    size_++;
  }

  // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
  // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
  // 如果index大于链表的长度，则返回空
  void addAtIndex(int index, int val) {
    if (index > size_) {
      return;
    }
    LinkedNode* new_node = new LinkedNode(val);
    LinkedNode* cur = dummy_;
    while (index--) {
      cur = cur->next;
    }
    new_node->next = cur->next;
    cur->next = new_node;
    size_++;
  }

  // 删除第index个节点，如果index
  // 大于等于链表的长度，直接return，注意index是从0开始的
  void deleteAtIndex(int index) {
    if (index >= size_ || index < 0) {
      return;
    }
    LinkedNode* cur = dummy_;
    while (index--) {
      cur = cur->next;
    }
    LinkedNode* tmp = cur->next;
    cur->next = cur->next->next;
    delete tmp;
    size_--;
  }

 private:
  int size_;
  LinkedNode* dummy_;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */