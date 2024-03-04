class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int i = 1, j = n-1;
        if(tokens.size()==0) return 0;
        sort(tokens.begin(),tokens.end());
        if(power < tokens[0] || power==0) return 0;
        int score = 1;
        int maxScore = 1;
        power-=tokens[0];
        while(i<=j){
            if(power >= tokens[i]){
                score++;
                maxScore = max(maxScore,score);
                power-=tokens[i];
                i++;
            }
            else{
                score--;
                power+=tokens[j];
                j--;
            }
        }
        return maxScore;
    }
};