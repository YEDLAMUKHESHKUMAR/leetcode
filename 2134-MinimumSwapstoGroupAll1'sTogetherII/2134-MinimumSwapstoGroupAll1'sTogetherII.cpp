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




class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // 0,1,1,1,0 0 1 1 ,0,1,1,    0,1,1,1,0,0,1,1,
        int n = nums.size();
        int ones = 0;
        for(int i = 0; i<n;i++){
            if(nums[i] == 1){
                ones++;
            }
        }
        vector<int> newArr = nums;
        for(int i = 0; i < ones - 1; i++){
            newArr.push_back(nums[i]);
        }
		// printv(newArr);
        int zeroes = 0;
        for(int i = 0; i<ones;i++){
            if(nums[i] == 0) zeroes++;
        }
        int minSwaps = zeroes;
        int m = newArr.size();
        for(int i = ones ; i<m;i++){
            zeroes -= (newArr[i - ones] ^ 1); // style :) , nothing but zeroes--;
            zeroes += (newArr[i] ^  1) ; // z++;
            minSwaps = min(minSwaps, zeroes);
        }
        return minSwaps;


    }
};