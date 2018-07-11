#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<malloc.h>
#include <limits.h>
#include<math.h>
#define MAX 10
#define MIN 5
char map[4][4], map1[4][4], map2[4][4];;
clock_t start,finish;

struct Chess {
    int x;
    int y;
    int player;
    double rate;
    double UCB;
    int win;
    int visit;
    Chess *father;
    Chess *son;
    Chess *brother;
};

Chess head;

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
            return 0;
    }
    return -1;

}

void MCT (int player, Chess ways) {
    int chess;

    chess=rand()%16;
    if (chess%4==0) {
        ways.x=chess/4-1;
        ways.y=3;
    }
    else {
        ways.x=chess/4;
        ways.y=chess%4-1;
    }
    map2[ways.x][ways.y]='o';
}

void UCT(int player, int n) {
    Chess ways[16];
    int chess=1;

    for (int i=0; i< n; i++) {
        ways[i].player=player;
        ways[i].win=0;
        ways[i].visit=0;

        for (int i = 0; i < 4; i++)
            strcpy(map2[i], map1[i]);
        MCT(ways[i].player, ways[i]);

        }
}


int main (void) {
    for (int i=0;i<4;i++) {
        strcpy(map[i], "    ");
        strcpy(map1[i], "    ");
    }
    int x, y, n=15;
    head.father=NULL;
    head.brother=NULL;


    while (1) {
        printf ("your turn:");
        scanf ("%d %d", x, y);
        map[x][y]='x';
        if (check()==-1) {
            for (int i=0;i<4;i++)
                for (int j=0;j<4;j++) {
                    if (map1[i][j]==' ') {
                        map1[i][j] = 'o';
                        head.x=i;
                        head.y=j;
                        head.player=1;
                        head.win=0;
                        head.visit=0;
                        head.rate=0;
                        head.UCB=0;
                        UCT(0 ,n--);
                        map1[i][j]=' ';
                    }
                }
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