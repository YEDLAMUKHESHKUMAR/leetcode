class Solution {
public:
    struct myComp {
    constexpr bool operator()(
        pair<long long, long long> const& a,
        pair<long long, long long> const& b)
        const noexcept
    {
        return a.second < b.second;
    }
};
 
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<long long , long long> mp;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, myComp> pq;
        int n = nums.size();
        vector<long long> ans;
        // int maxi = INT_MIN;
        long long maxi = INT_MIN;
        for(int i=0;i<n;i++){
            mp[nums[i]]+=freq[i];
            // ans.push_back(mp[nums[i]]);
            if(pq.empty()){
                pq.push({nums[i],mp[nums[i]]});
                // maxi = max(maxi,mp[nums[i]]);
            }
            while(!pq.empty()){
                long long num = pq.top().first; //  T_T
                long long f = pq.top().second; // T_T 
                // shit shit shit....literally if i put long long above , instead of int in contest , i would have completed this T_T
                if(f == mp[num]){
                    break;
                }
                pq.pop();
                if(mp[num]!=0){
                    // ans.push_back(9);
                    pq.push({num,mp[num]});
                }
            }
            pq.push({nums[i],mp[nums[i]]});

            // maxi = max(maxi,pq.top().second);
            ans.push_back(pq.top().second);
            
            
        }
        
        return ans;
        

    }
};