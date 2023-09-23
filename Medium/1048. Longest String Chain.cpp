class Solution 
{
    private:
    static bool comp(string &s1, string &s2)
    {
        return (s1.length() < s2.length());
    }

    bool isValid(string &s1, string &s2)
    {
        if(s1.length() == s2.length() + 1)
        {
            int s1Pointer = 0, s2Pointer = 0, length = s1.length();

            while(s1Pointer < length)
            {
                if(s1[s1Pointer] == s2[s2Pointer])
                {
                    s1Pointer++;
                    s2Pointer++;
                }
                else s1Pointer++;
            }

            if(s1Pointer == length && s2Pointer == length - 1) return true;
        }
        return false;
    }

    public:
    int longestStrChain(vector <string>& words) 
    {
        sort(words.begin(), words.end(), comp);

        int noOfWords = words.size(), maxLength = 1, i = 0, j;
        vector <int> dp(noOfWords, 1);

        for(; i < noOfWords; i++)
        {
            for(j = 0; j < i; j++)
            {
                if(isValid(words[i], words[j]) && dp[j] + 1 > dp[i]) dp[i] = 1 + dp[j];
            }

            maxLength = max(maxLength, dp[i]);
        }
        
        return maxLength;
    }
};