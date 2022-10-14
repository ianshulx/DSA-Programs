#include <iostream>
#include <vector>
#define noOfVertices 4
using namespace std;

int findMinVertex(vector<bool>& included, vector<int>& values){
	int minIndex, minValue = INT_MAX;
	for (int i=0; i<noOfVertices; ++i){
		if (!included[i] && values[i]<minValue){
			minValue = values[i];
			minIndex = i;
		}
	}
	return minIndex;
}

void primsAlgo(int graph[][noOfVertices]){
	vector<bool> included(noOfVertices, false);
	vector<int> values(noOfVertices, INT_MAX);
	int parents[noOfVertices];
	parents[0] = -1;
	values[0] = 0;
	int i, j, u;
	for (i=0; i<noOfVertices-1; ++i){
		u = findMinVertex(included, values);
		included[u] = true;
		for (j=0; j<noOfVertices; ++j){
			if (!included[j] && graph[u][j] != 0 && values[j]>graph[u][j]){
				values[j] = graph[u][j];
				parents[j] = u;
			}
		}
	}
	
	for (i=1; i<noOfVertices; ++i){
		cout<<"U->V: "<< parents[i]<<"->"<<i<<"  wt = "<< graph[parents[i]][i] << endl;
	}
}

int main(){
	int graph[4][4] = {{0,5,8,0},
					   {5,0,2,0},
					   {8,0,2,7},
					   {0,0,7,0}};
	primsAlgo(graph);
	return 0;
}