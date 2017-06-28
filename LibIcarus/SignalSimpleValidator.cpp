#include "SignalSimpleValidator.h"
namespace LibIcarus {

	template<class TInput> void SignalSimpleValidator<TInput>::GetBounds(double *toSetLower, double *toSetUpper, TInput input) {

		*toSetLower = lower;

		*toSetGreater = greater;

	}
};