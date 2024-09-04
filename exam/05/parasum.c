#include <unistd.h>

void ft_putnbr(int n)
{
    unsigned int nbr;
    char c;

    if (n < 0)
    {
        nbr = -n;
        write(1, "-", 1);
    }
    else
    {
        nbr = n;
    }
    if (nbr >= 10)
    {
        ft_putnbr(nbr / 10);
        ft_putnbr(nbr % 10);
    }
    else
    {
        c = nbr + '0';
        write(1, &c, 1);
    }
}

int main(int argc, char **argv)
{
    (void)argv;
    ft_putnbr(argc - 1);
    write(1, "\n" , 1);
    return (0);
}