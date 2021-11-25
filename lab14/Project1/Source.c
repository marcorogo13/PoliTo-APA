
#include <stdio.h>
#include <stdlib.h>

#define DX 20
#define DY 30

const int MAXX[] = { 10, 10, 15, DX };
const int MAXY[] = { 15, 20, 25, DY };

typedef struct boxes_s {
	int x, y;


}boxes_t;

boxes_t* read_file(char*, int*);
void mark_truck(int[][DY], int, int, int, int);
int place_recur(int[][DY], int, int, boxes_t*, int, int);
int check(int[][DY], int, int, int, int, int, int);
void printSolution(int truck[][DY], int maxX, int maxY);

int main(int argc,char *argv[]){

	int n,i,ok=0;
	int truck[DX][DY];

	boxes_t* boxes;

	boxes = read_file(argv[1], &n);
	mark_truck(truck, 0, 0, DX, DY, 0);

	for (i = 0; i < 4 && ok != 1; i++) {
		ok = place_recur(truck, MAXX[i], MAXY[i],boxes,n,0);
		if (ok) {
			printf("The %c-type truck is required:\n", 'A' + i);
			printSolution(truck, MAXX[i], MAXY[i]);
		}
	}
	if (!ok) {
		printf("no solution available\n");
	}


	return 0;
}


boxes_t* read_file(char* file, int* n) {
	boxes_t* boxes;
	int i;
	FILE* fp;
	fp = fopen(file, "r");
	if (fp == NULL) {
		printf("error in opening file\n");
	}
	fscanf(fp, "%d", n);
	
	boxes = (boxes_t*)malloc(*n * sizeof(boxes_t));
	if (boxes == NULL) {
		printf("error in allocating boxes\n");
	}


	for (i = 0; i < *n; i++) {
		fscanf(fp, "%dx%d", &boxes[i].x, &boxes[i].y);
	}

	fclose(fp);

	return boxes;
}

void mark_truck(int truck[][DY],int x,int y,int dx,int dy,int id) {
	int i, j;
	
	for (i = x; i <x+dx; i++) {
		for (j = y; j < y + dy; j++) {
			truck[i][j] = id;
		}
	}

	return;
}


int place_recur(int truck[][DY], int maxx, int maxy, boxes_t* boxes, int n, int id) {
	int i, j, x, y;

	if (id == n) {
		return 1;
	}

	for (i = 0; i < maxx; i++) {
		for (j = 0; j < maxy; j++) {
			x = boxes[id].x;
			y = boxes[id].y;
			if (check(truck, maxx, maxy, boxes, i, j, x, y)) {
				mark_truck(truck, i, j, x, y, id + 1);
				if (place_recur(truck, maxx, maxy, boxes, n, id + 1)) {
					return 1;
				}
				mark_truck(truck, i, j, x, y, 0);
			}

			if (check(truck, maxx, maxy, i, j, y, x)) {
				mark_truck(truck, i, j, y, x, id + 1);
				if (place_recur(truck, maxx, maxy, boxes, n, id + 1)) {
					return 1;
				}
				mark_truck(truck, i, j, y, x, 0);
			}
		}
	}

	return 0;
}


int check(int truck[][DY], int maxx, int maxy, int x, int y, int dimx, int dimy) {
	int i, j;

	if (x + dimx > maxx || y + dimy > maxy) {
		return 0;
	}

	for (i = x; i < x + dimx; i++) {
		for (j = y; j < y + dimy; j++) {
			if (truck[i][j] != 0) {
				return 0;
			}
		}
	}
	return 1;
}


void printSolution(int truck[][DY], int maxX, int maxY)
{
	int i, j;

	for (i = 0; i < maxX; i++) {
		for (j = 0; j < maxY; j++) {
			if (truck[i][j] == 0) {
				/* just for a better printing */
				printf(".");
			}
			else {
				printf("%d", truck[i][j]);
			}
		}
		printf("\n");
	}
}
