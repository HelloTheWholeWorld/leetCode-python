#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, l1_val, l2_val, sum;
        ListNode* start = new ListNode(-1);
        ListNode* temp = start;
        while (l1 != NULL || l2 != NULL) {
            l1_val = l1 == NULL ? 0 : l1->val;
            l2_val = l2 == NULL ? 0 : l2->val;;
            sum = l1_val + l2_val + carry;
            carry = sum / 10;
            sum %= 10;
            temp->next = new ListNode(sum);
            temp = temp->next;
            l1 = l1 == NULL ? NULL : l1->next;
            l2 = l2 == NULL ? NULL : l2->next;
            if (carry == 1 && l1 == NULL && l2 == NULL) {
                temp->next = new ListNode(1);
                carry = 0;
            }
        }
        return start->next;
    }
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        ListNode* temp = new ListNode(-1);
//        temp->next = this->help_method(l1, l2, 0);
//        return temp->next;
//    }
//
//    ListNode* help_method(ListNode* l1, ListNode* l2, int add_num) {
//        if (l1 == NULL && l2 == NULL) {
//            if (add_num == 0) return NULL;
//            else return new ListNode(add_num);
//        }
//        if (l1 == NULL) {
//            int add = l2->val + add_num;
//            ListNode* temp = new ListNode(add % 10);
//            temp->next = this->help_method(NULL, l2->next, add / 10);
//            return temp;
//        }
//        else if (l2 == NULL) {
//            int add = l1->val + add_num;
//            ListNode* temp = new ListNode(add % 10);
//            temp->next = this->help_method(l1->next, NULL, add / 10);
//            return temp;
//        }
//        else{
//            int add = l1->val + l2->val + add_num;
//            ListNode* temp = new ListNode(add % 10);
//            temp->next = this->help_method(l1->next, l2->next, add / 10);
//            return temp;
//        }
//    }
};

int main(){
    Solution s;
    ListNode* a = new ListNode(5);
//    a->next =  new ListNode(4);
//    a->next->next = new ListNode(3);

    ListNode* b = new ListNode(5);
//    b->next = new ListNode(6);
//    b->next->next = new ListNode(4);

    ListNode *ret = s.addTwoNumbers(a, b);
    while (ret != NULL) {
        cout << ret->val <<endl;
        ret = ret->next;
    }
    return 0;
}
