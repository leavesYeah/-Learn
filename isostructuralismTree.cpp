#include <iostream>

using namespace std;

struct Node{
    char data;
    int left;
    int right;
};
int createTree(struct Node tree[]){
    int n,root=-1;
    cin>>n;
    int tag[n]={0};
    char ch1,ch2;
    for(int i=0;i<n;i++){
        cin>>tree[i].data>>ch1>>ch2;
        if(ch1=='-')
            tree[i].left=-1;
        else{
            tree[i].left=ch1-'0';
            tag[tree[i].left]=1;
        }
        if(ch2=='-')
            tree[i].right=-1;
        else{
            tree[i].right=ch2-'0';
            tag[tree[i].right]=1;
        }
    }
    for(int i=0;i<n;i++){
        if(tag[i]==0){
            root=i;
            break;
        }

    }
    return root;
}
bool Compare(int r1,int r2,struct Node *t1,struct Node *t2){
    if(r1==-1&&r2==-1)
        return true;
    if((r1==-1&&r2!=-1)||(r1!=-1&&r2==-1))
        return false;
    if(t1[r1].data!=t2[r2].data)
        return false;
    if(t1[r1].left==-1&&t2[r2].left==-1)
        return Compare(t1[r1].right,t2[r2].right,t1,t2);
    if(t1[t1[r1].left].data==t2[t2[r2].left].data)
        return Compare(t1[r1].left,t2[r2].left,t1,t2)&&Compare(t1[r1].right,t2[r2].right,t1,t2);
    else
        return Compare(t1[r1].left,t2[r2].right,t1,t2)&&Compare(t1[r1].right,t2[r2].left,t1,t2);
}
int main()
{
    struct Node Tree1[11],Tree2[11];
    int r1=createTree(Tree1);
    int r2=createTree(Tree2);
    if(Compare(r1,r2,Tree1,Tree2))
        cout<<"Yes";
    else cout<<"No";
    return 0;
}
