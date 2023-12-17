class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int m=grid.size();
        long long n=m*m;
        long long s=n*(n+1)/2;
        long long s2=(n*(n+1)*(2*n+1))/6;
        long long sn=0;
        long long sn2=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<m;j++) {
                sn+=grid.at(i).at(j);
                sn2+=grid.at(i).at(j)*grid.at(i).at(j);
            }
        }
        long long misMinRep=s-sn;
        long long misPlusRep=(s2-sn2)/misMinRep;
        int missing=(misMinRep+misPlusRep)/2;
        int repeating=missing-misMinRep;
        return {repeating,missing};
    }
};
