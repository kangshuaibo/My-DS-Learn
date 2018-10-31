/*
试编写求无向图G的连通分量的算法，要求输出每一连通分量的顶点值（邻接表存储）
*/

//分析：使用图的遍历可以求出图的连通分量 进入DFS或BFS一次 就可以访问到图的一个连通分量的所有顶点
void dfs(int v)
{
	visited[v]=1;
	 printf("%d",v );	//输出连通分量的顶点
	 p=g[v].firstarc;
	 while(p!=NULL)
	 {
	 	if(!visited[p->adjvex])
	 		DFS(p->adjvex);
	 	p=p->next;
	 }
}

void Count()	//调用求连通分量
{
	int k=0;
	static Adjlist g;	//设无向图g有n个顶点
	for(i=1;i<=n;i++)
		if(visited[i]==0)
		{
			printf("第%d个连通分量：\n",++k );
			DFS(i);
		}
}