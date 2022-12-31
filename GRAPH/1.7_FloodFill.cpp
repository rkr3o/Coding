class Solution {
public:
    
    void bfs(vector<vector<int>>image , int row , int col , int color , int initialColor , vector<vector<int>>&ans)
    {
         
        int n = image.size();
        int m = image[0].size();
           queue<pair<int,int>>q ;
           q.push({row , col});
           ans[row][col]=color ;
           
           while(!q.empty())
           {
                int row = q.front().first ;
                int col = q.front().second;
                q.pop();
                
                int drow[]={-1,0,+1,0};
                int dcol[]={0,+1,0,-1};
                 
                for(int i = 0 ; i < 4 ; i++)
                {
                     int nrow = row+drow[i];
                     int ncol = col + dcol[i];
                    
                     if(nrow>=0 and nrow < n and ncol >=0 and ncol < m and image[nrow][ncol]==initialColor and ans[nrow][ncol]!=color )
                     {
                          q.push({nrow , ncol});
                          ans[nrow][ncol]=color ;
                     }
                }
           }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        
        int n = image.size();
        int m = image[0].size();
        
        int initialCol = image[sr][sc];
        vector<vector<int>>ans = image;
        
        bfs(image , sr , sc , color , initialCol , ans );
        
        
        return ans;
    }
};