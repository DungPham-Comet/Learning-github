#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    char data;
    struct node* next;
} node;
typedef struct stack{
    node * headst;
} stack;
void makest(stack *l){
    l->headst = NULL;
}
node * Cnode(char c){
    node *p = (node*)malloc(sizeof(node));
    p->data = c;
    p->next = NULL;
    return p;
}
void pushst(node *p, stack *l){
    if (l->headst == NULL)
        l->headst = p;
        else {
            p->next = l->headst;
            l->headst = p;
        }
}
void popst(stack *l){
    l->headst = l->headst->next;
}
char topst(stack *l){
    return l->headst->data;
}
int emptyst(stack *l){
    if (l->headst == NULL) 
        return 1;
        else return 0;
}
int main(){
    stack st;
    makest(&st);
    char s[100];
    printf("Nhap s:");
    fflush(stdin);
    gets(s); 
    int i;
    for (i=0;i<strlen(s);i++){
        node *p =Cnode(s[i]);
        pushst(p,&st);
    }
    while(emptyst(&st) != 1){
        popst(&st);
    }
    printf("mang co rong hay ko: %d",emptyst(&st));
    return 0;
}