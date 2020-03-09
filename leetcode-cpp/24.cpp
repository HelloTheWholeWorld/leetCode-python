#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return head;
        ListNode* temp1 = head;
        ListNode* temp2 = head ->next;
        temp1->next = this->swapPairs(temp2->next);
        temp2->next = temp1;
        return temp2;
    }
};


int main(){
    Solution s;
//    vector<string> ret = s.generateParenthesis(3);
//    for (auto i : ret){
//        cout <<i <<endl;
//    }


//    int target = -11;
//    vector<vector<int>> ret = s.fourSum(nums, target);
//    for (int i = 0; i < ret.size(); i++){
//        for (int j = 0; j < ret[i].size(); j++){
//            cout << ret[i][j] << "\t";
//        }
//        cout <<endl;
//    }

    ListNode* a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
//    a->next->next->next = new ListNode(4);
//    a->next->next->next->next = new ListNode(5);

    ListNode* ret = s.swapPairs(a);
    while(ret){
        cout << ret->val << endl;
        ret = ret->next;
    }
    return 0;
}
