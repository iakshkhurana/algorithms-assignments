#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
       vector<int> topoSort(int V, vector<int> adj[]){
           int indegree[V]={0}; // initialise all indegree zero
           for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
           }

           queue<int>q;
           for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
           }
           vector<int>topo;
           while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
           }
           return topo;
       }
};

int main() {
    int V = 6;  // Number of vertices
    vector<int> adj[V];
    
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    
    Solution obj;
    vector<int> result = obj.topoSort(V, adj);
    
    cout << "Topological Sort Order: ";
    for(int i : result)
        cout << i << " ";
    cout << endl;
    
    return 0;
}