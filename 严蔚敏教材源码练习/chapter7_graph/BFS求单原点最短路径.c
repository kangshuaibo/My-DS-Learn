//G为非带权图 u到v的最短路径d(u,v)为边最少，若无通路则d(u,v)=∞

//这是利用了广度优先搜索总是由近到远遍历图中每个节点的性质决定的
void BFS_MIN_Distance(Graph G,int u)
{
	for(i=0;i<G.vexnum;++i)//初始化
		d[i]=∞;

	visited[u]=TRUE;
	d[u]=0;
	EnQueue(Q,u);
	while(!IsEmpty(Q))
	{
		DeQueue(Q,u);
		for(w=FirstNeighbor(G,u);w>=0;w=NextNeighbor(G,u,w))	//w为u尚未访问的邻接点
			if(!visited[w])
			{
				visited[w]=TRUE;
				d[w]=d[u]+1;	//路径长度增加一
				EnQueue(Q,w);
			}
	}
}