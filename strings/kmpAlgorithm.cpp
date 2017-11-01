#include<bits/stdc++.h>
using namespace std;

void findLps(string pattern,int *lps)
{
    int j = 0;
    int i = 1;
    int m = pattern.length();
    lps[0] = 0;
    while(i<m)
    {
        if(pattern[i] == pattern[j])
        {
            lps[i] = ++j;
            i++;
        }
        else
        {
            if(j != 0)
            {
                j = lps[j-1];
            }
            else
            {
                lps[i] = 0;
                i = i + 1;
            }
        }
    }
    for(i=0;i<m;i++)
    {
        cout<<lps[i]<<" ";
    }
    cout<<endl;
}

void kmpAlgorithm(string text,string pattern)
{
    int j = 0;
    int i = 0;
    int lps[pattern.length()];
    findLps(pattern,lps);
    int n = text.length();
    while(i<n)
    {
        if(text[i] == pattern[j])
        {
            i++;
            j++;
        }
        if(j == pattern.length())
        {
            cout<<"pattern found at : "<<i-j<<endl;
            j = lps[j - 1];
        }
        else if(i < n && pattern[j] != text[i])
        {
            if(j == 0)
            {
                i = i + 1;
            }
            else
            {
                j = lps[j - 1];
            }
        }
    }
}

int main()
{
    string text, pattern;
    text = "bananasdfjbanabanabanana";
    pattern = "banana";
    kmpAlgorithm(text,pattern);
    return 0;
}
