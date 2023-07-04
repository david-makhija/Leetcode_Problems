// Clarity Questions :
// Limit on the length of the string expression?

class Solution {

    // Intuition :
    // Here we are just iterating through the string expression, not via a loop but recursively
    // toggleIt is a function designed to return a vector containing :
    // 1.) The actual value of the expression passed to it
    // 2.) minimum operations to toggle this expression
    // We call the function with i = n - 1, but still it evaluates the expression in a left-to-right order
    // - this is because it is working in a post order fashion, for reference look at lines (51,52) and (73,74)
    // now coming on to how this algorithm works -
    // generally what we are trying to do here is that, if we recieve an expression like 'a' operator 'b'
    // Where 'b' and 'a' could be a single digit, a whole expression or an expression surrounded by parentheses
    // for simplicity (in our code) we allow 'b' to either be a single digit or an expression surrounded by parentheses
    // if it is of the second type we have to call the function again to calculate it (ref. line 29)
    // after that we evaluate 'a' 
    // Now we have the value of 'a', the operator and value of b for the given values of these variables
    // There are a total of 8 possible combinations, 
    // And for each one of them we have to return different values for minimum operations
    
    vector<int> toggleIt(string& expression, int& i) {
        int value, minOps1, minOps2, value1, value2;
        
        if(expression[i] == ')') {
            vector<int> temp;
            i--;
            temp = toggleIt(expression, i);
            value = temp[0];
            value1 = value;
            minOps1 = temp[1];
        }
        
        else {
            value = expression[i--] - '0';
            value1 = value;
            minOps1 = 1;
        }

        
        if(i < 0 or expression[i] == '(') {
            i--;
            return {value, minOps1};
        }

        
        if(expression[i] == '|') {
            i--;
            
            vector<int> temp = toggleIt(expression, i);
            value |= temp[0];
            value2 = temp[0];
            minOps2 = temp[1];
            
            if(value == 1) {
                if(value1 == 1 and value2 == 1) {
                    return {value, min(minOps1, minOps2) + 1};
                }
                
                else {
                    return {value, 1};
                }
            }
            
            else {
                return {value, min(minOps1, minOps2)};
            }
        }
        else {
            i--;
            
            vector<int> temp = toggleIt(expression, i);
            value &= temp[0];
            value2 = temp[0];
            minOps2 = temp[1];
            
            if(value == 0) {
                if(value1 == 0 and value2 == 0) {
                    return {value, min(minOps1, minOps2) + 1};
                }
                
                else {
                    return {value, 1};
                }
            }
            
            else {
                return {value, min(minOps1, minOps2)};
            }
        }


        return {-1, -1};
    }

public:
    int minOperationsToFlip(string expression) {
        int i = expression.size() - 1;
        return toggleIt(expression, i)[1];
    }
};

// Accepted after 3 hours but did it myself :)

// Time Complexity => O(expression.length)
// Space Complexity => O(1)