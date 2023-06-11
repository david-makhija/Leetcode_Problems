class Solution {
    int Search(int value, vector<int>& nums, int idx, int n) {
        int st = idx;
        int en = n;
        while(st<en) {
            int mid = st + ((en-st)/2);
            if(nums[mid]==value) return mid;
            if(nums[mid]<value) st = mid+1;
            else en = mid;
        }
        return -1;
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i=0; i<n-1; i++) {
            int j = Search(target-numbers[i], numbers, i+1, n);
            if(j!=-1) return {i+1, j+1};
        }
        return {-1, -1};
    }
};