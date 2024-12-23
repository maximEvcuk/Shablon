#include"Array.h"

int main() {

    Array<int> myArray;

    for (int i = 0; i < 15; ++i)
    {
        myArray.append(i);
    }

    std::cout << "Array elements:";
        myArray.display();
    std::cout << "Size:" << myArray.getSize() << ", Capacity:" << myArray.getCapacity() << std::endl;
    
    
    myArray.erase(5);
    std::cout << "After erasing index 5:";
    myArray.display();

    myArray.clear();
    std::cout << "After clearing: Size:" << myArray.getSize() << ", Capacity:" << myArray.getCapacity() << std::endl;

    
    Array<int> myArray;

    for (int i = 0; i < 10; ++i)
    {
        myArray.append(i*10);
    }
    
    std::cout << "Array after appending:";
    myArray.display();
    
    myArray.shrink();
    std::cout << "After shrinking : Size:" << myArray.getSize() << ", Capacity:" << myArray.getCapacity() << std::endl;

    
    
    
    
    
    
    
   /* Array<int> emptyArray(5);
    emptyArray.display();

    Array<int> randomArray(10, true);
    randomArray.display();

    Array<int> rangeArray(10, 1, 100);
    rangeArray.display();

    std::cout << "Min: " << rangeArray.min() << std::endl;
    std::cout << "Max: " << rangeArray.max() << std::endl;

    rangeArray.sort();
    std::cout << "Sorted array: ";
    rangeArray.display();

    rangeArray.resize(5);
    std::cout << "Resized array: ";
    rangeArray.display();*/

    return 0;
}