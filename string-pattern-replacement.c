#include <stdio.h> 
#include <string.h> 
  
// Function to replace all the occurrences 
// of the substring S1 to S2 in string S 
 
void modifyString(char* s, char* s1, char* s2) { 
    // Stores the resultant string 
    char ans[1000] = { 0 }; 
    int ans_idx = 0; 
  
    // Traverse the string s 
    for (int i = 0; i < strlen(s); i++) { 
  
        int k = 0; 
  
        // If the first character of 
        // string s1 matches with the 
        // current character in string s 
 
        if (s[i] == s1[k] && i + strlen(s1) <= strlen(s)) { 
  
            int j; 
  
            // If the complete string 
            // matches or not 
            for (j = i; j < i + strlen(s1); j++) { 
  
                if (s[j] != s1[k]) { 
                    break; 
                } 
                else { 
                    k = k + 1; 
                } 
            } 
 
  
            // If complete string matches 
            // then replace it with the 
            // string s2 
            if (j == i + strlen(s1)) { 
                for (int l = 0; l < strlen(s2); l++) { 
                    ans[ans_idx++] = s2[l]; 
                } 
                i = j - 1; 
            } 
  
            // Otherwise 
            else { 
                ans[ans_idx++] = s[i]; 
            } 
        } 
  
        // Otherwise 
        else { 
            ans[ans_idx++] = s[i]; 
        } 
    } 
  
    // Print the resultant string 
    printf("%s", ans); 
} 
  
// Driver Code 
int main() { 
    char S[] = "geeksforgeeks"; 
    char S1[] = "eek"; 
    char S2[] = "ok"; 
    modifyString(S, S1, S2); 
  
    return 0; 
} 