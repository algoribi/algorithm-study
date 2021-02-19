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
    int level = 0, ans = 0;
    void dfs(TreeNode* root, int counter) {
        if (root == NULL)
            return;
        else if (level < counter) {
            level = counter;
            ans = root->val;
        }

        dfs(root->left, counter + 1);
        dfs(root->right, counter + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 1);
        return ans;
    }
};