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
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // try to think in sorting + grouping them 
        int n = nums.size();
        vector<pair<int,int>> pairs;         // :) :) notes
        for(int i = 0; i<n;i++){
            pairs.push_back({nums[i] , i});
        }
        sort(pairs.begin(), pairs.end());
        int component = 1;
        map<int, vector<int>> mp;
        vector<int> belongsTo(n,0);
        belongsTo[0] = 1;
        mp[1].push_back(pairs[0].second);
        
        // printm(pairs);
        // cout<<mp[1][0];
// return nums;
        for(int i = 1; i<n;i++){
            if(pairs[i].first - pairs[i-1].first > limit){
                component++;
            }
            belongsTo[i] = component;
            mp[component].push_back(pairs[i].second);
            // cout<<"component : "<<component<<" : "<<pairs[i].second<<" "; 

        }
        // cout<<endl;
        // cout<<endl;
        // for(auto i : mp){
        //     for(auto j : i.second){
        //         cout<<j<<" "; 
        //     }
        //     cout<<endl;
        // }
        for(auto &i:mp){ // found the bug :) dude ... put & if u want to sort , otherwise, it won't get affect, 
            sort(i.second.begin(), i.second.end());
        }
        // for(auto i : mp){
        //     for(auto j : i.second){
        //         cout<<j<<" "; 
        //     }
        //     cout<<endl;
        // }
        
        int j = 0 , totalComponents = belongsTo[n - 1];
        for(int i = 1; i<= totalComponents ;i++ ){
            for(int k = 0; k < mp[i].size(); k++){
                nums[mp[i][k]] = pairs[j].first;
                j++;
            }
        }
        return nums;

    }
};