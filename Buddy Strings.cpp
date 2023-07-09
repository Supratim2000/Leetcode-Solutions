class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        else
        {
            if(s==goal)
            {
                bool isSwapable=false;
                unordered_set<int> pres;
                for(int i=0;i<s.size();i++)
                {
                    if(pres.find(s[i])!=pres.end())
                    {
                        isSwapable=true;
                        break;
                    }
                    pres.insert(s[i]);
                }
                return isSwapable;
            }
            else
            {
                vector<int> misplacedIndex;
                for(int i=0;i<s.size();i++)
                {
                    if(s[i]!=goal[i])
                        misplacedIndex.push_back(i);
                }
                if(misplacedIndex.size()==2 && s[misplacedIndex[0]]==goal[misplacedIndex[1]] && s[misplacedIndex[1]]==goal[misplacedIndex[0]])
                    return true;
                else
                    return false;
            }
        }
        
    }
};
