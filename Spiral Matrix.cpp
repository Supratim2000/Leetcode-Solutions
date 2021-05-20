typedef long long ll;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rotate=0;
        ll row=matrix.size();
        ll col=matrix.at(0).size();

        ll a=0;
        ll b=0;
        ll c=row-1;
        ll d=col-1;

        while(b<=d && a<=c)
        {
            if(rotate==0)
            {
                for(int i=b;i<=d;i++)
                    ans.push_back(matrix[a][i]);
                a++;
            }
            else if(rotate==1)
            {
                for(int i=a;i<=c;i++)
                    ans.push_back(matrix[i][d]);
                d--;
            }
            else if(rotate==2)
            {
                for(int i=d;i>=b;i--)
                    ans.push_back(matrix[c][i]);
                c--;
            }
            else
            {
                for(int i=c;i>=a;i--)
                    ans.push_back(matrix[i][b]);
                b++;
            }
            rotate=(rotate+1)%4;
        }
        return ans;
    }
};
