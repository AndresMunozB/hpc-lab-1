# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include "getoptFunction.h"

int main(int argc, char *argv[])
{
    int NValue = 0;
    int dValue = 0;
    char* iValue = NULL;
    char* oValue = NULL;
    getoptFunction(argc,argv,&iValue,&oValue,&NValue,&dValue);
    //printf("%s\n",iValue);
    //printf("%s\n",oValue);
    //printf("%d\n",NValue);
    //printf("%d\n",dValue);
    return 0;
}