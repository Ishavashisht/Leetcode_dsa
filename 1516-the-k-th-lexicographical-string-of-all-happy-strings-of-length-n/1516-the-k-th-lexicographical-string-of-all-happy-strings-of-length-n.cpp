class Solution {
public:
    void generate(int n,string &path,vector<string>&res){
        if(path.size()==n)
        {res.push_back(path);
        return;
        }
        for(char ch:{'a','b','c'}){
            if(!path.empty() && path.back()==ch)continue;
            path.push_back(ch);
            generate(n,path,res);
            path.pop_back();
        }
    }
    string getHappyString(int n, int k) {
       vector<string>res;
       string path="";
       generate(n,path,res);
       if(res.size()<k)return "";
       return res[k-1]; 
    }
};