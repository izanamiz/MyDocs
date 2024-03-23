#include <stdio.h>

char *weekday(int n)
{
    switch(n)
    {
        case 2: return "Monday";
        case 3: return "Tuesday";

    }
    return " ";
}
int main()
{
    char *ngay = weekday(3);
    printf("%s",ngay);
}