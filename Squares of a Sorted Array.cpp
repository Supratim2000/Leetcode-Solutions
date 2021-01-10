class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int sz = nums.size();
        vector<int> v(sz);
        if(nums.at(0)>=0)
        {
            for(int i=0;i<nums.size();i++)
                v[i]=nums.at(i) * nums.at(i);
            return v;
        }
        else if(nums.at(nums.size()-1)<0)
        {
            int x=0;
            for(int i=nums.size()-1;i>=0;i--) 
            {
                v[i]=nums.at(x) * nums.at(x);
                x++;
            }
            return v;
        }
        else
        {
            int i=0;
            int j=nums.size()-1;
            int count=nums.size()-1;
            while(j>=i)
            {
                if(abs(nums.at(j)) > abs(nums.at(i)))
                {
                    v[count--]=nums.at(j) * nums.at(j);
                    j--;
                }
                else
                {
                    v[count--]=nums.at(i) * nums.at(i);
                    i++;
                }
            }
            return v;
        } 
    }
};
