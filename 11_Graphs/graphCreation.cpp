#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

//Generic type any data can be entered;
template <typename T>

class graph{

public:
    unordered_map <T, list <T>> adj;

    void addEdge(T u, T v, bool direction){
        //direction = 0 -> undirected graph
        //direction = 1 -> directed grapgh
        
        //create an edge from u to v
        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjacencyList(){
        for(auto i: adj){
            cout << i.first << "->";
            for(auto j : i.second){
                cout << j <<", ";
            }
            cout << endl;
        }
    }
};

int main(){
    int n;
    cout << "Enter the number of nodes: " << endl;
    cin >> n; 

    int m;
    cout << "Enter the number of edges: " << endl;
    cin >> m;

    graph <int>g;

    for(int i = 0; i <m; i++){
        int u, v;
        cin>> u >> v;
        //creating an undirected graph;
        g.addEdge(u,v,0); 
    }

    g.printAdjacencyList();

}


//COdeChef
#include<vector>
vector <vector <int>> printAdjacency(int n, int m, vector < vector < int >> & edges) { 
    vector<int> ans[n]; 
    for(int i = 0; i < m; i++){ 
        
        int u = edges[i][0]; 
        int v = edges[i][1]; 
    
        ans[u].push_back(v); 
        ans[v].push_back(u); 
    } 
    
    vector<vector<int>>adj(n);

    for(int i = 0; i < n; i++){
        adj[i].push_back(i);
        for(int j = 0; j < ans[i].size(); j++)
        {
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}