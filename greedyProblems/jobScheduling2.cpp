///minimum number of machines required to perform all jobs
///implementation using linear search
///O(n logn) when depth << n
#include<bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
int main()
{
    vector<pair<int,int> > jobs;
    jobs.push_back(make_pair(1,3));
    jobs.push_back(make_pair(2,5));
    jobs.push_back(make_pair(6,7));
    jobs.push_back(make_pair(4,8));

    sort(jobs.begin(),jobs.end());

    vector<int> machine;
    int depth = 0;
    machine.push_back(jobs[0].second);
    depth++;
    for(int i=1;i<jobs.size();i++)
    {
        int j=0;
        for(;j<machine.size();j++)
        {
            if(machine[j] <= jobs[i].first)
            {
                machine[j] = jobs[i].second;
                break;
            }
        }
        if(j == machine.size())
        {
            depth++;
            machine.push_back(jobs[i].second);
        }
    }
    cout<<depth<<endl;
    return 0;
}
