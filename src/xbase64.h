#ifndef _XBASE64_H
#define _XBASE64_H

int x_base64e(unsigned char* buf, int buf_len, unsigned char* data, int data_len);
int x_base64d(unsigned char* buf, int buf_len, unsigned char* data, int data_len);

#endif
