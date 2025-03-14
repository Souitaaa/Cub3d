

# Introduction
`This is all note wich I collect during my reseach for libf project, and you should do the same :).`
## definition 
A file descriptor is a low-level integer representing a open file in a program, it's a way for a program to identify and access a file or input/output resource.
# File Descriptor table
**`File Descriptor table`** A file descriptor table is the collection of integer array indices that are file descriptors in which elements are pointers to file table entries. One unique file descriptor  table is provided in the operating system for each process. 
# File Table Entry
**`File Table Entry`** file table entries a are a structure In-memory surrogate for an open file, which is created when processing a request to open the file and these entries maintain file position.
# 0, 1, 2 stdin stdout stderr
std* is a files (link file).
**any thing we write it in terminal it's write first in stdout**

# Definition (what) 
Linked list is a abstract data type, that provide to you to store a different data, in a different place in memory not like array, who store data in a consecutive block in memory. :luc_link:
# Goal (Why)
## what deference between array and linked list 
In array, elements are stored in consecutive memory locations , but in  linked list nodes are scattered here and there in the memory but they are still connected with each other.
## why linked list are better than array
- **Optimization of memory :** the array need a consecutive memory but linked list can store in any place in memory.
- **NON_pre_size :** this linked list don't need any initialization or have a pre_size. 
- **Linked lists allow more flexibility :** with linked list can grow shrink. 
# HOw 
## we need a struct 
```c
struct node 
{
	void *ff;
	struct node   *linker;
}    m_node;
```

### Self  referential structure 
```c
struct node *linker;
```
_self referential structure_ : is structure which contains a pointer to a structure of the same type.
## ++
```c
head->linker->linker. .....
```

# strchr
like strstr but here it's search this first character  c in string and it return a string starting   with the character c .
# strrchr 
the same of strchr but it search a last character. 
# strncmp 
it  compare two string and it will return a  int (positive or negative).
# memchr
this function that work like strchr but i the memory  level.
# memcmp
	this function like strcmp but in a memory level 
## description 
it compare  between two memory areas.
## Return value 
this function return a integer.
# strdup  
#strdup
## Description
strdup is a function to duplicate a string in a array,
## Prototype 
```c
char *strdup(const char *s);
```
## Return value 
it return a pointer copy of s.

# Malloc
## Description 
malloc is used to dynamically allocate a single large block of contiguous memory according to the size specified.
Malloc allocate in **heap**. 
## Prototype 
```c
void  *malloc(size_t size);
```
## return value
it's return a void pointer [[Data types in C]].
## How to allocate in a two dimensional array
### 1) Using a single pointer and 1D arry with pointer
```c
char **ptr = (int **)malloc(size);
ptr[i] = (int *)malloc(c);
```
### 2) Using an array of pointers
```c

```
## Why we need malloc 
- **Dynamic Memory Allocation**:  malloc allows you to allocate a memory at runtime, this is necessary when you need to allocate in memory and you don't know the size  can change during program execution.
- **Preventing Wastage of Memory**: with static allocation, you might have to allocate a fixed amount of memory but you aren't sure that you are going  to use it.
- **Memory Reusability**:  when you use Dynamic Memory Allocation you can deallocate this space in memory.
- **Flexibility and Adaptability**: ............... 
# Calloc
## Description 
allocate in memory with zeros to use it later.
Calloc initialize the memory to zero. 
## Prototype 
```c
void   *calloc(size_t nitems, sizre_t size);
```
## Parameters 
- nitems : This is number of elements to be allocated ;
- size : This is the size of elements;
## Return value 
This function returns a pointer to the allocated memory, or NULL if the request fails;
# Realloc 
## Description 
realloc reallocate or extend an array already allocated.
realloc from address memory to the same memory but with new size. 
## Prototype 
```c
void *relloc(void *ptr,size_t size);
```

# Pointers
Pointers is a variable included address of something 
- pointer can point to data.
- pointer can point to function.
## the address of a function 
the function are like variable store in memory but with instructions.  
## Use cases 
# Syntax 
```c
int (*p)(int,int);
p = &functionn_ame;
```

# Note 
## Note 1 : difference between **(\*p)[ ]** and **\*p[ ]**
int (\*p)[size] => that mean is a pointer of an array.  
int \*p[size] => that mean is an array of pointers.
# Advice
