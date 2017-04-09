
/* If a number has consecutive 1's then it is sparse 
 * Eg: 14 - > 1110
 * Logic: bitwise And Number with shifted Number gives
 * 1110 & 0111 
 */
int sparseorNot(int N){
    
    if ( N & (N >>1))
        return 1;
    return 0;
}

/* Find position of First sparse 
 * Eg: 14 -> 1110 -> position is 2 and 3
 * Logic: Get First two bits values and see whether both are set
 * repeat this by clearing that bit equivalent to moving the position
 */
void findPostionofSparse(int N) {
    char first_bit, second_bit;
    int k;
    for (k=1; N; k++) {
		/* Check 2 positions are set */
        first_bit = N & ( 1 << (k-1)) ? 1:0;
        second_bit = N & ( 1 << k) ? 1:0;
         
        if (first_bit & second_bit) {
            printf ("%d and %d are consecutive", k, k+1);
            break;
        }
        /* clear the k  bit ,equivalent to moving to next position*/
        N = N & ~ (1 << (k -1));
        }
}
/* Find if Number is Power of 2 
 * Logic N & (N-1) will be zero if Number is power of 2 (has single ), To deal
 * zero we AND N with result
 * Eg: 4 - 0100
 * This function returns 0 If number is not power of 2 
 */
int isPowerof2(int N) {
	return (N && !(N & (N - 1)))
}

/*
Logic:  Move each bit (i) until a set bit is found 
*/
int findSetBit(int N) {
	int i =0;
	while (!(i&N)) {
		i << 1;
		pos ++;
	}
}

/*
 Swap Even and odd bits
 Logic: Take 2 bits at a time and their values
 Clear that bit position and OR it with new value  
*/

int swapBits(int N) {
    int odd, even;
    int k;
    N = N & 0xFFFFFFFF; 
    for (k=0; k < 32; k +=2) {
        odd = (N & (0x1 << k)) ?1:0;
        even = (N & (0x1<< (k+1))) ?1:0;
        if (odd == even)
           continue;
        /* Clear that bit and use value of even bit */
        N  = (N & ~(1<<k)) | (even <<k);
        /* Clear this bit and use value of odd bit */
        N  = (N & ~(1<<(k+1))) | (odd << (k+1));
    
    }
    printf ("New number is %d",N);
}

/* Logic: Traverse through each bit */

void converttoBit(int N)
{
    unsigned int i;
    for ( i = 1 << 31; i >0; i = i / 2 ) {
        (i&N) ? printf("1") : printf("0");
    }
}
