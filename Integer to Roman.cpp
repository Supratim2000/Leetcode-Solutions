class Solution {
public:
    string intToRoman(int num) {
        vector<int> dig {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string> rom {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        string ans="";
        int i=12;
        while(num)
        {
            while(num>=dig[i])
            {
                ans+=rom[i];
                num-=dig[i];
            }
            i--;
        }
        return ans;
    }
};
