#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <iomanip>

int main()
{
	std::cout << "=== Serialization Test Program ===" << std::endl;
	std::cout << std::endl;
	
	Data originalData(42, "TestObject", 3.14f, true);
	
	std::cout << "1. Original Data object:" << std::endl;
	std::cout << "   Address: " << &originalData << std::endl;
	std::cout << "   Content: ";
	originalData.display();
	std::cout << std::endl;
	
	// Serialize the Data pointer
	uintptr_t serializedPtr = Serializer::serialize(&originalData);
	
	std::cout << "2. Serialization:" << std::endl;
	std::cout << "   Original pointer: " << &originalData << std::endl;
	std::cout << "   Serialized value: 0x" << std::hex << serializedPtr << std::dec << std::endl;
	std::cout << "   Serialized value (decimal): " << serializedPtr << std::endl;
	std::cout << std::endl;
	
	// Deserialize back to pointer
	Data* deserializedPtr = Serializer::deserialize(serializedPtr);
	
	std::cout << "3. Deserialization:" << std::endl;
	std::cout << "   Deserialized pointer: " << deserializedPtr << std::endl;
	std::cout << "   Content: ";
	deserializedPtr->display();
	std::cout << std::endl;

	std::cout << "4. Verification:" << std::endl;
	std::cout << "   Original pointer == Deserialized pointer: " 
			<< ((&originalData == deserializedPtr) ? " TRUE" : " FALSE") << std::endl;
	
	// Verify data is accessible and correct
	std::cout << "   Data integrity check: "
			<< ((originalData == *deserializedPtr) ? " TRUE" : " FALSE") << std::endl;
	std::cout << std::endl;
	
	// Additional test with another data
	std::cout << "5. Additional test with different data:" << std::endl;
	Data secondData(100, "SecondTest", -2.5f, false);
	std::cout << "   Second data: ";
	secondData.display();
	
	uintptr_t serialized2 = Serializer::serialize(&secondData);
	Data* deserialized2 = Serializer::deserialize(serialized2);
	
	std::cout << "   Pointer equality: " 
			<< ((&secondData == deserialized2) ? " TRUE" : " FALSE") << std::endl;
	std::cout << "   Data integrity: "
			<< ((secondData == *deserialized2) ? " TRUE" : " FALSE") << std::endl;
	std::cout << std::endl;
	
	// Test with null pointer
	std::cout << "6. Null pointer test:" << std::endl;
	Data* nullPtr = NULL;
	uintptr_t serializedNull = Serializer::serialize(nullPtr);
	Data* deserializedNull = Serializer::deserialize(serializedNull);
	
	std::cout << "   Original null pointer: " << nullPtr << std::endl;
	std::cout << "   Serialized null: " << serializedNull << std::endl;
	std::cout << "   Deserialized null: " << deserializedNull << std::endl;
	std::cout << "   Null pointer equality: " 
			<< ((nullPtr == deserializedNull) ? " TRUE" : " FALSE") << std::endl;
	
	std::cout << std::endl;
	std::cout << "=== All tests completed ===" << std::endl;
	
	return 0;
}
