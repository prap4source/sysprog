#include <stdio.h>
/* 
 * gcc stringfy.c -o stringfy -DFOO=bar
 * $ ./stringfy 
 * first(bar) 
 * second(FOO) 
 */

/* Indirect stringification.  Doing two levels allows the parameter to be a
 ** macro itself.  For example, compile with -DFOO=bar, __stringify(FOO)
 ** converts to "bar".
 **/
#define __stringify_1(x...) #x
#define __stringify(x...) __stringify_1(x)

/* Single level stringification */
#define __stringify_2(x...) #x

int main(void)
{
    printf("first(%s) \n", __stringify(FOO));
    printf("second(%s) \n", __stringify_2(FOO));
    return 0;
}
