#include <iostream>
#include <thread>


void min(int n) {
    std::cout << "Hello! I am minion " << n << std::endl;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "usage: " << argv[0] << " <nbminions>\n";
        return -1;
    }
    //code goes here
    int num = atoi(argv[1]);

    std::thread gru[num];

    for (int n = 0; n < num; ++n) {
        gru[n] = std::thread(min, n);
    }

    for (int n = 0; n < num; n++) {
        gru[n].join();
    }
    std::cout << "hello minions! I am the Overlord!" << std::endl;
    return 0;
}
