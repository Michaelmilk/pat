#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>

using namespace std;

const int maxx = 10001;

map<int,vector<int> > tree;
set<int> res;
set<int> tres;
int pre[maxx],cnt,maxn = -1;
int visit[maxx];
int set_size[maxx];
int root[maxx];//the root of every node

void dfs(int p,int step){
	if(step>maxn){
		res.clear();
		res.insert(p);
		maxn = step;
	}else if(step==maxn){
		res.insert(p);
	}

	vector<int>::iterator ite = tree[p].begin();
	for(;ite!=tree[p].end();++ite){
		if(visit[*ite]!=1){
			visit[*ite] = 1;
			dfs(*ite,step+1);
			visit[*ite] = 0;
		}
	}
}

void init(int n){
	int i;

	for(i=1;i<=n;++i){
		pre[i]=i;
		visit[i]=0;
	}
}

/*
int root(int x){
	if(x!=pre[x]){
		pre[x] = root(pre[x]);
	}
	return pre[x];
}

void merge(int x,int y){
	int fa = root(x);
	int fb = root(y);
	if(fa!=fb){
		pre[fa] = fb;
		--cnt;
	}
}
*/

int GetRoot(int n)
{
	if(root[n] == n)
	{
		return n;
	}

	return root[n] = GetRoot(root[n]);
}

void UnionSet(int s, int e)
{
	int s_root = GetRoot(s);
	int e_root = GetRoot(e);
	// cout << s << " " << s_root << endl;
	// cout << e << " " << e_root << endl;
	if(s_root == e_root)
	{
		return;
	}

	if(set_size[s] < set_size[e])
	{
		set_size[e] += set_size[s];
		root[s] = e_root;
	}
	else
	{
		set_size[s] += set_size[e];
		root[e] = s_root;
	}
}

int main(){
	int n,i,a,b;
	set<int>::iterator ite;
	scanf("%d",&n);
	cnt = n-1;
for(int i = 1; i <= n; i++)
	{
		set_size[i] = 1;
		root[i] = i;
	}
	init(n);

	for(i=1;i<n;++i){
		scanf("%d %d",&a,&b);
		tree[a].push_back(b);
		tree[b].push_back(a);
		UnionSet(a,b);
	}
  
  int count = 0;
	for(int i = 1; i <= n; i++)
	{
		if(root[i] == i)
		{
			//cout << node_num << " " << i << endl;
			count++;
		}
	}

	if(count > 1){
		printf("Error: %d components\n",count);
		return 0;
	}

	visit[1] = 1;
	dfs(1,1);
	visit[1] = 0;//因为已经是树，所以不会再有环了，所以所有dfs后都恢复该点的可访问性很重要

	ite = res.begin();
	for(;ite!=res.end();++ite){
		tres.insert(*ite);
	}

	
	int point = (*res.begin());
	visit[point] = 1;
	dfs(point,1);
	visit[point] = 0;

	ite = res.begin();
	for(;ite!=res.end();++ite){
		tres.insert(*ite);
	}

	ite = tres.begin();
	for(;ite!=tres.end();++ite){
		printf("%d\n",*ite);
	}

	return 0;
}