void leno(btnode &p,int key)
{
    if(p)
    {
        if(p->data==key)
            printf("leno=%d\n",L);
        ++L;
        leno(p->lchild,key);
        leno(p->rchild,key);
        --L;
    }
}
