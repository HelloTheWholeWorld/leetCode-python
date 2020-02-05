class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        borrow = 0
        temp = ListNode(-1)
        result = temp
        while l1 != None or l2 != None or borrow == 1:
            temp.next = ListNode(0)
            temp = temp.next
            val1 = 0 if l1 == None else l1.val
            val2 = 0 if l2 == None else l2.val
            sum_ = val1 + val2 + borrow
            borrow = 0 if sum_ < 10 else 1
            sum_ = sum_ % 10
            temp.val = sum_
            l1 = l1.next if l1 != None else None
            l2 = l2.next if l2 != None else None
        return result.next

def main():
    a = ListNode(2)
    tempa = a
    tempa.next = ListNode(4)
    tempa = tempa.next
    tempa.next = ListNode(3)

    b = ListNode(5)
    tempb = b
    tempb.next = ListNode(6)
    tempb = tempb.next
    tempb.next = ListNode(4)

    res = Solution()
    ret = res.addTwoNumbers(a, b)
    while ret != None:
        print(ret.val)
        ret = ret.next


if __name__ == '__main__':
    main()