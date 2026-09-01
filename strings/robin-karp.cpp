#include <bits/stdc++.h>
using namespace std;

const int BASE = 256;
const int MOD = 101; // Small prime for demonstration

vector<int> rabinKarp(string text, string pattern)
{
    vector<int> ans;
    int n = text.size();
    int m = pattern.size();

    int h = 1;
    for (int i = 0; i < m - 1; i++)
        h = (h * BASE) % MOD;

    int pHash = 0, tHash = 0;

    // Initial hashes
    for (int i = 0; i < m; i++)
    {
        pHash = (BASE * pHash + pattern[i]) % MOD;
        tHash = (BASE * tHash + text[i]) % MOD;
    }

    for (int i = 0; i <= n - m; i++)
    {

        if (pHash == tHash)
        {
            int j = 0;
            while (j < m && text[i + j] == pattern[j])
                j++;

            if (j == m)
                ans.push_back(i);
        }

        if (i < n - m)
        {
            tHash = (BASE * (tHash - text[i] * h) + text[i + m]) % MOD;

            if (tHash < 0)
                tHash += MOD;
        }
    }

    return ans;
}

int main()
{
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";

    vector<int> ans = rabinKarp(text, pattern);

    for (int x : ans)
        cout << x << " ";
}