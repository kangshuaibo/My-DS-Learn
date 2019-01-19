/*
判别无向图中任意两个顶点之间是否存在长度为k的简单路径
*/
int vistied[MAXSIZE];
int exit_path_len(ALGraph G,int i,int j,int k)
{
	if(i==j && k==0) //找到了一条路径,且长度符合要求
		return 1;
	else if(k>0)
	{
		vistied[i]=1;
		for(p.vertices[i].firstarc;p;p->nextarc)
		{
			l=p->adjvex;	//l是p的临接点
			if(!vistied[l])
				if(exit_path_len(G,l,j,k-1))	//剩余路径长度减1
					return 1;
		}
		vistied[i]=0;//允许被访问过的点出现在别的路径中
	}


	return 0；//没找到
}