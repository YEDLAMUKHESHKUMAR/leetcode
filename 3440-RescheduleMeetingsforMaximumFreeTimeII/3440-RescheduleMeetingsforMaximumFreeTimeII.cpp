// Last updated: 7/10/2025, 10:04:18 PM
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& st, vector<int>& et) {
        // _ ... _ _ _ . _ _ ..... _ .. _ _ _ _ _ . _ _ . _
        // 1      3     2           1       5        2    1

        // 1 1 2 2 3 5

        int n = st.size();
        vector<int> pre(n, 0);
        vector<int> suf(n, 0);
        if(st[0] > 0 ){
            pre[0] = st[0];
        }
        if(eventTime > et[n - 1]){
            suf[n - 1] = eventTime - et[n - 1];
        }

        for(int i = 1 ; i< n ;i++){
            int maxGapLeft = max(pre[ i - 1] , st[i] - et[i - 1]);
            pre[i] = maxGapLeft;
        }
        for(int i = n - 2; i >= 0; i--){
            int maxGapRight = max(suf[ i + 1 ] , st[i + 1] - et[i]);
            suf[i] = maxGapRight;
        }
        int maxi = 0;
        int prevEndTime = 0;
        for(int i = 0; i < n ;i++){
            int maxLeft = i - 1 >= 0 ? pre[i - 1] : -1;
            int maxRight = i + 1 < n ? suf[i + 1] : -1;
            int required = et[i] - st[i];
            int left = st[i] - ( i - 1 >= 0 ? et[ i - 1] : 0 ) ;
            int right = ( i + 1 < n  ? st[i + 1] : eventTime  ) - et[i] ;
            if(maxLeft >= required || maxRight >= required  ){
                maxi = max(maxi,  required +  left + right  );
            }
            else{
                maxi = max(maxi, left + right);
            }
            
        }
        return maxi;


        
    }
};