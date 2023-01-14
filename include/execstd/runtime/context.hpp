#pragma once
#include <execstd/runtime/builder.hpp>

namespace Runtime
{
/// \brief Class for representing runtime context.
class libapi Context
{
public:
    Context() = delete;
    Context(const Builder *builder);
};
using ContextPtr = std::shared_ptr<Context>;

libapi ContextPtr createContext(Builder *builder = createDefaultBuilder().get());

} // namespace Runtime
