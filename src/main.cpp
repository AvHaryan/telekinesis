#include "forward.h"

int main() {
    Forward_List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);
    list.display();
    Forward_List<char> chList {'a', 'b', 'c', 'd'};
    chList.display();
    Forward_List<int> list2(123);
    list2.display();
    Forward_List<int> list3(list);
    list3.display();
    Forward_List<int> list4(std::move(list3));
    list4.display();
    std::cout <<"--->\n";
    list3.display();
    std::cout << "<---\n";
    list3 = list4;
    list3.display();
    Forward_List<int> list5{7, 14, 21, 28, 35, 49};
    list3 = std::move(list5);
    list3.display();
    std::cout <<"--->\n";
    list5.display();
    std::cout << "<---\n";


}
