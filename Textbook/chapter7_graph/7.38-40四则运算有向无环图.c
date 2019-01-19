/*
◆7.38一个四则运算算术表达式以有向无环图的邹接表方式存储,
每个操作数原子都由单个序母表示。
写一个算法输出其逆波兰表达式
*/

void NiBoLan_DAG(ALGraph G)//输出有向无环图形式表示的表达式的逆波兰式 
{
	FindIndegree(G,indegree); 
	for(i=0;i<G.vexnum;i++)
		if(!indegree[i]) 
			r=i; //找到有向无环图的根 
	PrintNiBoLan_DAG(G,i);
}//NiBoLan_DAG


void PrintNiBoLan_DAG(ALGraph G,int i)//打印输出以顶点 i 为根的表达式的逆波兰式
 {
	c=G.vertices[i].data; 
	if(!G.vertices[i].firstarc) //c 是原子
		printf("%c",c); 
	else //子表达式
	{
		p=G.vertices[i].firstarc; 
		PrintNiBoLan_DAG(G,p->adjvex); 
		PrintNiBoLan_DAG(G,p->nexarc->adjvex); 
		printf("%c",c);
	}
}//PrintNiBoLan_DAG









/*
7.39把存储结构改为二又链表,重做7.38题。
*/

void PrintNiBoLan_Bitree(Bitree T)//在二叉链表存储结构上重做上一题 
{
	if(T->lchild) 
		PrintNiBoLan_Bitree(T->lchild); 
	if(T->rchild) 
		PrintNiBoLan_Bitree(T->rchild); 

	printf("%c",T->data);
}//PrintNiBoLan_Bitree


/*
7.40③ 若7.38题的运算符和操作数原子分别由字符和整数表示,请设计邻接表的
结点类型,并且写一个表达式求值的算法。
*/

int Evaluate_DAG(ALGraph G)//给有向无环图表示的表达式求值 
{
	FindIndegree(G,indegree); 
	for(i=0;i<G.vexnum;i++)
		if(!indegree[i]) 
			r=i; //找到有向无环图的根 
	return Evaluate_imp(G,i);

}//NiBoLan_DAG


int Evaluate_imp(ALGraph G,int i)//求子表达式的值 
{
	if(G.vertices[i].tag=NUM) 
		return G.vertices[i].value; 
	else
	{
		p=G.vertices[i].firstarc; 
		v1=Evaluate_imp(G,p->adjvex); 
		v2=Evaluate_imp(G,p->nextarc->adjvex); 
		return calculate(v1,G.vertices[i].optr,v2);
	}
}//Evaluate_imp

//分析:本题中,邻接表的 vertices 向量的元素类型修改如下: 
/*
struct {

	enum tag{NUM,OPTR}; union
	{
		int value;
		char optr; 
    };

    ArcNode * firstarc; 
} Elemtype;
*/
















