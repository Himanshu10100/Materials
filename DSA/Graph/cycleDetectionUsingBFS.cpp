#include <bits/stdc++.h>

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i].first - 1;
    int v = edges[i].second - 1;

    adj[u].push_back(v);
  }

  vector<int> indegree(n);
  for (auto i : adj)
  {
    for (auto j : i.second)
    {
      indegree[j]++;
    }
  }

  unordered_map<int, bool> visited;
  queue<int> q;

  for (int i = 0; i < indegree.size(); i++)
  {
    if (indegree[i] == 0)
      q.push(i);
  }

  int cnt = 0;
  while (!q.empty())
  {
    int front = q.front();
    q.pop();

    cnt++;

    for (auto neighbour : adj[front])
    {
      if (!visited[neighbour])
      {
        indegree[neighbour]--;

        if (indegree[neighbour] == 0)
          q.push(neighbour);
      }
    }
  }

  if (cnt == n)
    return false;

  return true;
}
/*
used same kanh's algorithem here
only difference is count cnt for number of node visited...
if count is same as number of node given then no cycle
else cycle present

https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
*/