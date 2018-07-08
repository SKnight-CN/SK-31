#include <iostream>

char map[4][4];
int ax, ay;
struct AX {
    int x;
    int y;
    struct AX *next;
};

AX head;

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


int alpha_beta(AX *current, int player, int alpha, int beta)
{
    int flag;
    flag=check();
    if(flag)
        return flag;
    if(player){
        while (current!=NULL) {
                if(map[current->x][current->y] == '.'){
                    int val;
                    map[current->x][current->y] = 'x';
                    val = alpha_beta(head.next, player^1, alpha, beta);
                    map[current->x][current->y] = '.';
                    if(val > alpha){
                        alpha = val;
                        ax = current->x;
                        ay = current->y;
                    }
                    if(alpha >= beta)
                        return alpha;
                }
            current=current->next;
        }
        return alpha;
    }
    else{
        while (current!=NULL) {
            if(map[current->x][current->y] == '.'){
                int val;
                map[current->x][current->y] = 'o';
                val = alpha_beta(head.next, player^1, alpha, beta);
                map[current->x][current->y] = '.';
                if(val < beta)
                    beta = val;
                if(alpha >= beta)
                    return beta;

            }
            current=current->next;
        }

        return beta;
    }
}




int main(void) {
    char judge[2];
    AX  *current, *Next;

    head.next=NULL;
    int val, count=0;



    while (scanf("%s", judge), judge[0] != '$') {
        int alpha=-2, beta=2;
        scanf ("%c", &judge);

        for (int i=0;i<4;i++) {
            scanf("%s", map[i]);
            for (int j=0;j<4;j++) {
                map[i][j]=map[i][j];
                if (map[i][j]=='.') {
                    count++;
                    if (head.next==NULL) {
                        current=(struct AX *)malloc(sizeof(struct AX));
                        current->x=i;
                        current->y=j;
                        head.next=current;
                        current->next=NULL;
                    }
                    else {
                        Next = (struct AX *) malloc(sizeof(struct AX));
                        Next->x = i;
                        Next->y = j;
                        current->next = Next;
                        current = Next;
                        Next->next = NULL;
                    }
                }
            }
        }
        if(count <= 4) {
            printf("#####\n");
            continue;
        }
            val = alpha_beta(head.next, 1, alpha, beta);
        if(val > 0)
            printf("(%d,%d)\n", ax, ay);
        else
            printf("#####\n");

}

    return 0;
}
