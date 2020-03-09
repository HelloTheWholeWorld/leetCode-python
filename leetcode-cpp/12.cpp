#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string strs[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int i = 0;
        string ret = "";
        while (num != 0){
            while (num - nums[i] < 0)
                i++;
            num -= nums[i];
            ret.append(strs[i]);
        }
        return ret;
    }
};

int main(){
    Solution s;
    int a = 1994;
    cout << s.intToRoman(a) <<endl;
    return 0;
}
