#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2/lab2.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab2test
{

   
        TEST_CLASS(lab2test) {
        public:

            // Имя метода теста
            TEST_METHOD(TestMethod1) {
        
                Assert::IsTrue(Prost(2));
                Assert::IsTrue(Prost(3));
                Assert::IsTrue(Prost(5));
                Assert::IsFalse(Prost(4));
                Assert::IsFalse(Prost(1));
                Assert::IsFalse(Prost(0));
                Assert::IsTrue(Prost(17));
                Assert::IsTrue(Prost(31));
                Assert::IsTrue(Prost(69));
            }
        }; 
  
}
