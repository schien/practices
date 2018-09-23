// https://leetcode.com/problems/heaters/

#include <vector>

using namespace std;

static int min_radius(int house, int ge, int le) {
  if (ge < 0) {
    return house - le;
  }
  if (le < 0) {
    return ge - house;
  }
  return min(house-le, ge-house);
}

class Solution {
  public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
      if (houses.empty()) { return 0; }
      if (heaters.empty()) { return -1; }

      sort(houses.begin(), houses.end());
      sort(heaters.begin(), heaters.end());

      const int sz = heaters.size();
      int result = 0;

      int g = 0;
      int l = -1;
      // for each house, found the closest left and right heater
      // to get the min radius for each house.
      for (auto house : houses) {
        while (g < sz && heaters[g] < house) ++g;
        while (l+1 < sz && heaters[l+1] <= house) ++l;
        const int ge = (g < sz) ? heaters[g] : -1;
        const int le = (l < 0) ? -1 : heaters[l];

        result = max(result, min_radius(house, ge, le));
      }
      return result;
    }
};
