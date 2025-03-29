// Last updated: 3/29/2025, 6:07:23 PM
#define ll long long
const int mod = 1e9 + 7;

class Solution {
public:
    ll expo(ll a, ll b){
        ll ans = 1;
        while(b != 0){
            if(b & 1 ){
                ans = (ans * a) %  mod;
            }
            a = (a * a) %  mod;
            b = b >> 1;
        }
        return ans;
    }
    void stackOp(bool flag, stack<ll> &st, ll i, vector<ll> &prev, vector<ll> &next, vector<ll> &primeFactors){
        
        while(!st.empty() && primeFactors[i] > primeFactors[st.top()]){
            ll top = primeFactors[st.top()];
            st.pop();
            next[top] = i;  // this is same as prev code....which i've written, but in a diff way.., if the prev guy is popping out, means someone greater came, so put this greater to that guy..
        }
        
       
        if(!st.empty()){
            prev[i] = st.top();
        }
        st.push(i);
        
    }
    void findNumberOfPrimeFactors(vector<int> &nums, vector<ll> &primeFactors){
        int n = nums.size();
        for (int index = 0; index < n; index++) {
            int num = nums[index];
            for (int factor = 2; factor <= sqrt(num); factor++) {
                if (num % factor == 0) {
                    primeFactors[index]++;

                    while (num % factor == 0) num /= factor;
                }
            }
            if (num >= 2) primeFactors[index]++;
        }
    }
    int maximumScore(vector<int>& nums, int k) {
        // 2 5 4 3 2 2 1 
        ll n = nums.size();
        vector<ll> next(n , n);
        vector<ll> prev(n , -1);
        vector<ll> primeFactors(n, 0);
        stack<ll> st;
        ll top, ind, left, right, possible, need, ans = 1;
        priority_queue<pair<ll,ll> > pq;
        findNumberOfPrimeFactors(nums, primeFactors);
        for(int i = 0; i < n ;i++){
            pq.push({nums[i], i});
            // stackOp(true, st, i , prev, next, primeFactors);

            while(!st.empty() && primeFactors[i] > primeFactors[st.top()]){
                ll top = st.top();
                st.pop();
                next[top] = i;  // this is same as prev code....which i've written, but in a diff way.., if the prev guy is popping out, means someone greater came, so put this greater to that guy..
            }
        
       
            if(!st.empty()){
                prev[i] = st.top();
            }
            st.push(i);
            
        }
        // while(!st.empty()) st.pop(); // clearing..

        // for(int i = n -1 ; i>=0; i--){  // don't know why this is failing for last test case... lets write this in another way...
        //     stackOp(false, st, i , next, primeFactors);
        // }
        ll K = k;
        cout<<endl;
        for(int i = 0; i < next.size();i++){
            cout<<prev[i]<<" : "<<next[i]<<endl;
        }
        while(K > 0){
            top = pq.top().first;
            ind = pq.top().second;
            pq.pop();
            left = ind - prev[ind];
            right = next[ind] - ind ;
            // ll l = (((left % mod) + (right  % mod)) % mod) ;
            // ll r = (((left - 1) % mod) * (right % mod)) % mod;
            // possible = ((l % mod) + (r % mod)) % mod;
            possible = ((left ) * right ) ;
            need = min(possible, K);
            K -= need;
            // ll power = expo(top, need) % mod;
            // cout<<ind<<" : "<<top<<" : "<<need<<" : "<<power<<endl;
            
            ans = (ans * expo(top , need)) % mod;

            // if(K == 0) break;
        }
        return ans % mod;
        
    }
};