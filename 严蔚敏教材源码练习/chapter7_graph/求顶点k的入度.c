//分析 ：有向邻接表中求顶点的出度容易，只要在该点的邻接点中查个数
//而求入度则需要遍历整个邻接表

int count(AdjList g,int k)
{
	int count = 0;
	for(i=1;i<=n;i++)
		if(i!=k)		//顶点k的邻接链表不必计算（它是出度）
		{
			p=g[i].firstarc;	//取顶点i的邻接表（第i个）
			while(p)
			{
				if(p->adjvex==k)	//p的顶点信息为k 别人指向我了
					count++;
				p=p->next;
			}
		}
		return count;
}