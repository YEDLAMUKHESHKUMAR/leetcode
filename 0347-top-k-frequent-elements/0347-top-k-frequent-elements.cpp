class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        while(k!=0){
            int num = pq.top().second;
            ans.push_back(num);
            pq.pop();
            k--;
        }
        return ans;
    }
};