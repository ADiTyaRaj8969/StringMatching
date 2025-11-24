// Modify an existing string matching algorithm to perform case-insensitive pattern search.
#include <bits/stdc++.h>
using namespace std;

// Function to convert string to lowercase
string toLowerCase(const string& s)
{
    string res = s;
    for (char& c : res)
    {
        c = tolower(c);
    }
    return res;
}

// Case-insensitive Naive String Matching
void searchPattern(const string& text, const string& pattern)
{
    string txt = toLowerCase(text);
    string pat = toLowerCase(pattern);

    int n = txt.length();
    int m = pat.length();

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (txt[i + j] != pat[j])
                break;
        }
        if (j == m)
            cout << "Pattern found at index " << i << endl;
    }
}

int main()
{
    string text = "Hello World, HELLO Universe!";
    string pattern = "hello";
    searchPattern(text, pattern);
    return 0;
}

/*
Time Complexity (TC): O((N-M+1)*M) where N = length of text, M = length of pattern
Space Complexity (SC): O(N+M) due to lowercase conversion of text and pattern
*/
