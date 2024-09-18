#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{ //int:int
    char*  key;
    int value;
} item;

typedef struct{
    item* head;
} Hashmap;

typedef struct{
    void* key;
    void* value;
} generic_item;

item* linear_search(item* items, size_t size, const char* key){
    /*
    items: our map (we get the address of the first key:value pair)
    size: total number of key:value pairs (need to know when to stop iterating)
    key: string we want to find (the address of the first character in the string)
    */
   for(size_t i=0; i < size; i++){
    if(strcmp(items[i].key,key) == 0) return &items[i];
   }
   return NULL;
}

int main(int argc, char** argv){
    item items[] = {
        {"foo", 10}, {"bar", 42}, {"bazz", 36}, {"buzz", 7},
        {"bob", 11}, {"jane", 100}, {"x", 200}};
    size_t size_items = sizeof(items)/sizeof(item);
    size_t size_item = sizeof(item);

    printf("%ld\n",size_items);
    printf("%ld\n",size_item);
    
    item* comparison_ptr = linear_search(items,size_items,"foo");
    if(!comparison_ptr) printf("Not found.\n");
    else printf("String found with value of %d\n",(*comparison_ptr).value);

    char name1[] = "Julio";
    char* name2 = "julio";
    int name_comparison = strcmp(name1,name2);
    printf("%d\n",name_comparison);

    return 0;
}

