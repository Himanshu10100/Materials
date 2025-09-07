//INPUT**********************
// Enter nodes : 5
// Enter Edges : 6
// 0 1
// 1 2
// 2 3
// 3 1
// 3 4
// 0 4

/*CODE***********************/
#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Graph{
    public:
      unordered_map<T,list<T>> adj;
      
      void addEdge(int u,int v, bool direction){
          adj[u].push_back(v);
          if(!direction){
            adj[v].push_back(u);
          }
      }
      
      void printGraph(){
          for(auto i:adj){
              cout<<i.first<<" -> ";
              for(auto j: i.second){
                  cout<<j<<", ";
              }
              cout<<endl;
          }
      }
};

int main() {
    int n;
    cout<<"Enter nodes : ";
    cin>>n;
    
    int e;
    cout<<"Enter Edges : ";
    cin>>e;
    
    Graph<int> g;
    
    for(int i=1;i<=e;i++){
        int u,v;
        cin>>u>>v;
        //undirected praph:0, directed praph: 1
        g.addEdge(u,v,0);
    }
    
    g.printGraph();
    return 0;
}
