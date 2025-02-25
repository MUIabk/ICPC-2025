int nodes = 0;
int subtree[N], parentcentroid[N];
set<int> g[N];
void dfs(int u, int par)
{
	nodes++, subtree[u] = 1;
	for(auto &it:g[u])
	{
		if(it == par) continue;
		dfs(it, u);
		subtree[u] += subtree[it];
	}
}
int centroid(int u, int par)//this par will be assigned to the centroid
{
	for(auto &it:g[u])
	{
		if(it == par)continue;
		if(subtree[it] > (nodes >> 1))
			return centroid(it,u);
	} return u;
}
void decompose(int u, int par)
{
	nodes = 0;
	dfs(u, u);
	int node = centroid(u, u);
	parentcentroid[node] = par;
	for(auto &it:g[node])
	{
		g[it].erase(node);
		decompose(it, node);
	}
}
