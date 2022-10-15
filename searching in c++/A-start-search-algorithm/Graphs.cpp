// Graphs.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include<vector>
#include<sstream>
#include<map>
#include<string>
#include<utility>
#include<algorithm>
using namespace std;
int no_of_vertex = 8;
struct edge
{
	int vertex,
		weight;
};
void findpath(vector<vector<edge>>obj, vector<int> heuristic);
map<int, char> output;
int main()
{

	output[1] = 'S';
	output[2] = 'B';
	output[3] = 'C';
	output[4] = 'F';
	output[5] = 'D';
	output[6] = 'E';
	output[7] = 'G';
	vector<vector<edge>>obj(no_of_vertex);
	obj[1].push_back({ 2,4 });//vertexno,weight
	obj[1].push_back({ 3,3 });
	obj[2].push_back({ 4,5 });
	obj[2].push_back({ 6,12 });
	obj[3].push_back({ 5,7 });
	obj[3].push_back({ 6,10 });
	obj[4].push_back({ 7,16 });
	obj[5].push_back({ 6,2 });
	obj[6].push_back({ 7,5 });
	for (int i = 1; i < no_of_vertex; i++)
	{
		cout << "for vertex " << output[i] << ":";
		for (int j = 0; j < obj[i].size(); ++j)
		{
			cout << output[obj[i][j].vertex] << ",";
		}
		cout << "\n";
	}
	vector<int> heuristic(8);
	pair<int, int>destiation;
	destiation.first = no_of_vertex - 1;
	destiation.second = 1;
	for (int i = 1; i < no_of_vertex; i++)
	{
		heuristic[i] = sqrt(pow((i - destiation.first), 2) + pow((1 - destiation.second), 2));
	}
	findpath(obj, heuristic);

}
void findpath(vector<vector<edge>>obj, vector<int> heuristic)
{
	struct find
	{
		int fn;
		vector<int> vertices;
	};
	vector<find>objects;
	vector<find>goods;

	for (int j = 0; j < obj[1].size(); ++j)
	{
		objects.push_back({ heuristic[obj[1][j].vertex] + obj[1][j].weight, {1,obj[1][j].vertex} });
	}
	sort(objects.begin(), objects.end(), [](find a, find b)
		{
			return a.fn < b.fn;
		});


	for (int i = 0; i < no_of_vertex - 1;)
	{

		i = objects[0].vertices[objects[0].vertices.size() - 1];
		for (int j = 0; j < obj[i].size(); j++)
		{
			int weight = 0;
			vector<int> all;
			auto it = objects[0].vertices.begin();
			for (; it < objects[0].vertices.end(); ++it)
			{

				if (it == objects[0].vertices.end() - 1)
				{
					all.push_back(*it);
					break;
				}
				int k = *(it + 1);
				int h = 0;
				for (; h < obj[*it].size(); h++)
				{
					if (obj[*it][h].vertex == k)
						break;
				}
				weight += obj[*it][h].weight;
				all.push_back(*it);
			}
			all.push_back(obj[i][j].vertex);
			objects.push_back({ weight + obj[i][j].weight + heuristic[obj[i][j].vertex],all });
			if (heuristic[obj[i][j].vertex] == 0)
			{
				goods.push_back({ weight + obj[i][j].weight + heuristic[obj[i][j].vertex],all });
			}

		}
		objects.erase(objects.begin());
		sort(objects.begin(), objects.end(), [](find a, find b)
			{
				return a.fn < b.fn;
			});

	}
	sort(goods.begin(), goods.end(), [](find a, find b)
		{
			return a.fn < b.fn;
		});
	cout << "SHORTEST PATH IS:";
	for (auto it : goods[0].vertices)
		cout << output[it];

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
