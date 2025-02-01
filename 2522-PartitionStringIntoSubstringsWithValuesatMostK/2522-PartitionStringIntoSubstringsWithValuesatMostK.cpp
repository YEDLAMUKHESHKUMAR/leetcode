#define ll long long
class Solution {
public:
    int minimumPartition(string s, int k) {
        int n = s.size();
        ll ans = 0;
        ll num = 0;
        ll i = 0;
        while(i<n){
            ll temp = s[i] - '0';
            if((num * 10 + temp)  > k){
                ans++;
                num = temp;
                if(num > k && k <=9) return -1;
                if(num > k) {
                    ans++;
                    num = 0;
                }
                // i--;
            }
            else{
                num = num * 10 + temp;
                cout<<"index : "<<i<<endl;
            }
            cout<<i<<" : "<<num<<endl;
            i++;
        }
        if(num != 0) ans++;
        return ans;

        
    }
};