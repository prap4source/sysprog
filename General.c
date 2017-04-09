#include <stdio.h>
/* Big endian format: MSB is saved in Least Address (network order)
------------------
Byte address  | 0x01 | 0x02 | 0x03 | 0x04 | 
              +++++++++++++++++++++++++++++
Byte content  | 0x76 | 0x54 | 0x32 | 0x10 |
			 
Little endian format: LSB is saved in least address`(host order)
---------------------
Byte address  | 0x01 | 0x02 | 0x03 | 0x04 | 
              +++++++++++++++++++++++++++++
Byte content  | 0x10 | 0x32 | 0x54 | 0x76 | 
*/
findEndianess(int x) {
   char *c = (char*) &x;
   printf ("*c is: 0x%x\n", *c);
  if (*c == 0x10)
  {
    printf ("Underlying architecture is little endian. \n");
  }
  else
  {
     printf ("Underlying architecture is big endian. \n");
  }
}


void findHighestDrop(int arr[])
{

int highest, drop,i,a;
highest = drop = a =0;
for (i=0;i< sizeof(arr);i++) {
    a = arr[i];
    drop = (highest-a) > drop ? (highest -a): drop;
    highest = (highest > a) ? highest : a;
    printf ("drop%d i%d highest%d a%d\n", drop, i, highest,a);
}

printf ("Highest Drop is %d",drop);
}

/* Function to reverse the sequence from start to end */
void reverseAny(char *start, char *end)
{
    char temp;
    while (start < end) {
        temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}
/* Reverse entire Sentence */
void reverse(char *str)
{
    char *str1 =str, *temp = str, *wordbegin;
    printf ("Before %s \n", str);
    while (*temp != '\0') {
        temp ++;
    }
       
    /* First reverse entire sentence 
     Now it will be "gnirts siht esreveR" */
    reverseAny(str1, temp-1);
    temp = str1;
    wordbegin = str1;
        
    /* Now reverse each word */
    while (1) {
           temp++;
            if (*temp == ' '){
                reverseAny(wordbegin, temp-1);
                wordbegin = temp +1;
            }
            if (*temp == '\0') {
               reverseAny(wordbegin, temp-1);
               break;
            }
    }
     printf ("After %s \n", str1);
}
int main ()
{
  unsigned int x = 0x76543210;
  char str[] = "Reverse this string";
  char arr[]={2,1,5,9,11,27,35,40,4,1};
  findEndianess(x);
  reverse(str);
  findHighestDrop(arr);
 
  return 0;
}