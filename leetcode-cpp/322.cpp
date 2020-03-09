#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
    void coinChange(vector<int>& coins, int amount, int c_index, int count, int& ans){
        if (amount == 0)
        {
            ans = min(ans, count);
            return;
        }
        if (c_index == coins.size()) return;

        for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--)
        {
            coinChange(coins, amount - k * coins[c_index], c_index + 1, count + k, ans);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        sort(coins.rbegin(), coins.rend());
        int ans = INT_MAX;
        coinChange(coins, amount, 0, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }
};

int main(){
    Solution s;
    vector<int> coins({1, 2, 5});
    int amount = 11;
    int ret = s.coinChange(coins, amount);
    cout << ret << endl;
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
