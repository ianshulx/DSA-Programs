//Strongly connected graph
#include <bits/stdc++.h>
using namespace std;
int BFS(vector<int>adj[],int s,int n)
{
    bool visited[n]={false};

    queue<int> q;
    visited[s]=true;
    q.push(s);

    while(!q.empty()){
        int t=q.front();
        for(int i=0;i<adj[t].size();i++){
            if(!visited[adj[t][i]]){
                visited[adj[t][i]]=true;
                q.push(adj[t][i]);
            }
        }
    }

    for(int i=0;i<n;i++){
        if(visited[i] == false)
        {
           return 1;
        }
    }
    return 0;
}

int main()
{
    int n;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of Edges: ";
    int e;
    cin>>e;
    vector<int> adj[n];
    for(int i=0;i<e;i++){
        a:int temp1,temp2;
        cout<<"Enter source and destination: ";
        cin>>temp1>>temp2;
        if(temp1>=n || temp2>=n){
            cout<<"Error"<<endl;
            goto a;
        }
        adj[temp1].push_back(temp2);
    }
    int x,flag{1};
    for(int i=0;i<n;i++){
        x = BFS(adj,i,n);
        if(x == 1){
            flag = 0;
            break;
        }
    }
    if(flag ==0){
        cout<<"Not a strongly connected graph";
    }
    else{
        cout<<"Strongly connected graph";
    }
}
