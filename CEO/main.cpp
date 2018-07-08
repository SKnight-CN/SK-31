#include <stdio.h>
#include <malloc.h>

char map[9][9];
char map1[9][9];

struct NODE {
    int x=-1;
    int y=-1;
    int live=0;
    struct NODE *next;
};

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int check_black (struct NODE *current) {
    NODE next[4], *current1;
    int  flag=1;
    current1=current;

    while (current1!=NULL) {
        for (int i=0; i<4;i++) {
            next[i].x=current1->x+dx[i];
            next[i].y=current1->y+dy[i];
        }
        for (int i=0; i<4; i++) {
            if ((next[i].x > 9) || (next[i].x < 0) || (next[i].y < 0) || (next[i].y > 9))
                continue;
            if ((map[next[i].x][next[i].y] == '.') ) {
                current1->live = 1;
                map1[current1->x][current1->y]='X';
                break;
            }
        }
        current1=current1->next;
    }
    current1=current;
    while (current1!=NULL) {
        if (current1->live==1) {
            current1 = current1->next;
            continue;
        }
        else {
            for (int i=0; i<4;i++) {
                next[i].x=current1->x+dx[i];
                next[i].y=current1->y+dy[i];
            }
            for (int i=0; i<4; i++) {
                if ((next[i].x > 9) || (next[i].x < 0) || (next[i].y < 0) || (next[i].y > 9))
                    continue;
                if ((map1[next[i].x][next[i].y] == 'X') ) {
                    current1->live = 1;
                    break;
                }
            }
            current1=current1->next;
        }
    }
    while (current!=NULL) {
        if (current->live == 0) {
            flag = 0;
            break;
        }
        else
            current=current->next;
    }
    return flag;
}

int check_white (struct NODE *current) {
    NODE next[4], *current1;
    int flag=1;
    current1=current;

    while (current1!=NULL) {
        for (int i=0; i<4;i++) {
            next[i].x=current1->x+dx[i];
            next[i].y=current1->y+dy[i];
        }
        for (int i=0; i<4; i++) {
            if ((next[i].x > 9) || (next[i].x < 0) || (next[i].y < 0) || (next[i].y > 9))
                continue;
            if ((map[next[i].x][next[i].y] == '.') ) {
                current1->live = 1;
                map1[current1->x][current1->y]='O';
                break;
            }
        }
        current1=current1->next;
    }
    current1=current;
    while (current1!=NULL) {
        if (current1->live==1) {
            current1 = current1->next;
            continue;
        }
        else {
            for (int i=0; i<4;i++) {
                next[i].x=current1->x+dx[i];
                next[i].y=current1->y+dy[i];
            }
            for (int i=0; i<4; i++) {
                if ((next[i].x > 9) || (next[i].x < 0) || (next[i].y < 0) || (next[i].y > 9))
                    continue;
                if ((map1[next[i].x][next[i].y] == 'O') ) {
                    current1->live = 1;
                    break;
                }
            }
            current1=current1->next;
        }
    }
    while (current!=NULL) {
        if (current->live == 0) {
            flag = 0;
            break;
        }
        else
            current=current->next;
    }
    return flag;
}

int main (void) {
    int x, y;
    int flag_black, flag_white;
    char zi;
    NODE *black, *white, *current;
    white=(struct NODE *)malloc(sizeof(struct NODE));
    black=(struct NODE *)malloc(sizeof(struct NODE));
    white->next=NULL;
    black->next=NULL;

    for (int i=0;i<9;i++)
        scanf ("%s", &map[i]);
    scanf ("%d %d %c", &x, &y, &zi);
    map[x][y]=zi;


    for (int i=0;i<9;i++)
        for (int j=0; j < 9; j++) {
            if (map[i][j] == 'X') {

                current=(struct NODE *)malloc(sizeof(struct NODE));
                current->x=i;
                current->y=j;
                current->next=black->next;
                black->next=current;

            }
            else if (map[i][j] == 'O') {

                current=(struct NODE *)malloc(sizeof(struct NODE));
                current->x=i;
                current->y=j;
                current->next=white->next;
                white->next=current;

            }
        }
    flag_black = check_black(black->next);
    flag_white = check_white(white->next);

    if (zi=='X') {
        if (flag_white==0)
            printf ("K.O.\n");
        else if (flag_black==0)
            printf ("Suicide\n");
        else
            printf ("Safe\n");
    }
    else {
        if (flag_black==0)
            printf ("K.O.\n");
        else if (flag_white==0)
            printf ("Suicide\n");
        else
            printf ("Safe\n");
    }
    return 0;
}