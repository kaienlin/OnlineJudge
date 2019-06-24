#ifndef __RMQ_H
#define __RMQ_H
 
#include <cstdint>
void* preprocessing(int N, int32_t A[]);
void offline_query(void *tool, int M, int32_t Q[][2], int32_t R[]);
void destroy(void *tool);
#endif
