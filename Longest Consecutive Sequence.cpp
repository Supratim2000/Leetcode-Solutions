//Using DSU
//Time Complexity:- O(n), Space Complexity:- O(n)
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
    
        void Union(int u, int v)
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
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        int maxSizeComp=INT_MIN;
        DSU* dsu=new DSU(n);
        unordered_map<int,int> valToIndx;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            if(valToIndx.find(nums[i])==valToIndx.end())
            {
                valToIndx[nums[i]]=i;
                if(valToIndx.find(nums[i]+1)!=valToIndx.end())
                    dsu->Union(i,valToIndx[nums[i]+1]);
                if(valToIndx.find(nums[i]-1)!=valToIndx.end())
                    dsu->Union(i,valToIndx[nums[i]-1]);
            }
        }
        for(int i=0;i<n;i++)
            mp[dsu->find(i)]++;
        for(auto x: mp)
            maxSizeComp=max(maxSizeComp,x.second);
        return maxSizeComp;
    }
};

//Using unordered_set
//Time Complexity:- O(n), Space Complexity:- O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int lcs=INT_MIN;
        if(n==0)
            return 0;
        unordered_set<int> st;
        for(int i=0;i<n;i++)
            st.insert(nums[i]);
        for(auto x: st)
        {
            if(st.find(x-1)==st.end())
            {
                int cur=x;
                int ccs=1;
                while(st.find(cur+1)!=st.end())
                {
                    ccs++;
                    cur++;
                }
                lcs=max(lcs,ccs);
                ccs=0;
            }
        }
        return lcs;
    }
};
