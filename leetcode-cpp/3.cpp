#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int flag[256], count=0,left=0,ans =0;
        memset(flag,0,sizeof(flag));
        for(int i=0;i<s.size();i++){
            if(flag[s[i]]==0){
                flag[s[i]]=1;
                count=i-left+1;
                if(ans<count)
                    ans=count;
                // cout<<"+"<<s[i]<<'\t'<<endl;
            }else{
                // cout<<"+"<<s[i]<<'\t'<<endl;
                while(flag[s[i]]==1){
                    flag[s[left]] = 0;
                    left++;
                }
                flag[s[i]]=1;
            }
            // printf("s[%d]=%c, s[%d]=%c\n", left, s[left], i, s[i]);
        }
        return ans;
    }
//    int lengthOfLongestSubstring(string s) {
//        if (s.size() <= 1) return s.size();
//        set<char> temp_set;
//        int i = 0, j = 0;
//        int max_len = 1;
//        while(j < s.size()){
//            if (temp_set.find(s[j]) == temp_set.end()) {
//                temp_set.insert(s[j++]);
//                max_len = max_len > temp_set.size() ? max_len : temp_set.size();
//            }else{
//                temp_set.erase(s[i++]);
//            }
//        }
//        return max_len;
//    }
};

int main(){
    Solution s;
    string b = "abcabcbb";
    cout << s.lengthOfLongestSubstring(b) <<endl;
    return 0;
}
