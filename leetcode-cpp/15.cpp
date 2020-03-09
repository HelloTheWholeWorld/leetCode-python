#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() <= 2)
            return vector<vector<int>>();
        // 定一议二，确定最小值
        sort(nums.begin(), nums.end());

//        for (int i= 0; i < nums.size(); i++) {
//            cout << nums[i] << "\t";
//        }
//        cout <<endl;

        int base = 0, i, j, temp;
        vector<vector<int>> ret;
        for (int base = 0; base < nums.size() - 2; base++) {
            if (nums[base] >0 || ( base > 0 && nums[base] == nums[base-1]))
                continue;
            i = base + 1, j = nums.size() - 1;
            while (i < j){
                bool l = false, r = false;
                temp = nums[base] + nums[i] + nums[j];
                if (temp == 0) {
                    ret.push_back(vector<int>({nums[base], nums[i], nums[j]}));
                    l = true;
                    r = true;
                } else if (temp < 0){
                    l = true;
                } else {
                    r = true;
                }
                if (l) {
                    i++;
                    while (i < j && nums[i] == nums[i-1])
                        i++;
                }
                if (r) {
                    j--;
                    while (i < j && nums[j] == nums[j+1])
                        j--;
                }
            }
        }
        return ret;
    }
};
int main(){
    Solution s;
    vector<int> temp({1, -1, -1, 0});
    vector<vector<int>> ret = s.threeSum(temp);
    for (int i = 0; i < ret.size(); i++){
        for (int j = 0; j < ret[i].size(); j++){
            cout << ret[i][j] << "\t";
        }
        cout <<endl;
    }
    return 0;
}
