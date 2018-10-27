//非递归后序遍历最后访问根节点 当访问x时 栈中所有元素为该节点的祖先节点
typedef struct{
	BiTree t;
	int tag;
}stack;   //tag=0表示左子女被访问过 tag=1表示右子女被访问过

void Search(BiTree bt,ElemType x)
{
	stack s[];
	top=0;
	while(bt!=NULL||top>0)
	{
		while(bt!=NULL &&bt->data!=x)//节点入栈
		{
			s[++top].t=bt;
			stop.tag=0;
			bt=bt->lchild;
		}
		if(bt->data==x)	//找到x输出
		{
			printf("节点则祖先为：\n");
			for(i=1;i<top;i++)
				printf("%d",s[i].t->data );
			exit 1;
		}
		while(top!=0 && s[top].tag==1)
			top--;	//退栈空遍历
		if(top!=0)
		{
			s[top].tag=1;	
			bt=s[top].t->rchild;	//沿右分支向下遍历	
		}
	}
}