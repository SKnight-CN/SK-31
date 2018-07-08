
#include <stdio.h>
#include <queue>
using namespace std;
int dx[4]= {1, 2, 1, 2};
int dy[4]= {2, 1, -2, -1};//四种走法
int ways=0;//记录路线条数

struct NODE {
    int x, y;
};//记录路线上的点的坐标

bool Valid (NODE h, int m, int n) {
    if ((h.x<=m)&&(h.y>=1)&&(h.y)<=n)
        return 1;
    else
        return 0;
}//判断下的这步棋是否符合规则

bool bfs (NODE s, int m, int n) {
    queue<NODE>q;//建立路线队列
    NODE now, next;//用于记录当前棋和进入下一步的棋
    q.push(s);//起点入列
    while (!q.empty()) {
        now = q.front();
        q.pop();//取出当前棋子并出列
        if ((now.x==m)&&(now.y==n)) {
            ways++;
            continue;
        }//判断是否走到终点
        for ( int i=0; i<4; i++) {
            next.x=now.x+dx[i];
            next.y=now.y+dy[i];//走出四种走法
            if (Valid(next,m, n))
                q.push(next);//如果有效则入列
        }
    }
}

int main() {
    int m, n;
    scanf ("%d %d", &m, &n);
    NODE s;
    s= {1,1};//起点
    bfs (s, n, m);//开始搜索
    printf ("%d\n", ways);
    return 0;
}