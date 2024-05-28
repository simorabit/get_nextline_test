#include <unistd.h>
#include <stdarg.h>

void put_string(char *s, int *len)
{
    if(!s)
        s = "(null)";
    while(*s)
        *len += write(1, s++, 1);
}
void put_digit(long long int digit, int base, int *len)
{
    char *hexa = "0123456789abcdef";
    if(digit < 0)
    {
        digit *= -1;
        *len += write(1, "-", 1);
    }
    if(digit >= base)
        put_digit(digit / base, base, len);
    *len += write(1, &hexa[digit % base], 1);
}
void put_digit(long long int digit, int base, int *len)
{
    char *hexa = "0123456789abcdef";
    if(digit < 0)
    {
        digit *= -1;
        *len += write(1, "-", 1);
    }
    if(digit >= base)
        put_digit(digit / base, base, len);
    *len += write(1, &hexa[digit % base], 1);
}

void put_str(char *s, int *len)
{
    if(!s)
        s = "(null)";
    while (*s)
        *len = write(1, s++, 1);
}
int ft_printf(char *s, ...)
{
    int i = 0;
    int len = 0;
    va_list vlist;
    va_start(vlist, s);

    while (s[i])
    {
        if(s[i] == '%' && (s[i + 1] == 'd' || s[i + 1] == 'x' || s[i + 1] == 's'))
        {
            i++;
            if(s[i] == 's')
                put_string(va_arg(vlist, char*), &len);
            else if(s[i] == 'd')
                put_digit((long long int)va_arg(vlist, int), 10, &len);
            else if(s[i] == 'x')
                put_digit((long long int)va_arg(vlist, unsigned int), 16, &len);
        }
        else
            len += write(1, &s[i], 1);
        i++;
    }
    return (va_end(vlist), len);
}
int ft_printf(char *data, ...)
{
    int i = 0;
    int len = 0;
    va_list vlist;
    va_start(vlist, data);

    while (data[i])
    {
        if(data[i] == '%' && (data[i + 1] == 'd' || data[i + 1] == 'x' || data[i + 1] == 's'))
        {
            i++;
            if(data[i] == 's')
                put_string(va_arg(vlist, char*), &len);
            else if(data[i] == 'x')
                put_digit((long long int)va_arg(vlist, unsigned int), 16, &len);
            else if(data[i] == 'd')
                put_digit((long long int)va_arg(vlist, int), 10, &len);
        }
        else
            len += write(1, &data[i], 1);
        i++;
    }
    return (va_end(vlist), len);
}
int main()
{
    ft_printf("fdsfdsf%d", 115454);
}