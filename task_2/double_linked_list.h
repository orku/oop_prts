#ifndef TASK_2_DOUBLE_LINKED_LIST_H
#define TASK_2_DOUBLE_LINKED_LIST_H
#include <iostream>

template<typename T>
class double_linked_list;

template<typename T>
std::ostream& operator<<(std::ostream&, const double_linked_list<T>&);

template<typename T>
class node {
public:
  T node_data;
  node<T> *prev_node;
  node<T> *next_node;

  node() {
    node_data;
    prev_node = nullptr;
    next_node = nullptr;
  }

  explicit node(const T &data) : node_data(data) {
    next_node = nullptr;
    prev_node = nullptr;
  }

  ~node() = default;
};

template<typename T>
class double_linked_list {
public:
  double_linked_list() {
    head_ = nullptr;
    tail_ = nullptr;
    count_ = 0;
  }

  ~double_linked_list() = default;

  void push_head(const T &data) {
    auto *tmp = new node<T>(data);
    if (!head_) {
      head_ = tmp;
      tail_ = tmp;
      head_->next_node = tail_;
      count_++;
    } else {
      tmp->next_node = head_;
      head_->prev_node = tmp;
      head_ = tmp;
      count_++;
    }
  }

  void push_tail(const T &data) {
    auto *tmp = new node<T>(data);
    if (!tail_) {
      head_ = tmp;
      tail_ = tmp;
      head_->next_node = tail_;
      count_++;
    } else {
      tmp->prev_node = tail_;
      tail_->next_node = tmp;
      tail_ = tmp;
      count_++;
    }
  }

  T pop_tail() {
    node<T> *tmp = tail_;
    T ret_val = tmp->node_data;
    tail_ = tail_->prev_node;
    delete tmp;
    count_--;
    return ret_val;
  }

  void sort() {
    node<T> *left = head_;
    node<T> *right = head_->next_node;

    auto *tmp = new node<T>;
    while (left->next_node) {
      while (right) {
        if ((left->node_data) > (right->node_data)) {
          tmp->node_data = left->node_data;
          left->node_data = right->node_data;
          right->node_data = tmp->node_data;
        }
        right = right->next_node;
      }
      left = left->next_node;
      right = left->next_node;
    }
  }

  unsigned int length() const {
    return count_;
  }

  friend std::ostream& operator<< <>(std::ostream& ostr, const double_linked_list<T>& lst);
private:
  node<T> *head_;
  node<T> *tail_;
  unsigned int count_ = 0;
};

template <typename T>
std::ostream & operator<<(std::ostream& ost, const double_linked_list<T>& lst){
  node<T>* tmp;
  tmp = lst.tail_;
  while (tmp){
    ost << tmp->node_data << "   ";
    tmp = tmp->prev_node;
  }
  return ost;
}


#endif //TASK_2_DOUBLE_LINKED_LIST_H
