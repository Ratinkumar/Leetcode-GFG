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

    TreeNode* maxValue(TreeNode* root)
    {
        if(root==NULL)
        {
            return NULL;
        }

        TreeNode* temp=root;
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        return temp;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
        {
            return NULL;
        }

        if(root->val==key)
        {
            //case 1 -> leaf node
            if(root->left==NULL && root->right==NULL)
            {
                delete root;
                return NULL;
            }
            //case 2 -> left non null and right null
            else if(root->left!=NULL && root->right==NULL)
            {
                TreeNode* childSubtree=root->left;
                delete root;
                return childSubtree;
            }
            //case 3 -> left null and right non null
            else if(root->left==NULL && root->right!=NULL)
            {
                TreeNode* childSubtree=root->right;
                delete root;
                return childSubtree;
            }
            //case 4 -> left non NULL and right non NULL
            else
            {
                TreeNode* maxi=maxValue(root->left);
                root->val=maxi->val;
                root->left=deleteNode(root->left,maxi->val);
                return root;
            }
        }
        else if(root->val > key)
        {
            //left mai jao
            root->left=deleteNode(root->left,key);
        }
        else
        {
            //right mai jao
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
};