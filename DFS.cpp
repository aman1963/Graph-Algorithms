#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    map<int,list<int>> mp;
public:
    void addEdge(int a,int b)
    {
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    void printEdge()
    {
        for(auto it:mp)
        {
            cout<<it.first<<"-> ";
            for(auto it2:it.second)
            {
                cout<<it2<<" ";
            }
            cout<<"\n";
        }
    }
    void dfs_helper(int src,map<int,bool> &visited)
    {
        visited[src]=true;
        list<int> nbrs = mp[src];
        cout<<src<<" ";
        for(auto it:mp[src])
        {
            if(!visited[it])
            {
                dfs_helper(it,visited);
            }
        }
    }
    void dfs(int src)
    {
        map<int,bool> visited;
        for(auto it:mp)
        {
            visited[it.first]=false;
        }
        dfs_helper(src,visited);
        cout<<"\n";
    }
    void bfs(int src)
    {

        queue<int> q;
        map<int,bool> visited;
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            cout<<f<<" ";
            list<int> nbrs = mp[f];
            for(auto it:nbrs)
            {
                if(!visited[it])
                {
                    q.push(it);
                    visited[it]=true;
                }
            }
        }
        cout<<"\n";
    }
};
int main()
{
        Graph g;
    g.addEdge(0,1);
      g.addEdge(1,2);
      g.addEdge(0,3);
      g.addEdge(2,3);
      g.addEdge(2,4);
      g.addEdge(4,5);
      g.printEdge();
      g.dfs(0);
}

