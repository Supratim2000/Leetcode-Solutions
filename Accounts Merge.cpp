class DSU {
    public:
        vector<int> parent;
        vector<int> rank;
        DSU(int v)
        {
            for(int i=0;i<=v;i++)
            {
                parent.push_back(i);
                rank.push_back(1);
            }
        }
        
        int find(int v)
        {
            if(v==parent[v])
                return v;
            int leader=find(parent[v]);
            parent[v]=leader;
            return leader;
        }
    
        void _union(int u, int v)
        {
            int lu=find(u);
            int lv=find(v);
            if(lu!=lv)
            {
                if(rank[lu]>rank[lv])
                    parent[lv]=lu;
                else if(rank[lu]<rank[lv])
                    parent[lu]=lv;
                else
                {
                    parent[lv]=lu;
                    rank[lu]++;
                }
            }
        }    
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
        map<int, set<string>> intAns;
        int n=accounts.size();
        //int m=accounts.at(0).size();

        /*
        johnnybravo@mail.com 5
        mary@mail.com 4
        john00@mail.com 3
        john_newyork@mail.com 2
        johnsmith@mail.com 1
        */
        unordered_map<string,int> mpString;
        unordered_map<int,string> mpStringRev;



        /*
        5 John
        4 Mary
        3 John
        2 John
        1 John
        */
        unordered_map<int,string> mpNum;
        int count=1;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts.at(i).size();j++)
            {
                if(mpString.find(accounts[i][j])==mpString.end())
                {
                    mpString[accounts[i][j]]=count;
                    mpStringRev[count]=accounts[i][j];
                    count++;
                }
            }
        }

        DSU* dsu=new DSU(count+1);

        for(auto x: mpString)
            cout<<x.first<<" "<<x.second<<endl;
        cout<<endl<<endl;
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts.at(i).size();j++)
            {
                mpNum[mpString[accounts[i][j]]]=accounts[i][0];
            }
        }

        for(auto x: mpNum)
            cout<<x.first<<" "<<x.second<<endl;
        cout<<endl<<endl;


        for(int i=0;i<n;i++)
        {
            if(accounts.at(i).size()>2)
            {
                for(int j=2;j<accounts.at(i).size();j++)
                {
                    dsu->_union(mpString[accounts[i][j-1]],mpString[accounts[i][j]]);
                }
            }
        }

        for(int i=1;i<=count-1;i++)
            cout<<dsu->find(i)<<" ";
        cout<<endl;

        for(int i=1;i<=count-1;i++)
        {

            intAns[dsu->find(i)].insert(mpStringRev[i]);
        }

        for(auto x: intAns)
        {
            cout<<x.first<<"->";
            for(auto y: x.second)
                cout<<y<<" ";
            cout<<endl;
        }

        for(auto x: intAns)
        {
            vector<string> temp;
            temp.push_back(mpNum[x.first]);
            //cout<<x.first<<"->";
            for(auto y: x.second)
            {
                temp.push_back(y);
            }
            ans.push_back(temp);
        }

        return ans;
        
    }
};
