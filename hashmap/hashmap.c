#include<stdio.h>
#include"hashmap.h"

hash_map_t g_hash_map;

void init()
{
    
    uint32_t i=0;
    g_hash_map._total_count=HASH_SIZE;
    g_hash_map._free_count=g_hash_map._total_count;
    g_hash_map._used_count=0;
    g_hash_map._free_index_top=HASH_SIZE;
    for( i=0; i<g_hash_map._total_count; i++)
    {
        g_hash_map._key_index[i]=INVALID_HASH_ENTRY;
        g_hash_map._free_elements[i]=i;
        g_hash_map._bucket[i]._key=INVALID_HASH_ENTRY;
        g_hash_map._bucket[i]._data=NULL;
    }
}

static uint32_t hash( uint32_t key )
{
    return key%g_hash_map._total_count;  //simple hash function
}


bool insert(uint32_t key, void *data)
{
    uint32_t hashKey;
    entry_t *tmp=NULL;

    if( g_hash_map._used_count >= g_hash_map._total_count )
    {
        printf("cant insert elements\n");
        return false;
    }

    hashKey = hash(key);
    
    if( g_hash_map._key_index[hashKey] == INVALID_HASH_ENTRY ){
        uint32_t bucket_index=g_hash_map._free_elements[--g_hash_map._free_index_top];
        g_hash_map._key_index[hashKey] = bucket_index;
        tmp=&(g_hash_map._bucket[bucket_index]);
        tmp->_key=key;
        tmp->_data=data;
        --g_hash_map._free_count;
        ++g_hash_map._used_count;
    }
    else{
        printf("Failed to insert element\n");
        return false;
    }
}

void* find_element(uint32_t key)
{
    uint32_t hashKey=hash(key);
    entry_t *tmp_entry=&g_hash_map._bucket[ g_hash_map._key_index[hashKey] ];
    if( tmp_entry->_key == key )
    {
        return tmp_entry->_data;
    }
    printf("element with key %u is not found\n",key);
    return NULL;
}

bool delete_element( uint32_t key )
{
    uint32_t hashKey=hash(key);
    if( g_hash_map._key_index[hashKey] != INVALID_HASH_ENTRY && 
            g_hash_map._bucket[ g_hash_map._key_index[hashKey] ]._key == key )
     {
         g_hash_map._free_elements[g_hash_map._free_index_top++]=g_hash_map._key_index[hashKey];
         --g_hash_map._used_count;
         ++g_hash_map._free_count;
         
         return true;
     }
    else{
        printf("Element with key %u is not found\n",key);
    }
    return false;
}

void print_statistics()
{
    printf("used_count:%u\n",g_hash_map._used_count);
    printf("free_count:%u\n",g_hash_map._free_count);
    printf("total_count:%u\n",g_hash_map._total_count);
}
