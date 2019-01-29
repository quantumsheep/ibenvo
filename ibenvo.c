#include "ibenvo.h"

EventEmitter *
ev_emmiter_init()
{
    EventEmitter *ev = (EventEmitter *)malloc(sizeof(EventEmitter *));
    ev->chain = NULL;

    return ev;
}

void
ev_on(EventEmitter *ev, char *event, void (*cb)(void *))
{
    _event_chain_t *chain = (_event_chain_t *)malloc(sizeof(_event_chain_t));
    chain->cb = cb;
    chain->event = event;
    chain->next = ev->chain;

    ev->chain = chain;
}

void
ev_emit(EventEmitter *ev, char *event, void *args)
{
    WorkerErr err;
    _event_chain_t *chain = ev->chain;

    while (chain != NULL)
    {
        if (strcmp(chain->event, event) == 0)
        {
            worker(chain->cb, args, &err);
        }

        chain = chain->next;
    }
}

void
ev_loop()
{
    while (1)
    {
    }
}
