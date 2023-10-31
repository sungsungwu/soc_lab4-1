#include "fir.h"

//#include <defs.h>
//#include <stub.c>

void __attribute__ ( ( section ( ".mprjram" ) ) ) initfir() {

    //initial your fir
    for(int i=0;i<N;i++){
       inputbuffer[i] = 0;
    }
}

int* __attribute__ ( ( section ( ".mprjram" ) ) ) fir(){
    initfir();
    int sum = 0; // initial sum = 0
    int data_storage = 0;

    for(int i=0;i<N;i++){
        int get_data = inputsignal[i]; // get data from stream
        inputbuffer[data_storage] = get_data; // store data to bram

        for(int k=0;k<N;k++){


            sum += taps[k]*inputbuffer[data_storage];
        }


     if(data_storage>=N){
             data_storage = data_storage-N;
             }

     outputsignal[i] = sum ;



     }


    //write down your fir
    return outputsignal;
}
