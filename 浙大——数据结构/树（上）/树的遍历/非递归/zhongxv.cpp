void InorderTraversal(BinTree BT)
{
    BinTree T=BT;
    Stack s=CreateStack(maxsize);
    while(T||!IsEmpty(s))
    {
        while(T)
        {
            push(S,T);
            T=T->left;
        }
        if(!IsEmpty(s))
        {
            T=pop(s);
            printf("%d",T->Date);
            T=T->right;
        }
    }
}
