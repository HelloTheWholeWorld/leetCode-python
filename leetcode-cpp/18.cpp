#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return vector<vector<int>>();
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for (int base_one = 0; base_one < nums.size()-3; base_one++){
            if(base_one > 0 && nums[base_one] == nums[base_one-1])
                continue;
            for (int base_two = base_one + 1; base_two < nums.size()-2; base_two++){
                if (base_two > base_one + 1 && nums[base_two] == nums[base_two-1])
                    continue;
                int min_sum = nums[base_one] + nums[base_two] + nums[base_two+1] + nums[base_two+2];

                // 这一部分的计算非常节约时间
                if (target < min_sum)
                    continue;
                int max_sum = nums[base_one] + nums[base_two] + nums[nums.size()-1] + nums[nums.size()-2];
                if (target > max_sum)
                    continue;


                int i = base_two + 1, j = nums.size() - 1, temp;
                while(i < j) {
                    temp = nums[base_one] + nums[base_two] + nums[i] + nums[j];
                    bool l = false, r = false;
                    if (temp == target){
                        ret.push_back(vector<int>({nums[base_one], nums[base_two], nums[i], nums[j]}));
                        l = true;
                        r = true;
                    }else if(temp < target){
                        l = true;
                    }else{
                        r = true;
                    }
                    if (l) {
                        i++;
                        while(i < j && nums[i] == nums[i-1]) i++;
                    }
                    if (r){
                        j--;
                        while(i < j && nums[j] == nums[j+1]) j--;
                    }
                }
            }
        }
        return ret;
    }
};

int main(){
    Solution s;
    vector<int> nums({1,-2,-5,-4,-3,3,3,5});
    int target = -11;
    vector<vector<int>> ret = s.fourSum(nums, target);
    for (int i = 0; i < ret.size(); i++){
        for (int j = 0; j < ret[i].size(); j++){
            cout << ret[i][j] << "\t";
        }
        cout <<endl;
    }
    return 0;
}
