#include <iostream>
#include <list>
#include <map>
#include <string.h>

using namespace std;



struct man{
    char name[20];
    int th;
    list<struct man>son;
};

struct man CEO;

map<string, struct man>ID;



void hire (char *a, char *b) {
    ID[a].son.push_back(ID[b]);
    ID[b].th=ID[a].th+1;
}

void fire (char *a) {
    struct man current;
    current=ID[a];
    while (current.son.size()!=0) {
        ID.erase(current.name);
        strcpy(current.name, current.son.front().name);
        ID[current.name]=current;
        current=current.son.front();
    }
    strcpy(current.name, current.son.front().name);
    current.son.pop_front();
}

void Print (char *a) {
    struct man current;
    current=ID[a];
    printf ("%s\n", a);
    while (current.son.size()!=0) {
        list<struct man>::iterator iter;
        for(iter = current.son.begin(); iter != current.son.end() ;iter++) {
            for (; iter->th>0; iter->th--)
                printf ("+");
            printf ("%s\n", iter->name);
        }
        current=current.son.front();
    }
    printf ("------------------------------------------------------------\n");
}

int main() {
    char  n1[20], n2[20], n3[20];
    char sentence[100];
    struct man people[100];
    int num, i = 0;


    scanf("%s", &CEO.name);
    CEO.th=0;
    ID[CEO.name]=CEO;
    while (gets(sentence) != NULL) {
        num = sscanf(sentence, "%[^ ] %[^ ] %[^ ]", n1, n2, n3);
        if (num == 3) {
            strcpy(people[i].name, n2);
            ID[people[i].name]=people[i];
            i++;
            hire (n1, n2);
        }
        else if (num==2)
            fire(n2);
        else
            Print (CEO.name);
        return 0;
    }
}
