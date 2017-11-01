///maximum number of jobs that can be performed on a single machine
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
    jobs.push_back(make_pair(1,4));
    jobs.push_back(make_pair(6,8));
    jobs.push_back(make_pair(3,6));
    jobs.push_back(make_pair(4,5));

    sort(jobs.begin(),jobs.end(),sortbysec);

    int count = 0;
    int running = jobs[0].second;
    count++;
    for(int i=1;i<jobs.size();i++)
    {
        if(running <= jobs[i].first)
        {
            count++;
            running = jobs[i].second;
        }
    }
    cout<<count<<endl;
    return 0;
}
