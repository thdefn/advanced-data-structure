#include "BinSrchTree.h"
#include <cstdlib> // rand(), srand()
#include <ctime>   // time()
#include <chrono> 
#include <iostream>
#include <vector>

int sequentialSearch(const std::vector<int>& arr, int key);

int main()
{
    std::srand(static_cast<unsigned int>(std::time(0)));  // ���� �õ� �ʱ�ȭ

    for (int i = 1; i <= 1000; i++) {
        int n = 10000 * i;
        std::vector<int> arr(n);  // ���� �迭�� ���� (std::vector ���)

        // �迭�� ���� ���� ä���
        for (int k = 0; k < n; k++) {
            arr[k] = std::rand() % n;
        }


		long long totalDuration = 0;

        // 10�� �ݺ� �׽�Ʈ
        for (int j = 0; j < 10; j++) {
            int key = std::rand() % n;
            
            auto start = std::chrono::high_resolution_clock::now();
            sequentialSearch(arr, key);
            auto end = std::chrono::high_resolution_clock::now();

            // ����ũ���� ������ ����
             auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count(); // �и��� ��� ����ũ���� ���
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
