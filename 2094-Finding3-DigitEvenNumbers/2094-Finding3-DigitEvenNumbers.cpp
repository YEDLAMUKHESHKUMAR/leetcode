// Last updated: 5/12/2025, 8:54:49 PM
class Solution {
public:
    bool isValid(int num, unordered_map<int,int> &freq, unordered_map<int,int> &mp){
        
        for(auto i : freq){
            if(i.second > mp[i.first]) return false;
        }
        if(num % 2 == 0) return true;
        return false;
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i = 0; i < n;i++){
            mp[digits[i]]++;
        }
        for(int number = 100; number<= 999; number++){
            int temp = number;
            int firstDigit = temp % 10;
            temp /= 10;
            int secondDigit = temp % 10;
            temp /= 10;
            int thirdDigit = temp % 10;
            cout<<firstDigit<<" "<<secondDigit<<" "<<thirdDigit<<endl;
            unordered_map<int,int> freq;
            freq[firstDigit]++;
            freq[secondDigit]++;
            freq[thirdDigit]++;
            if( isValid(number, freq, mp) ){
                ans.push_back(number);
            }

        }
        return ans;
    }
};