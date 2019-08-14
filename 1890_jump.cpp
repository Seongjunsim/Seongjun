#include "std_lib_facilities.h"
#include <queue>


int N;
int M = 0;
void dp(int** arr, int i, int j)
{
	int n = arr[i][j];
	if (i + n < N)
	{
		if (arr[i + n][j] == 0)
			M++;
		else
			dp(arr, i + n, j);
	}
	if (j + n < N)
	{
		if (arr[i][j + n] == 0)
			M++;
		else
			dp(arr, i, j + n);
	}
}

int main()
try {
	
	cin >> N;
	int **arr;
	arr = new int*[N];
	for (int i = 0; i < N; i++)
		arr[i] = new int[N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	dp(arr, 0, 0);
	cout << M << '\n';
	
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "exception\n";
	keep_window_open();
	return 2;
}
