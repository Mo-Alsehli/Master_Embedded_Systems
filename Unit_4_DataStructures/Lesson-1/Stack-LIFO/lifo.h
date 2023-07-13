/*
lifo.c
Mohamed Magdi
13 JUL 2023
*/

#ifndef _LIFO_H_
#define _LIFO_H_

typedef struct
{
    unsigned int *head;
    unsigned int *base;
    unsigned int length;
    unsigned int count;
} LIFO_BUF_t;

typedef enum
{
    LIFO_NO_ERROR,
    LIFO_FULL,
    LIFO_EMPTY,
    LIFO_NULL
} LIFO_STATUS_t;

LIFO_STATUS_t Lifo_Push_Item(LIFO_BUF_t *lifo_buf, unsigned int item);
LIFO_STATUS_t Lifo_Pop_Item(LIFO_BUF_t *lifo_buf, unsigned int *item);
LIFO_STATUS_t Lifo_Init(LIFO_BUF_t *lifo_buf, unsigned int *buf, unsigned int length);
unsigned int Lifo_Top_Item(LIFO_BUF_t *lifo_buf);
void Lifo_IsEmpty(LIFO_BUF_t *lifo_buf);

#endif