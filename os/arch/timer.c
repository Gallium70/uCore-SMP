#include <arch/riscv.h>
#include <ucore/defs.h>

const uint64 TICKS_PER_SEC = 100;   // 10 ms
const uint64 MSEC_PER_SEC = 1000;   // 1s = 1000 ms
const uint64 USEC_PER_SEC = 1000000;    // 1s = 1000000 us
const uint64 CPU_FREQ = 100000000;   // 100 MHz

uint64 get_cycle() {
    return r_time();
}


void timerinit() {

}

void start_timer_interrupt(){
    w_sie(r_sie() | SIE_STIE);
    set_next_timer();
}

void stop_timer_interrupt(){
    w_sie(r_sie() & ~SIE_STIE);
}

/// Set the next timer interrupt (10 ms)
void set_next_timer() {
    // 100Hz @ QEMU
    const uint64 timebase = CPU_FREQ / TICKS_PER_SEC; // how many ticks
    set_timer(get_cycle() + timebase);
}


uint64 get_time_ms() {
    return get_cycle() / (CPU_FREQ / MSEC_PER_SEC);
}

uint64 get_time_us() {
    // TODO: use variables, not literal numbers
    return get_cycle() / (CPU_FREQ / USEC_PER_SEC);
}