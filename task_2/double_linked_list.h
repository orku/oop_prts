//
// Created by orku on 16.11.2021.
//

#ifndef TASK_2_DOUBLE_LINKED_LIST_H
#define TASK_2_DOUBLE_LINKED_LIST_H

template<class T> class node{
public:
    T node_data;
    T* prev_node;
    T* next_node;

    node(){
        node_data;
        prev_node = nullptr;
        next_node = nullptr;
    }

    explicit node(const T& data) :node_data(data){
        prev_node = nullptr;
        next_node = nullptr;
    }

    ~node() = default;
};

template<class T> class double_linked_list{
public:
    double_linked_list(){
        head_ = new node<T>();
        tail_ = new node<T>();
        head_->next_node = tail_;
        head_->prev_node = nullptr;
        tail_->next_node = nullptr;
        tail_->prev_node = head_;
        count_ = 0;
    }

    explicit double_linked_list(const T& data){
        head_ = new node<T>(data);
        tail_ = new node<T>();
        head_->next_node = tail_;
        head_->prev_node = nullptr;
        tail_->next_node = nullptr;
        tail_->prev_node = head_;
        count_ = 1;
    }

    ~double_linked_list() = default;

    void push_head(const T& data){
        auto* tmp = new  node<T>(data);
        tmp->next_node = head_;
        tmp->prev_node = nullptr;
        head_ = tmp;
        count_++;
    }

    void push_tail(const T& data){
        auto* tmp = new node<T>(data);
        tmp->next_node = nullptr;
        tmp->prev_node = tail_;
        tail_ = tmp;
        count_++;
    }

    T pop_head(){
        node<T>* tmp = head_;
        T ret_val = tmp->node_data;
        head_ = head_->next_node;
        delete tmp;
        count_--;
        return ret_val;
    }

    T pop_tail(){
        node<T>* tmp = tail_;
        T ret_val = tmp->node_data;
        tail_ = tail_->prev_node;
        delete tmp;
        count_--;
        return ret_val;
    }

    unsigned int length() const{
        return count_;
    }

    node<T>* split(){
        node<T>* fast = head_;
        node<T>* slow = head_;
        while (fast->next_node && fast->next_node->next_node){
            fast = fast->next_node->next_node;
            slow = slow->next_node;
        }
        node<T>* tmp = slow->next_node;
        slow->next_node = nullptr;
        return tmp;
    }
    node<T>* merge(node<T>* first, node<T>* second){
        if(!first){
            return second;
        }
        if(!second){
            return first;
        }
        if (first->node_data < second->node_data){
            first->next_node = merge(first->next_node, second);
            first->next_node->prev_node = first;
        }
    }
    void sort(){

    }

private:
    unsigned int count_ = 0;
    node<T>* head_;
    node<T>* tail_;
};

template<class T> void swap_(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

#endif //TASK_2_DOUBLE_LINKED_LIST_H
