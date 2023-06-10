class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, vector<int>> um;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(um.find(nums[i])==um.end()) {
                vector<int> temp;
                temp.push_back(i);
                um[nums[i]] = temp;
            }
            else {
                um[nums[i]].push_back(i);
            }
        }
        set<vector<int>> Sample;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(um.find(-(nums[i]+nums[j]))!=um.end()) {
                    for(int x:um[-(nums[i]+nums[j])]) {
                        if(i!=x and j!=x) {
                            vector<int> temp = {nums[i], nums[j], nums[x]};
                            sort(temp.begin(), temp.end());
                            Sample.insert(temp);
                            break;
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans(Sample.begin(), Sample.end());
        return ans;
    }
};