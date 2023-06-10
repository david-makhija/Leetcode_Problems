class Solution {
    long long findTheSum(int index, int value) {
        if(value<=index) {
            return ((long long)(value+1)*((long long)value)/2) + index-value;
        }
        return (((long long)value)+((long long)(value-index+1)))*((long long)index)/2;
    }
public:
    int maxValue(int n, int index, int maxSum) {
        int l = 1, r = maxSum+1;
        while(l<r) {
            int mid = l + ((r-l)/2);
            long long sum = findTheSum(index+1, mid) + findTheSum(n-index, mid) - mid;
            if(sum==maxSum) return mid;
            else if(sum<maxSum) l = mid+1;
            else r = mid;
        }
        return l-1;
    }
};