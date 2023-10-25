/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL)
        return {};

        vector<int>ans;
        queue<TreeNode*>queue;
        queue.push(root);

        while(!queue.empty())
        {
            int curr_lvl=queue.size();
            int maxVal=INT_MIN;

            for(int i=0;i<curr_lvl;i++)
            {
                TreeNode* node=queue.front();
                queue.pop();
                maxVal=max(maxVal,node->val);

                if(node->left)
                queue.push(node->left);

                if(node->right)
                queue.push(node->right);
            }
            ans.push_back(maxVal);
        }
        return ans;
    }
};