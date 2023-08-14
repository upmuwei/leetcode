#include <iostream>
#include <thread>
#include <mutex>

using namespace std;


int main() {

    mutex nice;
    //unique_lock可以自动加锁
    unique_lock<mutex>  lock(nice);

    return 0;
}