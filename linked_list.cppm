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