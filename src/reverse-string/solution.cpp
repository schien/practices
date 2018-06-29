// https://leetcode.com/problems/reverse-string/description/

#include <string>
#include <iostream>

using namespace std;

static int x = []() {
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    string reverseString(string s) {
        int i = 0, j = s.size()-1;
        while (i < j) {
            swap(s[i++], s[j--]);
        }
        return s;
    }
};
