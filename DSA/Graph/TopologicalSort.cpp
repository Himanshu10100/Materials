DAG : directed asyclic graph

#include <bits/stdc++.h>

      void
      topoDfs(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            topoDfs(i, visited, s, adj);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    stack<int> s;
    unordered_map<int, bool> visited;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topoDfs(i, visited, s, adj);
        }
    }

    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

/*
https://www.naukri.com/code360/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION

Problem statement
A Directed Acyclic Graph (DAG) is a directed graph that contains no cycles.

Topological Sorting of DAG is a linear ordering of vertices such that for every directed edge from vertex ‘u’ to vertex ‘v’, vertex ‘u’ comes before ‘v’ in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.

Given a DAG consisting of ‘V’ vertices and ‘E’ edges, you need to find out any topological sorting of this DAG. Return an array of size ‘V’ representing the topological sort of the vertices of the given DAG.

For example, Consider the DAG shown in the picture.

In this graph, there are directed edges from 0 to 1 and 0 to 3, so 0 should come before 1 and 3. Also, there are directed edges from 1 to 2 and 3 to 2 so 1 and 3 should come before 2.

So, The topological sorting of this DAG is {0 1 3 2}.

Note that there are multiple topological sortings possible for a DAG. For the graph given above one another topological sorting is: {0, 3, 1, 2}

Note:
1. It is guaranteed that the given graph is DAG.
2. There will be no multiple edges and self-loops in the given DAG.
3. There can be multiple correct solutions, you can find any one of them.
4. Don’t print anything, just return an array representing the topological sort of the vertices of the given DAG.

******
stack used because every time you call dfs and it again call it neighour in dfs
at last node when their is no neighbor available then it become last node and this node at to stack...
by this you'll get all node in reverse order in stack, now convert stack to vector and return it..
*/