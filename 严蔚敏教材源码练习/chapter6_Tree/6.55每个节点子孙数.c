int DescNum(Bitree T)//求树结点 T 的子孙总数填入 DescNum 域中,并返回该数 
{
	if(!T) return -1;
	else d=(DescNum(T->lchild)+DescNum(T->rchild)+2); //计算公式 T->DescNum=d;
	return d;
}//DescNum
//分析:该算法时间复杂度为 O(n),n 为树结点总数.
//注意:为了能用一个统一的公式计算子孙数目,所以当 T 为空指针时,要返回-1 而不是 0.