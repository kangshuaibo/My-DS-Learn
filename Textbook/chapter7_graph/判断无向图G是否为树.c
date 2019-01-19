//G必须是无回路的连通图 或 有n-1条边的连通图。
//对于连通的判定：能否遍历全部顶点。深度优先遍历统计顶点个数和边的条数，如果一次就能遍历访问到n个顶点和n-1条边 是树

bool IsTree(Graph G)
{
	for(i=1;i<G.Vexnum;i++)	//初始化
		visited[i]=FALSE;

	int Vnum=0,Enum=0;			//记录顶点数和边数

	DFS(G,1,Vnum,Enum,visited);
	
	if(Vnum==G.Vexnum && Enum==2*(G.Vexnum-1))
		return true;
	else
		return false;
}

void DFS(Graph &G,int v,int &Vnum,int &Enum,int visited[])	//深度优先遍历 统计访问过的顶点数和边数，通过Vnum和Enum来返回
{
	visited[v]=TRUE;
	Vnum++;
	int w=FirstNeighbor(G,v);	//取v的第一个邻接点
	while(w!=-1)	//当邻接顶点存在
	{
		Enum++;
		if(!visited[w])
			DFS(G,w,Vnum,Enum,visited);
		w=NextNeighbor(G,v,w);
	}
}