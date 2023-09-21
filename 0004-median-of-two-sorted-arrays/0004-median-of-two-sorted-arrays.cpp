class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //    ouble findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int i=0,j=0,mid;
    //     double ans;
    //     mid=(nums1.size()+nums2.size())/2;
    //     vector<int> neww;
    //     while(neww.size()<=mid+1){
    //         if(nums1[i]<nums2[j]){
    //             neww.push_back(nums1[i]);
    //             i++;
    //         }
    //         else if(nums1[i]>nums2[j]){
    //             neww.push_back(nums2[j]);
    //             j++;
    //         }
    //         else{
    //             neww.push_back(nums1[i]);
    //             neww.push_back(nums2[j]);
    //             i++;
    //             j++;
                
    //         }
    //     }
    //     if((nums1.size()+nums2.size())%2==0){
    //         ans = double((neww[mid]+neww[mid-1]))/2.0;
    //         return ans;
    //     }
    //     ans= neww[mid];
    //     return ans;
    // }
       int i = 0, j = 0, mid;
    double ans;
    mid = (nums1.size() + nums2.size()) / 2;
    vector<int> neww;
    while (neww.size() <= mid) {
        if (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                neww.push_back(nums1[i]);
                i++;
            }
            else {
                neww.push_back(nums2[j]);
                j++;
            }
        }
        else if (i < nums1.size()) {
            neww.push_back(nums1[i]);
            i++;
        }
        else if (j < nums2.size()) {
            neww.push_back(nums2[j]);
            j++;
        }
        if (neww.size() > mid) {
            break;
        }
    }
    while (neww.size() <= mid) {
        if (i < nums1.size()) {
            neww.push_back(nums1[i]);
            i++;
        }
        else if (j < nums2.size()) {
            neww.push_back(nums2[j]);
            j++;
        }
    }
    if ((nums1.size() + nums2.size()) % 2 == 0) {
        ans = double((neww[mid] + neww[mid - 1])) / 2.0;
        return ans;
    }
    ans = neww[mid];
    return ans;






    






    }
};