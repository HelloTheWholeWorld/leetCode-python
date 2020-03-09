#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    int orangesRtting(vector<vector<int>>& grid) {
        int min = 0, fresh = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) q.push({i, j});
        }
        vector<pair<int, int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        while(!q.empty()) {
            int n = q.size();
            bool rotten = false;
            for(int i = 0; i < n; i++) {
                auto x = q.front();
                q.pop();
                for(auto cur: dirs) {
                    int i = x.first + cur.first;
                    int j = x.second + cur.second;
                    if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1) {
                        grid[i][j] = 2;
                        q.push({i, j});
                        fresh--;
                        rotten = true;
                    }
                }
            }
            if(rotten) min++;
        }
        return fresh ? -1 : min;
    }
};

int main(){
    Solution s;
//    vector<string> ret = s.generateParenthesis(3);
//    for (auto i : ret){
//        cout <<i <<endl;
//    }


//    int target = -11;
//    vector<vector<int>> ret = s.fourSum(nums, target);
//    for (int i = 0; i < ret.size(); i++){
//        for (int j = 0; j < ret[i].size(); j++){
//            cout << ret[i][j] << "\t";
//        }
//        cout <<endl;
//    }

//    ListNode* a = new ListNode(1);
//    a->next = new ListNode(2);
//    a->next->next = new ListNode(3);
//    a->next->next->next = new ListNode(4);
//    a->next->next->next->next = new ListNode(5);

//    ListNode* ret = s.swapPairs(a);
//    while(ret){
//        cout << ret->val << endl;
//        ret = ret->next;
//    }
//    return 0;
}
