// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// struct stats {
//     int A;
//     int D;
//     int H;
// };

// void insertionSort(int n, int a[])
// {
//     for (int i = 1; i <= n-1; i++)
//     {
//         int val = a[i], j = i-1;
//         while (j >= 0 && a[j] > val) // Critical operation is the comparison a[j] > val.
//         {
//             a[j+1] = a[j]; 
//             j -= 1;
//         }
//         a[j+1] = val;
//     }
// }

// int main() {
//     int N, K, count = 0, front = 0, rear = 0, Ataken = 1, Dtaken = 1, Htaken = 1;
//     bool isOK = true;

//     scanf("%d %d", &N, &K);
//     struct stats *s = malloc(N * sizeof(struct stats));
//     int *maxA = malloc(K * sizeof(int));
//     int *maxD = malloc(K * sizeof(int));
//     int *maxH = malloc(K * sizeof(int));
//     struct stats *selected = calloc(K * 3, sizeof(struct stats));

//     for (int i = 0; i < N; i++)
//     {
//         scanf("%d %d %d", &(s + i)->A, &(s + i)->D, &(s + i)->H);
//         maxA[i] = (s + i)->A;
//         maxD[i] = (s + i)->D;
//         maxH[i] = (s + i)->H;
//     }
//     insertionSort(N, maxA);
//     insertionSort(N, maxD);
//     insertionSort(N, maxH);
//     for (int j = 0; j < N; j++)
//     {
//         if (maxA[N - Ataken] == (s + j)->A && maxD[N - Dtaken] == (s + j)->D && maxH[N - Htaken] == (s + j)->H)
//         {
//             Dtaken++;
//             Htaken++;
//         }
//         else if (maxA[N - Ataken] == (s + j)->A && maxD[N - Dtaken] == (s + j)->D)
//         {
//             Dtaken++;
//         }
//         else if (maxA[N - Ataken] == (s + j)->A && maxH[N - Htaken] == (s + j)->H)
//         {
//             Htaken++;
//         }
//         else if (maxD[N - Dtaken] == (s + j)->D && maxH[N - Htaken] == (s + j)->H)
//         {
//             Htaken++;
//         }
//             if (maxA[N - Ataken] == (s + j)->A)
//             {
//                 selected[rear] = s[j];
//                 count++;
//                 rear++;
//                 Ataken++;
//             }
//             else if (maxD[N - Dtaken] == (s + j)->D)
//             {
//                 selected[rear] = s[j];
//                 count++;
//                 rear++;
//                 Dtaken++;
//             }
//             else if (maxH[N - Htaken] == (s + j)->H)
//             {
//                 selected[rear] = s[j];
//                 count++;
//                 rear++;
//                 Htaken++;
//             }
//     }
//     for (int i = 0; i < K * 3; i++)
//     {
//         for (int j = i + 1; j < K * 3; j++)
//         {
//             if (selected[i].D > selected[j].D && selected[i].H > selected[j].H && selected[i].A > selected[j].A)
//             {
//                 count = count - 2;
//             }
//             if (selected[i].D > selected[j].D && selected[i].H < selected[j].H && selected[i].A > selected[j].A)
//             {
//                 count = count - 1;
//             }
//             if (selected[i].H > selected[j].H && selected[i].D < selected[j].D && selected[i].A > selected[j].A)
//             {
//                 count = count - 1;
//             }
//             if (selected[i].H > selected[j].H && selected[i].D > selected[j].D && selected[i].A < selected[j].A)
//             {
//                 count = count - 1;
//             }
//         }
//     }
//     printf("%d\n", count);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     long int stats[3];
// } Pokenom;
// int J = 2;

// int compare(const void *a, const void *b) {
//     const Pokenom *pa = (const Pokenom *)a;
//     const Pokenom *pb = (const Pokenom *)b;

//     if (pa->stats[J] < pb->stats[J]) return 1;
//     if (pa->stats[J] > pb->stats[J]) return -1;
//     return 0;
// }

