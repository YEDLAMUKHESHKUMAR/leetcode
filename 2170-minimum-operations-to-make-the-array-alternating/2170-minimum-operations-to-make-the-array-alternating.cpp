class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        unordered_map<int, int> mp2;
        int evens = 0, odds = 0;
        for(int i = 0; i < n ; i++){
            if(i % 2 == 0){
                mp[nums[i]]++;
                evens++;
            }
            else{
                mp2[nums[i]]++;
                odds++;
            }
        }
        int maxi1 = 0, maxi2 = 0, maxi12 = 0, maxi22 = 0;
        int greaterFreqNum1 = 0, greaterFreqNum2 = 0;
        for(auto i : mp){
            if(i.second > maxi1){
                maxi12 = maxi1;
                maxi1 = i.second;
                greaterFreqNum1 = i.first;
            }
            else{
                maxi12 = max(maxi12, i.second);
            }
        }
        for(auto i : mp2){
            if(i.second > maxi2){
                maxi22 = maxi2;
                maxi2 = i.second;
                greaterFreqNum2 = i.first;
            }
            else{
                maxi22 = max(maxi22, i.second);
            }
        }
        
        if(greaterFreqNum1 != greaterFreqNum2){
            return n - (maxi1 + maxi2);
        }
        int alternate1 = maxi1 + maxi22;
        int alternate2 = maxi2 + maxi12;
        return n - max(alternate1, alternate2);

    }
};