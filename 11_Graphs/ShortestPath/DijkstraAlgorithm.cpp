#include <bits/stdc++.h> 
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.

    unordered_map<int, list<pair<int,int>>>adj;
    for(int i = 0; i < edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }

    set<pair<int,int>> st;
    vector<int>distance(vertices);

    for(int i = 0; i < vertices; i++){
        distance[i] = INT_MAX;
    }

    distance[source] = 0;

    st.insert({0,source});

    while(!st.empty()){
        auto top = *(st.begin());
        int distNode = top.first;
        int nodeTop = top.second;

        st.erase(st.begin());

        for(auto neigh : adj[nodeTop]){
            if(distNode + neigh.first < distance[neigh.second]){
                auto record = st.find({distance[neigh.second], neigh.second});

                if(record != st.end()){
                    st.erase(record);
                }  

                distance[neigh.second] = distNode + neigh.first;    
                st.insert({distance[neigh.second], neigh.second});   
            }
        }
    }
    return distance;
}


class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // Min-heap behavior using set: {distance, node}
        set<pair<int,int>> st;
        vector<int> dist(V, 1e9); // use large int value
        dist[S] = 0;
        st.insert({0, S});

        while(!st.empty()) {
            auto top = *(st.begin());
            int NodeDist = top.first;
            int Node = top.second;
            st.erase(st.begin()); // erase first element

            for(auto neighbour : adj[Node]) {
                int adjNode = neighbour[0];
                int weighN = neighbour[1];

                if(dist[adjNode] > NodeDist + weighN) {
                    // erase old record if it existed
                    auto it = st.find({dist[adjNode], adjNode});
                    
                    if(it != st.end()) {
                        st.erase(it);
                    }

                    dist[adjNode] = NodeDist + weighN;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};
