/*
设置一个全局变量i记录已访问过的节点的序号 其初值是根节点先序序列中的序号=1 
当树空返回‘#’，
i=k找到了满足条件的节点返回b->data 
i不等于k，递归找左子树，找到返回。找不到，递归右子树
*/
int i;
ElemType PreNode(BiTree b,int k)
{
	if(b==NULL)
		return '#';

	if(i=k)
		return b->data;

	i++;		//下一个节点

	ch=PreNode(b->lchild,k);  //左子树递归找
	if(ch！="#")
		return ch
	ch=PreNode(b->rchile,k);  //右子树递归找
		return ch;
}
//本质为遍历 只不过加了个记录序号的i