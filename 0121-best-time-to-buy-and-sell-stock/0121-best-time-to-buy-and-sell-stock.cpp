class Solution {
public:
    void solve(vector<int>&prices,int i,int &minPrice,int &maxProfit ){
        if(i==prices.size()){
            return ;
        }
        if(prices[i]<minPrice){
            minPrice=prices[i];
        }
        int todaysProfit=prices[i]-minPrice;
        if(todaysProfit>maxProfit){
            maxProfit=todaysProfit;
        }
        solve(prices, i + 1, minPrice, maxProfit);
    }
    int maxProfit(vector<int>& prices) {
     int minprice=INT_MAX;
     int maxProfit=0;
      solve(prices,0,minprice,maxProfit);  
      return maxProfit; 
    }
};