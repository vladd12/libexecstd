#pragma once
#include <execstd/runtime/builder.hpp>

namespace Runtime {
/// \brief
/// \details
class libapi Context
{
private:
public:
    Context() = delete;
    Context(const Builder *builder);
};

libapi std::shared_ptr<Context> CreateContext(Builder *builder = CreateDefaultBuilder().get());

} // namespace Runtime
