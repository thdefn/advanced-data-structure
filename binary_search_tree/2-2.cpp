#include "BinSrchTree.h"
#include <cstdlib> // rand(), srand()
#include <ctime>   // time()
#include <chrono> 
#include <iostream>
#include <vector>

int sequentialSearch(const std::vector<int>& arr, int key);

int main()
{
    std::srand(static_cast<unsigned int>(std::time(0)));  // 랜덤 시드 초기화

    for (int i = 1; i <= 1000; i++) {
        int n = 10000 * i;
        std::vector<int> arr(n);  // 동적 배열로 변경 (std::vector 사용)

        // 배열에 랜덤 숫자 채우기
        for (int k = 0; k < n; k++) {
            arr[k] = std::rand() % n;
        }


		long long totalDuration = 0;

        // 10번 반복 테스트
        for (int j = 0; j < 10; j++) {
            int key = std::rand() % n;
            
            auto start = std::chrono::high_resolution_clock::now();
            sequentialSearch(arr, key);
            auto end = std::chrono::high_resolution_clock::now();

            // 마이크로초 단위로 측정
             auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count(); // 밀리초 대신 마이크로초 사용
			//std::cout << "Time taken for sequential search: " << duration << " milliseconds" << std::endl;
			 totalDuration += duration; 
        }

		double averageDuration = static_cast<double>(totalDuration) / 10;
		std::cout << "Average time taken for search: " << averageDuration << " microseconds" << std::endl;

    }

    return 0;
}



int sequentialSearch(const std::vector<int>& list, int key) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i] == key) {
            return i;
        }
    }
    return -1;
}
