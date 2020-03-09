#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) return true;
        int front_ = 0;
        for (int i = 0; i < nums.size() - 1 && i <= front_; i++){
            front_ = max(front_, nums[i] + i);
        }
        return (front_ >= nums.size() - 1);
    }
};

int main(){
    Solution s;
    vector<int> temp({0, 2, 3});
    cout << s.canJump(temp) <<endl;
}
