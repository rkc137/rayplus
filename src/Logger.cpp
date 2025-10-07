#include <rayplus/Logger.hpp>

#include <raylib.h>

namespace rayplus::logger
{

void set_level(Level logLevel)
{
    SetTraceLogLevel(static_cast<int>(logLevel));
}

} // namespace rayplus::logger