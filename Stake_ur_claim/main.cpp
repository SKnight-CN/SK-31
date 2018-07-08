#include <iostream>
char map[10][10];
struct NODE {
    int x;
    int y;
    struct NODE *next;
};

int ax, ay;

struct grade {
    int x;
    int y;
    int point;
};

grade set[20];

NODE head;

int check () {
    NODE *check=head.next;
    while (check!=NULL) {
        if (map[check->x][check->y] != '.')
            check = check->next;
        else
            return 0;
    }
    return 1;
}

int get_points() {

}

int alpha_beta(NODE *current, int player, int alpha, int beta)
{
    int flag, points;
    flag=check();
    if(flag) {
        points=get_points();
        return points;
    }
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


int main() {
    int n, val;
    int alpha, beta;
    NODE  *current, *Next;

    scanf ("%d", &n);
    while ( n!=0) {
        alpha=-(n*n/2);
        beta=n*n/2;
        for (int i = 0; i < n; i++) {
            scanf("%s", map[i]);
            for (int j = 0; j < 4; j++) {
                map[i][j] = map[i][j];
                if (map[i][j] == '.') {
                    if (head.next == NULL) {
                        current = (struct NODE *) malloc(sizeof(struct NODE));
                        current->x = i;
                        current->y = j;
                        head.next = current;
                        current->next = NULL;
                    } else {
                        Next = (struct NODE *) malloc(sizeof(struct NODE));
                        Next->x = i;
                        Next->y = j;
                        current->next = Next;
                        current = Next;
                        Next->next = NULL;
                    }
                }
            }
            val=alpha_beta(head.next, 1, alpha, beta);

        }
        scanf ("%d", &n);
    }
    return 0;
}