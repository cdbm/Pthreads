#include <iostream>
#include <pthread.h>
#include <chrono>
#include <thread>
using namespace std;

#define Num 7
#define M 100

pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER;
int x = 0;
bool fim = false;


void *add(void  *id){
    long t;
    t = (long) id;

    while(!fim){
  
        pthread_mutex_lock(&myMutex);
        x++;
        pthread_mutex_unlock(&myMutex);
        cout << "valor de x: " << x << " somado por thread " << t<< endl;
    
        if(x == M){
            fim = true;
            cout << "término por thread: "  << t << "valor de x: " << x <<endl;
        }
    
    //this_thread::sleep_for (chrono::seconds(1));       
    }
    pthread_exit(NULL);
}


int main(int argc, char const *argv[])
{
    pthread_mutex_init(&myMutex, NULL);
    long i = 0;
    int counter;
    pthread_t threads[Num];
    for(i=0; i<Num && !fim; i++ ){
        cout << "creating thread " << i << endl; 
        counter = pthread_create(&threads[i], NULL, *add, (void *) i);
    }
    pthread_exit(NULL);
   
}


