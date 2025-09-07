#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
#include <string>
using namespace std;


bool dfsCheckCycle(int node,unordered_map<int,bool>&visi, unordered_map<int,bool>&dfsVisi, unordered_map<int,list<int>>&adj){
  visi[node] = true;
  dfsVisi[node] = true;

  for(auto i: adj[node]){
    if(!visi[i]){
      if(dfsCheckCycle(i,visi,dfsVisi,adj)){
        return true;
      }
    }
    else if(dfsVisi[i]){
      return true;
    }
  }

  dfsVisi[node] =false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

  // Write your code here.
  unordered_map<int, list<int>>adj;
  for(int i = 0; i < edges.size(); i++){
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }

  unordered_map<int,bool>visi;
  unordered_map<int,bool>dfsVisi;

  for(int i=0; i < n; i++){
    if(!visi[i]){
      if(dfsCheckCycle(i,visi,dfsVisi,adj)){
        return true;
      }
    }
  }
  return false;
}