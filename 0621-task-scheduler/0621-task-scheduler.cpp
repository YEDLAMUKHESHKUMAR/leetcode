class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       unordered_map<char,int> mp;
       int size = (int)tasks.size(); // notes
       int maxCount = 0;
       for(int i=0;i<size;i++){
           mp[tasks[i]]++;
           maxCount = max(maxCount,mp[tasks[i]]);
       } 
       int ans = (maxCount-1) * (n+1) ;                                       
       for(auto i:mp){           
           if(i.second == maxCount){
               ans++;
           }
       }
       return max(size,ans);
    }
};