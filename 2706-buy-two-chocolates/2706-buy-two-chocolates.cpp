class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int s1 = INT_MAX, s2 = INT_MAX;
        int n = prices.size();
        for(int i = 0; i<n;i++){        // ,
            if(prices[i] < s1){
                s2 = s1;
                s1 = prices[i];
            }
            else{
                s2 = min(prices[i],s2);
            }
        }
        if(s1+s2 > money) return money;
        return money-(s1+s2);
    }
};