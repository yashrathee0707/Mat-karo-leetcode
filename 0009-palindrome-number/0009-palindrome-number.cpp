class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        int answer = 0;
        int dup = x;
        while(x != 0){ 
            int last = x % 10;
            if (answer > INT_MAX / 10) {
                return false;
            }
            answer = (answer * 10) + last;
            x = x / 10;
        }
        if(dup == answer){
            return true;
        }
        else{
            return false;
        }
    }
};