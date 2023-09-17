class Solution {
public:
    int minDeletions(string s) {
        // e-1
        // b-2
        // c-2
        // a-3
        unordered_map<char,int> mp;
        unordered_map<int,int> freq;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            
        }
        // for(auto i:mp){
        //     freq[i.second]++;
        // } 
        // return mp['a'];
        int minOperations=0;
        for(auto i:mp){
            // if(freq[i.second]>1){
            if(freq[i.second]==0){
                freq[i.second]++;
            }
            else{
                while(freq[i.second]>0){
                    minOperations++;
                    // freq[i.second]--;
                    i.second--;
                }
                if(i.second!=0){
                    freq[i.second]++;
                }
            }
        }
        return minOperations;

        

    }
};