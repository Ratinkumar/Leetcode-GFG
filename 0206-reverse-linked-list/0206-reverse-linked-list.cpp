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
    ListNode* ByRecursion(ListNode* prev,ListNode* curr)
    {
        if(curr==NULL)
        {
            return prev;
        }

        ListNode* nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;

        ListNode* ans=ByRecursion(prev,curr);

        return ans;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        
        return ByRecursion(prev,curr);
    }
};