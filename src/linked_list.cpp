#include "assignment/linked_list.hpp"

namespace assignment {

  LinkedList::~LinkedList() {

    // эквивалентно очистке списка
    LinkedList::Clear();
  }

  void LinkedList::Add(int value) {
    Node* node = new Node(value, nullptr);
    if (size_ == 0) {
      front_ = node;
    } else {
      back_->next = node;
    }
    back_ = node;
    size_++;
  }

  bool LinkedList::Insert(int index, int value) {
    if (index < 0 || index > size_) {
      return false;
    }

    if (index == size_) {
      Add(value);
      return true;
    } else if (index == 0) {
      Node* node = front_;
      front_ = new Node(value, node);
    } else {
      Node* prev = FindNode(index - 1);
      Node* newNode = new Node(value, prev->next);
      prev->next = newNode;
    }
    size_++;
    return true;
  }

  bool LinkedList::Set(int index, int new_value) {
    if (index < 0 || index >= size_) {
      return false;
    }

    Node* cur = FindNode(index);
    cur->value = new_value;
    return true;
  }

  std::optional<int> LinkedList::Remove(int index) {
    int removedEl;
    if (index < 0 || index >= size_) {
      return std::nullopt;
    }
    if (index == 0) {
      removedEl = front_->value;
      front_ = front_->next;
    } else {
      Node* prev = FindNode(index - 1);
      removedEl = prev->next->value;
      prev->next = prev->next->next;
      if (index == size_ - 1) {
        back_ = prev;
      }
    }
    size_--;
    return removedEl;
  }

  void LinkedList::Clear() {
    Node* node = front_;
    for (int i = 0; i < size_; i++) {
      Node* next = node->next;
      delete node;
      node = next;
    }
    front_ = nullptr;
    back_ = nullptr;
    size_ = 0;
  }

  std::optional<int> LinkedList::Get(int index) const {
    if (index < 0 || index >= size_) {
      return std::nullopt;
    }
    return FindNode(index)->value;
  }

  std::optional<int> LinkedList::IndexOf(int value) const {
    Node* node = front_;
    for (int i = 0; i < size_; i++) {
      if (node->value == value) {
        return i;
      }
      node = node->next;
    }
    return std::nullopt;
  }

  bool LinkedList::Contains(int value) const {
    return IndexOf(value) != std::nullopt;
  }

  bool LinkedList::IsEmpty() const {
    return size_ == 0;
  }

  int LinkedList::size() const {
    return size_;
  }

  std::optional<int> LinkedList::front() const {
    if (size_ > 0) {
      return front_->value;
    }
    return std::nullopt;
  }

  std::optional<int> LinkedList::back() const {
    if (size_ > 0) {
      return back_->value;
    }
    return std::nullopt;
  }

  Node* LinkedList::FindNode(int index) const {
    if (index < 0 || index >= size_) {
      return nullptr;
    }
    Node* node = front_;
    for (int i = 0; i < index; i++) {
      node = node->next;
    }
    return node;
  }

  // ДЛЯ ТЕСТИРОВАНИЯ
  LinkedList::LinkedList(const std::vector<int>& values) {

    if (values.empty()) {
      return;
    }

    auto* curr_node = new Node(values.front());
    front_ = curr_node;

    for (int index = 1; index < values.size() - 1; ++index) {
      curr_node->next = new Node(values[index]);
      curr_node = curr_node->next;
    }

    if (values.size() == 1) {
      back_ = front_;
    } else {
      curr_node->next = new Node(values.back());
      back_ = curr_node->next;
    }

    size_ = static_cast<int>(values.size());
  }

  std::vector<int> LinkedList::toVector() const {

    if (front_ == nullptr || size_ == 0) {
      return {};
    }

    std::vector<int> array;
    array.reserve(size_);

    for (auto* node = front_; node != nullptr; node = node->next) {
      array.push_back(node->value);
    }

    return array;
  }

}  // namespace assignment