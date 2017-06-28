#pragma once
#include "ISignalValidator.h"
namespace LibIcarus {
	template<class TInput> class SignalValidator : ISignalValidator<TInput> {

	protected:
		void GetBounds(double *toSetLower, double *toSetUpper, TInput input) = 0;

		virtual double readSignalFromHardware() = 0;
	};
}