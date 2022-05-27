//Time Complexity:- O(n)+O(n)
//Space complexity:- O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int ans=0;
        int l=0,h=0;
        unordered_set<char> st;
        while(h<n)
        {
            if(st.find(s[h])==st.end())
            {
                ans=max(ans,h-l+1);
                st.insert(s[h++]);
            }
            else
            {
                while(s[l]!=s[h])
                    st.erase(s[l++]);
                l++;
                st.erase(s[h]);
            }
        }
        return ans;
    }
};

//Time Complexity:- O(n)
//Space complexity:- O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int ans=0;
        int l=0,h=0;
        unordered_map<char,int> mp;
        while(h<n)
        {
            if(mp.find(s[h])==mp.end())
                mp.insert({s[h],h});
            else if(mp[s[h]]>=l)
                    l=mp[s[h]]+1;
            mp[s[h]]=h;
            ans=max(ans,h-l+1);
            h++;
        }
        return ans;
    }
};
