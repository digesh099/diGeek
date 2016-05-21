#include<stdio.h>
#include<stdint.h>

#define MAX_VAL 5

int seq_sort(uint16_t *value)
{
    uint64_t temp = 0;
    uint8_t i,j = 0;

    (unsigned int*)value;
    for(i = 0; i<MAX_VAL; i++)
    {
        for(j = i+1; j<=MAX_VAL; j++)
        {
            // compare zeroth value to all values and swap is small value identified. Then same with first value and likewise
            if(value[j] < value[i])
            {
                temp = value[j];
                value[j] = value[i];
                value[i] = temp;
            }
        }
    }

    return 0;
}

int main()
{
    uint16_t value[MAX_VAL];
    uint8_t i = 0;
    for(i = 0; i <= MAX_VAL; i++)
    {
        printf("Enter the value %d to the list to be sorted : ", i);
        scanf("%hu", &value[i]);
    }

    printf("un-sorted array value is:\n");
    for(i = 0; i <= MAX_VAL; i++)
        printf("%u ", value[i]);

    // TODO: How to make this API generic. It should work with any data type content of the pointer
    seq_sort(value);

    printf("\nsequencial sorted array value is:\n");
    for(i = 0; i <= MAX_VAL; i++)
        printf("%u ", value[i]);
    printf("\n");
    
    return 0;
}
