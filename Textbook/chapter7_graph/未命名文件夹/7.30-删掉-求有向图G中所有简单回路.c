/*
7.30⑤试写一个求有向图G中 所有 简单回路的算法。
*/

//分析:这个算法的思想是,在遍历中暂存当前路径,当遇到一个结点已经在路径之中时就表明存在一条 回路;
//扫描路径向量 path 可以获得这条回路上的所有结点.把结点序列(例如,142857)存入 thiscycle 中;
// 由于这种算法中,一条回路会被发现好几次,所以必须先判断该回路是否已经在 cycles 中被记录过,
//如 果没有才能存入 cycles 的一个行向量中.把 cycles 的每一个行向量取出来与之比较.由于一条回路可能 有多种存储顺序,
//比如 142857 等同于 285714 和 571428,所以还要调整行向量的次序,并存入 temp 数组, 
//例如,thiscycle 为 142857 第一个结点为 1,cycles 的当前向量为 857142,
//则找到后者中的 1,把 1 后部分 提到 1 前部分前面,最终在 temp 中得到 142857,
//与 thiscycle 比较,发现相同,因此 142857 和 857142 是 同一条回路,不予存储.
//这个算法太复杂,很难保证细节的准确性,大家理解思路便可.希望有人给出更 加简捷的算法.

int visited[MAXSIZE];
int path[MAXSIZE];	//暂存当前路径
int cycles[MAXSIZE];	//储存发现的回路所包含的结点
int thiscycle[MAXSIZE];	//储存当前发现的一个回路

int cycount=0	//已经发现的回路个数

void GetAllCycle(ALGraph G)
{
	for(v=0;v<G.vexnum;v++)		//求有向图中所有简单回路
		visited[v]=0;	//初始化

	for(v=0;v<G.vexnum;v++)
		if(!visited[v])
			DFS(G,v,0)
}//DFSTraverse

void DFS(ALGraph G,int v,int k)		//k为当前节点在路径上的序号
{
	visited[v]=1;
	path[k]=v;
	for(p=G.vertices[v].firstarc; p ;p=p->nextarc)
	{
		w=p->adjvex;
		if(!visited[w])
			DFS(G,w,k+1);
		else
		{for(i=0;path[i]!=w;i++)
			for(j=0;path[i+j];i++)
				thiscycle[j]=path[i+j];	//把回路复制下来
		if(!exit_cycle())
			cycles[cycount++]=thiscycle;//如果该回路尚未被记录过 就添加到记录中

		for(i=0;i<G.vexnum;i++)
			thiscycle[i]=0;

		}
	}
	path[k]=0;
	 visited[k]=0;//一旦遍历中发现当前接待你visited为真，即表示发现了一条回路	
}//DFS

int exist_cycle()//判断 thiscycle 数组中记录的回路在 cycles 的记录中是否已经存在
{
int temp[MAXSIZE];
	for(i=0;i<cycount;i++) //判断已有的回路与 thiscycle 是否相同 
	{ //也就是,所有结点和它们的顺序都相同
		j=0;
		c=thiscycle[j];; //例如,142857 和 857142 是相同的回路
		for(k=0;cycles[i][k]!=c&&cycles[i][k]!=0;k++);//在 cycles 的一个行向量中寻找等于 thiscycle 第一 个结点的元素
		if(cycles[i][k]) //有与之相同的一个元素 
		{
			for(m=0;cycles[i][k+m];m++) 
				temp[m]=cycles[i][k+m];
			for(n=0;n<k;n++,m++)
				temp[m]=cycles[i][n]; //调整 cycles 中的当前记录的循环相位并放入 temp 数组中
			if(!StrCompare(temp,thiscycle)) //与 thiscycle 比较 return 1; //完全相等
			for(m=0;m<G.vexnum;m++)
			 	temp[m]=0; //清空这个数组 
		}
	}//for


return 0; //所有现存回路都不与 thiscycle 完全相等

}//exist_cycle
























