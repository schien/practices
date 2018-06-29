// https://leetcode.com/problems/reverse-vowels-of-a-string/

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
    bool isVowel(const char c) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                return true;
            default:
                return false;
        }
    }
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size()-1;
        while (i < j) {
            while (!isVowel(s[i]) && ++i < j);
            while (!isVowel(s[j]) && i < --j);
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};
