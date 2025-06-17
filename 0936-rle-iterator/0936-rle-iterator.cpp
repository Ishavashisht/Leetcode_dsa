class RLEIterator {
public:
    int index;
    vector<int>encoded;
    RLEIterator(vector<int>& encoding) {
        encoded=encoding;
     index=0;
    }
    
    int next(int n) {
      while(index<encoded.size()){
        int freq=encoded[index];
        int val=encoded[index+1];
        if(n>freq){
            n-=freq;
            encoded[index]=0;
            index+=2;
        }
        else {
            encoded[index]-=n;
            return val;
        }
                
      } 
      return -1; 
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */