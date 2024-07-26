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

    bool search(TreeNode* root,long int minval,long int maxval)
    {
        if(root==NULL) return true;

        if(root->val > minval && root->val < maxval)
        {
            bool leftans=search(root->left,minval,root->val);
            bool rightans=search(root->right,root->val,maxval);
            return leftans && rightans;
        }

        return false;
    }

    bool isValidBST(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        if(root->left==NULL && root->right==NULL)
        {
            return true;
        }

        return search(root,LONG_MIN,LONG_MAX);
    }
};