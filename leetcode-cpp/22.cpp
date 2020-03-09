#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if (n == 0) return ret;
        help_method(ret, "", n , n);
        return ret;
    }

    void help_method(vector<string>& ret, string temp, int m, int n){
        if (m == 0 && n == 0){
            ret.push_back(temp);
            return ;
        }
        if (m > 0) {
            help_method(ret, temp + '(', m - 1, n);
        }
        if (n - 1 >= m) {
            help_method(ret, temp + ')', m ,n - 1);
        }
    }
};


int main(){
    Solution s;
    vector<string> ret = s.generateParenthesis(3);
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
//
//    ListNode* ret = s.removeNthFromEnd(a, 1);
//    while(ret){
//        cout << ret->val << endl;
//        ret = ret->next;
//    }
    return 0;
}
