/*
 * active port forwarder - software for secure forwarding
 * Copyright (C) 2003,2004,2005 jeremian <jeremian [at] poczta.fm>
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

#ifndef _JS_ACTIVEFOR_H
#define _JS_ACTIVEFOR_H

#include "network.h"
#include "buflist.h"
#include "audit.h"

#define AF_S_CONCLOSED	  1
#define	AF_S_CONOPEN	    2
#define AF_S_MESSAGE	    3
#define AF_S_CLOSING	    4
#define AF_S_LOGIN	      8
#define AF_S_DONT_SEND	  9
#define AF_S_CAN_SEND	   10
#define AF_S_CANT_OPEN	 12

#define AF_S_WRONG       13
#define AF_S_ADMIN_LOGIN 14
#define AF_S_ADMIN_CMD   15

#define AF_S_KEEP_ALIVE  16

#define S_STATE_CLEAR	    0
#define S_STATE_CLOSING	  5
#define	S_STATE_OPENING	  6
#define S_STATE_OPEN	    7
#define S_STATE_STOPPED	 11

#define	AF_VER(info)	info" v0.7.1"

#define TYPE_TCP	1
#define TYPE_UDP	3
#define TYPE_SSL	4
#define TYPE_ZLIB	8
#define TYPE_IPV4	16
#define TYPE_IPV6	32
#define TYPE_COMP	0x4000

#define TYPE_SET_ZERO(type)	(type=0)
#define TYPE_IS_SET(type)       (type&1)
#define TYPE_IS_UDP(type)       TYPE_IS_SET(type)&&(type&2)
#define TYPE_IS_TCP(type)       TYPE_IS_SET(type)&&(!(type&2))
#define TYPE_SET_UDP(type)	(type|=TYPE_UDP)
#define TYPE_SET_TCP(type)	(type|=TYPE_TCP)
#define TYPE_SET_SSL(type)	(type|=TYPE_SSL)
#define TYPE_UNSET_SSL(type)	(type&=(~TYPE_SSL))
#define TYPE_IS_SSL(type)	(type&TYPE_SSL)
#define TYPE_SET_ZLIB(type)	(type|=TYPE_ZLIB)
#define TYPE_UNSET_ZLIB(type)	(type&=(~TYPE_ZLIB))
#define TYPE_IS_ZLIB(type)	(type&TYPE_ZLIB)

#define TYPE_SET_IPV4(type)	(type|=TYPE_IPV4)
#define TYPE_UNSET_IPV4(type)	(type&=(~TYPE_IPV4))
#define TYPE_IS_IPV4(type)	(type&TYPE_IPV4)
#define TYPE_SET_IPV6(type)	(type|=TYPE_IPV6)
#define TYPE_UNSET_IPV6(type)	(type&=(~TYPE_IPV6))
#define TYPE_IS_IPV6(type)	(type&TYPE_IPV6)
#define TYPE_SET_UNSPEC(type)	(type&=(~(TYPE_IPV4|TYPE_IPV6)))
#define TYPE_IS_UNSPEC(type)	(!(type&(TYPE_IPV4|TYPE_IPV6)))

#define TYPE_SET_COMP(type)	(type|=TYPE_COMP)
#define TYPE_IS_COMP(type)	(type&TYPE_COMP)

typedef struct {
  char* lisportnum;
  char* manportnum;
  int listenfd;
  int managefd;
} UsrCliT;

typedef struct {
	char state;
	int connfd;
  int whatcli;
  int userid;
  time_t connecttime;
	char namebuf[128];
	char portbuf[7];
	blnodeT* head;
} ConnectuserT;

typedef struct {
  char ready;
  clifd cliconn;
  struct timeval tv;
  int* users;
  int usercon;
  int usernum;
  int listenfd;
  int whatusrcli;
  int clientnum;
  time_t connecttime;
  char* clientid;
	char namebuf[128];
	char portbuf[7];
  char tunneltype;
  alnodeT* head;
} ConnectclientT;

typedef struct {
  char* hostname;
  char* users;
  char* clients;
  char* raclients;
  char* usrpcli;
  char* clim;
  char* timeout;
  char* realmname;
  unsigned char pass[4];
  int usercon;
  int usernum;
  int clicon;
  int clinum;
  int raclicon;
  int raclinum;
  int upcnum;
  int tmout;
  int climode;
  int usrclinum;
  int clientcounter;
  int usercounter;
  char type;
  char tunneltype;
  char dnslookups;
  char baseport;
  char audit;
  socklen_t addrlen;
  struct sockaddr* cliaddr;
  ConnectuserT* contable;
  ConnectclientT* clitable;
  ConnectclientT* raclitable;
  UsrCliT* usrclitable;
} RealmT;

typedef struct {
  char* certif;
  char* keys;
  char* dateformat;
  int size;
  time_t starttime;
  RealmT* realmtable;
} ConfigurationT;

#endif

