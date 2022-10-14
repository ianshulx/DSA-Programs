#include <iostream>
#include <vector>
#define noOfVertices 4
using namespace std;

class Edge{
	private:
		int source;
		int destination;
		int cost;
	public:
		Edge(): source(0), destination(0), cost(0){}
		Edge(int source, int destination, int cost): source(source), destination(destination), cost(cost){}
		friend void bellmanFord(vector<Edge>& edges);
};

vector<Edge> getEdges(int graph[noOfVertices][noOfVertices]){
	vector<Edge> edges;
	for (int i=0; i<noOfVertices; ++i){
		for (int j=0; j<noOfVertices; ++j){
			if (graph[i][j] != 0){
				Edge temp(i, j, graph[i][j]);
				edges.push_back(temp);
			}
		}
	}
	return edges;
}

void bellmanFord(vector<Edge>& edges){
	int parents[noOfVertices];
	vector<int> value(noOfVertices, INT_MAX);
	parents[0] = -1;
	value[0] = 0;
	int u, v, cost;
	bool updated;
	for (int i=0; i<noOfVertices-1; ++i){
		updated = false;
		for (int j=0; j<edges.size(); ++j){
			u = edges[j].source;
			v = edges[j].destination;
			cost = edges[j].cost;
			if (value[u] != INT_MAX && cost+value[u] < value[v]){
				value[v] = cost+value[u];
				parents[v] = u;
				updated = true;
			}
		}
		if (!updated)
			break;
	}
	for (int i=0; (i<noOfVertices-1) && updated; ++i){
		int u = edges[i].source;
		int v = edges[i].destination;
		int cost = edges[i].cost;
		if (value[u] != INT_MAX && value[u]+cost<value[v]){
			cout<<"Graph has -VE edge cycle\n";
			return;
		}
	}
	for (int i=1; i<noOfVertices; ++i){
		cout<<"U->V: "<<parents[i]<<"->"<<i<<"  Cost to reach "<<parents[i]<<"from source 0 = " << value[i] << endl;
	}
}

int main(){
	int graph[4][4] = {{0,5,8,0},
					   {0,0,2,0},
					   {0,0,0,7},
					   {0,0,0,0}};
	vector<Edge> edges = getEdges(graph);
	bellmanFord(edges);
	return 0;
}