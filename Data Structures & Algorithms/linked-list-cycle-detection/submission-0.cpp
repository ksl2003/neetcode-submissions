/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL || head->next==head){
            return head->next;
        }

        ListNode* slow = head->next;
        ListNode* fast = head->next->next;

        while(slow && fast && (slow!=fast)){
            slow = slow->next;
            if(fast->next)
            fast = fast->next->next;
            else
            fast = NULL;
        }
        
        if(slow && fast && slow==fast){
            return true;
        }
        return false;
    }
};
