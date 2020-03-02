#ifndef __HASH_MAP__
#define __HASH_MAP__

#include<stdint.h>
#include<stdbool.h>

#define HASH_SIZE  (1U<<8)  //256
#define INVALID_HASH_ENTRY   HASH_SIZE+1 


typedef struct entry  entry_t;

typedef struct entry {
    uint32_t  _key;
    entry_t *_prev, *_next;
    void*  _data;                
}entry_t;

typedef struct{
     uint32_t _key_index[HASH_SIZE];
     uint32_t _total_count;
     uint32_t _free_index_top;
     uint32_t _free_count;
     uint32_t _used_count;
     uint32_t _free_elements[HASH_SIZE];
     entry_t  _bucket[HASH_SIZE];
}hash_map_t;

extern hash_map_t g_hash_map;

void init();

bool insert(uint32_t key, void *data);

void* find_element(uint32_t key);

bool delete_element( uint32_t key );

void print_statistics();


#endif
