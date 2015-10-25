#include <iostream> 

#define M 5
#define N 3

float get_sample(){
    float x;
    std::cin >> x;
    return x;
}

int main(){
    
    int idx_w = 0; //index of the next sample 
    
    float buffer_w[M] = {0,0,0,0,0}; //buffer containing the last M status value w

    const float b[M+1] =  {-0.9,0.25,0.8,0.1,0.7,-0.1}; //b5,b4,b3,b2,b1,b0
    const float a[N] =  {0.3,-0.5,0.25}; //a2,a1,a0

    
    do{
        float x = get_sample();        
        
        if(!std::cin.eof()){
            
            float w  = x;
            for(int i =0; i < N; i++){
                w += a[i]*buffer_w[(idx_w+i+M-N)%M];
            }        
            
            float y = w*b[M];
            
            for(int i =0; i < M; i++){
                y += b[i]*buffer_w[(idx_w+i)%M];
            }        
            
            std::cout << y << std::endl;
            
            buffer_w[idx_w] = w;
            idx_w = (idx_w+1)%M;
            
        }        
        
    }while(!std::cin.eof());
    
    return 0;
} 