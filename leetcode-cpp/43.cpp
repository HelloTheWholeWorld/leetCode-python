#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        unsigned short s1 = num1.size(), s2 = num2.size();
        unsigned short temp_num[s1 + s2] = {0};
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (unsigned int i = 0; i < s1; i++) {
            for (unsigned int j = 0; j < s2; j++) {
                temp_num[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        unsigned short carry = 0;
        for (unsigned int i = 0; i < s1 + s2; i++) {
            temp_num[i] += carry;
            carry = temp_num[i] / 10;
            temp_num[i] %= 10;
        }

        string ret = "";
        short pos = s1 + s2 - 1;
        while(temp_num[pos] == 0 && pos >=0) pos--;
        while(pos >= 0){
            ret += (temp_num[pos] + '0');
            pos--;
        }
        return ret;
    }
};

int main(){
    Solution s;
    string num1 = "123", num2 = "456";
    cout << s.multiply(num1, num2) << endl;
}
