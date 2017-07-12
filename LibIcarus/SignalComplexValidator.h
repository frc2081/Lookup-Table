#pragma once
#include "ISignalValidator.h"
#include "SignalValidator.h"
#include "LookupTable.h"
namespace LibIcarus {
	template<class TInput> class __declspec(dllexport) SignalComplexValidator : SignalValidator<TInput>
	{
	public:
		~SignalComplexValidator();

		virtual double TInputGetDouble(TInput input) = 0;

	protected:

		LookupTable *lower;

		LookupTable *greater;


	};
}

