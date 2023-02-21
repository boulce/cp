// 백준 1197, 크루스칼 알고리즘(유니온 파인드)
#include <bits/stdc++.h>
using namespace std;

int parent[10001];

int find(int a){
    if(parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}

void unionSet(int a, int b){
    a = find(a);
    b = find(b);
    if(a < b) swap(a, b);
    parent[a] = b;
}

bool is_diff_set(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b) return true;
    else return false;
}

int v, e, a, b, c;
int cnt, ans;
tuple<int, int, int> edges[100000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    for(int i = 0; i < e; i++){
        cin >> a >> b >> c;
        edges[i] = {c, a, b};
    }

    for(int i = 1; i <= v; i++)
        parent[i] = i;
    sort(edges, edges+e); // 엣지 가중치가 작은 것부터 선택하기 위해 정렬
    for(int i = 0; i < e; i++){
        int cost, a, b;
        tie(cost, a, b) = edges[i];
        if(!is_diff_set(a, b)) continue; // 선택한 간선의 두 정점이 같은 집합에 속하면 continue
        // 같은 그룹에 속하지 않으면 트리에 담고 두 정점을 하나의 집합으로 합친다.
        unionSet(a, b);
        cnt++;
        ans += cost;
        if(cnt == v-1) break;
    }
    cout << ans;
}
