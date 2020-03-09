#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int m = l + (r - l) / 2;
        while(l <= r) {
            if (nums[m] == target){
                return m;
            }
            if (nums[l] <= nums[m]) {
                // 左侧有序
                if (nums[l] <= target && nums[m] >= target)
                    r = m - 1;
                else
                    l = m + 1;
            } else {
                // 右侧有序
                if (nums[m] <= target && nums[r] >= target)
                    l = m + 1;
                else
                    r = m - 1;
            }
            m = l + (r - l) / 2;
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> nums({4,5,6,7,0,1,2});
    int target = 3;
    int ret = s.search(nums, target);
    cout << ret << endl;
}
