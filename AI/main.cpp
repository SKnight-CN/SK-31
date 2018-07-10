#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<malloc.h>
#include <limits.h>
#include<math.h>

char map[4][4], map1[4][4];
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
    Chess *son
};


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

Chess *FoundMaxUCB() {

}

void UCT( Chess *item) {
    Chess *q, *head, *temp;
    char map1[4][4];
    int start_Time, end_Time;
    int Win_flag;
    start_Time = end_Time = clock();
    head=item->son;

    for (int i=0;i<4;i++)
        strcpy(map1[i], map[i]);



    while (end_Time - start_Time<=3) {
        q=FoundMaxUCB();
        if (map[q->x][q->y]=='x')
            q->player=0;
        else
            q->player=1;
        if (check()==q->player) {
            q->rate=1.00;
            q->UCB=ULONG_MAX;
            q->win++;
            q->visit++;
            Win_flag=q->player;
            temp=q->father;
            while (q->father!=NULL) {
                q=q->father;
                q->visit++;
                if (q->father->player==Win_flag)
                    q->win++;
                q->rate=(double)q->win/q->visit;
                q->UCB=q->rate+sqrt(2*log(totalvisit)/q->visit);
            }
            temp=NULL;
            q=head;
            for (int i=0;i<4;i++)
                strcpy(map1[i], map[i]);
        }
        else if(q->visit<SIM_MAX) {
            int isWin=MCT(1-q->player);
            Win_flag = q->player;
            if (isWIN)
                q->win++;
            else
                Win_flag=1-q->player;
            q->visit++;
            q->rate = (double)q->win / q->visit;
            if (q->visit >= SIM_MIN)
                q->UCB =q->rate+sqrt(2*log(totalvisit)/q->visit);
            while (q->father!=NULL) {
                q=q->father;
                q->visit++;
                if (q->father->player==Win_flag)
                    q->win++;
                q->rate=(double)q->win/q->visit;
                q->UCB=q->rate+sqrt(2*log(totalvisit)/q->visit);
            }
            temp=NULL;
            q=head;
            for (int i=0;i<4;i++)
                strcpy(map1[i], map[i]);
        }
        else if (q->visit>=SIM_MAX) {
            if (q->son != NULL) q = q->son;//有儿子了直接往下走
            else
            {
                q->player = 3 - q->player;//给对手生成招法
                Searchmove();
                q->player = 3 - q->player;//生成完记得换回来
                //如果需要加多线程，这一块必锁
                if (q->son == NULL)//生成失败
                {
                    //即已经分出胜负，正常操作即可
                }
                else q = q->son;
            }
        }
        end_Time=clock();
    }
}


int main (void) {
    for (int i=0;i<4;i++) {
        strcpy(map[i], "    ");
        strcpy(map1[i], "    ");
    }
    int x, y;


    while (1) {
        printf ("your turn:");
        scanf ("%d %d", x, y);
        map[x][y]='x';
        if (check()==-1) {
            for (int i=0;i<4;i++)
                for (int j=0;j<4;j++) {
                    if (map1[i][j]==' ') {
                        map1[i][j] = 'o';
                        UCT();
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