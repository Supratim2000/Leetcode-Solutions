class Solution {
public:
    unordered_set<string> powTwo {
        "1","2","4","8","16","32","64","128","256","512",
        "1024","2048","4096","8192","16384","32768","65536",
        "131072","262144","524288","1048576","2097152","4194304",
        "8388608","16777216","33554432","67108864","134217728","268435456","536870912",
        "1073741824"
    };
    
    bool reorderedPowerOf2(int n) {
        string num=std::to_string(n);
        sort(num.begin(),num.end());
        for(auto x: powTwo)
        {
            if(num.size()==x.size())
            {
                string temp=x;
                sort(temp.begin(),temp.end());
                if(temp==num)
                    return true;
            }
        }
        return false;
    }
};
