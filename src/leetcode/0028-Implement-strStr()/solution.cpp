#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
            return 0;
        int n = haystack.size() + 1, m = needle.size() + 1;
        char s[n + 1], p[m + 1];
        int nx[m + 1];

        strcpy(s + 1, haystack.c_str());
        strcpy(p + 1, needle.c_str());

        nx[1] = 0;
        for (int i = 2, j = 0; i <= m; i++)
        {
            while (j && p[i] != p[j + 1])
                j = nx[j];
            if (p[i] == p[j + 1])
                j++;
            nx[i] = j;
        }

        for (int i = 1, j = 0; i <= n; i++)
        {
            while (j && s[i] != p[j + 1])
                j = nx[j];
            if (s[i] == p[j + 1])
                j++;
            if (j == m - 1)
            {
                return i - m + 1;
            }
        }

        return -1;
    }

    int strStr2(string haystack, string needle) {
        if (needle.empty()) return 0;

        string s = " " + haystack, p = " " + needle;
        int n = s.size(), m = p.size();
        int nx[m + 1];

        nx[1] = 0;
        for (int i = 2, j = 0; i <= m; i++) {
            while (j && p[i] != p[j+1]) j = nx[j];
            if (p[i] == p[j+1]) j++;
            nx[i] = j;
        }

        for (int i = 1, j = 0; i <= n; i++) {
            while (j && s[i] != p[j+1]) j = nx[j];
            if (s[i] == p[j+1]) j++;
            if (j == m - 1) {
                return i - m + 1;
            }
        }

        return -1;
    }
};

int main()
{
    cout << Solution().strStr2("hello", "ll") << endl;
    cout << Solution().strStr2("abbbbbaabbaabaabbbaaaaabbabbbabbbbbaababaabbaabbbbbababaababbbbaaabbbbabaabaaaabbbbabbbaabbbaabbaaabaabaaaaaaaa", "abbbaababbbabbbabbbbbabaaaaaaabaabaabbbbaabab") << endl;
}