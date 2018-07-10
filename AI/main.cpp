#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<malloc.h>

char map[4][4];
clock_t start,finish;

struct NODE {
    int x;
    int y;
    double UCB;
    struct NODE* son;
};

NODE head, *current;

int check() {
    int i, j;
    int xa = 0, xb = 0;
    int ya = 0, yb = 0;
    for(i = 0; i < 4; i++){
        int ra = 0, rb = 0;
        int ca = 0, cb = 0;
        if(map[i][i] == 'x')
            xa += 1;
        else if(map[i][i] == 'o')
            xb += 1;
        if(map[i][3-i] == 'x')
            ya += 1;
        else if(map[i][3-i] == 'o')
            yb += 1;
        for(j = 0; j < 4; j++){
            if(map[i][j] == 'x')
                ra += 1;
            else if(map[i][j] == 'o')
                rb += 1;
            if(map[j][i] == 'x')
                ca += 1;
            else if(map[j][i] == 'o')
                cb += 1;
        }
        if(ra == 4 || ca == 4 || xa == 4 || ya == 4)
            return 1;
        else if(rb == 4 || cb == 4 || xb == 4 || yb == 4)
            return -1;
    }
    return 0;

}

void UCT( int player) {
    srand(time(NULL));
    int chess;
    int x, y;
    double TheTimes;
    NODE *cur;
    cur=(NODE*)malloc(sizeof(NODE));
    cur->son=NULL;


    TheTimes=(double)((finish-start)/CLOCKS_PER_SEC);
    if (TheTimes<=2.000000) {
        a:chess=rand()%16;
        if (chess%4==0) {
            x=chess/4-1;
            y=3;
        }
        else {
            x=chess/4;
            y=chess%4-1;
        }
        if (map[x][y]==' ') {
            if (player&1)
                map[x][y]='o';
            else
                map[x][y]='x';
        }
        else
            goto a;
        cur->x=x;
        cur->y=y;
        if (head.son==NULL) {
            cur->son=head.son;
            head.son=cur;
            current=cur;
        }
        else {
            current->son=cur;
            current=cur;
        }

        finish=clock();
    }


}


int main (void) {
    for (int i=0;i<4;i++)
        strcpy(map[i], "    ");
    int x, y;
    NODE chess;
    head.son=NULL;


    while (1) {
        printf ("your turn:");
        scanf ("%d %d", x, y);
        map[x][y]='x';
        start=clock();
        if (check()==0) {
            UCT( 1);
            printf ("SK chose (%d,%d)\n", chess.x, chess.y);
            for (int i=0;i<4;i++) {
                for (int j = 0; j < 4; j++)
                    printf ("%c", map[i][j]);
                printf ("\n");
            }
            continue;
        }
        else if (check()==1) {
            printf ("you win!");
            return 0;
        }
        else  {
            printf ("you lose!");
            return 0;
        }
    }
}