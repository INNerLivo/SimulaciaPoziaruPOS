#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <random>
#include <string>
#include "my_socket.h"

class ThreadData {
public:
    ThreadData(long long replicationsCount, int bufferCapacity, MySocket* serverSocket);
    void produce();
    void consume();
private:
    const long long replicationsCount;
    const int bufferCapacity;
    std::queue<Point> buffer;
    std::mutex mutex;
    std::condition_variable isFull;
    std::condition_variable isEmpty;
    MySocket* serverSocket;
};

ThreadData::ThreadData(long long replicationsCount, int bufferCapacity, MySocket* serverSocket) :
        replicationsCount(replicationsCount),
        bufferCapacity(bufferCapacity),
        buffer(),
        mutex(),
        isFull(),
        isEmpty(),
        serverSocket(serverSocket) {

}

void produce(ThreadData& data) {
    //data.produce();
}

void consume(ThreadData& data) {
    //data.consume();
}

int main() {
    // create connection: host, port
    MySocket* mySocket = MySocket::createConnection("frios2.fri.uniza.sk", 12345);

    ThreadData data(3000, 10, mySocket);
    std::thread thProduce(produce, std::ref(data));

    consume(data);
    thProduce.join();

    delete mySocket;
    mySocket = nullptr;

    return 0;
}
