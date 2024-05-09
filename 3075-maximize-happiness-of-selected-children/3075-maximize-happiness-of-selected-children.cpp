class Solution {
public:
    long long maximumHappinessSum(vector<int>& a, int k) {
        int n  = a.size();
        priority_queue<long long> pq;
        for(int i = 0; i<n ;i++){
            pq.push(a[i]);
        }
        long long sum = 0;
        long long happy = 0;
        while(!pq.empty() && k--){
            long long top = pq.top();
            pq.pop();
            top = top - sum ;
            if(top >= 0){
                happy+=top;
            } 
            sum++;
        }
        return happy;
    }
};