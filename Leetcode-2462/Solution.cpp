// Clarity Questions:
// What is the limit of candidates?
// What is the limit of k and the number of elements in costs?

class Compare {
public:
    bool operator()(pair<int, int> b, pair<int, int> a) {
        // a is the element that stays on top of b
        // if a does not satisfy the given conditions then a and b will be swapped so that b comes on top of a
        return a.first < b.first or (a.first == b.first and a.second < b.second);
    }
};

// To just give you an overview of how this solution is working - I will make a priority queue that stores all the eligible people to be hired
// Then we keep on extracting elements from this priority queue, keep hiring people and consequentially adding up to the final Hiring Cost.

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        // 'minElement' is a priority queue of pairs where first element is the cost of hiring a worker and second element is the index of that cost
        // This priority queue is defined in such a way that the top element is minimum of all the contained elements with smallest index possible
        // I ensured this via the custom comparator class defined above, you can take a look at it. 
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minElement;
        int n = costs.size();
        
        // first we engulf first and last candidates number of elements into the priority queue
        int i = 0, j = n - 1;
        while(i <= j and i < candidates) {
            minElement.push( {costs[i], i} );
            i++ ;
            if(i > j) {
                break;
            }

            minElement.push( {costs[j], j} );
            j-- ;
        }

        // Now after that we will run k operations to hire k number of workers 
        // And as we remove a worker from the queue we check from which part of the array was this worker taken 
        // And then consequentially add a new worker to the queue (if any more eligible workers are left to be considered) from the first part if the previously hired person was from the first part and vica verca
        long long hiringCost = 0;
        int hiredWorkers = 0;
        while(hiredWorkers < k) {
            pair<int, int> currentHire = minElement.top();
            minElement.pop();
            
            hiringCost += currentHire.first;
            hiredWorkers++ ;

            if( i <= j ) {
                if(currentHire.second < i) {
                    minElement.push({costs[i], i});
                    i++ ;
                }
                else {
                    minElement.push({costs[j], j});
                    j-- ;
                }
            }
        }
        return hiringCost;
    }
};

// Space Complexity -> O(candidates)
// Time Complexity -> O(( k + candidates ) * log(candidates))

// Wrong Answer (after 30 minutes)
// Runtime Error (after 25 minutes)
// TLE (after 1 minute)   fixed by removing cout
// TLE (after another 1 minute)   fixed by replacing vector with pair
// Accepted (after another 5 minutes)