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
    struct comp {
        bool operator()(pair<ListNode*, int> a, pair<ListNode*, int> b) {
            return a.first->val > b.first->val;
        }
    };

   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<ListNode*, int>, vector<pair<ListNode*, int>>, comp> minHeap;

        int n = lists.size();
        for (int i = 0; i < n; i++) {
            if (lists[i]) {
                auto presNode = lists[i];
                lists[i] = lists[i]->next;

                minHeap.push({presNode, i});
            }
        }
        ListNode* ansStart = new ListNode(-1);
        ListNode* ansEnd = ansStart;

        while (!minHeap.empty()) {
            auto presNode = minHeap.top();
            minHeap.pop();

            auto presListNode = presNode.first;
            int index = presNode.second;

            ansEnd->next = presListNode;
            ansEnd = ansEnd->next;

            if (lists[index]) {
                auto temp = lists[index];
                lists[index] = lists[index]->next;
                minHeap.push({temp, index});
            }
        }
        return ansStart->next;
    }
};
