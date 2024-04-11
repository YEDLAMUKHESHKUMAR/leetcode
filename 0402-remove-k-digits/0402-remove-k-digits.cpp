class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        st.push(num[0] );
        int i = 1,n=num.size();
        if(n == k) return "0";
        while(i<n && k>0){
            // int curr = num[i] - '0';
            // 1 4
            while(!st.empty() && i<n && k!=0 && st.top()  >  num[i]  ){
                st.pop();
                // i++;
                k--;
            }
            if(k!=0){
                st.push(num[i]);
                i++;
            }
            else{
                while(i<n){
                    st.push(num[i]);
                    i++;
                }
                break;
            }
        }
        string temp = "";
        string ans = "";
        bool check = false;
        while(!st.empty()){
            // temp = st.top() + temp; // caused MLE :( , reason :  check notes 
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        for(int i = 0;i<temp.size() - k;i++) {
            if(temp[i] == '0' && check == true){
                ans += temp[i];
            }
            else if(temp[i] != '0'){
                ans += temp[i];
                check = true;
            }

        }
        if(ans.size() == 0)return "0";
        return ans;


        // 123456789


    }
};