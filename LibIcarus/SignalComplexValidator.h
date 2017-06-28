#pragma once
#include "ISignalValidator.h"
#include "SignalValidator.h"
#include "LookupTable.h"
namespace LibIcarus {
	template<class TInput> class SignalComplexValidator : SignalValidator<TInput>
	{
	public:
		~SignalComplexValidator();

		double TInputGetDouble(TInput input) = 0;

	protected:

		LookupTable *lower;

		LookupTable *greater;


	};
}

