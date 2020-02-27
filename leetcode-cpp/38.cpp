#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; i++){
            string temp;
            for (int j = 0; j < s.size(); j++){
                int num_count = 1;
                while(j + 1 < s.size() && s[j+1] == s[j]){
                    j++;
                    num_count++;
                }
                temp += to_string(num_count) + s[j];
            }
            s = temp;
        }
        return s;
    }
};

int main(){
    Solution a;
    cout << a.countAndSay(5) <<endl;
    return 0;
}
