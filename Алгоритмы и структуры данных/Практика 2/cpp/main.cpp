#include "MyList.h"
#include <iostream>
#include <string>

int main()
{
    std::cout << "***** Test - epty dictionary: ******" << std::endl;
    SinglyOrderedList list;
    list.outAll();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "**** Test - Insert elements: ******" << std::endl;
    std::string str1 = "Hello";
    std::string str0 = "Ona";
    std::string str2 = "One";
    std::string str3 = "Ones";
    std::string str5 = "AAAA";
    std::string str6 = "Aaaa";
    std::string str7 = "----";
    std::string str8 = "****";

    list.insert(str1);
    list.insert(str2);
    list.insert(str6);
    list.insert(str0);
    list.insert(str3);
    list.insert(str7);
    list.insert(str5);
    list.insert(str8);
    list.outAll();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "***** Test - find element: ******" << std::endl;
    std::cout << str5 << " " << (list.searchItem(str5) == 1 ? "I find it!" : "No element") << std::endl;
    std::cout << "OOO " << (list.searchItem("OOO") == 1 ? "I find it!" : "No element!") << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;


    std::cout << "****** Test - delete element: *****" << std::endl;
    std::cout << "Count before delete:" << list.getCount() << std::endl;
    std::cout << (list.deleteItem(str1) ? "I delete " : "I can`t delete " ) << str1 << std::endl;
    std::cout << "Count after delete:" << list.getCount() << std::endl;
    std::cout << (list.deleteItem("adf") ? "I can delete adf!" : "I can`t delete adf!") << std::endl << std::endl;
    std::cout << "Count before delete:" << list.getCount() << std::endl;
    std::cout << (list.deleteItem(str7) ? "I delete " : "I can`t delete ") << str7 << std::endl;
    std::cout << "Count after delete:" << list.getCount() << std::endl;
    std::cout << std::endl << "List after delete:" << std::endl;
    list.outAll();
    std::cout << list.getCount();
    std::cout << std::endl;
    std::cout << std::endl;



    std::cout << std::endl << "***** Copy list ******" << std::endl;

    SinglyOrderedList list1(list);
    list1.outAll();
    std::cout << list1.getCount();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;




    std::cout << std::endl << "***** Merge with list ******" << std::endl;
    SinglyOrderedList list2;
    list2.insert("MayBe");
    list2.insert("----");
    list2.insert("Aaaa");
    std::cout << std::endl << "     ** Insert elements: ** " << std::endl;
    list2.outAll();
    std::cout << list2.getCount();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;




    std::cout << std::endl << "***** List after merge with list1 ******" << std::endl;
    list2.mergewithList(list);
    std::cout << "!!! List2 !!!" << std::endl;
    list2.outAll();
    std::cout << list2.getCount();
    std::cout << std::endl << "!!! List !!!" << std::endl;
    list.outAll();
    std::cout << list.getCount();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;




    SinglyOrderedList list3(list2);
    std::cout << std::endl << "***** Subtract Lists: ***** " << std::endl;
    list3.subtractList(list1);
    list3.outAll();
    std::cout << list3.getCount();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;



    std::cout << std::endl << "***** Cross Lists: ***** " << std::endl;
    SinglyOrderedList list4;
    list4.crossLists(list1, list2);
    list4.outAll();
    std::cout << list4.getCount();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    

}