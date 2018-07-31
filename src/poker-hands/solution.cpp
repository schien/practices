// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1256

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// card numbering: value << 2 | suit
static int to_card_number(const char value, const char suit) {
  int number;
  switch (value) {
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      number = value - '0';
      break;
    case 'T':
      number = 10;
      break;
    case 'J':
      number = 11;
      break;
    case 'Q':
      number = 12;
      break;
    case 'K':
      number = 13;
      break;
    case 'A':
      number = 14;
      break;
  }

  number <<= 2;

  switch (suit) {
    case 'C':
      number |= 0;
      break;
    case 'D':
      number |= 1;
      break;
    case 'H':
      number |= 2;
      break;
    case 'S':
      number |= 3;
      break;
  }

  return number;
}

static int to_suit(const int number) {
  return number&3;
}

static int to_value(const int number) {
  return number>>2;
}

static bool is_flush(const vector<int>& hand) {
  const int suit = to_suit(hand[0]);
  for (int i = 1; i < 5; ++i) {
    if (suit != to_suit(hand[i])) {
      return false;
    }
  }
  return true;
}

static int is_straight(const vector<int>& hand) {
  for (int i = 0; i < 4; ++i) {
    if (to_value(hand[i]) + 1 != to_value(hand[i+1])) {
      return 0;
    }
  }
  return to_value(hand[4]);
}

// cat << 20 | cat_rank
// high card:      (0<<20) | v4 << 16 | v3 << 12 | v2 << 8 | v1 << 4 | v0
// pair:           (1<<20) | p << 12 | v2 << 8 | v1 << 4 | v0
// two pair:       (2<<20) | p1 << 8 | p2 << 4| v0
// three:          (3<<20) | t
// straight:       (4<<20) | v
// flush:          (5<<20) | v4 << 16 | v3 << 12 | v2 << 8 | v1 << 4 | v0
// full house      (6<<20) | t
// four:           (7<<20) | f
// straight flush  (8<<20) | v
static int hand_rank(const vector<int>& hand) {
  int straight_value = is_straight(hand);

  if (is_flush(hand)) {
    if (straight_value) {
      return (8<<20) | straight_value;
    } else {
      return (5<<20) | (to_value(hand[4]) << 16) | (to_value(hand[3]) << 12) | (to_value(hand[2]) << 8) | (to_value(hand[1]) << 4) | (to_value(hand[0]));
    }
  }

  int max_kind = 0;
  unordered_map<int, int> bucket;
  for (auto n : hand) {
    int kind = ++bucket[to_value(n)];
    max_kind = max(max_kind, kind);
  }

  switch (bucket.size()) {
    case 2: {
      // four or full house
      int result = (max_kind == 4) ? 7<<20 : 6<<20;
      for (auto& e:bucket) {
        if (e.second == max_kind) {
          result |= e.first;
          break;
        }
      }
      return result;
    }
    case 3:
      if (max_kind == 3) {
        // three
        int result = 3<<20;
        for (auto& e:bucket) {
          if (e.second == 3) {
            result |= e.first;
            break;
          }
        }
        return result;
      } else {
        //two pair
        int result = 2<<20;
        int shift = 8;
        for (int i = 4; i >= 0; --i) {
          const int v = to_value(hand[i]);
          if (bucket[v] == 2) {
            result |= v << shift;
            shift -= 4;
            --i;
          } else {
            result |= v;
          }
        }
        return result;
      }
      break;
    case 4: {
    //pair
      int result = 1 << 20;
      int shift = 8;
      for (int i = 4; i >= 0; --i) {
        const int v = to_value(hand[i]);
        if (bucket[v] == 2) {
          result |= v << 12;
          --i;
        } else {
          result |= v << shift;
          shift -= 4;
        }
      }
      return result;
    }
    case 5:
    //high card or straight
      if (straight_value) {
        return (4<<20) | straight_value;
      } else {
        return (to_value(hand[4]) << 16) | (to_value(hand[3]) << 12) | (to_value(hand[2]) << 8) | (to_value(hand[1]) << 4) | (to_value(hand[0]));
      }
    default:
      return -1;
  }
}

class Solution {
public:
  int compare(const vector<string>& black, const vector<string>& white) {
    vector<int> deck_black, deck_white;

    for (int i = 0; i < 5; ++i) {
      deck_black.push_back(to_card_number(black[i][0], black[i][1]));
      deck_white.push_back(to_card_number(white[i][0], white[i][1]));
    }
    sort(deck_black.begin(), deck_black.end());
    sort(deck_white.begin(), deck_white.end());

    return hand_rank(deck_black) - hand_rank(deck_white);
  }
};
