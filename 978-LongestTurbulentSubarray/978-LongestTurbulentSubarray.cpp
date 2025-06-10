// Last updated: 6/10/2025, 4:36:00 PM
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        // 0 1 1 0 3 0 0
        // 0 0 0 2 0 4 0
        int n = arr.size();
        vector<int> less(n, 0);
        vector<int> greater(n, 0);
        int maxLen = 0;
        for(int i = 1;  i < n; i++){
            if(arr[i] == arr[i - 1]) continue;
            if(arr[i] < arr[i - 1]) less[i] = max(less[i], 1 + greater[i - 1]);
            else if(arr[i] > arr[i - 1]) greater[i] = max(greater[i], 1 + less[i - 1]);
            maxLen = max({maxLen, less[i], greater[i]});
        }
        return maxLen + 1;
    }
};