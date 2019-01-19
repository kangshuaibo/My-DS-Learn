/*
利用栈的基本操作编写，按深度优先搜索策略遍历一个强连通图的非递归算法
*/

//在深度优先搜索的非递归算法中使用了一个栈S，记忆下一步可能访问的顶点，同时使用了一个访问标记数组visited[i],
//在visited[i]中记忆第i个顶点是否曾经在栈内，若是则不能再进栈，采用临接表存储

void DFS_Non_RC(AGraph &G,int v)//从顶点v开始遍历
{
	int w;	//顶点序号
	InitStack(S);
	for(i=0;i<G.vexnum;i++)
		visited[i]=FALSE;	//初始化visited栈

	Push(S,v);
	visitd[v]=TRUE;
	while(!IsEmpty(S))
	{
		k=Pop;
		visit(k);
		for(w=FirstNeighbor(G,k);w>=0;NextNeighbor(G,k,w))
			if(!visited[w])
			{
				Push(S,w);
				visited[w]=TRUE;
			}
	}
}//从右到左的方式