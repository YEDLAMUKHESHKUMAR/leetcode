// Last updated: 7/9/2025, 8:42:20 PM
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& st, vector<int>& et) {
        int n = st.size();
        vector<int> gaps;
        if(st[0] > 0){
            gaps.push_back(st[0]);
        }
        for(int i = 1 ; i < n;i++){
            gaps.push_back(st[i] - et[i - 1]);
        }
        if(et[n - 1] < eventTime){
            gaps.push_back(eventTime - et[n-1]);
        }
        for(auto i : gaps) cout<<i << " ";
        int m = gaps.size();
        int sum = 0;
        for(int i = 0; i < min(k , m) ;i++){
            sum += gaps[i];
        }
        int ans = sum;
        for(int i = k ; i< m ;i++){
            sum += gaps[i];
            ans = max(ans, sum);
            sum -= gaps[i - k ];
        }
        return ans;

    }
};