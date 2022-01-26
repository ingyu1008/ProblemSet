#include <iostream>
#include <set>
#include <vector>

/*

그래프에서 사이클이란, 한 정점에서 같은 정점까지, 반복되는 간선이 없으며, 길이가 $0$이 아닌 경로이다.
사이클이 존재하지 않는 그래프가 주어진다.
우리는 이 그래프의 정점 중에서 연결된 간선이 하나인 정점을 {\bf 가장자리 정점}이라고 정의하자.
이 그래프의 \bf{가장자리 정점}들을 동시에 없애가는 과정을 반복하면서, 결국 그래프가 일직선의 형태가 되면 남아있는 정점들의 집합을 {\bf 그래프의 줄기}라고 정의하자.
\includegraphics{1.PNG}
위 그림과 같은 그래프가 있다고 할 때, 아래와 같이 \bf{가장자리 정점}들과 연결된 간선들을 빨간색으로 표시하면 아래와 같다.
\includegraphics{2.PNG}
빨간 색 간선들과 연결된 가장자리 정점들의 연결이 끊어지면 아래 그림과 같이 일직선 형태로 연결된 {\bf 그래프의 줄기}가 남는다. 만약 그래프가 일직선 모양이 되었다면, \bf{가장자리 정점}이 더 존재하더라도 더 이상 \bf{가장자리 정점}들을 없애지 않는다.
\includegraphics{3.PNG}
이때 {\bf 그래프의 줄기}를 이루는 정점들을 구하는 프로그램을 작성하시오.

입력의 첫 번째 줄에는 처음 그래프의 정점의 수 $N (2 \le N \le 100,000)$이 주어진다.
이후 $N-1$줄에 걸쳐 각 간선으로 연결된 두 정점의 번호 $a, b$가 입력된다. $(0 \le a, b < n,\ a \ne b)$

출력의 첫 번째 줄에 트리의 줄기를 이루는 정점의 번호들을 오름차순으로 정렬하고 공백으로 구분하여 출력한다.

*/
int n;
std::set<int> edges[100001];
std::vector<int> removed[100001];
int out[100001];
int oe;

int main() {

    std::cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        std::cin >> a >> b;
        edges[a].insert(b);
        edges[b].insert(a);
    }

    std::set<int> candidates;
    std::set<int> nexts;

    for (int i = 0; i < n; ++i) {
        if (edges[i].size() == 1) candidates.insert(i);
    }
    for (; candidates.size() > 2;) {
        nexts.clear();
        for (int i : candidates) {
            if (edges[i].size() == 1) {
                int a = *(edges[i].begin());
                removed[a].push_back(i);
                nexts.insert(a);
                edges[i].clear();
                out[i] = 1;
            }
        }
        candidates.clear();
        for (int i : nexts) {
            for (int j : removed[i]) {
                edges[i].erase(j);
            }
            removed[i].clear();
            if (edges[i].size() == 1) candidates.insert(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!out[i]) std::cout << i << " ";
    }
    return 0;
}