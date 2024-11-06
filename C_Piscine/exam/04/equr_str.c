#include <unistd.h>

void equr_str(char *str)
{
    int i;
    int flag;

    i = 0;
    flag = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' '|| str[i] == '\t')
            flag = 1;
        else if (str[i] != ' ' || str[i] != '\t')
        {
            if (flag)
            {
                write(1, " ", 1);
                flag = 0;
            }
            write(1, &str[i], 1);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        equr_str(argv[1]);
    write(1, "\n", 1);
}