class Solution {
public:
    double binExp(double x,int y)
    {
        if(y==0)
            return 1;
        double num=binExp(x,y/2);
        double sqre=num*num;
        return y&1?sqre*x:sqre;
    }
    
    double myPow(double x, int n) {
        return n>=0?binExp(x,n):1/binExp(x,n);
    }
};
