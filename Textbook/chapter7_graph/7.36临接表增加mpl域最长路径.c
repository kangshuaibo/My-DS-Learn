/*
◆7.36④在图的邻接表存储结构中,为每个顶点增加一个MPL域。
试写一算法,求有向无环图G的每个顶点出发的最长路径的长度,并存入其MPL域。
请给出算法的时间复杂度。
*/

void Fill_MPL(ALGraph &G)//为有向无环图 G 添加 MPL 域 
{
	FindIndegree(G,indegree); 
	for(i=0;i<G.vexnum;i++)
		if(!indegree[i]) 
			Get_MPL(G,i);//从每一个零入度顶点出发构建 MPL 域 
}//Fill_MPL


int Get_MPL(ALGraph &G,int i)//从一个顶点出发构建 MPL 域并返回其 MPL 值
{
	if(!G.vertices[i].firstarc) 
	{
		G.vertices[i].MPL=0;
			return 0; //零出度顶点
	}
	else 
	{
		max=0; 
		for(p=G.vertices[i].firstarc;p;p=p->nextarc) 
		{
			j=p->adjvex;
			if(G.vertices[j].MPL==0)
			 	k=Get_MPL(G,j);
  			if(k>max) 
  				max=k; //求其直接后继顶点 MPL 的最大者
  		}
		G.vertices[i]=max+1;//再加一,就是当前顶点的 MPL
		return max+1; 

	}//else

}//Get_MPL