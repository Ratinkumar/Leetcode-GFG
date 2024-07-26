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

    void inorder(TreeNode* root,int k,int &counter,int &ksmallest)
    {
        if(root==NULL || counter >= k)
        {
            return;
        }
        //treverse to left
        inorder(root->left,k,counter,ksmallest);
        //increment counter after visiting left subtree
        counter++;
        //check if current node is kth smallest
        if(counter==k)
        {
            ksmallest=root->val;
            return;
        }
        //treverse to right
        inorder(root->right,k,counter,ksmallest);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ksmallest=INT_MAX;
        int counter=0;//counter to track visited nodes
        
        inorder(root,k,counter,ksmallest);

        return ksmallest;
    }
};