// int main() {
//     int N, K, rear = 0, Ataken = 0, Dtaken = 0, Htaken = 0;
//     long int countCollected = 0;
//     scanf("%d %d", &N, &K);
//     Pokenom *pokenoms = (Pokenom *)malloc(N * sizeof(Pokenom));
//     Pokenom *Asorted = (Pokenom *)malloc(N * sizeof(Pokenom));
//     Pokenom *Dsorted = (Pokenom *)malloc(N * sizeof(Pokenom));
//     Pokenom *Hsorted = (Pokenom *)malloc(N * sizeof(Pokenom));
//     Pokenom *collected = (Pokenom *)calloc(K * 3, sizeof(Pokenom));

//     for (int i = 0; i < N; i++) {
//         scanf("%ld %ld %ld", &pokenoms[i].stats[0], &pokenoms[i].stats[1], &pokenoms[i].stats[2]);
//     }

//     qsort(pokenoms, N, sizeof(Pokenom), compare);
//     for (int i = 0; i < N; i++)
//     {
//         Hsorted[i] = pokenoms[i];
//     }
//     J--;
//     qsort(pokenoms, N, sizeof(Pokenom), compare);
//     for (int i = 0; i < N; i++)
//     {
//         Dsorted[i] = pokenoms[i];
//     }
//     J--;
//     qsort(pokenoms, N, sizeof(Pokenom), compare);
//     for (int i = 0; i < N; i++)
//     {
//         Asorted[i] = pokenoms[i];
//     }
//     for (int i = 0; i < K * 3; i++)
//     {
//         if (Hsorted[i].stats[2] == -1)
//             Htaken++;
//         if (Hsorted[Htaken].stats[2] == Dsorted[Dtaken].stats[2] && Hsorted[Htaken].stats[2] == Asorted[Ataken].stats[2])
//         {
//             collected[rear] = Hsorted[i];
//             rear++;
//             Htaken++;
//             Dtaken++;
//             Ataken++;
//             countCollected = countCollected + 2;
//         }
//         else if (Hsorted[Htaken].stats[1] == Dsorted[Dtaken].stats[1] && Hsorted[Htaken].stats[2] == Dsorted[Dtaken].stats[2])
//         {
//             collected[rear] = Hsorted[i];
//             rear++;
//             Htaken++;
//             Dtaken++;
//             countCollected++;
//         }
//         else if (Hsorted[Htaken].stats[0] == Asorted[Ataken].stats[0] && Hsorted[Htaken].stats[2] == Asorted[Ataken].stats[2])
//         {
//             collected[rear] = Hsorted[i];
//             rear++;
//             Htaken++;
//             Ataken++;
//             countCollected++;
//         }
//         else if (Htaken < Ataken && Htaken < Dtaken)
//         {
//             collected[rear] = Hsorted[Htaken];
//             rear++;
//             Htaken++;
//         }
//         else if (Dtaken <= Ataken && Dtaken <= Htaken)
//         {
//             if (Dsorted[Dtaken].stats[0] == Asorted[Ataken].stats[0])
//             {
//                 countCollected++;
//                 Ataken++;
//             }
//             collected[rear] = Dsorted[Dtaken];
//             rear++;
//             if (Hsorted[Htaken + 1].stats[1] == Dsorted[Dtaken].stats[1])
//                 Hsorted[Htaken + 1].stats[2] = -1;
//             Dtaken++;
//         }
//         else if (Ataken <= Htaken && Ataken <= Dtaken)
//         {
//             if (Dsorted[Dtaken].stats[0] == Asorted[Ataken].stats[0])
//             {
//                 countCollected++;
//                 Dtaken++;
//             }
//             collected[rear] = Asorted[Ataken];
//             rear++;
//             if (Hsorted[Htaken + 1].stats[0] == Asorted[Ataken].stats[0])
//                 Hsorted[Htaken + 1].stats[2] = -1;
//             Ataken++;
//         }
//         if (i + Htaken >= (K * 3) - countCollected && i + Dtaken >= (K * 3) - countCollected && i + Ataken >= (K * 3) - countCollected)
//         {
//             if (K == (1 + rear))
//                 rear++;
//             break;
//         }
//     }
//     printf("%d\n", rear);

//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     long int A, D, H;
// } Pokenom;

