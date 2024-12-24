#include <stdio.h>
#include "ft_printf.h"

int main(void){
    char *emptystring = "";

    ft_printf("!!%d %% %s %u %p \n", -123123, emptystring, (unsigned int) 4294967295, emptystring);
    printf("!!%d %% %s %u %p \n", -123123, emptystring, (unsigned int) 4294967295, emptystring);
}
