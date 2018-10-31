/*
7.35④若在DAG图中存在一个顶点r,在和图中所有其他顶点之间均存在由r出发的有向路径,
则称该DAG图有根。试编写求DAG图的根的算法。
*/

int visited[MAXSIZE];
void Get_Root(ALGraph G)//求有向无环图的根,如果有的话 
{
	for(v=0;v<G.vexnum;v++)
  	{
		for(w=0;w<G.vexnum;w++)
	 		visited[w]=0;	//每次都要将访问数组清零 

		DFS(G,v);	 //从顶点 v 出发进行深度优先遍历 

		for(flag=1,w=0;w<G.vexnum;w++)
			if(!visited[w]) 
				flag=0; 	//😄如果 v 是根,则深度优先遍历可以访问到所有结点

		if(flag) 
			printf("Found a root vertex:%d\n",v);
	}//for 
}//Get_Root,这个算法要求图中不能有环,否则会发生误判


void DFS(ALGraph G,int v)
{
	visited[v]=1; 
	for(p=G.vertices[v].firstarc;p;p=p->nextarc) 
	{
		w=p->adjvex;
		if(!visited[w])
		  DFS(G,w); 
	}
}//DFS