class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size()==1) return (target[0]==1) ? true : false;
        priority_queue<int> pq;
        int sum = 0;
        for(int x:target) {
            sum += x;
            pq.push(x);
        }
        while(pq.top()>1) {
            int temp = pq.top();
            pq.pop();
            int remainingSum = sum - temp;
            temp = temp - remainingSum;
            if(temp<1) return false;
            pq.push(temp);
            sum = temp + remainingSum;
        }
        return true;
    }
};