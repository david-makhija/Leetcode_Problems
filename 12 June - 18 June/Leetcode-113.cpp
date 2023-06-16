class Solution {
    void checkForTarget(TreeNode* node, vector<int>& temp, vector<vector<int>>& ans, int remSum) {
        if(remSum<node->val) return;
        temp.push_back(node->val);
        if(remSum==node->val) {
            if(node->right==NULL and node->left==NULL) ans.push_back(temp);
            temp.pop_back();
            return;
        }
        if(node->left!=NULL) checkForTarget(node->left, temp, ans, remSum-(node->val));
        if(node->right!=NULL) checkForTarget(node->right, temp, ans, remSum-(node->val));
        temp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        vector<int> temp;
        checkForTarget(root, temp, ans, targetSum);
        return ans;
    }
};