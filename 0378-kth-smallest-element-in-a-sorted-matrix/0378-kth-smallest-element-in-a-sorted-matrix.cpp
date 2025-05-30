class Solution {
public:
    int countLessOrEqual(vector<vector<int>>& matrix,int target){
         int m=matrix.size();
        int n=matrix[0].size();
        int count=0;
        int row=m-1;//start from bottom
        int col=0;
        while(row>=0 && col<n){
            if(matrix[row][col]<=target){
                count+=row+1;
                col++;
            }
            else{
                row--;//move up a row
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();
        int low=matrix[0][0];
        int high=matrix[m-1][n-1];
        while(low<high){
            int mid=low+(high-low)/2;
            int count=countLessOrEqual(matrix,mid);
            //till the time k==0 find matrix[row][col] and then return it 
if(count>=k){
    high=mid;
}
else{
    low=mid+1;
}

        }
        return low;
    }
};