#include <iostream>
#include "double_linked_list.h"

int main() {

  double_linked_list<int> lst;
  lst.push_tail(5555);
  lst.push_tail(4);
  lst.push_tail(5);
  lst.push_tail(900);
  lst.push_tail(1);
  lst.push_tail(4);
  lst.push_tail(8777);
  std::cout << "Unsorted list case" << std::endl;
  std::cout << lst << std::endl;
  lst.sort();
  std::cout << "Sorted list case" << std::endl;
  std::cout << lst << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  lst.pop_tail();
  lst.pop_tail();
  std::cout << lst << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  lst.push_head(4543);
  lst.push_head(4534543);
  std::cout << lst << std::endl;
  return 0;
}