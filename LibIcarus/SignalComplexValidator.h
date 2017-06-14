#pragma once
#include "ISignalValidator.h"
#include "LookupTable.h"
namespace LibIcarus {
	template<class Tinput> class SignalValidator : ISignalValidator<Tinput>
	{
	public:
		~SignalValidator();


	protected:

		virtual double readSignalFromHardware() = 0;

		LookupTable *lower;

		LookupTable *greater;


	};
}

