#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        if (strs.size() == 0) return ret;
        unordered_map<string, vector<int>> hashmap;

        for (int i = 0; i < strs.size(); i++){
            string str(strs[i]);
            sort(str.begin(), str.end());
            if (hashmap.find(str) != hashmap.end()){
                hashmap[str].push_back(i);
            } else {
                vector<int> temp_val;
                temp_val.push_back(i);
                hashmap[str] = temp_val;
            }
        }
        for (auto iter : hashmap){
            vector<string> temp;
            for (auto idx : iter.second){
                temp.push_back(strs[idx]);
            }
            ret.push_back(temp);
        }
        return ret;
    }
};

int main(){
    Solution s;
    vector<string> strs({"eat", "tea", "tan", "ate", "nat", "bat"});
    vector<vector<string>> ret = s.groupAnagrams(strs);
    for (int i = 0; i < ret.size(); i++){
        for (int j = 0; j < ret[i].size(); j++){
            cout << ret[i][j] << "\t";
        }
        cout <<endl;
    }
}
