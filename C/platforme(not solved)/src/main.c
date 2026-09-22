#include <stdio.h>

int length(int platforms[][3], int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        int y = platforms[i][0];
        int x1 = platforms[i][1];
        int x2 = platforms[i][2];
        
        int l = -1, r = -1;
        
        for (int j = i - 1; j >= 0; j--) {
            int y2 = platforms[j][0];
            int x3 = platforms[j][1];
            int x4 = platforms[j][2];
            
            if (l == -1 && x3 <= x1 && x1 <= x4) {
                l = y - y2;
            }
            
            if (r == -1 && x3 <= x2 && x2 <= x4) {
                r = y - y2;
            }
            
            if (l != -1 && r != -1) {
                break;
            }
        }
        
        s += (l != -1 ? l : y) + (r != -1 ? r : y);
    }
    return s;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int platforms[n][3];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &platforms[i][0], &platforms[i][1], &platforms[i][2]);
    }
    
    printf("%d\n", length(platforms, n));
    
    return 0;
}
