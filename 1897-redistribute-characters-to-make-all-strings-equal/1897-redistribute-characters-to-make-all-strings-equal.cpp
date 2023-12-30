class Solution {
public:
    bool makeEqual(vector<string>& words) {
       unordered_map<char,int> mp;
       int n=words.size(),count=0;
       for(int i=0;i<n;i++){
           int j=words[i].size()-1;
           while(j>=0){
               mp[words[i][j]]++;
               j--;
           }
           
       } 
       
       for(auto i:mp){
           if(i.second % n!=0){
               return false;
           }
       }
       return true;
    }
};