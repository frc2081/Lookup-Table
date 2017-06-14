#pragma once
namespace LibIcarus {
	template<class Tinput> class ISignalValidator
	{
		//Is abstract class - no implmentation and all methods are virtual
	public:

		virtual bool readSignal(Tinput input);

		//https://imgur.com/57wTpdb

	};
}

