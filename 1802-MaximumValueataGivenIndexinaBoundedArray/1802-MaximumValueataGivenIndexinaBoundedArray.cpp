#define ll long long
class Solution {
public:
    ll solveLeft(ll left, ll rem){
        if(left == 0 ) return 0;
        ll sum = 0 ;
        ll sumOfRem = (rem * (rem + 1)) / 2;
        if(left <= rem){
            ll r = rem - left;
            sum = sumOfRem  - (  ( r * (r + 1) ) / 2  );
        }
        else{
            ll stillHave = left - rem;
            sum = sumOfRem + stillHave; 
        }
        return sum;
    }
    ll solveRight(ll right, ll rem){
        if(right == 0) return 0;
        ll sum = 0 ;
        ll sumOfRem = (rem * (rem + 1)) / 2;
        if(right <= rem){
            ll r = rem - right;
            sum = sumOfRem  - (  ( r * (r + 1) ) / 2  );
        }
        else{
            ll stillHave = right - rem;
            sum = sumOfRem + stillHave; 
        }
        return sum;
    }
    int maxValue(int n, int index, int maxSum) {
        ll left = index, right = n - index - 1;
        ll low = 1, high = maxSum , ans = 0;
        while(low <= high){
            ll mid = (low + high) / 2;
            bool isValid = false;

            // _ _ _ _
            // 4 

            ll rem = mid - 1;

            ll rightSum = solveRight(right, rem);    
            ll leftSum = solveLeft(left, rem);
            if(rightSum + leftSum + mid <= maxSum) isValid = true;
            if(isValid){
                ans = mid;
                low = mid + 1;
            } 
            else high = mid - 1;

        }
        return ans;
    }
};