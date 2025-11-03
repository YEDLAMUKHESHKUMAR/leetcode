class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int count = 1;
        char color = colors[0];
        int maxi = neededTime[0];  
        int sum = neededTime[0];
        int ans = 0;
        int n = colors.size();
        for(int i=1;i<n;i++){
            if(colors[i] == color){
                count++;
                sum+=neededTime[i];
                maxi = max(maxi,neededTime[i]);
            }
            else if(colors[i] != color){
                if(count>1){
                    sum-= maxi;
                    ans+=sum;
                }
                color = colors[i];
                maxi = neededTime[i];
                sum=neededTime[i];
                count = 1;
            }
        }
        if(count>1){
            sum-= maxi;
            ans+=sum;
        }
        return ans;
    }
};