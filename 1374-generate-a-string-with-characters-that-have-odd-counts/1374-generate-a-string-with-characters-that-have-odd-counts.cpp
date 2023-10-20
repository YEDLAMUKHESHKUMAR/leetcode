class Solution {
public:
    string generateTheString(int n) {
        string s="";
        for(int i=1;i<=n-1;i++){
            s+='a';
        }
        if(n % 2 == 0){
            s+='b';
        }
        else{
            s+='a';
        }
        return s;
    }
};