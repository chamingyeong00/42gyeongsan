#include <unistd.h>

void hidenp(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    int s1_len = 0;
    int cnt = 0;

    while (s1[i] != '\0')
    {
        s1_len++;
        i++;
    }  
    i = 0;
    while (s1[i] != '\0')
    {
        while (s2[j] != '\0')
        {
            if (s1[i] == s2[j])
            {
                cnt++;
                j++;
                break;
            }    
            j++;
        }
        i++;
    }
    if (s1_len == cnt)
    {
        write(1, "1", 1);
    }
    else
        write(1, "0", 1);
}

int main(int argc, char **argv)
{
    if (argc == 3)
        hidenp(argv[1], argv[2]);
    write(1, "\n", 1);
}