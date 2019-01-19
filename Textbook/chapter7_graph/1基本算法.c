//-------------------------------------广度优先搜索BFS
bool visited[MAXSIZE];
void BFSTraverse(Graph G)
{
	for(i=0;i<G.vexnum,++i)
		visited[i]=FALSE;
	InitQueue(Q);
	for(i=0;i<G.vexnum;++i)
		if(!visited[i])
			BFS(G,i);
}

void BFS(Graph G,int v)
{
	visit(v);
	visited[v]=TRUE;
	EnQueue(Q,v);
	while(!IsEmpty)
	{
		DeQueue(Q,v);
		for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
			if(!visited[w])
			{
				visit(w);
				visited[w]=TRUE;
				EnQueue(Q,w);
			}
	}
}



//-----------------------------------------深度优先搜索

//递归
bool visited[MAXSIZE];

void DFSTraverse(Graph G)
{
	for(v=0;v<G.vernum;++v)
		visited[v]=FALSE;	//初始化

	for(v=0;v<G.vexnum;++v)
		if(!visited[v])
			DFS(G,v);
}

void DFS(Graph G,int v)	
{
	visit(v);
	visited[v]=TRUE;
	for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
		if(!visited[w])
		{
			DFS(G,w);
		}
}


//非递归
void DFS_Non_RC(Graph &G,int v)
{
	int w;
	InitStack(S);
	for(i=0;i<G.vexnum;++i)
		visited[i]=FALSE;	//初始化

	Push(S,v);
	visited[v]=TRUE;
	while(!IsEmpty)
	{
		k=Pop(S);
		visit(k);
		for( w=FirstNeighbor(G,k)  ;w>=0;  w=NextNeighbor(G,k,w)  )	   //k的邻接点
			if(!visited[w])
			{
				Push(S,w);
				visited=TRUE;
			}
			
	}
}
	
