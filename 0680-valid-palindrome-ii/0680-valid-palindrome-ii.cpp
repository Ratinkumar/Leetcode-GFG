class Solution {
public:
    bool checkpalindrome(string s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i < j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                //s[i] != s[j] then only one removal allowed
                //check palindrome for remaining string after removal

                //ith character -> remove
                bool ans1 = checkpalindrome(s,i+1,j);

                //jth character -> remove
                bool ans2 = checkpalindrome(s,i,j-1);

                return ans1 || ans2;
            }
        }
        //now if we arrive here means it is valid palindrome
        //then -> 0 removal
        return true;
    }
};