#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

class Solution {
public:
    void lookBack(vector<int>& candidates, vector<vector<int>>& ret, list<int>& stk, int target, int idx){
//        for (auto i : stk){
//            cout << i << " ";
//        }
//        cout << "\t" << target<<endl;
        if (target == 0){
            vector<int> temp;
            temp.assign(stk.begin(), stk.end());
            ret.push_back(temp);
            return ;
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (target < candidates[i])
                break;
            if (i == idx || (i != idx && candidates[i] != candidates[i - 1])) {
                stk.push_back(candidates[i]);
                lookBack(candidates, ret, stk, target - candidates[i], i+1);
                stk.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return vector<vector<int>>();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        list<int> stk;
        lookBack(candidates, ret, stk, target, 0);
        return ret;
    }
};

int main(){
    Solution s;
    vector<int> candidates({2,5,2,1,2});
    int target = 5;
    vector<vector<int>> ret = s.combinationSum2(candidates, target);
    for (int i = 0; i < ret.size(); i++){
        for (int j = 0; j < ret[i].size(); j++){
            cout << ret[i][j] << "\t";
        }
        cout <<endl;
    }
}
