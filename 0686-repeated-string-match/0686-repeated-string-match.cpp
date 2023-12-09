class Solution {
public:
    // int solve(string &str,string &b){
    //     int n = str.size(), m = b.size();
    //     int i = n - 1 , j = m - 1 ;
    //     while(i>=0 && j>=0){
    //         if(str[i] != b[j]) return -1;
    //         i--;
    //         j--;
    //     }
    //     return 1;
    // }
    int repeatedStringMatch(string A, string B) {

        string s="";
        int count = 0;
        while(s.size()<B.size())       // notes 
        {
            s+=A;
            count++;
        }
        if(s.find(B)!=string::npos)
            return count;
        s+=A;
        count++;
        if(s.find(B)!=string::npos)
            return count;
        
        return -1;
        // int n = a.size();
        // int m = b.size();
        // int required = (m * 2 ) / n ;
        // if((m*2) % n!=0) required++;
        // string str;
        // if(m < n){
        //     str+=a;
        //     if(str.find(b)!=string::npos){
        //         return 1;
        //     }
        //     str+=a;
        //     if(str.find(b)!=string::npos){
        //         return 2;
        //     }
        //     return -1;

        // }
        
        // for(int i=0;i<required;i++){
        //     str+=a;
        // }
        // bool check = false;
        // int start = 0; 
        // for(int i=0;i<n;i++){
        //     if(b[0] == a[i]){
        //         check = true;
        //         start = i;
        //         break;
        //     }
        // }
        // if(check == false) return -1;
        // int i = start + 1 , j = 1 ;
        // while(i<str.size() && j<b.size()){
        //     if(str[i]!=b[j]) return -1;
        //     i++;
        //     j++;
        // }
        // i = str.size() - i;
        // required -= (i / n) ;
        // return required;

    }
};