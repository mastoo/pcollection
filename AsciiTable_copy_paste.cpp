#include <iostream>
#include "AsciiTable.h"
#include <glm/vec3.hpp> // glm::vec3
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext.hpp>

int main(){    using namespace alf;
    
    AsciiTable tab;
    
    tab<<"Type" << "Quantity" << "Price" << "Best before" << AsciiTable::endl
       << "Milk"<<   5        <<  3.1    << "18/10/2012"  << AsciiTable::endl 
       << "Cheese" << 2       <<  18.4   << "18/10/2014"  << AsciiTable::endl ;
       
    std::cout << tab ;
    
    
    
    
    AsciiTable tab2;    
    tab2 << "type" << "value" << AsciiTable::endl;    
    tab2 << "glm::vec3" << glm::to_string(glm::vec3(0.0f, 0.0f,1.0f)) << AsciiTable::endl;
    tab2 << "glm::mat4" << glm::to_string(glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.f)) << AsciiTable::endl;
    
    
    std::cout << tab2;
    return 0;
}
