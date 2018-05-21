typedef stuct GNode *GList;
struct GNode
{
    int tag; //±êÖ¾Î»
    union
    {
        int Data;
        GList subList;
    }URegion;
    GList next;
};
