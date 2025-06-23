class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>dead(deadends.begin(),deadends.end());
        unordered_set<string>visited;
        queue<pair<string,int>>q;
        if(dead.count("0000"))return -1;
        q.push({"0000",0});
        visited.insert("0000");
        while(!q.empty()){
            auto[current,depth]=q.front();
            q.pop();
            if(current==target)return depth;
              for (int i = 0; i < 4; ++i) {
                for (int d = -1; d <= 1; d += 2) { // Turn the wheel forward or backward
                    string next = current;
                    next[i] = (next[i] - '0' + d + 10) % 10 + '0'; // Wrap around using modulo
                    
            
            if(!visited.count(next)&& !dead.count(next)){
                q.push({next,depth+1});
                visited.insert(next);
            }
        }
    }
        }
    return -1;
}
};