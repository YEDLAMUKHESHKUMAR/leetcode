// Last updated: 7/29/2025, 7:23:16 PM
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> bits(32, 0);
        vector<int> ans;
        
        int j = n - 1;

        for(int i = n - 1; i>= 0 ; i--){
            for(int pos = 0 ; pos < 32 ; pos++){
                if( ( nums[i] >> pos ) & 1 ) bits[pos]++; 
            }   
            while(i < j){
                vector<int> temp(32,0);
                bool check = true;
                for(int pos = 0 ; pos < 32 ; pos++){
                    if( (( nums[j]  >> pos) & 1) ){
                        temp[pos]++;
                        if(abs(temp[pos] - bits[pos]) <= 0) {
                            check = false;
                            cout<<1<<endl;
                            break;
                        }
                    }
                }
                if(check == false) break;
                for(int pos = 0 ; pos < 32 ;pos++){
                    if((nums[j] >> pos) & 1) bits[pos]--;
                }
                j--;
            }
            ans.push_back( j - i + 1 );
        }
            
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};