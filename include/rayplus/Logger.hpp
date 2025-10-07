#pragma once

namespace rayplus::logger
{

enum class Level;

void set_level(Level logLevel);

enum class Level
{
    all = 0,        // Display all logs
    trace,          // Trace logging, intended for internal use only
    debug,          // Debug logging, used for internal debugging, it should be disabled on release builds
    info,           // Info logging, used for program execution info
    warning,        // Warning logging, used on recoverable failures
    error,          // Error logging, used on unrecoverable failures
    fatal,          // Fatal logging, used to abort program: exit(EXIT_FAILURE)
    none            // Disable logging
};

} // namespace rayplus