class Solution {
    bool foundP = false, foundQ = false;
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return root;
        TreeNode* l = helper(root->left, p, q);
        TreeNode* r = helper(root->right, p, q);
        if(root==p) {
            foundP = true;
            return p;
        }
        if(root==q) {
            foundQ = true;
            return q;
        }
        if(l!=NULL and r!=NULL) return root;
        if(l==NULL and r==NULL) return NULL;
        if(l==NULL) return r;
        return l;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = helper(root, p, q);
        if(!foundP or !foundQ) return NULL;
        return lca;
    }
};