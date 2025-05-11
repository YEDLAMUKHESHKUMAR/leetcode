// Last updated: 5/11/2025, 2:45:33 PM
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odds = 0;
        for (auto i = 0; i < arr.size() && odds < 3; ++i){
            odds = arr[i] % 2 ? odds + 1 : 0;
        }   
        return odds == 3;
    }
};