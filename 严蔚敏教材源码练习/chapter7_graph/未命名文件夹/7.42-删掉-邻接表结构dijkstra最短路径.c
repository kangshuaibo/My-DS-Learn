void ALGraph_DIJ(ALGraph G,int v0,Pathmatrix &P,ShortestPathTable &D)//在邻接表存储结构上实现 迪杰斯特拉算法
{
	for(v=0;v<G.vexnum;v++) 
		D[v]=INFINITY;
	for(p=G.vertices[v0].firstarc;p;p=p->nextarc) 
		D[p->adjvex]=*p->info; //给 D 数组赋初值
	for(v=0;v<G.vexnum;v++) 
	{
		final[v]=0;
		for(w=0;w<G.vexnum;w++) 
			P[v][w]=0; //设空路径 
		if(D[v]<INFINITY)
		{
			P[v][v0]=1;
			P[v][v]=1; 
		}
	}//for

	D[v0]=0;final[v0]=1; //初始化
  	for(i=1;i<G.vexnum;i++) 
  	{
		min=INFINITY; 
		for(w=0;w<G.vexnum;w++)
		if(!final[w])
		if(D[w]<min) //尚未求出到该顶点的最短路径 
		{
			v=w;
			min=D[w]; 
		}
		final[v]=1; 
		for(p=G.vertices[v].firstarc;p;p=p->nextarc)
		{
			w=p->adjvex;
			if(!final[w]&&(min+(*p->info)<D[w])) //符合迪杰斯特拉条件 
			{
				D[w]=min+edgelen(G,v,w); P[w]=P[v];
				P[w][w]=1; //构造最短路径
			} 
		}//for
	}//for
}//ALGraph_DIJ 

//分析:本算法对迪杰斯特拉算法中直接取任意边长度的语句作了修改.由于在原算法中,每次循环都是 对尾相同的边进行处理,所以可以用遍历邻接表中的一条链来代替.
 