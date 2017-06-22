// Implementation of the KMeans Algorithm
// reference: http://mnemstudio.org/clustering-k-means-example-1.htm

#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <fstream>

#include "Point.cpp"
#include "Cluster.cpp"
#include "kmean.cpp"

using namespace std;

int main(int argc, char *argv[])
{
	srand (time(NULL));

	int total_points = 9, total_values = 20, K = 3, max_iterations = 100;

	vector<Point> points;
	string point_name;
	ifstream arq;
	arq.open("datasets/aluno1.txt");
	for(int i = 0; i < total_points; i++)
	{
		switch(i){
			case 1:
				arq.open("datasets/aluno2.txt");
				break;
			case 2:
				arq.open("datasets/aluno3.txt");
				break;
			case 3:
				arq.open("datasets/aluno4.txt");
				break;
			case 4:
				arq.open("datasets/aluno5.txt");
				break;
			case 5:
				arq.open("datasets/aluno6.txt");
				break;
			case 6:
				arq.open("datasets/aluno7.txt");
				break;
			case 7:
				arq.open("datasets/aluno8.txt");
				break;
			case 8:
				arq.open("datasets/aluno9.txt");
				break;	
		}
		vector<double> values;
		if(arq.is_open()){
			for(int j = 0; j <= total_values+9; j++)
			{
				double value;
				arq >> value;
				values.push_back(value);
			}
		}
		arq.close();

		Point p(i, values);
		points.push_back(p);
	}

	KMeans kmeans(K, total_points, total_values, max_iterations);
	kmeans.run(points);

	return 0;
}
