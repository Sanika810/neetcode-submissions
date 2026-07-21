class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int left = 0;
        int right = n - 1;
        while(left < right)
        {
            char l = tolower(s[left]);
            char r = tolower(s[right]);
            while(left < right && !isalnum(l))
            {
                left++;
                l = tolower(s[left]);
            }
                
            while(right > left && !isalnum(r))
            {
                right--;
                r = tolower(s[right]);
            }
                
            if(l != r)
                return false;
            left++;
            right--;
        }
        return true;
    }
};
