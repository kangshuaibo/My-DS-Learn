//判断两颗树是否相似
int Bitree_Sim(Bitree B1,Bitree B2)
{
	if(!B1&&!B2)return 1;//都为空树 相似
	else if( B1 && B2 && Bitree_Sim(B1->lchild,B2->lchild) && Bitree_Sim(B1->rchild,B2->rchild) )
		return 1;
	else
		return 0;
}