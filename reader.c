#include "reader.h"

#include <stdio.h>
#include <malloc.h>
#include <string.h>

int get_one_line(FILE **fp, char *line_buf) {
    unsigned int i = 0;
    int ret;
    char *buf_t = line_buf;

    if (fp == NULL || line_buf == NULL)
        return 0;

    memset(line_buf, 0, MAX_RECORD_LEN);

    while (*buf_t != 0x0a && !feof(*fp)) {
        buf_t = line_buf + i;
        fread(buf_t, sizeof(char), 1, *fp);
        i++;
    }

    if (!feof(*fp)) {
        // end of 0x0a
        *buf_t = '\0';
        ret = 1;
    } else {
        // end of EOF
        *(buf_t + 1) = '\0';
        ret = 0;
    }
}
