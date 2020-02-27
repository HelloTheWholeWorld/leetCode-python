#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) return "";
        if (strs.size() == 1) return strs[0];
        int min_len = INT_MAX;
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].size() < min_len)
                min_len = strs[i].size();
        }
        int max_pre = 0;
        string ret;
        while (max_pre < min_len){
            char temp = strs[0][max_pre];
            for (int i = 0; i < strs.size(); i++)
                if (strs[i][max_pre] != temp)
                    return ret;
            max_pre++;
            ret.append({temp});
        }
        return ret;
    }
};

int main(){
    vector<string> temp{"flower","flow","flight"};
    Solution a;
    string ret = a.longestCommonPrefix(temp);
    cout << ret <<endl;
    return 0;
}
