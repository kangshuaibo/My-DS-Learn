/*
7.29⑤试写一个算法,在以邻接矩阵方式存储的有向
图G中求顶点i到顶点j的不含回路的、长度为k的路径数。
*/

int GrtPathNum_Len(ALGraph G,int i,int j,int len)
{
	if(i==j && len==0)
		return 1;	//找到了一条路径 且长度符合要求
	else if 
	{
		sum=0;	//表示通过本节点的路径数
		visited[i]=1;
		for(p=G.vertices[i].firstarc; p ; p=p->nextarc)
		{
			l=p->adjvex;
			if(!visited[l])
				sum+=GetPathNum_Len(G,l,j,len-1)
		}
		visited[i]=0;
	}
	return sum;
}