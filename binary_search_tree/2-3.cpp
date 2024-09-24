#include "BinSrchTree.h"
#include <cstdlib>
#include <ctime>
#include <chrono> 
#include <iostream>

int main()
{
	  std::srand(static_cast<unsigned int>(std::time(0)));
	for(int i = 1; i <= 1000; i++){
		int n = 10000 * i;
		BinSrchTree tree;

		for(int k = 0; k < n; k++ ){
			int num =  std::rand() % n;
			tree.insert(new BinaryNode(num));
		}


		long long totalDuration = 0;


		for(int j = 0; j < 10; j++){
			int key = std::rand() % n;
			auto start = std::chrono::high_resolution_clock::now();
			tree.search(key);
			auto end = std::chrono::high_resolution_clock::now();

			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count(); // 밀리초 대신 마이크로초 사용
			totalDuration += duration; 
		}

		 double averageDuration = static_cast<double>(totalDuration) / 10;
		  std::cout << "Average time taken for search: " << averageDuration << " microseconds" << std::endl;

		
	}

	return 0;
}

