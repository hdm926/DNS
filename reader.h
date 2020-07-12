#ifndef DNS_READER_H
#define DNS_READER_H

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX_RECORD_LEN	256
//按行读取txt
extern int get_one_line(FILE **fp, char *line_buf);

#endif
