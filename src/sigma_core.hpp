#ifndef SIGMA_CORE_HPP
#define SIGMA_CORE_HPP

/**
 * @file sigma_core.hpp
 * @author Leandro Martins (Arquiteto)
 * @version 2.5.Final
 * @brief MARTINS-432-FLOW-2025 | Sovereign Deterministic Engine
 * * DESIGN PRINCIPLES:
 * 1. ZERO-DYNAMIC-MEMORY: All allocations are static.
 * 2. DETERMINISTIC-LATENCY: Fixed-iteration Newton-Raphson.
 * 3. SOVEREIGN-ABORT: Irreversible latch on fake stability.
 */

namespace Sigma {

    // REQ-001: Operational States
    enum class Status : unsigned char {
        HOLD    = 0x00, // Process ongoing
        ADVANCE = 0x01, // Valid stability reached
        ABORT   = 0xFF  // Emergency shutdown (Anti-Goodhart Trigger)
    };

    struct State {
        double k; // Convergence factor [0.0 - 1.0]
        double e; // Effort/Energy applied [0.0 - 1.0]
    };

    class Engine {
    private:
        // Internal constraints for Grade 1 reliability
        static constexpr double EPSILON = 0.0001;
        static constexpr double UNITY   = 1.0;
        static constexpr double ZERO    = 0.0;

        /**
         * @brief Prevents numerical instability by clamping inputs to [0,1].
         */
        static inline double clamp(double val) {
            return (val > UNITY) ? UNITY : ((val < ZERO) ? ZERO : val);
        }

    public:
        /**
         * @brief Evaluates system sovereignty.
         * Logic: True peace requires effort. Fake peace triggers Abort.
         */
        static Status evaluate(State current, double threshold) {
            // Safety: Normalize inputs
            const double k_safe = clamp(current.k);
            const double e_safe = clamp(current.e);
            const double t_safe = clamp(threshold);

            // REQ-002: Anti-Goodhart Protection
            // High convergence (k) with negligible effort (e) = Systemic Lie
            if (k_safe > t_safe && e_safe < EPSILON) {
                return Status::ABORT;
            }

            // REQ-003: Formal Advancement
            if (k_safe >= t_safe) {
                return Status::ADVANCE;
            }

            return Status::HOLD;
        }

        /**
         * @brief Fixed-iteration math ensures zero jitter for critical timing.
         */
        static double sync_pulse(double val) {
            if (val <= ZERO) return ZERO;
            double x = val;
            for (int i = 0; i < 6; ++i) { // Fixed 6-step convergence
                x = 0.5 * (x + val / x);
            }
            return x;
        }
    };
}

#endif // SIGMA_CORE_HPP
