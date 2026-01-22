#ifndef SIGMA_CORE_HPP
#define SIGMA_CORE_HPP

/**
 * @file sigma_core.hpp
 * @version 2.6.Dual
 * @brief MARTINS-432-FLOW-2025 | Dual-Layer Architecture
 */

namespace Sigma {

    enum class Status : unsigned char {
        HOLD    = 0x00,
        ADVANCE = 0x01,
        ABORT   = 0xFF 
    };

    /**
     * @brief LAYER 1: ENGINE CORE (Stateless / Pure)
     * Direct mathematical evaluation without internal memory.
     */
    class EngineCore {
    public:
        static constexpr double EPSILON = 0.0001;
        
        static Status evaluate(double k, double e, double threshold) {
            double k_s = (k > 1.0) ? 1.0 : (k < 0.0 ? 0.0 : k);
            double e_s = (e > 1.0) ? 1.0 : (e < 0.0 ? 0.0 : e);

            if (k_s > threshold && e_s < EPSILON) return Status::ABORT;
            if (k_s >= threshold) return Status::ADVANCE;
            return Status::HOLD;
        }
    };

    /**
     * @brief LAYER 2: ENGINE SUPERVISOR (Stateful / Telemetry)
     * Manages Latch, Reason and Reset for industrial integration.
     */
    struct Telemetry {
        unsigned char last_reason; // 0: None, 1: Anti-Goodhart
        bool is_latched;
    };

    class EngineSupervisor {
    private:
        static inline Telemetry log = {0, false};

    public:
        static Status evaluate(double k, double e, double threshold) {
            if (log.is_latched) return Status::ABORT;

            Status result = EngineCore::evaluate(k, e, threshold);

            if (result == Status::ABORT) {
                log.is_latched = true;
                log.last_reason = 1; 
            }
            return result;
        }

        static Telemetry get_report() { return log; }
        static void reset() { log = {0, false}; }
    };
}

#endif
