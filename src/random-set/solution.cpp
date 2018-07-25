// https://leetcode.com/problems/insert-delete-getrandom-o1/

#include <vector>
#include <unordered_map>
#include <stdexcept>

using namespace std;

class RandomizedSet {
  public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
      const auto it = table_.find(val);
      if (it != table_.end()) {
        return false;
      }

      val_.push_back(val);
      table_[val] = val_.size()-1;
      return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
      const auto it = table_.find(val);
      if (it == table_.end()) {
        return false;
      }

      const auto idx = it->second;
      swap(val_.back(), val_[idx]);
      table_[val_[idx]] = idx;
      table_.erase(it);
      val_.pop_back();
      return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
      const int size = val_.size();
      if (!size) {
        throw runtime_error("empty");
      }
      auto rnd_idx = rand()%size;
      return val_[rnd_idx];
    }
  private:
    unordered_map<int, int> table_; // val => idx
    vector<int> val_; // idx => val
};
