class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int ans = 0;
        vector<int> arr ;
        for(int i = 0; i < 2 * n;i++){
            arr.push_back(gas[i % n] - cost[i % n]);
        }
        // for(auto i : arr) cout<<i<<" ";
        // cout<<endl;
        int sz = 1, sum = 0 ,c = 0 , ind = 0;
        for(int i = 0; i < 2 * n;i++){
            sum += arr[i];
            if(sum < 0){
                if(c >= n) return ind;
                sum = 0;
                c = 0;
                ind = i + 1 ;
            }
            else c++;
            // cout<<sum<<" ";
        }
        if(c >= n) return ind;
        return -1;

    }
};