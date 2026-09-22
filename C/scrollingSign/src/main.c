#include <stdio.h>
#include <string.h>

int main() 
{
    int n;
    scanf("%d", &n);

    while (n--) 
    {
        int k;
        int w;
        scanf("%d %d", &k, &w);

        int total = 0;
        int count = 0;
        char word[101] = "";

        while (w--) 
        {
            if (word[0] == '\0') 
            {
                scanf("%s", word);
                total += strlen(word);
            } 
            else 
            {
                char s[101];
                scanf("%s", s);
                total += strlen(s);

                int c = 0;
                int x = strlen(word) - 1;
                int a = 1;

                while (x >= 0 && a <= strlen(s)) 
                {
                    char sub1[101];
                    char sub2[101];

                    strncpy(sub1, word + x, strlen(word) - x);
                    sub1[strlen(word) - x] = '\0';

                    strncpy(sub2, s, a);
                    sub2[a] = '\0';

                    if (strcmp(sub1, sub2) == 0) 
                    {
                        c = strlen(sub1);
                    }
                    x--;
                    a++;
                }
                count += c;
                strcpy(word, s);
            }
        }
        printf("%d\n", total - count);
    }
    return 0;
}