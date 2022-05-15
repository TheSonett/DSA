// Q. We have an array of repeated numbers. Now find their occurences


#include <iostream>
#include <map>

int main()
{
    int arr[11] = {2, 3, 4, 5, 6, 7, 2, 3, 4, 5, 6};
    std::map<int, int> mymap;

    for (int i = 0; i < 11; i++)
    {
        if(mymap.find(arr[i]) != mymap.end()) // 2 != end -> false
        {
            mymap[arr[i]]++;
        }
        else
        {
            mymap.insert(std::pair<int, int>(arr[i], 1));
        }
    }
    
    for(std::map<int,int>::iterator i = mymap.begin(); i != mymap.end(); i++) {
        std::cout << "Number: " << i->first << " is reapeated " << i->second << " times" << std::endl;
    }
    return 0;
}