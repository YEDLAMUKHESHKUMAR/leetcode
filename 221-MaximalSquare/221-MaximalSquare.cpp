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
    bool predicate(int mid, vector<vector<int>> &pre){
        int n = pre.size();
        int m = pre[0].size();

        for(int i = 0; i<n;i++){
            for(int j = 0;j<m;j++){
                int sum = pre[i][j];
                if(j - mid >= 0){
                    sum -= pre[i][j - mid];
                }
                if(i - mid >= 0){
                    sum -= pre[i- mid][j];
                }
                if(i - mid >= 0 && j - mid >= 0){
                    sum += pre[i - mid ][ j - mid];
                }

                if(sum == ( mid * mid )) return true;
            }
        }
        return false;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> prefix(n, vector<int> (m, 0));  // :)
        prefix[0][0] = matrix[0][0] - '0'; 
        for(int i = 0 ;i < n; i++){
            for(int j = 0; j<m;j++){
                if(i == 0 && j == 0) continue;
                int curr = matrix[i][j] - '0';
                prefix[i][j] += curr;
                if(i > 0){
                    prefix[i][j] += prefix[i-1][j];
                }
                if(j > 0){
                    prefix[i][j] += prefix[i][j-1];
                }
                if(i > 0 && j > 0){
                    prefix[i][j] -= prefix[i-1][j-1];
                }
            }
        }
        // for(auto i:prefix) printv(i);


        int low = 1, high = max(n, m);
        int ans = 0;
        while(low <= high){
            int mid = ( low + high ) / 2;
            if(predicate(mid, prefix) == true){
                ans = mid;
                low = mid  + 1;
            }
            else high = mid - 1;
        }
        return ans * ans;
    }
};