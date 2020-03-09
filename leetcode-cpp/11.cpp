#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1) return 0;
        int left = 0, right = height.size() - 1;
        int max_area = 0;
        while (left < right) {
            max_area = max(max_area, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right])
                left++;
            else right--;
        }
        return max_area;
    }
};

int main(){
    Solution s;
    vector<int> a({1,8,6,2,5,4,8,3,7});
    cout << s.maxArea(a) <<endl;
    return 0;
}
