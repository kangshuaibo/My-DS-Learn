/*
7.34③试编写一个算法,给有向无环图G中每个顶点赋以一个整数序号,并满足
以下条件:若从顶点i至顶点j有一条弧,则应使i<j。
*/

//拓扑排序

Status TopoSeq(ALGraph G,int new[ ])//按照题目要求给有向无环图的结点重新编号,并存入数组new 中
{
	int indegree[MAXSIZE]; //本算法就是拓扑排序 
	FindIndegree(G,indegree);
	Initstack(S);
	for(i=0;i<G.vexnum;i++)
		if(!indegree[i]) 
	
	Push(S,i); 
	count=0;
 	while(!stackempty(S))
 	{
		Pop(S,i);
		new[i]=++count; //把拓扑顺序存入数组的对应分量中

	 	for(p=G.vertices[i].firstarc;p;p=p->nextarc)
		{
			k=p->adjvex;
			if(!(--indegree[k])) 
				Push(S,k); 
		}
 	}//while

if(count<G.vexnum) 
	return ERROR; 
return OK;
}//TopoSeq