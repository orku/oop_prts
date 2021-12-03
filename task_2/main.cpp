#include <iostream>




template<class T> class node{
public:
    T node_data;
    node<T>* prev_node;
    node<T>* next_node;

    node(){
        node_data;
        prev_node = nullptr;
        next_node = nullptr;
    }

    explicit node(const T& data) :node_data(data){
        next_node = nullptr;
        prev_node = nullptr;
    }

    ~node() = default;
};

template<class T> class double_linked_list{
public:
    double_linked_list(){
        head_ = nullptr;
        tail_ = nullptr;
        count_ = 0;
    }


    ~double_linked_list() = default;

    void push_head(const T& data){
        auto* tmp = new node<T>(data);
        if (!head_){
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

    void push_tail(const T& data){
        auto* tmp = new node<T>(data);
        if (!tail_){
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

    node<T> *split_()
    {
        node<T>* fast = head_;
        node<T>* slow = head_;
        while (fast->next_node && fast->next_node->next_node)
        {
            fast = fast->next_node->next_node;
            slow = slow->next_node;
        }
        node<T>* tmp = slow->next_node;
        slow->next_node = nullptr;
        return tmp;
    }

    node<T>* merge_(node<T>* first, node<T>* second)
    {
        if (!first) {
            return second;
        }
        if (!second) {
            return first;
        }
        if (first->node_data < second->node_data)
        {
            first->next_node = merge_(first->next_node, second);
            first->next_node->prev_node = first;
            first->prev_node = nullptr;
            return first;
        }
        else
        {
            second->next_node = merge_(first, second->next_node);
            second->next_node->prev_node = second;
            second->prev_node = nullptr;
            return second;
        }
    }

    node<T>* mergeSort_(node<T>* head_node)
    {
        if (!head_node || !head_node->next_node)
            return head_node;
        node<T>* second = split_();

        head_node = mergeSort_(head_node);
        second = mergeSort_(second);

        return merge_(head_node, second);
    }

    node<T>* head_;
    node<T>* tail_;
private:
    unsigned int count_ = 0;

};




using namespace std;
class Node
{
public:
    int data;
    Node *next, *prev;
};

Node *split_(Node *head)
{
    Node *fast = head,*slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *temp = slow->next;
    slow->next = NULL;
    return temp;
}


// Function to merge two linked lists
Node *merge(Node *first, Node *second)
{
    // If first linked list is empty
    if (!first)
        return second;

    // If second linked list is empty
    if (!second)
        return first;

    // Pick the smaller value
    if (first->data < second->data)
    {
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

// Function to do merge sort
Node *mergeSort_(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *second = split_(head);

    // Recur for left and right halves
    head = mergeSort_(head);
    second = mergeSort_(second);

    // Merge the two sorted halves
    return merge(head, second);
}

// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(Node **head, int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = temp->prev = NULL;
    if (!(*head))
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

// A utility function to print a doubly linked list in
// both forward and backward directions
void print(Node *head)
{
    Node *temp = head;
    cout<<"Forward Traversal using next pointer\n";
    while (head)
    {
        cout << head->data << " ";
        temp = head;
        head = head->next;
    }
    cout  << "\nBackward Traversal using prev pointer\n";
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}

// Split a doubly linked list (DLL) into 2 DLLs of
// half sizes

// Driver program
int main()
{
    Node *head = NULL;
    insert(&head, 5);
    insert(&head, 20);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 30);
    insert(&head, 10);
    head = mergeSort_(head);
    cout << "Linked List after sorting\n";
    print(head);
    std::cout << " " << std::endl;

    double_linked_list<int> lst;
    lst.push_tail(3);
    lst.push_tail(4);
    lst.push_tail(5);
    lst.push_tail(900);
    lst.push_tail(1);
    lst.push_tail(4);
    lst.push_tail(8777);
    std::cout << lst.pop_head() << std::endl;
    std::cout << lst.pop_head() << std::endl;
    lst.mergeSort_(lst.head_);
    std::cout<< lst.pop_head() << std::endl;
    std::cout << lst.pop_tail() << std::endl;


    int a = 10;
    int b = 20;

    return 0;
}