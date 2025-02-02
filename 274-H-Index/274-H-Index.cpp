class Solution {
public:
    bool solve(int mid, vector<int> &arr){
        auto it = lower_bound(arr.begin(), arr.end(), mid);
        if(it == arr.end() ) return false;
        if(mid <= (arr.size() - (it - arr.begin()))) return true;
        return false;
    }
    int hIndex(vector<int>& citations) {
        // 2 5 5 5 6
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int l = 0, h = n , ans = 0;
        while(l <= h){
            int mid = (l + h) / 2;
            if(solve(mid, citations)) {
                ans = mid;
                l = mid + 1;
            }
            else h = mid - 1;
        }
        return ans;
    }
};