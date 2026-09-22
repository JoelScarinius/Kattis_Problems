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