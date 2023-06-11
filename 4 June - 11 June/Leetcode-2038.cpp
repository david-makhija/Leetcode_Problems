class Solution {
public:
    bool winnerOfGame(string colors) {
        int aliceTurns = 0, bobTurns = 0, n = colors.size(), i=0;
        while(i<n) {
            char color = colors[i];
            int prev = i;
            while(i<n and color==colors[i]) i++;
            if(color=='B' and i-prev>2) bobTurns += (i-prev-2);
            if(color=='A' and i-prev>2) aliceTurns += (i-prev-2);
        }
        int t = 0;
        while(aliceTurns>0 or bobTurns>0) {
            if(aliceTurns==0) return false;
            if(bobTurns==0) return true;
            if(t==0) {
                aliceTurns--;
                t = 1;
            }
            if(t==1) {
                bobTurns--;
                t = 0;
            }
        }
        return false;
    }
};