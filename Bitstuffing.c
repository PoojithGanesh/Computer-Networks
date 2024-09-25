#include <stdio.h>
void bitStuffing(int input[], int n) 
{
    int stuffed[100];  
    int i, j = 0, count = 0;
    for (i = 0; i < n; i++) 
    {
        stuffed[j] = input[i];  
        j++;
            
        if (input[i] == 1) 
        {
            count++;
        } 
        else 
        {
            count = 0;  
        }
        if (count == 5) {
            stuffed[j] = 0;
            j++;
            count = 0;  
        }
    }
    printf("Stuffed bit sequence: ");
    for (i = 0; i < j; i++) {
        printf("%d", stuffed[i]);
    }
    printf("\n");
}
int main() 
{
    int input[100], n, i;
    printf("Enter the number of bits: ");
    scanf("%d", &n);
    printf("Enter the bit sequence (0s and 1s): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &input[i]);  
    }
    bitStuffing(input, n);
    return 0;
}
Output:
Enter the number of bits: 8
Enter the bit sequence (0s and 1s): 1 1 1 1 1 0 0 1 
Stuffed bit sequence: 111110001
