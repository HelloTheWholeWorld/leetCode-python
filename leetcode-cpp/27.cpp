#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != val)
                nums[idx++] = nums[i];
        return idx;
    }
};

int main(){
    vector<int> nums({3,2,2,3});
    int val = 3;
    Solution a;
    cout << a.removeElement(nums, val) << endl;
    for (int i = 0; i <nums.size(); i++)
        cout << nums[i] << endl;
    return 0;
}
