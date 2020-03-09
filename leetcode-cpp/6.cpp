#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || numRows >= s.size()) return s;
        vector<string> temp(numRows);
        int loc = 1, row = 0;
        for (int i = 0; i < s.size(); i++) {
            if (row == 0) {
                loc = 1;
            }
            else if (row == numRows - 1) {
                loc = -1;
            }
            temp[row].push_back(s[i]);
            row += loc;
        }
        string ret = "";
        for (int i = 0 ; i< numRows; i++) {
            ret += temp[i];
        }
        return ret;
    }
};

int main(){
    Solution s;
    string b = "aaaa";
    cout << s.longestPalindrome(b) <<endl;
    return 0;
}
