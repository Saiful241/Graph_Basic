#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define endl '\n'


const int N=1e5+10;


vector<vector<int>>adj(N);

vector<int>depth(N);

vector<int>height(N);


void dfs(int vertex,int parent)
{

	//cout<<vertex<<" ";

	for(int child:adj[vertex])
	{
		if(child==parent) continue;

		depth[child]=depth[vertex]+1;

		dfs(child,vertex);

		height[vertex]=max(height[vertex],height[child]+1);
	}
}


int main()
{

   ios_base::sync_with_stdio(false);
  cin.tie(NULL);

 int n;
 cin>>n;//number of nodes ,number of edges->(n-1)

 for(int i=0;i<n-1;i++)
 {
 	int x,y;
 	cin>>x>>y;

 	adj[x].push_back(y);
 	adj[y].push_back(x);//undirected graph


 }

 dfs(1,0);


 for(int i=1;i<=n;i++)
 {
 	cout<<"NODE: "<<i<<"-> Depth: "<<depth[i]<<" , Height: "<<height[i]<<endl;
 }

}