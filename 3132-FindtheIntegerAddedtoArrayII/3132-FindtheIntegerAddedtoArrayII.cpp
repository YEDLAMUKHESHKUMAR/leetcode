// Last updated: 8/8/2025, 10:25:40 AM
class Solution {
public:
    int solve(int s1, int s2, vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        int m = n - 2;
        int i = 0, j = 0;
        int prev = INT_MAX;
        while(i < n){
            if(i == s1 || i == s2) {
                i++;
                continue;
            }
            // cout<<i<<" ";
            // if(j >= m) break;
            int curr = nums2[j] - nums1[i];
            if(prev == INT_MAX) prev = curr;
            else if(curr  != prev) return INT_MAX;
            i++;
            j++;
        }
        return prev;
        
    }
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = n - 2;
        int ans = INT_MAX;
        int ans2 = INT_MIN;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for(int k = 0; k < n ;k++){
            int skip1 = k;
            for(int l = k + 1; l < n ; l++){
                int skip2 = l;
                int curr = solve(skip1, skip2, nums1, nums2);
                // cout<<curr<<endl;
                if(curr != INT_MAX) {
                    ans = min(ans,  curr);
                }
                // ans2 = max(ans2, curr);
                
            }
        }
        // cout<<ans2<<endl;
        // if(abs(ans) < abs(ans2)) return ans;
        return ans;
    }
};