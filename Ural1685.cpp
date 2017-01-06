#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

const int M = 100+10;
int color[M], vis[M];
vector<int> G[M];

void dfs(int i){
	vis[i] = 1;
	for(int j = 0; j < G[i].size(); ++j){
		int v = G[i][j];
		if( !vis[v] )
		{
			color[v] = 3 - color[i];
			dfs(v); 
		}
	}
}
int main(){
	int n, t; 
	cin >> n;
	for(int i = 1; i <=n; ++i){
		while( scanf("%d", &t) && t){
			G[i].push_back(t);
		}
	}
	
	memset(vis, 0, sizeof(vis));
	memset(color, 0, sizeof(color));
	
	for(int i = 1; i <= n; ++i){
		if( !vis[i] ){
			color[i] = 1;
			dfs(i);
		}
	}
	
	int sum = 0;
	for(int i = 1; i <= n; ++i){
		if(color[i] == 1)
			++sum;
	}
	cout << sum << endl;
	for(int i = 1; i <= n; ++i){
		if(color[i] == 1)
			cout << i << ' ';
	}
}
