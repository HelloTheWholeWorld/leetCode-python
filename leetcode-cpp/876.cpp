#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (!head) return NULL;
        int len = 1;
        ListNode *t = head;
        while (t->next){
            t = t->next;
            len++;
        }
        len /= 2;
        t = head;
        while (len){
            t = t->next;
            len--;
        }
        return t;
    }
};

int main(){
    Solution s;
    ListNode* a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(4);
   a->next->next->next->next = new ListNode(5);

    ListNode* ret = s.middleNode(a);
    while(ret){
        cout << ret->val << endl;
        ret = ret->next;
    }
    return 0;
}
