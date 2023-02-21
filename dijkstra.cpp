#include <bits/stdc++.h>
using namespace std;

#define W first
#define V second
#define INF 1e8
int n;
vector<pair<int, int>> adjList[2001];
int dijkstra(int s, int e){ // s에서 e까지의 최단 경로 반환
    int dist[2001];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist, dist+n+1, INF);

    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();

        if(cur.W != dist[cur.V]) continue;
        if(cur.V == e) break;
        for(auto nxt : adjList[cur.V]){
            if(dist[nxt.V] > dist[cur.V] + nxt.W){
                dist[nxt.V] = dist[cur.V] + nxt.W;
                pq.push({dist[nxt.V], nxt.V});
            }
        }
    }
    return dist[e];
}
