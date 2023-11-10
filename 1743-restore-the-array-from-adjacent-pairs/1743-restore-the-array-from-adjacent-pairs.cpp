class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> mp;
        int n = adjacentPairs.size();
        vector<int> ans;
        for(int i=0;i<n;i++){                      // boogie woogie :)
            int curr1 = adjacentPairs[i][0];
            int curr2 = adjacentPairs[i][1];
            mp[curr1].push_back(curr2);
            mp[curr2].push_back(curr1);
        }
        int startWith ;
        int GoOn ;
        for(auto i:mp){
            if(i.second.size()==1){
                startWith = i.first;
                break;
            }
        }
        int j = 0;
        ans.push_back(startWith);
        startWith = mp[startWith][0];
        ans.push_back(startWith);
        if(n==1) return ans;
        j+=2;
        int size1 = 0 ;
        while(size1 !=1){ // look even you write !=100 , it will work , becoz it will keep on loop on the vector having size 1
            int currSize = mp[startWith].size();
            if(currSize==1) size1++;
            for(int i=0;i<currSize;i++){
                int currElement = mp[startWith][i];
                if(currElement!=ans[j-2]){
                    startWith = currElement ; 
                    ans.push_back(startWith);
                    j++;
                    break;
                }
            }


        }
        return ans;

        
    }
};