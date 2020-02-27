#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0|| nums.size() == 1) return nums.size();
        int i = 1, record_idx = 0;
        while (1){
            while (i < nums.size() && nums[i] == nums[record_idx])
                i++;
            if (i == nums.size())
                return record_idx + 1;
            nums[++record_idx] = nums[i++];
        }
    }
};

int main(){
    vector<int> nums({0,0,1,1,1,2,2,3,3,4});
    Solution a;
    int ret = a.removeDuplicates(nums);
    for (int i= 0; i < nums.size(); i++)
        cout << nums[i] << endl;
    cout <<ret << endl;
    return 0;
}
