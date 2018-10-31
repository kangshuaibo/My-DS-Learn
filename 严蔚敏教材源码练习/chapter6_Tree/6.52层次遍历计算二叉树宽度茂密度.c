//采用层次遍历方法
// 求出所有节点所在的层次，并将所有节点 和 对应的层次放在一个队列中
//然后通过 扫描队列求出 各层的节点总数
//最大的层节点总数 即为二叉树的宽度
typedef struct 
{BiTree data[Maxsize];
	int level[Maxsize];
	int front,rear;
	
}Qu;

int BTWidth(BiTree b)
{
	BiTree p;
	int k,max,i,n;
	Qu.front=Qu.rear=-1;//队列置为空

	Qu.rear++;
	Qu.data[Qu.rear]=b;	//根节点指针入队

	Qu.level[Qu.rear]=1; //根节点层次为1
	while(Qu.front<Qu.rear)
	{
		Qu.front++;	//出队
		p=Qu.data[Qu.front];//记录出队节点
		k=Qu.level[Qu.front];//记录出队节点的层次

		if(p->lchild!=NULL)
		{
			Qu.rear++;
			Qu.data[Qu.rear]=p->lchild;
			Qu.level[Qu.rear]=k+1;
		}
		if(p->rchild!=NULL)
		{
			Qu.rear++;
			Qu.data[rear]=p->rchild;
			Qu.level[Qu.rear]=k+1;
		}
	}

	max=0;i=1;
	k=1;	//从第一层开始扫描
	while(i<=Qu.rear)
	{
		n=0;
		while(i<Qu.rear && Qu.level[i]==k)
		{
			n++;	//统计k层节点数
			i++;
		}
		k=Qu.level[i];
		if(n>max) max=n;
	}
	return max；
}






































//-------高分笔记-----------------------------------------------
#define Maxsize 100
typedef struct BiTNode
{
 int data;
 struct BiTree *lchild,*rchild;
}BiTNode,BiTree *;

BTNode *p;
int rear,front,temp,last,maxw;
	

int width(BiTree bt)
{   
	if(bt==NULL)
		return 0;
	else
	{
		BiTree Q[Maxsize];//定义一个二叉链表节点的队列 元素为二叉树节点的指针
		front=1;rear=1;last=1;//last为同层最右边节点在队列中的位置
		temp=0;maxw=0;

		Q[rear]=bt;//根节点入队列
		while(front<=last)
		{
			p=Q[front++];temp++;//根节点出队 p保存 这一层的节点数加一

			if(p->rchild) Q[++rear]=p->lchild; //出队的这个节点左孩子入队
			if(p->lchild) Q[++rear]=p->rchild; //右孩子入队

		    if(front>last) //这一层结束
		    {
		    	last=rear;//last指向下一层最后
		    	if(temp>maxw) 
		    		maxw=temp;
		    	temp=0;   //重置下一层的计数
		    }
		}
	}
	return maxw;
}