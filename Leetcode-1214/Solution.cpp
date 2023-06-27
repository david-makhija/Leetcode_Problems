// Clarity Questions :
// Can this tree have negative values?
// What's the maximum number of nodes a tree can have?

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

// Put simply my solution is just iterating through the first tree with root1
// While on a node, it checks if a node with value node->val - target exists in the second tree if yes it true
// Else we look further deep into the first tree if this is true for any other nodes
// as soon  as we reach null pointers we return false
class Solution {
    
    bool findNode(TreeNode* root, int target) {
        if(root == NULL) {
            return false;
        }
        if(root->val == target) {
            return true;
        }
        return findNode(root->left, target) or findNode(root->right, target);
    }
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if(root1 == NULL) {
            return false;
        }
        if(findNode(root2, target - root1->val)) {
            return true;
        }

        return twoSumBSTs(root1->left, root2, target) or twoSumBSTs(root1->right, root2, target);
    }
};

// Space Complexity => O(height of the tree) (stack memory)
// Time Complexity => O((number of nodes in root1) * (number of nodes in root2))

// Solved within 12 minutes