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

    int findlength(ListNode* head)
    {
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        return len;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        int length=findlength(head);
        if(n==length)
        {
            ListNode* newhead=head->next;
            delete(head);
            return newhead;
        }
        int pos=(length-n)+1;
        int i=1;
        ListNode* prev=head;
        while(i<pos-1)
        {
            prev=prev->next;
            i++;
        }

        ListNode* curr=prev->next;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

        return head;
    }
};