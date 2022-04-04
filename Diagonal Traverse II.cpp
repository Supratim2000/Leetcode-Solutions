//Using Map
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n=nums.size();
        map<int,vector<int>> dig;
        vector<int> ans;
        for(int i=0;i<n;i++)
            for(int j=0;j<nums[i].size();j++)
                dig[i+j].push_back(nums[i][j]);
        for(auto x: dig)
            for(int i=x.second.size()-1;i>=0;i--)
                ans.push_back(x.second[i]);
        return ans;
    }
};

//Using unordered_map
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int maxKey=-1;
        vector<int> ans;
        unordered_map<int,vector<int>> dig;
        int n=nums.size();
        for(int i=0;i<n;i++)
            for(int j=0;j<nums[i].size();j++)
                maxKey=max(maxKey,i+j);
        for(int i=0;i<n;i++)
            for(int j=0;j<nums[i].size();j++)
                dig[i+j].push_back(nums[i][j]);
        
        for(int i=0;i<=maxKey;i++)
            for(int j=dig[i].size()-1;j>=0;j--)
                ans.push_back(dig[i][j]);
        return ans;
    }
};

//Using Sorting
class Trip {
    public:
    int key;
    int row;
    int val;
    Trip(int key,int row,int val){
        this->key=key;
        this->row=row;
        this->val=val;
    }
};
class Solution {
public:
    static bool comp(Trip a, Trip b)
    {
        if(a.key==b.key)
            return a.row>b.row;
        return a.key<b.key;
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<Trip> temp;
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                Trip t(i+j,i,nums[i][j]);
                temp.push_back(t);   
            }
        }
        sort(temp.begin(),temp.end(),comp);
        for(auto x: temp)
            ans.push_back(x.val);
        return ans;
    }
};
