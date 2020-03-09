#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if (str.size() == 0) return 0;
        int i = 0;
        while(str[i] == ' ') i++;
        if (isdigit(str[i]) || str[i] == '+' || str[i] == '-'){
            int flag = 1;
            if (str[i] == '-')
                flag = -1;
            if (!isdigit(str[i]))
                i++;
            long long ret = 0;
            while(i < str.size() && isdigit(str[i])) {
                    ret = ret * 10 + (str[i] - 48);
                if (ret >= ((long long)INT_MAX) + 1)
                    return flag == 1 ? INT_MAX : INT_MIN;
                i++;
            }
            ret *= flag;
            return (int)ret;
        }
        else{
            return 0;
        }
    }
};

int main(){
    Solution s;
    string b = "42";
    cout << s.myAtoi(b) <<endl;
    return 0;
}
