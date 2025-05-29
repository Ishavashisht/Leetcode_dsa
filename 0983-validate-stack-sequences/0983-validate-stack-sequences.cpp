class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        stack<int>st;
     //   st.push(pushed[0]);
     int l=0;
        for(int i=0;i<pushed.size();i++){
            st.push(pushed[i]);
while(!st.empty() &&  st.top()==popped[l]){
    st.pop();
    l++;
//next ele to be checked 
}
        }
        return st.empty();
        
    }
};