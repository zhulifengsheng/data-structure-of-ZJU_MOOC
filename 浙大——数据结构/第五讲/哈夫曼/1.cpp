typedef struct TreeNode *HuffmanTree
struct TreeNode
{
    int Weught;
    HuffmanTree Left,Right;
};

HuffmanTree Huffman(MinHear H)
{
    int i;
    HuffmanTree T;
    BuildMinHeap(H);
    for(i=1;i<H->Size;i++)
    {
        T=malloc(sizeof(struct TreeNode));
        T->Left=DeleteMin(H);
        T->Right=DeleteMin(H);
        T->Weight=T->Left->Weight+T->Right->Weight;
        Insert(H,T);
    }
    T=DeleteMin(H);
    return T;
}
