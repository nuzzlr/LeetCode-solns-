class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int a_count = 0;

        
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a_count++;
        }

        int b_count = 0;
        int min_deletions = n;

       
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a_count--;
            min_deletions = min(min_deletions, a_count + b_count);
            if (s[i] == 'b') b_count++;
        }

        return min_deletions;
    }
};