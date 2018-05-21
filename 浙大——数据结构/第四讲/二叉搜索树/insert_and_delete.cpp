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

//Ҷ�ڵ�ֱ��ɾ����NULL
//ֻ��һ�����ӣ������ָ������
//���������ӣ�1.��������СԪ�����2.���������Ԫ������������������һ�����ӣ�
BinTree Delete(ElementType x,BinTree BST)
{
    Position Tmp;
    if(!BST)printf("Ҫɾ����Ԫ��û�ҵ�");
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
