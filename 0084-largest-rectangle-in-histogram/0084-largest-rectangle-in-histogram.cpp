class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==1) return heights[0];
        stack<int> st;
        vector<int> left(n,0);
        vector<int> right(n,n);
        // st.push(0);
        // left[0]=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()) left[i]=0;
            else{
                left[i]=st.top()+1;
            }
            st.push(i);
        }
        st = stack<int> ();
        // right[n-1]=;
        // st.push(n-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()) right[i]=n-1;
            else{
                right[i]=st.top()-1;
            }
            st.push(i);
        }
        int maximumArea = 0;
        for(int i=0;i<n;i++){
            int currentElement = heights[i];
            maximumArea=max(maximumArea,currentElement*( right[i] - left[i] + 1));
        }
        return maximumArea;
    }
};