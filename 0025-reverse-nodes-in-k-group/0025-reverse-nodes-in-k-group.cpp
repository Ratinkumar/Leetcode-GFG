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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)
        {
            return head;
        }

        if(head->next==NULL)
        {
            return head;
        }

        ListNode* check=head;
        for(int i=0;i<k;i++)
        {
            if(!check) return head;
            check=check->next;
        }
        
        ListNode* prev=NULL;
        ListNode* curr=head;
        int pos=0;
        ListNode* nextNode=NULL;
        while(curr!=NULL && pos<k)
        {
            pos++;
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }

        
        if(nextNode!=NULL)
        {
            head->next=reverseKGroup(nextNode,k);
        }

        return prev;
    }
};