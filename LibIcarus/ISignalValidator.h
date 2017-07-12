#pragma once
namespace LibIcarus {
	template<class TInput> class __declspec(dllexport) ISignalValidator {
		//Is abstract class - no implmentation and all methods are virtual
	public:

		virtual bool readSignal(TInput input);

		//https://imgur.com/57wTpdb
		
	};
}

