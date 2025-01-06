#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
#define pii pair<int,int>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
// #define rep(i,a,b) for(int i = a ; i < b ; i++)
// #define rrep(i,a,b) for(int i = a ; i >= b ; i--)
#define N 1e6+1
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define test int tc; cin>>tc; while(tc--)
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define printm(a) {for(auto u:a) cout<<u.f << " " << u.s<<endl;}
// #define op() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef set<int> si;
typedef map<int, int> mii;
const double eps = 1e-9;
const int mod = (int)1e9 + 7;

class Solution {
public:
    vector<int> minOperations(string s) {
        int n = sz(s);
        int oneCount = 0;
        int onePosSum = 0;
        vector<int> pre(n);
        vector<int> suf(n);
        // 1 1 0 1 0 0 0 1
        // 0 1 2 3 4 5 6 7
        for(int i = 0;i<n;i++){
            int curr = abs(i * oneCount - onePosSum);
            pre[i] = curr;
            if(s[i] == '1'){
                oneCount++;
                onePosSum += i;
            }
        }
        oneCount =0, onePosSum = 0;
        for(int i = n-1;i>=0;i--){
            int curr = abs(i * oneCount - onePosSum);
            suf[i] = curr;
            if(s[i] == '1'){
                oneCount++;
                onePosSum += i;
            }
        }
        vector<int> ans(n);
        for(int i = 0; i<n;i++){
            ans[i] = pre[i] + suf[i];
        }
        return ans;
        
    }
};