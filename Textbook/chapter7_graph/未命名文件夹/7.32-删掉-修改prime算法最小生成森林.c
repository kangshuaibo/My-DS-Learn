/*
7.32②试修改普里姆算法,使之能在邻接表存储结构上实现求图的最小生成森林,
并分析其时间复杂度(森林的存储结构为孩子兄弟链表)
*/
void Forest_Prim(ALGraph G,int k,CSTree &T)//从顶点 k 出发,构造邻接表结构的有向图 G 的最小生成 森林 T,用孩子兄弟链表存储
{
	for(j=0;j<G.vexnum;j++) //以下在 Prim 算法基础上稍作改动 
		if(j!=k)
		{
		closedge[j]={k,Max_int}; 
		for(p=G.vertices[j].firstarc;p;p=p->nextarc)
		if(p->adjvex==k) 
			closedge[j].lowcost=p->cost; 
		}//if

	closedge[k].lowcost=0; 
	for(i=1;i<G.vexnum;i++) 
	{
		k=minimum(closedge); 
		if(closedge[k].lowcost<Max_int) 
		{
			Addto_Forest(T,closedge[k].adjvex,k); //把这条边加入生成森林中
			 	closedge[k].lowcost=0;
			for(p=G.vertices[k].firstarc;p;p=p->nextarc)
			if(p->cost<closedge[p->adjvex].lowcost)
				 closedge[p->adjvex]={k,p->cost};
		}//if
		else Forest_Prim(G,k); //对另外一个连通分量执行算法

 
  	}//for
}//Forest_Prim


void Addto_Forest(CSTree &T,int i,int j)//把边(i,j)添加到孩子兄弟链表表示的树 T 中
 {
	p=Locate(T,i); //找到结点 i 对应的指针 p,过程略 
	q=(CSTNode*)malloc(sizeof(CSTNode));
	 q->data=j;
	if(!p) //起始顶点不属于森林中已有的任何一棵树
	{
		p=(CSTNode*)malloc(sizeof(CSTNode)); 
		p->data=i; 
		for(r=T;r->nextsib;r=r->nextsib); 
			r->nextsib=p;
		p->firstchild=q;
	} 	//作为新树插入到最右侧

	else if(!p->firstchild) 	//双亲还没有孩子
		p->firstchild=q; 	//作为双亲的第一个孩子 

	else //双亲已经有了孩子
	{	
		for(r=p->firstchild;r->nextsib;r=r->nextsib);
		r->nextsib=q; //作为双亲最后一个孩子的兄弟 
	}
}//Addto_Forest 


main()
{
...
T=(CSTNode*)malloc(sizeof(CSTNode)); //建立树根 T->data=1;
Forest_Prim(G,1,T);
...
}//main
分析:这个算法是在 Prim 算法的基础上添加了非连通图支持和孩子兄弟链表构建模块而得到的,其时 间复杂度为 O(n^2).