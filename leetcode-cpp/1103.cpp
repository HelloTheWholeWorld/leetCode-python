#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ret(num_people, 0);
        int base = 1, idx = 0;
        while (candies){
            if (candies - base >= 0) {
                candies -= base;
                ret[idx] += base++;
                if (idx == num_people - 1) idx = 0;
                else idx++;
            } else {
                ret[idx] += candies;
                break;
            }
        }
        return ret;
    }
};

int main(){
    Solution s;
    vector<int> ret = s.distributeCandies(10, 3);
    for (auto i : ret){
        cout <<i <<endl;
    }


//    int target = -11;
//    vector<vector<int>> ret = s.fourSum(nums, target);
//    for (int i = 0; i < ret.size(); i++){
//        for (int j = 0; j < ret[i].size(); j++){
//            cout << ret[i][j] << "\t";
//        }
//        cout <<endl;
//    }

//    ListNode* a = new ListNode(1);
//    a->next = new ListNode(2);
//    a->next->next = new ListNode(3);
//    a->next->next->next = new ListNode(4);
//    a->next->next->next->next = new ListNode(5);

//    ListNode* ret = s.swapPairs(a);
//    while(ret){
//        cout << ret->val << endl;
//        ret = ret->next;
//    }
//    return 0;
}
