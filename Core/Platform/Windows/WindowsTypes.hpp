#ifndef __WINDOWS_TYPES_HPP_
#define	__WINDOWS_TYPES_HPP_


namespace DadEngine::Core
{
	using uint64 = unsigned long long;
	using int64 = long long;
	using uint32 = unsigned int;
	using int32 = int;
	using uint16 = unsigned short;
	using int16 = short;
	using uint8 = unsigned char;
	using int8 = char;
	using b64 = unsigned long long;
	using b32 = unsigned int;
	using b16 = unsigned short;
	using b8 = unsigned char;

	const uint64 MAX_UINT64 = 0xffffffff;
	const int64 MAX_INT64	= 0xffffffff;
	const uint32 MAX_UINT32 = 0xffffffff;
	const int32 MAX_INT32	= 0xffffffff;

#if defined (_WIN64)
	using size_t = uint64;
#else
	using size_t = uint32;
#endif

    namespace Test
    {
        void TestTypes();
    } // namespace Test
}

//using namespace DadEngine::Core::Types;

#endif //__WINDOWS_TYPES_HPP_