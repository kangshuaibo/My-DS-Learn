/*
已知在二叉树中 *root为根节点，*p和*q为二叉树中两个结点，试编写求距离他们最近的共同祖先的算法
*/

//后序遍历 最后访问根节点 即在递归算法中 根是压在栈低的，设p在q的左边

//采用后序非递归算法，栈中存放二叉树节点的指针，当访问到某节点时，栈中所有元素均为该节点的祖先。
//后序遍历必然先遍历到节点p，栈中元素均为p的祖先。
//先将栈复制到另一个辅栈中。
//继续遍历到q时，将栈中元素从栈顶开始逐个到辅栈中去匹配，第一个匹配到的就是p和q的最近公共祖先
typedef struct 
{
	BiTree t;
	int tag;     //tag为0表示左子女已经被访问 tag为1表示右子女已经被访问
}stack;

stack s[],s1[];  //设栈容量足够大

BiTree Ancestor(BiTree ROOT,BiTNode *p,BiTNode *q)
{
	top=0;bt=ROOT;
	while(bt!=NULL ||top>0)
	{
		while(bt!=NULL && bt!=p &&bt!=q)
			while(bt!=NULL)			//节点入栈
			{
				s[++top].t=bt;
				s[top].tag=0;
				bt=bt->lchild;
			}
		while(top!=0&&s[top].tag==1)//假定p在q左侧 遇到p时 栈中元素均为p的祖先
		{
			if(a[top].t==p)
			{
				for(i=1;i<=top;i++)
					s1[i]=s[i];
				top1=top;
			}				//将栈s的元素转入辅助栈s1保存
			if(s[top].t==q) //找到q节点
			{
				for(i=top;i>0;i--)//将栈中元素的树节点到s1中去匹配
					for(j=top1;j>0;j--)
						if(s1[j].t==s[i].t)
							return s[i].t; //p和q的最近公共祖先已经找到
			}
			top--；//退栈
		}
		
		if(top!=0)
		{
			s[top].tag=1;
			bt=s[top].t->rchild;//沿右分支向下
		}
	}
	return NULL;//p和q无公共祖先
}
