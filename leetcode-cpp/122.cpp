#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
//    int maxProfit(vector<int>& prices) {
//        if (prices.size() <= 1) return 0;
//        return max(recall(prices, 1, -prices[0], 1),
//                   recall(prices, 1, 0, 0));
//    }
//
//    int recall(vector<int>& prices, int day, int profit, int buy){
//        if (day == prices.size() - 1)
//            return buy == 0 ? profit : profit + prices[day];
//        else {
//            // 当前没买
//            if (buy == 0)
//                return max(recall(prices, day + 1, profit - prices[day], 1),
//                            recall(prices, day + 1, profit, 0));
//            // 当前已买
//            else
//                return max(recall(prices, day + 1, profit + prices[day], 0),
//                           recall(prices, day + 1, profit, 1));
//        }
//    }
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int max_profit = 0;
        for (int i = 0; i < prices.size() - 1; i++)
            if (prices[i + 1] > prices[i])
                max_profit += prices[i + 1] - prices[i];
        return max_profit;
    }
};

int main(){
    Solution a;
    vector<int> prices({7,6,4,3,1});
    cout << a.maxProfit(prices) << endl;
    return 0;
}
