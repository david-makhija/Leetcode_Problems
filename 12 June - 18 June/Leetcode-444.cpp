class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        next = NULL;
    }
}
bool comp(vector<int> a, vector<int> b) {
    return a.size()<=b.size();
}
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<Node*> nodes(n+1, NULL);
        sort(sequences.begin(), sequences.end(), comp);
        int m = sequences.size();
        for(int i=0; i<m; i++) {
            int l = sequences[i].size();
            for(int j=0; j<l; j++) {
                
            }
        }
    }
};