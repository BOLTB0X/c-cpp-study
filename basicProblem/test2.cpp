#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // find

using namespace std;

void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited, vector<int>& path, vector<int>& cycleNodes, int startNode) {
    visited[node] = true;
    path.push_back(node);

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, path, cycleNodes, startNode);
        } else if (neighbor == startNode && path.size() >= 3) { // 시작 노드로 돌아왔고 길이가 3 이상일 때
            for (int p : path) {
                // 이미 cycleNodes에 포함되어 있지 않은 노드만 추가
                if (find(cycleNodes.begin(), cycleNodes.end(), p) == cycleNodes.end()) {
                    cycleNodes.push_back(p);
                }
            }
        }
    }

    path.pop_back(); // Backtrack
    visited[node] = false; // 방문 상태 초기화
}

vector<int> findCycleNodes(int s_nodes, const vector<int>& s_from, const vector<int>& s_to) {
    vector<vector<int>> graph(s_nodes);
    
    // 그래프 생성
    for (size_t i = 0; i < s_from.size(); ++i) {
        graph[s_from[i]].push_back(s_to[i]);
        graph[s_to[i]].push_back(s_from[i]); // 양방향 그래프
    }
    
    vector<int> cycleNodes;

    // 모든 노드를 방문하여 DFS 수행
    for (int i = 0; i < s_nodes; ++i) {
        vector<bool> visited(s_nodes, false);
        vector<int> path;
        dfs(i, graph, visited, path, cycleNodes, i); // 시작 노드를 i로 설정
    }

    return cycleNodes;
}

vector<int> calculateDistancesFromCycleNodes(int s_nodes, const vector<vector<int>>& graph, const vector<int>& cycleNodes) {
    vector<int> distances(s_nodes, -1);
    queue<int> que;

    // 순환 노드의 거리를 0으로 초기화하고 큐에 추가
    for (int node : cycleNodes) {
        distances[node] = 0;
        que.push(node);
    }

    // BFS 수행
    while (!que.empty()) {
        int current = que.front();
        que.pop();

        for (int neighbor : graph[current]) {
            if (distances[neighbor] == -1) { // 아직 방문하지 않은 경우
                distances[neighbor] = distances[current] + 1; // 거리를 1 증가시킴
                que.push(neighbor);
            }
        }
    }

    return distances;
}

int main() {
    int s_nodes = 6; // 노드 수
    vector<int> s_from = {5, 1, 0, 1, 0, 2}; // 연결 정보
    vector<int> s_to = {1, 0, 2, 2, 3, 4}; // 연결 정보

    vector<int> cycleNodes = findCycleNodes(s_nodes, s_from, s_to);
    
    // 거리 계산
    vector<vector<int>> graph(s_nodes);
    for (size_t i = 0; i < s_from.size(); ++i) {
        graph[s_from[i]].push_back(s_to[i]);
        graph[s_to[i]].push_back(s_from[i]); // 양방향 그래프
    }
    
    vector<int> distances = calculateDistancesFromCycleNodes(s_nodes, graph, cycleNodes);

    // 결과 출력
    cout << "Distances: ";
    for (int dist : distances) {
        cout << dist << " ";
    }
    cout << endl;

    return 0;
}
