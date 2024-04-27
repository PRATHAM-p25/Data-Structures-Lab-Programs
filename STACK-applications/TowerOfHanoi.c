#include <stdio.h> 

void toH(int n, char pegA, char pegC, char pegB) { 
    if (n == 1) { 
        printf("\n Move disk 1 from peg %c to peg %c",pegA ,pegC ); 
        return; 
    } 
    toH(n-1, pegA, pegB, pegC); 
    printf("\n Move disk %d from peg %c to peg %c", n, pegA, pegC); 
    toH(n-1, pegB, pegC,pegA); 
} 

int main() { 
    int no_of_disks ; 
    printf("Enter number of disks: "); 
    scanf("%d", &no_of_disks); 
    
    toH(no_of_disks, 'A','C','B');  
    
    return 0; 
}