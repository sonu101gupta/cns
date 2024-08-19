#include<stdio.h>
#include<math.h>
#include<string.h>

int gcd(int a, int h) {
    int temp;
    while (1) {
        temp = a % h;
        if (temp == 0)
            return h;
        a = h;
        h = temp;
    }
}

int modInverse(int e, int phi) {
    int t = 0, newt = 1;
    int r = phi, newr = e;
    while (newr != 0) {
        int quotient = r / newr;
        int temp = newt;
        newt = t - quotient * newt;
        t = temp;
        temp = newr;
        newr = r - quotient * newr;
        r = temp;
    }
    if (r > 1) return -1;
    if (t < 0) t += phi;
    return t;
}

// int txtToint(char text) {
//     int ch=0;
//     if (islower(text)) {
//         ch = (ch * 26) + (text - 'a');
//     }
//     else if (isupper(text)) {
//         ch = (ch * 26) + (text - 'A');
//     }
//     else {
//         printf("Invalid Message");
//         return -1; 
//     }
//     return ch;
// }


// char intTotxt(int msg) {
//     char ch;
 
//     if (msg >= 0 && msg < 26) {
//         ch = (msg + 'a');
//     }
//     else if (msg >= 26 && msg < 52) {
//         ch = (msg - 26 + 'A');
//     }
//     else {
//         printf("Invalid Message");
//         return '\0'; // or any other error code
//     }
//     return ch;
// }

int main() {
    int p, q, e;
    int msg, encrypt, decrypt;
    printf("Enter the prime number 'P' : ");
    scanf("%d", &p);
    
    printf("Enter the prime number 'Q' : ");
    scanf("%d", &q);
    
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    
    printf("Enter the public key 'e' : ");
    scanf("%d", &e);
    
    while (e < phi) {
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }
    
    int d = modInverse(e, phi);
    
    printf("Enter the message : ");
    scanf("%d", &msg);
    // for(int i=0;i<strlen(msg);i++){
        // int plaintext = msg;
    
        int c = pow(msg, e);
        c = fmod(c, n);
    
        encrypt = c;
    
    
        int m = pow(c, d);
	    m = fmod(m, n);
	
	    decrypt = m;
	    
    // }
    printf("\nEncrypted data = %d", encrypt);
    printf("\nOriginal Message Sent = %d", decrypt);
    return 0;
}
