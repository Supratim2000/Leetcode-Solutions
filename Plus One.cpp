class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if(digits.at(n-1)!=9)
            digits.at(n-1)+=1;
        else
        {
            int x=n-1;
            while(x>=0 && digits.at(x)==9)
            {
                digits.at(x)=0;
                x--;
            }
            if(x==-1)
            {
                digits.at(0)=1;
                digits.push_back(0);
            }
            else
                digits.at(x)+=1;
        }
        return digits;
    }
};
