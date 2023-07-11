// Clarity Questions:
// What's the limit on time.size()?
// What's the limit on time[i]?

// Intuition:
// The first approach that comes into my mind is to keep try making pairs and record the ones that have a total duration divisible by 60
// But watching the limits on time.size() I do not think that it is possible to implement this O(n^2) approach
// To optimize this - I think binary search would be the perfect fit
// To implement that we will make a vector of pairs 'durationMod60' such that durationMod60[j] = {time[i] % 60, i}
// We will iterate through the whole array time and in each iteration we will search for a pair in this vector such that durationMod60[j][0] = 60 - (time[i] % 60) we will make the pairs
// And we will try to pair only those pairs that have not been considered yet

// Approach:
// Half of how the solution is implemented is already stated in the Intuition 
// Let me tell you the other half i.e. avoiding duplicates and efficiently find the number of pairs
// There are a total of 2 functions that use binary search to find 2 important indices
// The first index is stIdx, it is filled via the function 'searchMatchingFirstTime'. It is defined in such a way that duplicateMod60[stIdx].first == 60 - (time[i] % 60) and duplicate[stIdx].second > i, if such index does not exist then it returns a value as if it is the smallest value of stIdx such that duplicate[stIdx].first > 60 - (time[i] % 60)
// The second index is enIdx, it is filled via the function 'searchMatchingLastTime'. It is defined in such a way as if it is the smallest value of stIdx such that duplicate[stIdx].first > 60 - (time[i] % 60)
// The range from stIdx to enIdx is the range that contains the songs that can be paired with this song
// Thus we add enIdx - stIdx to the answer

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first == b.first ? a.second < b.second : a.first < b.first;
}

int searchMatchingLastTime(vector<pair<int, int>>& durationMod60, int target, int n) {
    int st = 0, en = n;
    while(st < en) {
        int mid = st + ((en - st) / 2);
        if(durationMod60[mid].first <= target) {
            st = mid + 1;
        }
        else {
            en = mid;
        }
    }
    return st;
}

int searchMatchingFirstTime(vector<pair<int, int>>& durationMod60, int target, int n, int idx) {
    int st = 0, en = n;
    while(st < en) {
        int mid = st + ((en - st) / 2);
        if(durationMod60[mid].first == target) {
            if(durationMod60[mid].second <= idx) {
                st = mid;
                st += ((en - st) % 2);
            }
            else {
                en = mid;
            }
        }
        else if(durationMod60[mid].first < target) {
            st = mid;
            st += ((en - st) % 2);
        }
        else {
            en = mid;
        }
    }
    return en;
}

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        vector<pair<int, int>> durationMod60;

        for(int i = 0; i < n; i++) {
            durationMod60.push_back({time[i] % 60, i});
        }

        sort(durationMod60.begin(), durationMod60.end(), comp);
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            int stIdx = searchMatchingFirstTime(durationMod60, (60 - (time[i] % 60)) % 60, n, i);
            int enIdx = searchMatchingLastTime(durationMod60, (60 - (time[i] % 60)) % 60, n);
            
            ans += (enIdx - stIdx);
        }
        
        return ans;
    }
};

// Accepted after 4 tries and approx 1 and a half hour :)

// Time Complexity => O(time.length * log(time.length))
// Space Complexity => O(time.length)