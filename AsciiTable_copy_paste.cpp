#include <iostream>
#include "AsciiTable.h"
#include <Eigen/Dense>

// compilse with 
// g++ -I common -I external  AsciiTable_copy_paste.cpp -o ./bin/AsciiTable_copy_paste

// ****************************************************************************
// Here are the various examples you can use to display data in an organized, 
// tabular form, along with an example demonstrating a possible use Asciitable
// class.


int main(){    using namespace alf;
    
    AsciiTable tab;
    
    tab<<"Type" << "Quantity" << "Price" << "Best before" << AsciiTable::endl  //add the title
       << "Milk"<<   5        <<  3.1    << "18/10/2012"  << AsciiTable::endl  //add a new row
       << "Cheese" << 2       <<  18.4   << "18/10/2014"  << AsciiTable::endl; //add a new row
       
    
    std::cout << tab ; //print the table
    
    AsciiTable tab2;    
    tab2 << "type" << "value" << AsciiTable::endl;                                      //add the title
    tab2 << "matrix" << Eigen::MatrixXd::Constant(3,3,1.2)  << AsciiTable::endl;        //add a new row
    tab2 << "vector" << Eigen::VectorXd(3) << AsciiTable::endl;                         //add a new row
    tab2 << "vector.transpose" << Eigen::VectorXd(3).transpose() << AsciiTable::endl;   //add a new row
    
    std::cout << tab2; //print the table
    return 0;
}
