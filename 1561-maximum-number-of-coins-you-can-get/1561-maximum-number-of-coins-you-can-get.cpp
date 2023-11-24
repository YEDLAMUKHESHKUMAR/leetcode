class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int n = piles.size(), i=0,j=n-1;     // :)
        int maximumCoins = 0;
        while(i<j){
            maximumCoins = maximumCoins + piles[j-1];
            i++;
            j-=2;
        }
        return maximumCoins;
    }
};