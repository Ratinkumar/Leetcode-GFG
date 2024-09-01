/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,bool>m;

        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(m[temp]==false)
            {
                m[temp]=true;
            }
            else
            {
                //cycle present
                return true;
            }
            temp=temp->next;
        }
        //loop not present
        return false;
    }
};