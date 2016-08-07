


//NAME:           RAHUL KRISHNA DENDUKURI
//ZID:              Z1749863
//Assignment 5
//Due Date :04/28/2015
//CSCI 631 section -1


#ifndef in_out_H
#define in_out_H

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<strings.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<time.h>

ssize_t writen(int fd, const void *vptr, size_t n);
ssize_t readline(int fd, void *vptr, size_t maxlen);
void get_args(char* buf,char* cmd,char*arg1,char* arg2);
void  get_parent(char* cdir);
char* check_home(char* t);

#endif
