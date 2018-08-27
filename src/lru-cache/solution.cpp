// https://leetcode.com/problems/lru-cache/

#include <vector>
#include <unordered_map>

using namespace std;

class LRUCache {
  struct Entry {
    int key = 0;
    int value = 0;
    Entry* next = nullptr;
    Entry* prev = nullptr;
  };
public:
  LRUCache(int capacity)
    : entries(capacity), available(capacity)
  {
  }

  int get(int key) {
    auto it = table.find(key);
    if (it == table.end()) {
      return -1;
    }

    Entry* curr = it->second;

    if (curr != first) {
      curr->prev->next = curr->next;
      if (curr->next) {
        curr->next->prev = curr->prev;
      } else {
        last = curr->prev;
      }
      first->prev = curr;
      curr->next = first;
      curr->prev = nullptr;
      first = curr;
    }
    return curr->value;
  }

  void put(int key, int value) {
    Entry* curr = nullptr;
    auto it = table.find(key);
    if (it != table.end()) {
      curr = it->second;
    }

    if (!curr) {
      if (available > 0) {
        curr = &entries[entries.size() - (available--)];

        curr->next = first;
        curr->key = key;
        if (first) {
          first->prev = curr;
        }
        first = curr;

        if (!last) {
          last = first;
        }

        table[key] = curr;
      } else if (last) {
        curr = last;
        table.erase(curr->key);

        curr->key = key;
        table[key] = curr;
      } else {
        return;
      }
    }

    if (curr != first) {
      if (curr == last) {
        last = curr->prev;
      }

      curr->prev->next = curr->next;
      if (curr->next) {
        curr->next->prev = curr->prev;
      }
      first->prev = curr;
      curr->next = first;
      curr->prev = nullptr;
      first = curr;
    }

    first->value = value;
  }
private:
  vector<Entry> entries;
  int available;
  Entry* first = nullptr;
  Entry* last = nullptr;
  unordered_map<int, Entry*> table;
};
