void Convert(ALGraph G,int arcs[M][N])
{
	for(i=0;i<n;i++)
	{
		p=G.vertexs[i].firstarc;	//依次遍历边链表
		while(p!=NULL)
		{
			arcs[i][p->data]=1;
			p=p->nextarc;
		}
	}
}