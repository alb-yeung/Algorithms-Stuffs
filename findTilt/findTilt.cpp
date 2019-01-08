/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /* basic recursion runs in 24ms */
    int findTilt(TreeNode* root) {
        if (root == 0)
            return 0;
        int tilt = 0;
        int left = 0;
        int right = 0;
        if (root->left){
            left = findSum(root->left);
        }
        if (root->right){
            right = findSum(root->right);
        }
        tilt += abs(left-right);
        tilt += findTilt(root->left) + findTilt(root->right);
        return tilt;
    }
    
    int findSum(TreeNode* root){
        if (root == 0)
            return 0;
        return root->val + findSum(root->left) + findSum(root->right);
    }
};
