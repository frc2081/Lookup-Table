#pragma once
#include "ISignalValidator.h"
namespace LibIcarus {
	template<class TInput> class __declspec(dllexport) SignalValidator : ISignalValidator<TInput> {

	protected:
		virtual void GetBounds(double *toSetLower, double *toSetUpper, TInput input) = 0;

		virtual double readSignalFromHardware() = 0;
	};
}