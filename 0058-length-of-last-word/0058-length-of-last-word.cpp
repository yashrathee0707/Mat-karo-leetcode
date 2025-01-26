class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        for(int i=s.length() - 1; i>=0; i--){
            //trailing spaces 
            if(s[i] == ' ' && count > 0){
                break;//if first char encountered
            }
            //count char of last word
            if(s[i] != ' '){
                count++;
            }
        }
        return count;
    }
};
