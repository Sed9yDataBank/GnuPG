/* md5.h - message digest 5
 *	Copyright (c) 1997 by Werner Koch (dd9jn)
 *
 * This file is part of G10.
 *
 * G10 is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * G10 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */
#ifndef G10_MD5_H
#define G10_MD5_H

#include "types.h"

typedef struct {
    u32 i[2];		  /* number of _bits_ handled mod 2^64 */
    u32 buf[4]; 	  /* scratch buffer */
    int count;
    byte in[64];	  /* input buffer */
    byte digest[16+8+1];  /* actual digest after Final call */
} MD5_CONTEXT;


void md5_init( MD5_CONTEXT *c );
void md5_write( MD5_CONTEXT *hd, byte *inbuf, size_t inlen);
void md5_final( MD5_CONTEXT *hd);
#define md5_read(h) ( (h)->digest )

#endif /*G10_MD5_H*/
