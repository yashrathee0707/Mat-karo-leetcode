class Solution {
public:
    bool helper(string& s, int left, int right){
        if(left >= right) return true;
        while(left < right && !isalnum(s[left])) left++;
        while(left < right && !isalnum(s[right])) right--;
        if(tolower(s[left]) != tolower(s[right])) return false;
        return helper(s, left+1, right-1);
    }
    bool isPalindrome(string s) {
        return helper(s, 0, s.length()-1);
    }
};