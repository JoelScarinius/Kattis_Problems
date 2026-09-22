#include <stdio.h>
#include <stdbool.h>

#define MAX_CLAUSES 20

typedef struct {
    int variables[MAX_CLAUSES];
} Clause;

bool isSatisfiable(Clause clauses[], int numClauses, int numVariables) {
    for (int combination = 0; combination < (1 << numVariables); combination++) {
        bool satisfiesAll = true;

        for (int i = 0; i < numClauses; i++) {
            bool clauseSatisfied = false;

            for (int j = 0; j < MAX_CLAUSES; j++) {
                int variable = clauses[i].variables[j];

                if (variable == 0) {
                    break; // End of clause
                }

                int variableIndex = variable > 0 ? variable - 1 : -variable - 1;
                bool isTrue = (combination & (1 << variableIndex)) != 0;

                if ((variable > 0 && isTrue) || (variable < 0 && !isTrue)) {
                    clauseSatisfied = true;
                    break; // Clause is satisfied
                }
            }

            if (!clauseSatisfied) {
                satisfiesAll = false;
                break; // At least one clause is not satisfied
            }
        }

        if (satisfiesAll) {
            return true; // All clauses are satisfied by this combination
        }
    }

    return false; // No combination satisfies all clauses
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        Clause clauses[MAX_CLAUSES];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < MAX_CLAUSES; j++) {
                scanf("%d", &clauses[i].variables[j]);

                if (clauses[i].variables[j] == 0) {
                    break; // End of clause
                }
            }
        }

        if (isSatisfiable(clauses, m, n)) {
            printf("satisfiable\n");
        } else {
            printf("unsatisfiable\n");
        }
    }

    return 0;
}
