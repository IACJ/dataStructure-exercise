#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Edge {
public:
	int toVertex;
	int weight;
	Edge(int v2 = 0, int weight = 0) {
		this->toVertex = v2;
		this->weight = weight;
	}
};

class Graph_list {
private:
	int numVertex;
	vector<  list<Edge>  > lists;
	vector<  list<Edge>  > lists_inv;
	vector<int> mark;

public:
	Graph_list(int numVert) {
		Init(numVert);
	}

	//Opration of Edges
	void addEdge(int v1, int v2, int wt = 1) {

		lists[v1].push_back(Edge(v2, wt));
		lists_inv[v2].push_back(Edge(v1, wt));
	}

	int maxIndegree() {
		int ans = 0;
		for (int i = 0; i < numVertex; i++) {
			if (lists_inv[i].size() > ans) {
				ans = lists_inv[i].size();
			}
		}
		return ans;
	}

private:
	void Init(int n) {
		numVertex = n;
		mark.insert(mark.begin(), n, 0);
		lists.insert(lists.begin(), n, list<Edge>());
		lists_inv.insert(lists_inv.begin(), n, list<Edge>());
	}
};

int main() {
	int m;
	cin >> m;
	while (m--) {
		int n, e;
		cin >> n >> e;

		Graph_list g(n);

		int temp1, temp2;
		for (int i = 0; i < e; i++) {
			cin >> temp1 >> temp2;
			g.addEdge(temp1-1, temp2-1);
		}

		cout << g.maxIndegree() << endl;
	}
}