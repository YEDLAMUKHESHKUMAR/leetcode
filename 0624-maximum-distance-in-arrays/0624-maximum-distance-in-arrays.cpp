class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int size = arrays.size();
        int minimumElement = arrays[0][0];
        int maximumElement = arrays[0][arrays[0].size() - 1 ]; // can also solve this another way....take min,secondmin,max,secondmax
        // if min and max are both in same array, take max of 
        // min - secondmax  and secondmin - max
        int maxAbsDiff = 0;
        for(int i = 1 ;i< size; i++){
            int absDiff1 =  abs(arrays[i][arrays[i].size() - 1 ] - minimumElement);
            int absDiff2 = abs(arrays[i][0] - maximumElement);
            maxAbsDiff = max(maxAbsDiff,max(absDiff1,absDiff2));
            minimumElement = min(minimumElement,arrays[i][0]);
            maximumElement = max(maximumElement,arrays[i][arrays[i].size() - 1 ]);
        }
        return maxAbsDiff;

    }
};