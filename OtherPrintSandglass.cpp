#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {
    int count;
    char sign;
    scanf("%d %c", &count, &sign);
    
    int k = (int)sqrt((double)((count+1)/2));
    int size = k * 2 - 1, line;
    for (int i = k; i > 0; i--) {
        line = i * 2 - 1;
        for (int j = 0; j < (size - line) / 2; j++) {
            printf(" ");
        }
        for (int j = 0; j < line; j++) {
            printf("%c", sign);
        }
        printf("\n");
    }
    for (int i = 2; i <= k; i++) {
        line = i * 2 - 1;
        for (int j = 0; j < (size - line) / 2; j++) {
            printf(" ");
        }
        for (int j = 0; j < line; j++) {
            printf("%c", sign);
        }
        printf("\n");
    }
    printf("%d\n", count - 2 * k * k + 1);
    return 0;
}
