class Solution {
public:
   string makeKey(int pos,int speed){
    return to_string(pos)+","+to_string(speed);
   }
    int racecar(int target) {
      queue<tuple<int,int,int>>q;
q.push({0,1,0});
unordered_set<string>visited;
visited.insert(makeKey(0,1));
while(!q.empty()){
auto[pos,speed,steps]=q.front();
q.pop();
if(pos==target)return steps;
//A
int newPos=pos+speed; 
int newSpeed=speed*2;
string keyA=makeKey(newPos,newSpeed);
if(abs(newPos)<=2*target && visited.find(keyA)==visited.end()){
visited.insert(keyA); 
q.push({newPos,newSpeed,steps+1});
}
//R
int reverseSpeed=speed>0 ?-1 :1; 
string keyR=makeKey(pos,reverseSpeed);
if(visited.find(keyR)==visited.end()){
visited.insert(keyR);
q.push({pos,reverseSpeed,steps+1}); 
}
}
return -1;
}
  
    
};