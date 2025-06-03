class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        sort(people.begin(),people.end(),[](const vector<int>&a,const vector<int>&b){
            if(a[0]==b[0]){
            return a[1]<b[1];
            }
            return a[0]>b[0];
        });
        vector<vector<int>>q;
        for(const auto&p:people){
            q.insert(q.begin()+p[1],p);
        }
        return q;
            

        
    }
};