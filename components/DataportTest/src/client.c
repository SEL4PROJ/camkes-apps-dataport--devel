/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */

#include <stdio.h>
#include <string.h>
#include <sel4/sel4.h>

#include <DataportTest.h>

int run(void) {
    char *shello = "hello world";

    printf("Starting...\n");
    printf("-----------\n");

    strcpy((void*)DataOut, shello);
    while(!*((char*)DataIn))
        seL4_Yield();
    printf("%s read %s\n", get_instance_name(), (char*)DataIn);
    return 0;
}
