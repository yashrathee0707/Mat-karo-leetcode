class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs[strs.size() - 1];
        int i = 0;
        
        while(i < first.size() && last.size() && first[i] == last[i]){
            i++;
        }
        return first.substr(0,i);
    }
};