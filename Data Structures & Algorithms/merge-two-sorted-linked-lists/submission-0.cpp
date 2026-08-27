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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* presNode1 = list1;
        ListNode* presNode2 = list2;
        ListNode* ans = new ListNode(1);
        ListNode* startNode = ans;
        while(presNode1 && presNode2){
            if(presNode1->val < presNode2->val){
                ListNode* temp = presNode1;
                presNode1 = presNode1 -> next;
                temp->next = NULL;
                ans->next = temp;
                ans = ans->next;
            }
            else{
                ListNode* temp = presNode2;
                presNode2 = presNode2 -> next;
                temp->next = NULL;
                ans->next = temp;
                ans = ans->next;
            }
        }
        while(presNode1){
            ListNode* temp = presNode1;
            presNode1 = presNode1 -> next;
            temp->next = NULL;
            ans->next = temp;
            ans = ans->next;
        }
        while(presNode2){
            ListNode* temp = presNode2;
                presNode2 = presNode2 -> next;
                temp->next = NULL;
                ans->next = temp;
                ans = ans->next;
        }
        startNode = startNode->next;
        return startNode;
    }
};
