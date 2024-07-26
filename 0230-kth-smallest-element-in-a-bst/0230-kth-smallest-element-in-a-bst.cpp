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

    void inorder(TreeNode* root,int k,vector<int>&arr)
    {
        if(root==NULL) return;

        inorder(root->left,k,arr);
        arr.push_back(root->val);
        inorder(root->right,k,arr);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int>arr;
        inorder(root,k,arr);
        int temp=0;
        for(int i=0;i<arr.size();i++)
        {
            temp=arr[k-1];
        }
        return temp;
    }
};