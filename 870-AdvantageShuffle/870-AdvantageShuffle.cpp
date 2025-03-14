class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        priority_queue< pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq1;
        priority_queue< pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq2;
        vector<int> ans(n, -1);
        vector<int> wasted;
        for(int i = 0; i < n;i++){
            pq1.push({nums1[i], i});
            pq2.push({nums2[i], i});
        }
        while(!pq2.empty() && !pq1.empty()){
            while(!pq1.empty() && pq2.top().first >= pq1.top().first){
                wasted.push_back(pq1.top().first);
                pq1.pop();
            }
            if(pq1.empty()) break;
            ans[pq2.top().second] = pq1.top().first;
            pq1.pop();
            pq2.pop();
        }
        int j = 0;
        for(int i = 0; i < n ;i++){
            if(ans[i] == -1){
                ans[i] = wasted[j++]; 
            }
        }
        return ans;

    }
};