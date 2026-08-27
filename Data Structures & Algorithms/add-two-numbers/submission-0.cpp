class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* ansEnd = dummy;

        int carry = 0;

        while(l1 || l2 || carry) {
            int sum = carry;

            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            ansEnd->next = new ListNode(sum % 10);
            ansEnd = ansEnd->next;

            carry = sum / 10;
        }

        return dummy->next;
    }
};