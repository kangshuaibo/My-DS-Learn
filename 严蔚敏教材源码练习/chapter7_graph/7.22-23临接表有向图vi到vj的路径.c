/*
基于图的 深度优先 搜索，判别以临接表方式存储的有向图是否存在vi到vj的路径
*/
//分析：从顶点vi出发，依次遍历图中每个顶点，直到搜索的顶点vj，如果能搜索到vj，则说明存在vi到vj的路径


int visited[MAXSIZE]={0};	//访问标记数组

int Exist_Path_DFS(ALGraph G,int i,int j)//图以临接表方式 取名字AL
{
	int p;		//顶点序号
	if(i==j)
		return 1;
	else
	{
		visited[i]=1;	//置访问标记
		for(p=FirstNeighbor(G,i);p>=0;p=NextNeighbor)(G,i,p)//依次检查第i个节点的临界点p
			if(!visited[k] && Exist_Path_DFS(G,p,j))	//递归检测临接点
				return 1;
	}
	return 0;





/*
基于图的 广度优先 搜索，判别以临接表方式存储的有向图是否存在vi到vj的路径
*/

int visited[MAXSIZE]={0};
int Exist_Path_DFS(ALGraph G,int i,int j)
{
	InitQueue(Q);
	EnQueue(Q,u);
	whlie(!IsEmpty(Q))
	{
		DeQueue(Q,u);
		visited[u]=1;
		for(p=FirstNeighbor(G,i);p;p=NextNeighbor(G,i,p))
	}
}