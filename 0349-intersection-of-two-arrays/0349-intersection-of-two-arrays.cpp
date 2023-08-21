class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> ans;
        int n1=nums1.size(),n2=nums2.size();
        for(int i=0;i<n1;i++){
            mp[nums1[i]]++;
        }
        for(int i=0;i<n2;i++){
            if(mp[nums2[i]]>0){
                ans.push_back(nums2[i]);
                mp[nums2[i]]=-1;
            }

        }
        return ans;
    }
};