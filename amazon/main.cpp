
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
//have a try
//have another try
struct node1
{
    int Write_MinStep;
    int Blake_MinStep;
};
node1 StrMap2_Q[11][11], StrMap2_K[11][11];

char StrMap1[11][11];

struct node2
{
    int x, y;
    int step;
};

int vis1[11][11], vis2[11][11];
int trend[8][2] = { {1,1},{-1,-1},{1,0},{-1,0},{0,1},{0,-1},{1,-1},{-1,1} };

void K_BFS_W(node2 old)
{
    node2 st,next;
    queue<node2>W;
    W.push(old);
    while (!W.empty())
    {
        st = W.front();
        W.pop();
        for (int k = 0; k < 8; k++)
        {
            next.x = st.x + trend[k][0];
            next.y = st.y + trend[k][1];
            next.step = st.step + 1;
            if (StrMap1[next.x][next.y] == '.'&&vis2[next.x][next.y] == 0 && next.x >= 0 && next.x < 10 && next.y >= 0 && next.y < 10)
            {
                StrMap2_K[next.x][next.y].Write_MinStep =  min(StrMap2_K[next.x][next.y].Write_MinStep,next.step);
                vis2[next.x][next.y] = 1;
                W.push(next);
            }
        }
    }
}
void K_BFS_B(node2 old)
{
    node2 st, next;
    queue<node2>B;
    B.push(old);
    while (!B.empty())
    {
        st = B.front();
        B.pop();
        for (int k = 0; k < 8; k++)
        {
            next.x = st.x + trend[k][0];
            next.y = st.y + trend[k][1];
            next.step = st.step + 1;
            if (StrMap1[next.x][next.y] == '.'&&vis2[next.x][next.y] == 0 && next.x >= 0 && next.x < 10 && next.y >= 0 && next.y < 10)
            {
                StrMap2_K[next.x][next.y].Blake_MinStep = min(StrMap2_K[next.x][next.y].Blake_MinStep, next.step);
                vis2[next.x][next.y] = 1;
                B.push(next);
            }
        }
    }
}

void Q_BFS_B(node2 old)
{
    node2 st, next;
    queue<node2>B;
    B.push(old);
    while (!B.empty())
    {
        st = B.front();
        B.pop();
        for (int k = 0; k < 8; k++)
        {
            next.x = st.x; next.y = st.y;
            next.step = st.step + 1;
            while (1)
            {
                next.x += trend[k][0];
                next.y += trend[k][1];
                if (vis1[next.x][next.y] == 1)
                {
                    continue;
                }
                if (StrMap1[next.x][next.y] == '.' && next.x >= 0 && next.x < 10 && next.y >= 0 && next.y < 10)
                {
                    StrMap2_Q[next.x][next.y].Blake_MinStep = min(StrMap2_Q[next.x][next.y].Blake_MinStep, next.step);
                    vis1[next.x][next.y] = 1;
                    B.push(next);
                }
                else
                    break;
            }
        }
    }
}
void Q_BFS_W(node2 old)
{
    node2 st, next;
    queue<node2>W;
    W.push(old);
    while (!W.empty())
    {
        st = W.front();
        W.pop();
        for (int k = 0; k < 8; k++)
        {
            next.x = st.x; next.y = st.y;
            next.step = st.step + 1;
            while (1)
            {
                next.x += trend[k][0];
                next.y += trend[k][1];
                if (vis1[next.x][next.y] == 1)
                {
                    continue;
                }
                if (StrMap1[next.x][next.y] == '.' && next.x >= 0 && next.x < 10 && next.y >= 0 && next.y < 10)
                {
                    StrMap2_Q[next.x][next.y].Write_MinStep = min(StrMap2_Q[next.x][next.y].Write_MinStep, next.step);
                    vis1[next.x][next.y] = 1;
                    W.push(next);
                }
                else
                    break;
            }
        }
    }
}
int QueenMove()
{
    int Q_Write=0, Q_Blake=0;
    node2 st;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (StrMap1[i][j] == 'R')
            {
                memset(vis1, 0, sizeof(vis1));
                st.x = i; st.y = j; st.step = 0;
                vis1[i][j] = 1;
                Q_BFS_B(st);
            }
            if (StrMap1[i][j] == 'W')
            {
                memset(vis1, 0, sizeof(vis1));
                st.x = i; st.y = j; st.step = 0;
                vis1[i][j] = 1;
                Q_BFS_W(st);
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (StrMap1[i][j] == '.')
            {
                if (StrMap2_Q[i][j].Write_MinStep > StrMap2_Q[i][j].Blake_MinStep)
                    Q_Blake++;
                if (StrMap2_Q[i][j].Write_MinStep < StrMap2_Q[i][j].Blake_MinStep)
                    Q_Write++;
            }
        }
    }
    return Q_Write - Q_Blake;
}

int KingMove()
{
    int K_Write = 0, K_Blake = 0;
    node2 st;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (StrMap1[i][j] == 'R')
            {
                memset(vis2, 0, sizeof(vis2));
                st.x = i; st.y = j; st.step = 0;
                vis2[i][j] = 1;
                K_BFS_B(st);
            }
            if (StrMap1[i][j] == 'W')
            {
                memset(vis2, 0, sizeof(vis2));
                st.x = i; st.y = j; st.step = 0;
                vis2[i][j] = 1;
                K_BFS_W(st);
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (StrMap1[i][j] == '.')
            {
                if (StrMap2_K[i][j].Write_MinStep > StrMap2_K[i][j].Blake_MinStep)
                    K_Blake++;
                if (StrMap2_K[i][j].Write_MinStep < StrMap2_K[i][j].Blake_MinStep)
                    K_Write++;
            }
        }
    }
    return  K_Write - K_Blake;
}

int main()
{
    int count = 1;
    while (~scanf("%s", StrMap1[0]))
    {
        for (int i = 1; i < 10; i++)
            scanf("%s", StrMap1[i]);
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                StrMap2_Q[i][j].Write_MinStep = 105;
                StrMap2_Q[i][j].Blake_MinStep = 105;
                StrMap2_K[i][j].Write_MinStep = 105;
                StrMap2_K[i][j].Blake_MinStep = 105;
            }
        }
        printf("case %d: queen win:%d king win:%d\n", count++, QueenMove(), KingMove());
    }
    return 0;
}