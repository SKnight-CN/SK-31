#include <iostream>
#include <list>
#include<string.h>
#include<time.h>
#include<math.h>
using namespace std;
int X,Y;
#define MIN_SIZE 100
#define MAX_SIZE 200

char qi_pan[4][4] , map[4][4];

struct step {
    int x;
    int y;
    double UCB;
    int visit;
    int win;
};
step set[14], *cur_set;

struct Chess {
    int x;
    int y;
    Chess *next;
    Chess *father;
    int th;
};



int check_1() {
    int i, j;
    int xa = 0, xb = 0;
    int ya = 0, yb = 0;
    for(i = 0; i < 4; i++){
        int ra = 0, rb = 0;
        int ca = 0, cb = 0;
        if(qi_pan[i][i] == 'x')
            xa += 1;
        else if(qi_pan[i][i] == 'o')
            xb += 1;
        if(qi_pan[i][3-i] == 'x')
            ya += 1;
        else if(qi_pan[i][3-i] == 'o')
            yb += 1;
        for(j = 0; j < 4; j++){
            if(qi_pan[i][j] == 'x')
                ra += 1;
            else if(qi_pan[i][j] == 'o')
                rb += 1;
            if(qi_pan[j][i] == 'x')
                ca += 1;
            else if(qi_pan[j][i] == 'o')
                cb += 1;
        }
        if(ra == 4 || ca == 4 || xa == 4 || ya == 4)
            return 1;
        else if(rb == 4 || cb == 4 || xb == 4 || yb == 4)
            return 0;
    }
    return -1;
}

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



int MCT(int sum, int player) {
    Chess *head, *cur, *temp;
    int th=0, random_chess;
    temp=(Chess *)malloc(sizeof(Chess));
    head=temp;
    temp->father=NULL;

    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            if (map[i][j]==' ') {
                cur=(Chess *)malloc(sizeof(Chess));
                cur->th=th++;
                cur->next=NULL;
                cur->x=i;
                cur->y=j;
                temp->next=cur;
                cur->father=temp;
                temp=cur;
            }
    head=head->next;
    while (head!=NULL) {
        srand(time(NULL));
        random_chess = rand() % sum;

        if (head->next==NULL) {
            cur=head;
            head=NULL;
            goto b;
        }
        if (head->th==random_chess) {
            head = head->next;
            head->next->father=NULL;
            cur=head;
            while (cur!=NULL) {
                cur->th-=1;
                cur=cur->next;
            }
            cur=head;
            goto b;
        }
        cur=head;
        while (cur!=NULL) {
            if (cur->th==random_chess) {
                if (cur->next!=NULL)
                    cur->next->father=cur->father;
                cur->father->next=cur->next;
                temp=cur->next;
                while (temp!=NULL) {
                    temp->th-=1;
                    temp=temp->next;
                }
                break;
            }
            else
                cur=cur->next;
        }
        if (cur==NULL)
            return check();

        b:if (player&1) {
            map[cur->x][cur->y]='x';
            free(cur);
        }
        else {
            map[cur->x][cur->y]='o';
            free(cur);
        }
        if (check()!=-1)
            return check();
        player=1-player;
        sum--;
    }
    return check();
}


void cal1(step *set1, int sum) {


    while (set1->visit<MIN_SIZE) {
        if (MCT(sum, 1)==0) {
            set1->visit++;
            set1->win++;
        }
        else {
            set1->visit++;
        }
        for (int i = 0; i < 4; i++)
            for(int j=0;j<4;j++)
                map[i][j]= qi_pan[i][j];
        map[set1->x][set1->y]='o';
    }


}

void MCT_once(step *,int sum) {

}

step *Foundmax(int sum) {
    step *wow;
    wow=(step*)malloc(sizeof(step));
    wow->UCB=0;
    for (int i=0;i<=sum;i++)
        if (wow->UCB<set[i].UCB)
            wow=&set[i];
    return wow;
}

int main() {
    clock_t start,finish;
    int totalvisit;

    int sum=14;
    int x, y;
    double TheTimes;


    int s=0;
    for (int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            qi_pan[i][j]=' ';
            map[i][j]=' ';
    }

    while (check_1()==-1) {
        printf("your turn:");
        scanf("%d %d", &x, &y);
        start=clock();
        qi_pan[x][y] = 'x';
        map[x][y] = 'x';
        for (int i = 0; i < sum; i++) {
            set[i].visit = 0;
            set[i].win = 0;
        }
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                if (map[i][j] == ' ') {
                    map[i][j] = 'o';
                    set[i].x=i;
                    set[i].y=j;
                    cal1(&set[s++], sum);
                    for (int i = 0; i < 4; i++)
                        for(int j=0;j<4;j++)
                            map[i][j] = qi_pan[i][j];
                }
            }

        s = 0;
        sum--;




        while (1) {
            a:finish=clock();
            TheTimes=(double)((finish-start)/CLOCKS_PER_SEC);
            if (TheTimes>=5)
                break;
            for (int i=0;i<=sum;i++) {
                totalvisit += set[i].visit;
                set[i].UCB=set[i].win/set[i].visit+sqrt(2*log(totalvisit)/set[i].visit);
            }
            cur_set=Foundmax(sum);
            MCT_once(cur_set, sum);
            goto a;
        }
        cur_set=Foundmax(sum);
        qi_pan[cur_set->x][cur_set->y]='o';
        printf ("SK chose (%d,%d)", cur_set->x, cur_set->y);
        for(int i;i<4;i++)
            printf ("%s\n", qi_pan[i]);
    }

    return 0;
}