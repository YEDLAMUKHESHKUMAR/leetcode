#include<bits/stdc++.h>
using namespace std;

#define ll long long int
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
#define rep(i,a,b) for(int i = a ; i < b ; i++)
// #define rrep(i,a,b) for(int i = a ; i >= b ; i--)
#define N 1e6+1
 // -------------------------------------MATH-----------------------------------
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))

// -------------------------------------TEST CASE-------------------------
#define test int tc; cin>>tc; while(tc--)
#define narr ll n ; cin>>n; vi arr(n); rep(i , 0 , n) cin>>arr[i];
#define take(x) ll (x);cin>>(x);
#define takearr(name, size)  vl (name)(size); rep(i , 0 , size) cin>>(name)[i];
// -----------------------------DEBUG----------------------------------------
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define printm(a) {for(auto u:a) cout<<u.F << " " << u.S<<endl;}
// ------------------------------------------------------------------
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
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vi> dp(n, vi (m , 1e8));
        for(int j = 0; j<m;j++) dp[0][j] = matrix[0][j];
        for(int i = 1; i<n;i++){
            for(int j = 0; j<m;j++){
                dp[i][j] = min(dp[i][j], dp[i-1][j]); // up

                if(j > 0){
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                }
                if(j < m-1){
                    dp[i][j] = min(dp[i][j], dp[i-1][j+1]);
                }
                dp[i][j] += matrix[i][j] ; // consider curr sum
            }
        }
        int mini = INT_MAX;
        for(int j = 0; j<m;j++){
            mini = min(mini, dp[n-1][j]);
        }
        return mini;
    }
};