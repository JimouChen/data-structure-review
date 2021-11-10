#include <cstdio>
#include <deque>
#include <map>

using namespace std;
const int maxn = 25000 + 50;
const int oo = 0xffffff;
int dist[maxn];
int vis[maxn];
map<int, int> G[maxn];
map<int, int>::iterator iter;
deque<int> dq;
int t, r, p, s;

void spfa(int v0) {
    for (int i = 1; i <= t; i++) {
        dist[i] = oo;
        vis[i] = 0;
    }
    dist[v0] = 0;
    vis[v0] = 1;
    dq.push_back(v0);
    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();
        vis[cur] = 0;
        for (iter = G[cur].begin(); iter != G[cur].end(); iter++) {
            int i = iter->first;
            if (dist[cur] + G[cur][i] < dist[i]) {
                dist[i] = dist[cur] + G[cur][i];
                if (!vis[i]) {
                    vis[i] = 1;
                    if (!dq.empty()) {
                        if (dist[i] < dist[dq.front()]) {
                            dq.push_front(i);
                        } else {
                            dq.push_back(i);
                        }
                    } else {
                        dq.push_back(i);
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d", &t, &r, &p, &s);
    int a, b, l;
    for (int i = 0; i < r; i++) {
        scanf("%d%d%d", &a, &b, &l);
        if (G[a].find(b) == G[a].end() || G[a][b] > l) {
            G[a][b] = G[b][a] = l;
        }
    }
    for (int i = 0; i < p; i++) {
        scanf("%d%d%d", &a, &b, &l);
        if (G[a].find(b) == G[a].end() || G[a][b] > l) {
            G[a][b] = l;
        }
    }
    spfa(s);
    for (int i = 1; i <= t; i++) {
        if (dist[i] == oo) {
            printf("NO PATH\n");
        } else {
            printf("%d\n", dist[i]);
        }
    }
    return 0;
}