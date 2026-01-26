/*
 * 🛡️ MARTINS-432-FLOW | Experimental Module
 * MODULE: EngineSupervisor
 * STATUS: DEVELOPMENT_PREVIEW
 * * DESCRIPTION:
 * This module provides a temporal watchdog for the 432Hz pulse.
 * It is designed to verify cycle integrity without interfering with the Core.
 */

#ifndef ENGINE_SUPERVISOR_HPP
#define ENGINE_SUPERVISOR_HPP

class EngineSupervisor {
private:
    unsigned long last_tick;
    const unsigned long target_cycle_ns = 2314814; // Precise 432Hz in nanoseconds

public:
    EngineSupervisor() : last_tick(0) {}

    /**
     * @brief Validates if the current pulse is within the sovereign window.
     * @param current_ns The current timestamp in nanoseconds.
     * @return true if pulse is stable, false if jitter is detected.
     */
    bool verify_stability(unsigned long current_ns) {
        if (last_tick == 0) {
            last_tick = current_ns;
            return true;
        }

        unsigned long delta = current_ns - last_tick;
        last_tick = current_ns;

        // Tolerance window of 0.5%
        if (delta > (target_cycle_ns * 0.995) && delta < (target_cycle_ns * 1.005)) {
            return true;
        }
        return false;
    }
};

#endif
