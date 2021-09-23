class Solution {
public:
    bool checkPowersOfThree(int n) {
        if(n==1)
            return true;
        if(n%3==0)
            return checkPowersOfThree(n/3);
        else if((n-2)%3==0)
            return false;
        else
            return checkPowersOfThree(n-1);
    }
};
