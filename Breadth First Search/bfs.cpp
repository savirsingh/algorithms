// code by savir singh
// BFS algorithm to find shortest path
// between node 1 and node n

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// all vars
const int MAX=100;
vector<int> graph[MAX];
bool visited[MAX];
int dist[MAX];
int n=50;

int main()
{
    deque<int> deq;
    deq.push_back(1);
    visited[1]=true;
    dist[1]=0;
    while (!deq.empty()) {
        int curr=deq.front();
        deq.pop_front();
        int lvl=dist[curr];
        for (int adj : graph[curr]) {
            if (!visited[adj]) {
                visited[adj]=true;
                dist[adj]=lvl+1;
                deq.push_back(adj);
            }
        }
    }
    cout << dist[n];
}
