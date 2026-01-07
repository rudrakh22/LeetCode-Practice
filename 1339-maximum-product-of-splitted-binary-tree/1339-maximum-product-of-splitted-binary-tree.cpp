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
    long long totalProduct=0;
    const int MOD=1e9+7;
    long long dfs(TreeNode* root){
        if(!root) return 0;
        return root->val+dfs(root->left)+dfs(root->right);
    }
    long long dfsSub(TreeNode * root,long long total){
        if(!root) return 0;
        long long leftSum=dfsSub(root->left,total);
        long long rightSum=dfsSub(root->right,total);
        long long subSum=leftSum+rightSum+root->val;
        totalProduct=max(totalProduct,subSum*(total-subSum));
        return subSum;
    }

    int maxProduct(TreeNode* root) {
        long long total=dfs(root);
        dfsSub(root,total);
        return totalProduct%MOD;
    }
};