// int compare(const void *a, const void *b) {
//     const Pokenom *pa = (const Pokenom *)a;
//     const Pokenom *pb = (const Pokenom *)b;

//     // Compare based on the first attribute
//     if (pa->A < pb->A) return 1;
//     if (pa->A > pb->A) return -1;
//     return 0;
// }

// int main() {
//     int N, K;
//     scanf("%d %d", &N, &K);

//     Pokenom *pokenoms = (Pokenom *)malloc(N * sizeof(Pokenom));
//     for (int i = 0; i < N; i++) {
//         scanf("%ld %ld %ld", &pokenoms[i].A, &pokenoms[i].D, &pokenoms[i].H);
//     }

//     qsort(pokenoms, N, sizeof(Pokenom), compare);

//     Pokenom *selected = malloc(K * 3 * sizeof(Pokenom));
//     long int selectedCount = 0;
//     for (int j = 0; j < N; j++) {
//         for (int i = 0; i < K; i++) {
//             selected[selectedCount++] = pokenoms[j];
//         }
//     }
//     for (int i = 0; i < K * 3; i++)
//     {
//         for (int j = i + 1; j < K * 3; j++)
//         {
//             if (selected[i].D > selected[j].D && selected[i].H > selected[j].H && selected[i].A > selected[j].A)
//             {
//                 selectedCount = selectedCount - 2;
//                 break;

//             }
//             if (selected[i].D > selected[j].D && selected[i].H < selected[j].H && selected[i].A > selected[j].A)
//             {
//                 selectedCount = selectedCount - 1;
//                 break;
//             }
//             if (selected[i].H > selected[j].H && selected[i].D < selected[j].D && selected[i].A > selected[j].A)
//             {
//                 selectedCount = selectedCount - 1;
//                 break;

//             }
//             if (selected[i].H > selected[j].H && selected[i].D > selected[j].D && selected[i].A < selected[j].A)
//             {
//                 selectedCount = selectedCount - 1;
//                 break;

//             }
//         }
//     }
    
//     printf("%ld\n", selectedCount);

//     // free(pokenoms);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     long a, d, h;
//     int taken;
// } Pokemon;

// int compare_atk(const void *a, const void *b) {
//     const Pokemon *pa = (const Pokemon *)a;
//     const Pokemon *pb = (const Pokemon *)b;
//     return (pa->a < pb->a) ? 1 : (pa->a > pb->a) ? -1 : 0;
// }

// int compare_def(const void *a, const void *b) {
//     const Pokemon *pa = (const Pokemon *)a;
//     const Pokemon *pb = (const Pokemon *)b;
//     return (pa->d < pb->d) ? 1 : (pa->d > pb->d) ? -1 : 0;
// }

// int compare_health(const void *a, const void *b) {
//     const Pokemon *pa = (const Pokemon *)a;
//     const Pokemon *pb = (const Pokemon *)b;
//     return (pa->h < pb->h) ? 1 : (pa->h > pb->h) ? -1 : 0;
// }

// int main() {
//     int cases, k;
//     scanf("%d %d", &cases, &k);

//     Pokemon *attack = (Pokemon *)malloc(cases * sizeof(Pokemon));
//     Pokemon *defense = (Pokemon *)malloc(cases * sizeof(Pokemon));
//     Pokemon *health = (Pokemon *)malloc(cases * sizeof(Pokemon));

//     for (int x = 0; x < cases; x++) {
//         long a, d, h;
//         scanf("%ld %ld %ld", &a, &d, &h);
//         attack[x].a = defense[x].d = health[x].h = a;
//         attack[x].d = defense[x].d = health[x].h = d;
//         attack[x].h = defense[x].d = health[x].h = h;
//         attack[x].taken = defense[x].taken = health[x].taken = 0;
//     }

//     qsort(attack, cases, sizeof(Pokemon), compare_atk);
//     qsort(defense, cases, sizeof(Pokemon), compare_def);
//     qsort(health, cases, sizeof(Pokemon), compare_health);

//     int count = 0;
//     for (int x = 0; x < k; x++) {
//         if (!attack[x].taken) {
//             attack[x].taken = 1;
//             count++;
//         }
//         if (!defense[x].taken) {
//             defense[x].taken = 1;
//             count++;
//         }
//         if (!health[x].taken) {
//             health[x].taken = 1;
//             count++;
//         }
//     }

