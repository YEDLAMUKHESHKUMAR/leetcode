class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        int equal = 0;
        // if(n1<2 || n2<2 || n3<2) return -1;
        int i , n;
        n = min(n1,min(n2,n3));
        for(i=0;i<n;i++){
            if(s1[i]==s2[i] && s2[i]==s3[i]){
                equal++;
            }
            else break;
        }
        if(equal<1) return -1;
        int operations = (n1-i)+(n2-i)+(n3-i);
        return operations;
    }
};