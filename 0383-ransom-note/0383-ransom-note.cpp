class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Create an array to count frequency of characters in the magazine
        vector<int> charCount(26, 0);
        
        // Count frequency of characters in the magazine
        for (char c : magazine) {
            charCount[c - 'a']++;
        }
        
        // Check if the magazine has enough characters for the ransom note
        for (char c : ransomNote) {
            if (charCount[c - 'a'] > 0) {
                charCount[c - 'a']--;  // Use one character from the magazine
            } else {
                return false;  // If no characters left for the ransom note, return false
            }
        }
        
        return true;  // All characters were found in the magazine
    }
};
