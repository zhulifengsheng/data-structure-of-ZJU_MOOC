#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int xuan[30];
int zhong[30];
int hou[30];

typedef struct StackNode
{
    int data;
    struct StackNode *next;
}*Stack;

typedef struct TreeNode
{
    int data;
    struct TreeNode *left,*right;
}*Tree;

Stack push(Stack s,int e)//不用指针，因为每次返回新的top
{
    Stack newstack=(Stack)malloc(sizeof(struct StackNode));
    newstack->data=e;
    newstack->next=(s);
    (s)=newstack;
    return (s);
}

int pop(Stack *s)
{
    if((*s)->next!=NULL)
    {
        Stack t=(*s);
        (*s)=(*s)->next;
        int a=t->data;
        free(t);
        return a;
    }
    return -1;
}

void hou1(int prel,int inl,int postl,int n)
{
	if(n==0)return;
    if(n==1){hou[postl]=xuan[prel];return;}
	int i;
    int root=xuan[prel];
    hou[n+postl-1]=root;
    for(i=0;i<n;i++)
        if(zhong[inl+i]==root)break;
    int L=i;
    int R=n-i-1;
    hou1(prel+1,inl,postl,L);
    hou1(prel+i+1,inl+1+i,postl+i,R);
}

int main()
{
    int n;

    Stack top=(Stack)malloc(sizeof(struct StackNode));
    top->next=NULL;

    Tree T=(Tree)malloc(sizeof(struct TreeNode));
    T->left=T->right=NULL;

    scanf("%d",&n);
    char s[5];

    //升级为全局变量，为后序遍历函数做准备
    //int *zhong=(int *)malloc(n*sizeof(int));
    //int *xuan=(int *)malloc(n*sizeof(int));

    int j=0;
    int q=0;

    while(j!=n)
    {
        scanf("%s",s);
        if(strcmp("Push",s)==0)
        {
            int i;
            scanf("%d",&i);
            xuan[q]=i;
            q++;
            top=push(top,i);
        }
        else
        {
            zhong[j]=pop(&top);
            j++;
        }
    }
    hou1(0,0,0,n);

    for(int a=0;a<n;a++)
    {
        if(a==n-1)
            printf("%d",hou[a]);
        else
            printf("%d ",hou[a]);
    }

    return 0;
}
