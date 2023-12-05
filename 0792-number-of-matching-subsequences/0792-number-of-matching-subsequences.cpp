class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
         int n = s.length();
        map<char,vector<int>>mp;
        int z = 0;
        for(auto it : s) mp[it].push_back(z++);
        int m = words.size();
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            string s1 = words[i];
            int latest = -1;
            for(int j=0;j<s1.size();j++)
            {
                auto it = upper_bound(mp[s1[j]].begin(), mp[s1[j]].end(),latest);  
                        // to find the first position in the vector associated with that character in the map where the position is greater than the current value of latest.

                if(it == mp[s1[j]].end())break;
                latest = *it;
                if(j == s1.size()-1) cnt++;
            }
        }
        return cnt;
        
    }
};