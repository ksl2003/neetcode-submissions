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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return head;
        }

        ListNode* prevNode = NULL;
        ListNode* presNode = NULL; 
        ListNode* nextNode = NULL;
        presNode = head;
        nextNode = head->next;

        while(presNode!=NULL){
            presNode->next = prevNode;
            

            prevNode = presNode;
            presNode = nextNode;
            if(nextNode)
            nextNode = nextNode->next;
        }
        return prevNode;
    }
};
