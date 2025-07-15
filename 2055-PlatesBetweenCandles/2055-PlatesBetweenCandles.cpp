// Last updated: 7/15/2025, 2:29:58 PM
class Solution {
public:
    int BS(int left, int right , vector<int>& candles){
        int n = candles.size();
        int low = 0, high = n - 1;
        int ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(candles[mid] <= right){
                ans = candles[mid];
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        if(ans == -1 || ans < left) return -1;
        return ans;
    }
    int BS1(int left, int right, vector<int>& candles){
        int n = candles.size();
        int low = 0, high = n - 1 ;
        int ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(candles[mid] >= left){
                ans = candles[mid];
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        if(ans == -1 || ans > right ) return -1; 
        return ans;
    }
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& q) {
        int n = s.size();
        vector<int> candles;
        vector<int> prefix(n, 0);
        int plates = 0;
        for(int i = 0 ; i < n ;i++){
            if(s[i] == '*') plates++;
            else candles.push_back(i);
            prefix[i] = plates;
        }
       
        int qs = q.size();
        vector<int> ans;
        for(int i = 0; i < qs;i++){
            int l = q[i][0];
            int r = q[i][1];
            int next = BS1(l,r, candles);
            int prev = BS(l, r, candles);
            // cout<<next<<" "<<prev<<endl;
            if(next == -1 || prev == -1) ans.push_back(0);
            else{
                ans.push_back(prefix[prev] - prefix[next]);
            }
        }
        return ans;



    }
};