 #include<stdio.h>
 #include<stdlib.h>
 #include<math.h>
 
 struct pnode {
    float coef;
    int xexpon;
    int yexpon;
    int zexpon;
    struct pnode* link;
 };
 struct pnode* head1=NULL, *head2=NULL, *head3=NULL,*head4=NULL;
 struct pnode* last1=NULL, *last2=NULL, *last3=NULL,*last4=NULL;
 struct pnode* temp=NULL;
 
 void create_node() {
    temp=(struct pnode*)malloc(sizeof(struct pnode));
    printf("enter term");
    scanf("%f %d %d %d",&temp->coef,&temp->xexpon,&temp->yexpon,&temp->zexpon);
    temp->link=NULL;
 }
 
 void attach(float coef, int xexpon, int yexpon, int zexpon) {
    temp=(struct pnode*)malloc(sizeof(struct pnode));
    temp->coef=coef;
    temp->xexpon=xexpon;
    temp->yexpon=yexpon;
    temp->zexpon=zexpon;
    temp->link=NULL;
    
    last4->link=temp;
    last4=temp;
    last4->link=head4;
 }

 int compare(int a, int b) {
    if(a>b)
        return 1;
    else if(a<b)
        return-1;
    else
        return 0;
 }
 
 void eval_polynomial() {
    int n;
    int x,y,z;
    int sum=0;
    printf("Enter number of terms in a polynomial\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        create_node();
        last1->link=temp;
        last1=temp;
        last1->link=head1;
    }
    printf("Enter x y and z values\n");
    scanf("%d %d %d",&x,&y,&z);
    last1=head1->link;
    printf("%f",last1->coef);
    while(last1!=head1) {
        sum=sum+((last1->coef)*pow(x,last1->xexpon)*pow(y,last1->yexpon)*pow(z,last1->zexpon));
        last1=last1->link;
    }
    printf("Result=%d",sum);
 }
 
 void add_polynomial() {
    int n1,n2;
    int sum;
    printf("Enter number of terms in polynomial 1\n");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++) {
        create_node();
        last2->link=temp;
        last2=temp;
        last2->link=head2;
    }
    
    printf("Enter number of terms in polynomial 2\n");
    scanf("%d",&n2);
    for(int j=0;j<n2;j++) {
        create_node();
        last3->link=temp;
        last3=temp;
        last3->link=head3;
    }
    last2=head2->link;
    last3=head3->link;
    while(last2!=head2&&last3!=head3) {
        switch(compare(last2->xexpon,last3->xexpon)) {
            case-1: attach(last3->coef, last3->xexpon,last3->yexpon, last3->zexpon);
                    last3=last3->link;
                    break;
            case 0: switch(compare(last2->yexpon,last3->yexpon))
            {
                case-1: attach(last3->coef, last3->xexpon, last3->yexpon, last3->zexpon);
                        last3=last3->link;
                        break;
                case 0: switch(compare(last2->zexpon, last3->zexpon)) {
                    case-1: attach(last3->coef, last3->xexpon, last3->yexpon,
                            last3->zexpon);
                            last3=last3->link;
                            break;
                    case 0: sum=last2->coef+last3->coef;
                    if(sum) {
                        attach(sum, last2->xexpon, last2->yexpon, last2->zexpon);
                        last2=last2->link;
                        last3=last3->link;
                    }
                    break;
                    case 1: attach(last2->coef, last2->xexpon, last2->yexpon, last2->zexpon);
                            last2=last2->link;
                }
                break;
                case 1: attach(last2->coef, last2->xexpon, last2->yexpon, last2->zexpon);
                        last3=last3->link;
                        break;
            }
            break;
            case 1: attach(last2->coef, last2->xexpon, last2->yexpon, last2->zexpon);
                    last2=last2->link;
        }
    }
    for(;last2!=head2;last2->link)
        attach(last2->coef, last2->xexpon,last2->yexpon,last2->zexpon);
    for(;last3!=head3;last3->link)
        attach(last3->coef, last3->xexpon, last3->yexpon, last3->zexpon);
    
    last4=head4->link;
    printf("Resultant polynomial:\n");
    while(last4!=head4) {
        printf("%f %d %d %d\t", last4->coef, last4->xexpon, last4->yexpon, last4->zexpon);
        last4=last4->link;
    }
 }

void main() {
    head1=(struct pnode*)malloc(sizeof(struct pnode));
    head2=(struct pnode*)malloc(sizeof(struct pnode));
    head3=(struct pnode*)malloc(sizeof(struct pnode));
    head4=(struct pnode*)malloc(sizeof(struct pnode));
    
    last1=head1;
    last1->link=head1;
    last2=head2;
    last2->link=head2;
    last3=head3;
    last3->link=head3;
    last4=head4;
    last4->link=head4;
    
    eval_polynomial();
    add_polynomial();
 } 