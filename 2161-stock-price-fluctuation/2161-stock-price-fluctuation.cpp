class StockPrice {
public:
unordered_map<int,int>timestamp_to_price;
map<int,int>price_freq;
int latest_timestamp;

    StockPrice() {
        latest_timestamp=0;
    }
    
    void update(int timestamp, int price) {
       if (timestamp_to_price.count(timestamp)) {
int old_price=timestamp_to_price[timestamp];
price_freq[old_price]--;
if(price_freq[old_price]==0){
price_freq.erase(old_price);
}
}
timestamp_to_price[timestamp]=price;
price_freq[price]++;
 latest_timestamp=max( latest_timestamp,timestamp);
 
    }
    
    int current() {
      return timestamp_to_price[ latest_timestamp];
  
    }
    
    int maximum() {
      return price_freq.rbegin()->first;  
    }
    
    int minimum() {
        return price_freq.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */