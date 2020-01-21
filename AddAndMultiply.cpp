#include <iostream>

using namespace std;
typedef struct LNode* List;
struct LNode{
    int coef;
    int expon;
    List next;
};
List Read(){
    List L=new LNode();
    L->next=NULL;
    List p=L,s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        s=new LNode();
        cin>>s->coef;
        cin>>s->expon;
        s->next=p->next;
        p->next=s;
        p=s;
    }
    return L;
}
void Print(List L){
    if(L->next==NULL){
        cout<<"0 0"<<endl;
    }else{
        List p=L->next;
        while(p){
            if(p->next){
                cout<<p->coef<<" "<<p->expon<<" ";
            }
            else
                cout<<p->coef<<" "<<p->expon<<endl;
            p=p->next;
        }
    }
}
List Multiply(List L1,List L2){
    List L=new LNode();
    L->next=NULL;
    if(!(L1->next)||!(L1->next)){
        return L;
    }
    List p=L,k=L->next,s,v1=L1->next,v2=L2->next;
    while(v1){
        while(v2){
            s=new LNode();
            s->coef=(v1->coef)*(v2->coef);
            s->expon=(v1->expon)+(v2->expon);
            while(p){
                if(!k){
                    s->next=p->next;
                    p->next=s;
                    p=L;
                    k=L->next;
                    break;
                }
                 if((k->expon)<(s->expon)){
                    s->next=p->next;
                    p->next=s;
                    p=L;
                    k=L->next;
                    break;
                }
                else if((k->expon)>(s->expon)){
                    p=p->next;
                    k=k->next;
                }else{
                    k->coef+=s->coef;
                    if(k->coef==0){
                        p->next=k->next;
                    }
                    p=L;
                    k=L->next;
                    break;

                }
            }
            v2=v2->next;
        }
        v1=v1->next;
        v2=L2->next;
    }
    return L;
}
List Add(List L1,List L2){
    List L=new LNode();
    L->next=NULL;
    if(!(L1->next)&&!(L2->next)){
        return NULL;
    }
    List p=L,s;
    List v1=L1->next,v2=L2->next;
   while(v1&&v2){
        if((v1->expon)>(v2->expon)){
            s=v1;
            L1->next=v1->next;
            v1=L1->next;
            s->next=p->next;
            p->next=s;
            p=s;
        }
        else if((v1->expon)<(v2->expon)){
            s=v2;
            L2->next=v2->next;
            v2=L2->next;
            s->next=p->next;
            p->next=s;
            p=s;
        }else{
            v1->coef+=v2->coef;
             if(v1->coef!=0){
            s=v1;
            L1->next=v1->next;
            L2->next=v2->next;
            v1=L1->next;
            v2=L2->next;
            s->next=p->next;
            p->next=s;
            p=s;
            }else{


            v1=v1->next;
            v2=v2->next;
            }
            }
        }
    if(v1){
        p->next=v1;
    }
    else
        p->next=v2;

    return L;
}
int main()
{
    List L1=Read();
     List L2=Read();
     List L=Multiply(L1,L2);
     List L3=Add(L1,L2);
    Print(L);
    Print(L3);
    return 0;
}