//     printf("%d\n", count);

//     free(attack);
//     free(defense);
//     free(health);

//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     long a, d, h;
//     int taken;
// } Pokemon;

// int compare_atk(const void *a, const void *b) {
//     const Pokemon *pa = (const Pokemon *)a;
//     const Pokemon *pb = (const Pokemon *)b;
//     return (pa->a < pb->a) ? 1 : (pa->a > pb->a) ? -1 : 0;
// }

// int compare_def(const void *a, const void *b) {
//     const Pokemon *pa = (const Pokemon *)a;
//     const Pokemon *pb = (const Pokemon *)b;
//     return (pa->d < pb->d) ? 1 : (pa->d > pb->d) ? -1 : 0;
// }

// int compare_health(const void *a, const void *b) {
//     const Pokemon *pa = (const Pokemon *)a;
//     const Pokemon *pb = (const Pokemon *)b;
//     return (pa->h < pb->h) ? 1 : (pa->h > pb->h) ? -1 : 0;
// }

// int main() {
//     int cases, k;
//     scanf("%d %d", &cases, &k);

//     Pokemon *attack = (Pokemon *)malloc(cases * sizeof(Pokemon));
//     Pokemon *defense = (Pokemon *)malloc(cases * sizeof(Pokemon));
//     Pokemon *health = (Pokemon *)malloc(cases * sizeof(Pokemon));

//     for (int x = 0; x < cases; x++) {
//         scanf("%ld %ld %ld", &attack[x].a, &attack[x].d, &attack[x].h);
//         defense[x] = health[x] = attack[x];
//         attack[x].taken = defense[x].taken = health[x].taken = 0;
//     }

//     qsort(attack, cases, sizeof(Pokemon), compare_atk);
//     qsort(defense, cases, sizeof(Pokemon), compare_def);
//     qsort(health, cases, sizeof(Pokemon), compare_health);

//     int count = 0;
//     for (int x = 0; x < k; x++) {
//         if (!attack[x].taken) {
//             attack[x].taken = 1;
//             count++;
//         }
//         if (!defense[x].taken) {
//             defense[x].taken = 1;
//             count++;
//         }
//         if (!health[x].taken) {
//             health[x].taken = 1;
//             count++;
//         }
//     }

//     printf("%d\n", count);

//     free(attack);
//     free(defense);
//     free(health);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     int attack, defense, health;
// } Pokenom;

// int compare_attack(const void *a, const void *b) {
//     const Pokenom *pa = (const Pokenom *)a;
//     const Pokenom *pb = (const Pokenom *)b;
//     return pb->attack - pa->attack;
// }

// int compare_defense(const void *a, const void *b) {
//     const Pokenom *pa = (const Pokenom *)a;
//     const Pokenom *pb = (const Pokenom *)b;
//     return pb->defense - pa->defense;
// }

// int compare_health(const void *a, const void *b) {
//     const Pokenom *pa = (const Pokenom *)a;
//     const Pokenom *pb = (const Pokenom *)b;
//     return pb->health - pa->health;
// }

// int main() {
//     int n, k;
//     scanf("%d %d", &n, &k);

//     Pokenom *pokenoms = (Pokenom *)malloc(n * sizeof(Pokenom));

//     for (int i = 0; i < n; i++) {
//         scanf("%d %d %d", &pokenoms[i].attack, &pokenoms[i].defense, &pokenoms[i].health);
//     }

//     qsort(pokenoms, n, sizeof(Pokenom), compare_attack);
//     qsort(pokenoms, n, sizeof(Pokenom), compare_defense);
//     qsort(pokenoms, n, sizeof(Pokenom), compare_health);

//     int selected_count = 0;
//     for (int i = 0; i < k; i++) {
//         selected_count++;
//     }

//     printf("%d\n", selected_count);

//     free(pokenoms);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long int stats[3];
} Pokenom;
int J = 2;

int compare(const void *a, const void *b) {
    const Pokenom *pa = (const Pokenom *)a;
    const Pokenom *pb = (const Pokenom *)b;

    if (pa->stats[J] < pb->stats[J]) return 1;
    if (pa->stats[J] > pb->stats[J]) return -1;
    return 0;
}

