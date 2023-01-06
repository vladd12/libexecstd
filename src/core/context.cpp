#include <core/context.hpp>

namespace Context {

Context::Context(const Builder *builder) {}

std::shared_ptr<Context> CreateContext(Builder *builder)
{
    return std::shared_ptr<Context>(new Context(builder));
}

} // namespace Context
