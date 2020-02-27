#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if (k == 0 || k == nums.size()) return;
        int count = 0;
        for (int i = 0; count < nums.size(); i++){
            int record = i;
            int prev = nums[i];
            do{
                int next = (i + k) % nums.size();
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                i = next;
                count++;
            }while(record != i);
        }
    }
};

int main(){
    Solution a;
    vector<int> prices({1,2,3,4,5,6});
    a.rotate(prices, 3);
    for (int i = 0; i < prices.size(); i++){
        cout << prices[i] <<endl;
    }
    return 0;
}
