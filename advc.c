#include <stdio.h>


//extern void exitnow() __attribute__((noreturn));
static int  myfunc(){
	int i = 0;
	///if (i)
	  //exitnow();
    	return 1;
}
int main() {
	char *s ="-Dfoo";
	myfunc();
	printf("%s --> %s \n",s,__stringify("-Dfoo"));
	return 0;
}
