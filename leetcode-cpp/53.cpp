#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int max_num = nums[0];
        for (int i = 1; i < nums.size(); i++){
            if (nums[i - 1] > 0)
                nums[i] = nums[i - 1] + nums[i];
            max_num = nums[i] > max_num ? nums[i] : max_num;
        }
        return max_num;
    }
};

int main(){
    vector<int> nums({-2,1});
    Solution a;
    cout << a.maxSubArray(nums) <<endl;
    return 0;
}
