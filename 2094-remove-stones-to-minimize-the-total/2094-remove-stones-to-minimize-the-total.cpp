class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum=0;
       if (piles.empty()) return 0;
        priority_queue<int>maxheap;
        for(int i=0;i<piles.size();i++){
            maxheap.push(piles[i]);
        }
        while(k--){
           int top=maxheap.top();
          
            maxheap.pop();
            top-=top/2;
            maxheap.push(top);
        
        }
        while(!maxheap.empty())
          {  sum+=maxheap.top();
             maxheap.pop();}

        
        return sum;
    }
};