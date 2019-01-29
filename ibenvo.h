#ifndef _EVENEMENTIAL_H
#define _EVENEMENTIAL_H

#include "worker.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct _event_chain_t _event_chain_t;
struct _event_chain_t
{
    char *event;
    void (*cb)(void *);

    _event_chain_t *next;
};

typedef struct event_emitter_t EventEmitter;
struct event_emitter_t
{
    _event_chain_t *chain;
};

EventEmitter *
ev_emmiter_init();

void
ev_on(EventEmitter *ev, char *event, void (*cb)(void *));

void
ev_emit(EventEmitter *ev, char *event, void *args);

void
ev_loop();

#endif
