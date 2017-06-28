#include "SignalComplexValidator.h"
namespace LibIcarus {

	template<class TInput> void SignalComplexValidator<TInput>::GetBounds(double *toSetLower, double *toSetUpper, TInput input) {

		//what user wants
		double TInputReading = TInputGetDouble();

		*toSetLower = lower->GetOutput(TInputReading);

		*toSetGreater = greater->GetOutput(TInputReading);
	}

	template<class TInput>SignalComplexValidator<TInput>::~SignalComplexValidator()
	{
		delete lower;
		delete greater;
	}
};
