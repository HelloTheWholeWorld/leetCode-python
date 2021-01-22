#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
class Solution {
public:
    int ret = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return ret;
    }
    int depth(TreeNode* root) {
        if (!root) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        ret = max(ret, left + right);
        return left > right ? left + 1: right + 1;
    }
};