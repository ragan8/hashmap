#include<stdio.h>
#include<stdint.h>

#include"hashmap.h"



int main()
{
    uint32_t data=10;
    init();

    uint32_t i=0;

    print_statistics();

    for( i=1; i<HASH_SIZE; i++ ){
        insert(i,(void*)&data);
    }
    print_statistics();

    for( i=1; i<HASH_SIZE; i++ ){
        delete_element( i );
    }
    print_statistics();
#if 0
    insert(129,(void*)&data);
    
    insert(120,(void*)&data);
    insert(43,(void*)&data);
    insert(56,(void*)&data);
    insert(231,(void*)&data);
    insert(150,(void*)&data);
    insert(160,(void*)&data);
    insert(149,(void*)&data);
    insert(89,(void*)&data);
    insert(100,(void*)&data);

    print_statistics();

    printf("%d\n",*((uint32_t*)find_element( 120 )));
    printf("%d\n",*((uint32_t*)find_element( 160 )));
    printf("%d\n",*((uint32_t*)find_element( 231 )));

    delete_element( 120 );
    delete_element( 160 );

    print_statistics();

    find_element( 120 );
    find_element( 160 );
    find_element( 231 );
#endif

    return 0;
}

