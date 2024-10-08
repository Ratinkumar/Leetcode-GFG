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
    ListNode* reverseLL(ListNode* prev,ListNode* curr)
    {
        if(curr==NULL)
        {
            return prev;
        }

        ListNode* nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;

        return reverseLL(prev,curr);
    }

    ListNode* middleNode(ListNode* head)
    {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=NULL)
        {
            fast=fast->next;
            if(fast->next!=NULL)
            {
                fast=fast->next;
                slow=slow->next;
            }
        }
        return slow;
    }

    bool compareLL(ListNode* head,ListNode* head2)
    {
        while(head2!=NULL)
        {
            if(head->val != head2->val)
            {
                return false;
            }
            else
            {
                head=head->next;
                head2=head2->next;
            }
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        //break into 2 halves
        ListNode* midNode=middleNode(head);
        ListNode* head2=midNode->next;
        midNode->next=NULL;
        //reverse second half
        ListNode* prev=NULL;
        ListNode* curr=head2;
        head2=reverseLL(prev,curr);

        //compare both linked list
        bool ans=compareLL(head,head2);
        return ans;
    }
};