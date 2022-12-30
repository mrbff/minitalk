#include <unistd.h>

void    f_printbits(unsigned char c)
{
        int             i;
        unsigned char   revbits[8];

        i = 0;
        while (i < 8)
        {
                revbits[i] = c % 2 + 48;
                if (c)
                        c /= 2;
                i++;
        }
        while (--i >= 0)
                write(1, &revbits[i], 1);
        write(1, " ", 1);
}

void    f_printbytes(char *s)
{
        int     i;

        i = 0;
        while (s[i])
        {
                f_printbits(s[i]);
                i++;
        }
}
