class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
if(n==0){
return 0;
}
for(int i=0;i<n;i++){
if(books[i][0]> shelfWidth){
return -1;
}}
if(n==1){
return books[0][1];

}
vector<int>dp(n+1,0);
for(int i=n-1;i>=0;--i){
int totalthickness=0;
int max_height=0;
int minheight=INT_MAX;
for(int j=i;j<n;j++){
totalthickness+=books[j][0];
if(totalthickness> shelfWidth){
break;
}
max_height=max(max_height,books[j][1]);
int curr=max_height+dp[j+1];
minheight=min(minheight,curr);
}
dp[i]=minheight;
}
return dp[0];

    }
};