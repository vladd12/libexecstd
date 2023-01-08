#include <execstd/runtime/context.hpp>

namespace Runtime {

Context::Context(const Builder *builder) {}

std::shared_ptr<Context> CreateContext(Builder *builder)
{
    return std::shared_ptr<Context>(new Context(builder));
}

} // namespace Runtime
