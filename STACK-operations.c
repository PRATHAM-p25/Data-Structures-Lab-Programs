#include <stdio.h> 
#include <stdlib.h> 
#define SIZE 4 

int top = -1, inp_array[SIZE]; 
void push(int); 
int pop(); 
void show(); 
void palindrome(); 

int main() { 
    int choice,x; 
    while (1) { 
        printf("\nPerform operations on the stack:"); 
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.palindrome\n5.End"); 
        printf("\n\nEnter the choice: "); 
        scanf("%d", &choice); 
        switch (choice) { 
            case 1: 
                if (top == SIZE - 1) { 
                    printf("\nOverflow!!"); 
                } 
                else { 
                    printf("\nEnter the element to be added onto the stack: "); 
                    scanf("%d", &x); 
                    push(x); 
                } 
                break; 
                        
            case 2: 
                if (top == -1) { 
                    printf("\nUnderflow!!"); 
                } 
                else { 
                    x=pop(); 
                    printf("\nPopped element: %d", x); 
                } 
                break; 
                    
            case 3: 
                show(); 
                break; 
                    
            case 4: 
                palindrome(); 
                break; 
                        
            case 5: 
                exit(0); 
            
            default: 
                printf("\nInvalid choice!!"); 
        } 
    } 
} 
 
void push(int x) { 
    top = top + 1; 
    inp_array[top] = x;      
} 
 
int pop() { 
    int x; 
    x=inp_array[top]; 
    top = top - 1; 
    return x; 
} 
 
void show() { 
    if (top == -1) { 
        printf("\nUnderflow!!"); 
    } 
    else { 
        printf("\nElements present in the stack: \n"); 
        for (int i = top; i >= 0; --i) 
            printf("%d\n", inp_array[i]); 
    } 
} 
 
void palindrome() {  
    int i=0,b; 
    char str[100]; 
    printf("Enter the String\n"); 
    scanf("%s", str); 
             
            while(str[i]!='\0') { 
                b = str[i]; 
                push(b); 
                i++; 
            } 
            i=0; 
            while(str[i]!='\0') { 
                b=pop(); 
                if(b!=str[i]) 
                    break; 
                i++;     
            } 
            if(str[i]=='\0') 
                printf("Palindrome\n"); 
            else 
                printf("Not palindrome\n"); 
             
} 