#include <math.h>
#include <stdio.h>

long long int power(long long int a, long long int b, long long int P)
{
    if (b == 1)
        return a;
    else
        return (((long long int)pow(a, b)) % P);
}

int main()
{
    long long int P, G, x, a, y, b, ka, kb;

   
    printf("Enter the value of prime number P: ");
    scanf("%lld", &P);
    printf("Enter the value of primitive root G: ");
    scanf("%lld", &G);
    printf("Enter the private key for User 1 (a): ");
    scanf("%lld", &a);
    printf("Enter the private key for User 2 (b): ");
    scanf("%lld", &b);

    printf("\nThe value of P : %lld\n", P);
    printf("The value of G : %lld\n\n", G);
    printf("The private key a for Alice : %lld\n", a);
    printf("The private key b for Bob : %lld\n\n", b);

    
    x = power(G, a, P); 
    y = power(G, b, P); 

    
    ka = power(y, a, P); 
    kb = power(x, b, P); 

    printf("Public key for Alice is : %lld\n", x);
    printf("Public key for Bob is : %lld\n", y);

    
    if (ka == kb) {
        printf("\nKey exchange successful!\n");
        printf("Secret key for User 1 is : %lld\n", ka);
        printf("Secret key for User 2 is : %lld\n", kb);
        return 1;
    } else {
        printf("\nKey exchange failed!\n");
        return 0;
    }
}
