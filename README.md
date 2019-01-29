# What is an event loop?
Basically, an event loop is a state where a program runs indefinitely and waits for some events to be triggered. In this library, each time an event is emitted, the defined listeners callbacks will be started as a thread, which means that the program will execute instructions asynchronously!

This library makes use of [worker library](https://github.com/QuantumSheep/worker-c).

# How to use
Well, you don't have a lot of functions:
- `ev_emitter_init()` which instantiate an `EventEmitter *`. Use this function before using any other functions that requires an `EventEmitter`, else it will just doesn't work.
- `ev_on(EventEmitter *ev, char *event, void (*cb)(void *)))` can be used to add a listener to a given event. The callback function (`cb`) will be launched if the given event is emitted. Events are stored in a chained list style to take care of your RAM.
- `ev_emit(EventEmitter *ev, char *event, void *args)` is the emitter, when you launch this function, it will loop over all events who are listening in the `EventEmitter` (`ev`) and launch the callbacks that match the given event.
