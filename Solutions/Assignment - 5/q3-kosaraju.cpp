#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }
    
    void revDfs(int node, vector<int>& vis, vector<int> transpose[]) {
        cout << node << " ";
        vis[node] = 1;
        for(auto it : transpose[node]) {
            if(!vis[it]) {
                revDfs(it, vis, transpose);
            }
        }
    }
    
public:
    void kosarajuSCC(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        stack<int> st;
        
        // Step 1: Fill vertices in stack according to their finishing times
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }
        
        // Step 2: Create transpose of graph
        vector<int> transpose[V];
        for(int i = 0; i < V; i++) {
            vis[i] = 0;
            for(auto it : adj[i]) {
                transpose[it].push_back(i);
            }
        }
        
        // Step 3: Process vertices in order defined by stack
        cout << "Strongly Connected Components are:\n";
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(!vis[node]) {
                revDfs(node, vis, transpose);
                cout << endl;
            }
        }
    }
};

int main() {
    int V = 5;
    vector<int> adj[V];
    
    // Add edges
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(4);
    
    Solution obj;
    obj.kosarajuSCC(V, adj);
    
    return 0;
}