#include "SignalValidator.h"
namespace LibIcarus {

	template<class TInput> bool SignalValidator<TInput>::readSignal(TInput input) {
		double signal = readSignalFromHardware();

		double greater, lower;

		GetBounds(&lower, &greater, input);
		
		return signal <= greater && signal >= lower;
	}
}