int PostOrderGetHeight(BinTree BT)
{
    int HL,HR,MAXH;
    if(BT)
    {
        HL=PostOrderGetHeight(BinTree BT->left);
        HR=PostOrderGetHeight(BinTree BT->right);
        MAXH=(HL>HR)?HL:HR;
        return(MAXH+1);
    }
    else return 0;
}
