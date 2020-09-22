#include "pch.h"
#include "CppUnitTest.h"
#include "PolyDrawable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(PollyDrawableTest)
	{
	public:
		bool CheckColor(Gdiplus::Color color1, Gdiplus::Color color2) 
		{
			return (color1.GetValue() == color2.GetValue() );
		}

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCPolyDrawableConstructor)
		{
			CPolyDrawable poly(L"Harold");

			Assert::AreEqual(std::wstring(L"Harold"), poly.GetName());

		}

		TEST_METHOD(TestCPolyDrawableColor)
		{
			CPolyDrawable poly(L"Harold");
			Gdiplus::Color color1 = Gdiplus::Color::Black;

			Assert::IsTrue( CheckColor(color1, poly.GetColor()) );

			Gdiplus::Color color2 = Gdiplus::Color::Red;
			
			poly.SetColor(color2);

			Assert::IsFalse(CheckColor(color1, poly.GetColor()) );
			Assert::IsTrue(CheckColor(color2, poly.GetColor()) );

		}

	};
}