// Intuition:
// Suppose you are given some projects with given number of milestones, the most efficient way of distributing 
// these among my work schedule would be to first lie down the milestones of the project having the highest number of milestones 
// Now to not let these milestones be distributed in a consecutive fashion
// We would like to fill the spaces among these consecutive milestones
// To do this we would fill these spaces with milestones of other projects
// When all these spaces have been filled we will fill the spaces in the newly formed schedule to make room for the milestones of new projects and this cycle will continue and we will be able to allocate weeks to every milestone of every project
// Now there is a corner case i.e. when the project have most number of milestones has projects more than half of the total number of projects
// In that case it might not be possible to fill the spaces between the consecutive milestones of the biggest project and that is what we have taken care of
// When that corner case comes up we will simply lie down all the rest of the milestones consecutivly one after another
// After this we have a total of rest + 1 spaces that we can fill, so that no 2 milestones project are on consecutive weeks 

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long maxElement = 0, totalSum = 0;
        for(int milestone : milestones) {
            maxElement = (milestone > maxElement) ? milestone : maxElement;
            totalSum += milestone;
        }
        long long rest = totalSum - maxElement;
        return ((2 * rest) + 1 > totalSum) ? totalSum : (2 * rest) + 1;
    }
};