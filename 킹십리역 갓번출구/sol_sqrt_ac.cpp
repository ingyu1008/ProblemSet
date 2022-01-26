#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

constexpr int sqrtN = 316;
typedef long long ll;

struct Edge {
    int from;
    int to;
    ll cost;
};

struct Graph {
    std::vector<std::vector<Edge>> edges;
    Graph(int n) : edges(n) {};
    void addEdge(int from, int to, ll cost) {
        edges[from].push_back({ from, to, cost });
        edges[to].push_back({ to, from, cost });
    }

    ll findEdge(int from, int to) const {
        for (int i = 0; i < edges[from].size(); i++) {
            if (edges[from][i].to == to) return edges[from][i].cost;
        }
        return -1;
    }
};

struct Tree : public Graph {
    std::vector<int> sqrtparent;
    std::vector<int> parent;
    std::vector<int> depth;
    std::vector<int> size;
    std::vector<ll> cost;
    std::vector<ll> sqrtcost;
    std::vector<ll> lazy;
    Tree(int n) : Graph(n), sqrtparent(n),  parent(n), depth(n), size(n), cost(n), sqrtcost(n), lazy(n) {};

    // Analyze the tree
    int analyze(int node = 0, int par = -1) {
        static std::stack<int> st;
        sqrtparent[node] = -1;
        parent[node] = par;
        depth[node] = par == -1 ? 0 : depth[par] + 1;
        if (!st.empty()) {
            sqrtparent[node] = st.top();
        }
        if ((depth[node] % sqrtN) == 1) {
            st.push(node);
        }
        size[node] = 1;
        cost[node] = 0;
        sqrtcost[node] = 0;
        lazy[node] = 0;
        for (int i = 0; i < edges[node].size(); i++) {
            int next = edges[node][i].to;
            if (par >= 0 && next == par) {
                cost[node] = edges[node][i].cost;
                if (sqrtparent[node] != -1) sqrtcost[sqrtparent[node]] += cost[node];
                continue;
            }
            size[node] += analyze(next, node);
        }
        if ((depth[node] % sqrtN) == 1) {
            st.pop();
        }
        return size[node];
    }

    // Returns the sum of costs
    ll get_cost(int node) const {
        int flag = 1;
        int cur = node;
        ll sum = 0;
        while (parent[cur] != -1) {
            if ((depth[cur] % sqrtN) == 1 && sqrtparent[cur] != -1) {
                if (flag) {
                    flag = 0;
                    sum += lazy[cur] * (((depth[node] + sqrtN - 1) % sqrtN) + 1);
                }
                sum += sqrtcost[sqrtparent[cur]];
                sum += lazy[sqrtparent[cur]] * sqrtN;
                cur = sqrtparent[cur];
                continue;
            }
            sum += cost[cur];
            cur = parent[cur];
        }
        return sum;
    }

    // Learn
    void learn(int node, ll v) {
        int flag = 1;
        int cur = node;
        while (parent[cur] != -1) {
            if ((depth[cur] % sqrtN) == 1 && sqrtparent[cur] != -1) {
                if (flag) {
                    flag = 0;
                } else {
                    lazy[sqrtparent[cur]] -= v;
                }
                cur = sqrtparent[cur];
                continue;
            }

            cost[cur] -= v;

            if (sqrtparent[cur] != -1) {
                sqrtcost[sqrtparent[cur]] -= v;
            }
            cur = parent[cur];
        }
    }
};

namespace G2T {
    void kruskal_mst(const Graph& graph, Tree* dest) {
        std::vector<Edge> edges;
        for (int i = 0; i < graph.edges.size(); i++) {
            for (int j = 0; j < graph.edges[i].size(); j++) {
                edges.push_back({ i, graph.edges[i][j].to, graph.edges[i][j].cost });
            }
        }
        std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.cost < b.cost;
            });
        for (int i = 0; i < edges.size(); i++) {
            int from = edges[i].from;
            int to = edges[i].to;
            ll cost = edges[i].cost;
            if (dest->findEdge(from, to) == -1) {
                dest->addEdge(from, to, cost);
                dest->addEdge(to, from, cost);
            }
        }
    }

    void shortest_path_tree_dijkstra(const Graph& graph, Tree* dest, int root = 0) {
        std::vector<int> dist(graph.edges.size(), -1);
        std::vector<bool> visited(graph.edges.size(), false);
        std::vector<int> parent(graph.edges.size(), -1);
        std::priority_queue<std::pair<ll, std::pair<int, std::pair<int, int>>>, std::vector<std::pair<ll, std::pair<int, std::pair<int, int>>>>, std::greater<std::pair<ll, std::pair<int, std::pair<int, int>>>>> pq;
        dist[root] = 0;
        pq.push({ 0, {0, {-1, root}} });
        while (!pq.empty()) {
            int k = pq.top().second.first;
            int par = pq.top().second.second.first;
            int cur = pq.top().second.second.second;
            int d = pq.top().first;
            pq.pop();
            if (cur < 0 || visited[cur]) continue;
            visited[cur] = true;
            dist[cur] = d;
            parent[cur] = par;
            for (int i = 0; i < graph.edges[cur].size(); i++) {
                int next = graph.edges[cur][i].to;
                ll cost = graph.edges[cur][i].cost;
                if (dist[next] == -1 || dist[next] > dist[cur] + cost) {
                    pq.push({ dist[cur] + cost, {k + 1, {cur, next}} });
                }
            }
        }
        for (int i = 0; i < graph.edges.size(); i++) {
            if (dist[i] == -1 || parent[i] == -1) continue;
            dest->addEdge(i, parent[i], dist[i] - dist[parent[i]]);
        }
    }
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M, G;
    std::cin >> N >> M >> G;

    Graph graph(101010);
    Tree tree(101010);

    for (int i = 0; i < M; i++) {
        int a, b;
        ll c;
        std::cin >> a >> b >> c;
        graph.addEdge(a, b, c);
    }

    G2T::shortest_path_tree_dijkstra(graph, &tree, G);
    tree.analyze(G, -1);

    int Q;
    std::cin >> Q;

    ll tot = 0;

    for (int x = 0; x < Q; x++) {
        int q, i;
        std::cin >> q;
        if (q == 1) {
            ll v;
            std::cin >> i >> v;
            tot += v;
            tree.learn(i, v);
        } else {
            std::cin >> i;
            std::cout << tree.depth[i] * tot + tree.get_cost(i) << "\n";
        }
    }


    return 0;
}