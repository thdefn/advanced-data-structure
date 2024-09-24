#include "BinSrchTree.h"
#include <cstdlib> // rand(), srand()
#include <ctime>   // time()
#include <chrono> 
#include <iostream>
#include <vector>

int sequentialSearch(int arr[], int size, int key);

int main()
{
	  std::srand(static_cast<unsigned int>(std::time(0)));
	for(int i = 1; i <= 1000; i++){
		int n = 10000 * i;
		int arr[n];

		for(int k = 0; k < n; k++ ){
			arr[k] =  std::rand() % n;
		}


        long long totalDuration = 0;
		for(int j = 0; j < 10; j++){
			int key = std::rand() % n;
			auto start = std::chrono::high_resolution_clock::now();
			sequentialSearch(arr, n, key);
			auto end = std::chrono::high_resolution_clock::now();

			 auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
			 totalDuration += duration; 
		}

		double averageDuration = static_cast<double>(totalDuration) / 10;
		std::cout << "Average time taken for search: " << averageDuration << " microseconds" << std::endl;

	}

	return 0;
}


int sequentialSearch(int list[], int n, int key){
	for(int i = 0; i < n; i++)
		if(list[i] == key)
			return i;
	return -1;
}