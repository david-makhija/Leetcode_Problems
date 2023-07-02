// Clarity Questions :
// maximum length of persons?
// maximum length of times?
// max value of times[i]?

class TopVotedCandidate {
    vector<int> winners;
    vector<int> times;
    int n;
    // Intuition :
    // This is a simple binary search solution
    // Here we've made an array winners which stores the candidates that was the winners on specific times
    // winners[i] was the topvotedcandidate during the interval [times[i], times[i + 1]);
    // after we've made an array like this,
    // for a general query of t we search for the index i such that times[i] <= t < times[i + 1]
    // and the answer is winner[i], as can be deduced from the above explanation refer to line 13
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this -> times = times;
        n = persons.size();
        int winner = -1, mostVotes = 0;
        vector<int> candidates(n, 0);
        for(int i = 0; i < n; i++) {
            candidates[persons[i]] ++;
            if(mostVotes <= candidates[persons[i]]) {
                mostVotes = candidates[persons[i]];
                winner = persons[i];
            }
            winners.push_back(winner);
        }
    }
    
    int q(int t) {
        int st = 0, en = n;
        while(st < en) {
            int mid = st + ((en - st)/2);
            if(times[mid] == t) {
                return winners[mid];
            }
            if(times[mid] <= t) {
                st = mid+1;
            }
            else {
                en = mid;
            }
        }
        return winners[st - 1];
    }
};

// Accepted in 21 minutes

// TopVotedCandidate -> Time Complexity => O(times.length)
// TopVotedCandidate.q -> Time Complexity => O(log(times.length))
// Overall Space Complexity => O(times.length)