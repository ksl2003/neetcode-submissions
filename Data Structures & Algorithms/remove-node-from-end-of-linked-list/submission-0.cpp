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
private:
    int findN(ListNode* head) {
        ListNode* presHead = head;
        int n = 0;
        while (presHead != NULL) {
            presHead = presHead->next;
            n++;
        }
        return n;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int totalN = findN(head);
        if(totalN==0 || totalN==1){
            if(n==0){
                return head;
            }
            return NULL;
        }
        int getRemove = totalN-n;
        if(getRemove==0){
            head = head->next;
            return head;
        }
        ListNode* prev = NULL;
        ListNode* pres = head;
        while(getRemove){
            prev = pres;
            pres = pres->next;
            getRemove--;
        }
        prev->next = pres->next;
        pres->next = NULL;
        return head;
    }
};
