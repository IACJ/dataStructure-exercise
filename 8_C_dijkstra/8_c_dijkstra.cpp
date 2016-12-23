#include <iostream>
#include <vector>
#include <list>
#include <string>

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

	vector<int> ans;

public:
	Graph_list(int numVert) {
		Init(numVert);
	}


	//Opration of Edges
	void addEdge(int v1, int v2, int wt = 1) {

		lists[v1].push_back(Edge(v2, wt));

		lists_inv[v2].push_back(Edge(v1, wt));

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

	bool hasHuan() {

		initMark();
		vector< int >  topo(numVertex, 0);

		for (int i = 0; i < numVertex; i++) {
			topo[i] = lists_inv[i].size();
		}

		list<int> queue;


		do {


			for (int i = 0; i < numVertex; i++) {
				if (!getMark(i) && topo[i] == 0) {
					setMark(i);
					queue.push_back(i);

				}
			}

			if (queue.size() == 0) {
				break;
			}

			int tempV = queue.front();
			queue.pop_front();

			list<Edge>::iterator it = lists[tempV].begin();

			while (it != lists[tempV].end()) {

				if (!getMark(it->toVertex)) {
					topo[it->toVertex] --;
				}

				it++;
			}


		} while (1);

		for (int i = 0; i < numVertex; i++) {
			if (!getMark(i)) {
				return true;
			}
		}
		return false;
	}

	//dijstra
	void shortest(int Ts, int Te) {
		vector<int>  flushArr(numVertex, 9999999);
		vector<int>  shortestArr(numVertex, 9999999);
		ans.insert(ans.begin(), numVertex, 0);
		initMark();


		setMark(Ts);
		shortestArr[Ts] = 0;
		int tempV = Ts;

		//================

		while (1) {

			list<Edge>::iterator it = lists[tempV].begin();
			while (it != lists[tempV].end()) {

				if (!getMark(it->toVertex) && flushArr[it->toVertex] > shortestArr[tempV] + it->weight) {
					flushArr[it->toVertex] = shortestArr[tempV] + it->weight;



					ans[it->toVertex] = tempV;
				}
				it++;
			}

			tempV = -1;
			for (int i = 0; i < numVertex; i++) {
				if ((!getMark(i)) && (tempV == -1 || flushArr[i] < flushArr[tempV])) {


					tempV = i;
				}
			}

			setMark(tempV);
			shortestArr[tempV] = flushArr[tempV];



			if (tempV == Te) {






				print_rec(Ts, Te);
				cout << endl;
				return;
			}
		}

	}


	void print_rec(int Ts, int Tnum) {




		if (Tnum == Ts) {
			cout << Ts + 1;
		}
		else {
			print_rec(Ts, ans[Tnum]);
			cout << " " << Tnum + 1;
		}
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
		int n, e, Ts, Te;
		cin >> n >> e >> Ts >> Te;

		Graph_list g(n);


		int temp1, temp2, c;
		for (int i = 0; i < e; i++) {
			cin >> temp1 >> temp2 >> c;
			g.addEdge(temp1 - 1, temp2 - 1, c);
			g.addEdge(temp2 - 1, temp1 - 1, c);
		}

		g.shortest(Ts - 1, Te - 1);



	}
}