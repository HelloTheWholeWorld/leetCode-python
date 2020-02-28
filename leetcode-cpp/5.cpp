#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;
        int matrix[s.size()][s.size()];
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < s.size(); j++){
                if (i == j) matrix[i][j] = 1;
                else matrix[i][j] = 0;
            }
        }
        string ret = s.substr(0,1);
        int maxi = 0, len = 1;
        for (int add_base = 1; add_base < s.size(); add_base++) {
            for (int i = 0; i < s.size() && i + add_base < s.size(); i++){
                int j = i + add_base;
                int val = 0;
                if (j == i + 1)
                    val = s[i] == s[j];
                else
                    val = s[i] == s[j] && matrix[i+1][j-1];
                matrix[i][j] = val;
                if (val) {
                    maxi = i;
                    len = add_base + 1;
                }
            }
            ret = s.substr(maxi, len);
        }
//        for (int i = 0; i < s.size(); i++) {
//            for (int j =0 ;j <s.size(); j++){
//                cout << matrix[i][j] << "\t";
//            }
//            cout <<endl;
//        }
        return ret;
    }
};

int main(){
    Solution s;
    string b = "aaaa";
    cout << s.longestPalindrome(b) <<endl;
    return 0;
}
