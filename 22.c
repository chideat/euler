#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 81920

typedef struct n {
    char *name;
    struct n *next;
}Name;

void str_cmp(Name *head, Name *last) {
    Name *point = head;
    while(point != NULL) {
        if(strcmp(point->name, last->name) < 0) {
            if(point->next == NULL) {
                last->next = point->next;
                point->next = last;
                break;
            }
            else {
                if(strcmp(point->next->name, last->name) < 0) {
                    point = point->next;
                }
                else {
                    last->next = point->next;
                    point->next = last;
                    break;
                }
            }
        }
        else if(strcmp(point->name, last->name) == 0) {
            last->next = point->next;
            point->next = last;
            break;
        }
    }
}

int main() {
    int i = 0;
    char buffer[BUF_SIZE];
    FILE *file = fopen("22.txt","r");
    if(file == NULL) {
        printf("error\n");
        exit(1);
    }
    char *delim = ",";
    char *next;
    Name *last;


    fread(buffer, sizeof(char), BUF_SIZE, file);
    fclose(file);

    Name *head = malloc(sizeof(*head));
    next = strtok(buffer,delim);
    head[i].name = next;
    head[i ++].next = NULL;
    while(next = strtok(NULL, delim)) {
        if(strcmp(head[0].name,next) > 0)
            continue;
        head[i ++].name = next;
        str_cmp(head, &head[i-1]);
    }
    unsigned j, k;
    unsigned long tmp;
    unsigned long sum = 0;
    last = head->next;
    k = 0;
    while(last){
        tmp = 0;
        for(j = 1;j < strlen(last->name) - 1;j ++){
            tmp += last->name[j] - 64;
        }
        tmp = tmp * (++k);
        sum += tmp;
        last = last->next;
    }
    printf("%lu\n",sum);
    return 0;
}
