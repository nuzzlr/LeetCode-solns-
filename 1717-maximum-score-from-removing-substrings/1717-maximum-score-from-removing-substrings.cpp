class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        char first_char = (x > y) ? 'a' : 'b';
        char second_char = (x > y) ? 'b' : 'a';
        int first_char_count = 0; 
        int second_char_count = 0;
        if(x < y)swap(x, y);

        for(int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            if(ch != first_char and ch != second_char)
            {
                ans += min(first_char_count, second_char_count) * y;
                first_char_count = 0;
                second_char_count = 0;
            }
            else if(ch == second_char)
            {
                second_char_count++;
                if(first_char_count > 0)
                {
                    ans += x;
                    first_char_count--;
                    second_char_count--;
                }
            }
            else
            {
                first_char_count++;
            }
        }
        ans += min(first_char_count, second_char_count) * y;

        return ans;
    }
};