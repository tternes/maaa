//
//  main.c
//  maaa
//
//  Created by Thaddeus Ternes on 7/1/13.
//  Copyright (c) 2013 Bluetoo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char * argv[])
{

    // insert code here...
    if(argc < 2)
    {
        fprintf(stderr, "Usage: maaa <MB>\n");
        return -1;
    }

    const unsigned long ulMB = 1024 * 1024;
    unsigned long ulAllocationMegabytes = strtoul(argv[1], NULL, 10);
    
    fprintf(stdout, "Allocating %lu MB...\n", ulAllocationMegabytes);
    
    void *buffer = malloc(ulAllocationMegabytes * 1024 * 1024);

    fprintf(stdout, "Starting write cycle, press ctrl-c to stop\n");
    for(int pass=0; ; pass++)
    {
        for(unsigned long index = 0; index < ulAllocationMegabytes; index++)
        {
            memset(buffer + (index * ulMB), pass, ulMB);
            fprintf(stdout, "\rPass %i MB block %li", pass, index);
            usleep(10000);
            fflush(stdout);
        }
        
        fprintf(stdout, " done\n");
        sleep(1);
    }
    
    return 0;
}

