#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
//        for (int i = 0; i < nums.size(); i++)
//            if (nums[i] >= target)
//                return i;
//        return nums.size();
        if (nums.size() == 0) return 0;
        int left = 0, right = nums.size() - 1, mid;
        while(left <= right){
            mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};

int main(){
    Solution a;
    vector<int> test({1,3,5,6});
    int val = 7;
    cout << a.searchInsert(test, val) << endl;
    return 0;
}
