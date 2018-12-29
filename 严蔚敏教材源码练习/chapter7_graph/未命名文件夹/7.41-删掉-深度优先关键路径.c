/*
7.41④试编写利用深度优先遍历有向图实现求关键路径的算法。
*/
void Critical_Path(ALGraph G)//利用深度优先遍历求网的关键路径
{
	FindIndegree(G,indegree); 
	for(i=0;i<G.vexnum;i++)
		if(!indegree[i]) 
			DFS1(G,i); //第一次深度优先遍历:建立 ve 

	for(i=0;i<G.vexnum;i++)
		if(!indegree[i]) 
			DFS2(G,i); //第二次深度优先遍历:建立 vl 

	for(i=0;i<=G.vexnum;i++)
		if(vl[i]==ve[i]) 
			printf("%d",i); //打印输出关键路径 
}//Critical_Path


void DFS1(ALGraph G,int i) 
{
	if(!indegree[i]) 
		ve[i]=0; 
	for(p=G.vertices[i].firstarc;p;p=p->nextarc) 
	{
		dut=*p->info;
  		if(ve[i]+dut>ve[p->adjvex]) 
  			ve[p->adjvex]=ve[i]+dut;
				DFS1(G,p->adjvex); 
	}
}//DFS1


void DFS2(ALGraph G,int i) 
{
	if(!G.vertices[i].firstarc) 
		vl[i]=ve[i]; 
	else
	{
		for(p=G.vertices[i].firstarc;p;p=p->nextarc)
		 {
			DFS2(G,p->adjvex); 
			dut = *p->info; 
			if(vl[p->adjvex]-dut<vl[i])
				vl[i]=vl[p->adjvex]-dut; 
		}
	}//else 
}//DFS2