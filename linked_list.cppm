export module linked_list;

#include <cstddef>
#include <stdexcept>

export template <typename T>
class LinkedList {
 public:
  LinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}

  ~LinkedList() { Clear(); }

  void Clear() {
    Node* current = head_;
    while (current != nullptr) {
      Node* next_node = current->next;
      delete current;
      current = next_node;
    }
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
  }

  void PushTail(const T& value) {
    Node* new_node = new Node(value);
    new_node->prev = tail_;
    if (tail_ != nullptr) {
      tail_->next = new_node;
    } else {
      head_ = new_node;
    }
    tail_ = new_node;
    ++size_;
  }

  void PushHead(const T& value) {
    Node* new_node = new Node(value);
    new_node->next = head_;
    if (head_ != nullptr) {
      head_->prev = new_node;
    } else {
      tail_ = new_node;
    }
    head_ = new_node;
    ++size_;
  }

  void PopHead() {
    if (head_ == nullptr) {
      throw std::out_of_range("PopHead: list is empty");
    }
    Node* old_head = head_;
    head_ = head_->next;
    if (head_ != nullptr) {
      head_->prev = nullptr;
    } else {
      tail_ = nullptr;
    }
    delete old_head;
    --size_;
  }

  void PopTail() {
    if (tail_ == nullptr) {
      throw std::out_of_range("PopTail: list is empty");
    }
    Node* old_tail = tail_;
    tail_ = tail_->prev;
    if (tail_ != nullptr) {
      tail_->next = nullptr;
    } else {
      head_ = nullptr;
    }
    delete old_tail;
    --size_;
  }

 private:
  struct Node {
    T value;
    Node* prev;
    Node* next;

    explicit Node(const T& node_value)
        : value(node_value), prev(nullptr), next(nullptr) {}
  };

  Node* head_;
  Node* tail_;
  std::size_t size_;
};