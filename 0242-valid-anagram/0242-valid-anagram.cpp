class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        // feq array to store character count
        int freq[26] = {0};

        // count freq of each character
        for(int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++; // incr freq for each character
        }

        // Decr freq of each character in t string
        for(int i = 0; i < t.length();i++)
        {
            freq[t[i] - 'a']--; // dec freq for each character
        }

        // check all freq are zero if any are not zero they are not anagrams
        for(int i = 0; i < 26; i++)
        {
          if(freq[i] != 0) return false;
        }
        return true;
    }
};