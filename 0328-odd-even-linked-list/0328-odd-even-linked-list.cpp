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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return NULL;
        int order = 1;
        int lnt = 1;
        ListNode* temp = head;
        while(temp->next != NULL) {
            lnt++;
            temp = temp->next;
        }
        if(lnt <= 2) return head;
        ListNode* last = temp;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int cnt = lnt/2;
        while(cnt--) {
            prev->next = curr->next;
                prev = curr->next;
                curr->next = NULL;
                temp->next = curr;
                temp = curr;
                curr=prev->next;
        }

        return head;
    }
};