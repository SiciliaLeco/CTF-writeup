#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));
    int i;
    for(i=0;i<7;i++){
        printf("%d ", rand()%100+1);
    }
    return 0;
}
