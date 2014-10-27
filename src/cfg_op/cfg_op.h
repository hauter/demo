
#ifndef CFG_OP_H
#define CFG_OP_H
#ifdef __cplusplus

#define LINEMAXLEN 2048
#define VALUEMAXLEN 128
extern "C"
{
#endif
int GetcfgItem(char *fileName, char *keyName, char *value);
int WritecfgItem(char *fileName, char *keyName, char *value);



#ifdef __cplusplus
}
#endif

#endif // CFG_OP_H
