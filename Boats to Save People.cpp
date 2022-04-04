class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n=people.size();
        int count=0;
        int i=0;
        int j=n-1;
        while(i<=j)
        {
            if(i==j)
            {
                if(people[i]<=limit)
                    count++;
                break;
            }
            else if(people[i]+people[j]>limit)
            {
                if(people[i]<=limit)
                    count++;
                j--;
            }
            else
            {
                i++;
                j--;
                count++;
            }
        }
        return count;
    }
};
