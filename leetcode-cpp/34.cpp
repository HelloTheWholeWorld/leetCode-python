#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void binary_search(vector<int>& nums, int target, int l, int r, int& l_bound, int& r_bound) {
        if (l > r) return ;
        int m = l + (r - l) / 2;
        bool l_flag = false, r_flag = false;

        if (nums[m] == target) {
            l_bound = min(l_bound, m);
            r_bound = max(r_bound, m);
            l_flag = true;
            r_flag = true;
        } else if (nums[m] < target) {
            r_flag = true;
        } else {
            l_flag = true;
        }
        if (l_flag)
            binary_search(nums, target, l, m - 1, l_bound, r_bound);
        if (r_flag)
            binary_search(nums, target, m + 1, r, l_bound, r_bound);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int l_bound = INT_MAX, r_bound = INT_MIN;
        binary_search(nums, target, l, r, l_bound, r_bound);
        if (l_bound == INT_MAX)
            return vector<int>({-1, -1});
        else
            return vector<int>({l_bound, r_bound});
    }
};


int main(){
    Solution s;
    vector<int> nums({5,7,7,8,8,10});
    int target = 6;
    vector<int> ret = s.searchRange(nums, target);
//    cout << ret << endl;
    for (auto i : ret){
        cout <<i <<endl;
    }
}
