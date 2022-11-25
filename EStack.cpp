#include "EStack.h"


namespace Exc
{


	EStack::EStack(const std::string& msg)
		: errMsg(msg)
	{
	}

	EStack::EStack(const EStack& otherStack)
		: errMsg(otherStack.errMsg)
	{
	}

	EStack::~EStack()
	{
	}

	const char* EStack::what() const
	{
		return errMsg.c_str();
	}


	EStackEmpty::EStackEmpty(const std::string& msg)
		: EStack(msg)
	{
	}

	EStackEmpty::EStackEmpty(const EStackEmpty& otherStack)
		: EStack(otherStack)
	{
	}

	EStackEmpty::~EStackEmpty()
	{
	}


	EStackOverflow::EStackOverflow(const std::string& msg)
		: EStack(msg)
	{
	}

	EStackOverflow::EStackOverflow(const EStackEmpty& otherStack)
		: EStack(otherStack)
	{
	}

	EStackOverflow::~EStackOverflow()
	{
	}


} // namespace Exc
