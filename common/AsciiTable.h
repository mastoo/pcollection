#ifndef __ASCII_TABLE_H__
#define __ASCII_TABLE_H__
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>
#include <cassert>

namespace alf{

class AsciiTable {
   
    std::vector<std::vector< std::vector<std::string> > >row_list;
    std::vector<size_t> column_width_list;
    std::vector<size_t> row_height_list;

    size_t num_rows;
    size_t num_columns;
    size_t column_index;

    void print_orizontal_line(std::ostream& stream) const{
        stream << "+" ;
        for(size_t c = 0; c< column_width_list.size(); c++)
        {
            for(size_t i = 0; i<column_width_list[c]; i++ )
                stream << "-";
            stream << "+";
        } 
        stream << std::endl;
    }
    
    void clear_table(){
        row_list.clear();
        column_width_list.clear();
        row_list.push_back(std::vector<std::vector<std::string> >());
        row_height_list.push_back(1);
        
        num_rows = 0; 
        num_columns = 0;
        column_index = 0;
    }
    
    void print_table(std::ostream& stream) const{
        stream << std::endl;
        print_orizontal_line(stream);
        for ( size_t r = 0; r < num_rows; r ++){
            for(size_t m =0 ; m < row_height_list[r]; m++){
                stream << "|";                
                for ( size_t c = 0;c< num_columns; c++ ){                
                    stream << std::setw(column_width_list[c]);
                    
                    if(c<row_list[r].size()){
                        if(m < row_list[r][c].size()){
                            stream <<  row_list[r][c][m] ;
                        }else{
                            stream << "";
                        }
                    }else{
                        stream << "";
                    }
                    stream << "|";
                }
                
                stream <<std::endl;
            }
            
            if(r==0) print_orizontal_line(stream);
        }
        
        print_orizontal_line(stream);
        stream << std::endl;
    }
    
public:
    enum COMMAND {endl,clear} ;
    
    AsciiTable(): 
        num_rows(0),num_columns(0),column_index(0){
        row_list.push_back(std::vector<std::vector<std::string> >());
        row_height_list.push_back(1);
    }
    
    template <typename T>
    AsciiTable& operator<<(const T &obj){
        std::stringstream ss;
        //ss.flags(stream.flags());
        ss << /*std::setprecision(stream.precision()) <<*/ obj;
        
        std::vector<std::string> sub_rows;
        std::string to;
        size_t newH =0;
        size_t newW = 0;
        while(std::getline(ss,to,'\n')){
            newH++;
            newW = std::max(newW,2*(to.length()/2 + 1));
            sub_rows.push_back(to);
        }    
        
        if(column_index<num_columns){            
            size_t currentW = column_width_list[column_index];           
            column_width_list[column_index] = std::max(currentW,newW);
        }else{
            column_width_list.push_back(newW);
        }
        row_height_list[num_rows] = std::max(row_height_list[num_rows],newH);            
                
        row_list[num_rows].push_back(sub_rows);        

        column_index++;        
        if(num_columns < column_index)  num_columns = column_index;       
        
        return *this;
    }
    
    AsciiTable& operator<<(const COMMAND &c){
        switch(c){
            case endl:{
                row_list.push_back(std::vector<std::vector<std::string> >());
                row_height_list.push_back(1);
                num_rows ++;
                column_index = 0;
            }break;
            case clear:{
                clear_table();
            }break;
            default: 
                assert(false);
        }        
        return *this;
    }
   
    friend std::ostream & operator <<(std::ostream &os, const AsciiTable &tab);    
};

inline
std::ostream &operator <<(std::ostream &os, const AsciiTable &tab){
    tab.print_table(os);
    return os;
}

}// end namespace alf

#endif
