class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> grid{
            {0,0,0},
            {0,0,0},
            {0,0,0}
        };
        
        for(int i=0;i<moves.size();i++)
            i&1?grid[moves[i][0]][moves[i][1]]=1:grid[moves[i][0]][moves[i][1]]=2;
        
        //Check Row
        for(int i=0;i<3;i++)
            if(grid[i][0]==grid[i][1] && grid[i][1]==grid[i][2] && grid[i][0]!=0)
                return grid[i][0]==2?"A":"B";
        
        //Check Column
        for(int i=0;i<3;i++)
            if(grid[0][i]==grid[1][i] && grid[1][i]==grid[2][i] && grid[0][i]!=0)
                return grid[0][i]==2?"A":"B";
        
        //Check Diagonal
        if(grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2] && grid[0][0]!=0)
            return grid[0][0]==2?"A":"B";
        if(grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0] && grid[0][2]!=0)
            return grid[0][2]==2?"A":"B";
        return moves.size()==9?"Draw":"Pending";
    }
};
