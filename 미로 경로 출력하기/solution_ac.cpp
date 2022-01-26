#include <iostream>

int N, M;
char map[2020][2020];
bool visited[2020][2020];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void init();
void solve();
void print();

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    init();
    solve();
    print();

    return 0;
}

void init() {
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
            if(map[i][j] == '.') map[i][j] = '@';
        }
    }
}

void find_start_end_points(int& start_x, int& start_y, int& end_x, int& end_y) {
    for (int i = 0; i < M; i++) {
        if (map[0][i] == '@') {
            if (start_x == -1) {
                start_x = 0;
                start_y = i;
            } else {
                end_x = 0;
                end_y = i;
            }
        }
        if (map[N - 1][i] == '@') {
            if (start_x == -1) {
                start_x = N - 1;
                start_y = i;
            } else {
                end_x = N - 1;
                end_y = i;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (map[i][0] == '@') {
            if (start_x == -1) {
                start_x = i;
                start_y = 0;
            } else {
                end_x = i;
                end_y = 0;
            }
        }
        if (map[i][M - 1] == '@') {
            if (start_x == -1) {
                start_x = i;
                start_y = M - 1;
            } else {
                end_x = i;
                end_y = M - 1;
            }
        }
    }
}

bool dfs(int si, int sj, int ei, int ej) {
    if (si == ei && sj == ej) {
        map[si][sj] = '.';
        return true;
    }

    bool res = false;

    for (int dir = 0; dir < 4; dir++) {
        int nx = si + dx[dir];
        int ny = sj + dy[dir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (map[nx][ny] == '+') continue;
        if (visited[nx][ny]) continue;

        visited[nx][ny] = true;
        res = dfs(nx, ny, ei, ej);
        if (res) {
            map[si][sj] = '.';
            return true;
        }
    }

    return false;
}

void solve() {
    int si = -1, sj = -1, ei = -1, ej = -1;
    find_start_end_points(si, sj, ei, ej);

    dfs(si, sj, ei, ej);
}

void print() {
    for (int i = 0; i < N;i++) {
        for (int j = 0; j < M; j++) {
            std::cout << map[i][j];
        }
        std::cout << "\n";
    }
}