#include <stdio.h>
int main() {
    int m , g , mGod, god, x, ent;
    scanf("%d", &x);
    while (x--) {
        scanf("%d%d", &g, &m);
        mGod = 0; god = 0;
        for (int i = 0; i < g; i++) {
            scanf("%d", &ent);
            if (ent  > god) god = ent;
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &ent);
            if (ent  > mGod) mGod = ent;
        }
        if (god >= mGod)
            printf("Godzilla\n");
        else
            printf("MechaGodzilla\n");
    }
    return 0;
}