BinTree Insert(ElementType x,BinTree BST)
{
    if(!BST)
    {
        BST=malloc(sizeof(struct TreeNode));
        BST->Data=x;
        BST->Left=BST->Right=NULL;
    }
    else
    {
        if(x<BST->Data)
            BST->Left=Insert(x,BST->Left);
        else if(x>BST->Data)
            BST->Right=Insert(x,BST->Right);
    }
    return BST;
}

//叶节点直接删除变NULL
//只有一个儿子，父结点指向孙子
//有两个孩子，1.右子树最小元素替代2.左子树最大元素替代（且他们最多有一个孩子）
BinTree Delete(ElementType x,BinTree BST)
{
    Position Tmp;
    if(!BST)printf("要删除的元素没找到");
    else if(x<BST->Data)
        BST->Left=Delete(x,BST->Left);
    else if(x>BST->Data)
        BST->Right=Delete(x,BST->Right);
    else if(BST->Left&&BST->Right)
    {
        Tmp=FindMin(BST->Right);
        BST->Data=Tmp->Data;
        BST->Right=Delete(BST->Data,BST->Right);
    }
    else
    {
        Tmp=BST;
        if(!BST->Left)
            BST=BST->Right;
        else if(!BST->Right)
            BST=BST->Left;
        free(Tmp);
    }

    return BST
}
