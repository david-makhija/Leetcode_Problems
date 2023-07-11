// Clarity Questions:
// What's the limit on slots1.length ?
// What's the limit on slots2.length ?
// Are both the slots arrays sorted ?

// Intuition:
// We will iterate through both the arrays simultaneously with 1 iterator for each array
// We have to look for slots in both the arrays such that they are overlapping with each other and if we find a pair of slots that are overlapping then
// We will compare the end times of both the slots then compare the least end time such that if end1 - st1 < duration or end1 - st2 < duration then we increment iterator1
// As soon as we find slots {st1, end1}, {st2, end2} such that end1 < end2 and end1 - st1 >= duration and end1 - st2 >= duration then we will return the interval{max(st1, st2), max(st1, st2) + duration}

class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        int n1 = slots1.size(), n2 = slots2.size();
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());

        int i = 0, j = 0;
        while(i < n1 and j < n2) {
            if(slots1[i][1] < slots2[j][0]) {
                i ++;
            }
            else if(slots2[j][1] < slots1[i][0]) {
                j ++;
            }
            else if(slots1[i][1] < slots2[j][1]) {
                if(slots1[i][1] - slots1[i][0] < duration || slots1[i][1] - slots2[j][0] < duration) {
                    i ++;
                }
                else {
                    return {max(slots1[i][0], slots2[j][0]), max(slots1[i][0], slots2[j][0]) + duration};
                }
            }
            else {
                if(slots2[j][1] - slots2[j][0] < duration || slots2[j][1] - slots1[i][0] < duration) {
                    j ++;
                }
                else {
                    return {max(slots1[i][0], slots2[j][0]), max(slots1[i][0], slots2[j][0]) + duration};
                }
            }
        }
        
        return {};
    }
};

// Accepted after 30 minutes into the question in the very first try :)

// Time Complexity => O((slots1.length * log(slots1.length)) + (slots2.length * log(slots2.length)))
// Space Complexity => O(1)