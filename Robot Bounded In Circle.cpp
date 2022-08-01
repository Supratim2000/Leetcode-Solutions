class Solution {
public:
    bool isRobotBounded(string instructions) {
        int n=instructions.size();
        vector<int> loc(2,0);
        int dir=1;
        for(int i=0;i<n;i++)
        {
            if(instructions[i]=='G')
            {
                if(dir==1)
                    loc[1]=loc[1]+1;
                else if(dir==2)
                    loc[0]=loc[0]+1;
                else if(dir==3)
                    loc[1]=loc[1]-1;
                else
                    loc[0]=loc[0]-1;
            }
            else if(instructions[i]=='L')
            {
                dir--;
                if(dir==0)
                    dir=4;
            }
            else
            {
                dir++;
                if(dir==5)
                    dir=1;
            }
        }
        if(loc[0]==0 && loc[1]==0)
                return true;
        else if(dir==1)
            return false;
        else
            return true;
    }
};
