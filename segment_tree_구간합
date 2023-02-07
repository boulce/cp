//https://book.acmicpc.net/ds/segment-tree

#include <bits/stdc++.h>
using namespace std;
#define ll long long
//a: 배열 A
//tree: 세그먼트 트리
//node: 노드 번호
//node에 저장되어 있는 합의 범위가 start~end
void init(vector<ll>& a, vector<ll>& tree, int node, int start, int end){
    if(start == end){
        tree[node] = a[start];
    }
    else{
        int mid = (start+end)/2;
        init(a, tree, node*2, start, mid);
        init(a, tree, node*2+1, mid+1, end);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

ll query(vector<ll>& tree, int node, int start, int end, int left, int right){
    if(left > end || right < start){
        return 0;
    }
    if(left <= start && end <= right){
        return tree[node];
    }
    int mid = (left+right)/2;
    ll lsum = query(tree, node*2, start, mid, left, right);
    ll rsum = query(tree, node*2+1, mid+1, end, left, right);
    return lsum + rsum;
}

void update(vector<ll>& tree, int node, int start, int end, int index, ll diff){
    if(index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if(start != end){
        int mid = (start+end)/2;
        update(tree, node*2, start, mid, index, diff);
        update(tree, node*2+1, mid+1, end, index, diff);
    }
}

void update(vector<ll>& a, vector<ll>& tree, int n, int index, ll val){
    ll diff = val - a[index];
    a[index] = val;
    update(tree, 1, 0, n-1, index, diff);
}
