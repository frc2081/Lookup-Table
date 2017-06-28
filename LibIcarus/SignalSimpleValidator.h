#pragma once
#include "SignalValidator.h"
namespace LibIcarus {
	template<class TInput> class SignalSimpleValidator : SignalValidator<TInput>
	{
	public:

		SignalSimpleValidator();

		~SignalSimpleValidator();


	protected:

		virtual double readSignalFromHardware() = 0;

		double lower;

		double greater;
	};
}

