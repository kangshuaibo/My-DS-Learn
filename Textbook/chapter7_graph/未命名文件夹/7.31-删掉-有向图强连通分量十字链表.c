/*
7.31③试完成求有向图的强连通分量的算法,并分析算法的时间复杂度
*/

int visited[MAXSIZE];
int finished[MAXSIZE];
int count; //count 在第一次深度优先遍历中用于指示 finished 数组的填充位置
void Get_SGraph(OLGraph G)//求十字链表结构储存的有向图 G 的强连通分量
{
	count=0;
	for(v=0;v<G.vexnum;v++) 
		visited[v]=0;
	for(v=0;v<G.vexnum;v++) //第一次深度优先遍历建立 finished 数组
		if(!visited[v]) 
			DFS1(G,v);
	for(v=0;v<G.vexnum;v++) 
	visited[v]=0; //清空 visited 数组 
	for(i=G.vexnum-1;i>=0;i--) //第二次逆向的深度优先遍历 
	{
		v=finished(i); 
		if(!visited[v]) 
		{
			printf("\n"); //不同的强连通分量在不同的行输出
			DFS2(G,v); 
		}
	}//for
}//Get_SGraph


void DFS1(OLGraph G,int v)//第一次深度优先遍历的算法 
{
	visited[v]=1; 
	for(p=G.xlist[v].firstout;p;p=p->tlink) 
	{
		w=p->headvex; 
		if(!visited[w]) 
			DFS1(G,w);

  	}//for
	finished[++count]=v; //在第一次遍历中建立 finished 数组 
}//DFS1


void DFS2(OLGraph G,int v)//第二次逆向的深度优先遍历的算法 
{
	visited[v]=1;
	printf("%d",v); //在第二次遍历中输出结点序号 
	for(p=G.xlist[v].firstin;p;p=p->hlink)
	{
		w=p->tailvex;
		if(!visited[w]) 
		DFS2(G,w); 
	}//for
}//DFS2


//分析:求有向图的强连通分量的算法的时间复杂度和深度优先遍历相同,也为 O(n+e).

