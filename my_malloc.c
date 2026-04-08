#include <unistd.h> // system call library for Unix
#include <stdio.h>
#include <string.h>

// heap start variable to keep track of heap memory
void *heap_start = NULL;


// custom malloc function
void* own_malloc(size_t length)
{
    // returns a pointer to previous program break with a buffer
    // length allocated of size length
    // allocated address is pointer to the start of new memory allocated
    // if heap_start is null them it starts at allocated address
    void* allocated_address = sbrk(length);
    if(heap_start == NULL)
    {
       heap_start = allocated_address;
    }
    return allocated_address;
}

// custom free function
int own_free_all()
{
   // no memory in heap, so can't free memory, error
   if(heap_start == NULL)
   {
       return -1;
   }
   return brk(heap_start); // set program break back to start address of heap_start
   

}


int main()
{
    /*
    // store initial end of program space
    // include \0 - null character for proper termination of the string
    // strlen does not count null terminating character
    const char* message = "This is my heap message";
    const size_t message_bytes = strlen(message)*sizeof(char);
    char *memory = (char*) sbrk(message_bytes);
    // sbrk sets location of program break
    // to value of increment parameter passed into function
    // sbrk returns a pointer to previous program break to write
    // x number of bytes from
    // this is in stack, will not work memory = "0123456789";
    // need to allocate a string on heap
    // use strcpy
    // strcpy - copies string pointed to by src (2nd arg) and copies
    // into a string at the buffer pointed to by destination (1st arg)
    strcpy(memory, message);
    const char* second_message = "Second!\0";
    const size_t second_length = strlen(second_message)*sizeof(char);
    char *second_memory = (char*) sbrk(second_length);
    strcpy(second_memory, second_message);
    brk(memory);  // this will return the program break to the original break when allocating new memory
    // memory of 2 messages will become invalidated and thus can be overwritten
    const char* overwriting_message = "Overwritten!\0";
    const size_t overwriting_length = strlen(overwriting_message)*sizeof(char);
    char* newly_allocated_memory = sbrk(overwriting_length);
    strcpy(newly_allocated_memory, overwriting_message);
    */
     
    // Test malloc and free_all
    const char* message = "This is my own malloc!";
    size_t size = strlen(message)*sizeof(char);
    char* allocated_memory = own_malloc(size); // gives address
    strcpy(allocated_memory, message);
    own_free_all();
}
