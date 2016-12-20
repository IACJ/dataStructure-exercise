#include <iostream>
#include <vector>
#include <list>

using namespace std;


class Graph_matrix {
private:
	int numVertex;
	int numEdge;
	vector< vector<int> > matrix;
	vector<int> mark;

public:
	Graph_matrix(int numVert) {
		Init(numVert);
	}

	//Opration of Edges
	void addEdge(int v1, int v2, int wt = 1) {
		if (matrix[v1][v2] == 0) {
			numEdge++;
		}
		matrix[v1][v2] = wt;
	}


	//Opration of marks
	void initMark(int flag = 0) {
		mark.clear();
		mark.insert(mark.begin(), numVertex, flag);
	}
	void setMark(int v, int flag = 1) {
		mark[v] = flag;
	}
	int getMark(int v) {
		return mark[v];
	}

	void bfs(int begin) {
		initMark();

		list<int> ll;
		vector<int> mark_inqueue(numVertex, 0);

		ll.push_back(begin);
		cout << begin;

		while (ll.size() != 0) {
			int v1 = ll.front();
			ll.pop_front();

			setMark(v1, 1);

			for (int i = 0; i < numVertex; i++) {
				if (getMark(i) == 0 && matrix[v1][i] == 1 && mark_inqueue[i] == 0) {
						cout << ' ' << i;
						ll.push_back(i);
						mark_inqueue[i] = 1;
				}
			}
		}

	}


private:
	void Init(int n) {
		numVertex = n;
		numEdge = 0;

		mark.insert(mark.begin(), n, 0);
		matrix.insert(matrix.begin(), n, vector<int>(n, 0));
	}

};

int main() {
	int m;
	cin >> m;
	while (m--) {
		int n, e, s;
		cin >> n >> e >> s;

		Graph_matrix g(n);

		int temp1, temp2;
		for (int i = 0; i < e; i++) {
			cin >> temp1 >> temp2;
			g.addEdge(temp1, temp2);
			g.addEdge(temp2, temp1);
		}

		g.bfs(s);
		cout << endl;

	}
}