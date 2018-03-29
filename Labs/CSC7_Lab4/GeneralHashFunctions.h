/* 
 * File:   GeneralHashFunctions.h
 * Author: Josh McIntyre
 * Created on March 29, 2018, 11:39 AM
 */

#ifndef GENERALHASHFUNCTIONS_H
#define GENERALHASHFUNCTIONS_H

#include <string>
using namespace std;

typedef unsigned int (*HashFunction)(const string&);


unsigned int RSHash  (const string& str);
unsigned int JSHash  (const string& str);
unsigned int PJWHash (const string& str);
unsigned int ELFHash (const string& str);
unsigned int BKDRHash(const string& str);
unsigned int SDBMHash(const string& str);
unsigned int DJBHash (const string& str);
unsigned int DEKHash (const string& str);
unsigned int BPHash  (const string& str);
unsigned int FNVHash (const string& str);
unsigned int APHash  (const string& str);

#endif /* GENERALHASHFUNCTIONS_H */

