#define ll long long
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        ll n = nums.size();
        priority_queue<ll , vector<ll> , greater<ll> > pq;
        for(int i = 0; i<n;i++){
            pq.push(nums[i]);
        }
        ll ans = 0;
        while(!pq.empty() && pq.size() >= 2){
            ll top1 = pq.top();
            pq.pop();
            if(top1 >= k) break;
            ll top2 = pq.top();
            pq.pop();
            ll newEl = min(top1, top2) * 2 + max(top1, top2);
            pq.push(newEl);
            ans++;
        }
        return ans;
    }
};