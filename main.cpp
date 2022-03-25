#include <iostream>  // cout

#include "assignment/dynamic_array.hpp"  // DynamicArray
#include "assignment/linked_list.hpp"    // LinkedList
#include "assignment/array_stack.hpp"    // ArrayStack
#include "assignment/linked_queue.hpp"   // LinkedQueue

using std::cout;
using namespace assignment;

int main(int argc, char **argv) {

  // Пример. Создание пустого динамического массива.
  auto * array = new DynamicArray(5);

  return 0;
}
