#include<stdio.h>
 

int main()
{
    char alph[26];
    int k = 3;
    char m = 71;
    sprintf(alph,"GETLIT"); //storing 'GETLIT' into array.
    
    alph = (m + k) % 26;  

    printf("%s", alph);
    
   
    

}
