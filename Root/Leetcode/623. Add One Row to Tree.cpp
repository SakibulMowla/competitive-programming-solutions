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
    void solve(TreeNode* root, TreeNode* prev, int v, int d, int l) {
        if (d == 1) {
            TreeNode* now = new TreeNode(v);
            if (l == 1) {
                prev->left = now;
                now->left = root;
            } else {
                prev->right = now;
                now->right = root;
            }
        } else {
            if (root == NULL) return;
            solve(root->left, root, v, d - 1, 1);
            solve(root->right, root, v, d - 1, 2);
        }
        return;
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* now = new TreeNode(v);
            now->left = root;
            root = now;
        } else {
            solve(root, root, v, d, 0);
        }
        return root;
    }
};