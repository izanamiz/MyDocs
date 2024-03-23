#include <stdio.h>
#include <dos.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>
struct BOOT // for FAT16
{
    char jmp[3];
    char OEM[8]; // MSDOS5.0
    int bytes_per_sector;
    char sectors_per_cluster;
    int reserved;
    char FAT_cnt;
    int ROOT_size;
    int total_sectors;
    char media;
    int FAT_size;
    int sectors_per_track;
    int head_cnt;
    long hidden_sectors;
    long total_sectors_long;
    char un_known[31];
    long serial;
    char volume[11];
    char FAT_type[8];
    char loader[448];
    char mark[2];
};
struct  ROOT{
    char name[8];
    char ext[3];
    char attr;
    char reserved[10];
    char time[2];
    char date[2];
    int first_cluster;
    long size;
};
