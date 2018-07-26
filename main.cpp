#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

constexpr int size = 500000000;
constexpr int numberOfThreads = 10;
constexpr int placesForThread = size/numberOfThreads;

std::vector<int> randomManual;
std::vector<int> randomThreads;

void f(int y)
{
  std::cout << std::this_thread::get_id() << "\t" << y << std::endl;
}

void fillManualy()
{
  for(auto i = 0; i<size; i++)
  {
    randomManual[i]=3;
  }
}

void fillByThreads(int begin, int end)
{
  for(; begin<end; begin++){
    randomThreads[begin]=3;
    }
}


int main(int, char**)
{
  //std::vector<int> randomManual;
  //std::vector<int> randomThreads;
  randomManual.reserve(size);
  randomThreads.reserve(size);
  auto start=std::chrono::high_resolution_clock::now();
  fillManualy();
  auto end=std::chrono::high_resolution_clock::now();

  std::chrono::duration<double, std::micro> delta = end - start;
  std::cout << "Wypelnianie reczne: " <<std::chrono::duration_cast<std::chrono::milliseconds>(delta).count() <<"ms" << std::endl;


  start=std::chrono::high_resolution_clock::now();

  std::thread t1(fillByThreads, 0, placesForThread);
  std::thread t2(fillByThreads, placesForThread, 2*placesForThread);
  std::thread t3(fillByThreads, 2*placesForThread, 3*placesForThread);
  std::thread t4(fillByThreads, 3*placesForThread, 4*placesForThread);
  std::thread t5(fillByThreads, 4*placesForThread, 5*placesForThread);
  std::thread t6(fillByThreads, 5*placesForThread, 6*placesForThread);
  std::thread t7(fillByThreads, 6*placesForThread, 7*placesForThread);
  std::thread t8(fillByThreads, 7*placesForThread, 8*placesForThread);
  std::thread t9(fillByThreads, 8*placesForThread, 9*placesForThread);
  std::thread t10(fillByThreads, 9*placesForThread, 10*placesForThread);

  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  t6.join();
  t7.join();
  t8.join();
  t9.join();
  t10.join();
  end=std::chrono::high_resolution_clock::now();

  std::chrono::duration<double, std::micro> delta1 = end - start;
  std::cout << "MultiThreading: " <<std::chrono::duration_cast<std::chrono::milliseconds>(delta1).count() <<"ms" << std::endl;


  //std::thread t1(f, 10);
  //std::cout << std::endl;
  //std::thread t2(f, 40);
  //t1.joinable();
  ///t1.detach();
  //t2.detach();
  //t1.join();
  //t2.join();
//  std::cout << std::this_thread::get_id() << std::endl;
}
