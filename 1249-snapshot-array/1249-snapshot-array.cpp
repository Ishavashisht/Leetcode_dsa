class SnapshotArray {
public:
    int Tsnap_id=0;
    vector<vector<pair<int,int>>>data;
    SnapshotArray(int length) {
        data.resize(length);
        for(int i=0;i<length;i++){
            data[i].push_back({-1,0});
        }
    }
    
    void set(int index, int val) {
       if (data[index].back().first == Tsnap_id) {
            data[index].back().second = val;
        }
        else{
        data[index].push_back({Tsnap_id,val});
        }
    }
    int snap() {
        return Tsnap_id++;
        
    }
    
    int get(int index, int snap_id) {
        int low=0,high=data[index].size()-1;
        int res=0;
        while(low<=high){
            int mid=low+(high-low)/2;
           if(data[index][mid].first<=snap_id){
             res = data[index][mid].second;
             low=mid+1;
           }
           else{
            high=mid-1;
           }

        }
        return res;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */