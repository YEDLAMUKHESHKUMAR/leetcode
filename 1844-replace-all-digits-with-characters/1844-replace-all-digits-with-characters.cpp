class Solution {
public:
    string replaceDigits(string s) {
        vector<char> ans = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        int n=s.size();
        for(int i=1;i<n;i+=2){
            int num=s[i]-'0';
            int ch=s[i-1]-'a';
            int sum = num + ch;
            s[i]=ans[sum];
        }
        return s;
    }
};