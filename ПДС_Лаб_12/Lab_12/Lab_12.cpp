#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <sstream>
#include <windows.h>  

using namespace std;

const int INF = (std::numeric_limits<int>::max)();

struct Edge {
    int v, weight;
    Edge(int v, int weight) : v(v), weight(weight) {}
};

void dijkstra(const vector<vector<Edge>>& graph, int source, vector<int>& dist, vector<int>& parent) {
    int n = graph.size();
    dist.assign(n, INF);
    parent.assign(n, -1);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, source });

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : graph[u]) {
            int v = edge.v;
            int weight = edge.weight;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({ dist[v], v });
            }
        }
    }
}

void printPath(int start, int end, const vector<int>& parent) {
    if (end == -1) {
        cout << "Немає шляху" << endl;
        return;
    }
    if (start == end) {
        cout << start + 1;
        return;
    }
    printPath(start, parent[end], parent);
    cout << " -> " << end + 1;
}

void readGraphFromFile(const string& filename, vector<vector<Edge>>& graph, int& n, int& m) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return;
    }

    file >> n >> m;
    graph.resize(n);

    int u, v, w;
    for (int i = 0; i < m; ++i) {
        file >> u >> v >> w;
        graph[u - 1].push_back(Edge(v - 1, w)); 
    }

    file.close();
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n, m;  
    vector<vector<Edge>> graph;

    string inputFile = "D:\\Лаби ДПС\\ПДС_Лаб_10\\wag_graph.txt"; 
    readGraphFromFile(inputFile, graph, n, m);

    int start, end;
    cout << "Введіть початкову вершину (від 1 до " << n << "): ";
    cin >> start;
    cout << "Введіть кінцеву вершину (від 1 до " << n << "): ";
    cin >> end;

    vector<int> dist(n), parent(n);
    dijkstra(graph, start - 1, dist, parent);

    cout << "Найкоротший шлях від вершини " << start << " до вершини " << end << ":\n";
    printPath(start - 1, end - 1, parent);
    cout << "\nДовжина шляху: " << dist[end - 1] << endl;

    cout << "\nВведіть початкову вершину для знаходження всіх відстаней (від 1 до " << n << "): ";
    cin >> start;

    dijkstra(graph, start - 1, dist, parent);

    cout << "\nВідстані від вершини " << start << " до всіх інших вершин:\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Вершина " << i + 1 << ": Немає шляху" << endl;
        }
        else {
            cout << "Вершина " << i + 1 << ": " << dist[i] << endl;
        }
    }

    return 0;
}
