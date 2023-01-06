#pragma once
#include "builder.hpp"

namespace Context {
	/// \brief 
	/// \details 
	class Context {
	private:
	public:
		Context() = delete;
		Context(const Builder* builder);
	};

	std::shared_ptr<Context> CreateContext(Builder* builder = CreateDefaultBuilder().get());

}
