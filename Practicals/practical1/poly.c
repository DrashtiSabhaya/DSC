/*A polynomial is of the form 5x 3 +10x+3. Write a program for
given p(x) and appoint say x from user, finds the value of p(x) at
that point.*/
#include <stdio.h>
void main()
{
    int array[10];
    int i, num, power;
    float x, polySum;
 
    printf("Enter the order of the polynomial = ");
    scanf("%d", &num);
    printf("Enter the value of x = ");
    scanf("%f", &x);
    for (i = 0; i <= num; i++)
    {
    	printf("Enter %d coefficients = ", i+1);
        scanf("%d", &array[i]);
    }
    polySum = array[0];
    for (i = 1; i <= num; i++)
        polySum = polySum * x + array[i];
    power = num;
 
    printf("----Polynomial---- \n");
    for (i = 0; i <= num; i++)
    {
       if (power < 0)
            break;
       if(i!=num)
        	printf("%dx^%d + ", array[i], power--);
       else
       		printf("%dx^%d ", array[i], power--);
     }
    printf("\nSum of the polynomial = %6.2f \n", polySum);
}
