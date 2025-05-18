#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& path, int pos) {
    if (graph[path[pos - 1]][v] == 0) return false; // agar last position se current position ke path nahi hai toh false
    // agar current position pehle se hai toh false
    for (int i = 0; i < pos; i++)
        if (path[i] == v) return false;
    return true;
}

bool hamiltonianCycleUtil(vector<vector<int>>& graph, vector<int>& path, int pos) {
    if (pos == graph.size()) {
        if (graph[path[pos - 1]][path[0]] == 1) return true;
        return false;
    }

    for (int v = 1; v < graph.size(); v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamiltonianCycleUtil(graph, path, pos + 1)) return true;
            path[pos] = -1;
        }
    }
    return false;
}

void hamiltonianCycle(vector<vector<int>>& graph) {
    vector<int> path(graph.size(), -1);
    path[0] = 0;
    if (!hamiltonianCycleUtil(graph, path, 1)) {
        cout << "No Hamiltonian Cycle\n";
    } else {
        for (int i = 0; i < graph.size(); i++) {
            cout << path[i] << " ";
        }
        cout << path[0] << "\n";
    }
}

int main() {
    vector<vector<int>> graph = {{0, 1, 0, 1, 0}, {1, 0, 1, 1, 1}, {0, 1, 0, 0, 1}, {1, 1, 0, 0, 1}, {0, 1, 1, 1, 0}};
    hamiltonianCycle(graph);
    return 0;
}
