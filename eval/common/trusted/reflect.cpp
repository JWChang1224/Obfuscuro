#include <stdio.h>
#include <string.h>
#include "reflect.h"

struct sym_table_t gbl_sym_table[1] __attribute__((weak)) = {{NULL, NULL}};

int return_symbol_index(const char * name)
{
	
    struct sym_table_t *p = &gbl_sym_table[0];
    int index = 0;
    for(; p->name; p++)
    {
        if(strcmp(p->name, name) == 0)
        {
	     return index;
        }
	index++;
    }
    return -1;
}
void * reflect_query_symbol(const char * name)
{
    struct sym_table_t *p = &gbl_sym_table[0];
    for(; p->name; p++)
    {
        if(strcmp(p->name, name) == 0)
        {
            return p->addr;
        }
    }
    return NULL;
}
