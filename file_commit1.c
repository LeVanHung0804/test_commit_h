// #include <stdio.h>
// #include <conio.h>
// #include <stdlib.h>
// #include "sub1.h"
// #include "sub2_folder/sub2.h"
// #include "sub2_folder/sub_sub2_folder/sub_sub2.h"
// #include "sub2_folder/sub3_folder/sub3.h"

// void main(void){
//     printf("hello, I am hung!\n");
//     print_sub1();
//     print_sub2();
//     print_sub_sub2();
//     print_sub3();
//     system("pause");
//     return;
// }

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

uint8_t id_ta[32] = {0x01, 0x02, 0x03, 0x04, 0x01, 0x02, 0x03, 0x04, 0x01, 0x02, 0x03, 0x04, 0x01, 0x02, 0x03, 0x04, 0xFE, 0xFD, 0xFC, 0xFB , 0xFE, 0xFD, 0xFC, 0xFB , 0xFE, 0xFD, 0xFC, 0xFB, 0xFE, 0xFD, 0xFC, 0xFB};
uint8_t id_tb[32] = {0x02, 0x02, 0x03, 0x04, 0x01, 0x02, 0x03, 0x04, 0x01, 0x02, 0x03, 0x04, 0x01, 0x02, 0x03, 0x04, 0xFD, 0xFD, 0xFC, 0xFB , 0xFE, 0xFD, 0xFC, 0xFB , 0xFE, 0xFD, 0xFC, 0xFB, 0xFE, 0xFD, 0xFC, 0xFB};
uint8_t id_tc[32] = {0x03, 0x02, 0x03, 0x04, 0x01, 0x02, 0x03, 0x04, 0x01, 0x02, 0x03, 0x04, 0x01, 0x02, 0x03, 0x04, 0xFC, 0xFD, 0xFC, 0xFB , 0xFE, 0xFD, 0xFC, 0xFB , 0xFE, 0xFD, 0xFC, 0xFB, 0xFE, 0xFD, 0xFC, 0xFB};
uint8_t id_td[32] = {0x04, 0x02, 0x03, 0x04, 0x01, 0x02, 0x03, 0x04, 0x01, 0x02, 0x03, 0x04, 0x01, 0x02, 0x03, 0x04, 0xFB, 0xFD, 0xFC, 0xFB , 0xFE, 0xFD, 0xFC, 0xFB , 0xFE, 0xFD, 0xFC, 0xFB, 0xFE, 0xFD, 0xFC, 0xFB};

uint8_t id1[256] = {0}; 
uint8_t id2[256] = {0};
uint8_t id3[256] = {0};
uint8_t id4[256] = {0};
int main(void)
{
    memcpy((uint8_t *)id1, id_ta, 32); 
    memcpy((uint8_t *)id1 + 32, id_ta, 32);
    memcpy((uint8_t *)id1 + 32*2, id_ta, 32);
    memcpy((uint8_t *)id1 + 32*3, id_ta, 32);
    memcpy((uint8_t *)id1 + 32*4, id_ta, 32);

    memcpy((uint8_t *)id2, id_tb, 32); 
    memcpy((uint8_t *)id2 + 32, id_tb, 32);
    memcpy((uint8_t *)id2 + 32*2, id_tb, 32);
    memcpy((uint8_t *)id2 + 32*3, id_tb, 32);
    memcpy((uint8_t *)id2 + 32*4, id_tb, 32);

    memcpy((uint8_t *)id3, id_tc, 32); 
    memcpy((uint8_t *)id3 + 32, id_tc, 32);
    memcpy((uint8_t *)id3 + 32*2, id_tc, 32);
    memcpy((uint8_t *)id3 + 32*3, id_tc, 32);
    memcpy((uint8_t *)id3 + 32*4, id_tc, 32);

    memcpy((uint8_t *)id4, id_td, 32); 
    memcpy((uint8_t *)id4 + 32, id_td, 32);
    memcpy((uint8_t *)id4 + 32*2, id_td, 32);
    memcpy((uint8_t *)id4 + 32*3, id_td, 32);
    memcpy((uint8_t *)id4 + 32*4, id_td, 32);
    
    printf("Find get unique id\n: ");
    
    //get unique ID of each id
    uint64_t c_id;
    uint64_t t_id;
    uint8_t ok_id[16];
    uint64_t a,b,c,n;
    uint8_t visited[8U] = {0};
    int count = 0;

    uint64_t  *test = (uint64_t *)id1;
    uint64_t  *test2 = (uint64_t *)(id1 + 16U);
    a = *test;

    for (int i = 0U; i < 8U; i++)
    {
        if (visited[i] == 1U)
        {
            continue;
        }
        if ((*(uint64_t *)(id1 + 32*i) ^ *(uint64_t *)(id1 + 32*i + 16)) != 0xFFFFFFFFFFFFFFFF || (*(uint64_t *)(id1 + 32*i + 8U) ^ *(uint64_t *)(id1 + 32*i + 24U)) != 0xFFFFFFFFFFFFFFFF)
        {
            visited[i] = 1U;
            continue;
        }
        count = 1;
        for (int j = i+1; j < 8U; j++)
        {
            if ((*(uint64_t *)(id1 + 32*j) ^ *(uint64_t *)(id1 + 32*j + 16)) != 0xFFFFFFFFFFFFFFFF || (*(uint64_t *)(id1 + 32*j + 8U) ^ *(uint64_t *)(id1 + 32*j + 24U)) != 0xFFFFFFFFFFFFFFFF)
            {
                visited[j] = 1U;
                continue;
            }
            if ((uint8_t)memcmp(id1 + 32*i, id1 + 32*j, 16U))
            {
                continue;
            }
            count++;
        }
        if (count > 4U)
        {
            memcpy(ok_id, id1+32*i, 16U);
            break;       
        }
        else if (i > 3U)
        {
            return 1;
        }
    }
    return 0;
}
