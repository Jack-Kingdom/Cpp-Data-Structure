#include <stdio.h>

#pragma pack(push)
#pragma pack(1)     // try to test 2, 4, 8
typedef struct {
    char a;
    double b;
    int c;
} DataType;
#pragma pack(pop)

int main() {
    printf("%lu\n", sizeof(DataType));
    return 0;
}