#include <stdio.h>
#include <stdlib.h>

struct cLL {
    int val;
    struct cLL *nxt;
};

void atend(struct cLL** l, int d) {
    struct cLL* new = (struct cLL*)malloc(sizeof(struct cLL));
    if (new == NULL) return;
    new->val = d;
    new->nxt = *l;
    if (*l == NULL) {
        *l = new;
        new->nxt = new;
    } else {
        struct cLL* temp = *l;
        while (temp->nxt != *l) {
            temp = temp->nxt;
        }
        temp->nxt = new;
    }
}

struct cLL* New_node(int d){
    struct cLL* new=(struct cLL*)malloc(sizeof(struct cLL));
    if(new==NULL){
        printf("Memmory allocation Failed!");
        return new;
    }
    new->val=d;
    new->nxt=NULL;
    return new;
} 

int main(){
    struct cLL* fi=New_node(1);
    struct cLL* se=New_node(2);
    struct cLL* th=New_node(3);
    struct cLL* fo=New_node(4);
    struct cLL* fi1=New_node(5);

    struct cLL* temp = fi;
    do {
        printf("%d ", temp->val);
        temp = temp->nxt;
    } while (temp != fi);
    printf("\n");

    return 0;



}