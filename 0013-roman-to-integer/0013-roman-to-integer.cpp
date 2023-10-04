class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp = {
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };
        int n=s.size();
        bool check=false;
        int ans=0;
        for(int i=0;i<n;i++){
            if(mp[s[i]]<mp[s[i+1]]){
                ans-=mp[s[i]];
            }
            else{
                ans+=mp[s[i]];
            }
        }
        return ans;
        // for(int i=0;i<n;i++){
        //     if(i==n-1){
        //         check=true;
        //         break;
        //     }
        //     if(s[i]=='I'){
        //         if(s[i+1]=='V'){
        //             ans+=mp['IV'];
        //             i++;
        //         }
        //         else if(s[i+1]=='X'){
        //             ans+=mp['IX'];
        //             i++;
        //         }
        //         else{
        //             ans+=mp['I'];
        //         }
        //     }
        //     else if(s[i]=='X'){
        //         if(s[i+1]=='L'){
        //             ans+=mp['XL'];
        //             i++;
        //         }
        //         else if(s[i+1]=='C'){
        //             ans+=mp['XC'];
        //             i++;
        //         }
        //         else{
        //             ans+=mp['X'];
        //         }
        //     }
        //     else if(s[i]=='C'){
        //         if(s[i+1]=='D'){
        //             ans+=mp['CD'];
        //             i++;
        //         }
        //         else if(s[i+1]=='M'){
        //             ans+=mp['CM'];
        //             i++;
        //         }
        //         else{
        //             ans+=mp['C'];
        //         }
        //     }
        //     else{
        //         ans+=mp[s[i]];
        //     }
        // }
        // if(check==true) ans+=mp[s[n-1]];
        // return ans;

        
    }
};