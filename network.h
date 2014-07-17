/*
 * active port forwarder - software for secure forwarding
 * Copyright (C) 2003 jeremian <jeremian@poczta.fm>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 */

#ifndef _JS_NETWORK_H
#define _JS_NETWORK_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#include <netdb.h>
#include <openssl/ssl.h>

int ip_listen(const char *host, const char *serv, socklen_t *addrlenp, const char *type); /* socket, bind, listen... */
int ip_connect(const char *host, const char *serv, const char *type); /* socket, connect... */
char* sock_ntop(const struct sockaddr* sa, socklen_t salen); /* return the hostname of connected user */
int SSL_writen(SSL* fd, unsigned char* buf, int amount);
int SSL_readn(SSL* fd, unsigned char* buf, int amount); 
int writen(int fd, unsigned char* buf, int amount);
int readn(int fd, unsigned char* buf, int amount);

#endif
