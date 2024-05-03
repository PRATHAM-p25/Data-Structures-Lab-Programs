 #include <stdio.h>
 #include <stdlib.h>
 
 struct dnode {
    struct dnode* llink;
    struct dnode* rlink;
    long long int phno;
    int ssn;
    float sal;
    char name[20], dept[20];
 };
 struct dnode *first=NULL, *last=NULL, *temp=NULL, *p=NULL;
 
 void create() {
    temp=(struct dnode*)malloc(sizeof(struct dnode));
    printf("Enter employee details\n");
    scanf("%s %d %s %f %llu", temp->name, &temp->ssn, temp->dept, &temp->sal, &temp->phno);
    temp->rlink=NULL;
    temp->llink=NULL;
 }
 
 void insert_front() {
    create();
    if(first==NULL)
        first=last=temp;
    else {
        temp->rlink=first;
        first->llink=temp;
        first=temp;
    }
 }
 
 void insert_rear() {
    create();
    if(first==NULL)
        first=last=temp;
    else {
        last->rlink=temp;
        temp->llink=last;
        last=temp;
    }
 }
 
 void delete_front() {
    p=first;
    if(p==NULL)
        printf("List is empty");
    else if(p->rlink==NULL) {
        printf(" %s\n %d\n %s\n %f\n %llu\n", p->name,p->ssn, p->dept, p->sal, p->phno);
        free(p);
        first=last=NULL;
    }
    else {
        first=first->rlink;
        printf(" %s\n %d\n %s\n %f\n %llu\n", p->name,p->ssn, p->dept, p->sal, p->phno);
        free(p);
    }
 }
 
 void delete_rear() {
    p=last;
    if(p==NULL)
        printf("List is empty\n");
    else if(first->rlink==NULL) {
        printf(" %s\n %d\n %s\n %f\n %llu\n", p->name,p->ssn, p->dept, p->sal, p->phno);
        free(p);
        first=last=NULL;
    }
    else {
        last=last->llink;
        printf(" %s\n %d\n %s\n %f\n %llu\n", p->name,p->ssn, p->dept, p->sal, p->phno);
        free(p);
        last->rlink=NULL;
    }
 }
 
 void display() {
    p=first;
    if(p==NULL)
        printf("List is empty\n");
    else {
        while(p!=NULL) {
            printf(" %s\n %d\n %s\n %f\n %llu\n", p->name,p->ssn, p->dept, p->sal, p->phno);
            p=p->rlink;
        }
    }
 }
 
 int main() {
    int ch, i,n;
    while(1) {
        printf(" 1: Creat list\n 2: insert front\n 3: Insert rear\n 4: Delete front\n 5: Delete rear\n 6: Display\n 7: Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch) {
            case 1: printf("Enter number of students\n");
                    scanf("%d",&n);
                    for(i=0;i<n;i++)
                        insert_front();
                    break;
            case 2: insert_front();
                    break;
            case 3: insert_rear();
                    break;
            case 4:delete_front();
                    break;
            case 5: delete_rear();
                    break;
            case 6: display();
                    break;
            case 7: exit(0);
        }
    }
 }