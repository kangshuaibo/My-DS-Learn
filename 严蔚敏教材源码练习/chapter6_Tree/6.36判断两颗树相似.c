
/*
17.试设计判断两棵二叉树是否相似的算法。所谓二叉树T1和T2相似,指的是T1和T2
都是空的二叉树或都只有一个根结点;或T1的左子树和T2的左子树是相似的且T1的右子树和
T2的右子树是相似的
*/

//思想：若T1和T2都为空树则相似；若一个空一个不空则不相似；否则递归比较左右子树是否相似
//a、f(T1,T2)=1;若T1==T2==NULL;
//b、f(T1,T2)=0;若T1和T2一个为空一个不为空
//c、f(T1,T2)=f(T1->lchild,T2->lchild)&&f(T1->rchild,T2->rchild);若T1和T2均不为空 递归
int similar(BiTree T1,BiTree T2)
{
	int leftS,rightS;
	if(T1==NULL && T2==NULL)//两树都空
		return 1;
	else if(T1==NULL || T2==NULL)//只有一树空
		return 0;
	else{
		leftS=similar(T1->lchild,T2->lchild);
		rightS=similar(T1->rchild,T2->rchild);
		return leftS&&rightS;
	}
}





/*
6.36③若已知两棵二又树B1和B2皆为空,或者皆不空且B1的左、右子树和B
的左、右子树分别相似,则称二叉树Bl和B2相似。试编写算法,判别给定两棵二叉树是
否相似。
*/
//判断两颗树是否相似
int Bitree_Sim(Bitree B1,Bitree B2)
{
	if(!B1&&!B2)return 1;//都为空树 相似
	else if( B1 && B2 && Bitree_Sim(B1->lchild,B2->lchild) && Bitree_Sim(B1->rchild,B2->rchild) )
		return 1;
	else
		return 0;
}