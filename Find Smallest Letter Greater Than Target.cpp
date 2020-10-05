class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters[ letters.size() - 1 ] <= target)
                return letters[0];
        long long low = 0;
        long long high = letters.size() - 1;
        char ans;
        while(low<=high)
        {
            long long mid = low + (high - low)/2;
            if(letters[mid]>target)
            {
                ans=letters[mid];
                high = mid -1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};
