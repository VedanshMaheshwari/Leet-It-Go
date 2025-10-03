#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	unordered_map<int, list<int>>adj;
	for(int i = 0; i < edges.size(); i++){
		int x = edges[i].first;
		int y = edges[i].second;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	unordered_map<int,bool>visited;
	unordered_map<int,int>parent;

	queue<int>q;
	q.push(s);
	visited[s] = 1;
	parent[s] = -1;

	while(!q.empty()){
		int front = q.front();
		q.pop();
		for(auto i: adj[front]){
			if(!visited[i]){
				visited[i] = true;
				parent[i] = front;
				q.push(i);
			}
		}
	}

	vector<int>ans;
	ans.push_back(t);
	int node = t;
	while (node != s){
		node = parent[node];
		ans.push_back(node);

	}

	reverse(ans.begin(), ans.end());
	return ans;
}
