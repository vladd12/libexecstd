#include <execstd/runtime/context.hpp>

namespace Runtime
{

Context::Context(const Builder *builder)
{
}

ContextPtr createContext(Builder *builder)
{
    return std::shared_ptr<Context>(new Context(builder));
}

} // namespace Runtime
