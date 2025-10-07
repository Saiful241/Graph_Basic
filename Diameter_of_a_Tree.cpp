#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define endl '\n'



// A diameter of the tree a→b
//  is the longest path, i.e., the one that maximizes dist(a,b)
//  over all pairs of nodes. If there are multiple diameters, let's pick any of them.

// The same definition is valid for a weighted tree with nonnegative weights (with dist(a,b)=
//  the sum of the weights of the edges in the simple path a→b).



// Given a tree with n
//  nodes are multiple ways to find a diameter. Here is one of the simplest ways:

// Run a DFS from any node p
//  Let 'a'  be a node whose distance from node p
//  is maximized. Run another DFS from node 'a'

//  Let 'b' be a node whose distance from node 'a'
//  is maximized. a→b  is a diameter.


const int N=1e5+10;

vector<vector<int>>adj(N);

vector<int>depth(N);

void dfs(int vertex,int parent)
{

	for(auto child:adj[vertex])
	{
		if(child==parent) continue;

		depth[child]=depth[vertex]+1;

		dfs(child,vertex);
	}
}




int main()
{

   ios_base::sync_with_stdio(false);
  cin.tie(NULL);

 int n;
 cin>>n;

 for(int i=0;i<n-1;i++)
 {
 	int x,y;
 	cin>>x>>y;

 	adj[x].push_back(y);
 	adj[y].push_back(x);//undirected graph


 }

 dfs(1,0);

 int mx_depth=-1;

 int mx_node=-1;

 for(int i=1;i<=n;i++)
 {
 	if(depth[i]>mx_depth)
 	{
 		mx_depth=depth[i];
 		mx_node=i;
 	}
 }

 for(int i=1;i<=n;i++) depth[i]=0;

 int a=mx_node;

 dfs(mx_node,0);

 mx_depth=-1;
 mx_node=-1;




 for(int i=1;i<=n;i++)
 {
 	if(depth[i]>mx_depth)
 	{
 		mx_depth=depth[i];
 		mx_node=i;
 	}
 }

 int b=mx_node;

 cout<<a<<" "<<b<<endl;

}