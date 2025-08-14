class Solution {
public:
 
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<pair<int,int>>dirs={{-1,-1},{-1,0},{1,0},{0,-1},{0,1},{1,1},{-1,1},{1,-1}};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int liveNeigbhor=0;
                for(auto&d:dirs){
                    int ni=i+d.first;
                    int nj=j+d.second;
                    if(ni>=0 && ni<m && nj>=0 && nj<n ){
                        if(abs(board[ni][nj])==1){
                            liveNeigbhor++;


                        }
                    }
                }
                if(board[i][j]==1){
                    if(liveNeigbhor<2 ||liveNeigbhor>3){
                        board[i][j]=-1;//live to dead
                    }
                }
                    else{
                        if(liveNeigbhor==3){
                            board[i][j]=2;//dead to live
                        }
                    }
                }


            
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                   if (board[i][j] > 0) board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
    }
};