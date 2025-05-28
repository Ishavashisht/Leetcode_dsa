class Solution {
public:
int kadane(vector<int>&arr,int k){
    int curr_sum=0,max_sum=INT_MIN;
    set<int>s;
    s.insert(0);
    for(int i=0;i<arr.size();i++){
        curr_sum+=arr[i];
        auto it =s.lower_bound(curr_sum-k);
        if(it!=s.end()){
            max_sum=max(curr_sum- *it,max_sum);
        }
        s.insert(curr_sum);
        
    }
    return max_sum;
}
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();
        int curr_sum=0;int max_sum=INT_MIN;
        for(int col_start=0;col_start<n;col_start++ ){
            vector<int>temp(m,0);
            for(int col_end=col_start;col_end<n;col_end++){
                for(int row=0;row<m;row++){
                    temp[row]+=matrix[row][col_end];
                }
                    curr_sum=kadane(temp,k);
                max_sum=max(max_sum,curr_sum);
            }
        }
return max_sum;
    }
};