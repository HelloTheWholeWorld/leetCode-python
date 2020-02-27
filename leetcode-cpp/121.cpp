#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
//        if (prices.size() <= 1)
//            return 0;
//        int max_profit = 0;
//        for (int i = 0; i < prices.size() - 1; i++) {
//            int temp_max = 0;
//            for (int j = i + 1; j < prices.size(); j++)
//                temp_max = max(prices[j] - prices[i], temp_max);
//            max_profit = max(temp_max, max_profit);
//        }
//        return max_profit;
        if (prices.size() <= 1)
            return 0;
        // 当前遇到的谷底是必须用到的
        int min_val = INT_MAX, max_profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            min_val = min(prices[i], min_val);
            max_profit = max(max_profit, prices[i] - min_val);
        }
        return max_profit;
    }
};
int main(){
    Solution a;
    vector<int> prices({7,1,5,3,6,4});
    cout << a.maxProfit(prices) << endl;
    return 0;
}
