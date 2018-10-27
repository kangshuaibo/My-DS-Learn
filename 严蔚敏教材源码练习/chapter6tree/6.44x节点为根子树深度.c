/*求二叉树中以元素值为x的节点为根的子树深度*/

int Get_Sub_Depth(Bitree T,int x)//求二叉树中以值为 x 的结点为根的子树深度
{
	if(T->data==x) 
	{
	 printf("%d\n",Depth(T)); //找到了值为 x 的结点,求其深度
	 exit 1; 
	}
	else 
	{
		if(T->lchild) Get_Sub_Depth(T->lchild,x);
		if(T->rchild) Get_Sub_Depth(T->rchild,x); //在左右子树中继续寻找
	}
}//Get_Sub_Depth


int Depth(Bitree T)//求树深度的递归算法
 {
 	 if(!T) 
  		return 0; 
  	else
	{
		m=Depth(T->lchild); 
		n=Depth(T->rchild); 
		return (m>n?m:n)+1;
	}
}//Get_Depth