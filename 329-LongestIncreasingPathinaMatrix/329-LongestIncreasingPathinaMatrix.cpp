#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
#define pii pair<int,int>
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
    vector<int> rows = {-1, 0, 1, 0};
    vector<int> cols = {0, 1, 0, -1};
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxPath = 1, qs, level, i1, j1, prev, newRow, newCol, prevValue, currValue ;  // :) :) 
    // notes
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (m + 1, vector<int> (2, -1)));
        queue< pair<int, pair<int,int>> > q;
        for(int i = 0 ; i < n ;i++){

            for(int j = 0; j < m ; j++){

                q.push({ -1, { i, j } } );
                level = 0;
                while(!q.empty()){ // BFS
                    level++;
                    qs = q.size();
                    for(int k = 0 ; k < qs ; k++){  // Level wise...
                        i1 = q.front().second.first;
                        j1 = q.front().second.second;
                        prev = q.front().first;
                        prevValue = mat[i1][j1];
                        q.pop();

                        for(int t = 0; t < 4 ; t++){
                            newRow = i1 + rows[t];
                            newCol = j1 + cols[t];
                            if(newRow < n && newRow >= 0 && newCol < m && newCol >=0 ){
                                currValue = mat[newRow][newCol];
                                if(currValue == prevValue) continue;
                                if( currValue < prevValue){
                                    if((prev == -1 || prev == 0 ) && (level + 1 > dp[newRow][newCol][0]) ){ // 0 means , decreasing..
                                        q.push({ 0, { newRow, newCol } });
                                        dp[newRow][newCol][0] = level + 1;
                                    }
                                }
                                else {
                                    if( (prev == -1 || prev == 1) && level + 1 > dp[newRow][newCol][1]) {
                                        q.push({ 1, {newRow, newCol} });
                                        dp[newRow][newCol][1] = level + 1;
                                    }
                                }
                            }
                        }
                        
                    }
                }
                maxPath = max(maxPath, level);

            }

        }
        // for(auto i : dp){
        //     printm(i);
        // }
       
        return maxPath;
    }
};