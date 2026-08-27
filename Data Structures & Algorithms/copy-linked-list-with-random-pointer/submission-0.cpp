/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return head;
        }

        Node* ansStart = new Node(head->val);
        Node* ansEnd = ansStart;
        Node* presHead = head->next;
        map<Node*, Node*> ansToPres;
        map<Node*, Node*> presToAns;
        ansToPres[ansStart] = head;
        presToAns[head] = ansStart;
        while(presHead){
            Node* temp = new Node(presHead->val);
            ansEnd->next = temp;
            ansEnd = temp;
            ansToPres[temp] = presHead;
            presToAns[presHead] = temp;
            presHead = presHead->next;
        }

        // presHead = head;
        Node* presAnsHead = ansStart;
        while(presAnsHead){
            presAnsHead->random = presToAns[ansToPres[presAnsHead]->random];
            presAnsHead = presAnsHead->next;
        }
        return ansStart;
    }
};
