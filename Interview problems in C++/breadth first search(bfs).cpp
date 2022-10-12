#include <iostream>
#include<map>
#include<vector>
#include <queue>
using namespace std;





class graph{
    public:
    map<char,vector<char>>adjlist;
    void addEdge(char node1,char node2,bool isdirectional);
    void bfs(char src);
};

void graph::addEdge(char node1,char node2,bool isdirectional=true){
    adjlist[node1].push_back(node2);
    if(isdirectional){
        adjlist[node2].push_back(node1);
    }
}

void graph::bfs(char src){
    queue<char>q;
    map<char,bool>visited;
    q.push(src);
    visited[src]=true;
    while (!q.empty()){
        char node=q.front();
        cout<<node<<"; ";
        q.pop();
        for(char neighbor:adjlist[node]){
            if(!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor]=true;
            }
        }
    }
}

int main(){
    graph g;
    g.addEdge('a','b');
    g.addEdge('b','c');
    g.addEdge('c','d');
    g.addEdge('b','e');
    g.addEdge('e','f');
    g.addEdge('f','i');
    g.addEdge('i','j');
    g.addEdge('d','k');
    g.bfs('a');
}
