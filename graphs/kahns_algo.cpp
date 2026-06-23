#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fr(i,a,b) for(int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef vector<int> vi;

/*

===================== KAHN'S ALGORITHM =====================

Used for:
-> Topological Sorting of DAG (Directed Acyclic Graph)

Meaning:
If u -> v
then u must come before v.

------------------------------------------------------------

Main Idea:

1. Store indegree of every node.
   indegree[x] = number of incoming edges.

2. Nodes with indegree 0 can be placed first
   because nothing depends before them.

3. Push all indegree 0 nodes into queue.

4. Pop node:
      add to topo answer
      remove its outgoing edges

5. If some node indegree becomes 0:
      push into queue

6. If topo size != n:
      cycle exists

Time Complexity:
O(V + E)

============================================================

Example:

1 -> 2
1 -> 3
2 -> 4
3 -> 4

Indegree:
1 = 0
2 = 1
3 = 1
4 = 2

Queue initially:
1

Process:
1 removed
2 indegree becomes 0
3 indegree becomes 0

Then:
2 removed
4 indegree becomes 1

Then:
3 removed
4 indegree becomes 0

Then:
4 removed

Topo:
1 2 3 4

============================================================

*/

void solve(){

    int n , m;
    cin >> n >> m;

    // adjacency list
    vector<vi> g(n + 1);

    // indegree array
    vi indeg(n + 1 , 0);

    fr(i,0,m){

        int u , v;
        cin >> u >> v;

        // edge u -> v
        g[u].pb(v);

        // v has one more incoming edge
        indeg[v]++;
    }

    queue<int> q;

    // initially push all nodes
    // having indegree 0
    fr(i,1,n+1){

        if(indeg[i] == 0){
            q.push(i);
        }
    }

    vi topo;

    while(!q.empty()){

        int u = q.front();
        q.pop();

        // u is now fixed in topo order
        topo.pb(u);

        // remove all outgoing edges of u
        for(auto v : g[u]){

            indeg[v]--;

            // if no incoming edges left
            // this node can now appear
            if(indeg[v] == 0){
                q.push(v);
            }
        }
    }

    // if topo does not contain all nodes
    // graph has cycle
    if(topo.size() != n){

        cout << "Cycle Exists\n";
        return;
    }

    cout << "Topological Order:\n";

    for(auto x : topo){
        cout << x << " ";
    }

    cout << endl;
}

signed main(){

    fast;

    solve();

    return 0;
}

/*

Important Notes:

1. Works only for DAG.

2. If multiple nodes have indegree 0:
   multiple topo orders possible.

3. To get lexicographically smallest topo:
   use priority_queue instead of queue.

4. Common Uses:
   -> Course Schedule
   -> Dependency Resolution
   -> Build Systems
   -> Ordering Constraints
   -> Alien Dictionary
   -> DP on DAG

5. Trick:
   "u before v"
   always means:
   u -> v

Humans invented prerequisites.
Now we maintain giant indegree arrays to survive academia.

*/