#include <iostream> 

#define M 4
#define N 3

float get_sample(){
    float x;
    std::cin >> x;
    return x;
}

int main(){
    
    int idx_x = 0; //index of the next sample 
    float buffer_x[M+1] = {0,0,0,0,0}; //buffer containing the last M+1 samples
    const float b[M+1] =  {0.25,0.8,0.1,0.7,-0.1}; //b4,b3,b2,b1,b0

    int idx_y = 0; //index of the next output
    float buffer_y[N] = {0,0,0}; //buffer containing the last N output
    const float a[N] =  {0.3,-0.5,0.25}; //a2,b1,b0

    
    do{
        buffer_x[idx_x] = get_sample(); 
        idx_x = (idx_x+1)%(M+1);    
                
        if(!std::cin.eof()){
            float y = 0;
            for(int i =0; i < M+1; i++){
                y += b[i]*buffer_x[(idx_x+i)%(M+1)];
            }        

            for(int i =0; i < N; i++){
                y += a[i]*buffer_y[(idx_y+i)%N];
            }        
            
            std::cout << y << std::endl;
            
            buffer_y[idx_y] = y;
            idx_y = (idx_y+1)%N;    
        }        
        
    }while(!std::cin.eof());
    
    return 0;
} 