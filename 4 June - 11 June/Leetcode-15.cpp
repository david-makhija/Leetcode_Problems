class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size(), prev=INT_MAX, prevlo=INT_MAX, prevhi=INT_MIN;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            if(nums[i]==prev) continue;
            if(nums[i]>0) break;
            int lo=i+1, hi=n-1;
            while(lo<hi) {
                if((long long)(nums[lo]+nums[hi]+nums[i])==0) {
                    ans.push_back({nums[i], nums[lo], nums[hi]});
                    prevlo = nums[lo], prevhi = nums[hi];
                    lo++, hi--;
                }
                else if((long long)(nums[lo]+nums[hi]+nums[i])<0) {
                    prevlo = nums[lo];
                    lo++;
                }
                else if((long long)(nums[lo]+nums[hi]+nums[i])>0) {
                    prevhi = nums[hi];
                    hi--;
                }
                while(lo<hi and nums[lo]==prevlo) lo++;
                while(lo<hi and nums[hi]==prevhi) hi--;
            }
            prev = nums[i];
        }
        return ans;
    }
};