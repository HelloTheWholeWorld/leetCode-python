#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_diff = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());

        for (int base = 0; base < nums.size() - 2; base++){
            if (base > 0 && nums[base] == nums[base-1])
                continue;
            int i = base + 1, j = nums.size() - 1, temp;
            while (i < j) {
                temp = nums[base] + nums[i] + nums[j];
                bool l = false, r = false;
                if (abs(min_diff - target) > abs(temp - target))
                    min_diff = temp;
                if (temp == target){
                    return temp;
                } else if (temp < target) {
                    l = true;
                } else{
                    r = true;
                }
                if (l) {
                    i++;
                    while(i < j && nums[i] == nums[i-1]) i++;
                }
                if (r) {
                    j--;
                    while(i < j && nums[j] == nums[j+1]) j--;
                }
            }
        }
        return min_diff;
    }
};

int main(){
    Solution s;
    vector<int> temp({0, 2, 1, -3});
    int target = 1;
    cout << s.threeSumClosest(temp, target) << endl;
//    vector<vector<int>> ret = s.threeSum(temp);
//    for (int i = 0; i < ret.size(); i++){
//        for (int j = 0; j < ret[i].size(); j++){
//            cout << ret[i][j] << "\t";
//        }
//        cout <<endl;
//    }
    return 0;
}
