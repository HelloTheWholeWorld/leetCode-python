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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        n += 1;
        while (first){
            first = first->next;
            if (n == 0)
                second = second->next;
            else
                n--;
        }
        second->next = second->next->next;
        ListNode *temp = dummy->next;
        delete(dummy);
        return temp;
    }
};
int main(){
    Solution s;
//    vector<int> A({1,2,3,0,0,0});
//    vector<int> B({2,5,6});
//    s.merge(A, 3, B, 3);
//    for (auto i : A){
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
    a->next->next->next = new ListNode(4);
    a->next->next->next->next = new ListNode(5);

    ListNode* ret = s.removeNthFromEnd(a, 1);
    while(ret){
        cout << ret->val << endl;
        ret = ret->next;
    }
    return 0;
}
