// Last updated: 6/21/2025, 10:35:34 AM
class Solution {
public:
    int minimumDeletions(string s, int k) {
        // 1 1 1 2 3 5 
        int n = s.size();
        vector<int> mp(26, 0);
        // unordered_map<int,int> freq;
        // vector<int> store;
        for(int i = 0; i < n ;i++){
            mp[s[i] - 'a']++;
        }
        // for(int i = 0; i < 26; i++){
        //     freq[mp[i]]++;
        //     if(freq[mp[i]] == 1) store.push_back(mp[i]);
        // }
        // sort(store.begin(), store.end());
        int ans = n;
        for(int i = 0 ; i< 26; i++){
            int freq = mp[i];
            int lessSum = 0, greaterSum = 0, c = 0;
            for(int j = 0 ; j < 26 ; j++){
                if(mp[j] < freq) lessSum += mp[j]; 
                else if(mp[j] >= freq + k + 1) {
                    greaterSum += mp[j];
                    c++;
                }
            }
            // cout<<lessSum<<" "<<greaterSum<<endl;
            int MinDelete = lessSum + ( greaterSum - ( freq + k ) * c );
            ans = min(ans, MinDelete);

        }
        return ans;


    }
};