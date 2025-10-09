#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define endl '\n'

;


const int N=1e5+10;

vector<vector<int>>adj(N);

vector<bool>visited(N,false);


void dfs(int edge)
{
	visited[edge]=true;

	for(auto child:adj[edge])
	{
		if(visited[child]) continue;

		dfs(child);
	}
}







int main()
{

   ios_base::sync_with_stdio(false);
  cin.tie(NULL);

 
 int n,e;
 cin>>n>>e;

 for(int i=0;i<e;i++)
 {
 	int x,y;

 	cin>>x>>y;

 	adj[x].push_back(y);
 	adj[y].push_back(x);
 }


 int ans=0;

 for(int i=1;i<=n;i++)
 {
 	if(visited[i]) continue;

 	dfs(i);

 	ans++;
 }

 cout<<ans<<endl;

}