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
#define rep(i,a,b) for(int i = a ; i < b ; i++)
// #define rrep(i,a,b) for(int i = a ; i >= b ; i--)
#define N 1e6+1
 // -------------------------------------MATH-----------------------------------
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
// -------------------------------------TEST CASE-------------------------
#define test int tc; cin>>tc; while(tc--)
#define narr int n ; cin>>n; vi arr(n); rep(i , 0 , n) cin>>arr[i];
// -----------------------------DEBUG----------------------------------------
#define printv(a) {for(auto u:a) cout<<u<<" "; cout<<endl;}
#define printm(a) {for(auto u:a) cout<<u.f << " " << u.s<<endl;}
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


// Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
// Output: ["facebook","google","leetcode"]
class Solution {
public:
    vector<string> wordSubsets(vector<string>& s1, vector<string>& s2) {
        int n = sz(s1);
        int m = sz(s2);
        vi need(26 , 0);
        for(int i = 0; i<m;i++){    // :) 
            int ws = sz(s2[i]);
            vi temp(26,0);
            for(int j = 0; j< ws;j++){
                temp[s2[i][j] - 'a']++;
            }
            for(int i = 0; i<26 ;i++){
                need[i] = max(need[i] , temp[i]);
            }
        }
        vs ans;
        for(int i = 0; i<n;i++){
            int ws = sz(s1[i]);
            vi temp(26,0);
            for(int j = 0 ; j<ws ;j++){
                temp[s1[i][j] - 'a']++;
            }
            bool check = true;
            for(int i = 0; i<26 ;i++){
                if(temp[i] < need[i]){
                    check = false;
                    break;
                }
            }
            if(check == true) ans.push_back(s1[i]);
        }
        return ans;

        
    }
};