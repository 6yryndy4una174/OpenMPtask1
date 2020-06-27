#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

#include <omp.h>

int main()
{
	int seed = (int)time(0);
	omp_set_num_threads(5);
#pragma omp parallel
	{
		int rank = omp_get_thread_num();
		srand(seed + rank);
		int num = rand();
		std::ofstream file(std::to_string(rank) + ".txt");
		file << num;
		file.close();
	}
}
