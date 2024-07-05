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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev= head;
        ListNode* curr=head->next;
        int firstCP=0;
        int lastCP=0;
        int index=1;

        vector<int>ans(2,INT_MAX);

        while(curr->next)
        {
            bool isCritical=curr->val < min(prev->val,curr->next->val) || curr->val > max(prev->val,curr->next->val);

            if(isCritical)
            {
                if(lastCP==0)
                {
                    firstCP=index;
                }
                else
                {
                    ans[0]=min(ans[0],index-lastCP);
                    ans[1]=index-firstCP;
                }
                lastCP=index;
            }
            index++;
            prev=curr;
            curr=curr->next;
        }
        if(firstCP == lastCP)
        {
            return {-1,-1};
        }
        return ans;
    }
};