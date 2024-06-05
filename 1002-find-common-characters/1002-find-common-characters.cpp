class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<int> initial(26,0);
        for(int i = 0 ; i < words[0].size();i++){  // :)
            initial[words[0][i] - 'a']++;
        }
        for(int i = 1 ; i < n ; i++){
            string s = words[i];
            int m = s.size();
            vector<int> partial(26,0);
            for(int j = 0 ; j < m ; j++){
                partial[s[j] - 'a']++;
            }
            for(int k = 0 ; k<26 ; k++){
                if(partial[k] < initial[k]){
                    initial[k] = partial[k]; 
                }
            }
        }
        vector<string> ans;
        for(int i = 0; i<26;i++){
            char c = char(i + 'a');
            string s = "";
            s+=c;
            int num = initial[i];
            while(num--){
                ans.push_back(s);
            }
        }
        return ans;
    }
};