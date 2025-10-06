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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*>q;

        q.push(root->left);
        q.push(root->right);

        while(!q.empty()){
            TreeNode* a = q.front(); q.pop();
            TreeNode* b = q.front(); q.pop();

            //agar null hai toh koi dikkat nahi aage badh jao
            if(!a && !b) continue;
            // agar ek null hai ot ek non-null toh symmmerty nahi hai
            if(!a || !b) return false;

            if(a->val != b->val) return false;

            //outside
            q.push(a->left);
            q.push(b->right);
            //inside
            q.push(a->right);
            q.push(b->left);
        }
        return true;
    }
};