#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int check(int first1,int end1,int first2,int end2);
int n;
string s1,s2;

int main()
{
    cin>>n;
    cin>>s1;
    cin>>s2;
    cout<<check(0,n-1,0,n-1)<<endl;

    return 0;
}

int check(int first1,int end1,int first2,int end2)
{
    if(end2-first2==0)
        return 1;
    if(end2-first2==1)
        return 2;

    int leftdepth=0,rightdepth=0;
    int i=0;
    for(i=first2;i<end2+1;i++)
    {
        if(s1[first1]==s2[i])
        {
            leftdepth=check(first1+1,end1-(end2-i),first2,i-1);
            rightdepth=check(end1-(end2-i)+1,end1,i+1,end2);
        }
    }

    return max(leftdepth,rightdepth)+1;
}
