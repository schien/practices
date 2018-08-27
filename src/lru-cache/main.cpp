#include <iostream>
#include "input_helper.h"

#include "solution.cpp"

int main() {
  int n = next<int>();

  LRUCache cache(n);

  while(true) {
     char op = next<char>();
     if (std::cin.eof()) {
       break;
     }

     switch (op) {
       case 'p':
         {
           int key = next<int>();
           int value = next<int>();
           cache.put(key, value);
         }
         break;
       case 'g':
         {
           int key = next<int>();
           auto output = cache.get(key);
           std::cout << output << std::endl;
         }
         break;
       default:
         break;
     }
  }
  return 0;
}
