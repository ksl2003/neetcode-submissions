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
    void findMid(ListNode* head, ListNode*& presMid) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        presMid = slow;
    }

    void makeRev(ListNode* head, ListNode*& presLast) {
        ListNode* prevNode = NULL;
        ListNode* presNode = NULL;
        ListNode* nextNode = NULL;
        presNode = head;
        nextNode = head->next;

        while (presNode != NULL) {
            presNode->next = prevNode;
            prevNode = presNode;
            presNode = nextNode;
            if (nextNode) nextNode = nextNode->next;
        }
        presLast = prevNode;
    }

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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return;
        }
        ListNode* presMid = NULL;
        findMid(head, presMid);

        int n = findN(head);

        ListNode* presLast = NULL;
        makeRev(presMid, presLast);

        ListNode* start1 = head;
        ListNode* start2 = presLast;
        ListNode* ansNode = new ListNode(-1);
        ListNode* ansNodeEnd = ansNode;
        bool isStarting = true;
        while (start1 && start2 && (start1->next != start2 || start1 != start2->next)) {
            if(start1==start2){
                ListNode* tempNode = start1;
                start1 = NULL;
                start2 = NULL;
                tempNode->next = NULL;
                ansNodeEnd->next = tempNode;
                break;
            }
            if(isStarting){
                ListNode* tempNode = start1;
                start1 = start1->next;
                tempNode->next = NULL;
                ansNodeEnd->next = tempNode;
                ansNodeEnd = ansNodeEnd->next;
            }
            else{
                ListNode* tempNode = start2;
                start2 = start2->next;
                tempNode->next = NULL;
                ansNodeEnd->next = tempNode;
                ansNodeEnd = ansNodeEnd->next;
            }
            isStarting = !isStarting;
        }

        ansNode = ansNode->next;
        head = ansNode;
    }
};
