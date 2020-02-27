#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int ,int> hashmap;
        for (int i = 0; i < nums.size(); i++){
            if (hashmap.find(target - nums[i]) != hashmap.end())
                return vector<int>{i, hashmap[target - nums[i]]};
            hashmap[nums[i]] = i;
        }
        return vector<int>{};
    }
};

int main(){
    Solution a;
    vector<int> nums {2, 7, 11, 15};
    int target = 9;
    vector<int> ret = a.twoSum(nums, target);
    for (int i = 0; i < ret.size(); i++)
        cout<< ret[i] << endl;
    return 0;
}
