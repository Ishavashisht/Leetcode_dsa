class Solution {
public:
vector<int>findOccurrences(const string&s,const string&pattern){
vector<int>indics;
int n=s.length();
int m=pattern.length();
for(int i=0;i<=n-m;i++){
if(s.substr(i,m)==pattern){
indics.push_back(i);
}
}
return indics;
}

vector<int> beautifulIndices(string s, string a, string b, int k) {
vector<int>aIndices=findOccurrences(s,a);
vector<int>bIndices=findOccurrences(s,b);
vector<int>result;
sort(bIndices.begin(),bIndices.end());
for(int i:aIndices){ 
auto it=lower_bound(bIndices.begin(),bIndices.end(),i-k);
while(it!=bIndices.end() && abs(*it -i)<=k){  
result.push_back(i);
break;

    }
}
    return result;
}
};