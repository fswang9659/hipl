# $USAGI: Makefile.in,v 1.34 2003/06/21 04:17:42 yoshfuji Exp $
#
# Makefile.am for USAGI libinet6. Conversion from ".in" to ".am" by
# miika@iki.fi.
#
# Copyright (C) 2000-2001 USAGI/WIDE Project.
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. Neither the name of the project nor the names of its contributors
#    may be used to endorse or promote products derived from this software
#    without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.

AUTOMAKE_OPTIONS = foreign

# XX TODO: How to make autoconf link libcrypto.a to libinet6.a?

lib_LTLIBRARIES = libinet6.la

# Original sources
libinet6_la_SOURCES  = usagi.c getaddrinfo.c getnameinfo.c ip6opt.c rthdr.c
libinet6_la_SOURCES += ifaddrs.c ifnames.c cmsg_nxthdr.c rcmd.c rexec.c
libinet6_la_SOURCES += sa_len.c tempname.c util.c

# Original flags.
CFLAGS  = -D_LIBC_REENTRANT -D_USAGI -D_GNU_SOURCE
CFLAGS += -DCOMPAT_RFC2292 -Iinclude -D__ss_family=ss_family -D__ss_len=ss_len
CFLAGS += -D_USAGI_LIBINET6=$(usagi_libc) -Iinclude_glibc$(usagi_libc)
CFLAGS += $(OPTIMIZATIONS_CFLAGS)
CFLAGS += $(GPROF_CFLAGS)

# HIP additions to the flags.
INCLUDES = $(hipl_common_include_paths) -Iinclude_glibc -I$(HIPL_LIBINET6_INCLUDE) -I$(HIPL_PJPROJECT_NATH)/include -I$(HIPL_PJPROJECT_LIB)/include -I$(HIPL_PJPROJECT_LIB_UTIL)/include -I$(HIPL_PJPROJECT_MEDIA)/include 
CFLAGS += $(hipl_common_cflags)
# Enable the following option if you want to compile HIP enabled apps without
# no changes to code using the legacy HIP API (assuming that the code uses
# only getaddrinfo).
CFLAGS += -DHIP_TRANSPARENT_API

# HIP library added
LDADD  = #../libhiptool/.libs/libhiptool.a

include_HEADERS = libc-compat.h util.h 

EXTRA_DIST = include_glibc21 include_glibc22 include_glibc23 include_glibc

INCLUDES += -I../libdht
LDADD += ../libdht/.libs/libhipopendht.a 

INCLUDES += -I../i3/i3_client -I../i3/utils -I../i3/i3

#getendpointinfo.c: include/netdb.h

include/netdb.h:
	$(LN_S) -f include_glibc$(usagi_libc) include

SUBDIRS = include_glibc21 include_glibc22 include_glibc23
