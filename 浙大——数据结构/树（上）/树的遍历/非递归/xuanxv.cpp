void InorderTraversal(BinTree BT)
{
    BinTree T=BT;
    Stack s=CreateStack(maxsize);
    while(T||!IsEmpty(s))
    {
        while(T)
        {
            push(S,T);
            printf("%d",T->Date);
            T=T->left;
        }
        if(!IsEmpty(s))
        {
            T=pop(s);
            T=T->right;
        }
    }
