class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
       sort(clips.begin(),clips.end());
       int res=0,i=0,n=clips.size();
       int currEnd=0,farthest=0;
       while(currEnd<time){
       while(i<n && clips[i][0]<=currEnd){
        farthest=max(farthest,clips[i][1]);
        i++;
       } 
       if(farthest==currEnd)return -1;
       currEnd=farthest;
       res++;
    }
    return res;
}
};