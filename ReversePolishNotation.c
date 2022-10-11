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
    if (l->headst->next == NULL)
        l->headst = NULL;
        else
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
int sizest(stack *l){
    node *k;
    int dem = 0;
    for (k=l->headst;k!=NULL;k=k->next){
        dem++; 
    }
    return dem;
}
// tu phan nay tro xuong la tao queue
typedef struct queue{
    node *headq;
} queue;
void makeq(queue *q){
    q->headq = NULL;
}
int sizeq(queue *q){
    node *k;
    int dem = 0;
    for (k=q->headq;k!=NULL;k=k->next)
        dem++;
    return dem;
}
int emptyq(queue *q){
    if (q->headq == NULL)
        return 1;
        else return 0;
}
void pushq(node *p,queue*q){
    if (q->headq == NULL)
        q->headq = p;
        else{
            p->next = q->headq;
            q->headq = p;
        }
}
void popq(queue *q){
    node *k;
    if (q->headq->next == NULL)
        q->headq = NULL;
        else{
            for (k=q->headq;k->next->next != NULL; k=k->next)
                ;;
            k->next = NULL;
        }
}
char frontq(queue *q){
    node *k;
    for (k=q->headq;k->next != NULL; k=k->next)
        ;;
    return k->data;
}
int main(){
    stack st;
    queue q;
    makest(&st);
    makeq(&q);
    char s[100];
    printf("Nhap bieu thuc hau to: ");
    fflush(stdin);
    gets(s);
    int i;
    for (i=0;i<strlen(s);i++){
        if (s[i] >= '0' && s[i] <= '9'){
            node *p = Cnode(s[i]);
            pushq(p,&q);
        }
        else if (s[i] == '('){ 
            node *p1 = Cnode(s[i]);
            pushst(p1,&st);
        }
        else if (s[i] == '+' || s[i] == '-'|| s[i] == '*'|| s[i] == '/'){
            if (emptyst(&st) == 1){
                node *p = Cnode(s[i]);
                pushst(p,&st);
            }
            else{
                if (topst(&st) == '('){ 
                    node *p = Cnode(s[i]);
                    pushst(p,&st);
                }
                else if(topst(&st) == '+'|| topst(&st) == '-'|| topst(&st) == '*'|| topst(&st) =='/'){
                    if (s[i] == '+' || s[i] == '-'){
                        while(emptyst(&st)  != 1 ){
                            node *p = Cnode(topst(&st));
                            pushq(p,&q);
                            popst(&st);
                        }
                        node *p = Cnode(s[i]);
                        pushst(p,&st);
                    }
                    else if (s[i] == '*'|| s[i] == '/'){
                        if (topst(&st) == '+'|| topst(&st) =='-'){
                            node *p = Cnode(s[i]);
                            pushst(p,&st);
                        }
                        else if (topst(&st) == '*' || topst(&st)=='/'){
                            if (sizest(&st) != 1){
                                while(sizest(&st) != 1){
                                    if(topst(&st) == '*' || topst(&st) =='/'){
                                        node *p = Cnode(topst(&st));
                                        pushq(p,&q);
                                        popst(&st);
                                    }
                                    else if (topst(&st) =='+'|| topst(&st) == '-'|| topst(&st)=='('){
                                        node *p =Cnode(s[i]);
                                        pushst(p,&st);
                                    }
                                }
                            }
                            else if (sizest(&st) == 1){
                                if(topst(&st) == '*' || topst(&st) == '/'){
                                    node *p = Cnode(topst(&st));
                                    pushq(p,&q);
                                    popst(&st);
                                    node *p3 = Cnode(s[i]);
                                    pushst(p3,&st);
                                }
                                else if (topst(&st) == '+'|| topst(&st) == '-'|| topst(&st) =='('){
                                    node *p = Cnode(s[i]);
                                    pushst(p,&st);
                                }
                            }
                        }
                    }
                }
            }
        }
        else if (s[i] == ')'){
            while(topst(&st) != '('){
                node *p8 =Cnode(topst(&st));
                pushq(p8,&q);
                popst(&st);
            }
            popst(&st);
        }
        if (i == strlen(s)-1){
            while(emptyst(&st) != 1){
                node *p9= Cnode(topst(&st));
                pushq(p9,&q);
                popst(&st);
            }
        }
    }
    /*printf("Post fix: ");
    while(emptyq(&q) != 1){
        printf("%c ",frontq(&q));
        popq(&q);
    }*/
    int kq[50];
    int l;
    for (l=0;l<50;l++){
        kq[l] = 100;
    }
    l=0;
    while(emptyq(&q) != 1){
        if(frontq(&q) >= '0' && frontq(&q) <= '9'){
            kq[l] = (int)(frontq(&q)) - 48;
            l++;
            popq(&q);
        }
        else if (frontq(&q) == '+' || frontq(&q) == '-' || frontq(&q) =='*'|| frontq(&q) == '/'){
            if (frontq(&q) == '+'){
                kq[l-2] = kq[l-1] + kq[l-2];
                l=l-1;
                popq(&q);
            }
            else if (frontq(&q) == '-'){
                kq[l-2] = kq[l-1] - kq[l-2];
                l=l-1;
                popq(&q);
            }
            else if (frontq(&q) =='*'){
                kq[l-2] = kq[l-1] * kq[l-2];
                l=l-1;
                popq(&q);
            }
            else if (frontq(&q) == '/'){
                kq[l-2] = kq[l-1]/kq[l-2];
                l=l-1;
                popq(&q);
            }
        }
    }
    printf("kq: %d",kq[0]);
    return 0;
}
 