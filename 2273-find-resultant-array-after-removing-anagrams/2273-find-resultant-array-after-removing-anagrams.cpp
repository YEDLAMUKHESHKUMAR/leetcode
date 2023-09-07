class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        // unordered_map<string,int> mp;
        string check=words[0];
        ans.push_back(check);
        sort(check.begin(),check.end());
        int n=words.size();
        for(int i=1;i<n;i++){
            string temp=words[i];
            sort(temp.begin(),temp.end());
            if(check!=temp){
                ans.push_back(words[i]);
                check=words[i];
                sort(check.begin(),check.end());
            }


        }
        return ans;
    }
};