#include<stdio.h>
#include<string.h>
#include<stdint.h>

#define MAX_SIZE 100000

typedef struct studentArray_t
{
    uint32_t roll_no;
    char name[26];
} studentArray;

studentArray data[MAX_SIZE];

// take input
// store input data:
// - iterate over the input values
// - calculate the hash for the input data and generate the index
// - if index position is available then store the data at the same index
// - if index position is not available then re-hash it untill finding the available index
//
// action on query:
// - iterate over the queries
// - calculate the 

uint32_t hash(uint32_t roll_no)
{
    return (roll_no % MAX_SIZE);
}

uint32_t rehash(uint32_t index, uint32_t retry)
{
    return ((index + retry*retry) % MAX_SIZE);
}

int main()
{
    uint32_t n = 0, i = 0;
    uint32_t roll_no = 0;
    uint32_t query_no = 0;
    uint32_t index = 0;
    uint32_t try_count = 1;
    char str[26] = {0};
    scanf("%d\n", &n);

    memset(&data, 0x0, sizeof(studentArray));
    for (i = 0; i<n; i++)
    {
        scanf("%d",&roll_no);
        scanf("%s", str);

        index = hash(roll_no);
        while(data[index].roll_no != 0)
        {
            index = rehash(index, try_count++);
        }

        try_count = 1;
        data[index].roll_no = roll_no;
        memcpy(data[index].name, str, strlen(str)+1);
    }

    scanf("%d", &query_no);
    for(i = 0; i<query_no; i++)
    {
        scanf("%d", &roll_no);
        index = hash(roll_no);
        while(data[index].roll_no != roll_no)
        {
            index = rehash(index, try_count++);
        }

        try_count = 1;
        printf("%s\n", data[index].name);
    }
    return 0;
}
