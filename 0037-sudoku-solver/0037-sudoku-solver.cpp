class Solution {
public:
    bool isSafe(int row,int col,char value,vector<vector<char>>&board){
        //same row vo number na ho 
        //same col m vo number na ho 
        //same 3*3 matrix m vo number na ho 
        int n=board.size();
        //row check
        for(int i=0;i<n;i++){
            if(board[row][i]==value){
                return false;
            }
        }
        //col check 
        for(int i=0;i<n;i++){
            if(board[i][col]==value){
                return false;
            }
        }
        //3*3 box ka check 
        for(int i=0;i<n;i++){
            //yaha pr hi glti hoti h 
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==value)
            return false;

        }
        //place is safe 
        return true;
    }
    bool solveHelper(vector<vector<char>>& board){
         int n=board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //check empty cell
                if(board[i][j]=='.'){
                    //try karo 1->9 insert krna 
                    for(char ch='1';ch<='9';ch++){
                        if(isSafe(i,j,ch,board)){
                            //place akrdo 
                            board[i][j]=ch;
                            //recursion 
                            bool recursionKaAns=solveHelper(board);
                            if(recursionKaAns==true){
                                return true;
                            }
                            else{
                                //then the ch we had inserted is wrong 
                                //then backtrack
                                board[i][j]='.';

                            }
                        }
                    }
                    //kisiki bhi case m ans ni aaya 
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
       solveHelper(board);
    }
};