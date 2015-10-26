#include <iostream>
#include "AsciiTable.h"

int main(){    using namespace alf;
    
    AsciiTable tab;
    
    tab<<"Type" << "Quantity" << "Price" << "Best before" << AsciiTable::endl
       << "Milk"<<   5        <<  3.1    << "18/10/2012"  << AsciiTable::endl 
       << "Cheese" << 2       <<  18.4   << "18/10/2014"  << AsciiTable::endl ;
       
    std::cout << tab ;
    
    
    return 0;
}
