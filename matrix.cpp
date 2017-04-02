#include<iostream>
#include<malloc.h>
#define MaxSize 30
typedef int ElemType;
using namespace std;
typedef struct {
	int r;
	int c;
	ElemType d;
}Node;
typedef struct {
	int row;
	int cols;
	int nums;
	Node data[MaxSize];
}TMatrix;

void DispTMatrix(TMatrix L) {
	int n=0;
	for (int i = 1; i <= L.row; i++) {
		for (int j = 1; j <= L.cols; j++) {
			if (L.data[n].r == i && L.data[n].c == j) {
				cout << "  " << L.data[n].d << "  ";
				n++;
			}
			else
			{
				cout << "  " << 0<<"  ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void Created(TMatrix &L) {
	int r, w, x;
	cout << "请输入行数和列数\n";
	cin >> r >> w;
	L.row = r;
	L.cols = w;
	L.nums = 0;
	for (int i = 1; i <= r; i++) {
		cout << "请输入第"<<i<<"行";
		for (int j = 1; j <= w; j++) {
			cin >> x;
			if (x != 0) {
				L.data[L.nums].d = x;
				L.data[L.nums].r = i;
				L.data[L.nums].c = j;
				L.nums++;
			}
		}
	}
}

void AddMatrix(TMatrix A,TMatrix B,TMatrix &C) {
	if (A.cols != B.cols || A.row != B.row)
		return;
	int a = 0;
	int b = 0;
	C.cols = A.cols; C.row = A.row;
	C.nums = 0;
	while (a<A.nums||b<B.nums)
	{
		if (A.data[a].r< B.data[b].r||(A.data[a].r == B.data[b].r&&A.data[a].c<B.data[b].c)) {
			C.data[C.nums].d = A.data[a].d;
			C.data[C.nums].c = A.data[a].c;
			C.data[C.nums].r = A.data[a].r;
			C.nums++;
			a++;
		}
		else
		{
			if (A.data[a].r == B.data[b].r&&A.data[a].c==B.data[b].c) {
				C.data[C.nums].d = A.data[a].d+B.data[b].d;
				C.data[C.nums].c = A.data[a].c;
				C.data[C.nums].r = A.data[a].r;
				C.nums++;
				a++;
				b++;
			}
			else
			{
				C.data[C.nums].d = B.data[b].d;
				C.data[C.nums].c = B.data[b].c;
				C.data[C.nums].r = B.data[b].r;
				C.nums++;
				b++;
			}
		}
	}
}

void UnMatrix(TMatrix L,TMatrix &T) {
	T.row = L.cols;
	T.cols = L.row;
	T.nums = 0;
	for (int i=1; i<=L.cols; i++) {
		 for(int j = 0; j <= L.nums; j++) {
			if (L.data[j].c == i ) {
				T.data[T.nums].d = L.data[j].d;
				T.data[T.nums].c = L.data[j].r;
				T.data[T.nums].r = L.data[j].c;
				T.nums++;	
			}
		}
	}
}

void MxMatrix(TMatrix A,TMatrix B,TMatrix &C) {
	if (A.cols != B.row)
		return;
	C.nums = 0;
	C.row = A.row;
	C.cols = B.cols;
	int *data = (int*)malloc(sizeof(int) * 100);
	for (int c = 0; c < B.cols; c++) {
		data[c] = 0;
	}
	int a = 0;
	int b = 0;
	for (int i = 1; i <= A.row; i++) {
		b = 0;
		for (int j = 1; j <= A.cols; j++) {
			if (A.data[a].r == i && A.data[a].c == j) {
				while (B.data[b].r <= j) {
					if (B.data[b].r == j) {
						data[B.data[b].c] += B.data[b].d*A.data[a].d;
					}
					b++;
				}
				a++;
			}
		}
		for (int ci = 0; ci < B.cols; ci++) {
			if (data[ci] != 0) {
				C.data[C.nums].d = data[ci];
				data[ci] = 0;
				C.data[C.nums].r = i;
				C.data[C.nums].c = ci;
				C.nums++;
			}
		}
	}
	
	free(data);
}

int main() {
	TMatrix A1, A2, B1, B2,C1;
	Created(A1);
	DispTMatrix(A1);
	UnMatrix(A1, B1);
	DispTMatrix(B1);
	Created(C1);
	DispTMatrix(C1);
	MxMatrix(A1, C1, B2);
	DispTMatrix(B2);
	return 0;
}