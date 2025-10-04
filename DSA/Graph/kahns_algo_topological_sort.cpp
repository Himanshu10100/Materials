vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    queue<int> q;
    vector<int> degree(v);

    for (auto i : adj)
    {
        for (int j : i.second)
        {
            degree[j]++;
        }
    }

    for (int i = 0; i < v; i++)
    {
        if (degree[i] == 0)
            q.push(i);
    }

    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for (auto neighbour : adj[front])
        {
            degree[neighbour]--;
            if (degree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    return ans;
}

/*
make vector for indegree with degree count
push all 0'th degree to q
now start while q become empty
push q's element in ans
iterate all q's element's neighbour, here front node is removed so it's neighbour's degree decrease to one.. & check if zero then push that neighbour in q.
make this process untill and unless q become empty
return ans
*/