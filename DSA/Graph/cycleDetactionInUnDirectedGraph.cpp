#include <bits/stdc++.h>

bool isCyclic(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{
    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = 1;

    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto neighbour : adj[front])
        {
            // this node is visited but it's not nrighbour parent means : we have come to this node by other way and now reached again : CYCLE
            if (visited[neighbour] == true && parent[front] != neighbour)
            {
                return true;
            }
            else if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }

    return false;
}

bool cycleDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{
    visited[node] = 1;

    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool ans = cycleDFS(neighbour, node, visited, adj);
            if (ans)
                return ans;
        }
        else if (neighbour != parent)
        {
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            // bool ans = isCyclic(i,visited, adj);
            bool ans = cycleDFS(i, -1, visited, adj);
            if (ans)
                return "Yes";
        }
    }

    return "No";
}

/*
Problem statement
You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 to 'N'.

Your task is to find if the graph contains a cycle or not.

A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a cycle.

Example :

In the below graph, there exists a cycle between vertex 1, 2 and 3.

1
3 2
1 2
2 3
Sample output 1:
No

Sample Input 2:
2
4 0
4 3
1 4
4 3
3 1
Sample output 2:
No
Yes
https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
*/