#pragma once

#include <string>


namespace Exc
{


	class EStack
	{
	public:
		explicit EStack(const std::string& msg);
		EStack(const EStack& otherStack);

		virtual ~EStack();

		const char* what() const;
	private:
		std::string errMsg;
	};


	class EStackEmpty : public EStack
	{
	public:
		explicit EStackEmpty(const std::string& msg);
		EStackEmpty(const EStackEmpty& otherStack);
		~EStackEmpty() override;
	};


	class EStackOverflow : public EStack
	{
	public:
		explicit EStackOverflow(const std::string& msg);
		explicit EStackOverflow(const EStackEmpty& otherStack);
		~EStackOverflow() override;
	};


} // namespace Exc
