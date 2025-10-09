#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define endl '\n'

const int N=1e5+10;

vector<vector<int>>adj(N);

vector<int>par(N);




void dfs(int vertex,int parent)
{
	par[vertex]=parent;


	for(auto&child:adj[vertex])
	{
		if(child==parent) continue;


		dfs(child,vertex);
	}

}

vector<int> path(int vertex)
{
	vector<int>ans;

	while(vertex!=0)
	{
		ans.push_back(vertex);
		vertex=par[vertex];
	}

	reverse(ans.begin(),ans.end());
	return ans;
}



int main()
{

   ios_base::sync_with_stdio(false);
  cin.tie(NULL);

 int n;
 cin>>n;//number of nodes,so number edges->(n-1)

 for(int i=0;i<n-1;i++)
 {
 	int x,y;
 	cin>>x>>y;

 	adj[x].push_back(y);
 	adj[y].push_back(x);//undirected graph;
 }

 int x,y;//need to find lca of x,y

 cin>>x>>y;


 dfs(1,0);

 vector<int>path_x=path(x);
 vector<int>path_y=path(y);



 int size=min(path_x.size(),path_y.size());

 int lca=-1;


 cout<<x<<"-> ";

 for(auto&p:path_x) cout<<p<<" ";

 	cout<<endl;

 cout<<y<<"-> ";


 for(auto&p:path_y) cout<<p<<" ";

 	cout<<endl;

 for(int i=0;i<size;i++)

 {
 	if(path_x[i]==path_y[i])
 	{
 		lca=path_x[i];
 	}

 	else break;
 }

 cout<<"LCA-> "<<lca<<endl;

}