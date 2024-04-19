#include <stdio.h> 
#include<stdlib.h> 

typedef struct { 
    char *day; 
    int dt; 
    char *desc; 
} date; 

void create(); 
date *calender; 
void read(); 
void display(); 

void main() { 
    printf("Creating\n"); 
    create(); 
    printf("Reading\n"); 
    read(); 
    printf("Displaying\n"); 
    display(); 
} 

void create() { 
    calender=(date*)malloc(sizeof(date)*7); 
} 

void read() { 
    int i; 
    for(i=0;i<7;i++) { 
        printf("\nEnter day of the week:"); 
        calender[i].day = (char*)malloc(sizeof(char)*100); 
        scanf("%s",calender[i].day); 
        printf("\nEnter the date:"); 
        scanf("%d",&calender[i].dt); 
        printf("\nEnter the description:"); 
        calender[i].desc = (char*)malloc(sizeof(char)*100); 
        scanf("%s",calender[i].desc); 
    } 
} 

void display() { 
    int i; 
    for(i=0;i<7;i++) { 
        printf("\nDay of the week:%s\n",calender[i].day ); 
        printf("\nDate:%d\n",calender[i].dt); 
        printf("\nDescription:%s\n",calender[i].desc); 
    } 
} 
