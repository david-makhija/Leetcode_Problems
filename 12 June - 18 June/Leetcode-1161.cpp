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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int maxRowSum = INT_MIN;
        int rowSum = 0, row = 1, ans=1;
        while(!q.empty()) {
            if(q.front()==NULL) {
                q.pop();
                if(rowSum>maxRowSum) {
                    maxRowSum = rowSum;
                    ans = row;
                }
                rowSum = 0;
                row++;
                if(q.empty()) break;
                q.push(NULL);
            }
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
            rowSum += temp->val;
        }
        return ans;
    }
};