#ifndef _X_CRYPTO_H
#define _X_CRYPTO_H

#include <stdio.h>
#include <sys/types.h>

#define MTX_BUFFER_SIZE 65536
#define MTX_ENCRYPT  0
#define MTX_DECRYPT  1
#define CRYPTO_KEY_BITS  256
#define CRYPTO_KEY_BYTES  (CRYPTO_KEY_BITS/8)

struct _aesParam
{
	//Holds the key expansion.
	uint32_t k[64];
	 
	//Number of rounds to be used in encryption/decryption.
	uint32_t nr;
	
	//Buffer to be used by block chaining or feedback modes.
	uint32_t fdback[4];
};

//aes function
int aes_setup(struct _aesParam* ap, const uint8_t* key, size_t keybits, int mode);
int aes_encrypt(struct _aesParam* ap, const uint32_t* src, uint32_t* dst);
int aes_decrypt(struct _aesParam* ap, const uint32_t* src, uint32_t* dst);
int aes_encrypt_string(struct _aesParam *ap, uint8_t* src, int src_len, uint8_t *dst, int dst_len);
int aes_decrypt_string(struct _aesParam *ap, uint8_t* src, int src_len, uint8_t *dst, int dst_len);

//xbase64 function
int x_base64e(unsigned char* buf, int buf_len, unsigned char* data, int data_len);
int x_base64d(unsigned char* buf, int buf_len, unsigned char* data, int data_len);

//random dictionary
uint8_t cyt_randdict_encrypt[256];
uint8_t cyt_randdict_decrypt[256]; 
#define CYT_RAND_ENCRYPT(t) cyt_randdict_encrypt[t]
#define CYT_RAND_DECRYPT(t) cyt_randdict_decrypt[t]

struct crypto
{
	//aes	
	struct _aesParam encrypt_ap;
	struct _aesParam decrypt_ap;

	//custom

};

//
bool cyt_initialize(struct crypto* p, uint8_t* key, int key_len);

//pure crypto
int  cyt_encrypt(struct crypto* p, uint8_t* src, int src_len, uint8_t* dst, int dst_len);
int  cyt_decrypt(struct crypto* p, uint8_t* src, int src_len, uint8_t* dst, int dst_len);

//
struct crypto* init();
void clean(struct crypto* hdr);
char* jstringToChar(JNIEnv* env, jstring jstr);
jstring stoJstring(JNIEnv* env, const char* pat);

#endif
