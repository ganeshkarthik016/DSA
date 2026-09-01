#include <bits/stdc++.h>
using namespace std;

vector<int> buildLPS(string pat)
{
    int m = pat.size();
    vector<int> lps(m, 0);

    int len = 0;

    for (int i = 1; i < m;)
    {

        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {

            if (len)
                len = lps[len - 1];
            else
                i++;
        }
    }

    return lps;
}

vector<int> KMP(string text, string pat)
{

    vector<int> ans;
    vector<int> lps = buildLPS(pat);

    int i = 0;
    int j = 0;

    while (i < text.size())
    {

        if (text[i] == pat[j])
        {
            i++;
            j++;
        }

        if (j == pat.size())
        {
            ans.push_back(i - j);
            j = lps[j - 1];
        }

        else if (i < text.size() && text[i] != pat[j])
        {

            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return ans;
}

int main()
{
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    vector<int> ans = KMP(text, pattern);

    for (int x : ans)
        cout << x << " ";
}