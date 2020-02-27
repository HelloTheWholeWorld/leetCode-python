#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0) return true;
        char left[] = {'(', '[', '{'};
        char right[] = {')', ']', '}'};
        stack<char> stk;
        for (int i = 0; i < s.size(); i++){
            char temp = s[i];
            if (temp == '(' || temp == '[' || temp == '{')
                stk.push(temp);
            else{
                if (stk.empty())
                    return false;
                if (temp == ')')
                    if (stk.top() == '(')
                        stk.pop();
                    else
                        return false;
                else if (temp == ']')
                    if (stk.top() == '[')
                        stk.pop();
                    else
                        return false;
                else if (temp == '}')
                    if (stk.top() == '{')
                        stk.pop();
                    else
                        return false;
            }
        }
        return stk.empty();
    }
};

int main(){
    string s = "{[]}";
    Solution a;
    bool ret = a.isValid(s);
    cout << ret << endl;
    return 0;
}
