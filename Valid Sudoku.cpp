//Time complexity:- O(n^2)+O(n^2)+O(n^2), Space Complexity:- O(n)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int a=0,b=0;
        int x=9;
        //Block
        while(x--)
        {
            unordered_set<char> st;
            for(int i=a;i<3+a;i++)
            {
                for(int j=b;j<3+b;j++)
                {
                    if(board[i][j]=='.')
                        continue;
                    if(st.find(board[i][j])!=st.end())
                        return false;
                    else
                        st.insert(board[i][j]);

                }
            }
            b+=3;
            if(b==9)
            {
                b=0;
                a+=3;
            }
        }
        //Row
        for(int i=0;i<9;i++)
        {
            unordered_set<char> st;
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                    continue;
                
                if(st.find(board[i][j])!=st.end())
                    return false;
                else
                    st.insert(board[i][j]);
            }
        }
        //Column
        for(int i=0;i<9;i++)
        {
            unordered_set<char> st;
            for(int j=0;j<9;j++)
            {
                if(board[j][i]=='.')
                    continue;
                
                if(st.find(board[j][i])!=st.end())
                    return false;
                else
                    st.insert(board[j][i]);
            }
        }
        return true;
    }
};

//Time complexity:- O(n^2)+O(n^2)+O(n^2), Space Complexity:- O(1)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int a=0,b=0;
        int x=9;
        //Block
        while(x--)
        {
            int hash=0;
            for(int i=a;i<3+a;i++)
            {
                for(int j=b;j<3+b;j++)
                {
                    if(board[i][j]!='.')
                    {
                        if(((1 << ((board[i][j]-'0')-1)) & hash))
                            return false;
                        else
                            hash=(hash | (1 << ((board[i][j]-'0')-1)));
                    }
                }
            }
            b+=3;
            if(b==9)
            {
                b=0;
                a+=3;
            }
        }
        //Row
        for(int i=0;i<9;i++)
        {
            int hash=0;
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(((1 << ((board[i][j]-'0')-1)) & hash))
                        return false;
                    else
                        hash=(hash | (1 << ((board[i][j]-'0')-1)));
                }
            }
        }
        //Column
        for(int i=0;i<9;i++)
        {
            int hash=0;
            for(int j=0;j<9;j++)
            {
                if(board[j][i]!='.')
                {
                    if(((1 << ((board[j][i]-'0')-1)) & hash))
                        return false;
                    else
                        hash=(hash | (1 << ((board[j][i]-'0')-1)));
                }
                
            }
        }
        return true;
    }
};
