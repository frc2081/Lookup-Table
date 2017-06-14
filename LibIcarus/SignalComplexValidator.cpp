#include "SignalComplexValidator.h"
namespace LibIcarus {
	template<class Tinput> bool SignalValidator<Tinput>::readSignal(Tinput input) {
		double signal = readSignalFromHardware();

		return signal >= lower->GetOutput(signal) && signal <= greater->GetOutput(signal);
	}

	template<class Tinput>SignalValidator<Tinput>::~SignalValidator()
	{
		delete lower;
		delete greater;
	}
}
