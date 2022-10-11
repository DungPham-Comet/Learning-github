#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
node *phead;
node *taonode(int x){
    node *p = new node;
    p->data=x;
    p->next=NULL;
    return p;
}
void add(node *p){
    if (phead == NULL)
        phead = p;
    else{
        node *k=NULL;
        for (k=phead; k -> next != NULL; k = k->next){
            ;;
        }
        k->next=p;
    }
}
void in(){
    node *k;
    for (k=phead; k!=NULL; k=k->next)
        cout<<k->data<<" ";
}
int main(){
    phead=NULL;
    int n;
    cout<<"Nhap n:";
    cin>>n;
    int i,x;
    for (i=0;i<n;i++){
        cout<<"Nhap phan tu :";
        cin>>x;
        node *p=taonode(x);
        add(p);
    }
    in();
    return 0;
}