
/*7.26试证明,对有向图中顶点适当地编号,可使其邻接矩阵为下三角形且主对角
线为全零的充要条件是:该有向图不含回路。然后写一算法对无环有向图的顶点重新编
号,使其邻接矩阵变为下三角形,并输出新旧编号对照表。
*/

Status TopoNo(ALGraph G)//按照题目要求顺序重排有向图中的顶点
{
	int new[MAXSIZE],indegree[MAXSIZE]; //储存结点的新序号 
	n=G.vexnum;
	FindInDegree(G,indegree);
	InitStack(S);
	for(i=1;i<G.vexnum;i++)
	if(!indegree[i]) Push(S,i); //零入度结点入栈
	count=0; 
	while(!StackEmpty(S)) 
	{
		Pop(S,i);
		new[i]=n--; //记录结点的拓扑逆序序号 
		count++; 
		for(p=G.vertices[i].firstarc;p;p=p->nextarc) 
		{
			k=p->adjvex;
			if(!(--indegree[k])) Push(S,k); 
		}//for
	}//while

	if(count<G.vexnum) 
	return ERROR; //图中存在环 
	for(i=1;i<=n;i++) 
		printf("Old No:%d New No:%d\n",i,new[i]) 
	return OK;
}//TopoNo
//分析:只要按拓扑逆序对顶点编号,就可以使邻接矩阵成为下三角矩阵.