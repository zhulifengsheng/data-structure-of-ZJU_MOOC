typedef stuct GNode *GList;
struct GNode
{
    int tag; //��־λ
    union
    {
        int Data;
        GList subList;
    }URegion;
    GList next;
};
