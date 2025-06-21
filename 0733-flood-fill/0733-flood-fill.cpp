class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc,int originalColor,int color){
        int m=image.size();
        int n=image[0].size();
           if (sr < 0 || sr >= m || sc < 0 || sc >= n || image[sr][sc] != originalColor) {
            return;
           }
        image[sr][sc]=color;
        dfs(image,sr-1,sc,originalColor,color);
        dfs(image,sr+1,sc,originalColor,color);
        dfs(image,sr,sc-1,originalColor,color);
        dfs(image,sr,sc+1,originalColor,color);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor=image[sr][sc];
        if(originalColor!=color){
            dfs(image,sr,sc,originalColor,color);
        }
        return image;
    }
};