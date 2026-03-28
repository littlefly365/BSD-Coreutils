/*
 * Copyright (c) 2026 littlefly365
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of littlefly365 nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES ARE DISCLAIMED.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <err.h>
#include "nb_stdlib.h"
#include "sys/nb_cdefs.h"

__dead static void usage();

int 
main(int argc, char *argv[])
{	
	if (argc > 1)
		usage();

	long nprocs = sysconf(_SC_NPROCESSORS_ONLN);

	if (nprocs < 1){
		err(1, "nproc");
	}

	printf("%ld\n", nprocs);
	return 0;
}

static void
usage(void)
{
fprintf(stderr, "usage: %s\n", getprogname());
exit(1);
}