int main() {
    int N, K, rear = 0, Ataken = 0, Dtaken = 0, Htaken = 0;
    long int countCollected = 0;
    scanf("%d %d", &N, &K);
    Pokenom *pokenoms = (Pokenom *)malloc(N * sizeof(Pokenom));
    Pokenom *Asorted = (Pokenom *)malloc(N * sizeof(Pokenom));
    Pokenom *Dsorted = (Pokenom *)malloc(N * sizeof(Pokenom));
    Pokenom *Hsorted = (Pokenom *)malloc(N * sizeof(Pokenom));
    Pokenom *collected = (Pokenom *)calloc(K * 3, sizeof(Pokenom));

    for (int i = 0; i < N; i++) {
        scanf("%ld %ld %ld", &pokenoms[i].stats[0], &pokenoms[i].stats[1], &pokenoms[i].stats[2]);
    }

    qsort(pokenoms, N, sizeof(Pokenom), compare);
    for (int i = 0; i < N; i++)
    {
        Hsorted[i] = pokenoms[i];
    }
    J--;
    qsort(pokenoms, N, sizeof(Pokenom), compare);
    for (int i = 0; i < N; i++)
    {
        Dsorted[i] = pokenoms[i];
    }
    J--;
    qsort(pokenoms, N, sizeof(Pokenom), compare);
    for (int i = 0; i < N; i++)
    {
        Asorted[i] = pokenoms[i];
    }
    for (int i = 0; i < K * 3; i++)
    {
        if (Hsorted[i].stats[2] == -1)
            Htaken++;
        if (Hsorted[Htaken].stats[2] == Dsorted[Dtaken].stats[2] && Hsorted[Htaken].stats[2] == Asorted[Ataken].stats[2])
        {
            collected[rear] = Hsorted[i];
            rear++;
            Htaken++;
            Dtaken++;
            Ataken++;
            countCollected = countCollected + 2;
        }
        else if (Hsorted[Htaken].stats[1] == Dsorted[Dtaken].stats[1] && Hsorted[Htaken].stats[2] == Dsorted[Dtaken].stats[2])
        {
            collected[rear] = Hsorted[i];
            rear++;
            Htaken++;
            Dtaken++;
            countCollected++;
        }
        else if (Hsorted[Htaken].stats[0] == Asorted[Ataken].stats[0] && Hsorted[Htaken].stats[2] == Asorted[Ataken].stats[2])
        {
            collected[rear] = Hsorted[i];
            rear++;
            Htaken++;
            Ataken++;
            countCollected++;
        }
        else if (Htaken < Ataken && Htaken < Dtaken)
        {
            collected[rear] = Hsorted[Htaken];
            rear++;
            Htaken++;
        }
        else if (Dtaken <= Ataken && Dtaken <= Htaken)
        {
            if (Dsorted[Dtaken].stats[0] == Asorted[Ataken].stats[0])
            {
                countCollected++;
                Ataken++;
            }
            collected[rear] = Dsorted[Dtaken];
            rear++;
            if (Hsorted[Htaken + 1].stats[1] == Dsorted[Dtaken].stats[1])
                Hsorted[Htaken + 1].stats[2] = -1;
            Dtaken++;
        }
        else if (Ataken <= Htaken && Ataken <= Dtaken)
        {
            if (Dsorted[Dtaken].stats[0] == Asorted[Ataken].stats[0])
            {
                countCollected++;
                Dtaken++;
            }
            collected[rear] = Asorted[Ataken];
            rear++;
            if (Hsorted[Htaken + 1].stats[0] == Asorted[Ataken].stats[0])
                Hsorted[Htaken + 1].stats[2] = -1;
            Ataken++;
        }
        if (i + Htaken >= (K * 3) - countCollected && i + Dtaken >= (K * 3) - countCollected && i + Ataken >= (K * 3) - countCollected)
        {
            if (K == (1 + rear))
                rear++;
            break;
        }
        else if (rear + countCollected == N)
            break;
    }
    printf("%d\n", rear);

    return 0;
}