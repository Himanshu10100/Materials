# ✅ ** GRAPH PATTERNS(DSA MASTER LIST) **

---

# 🔵 ** 1. Graph Representation Pattern **

Understand how the graph is stored:

* **Adjacency list** → most common
* **Adjacency matrix**
* **Edge list**

**Needed for ALL graph problems.**

---

# 🔵 ** 2. Traversal Pattern **

Used to explore graph step-by-step.

### **Pattern: BFS (Breadth First Search)**

Use when:

* Shortest path in **unweighted graph**
* Level–wise traversal
* Multi-source shortest path

### **Pattern: DFS (Depth First Search)**

Use when:

* Count connected components
* Detect cycle
* Backtracking

---

# 🔵 ** 3. Connected Components Pattern **

Find groups of nodes that are connected.

Techniques:

* DFS/BFS
* Union-Find (Disjoint Set)

Common questions:

* No. of islands
* Provinces
* Connected components in undirected graph

---

# 🔵 ** 4. Cycle Detection Pattern **

### **Undirected Graph**

* DFS with parent tracking
* Union-Find

### **Directed Graph**

* DFS + recursion stack
* Kahn’s BFS (topological) → cycle exists if nodes != visited count

---

# 🔵 ** 5. Topological Sort Pattern **

Used for **Directed Acyclic Graphs (DAG)**.

Algorithms:

* DFS-based
* Kahn’s BFS algorithm

Common problems:

* Course schedule
* Job scheduling
* Find valid order of tasks

---

# 🔵 ** 6. Shortest Path Pattern **

### **Case 1 → Unweighted graph**

✔️ BFS

### **Case 2 → Weighted graph (positive weights)**

✔️ Dijkstra

### **Case 3 → Negative weights (no negative cycle)**

✔️ Bellman–Ford

### **Case 4 → Negative cycle detection**

✔️ Bellman–Ford
✔️ Floyd–Warshall

### **Case 5 → All-pairs shortest paths**

✔️ Floyd–Warshall

---

# 🔵 ** 7. Minimum Spanning Tree(MST) Pattern **

Used in network design.

Algorithms:

* **Kruskal** (using DSU)
* **Prim** (using min-heap)

Common questions:

* Minimum cost to connect network
* Connecting all cities with minimum roads

---

# 🔵 ** 8. DAG DP Pattern(Dynamic Programming on Graphs) **

DP applied on DAG using topological sort.

Used for:

* Longest path in DAG
* Max weight path
* DP with dependency order

---

# 🔵 ** 9. Grid / Matrix as Graph Pattern **

Treat grid as graph (4-directional or 8-directional).

Techniques:

* BFS/DFS
* Multi-source BFS
* Flood fill

Problems:

* Number of islands
* Rotten oranges
* Shortest path in grid
* Maze problems

---

# 🔵 ** 10. Bipartite Graph Pattern **

Check whether graph can be colored using 2 colors.

Used for:

* Graph coloring
* Cycle detection (odd cycle)
* Matching problems

Algorithms:

* BFS coloring
* DFS coloring

---

# 🔵 ** 11. Bridges & Articulation Points Pattern **

Used to find critical connections.

Techniques:

* Tarjan’s algorithm
* DFS + low-link values

Problems:

* Critical connections in a network
* Articulation points

---

# 🔵 ** 12. Strongly Connected Components(SCC) Pattern **

For directed graphs.

Algorithms:

* Kosaraju
* Tarjan

Used for:

* Condensing directed graph
* Component grouping
* Cycle-based problems

---

# 🔵 ** 13. Top - K / Priority Based Graph Pattern **

Used when:

* You need to pick best next option (like greedy on graph)

Data structures:

* Min-heap
* Max-heap
* Priority queue

Dijkstra, Prim, etc.

---

# 🔵 ** 14. Union - Find / DSU Pattern **

Used for:

* Cycle detection
* MST (Kruskal)
* Grouping nodes
* Checking if two nodes are connected

---

# 🔵 ** 15. Tree Pattern(Special Graph) **

Tree = graph with **N nodes & N-1 edges**.

Common techniques:

* DFS
* Depth/height
* LCA (Binary lifting)
* Diameter of tree
* Subtree sums
* Euler tour

---

# 🔵 ** 16. Multi - Source BFS Pattern **

Start BFS from **multiple nodes** at once.

Examples:

* Rotten oranges
* Walls and gates
* Minimum distance from land to water

---

# 🔵 ** 17. State - Space Graph Pattern **

Graph isn't given; you create graph using states.

Used in:

* Word ladder
* 8-puzzle
* Knight moves
* Minimum operations to convert number

---

# 🔵 ** 18. Backtracking on Graph Pattern **

Used for:

* Hamiltonian path
* Knight’s tour
* Solve maze problems

---

# 🔵 ** 19. Flow Network Pattern **

Advanced, mostly for competitive programming.

Algorithms:

* Ford–Fulkerson
* Edmonds–Karp
* Max-flow
* Min-cut

Problems:

* Maximum bipartite matching
* Network flow optimization

---

# 🟢 Summary Table(Cheat Sheet)

| Pattern            | When to Use                        |
| ------------------ | ---------------------------------- |
| BFS                | Shortest path (unweighted), levels |
| DFS                | Components, cycle detection        |
| DSU                | Components, cycles, Kruskal        |
| Topological Sort   | Directed acyclic graph ordering    |
| Dijkstra           | Weighted shortest path             |
| Bellman–Ford       | Negative edges                     |
| Floyd–Warshall     | All-pairs shortest path            |
| MST                | Minimum cost connections           |
| SCC                | Condensed graph / cycles           |
| Tarjan (Low-Link)  | Bridges, articulation points       |
| Grid BFS           | Maze, islands                      |
| Bipartite Checking | 2-coloring, odd cycle              |
| Tree DP            | Tree questions                     |
| State-space Search | Word ladder, puzzles               |
