#ifndef _Policy_H_
#define _Policy_H_
#include <Windows.h>

namespace TL
{

	class NullType;
	struct EmptyType{};

	//TypeList
	template< class T, class U >
	struct TypeList
	{
		typedef	T	Head;
		typedef U	Tail;
	};

#define TYPELIST_1(T1) TypeList<T1,NullType>
#define TYPELIST_2(T1,T2) TypeList<T1,TYPELIST_1(T2)>
#define TYPELIST_3(T1,T2,T3) TypeList<T1,TYPELIST_2(T2,T3)>
#define TYPELIST_4(T1,T2,T3,T4) TypeList<T1,TYPELIST_3(T2,T3,T4)>
#define TYPELIST_5(T1,T2,T3,T4,T5) TypeList<T1,TYPELIST_4(T2,T3,T4,T5)>
#define TYPELIST_6(T1,T2,T3,T4,T5,T6) TypeList<T1,TYPELIST_4(T2,T3,T4,T5,T6)>

	//IndexOf
	template< class TList, class T > struct IndexOf;
	template< class T >
	struct IndexOf<NullType, T>{
		enum { value = -1 };
	};
	template< class Tail, class T >
	struct IndexOf< TypeList<T,Tail>, T >{
		enum { value = 0 };
	};
	template< class Head, class Tail, class T >
	struct IndexOf< TypeList<Head,Tail>, T >{
	private:
		enum { temp = IndexOf<Tail, T>::value };
	public:
		enum { value = temp == -1 ? -1 : 1 + temp };
	};

	//Select
	template< bool flag, typename T, typename U >
	struct Select
	{
		typedef T Result;
	};
	template<typename T, typename U>
	struct Select<false, T, U >
	{
		typedef U Result;
	};

	//TypeAtNonStrict
	template <class TList, unsigned int index,
	typename DefaultType = NullType>
	struct TypeAtNonStrict
	{
		typedef DefaultType Result;
	};        
	template <class Head, class Tail, typename DefaultType>
	struct TypeAtNonStrict<TypeList<Head, Tail>, 0, DefaultType>
	{
		typedef Head Result;
	};        
	template <class Head, class Tail, unsigned int i, typename DefaultType>
	struct TypeAtNonStrict<TypeList<Head, Tail>, i, DefaultType>
	{
		typedef typename 
			TypeAtNonStrict<Tail, i - 1, DefaultType>::Result Result;
	};    


	template< typename T >
	class TypeTraits
	{
	private:
		//PointerTraits
		template<class U> struct PointerTraits
		{
			enum{ result = false };
			typedef NullType PointeeType;
		};
		template<class U> struct PointerTraits<U*>
		{
			enum{ result = true };
			typedef U PointeeType;
		};

		//PToMTraits
		template<class U> struct PToMTraits
		{
			enum{ result = false };
		};
		template<class U, class V> struct PToMTraits<U V::*>
		{
			enum{ result = true };
		};

		//ReferencedType
		template<class U> struct ReferenceTraits
		{
			enum{ result = false };
			typedef U ReferencedType;
		};
		template<class U> struct ReferenceTraits<U&>
		{
			enum{ result = true };
			typedef U ReferencedType;
		};

		//UnConst
		template<class U> struct UnConst
		{
			typedef U Result;
		};
		template<class U> struct UnConst<const U>
		{
			typedef U Result;
		};
	public:
		typedef TYPELIST_4( unsigned char, unsigned short int, unsigned int, unsigned long int ) UnsignedInts;
		typedef TYPELIST_4( signed char, short int, int, long int ) SignedInts;
		typedef TYPELIST_3( bool, char, wchar_t ) OtherInts;
		typedef TYPELIST_3( float, double, long double ) Floats;

		enum{ isStdUnsignedInt = TL::IndexOf<UnsignedInts, T>::value >= 0 };
		enum{ isStdSignedInt = TL::IndexOf<SignedInts, T>::value >= 0 };
		enum{ isStdIntegral = isStdUnsignedInt || isStdSignedInt || TL::IndexOf<OtherInts, T>::value >=0 };
		enum{ isStdFloat = TL::IndexOf<Floats, T>::value >=0 };
		enum{ isStdArith = isStdIntegral || isStdFloat };
		enum{ isStdFundamental = isStdArith || isStdFloat };

		enum{ isMemberPointer = PToMTraits<T>::result };
		enum{ isPointer = PointerTraits<T>::result };

		typedef typename UnConst<T>::Result NoConstType;
		typedef typename ReferenceTraits<T>::ReferencedType ReferencedType;
		typedef typename Select<isStdArith || isPointer || isMemberPointer, T, ReferencedType& >::Result	ParameterType;
	};
}

#endif