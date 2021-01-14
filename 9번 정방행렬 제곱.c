


#include <stdio.h>
#include <stdlib.h>
int main() {


	int Arow;
	do {
		printf("행렬 A 의 ROW 값 입력(양수) : ");
		scanf("%d", &Arow); //행렬 A 의 row 는 항상 0이 아닌 양수여야 한다
	} while (Arow <= 0); //그렇기 때문에 do While 문을 사용하여 행렬 A 의 row 가 음수가 오는것 방지 


	int Acolum;
	do {
		printf("행렬 A 의 COLUMN 값 (양수) 입력 : ");
		//행렬 A 의 column 은 항상 0이 아닌 양수여야 한다
		scanf("%d", &Acolum);
		//그렇기 때문에 do while 문을 사용하여 행렬 A 의 column 이 음수가 오는것 방지.
	} while (Acolum <= 0);



	int Brow;
	do {
		//행렬 B 의 row 은 항상 0이 아닌 양수여야 한다
		printf("행렬 B 의 ROW 값 입력(양수) : ");
		scanf("%d", &Brow);
		//그렇기 때문에 do while 문을 사용하여 음수가 되는것 방지
	} while (Brow <= 0);


	int Bcolum;
	do {
		//행렬 B 의 COLUMN 은 항상 0이 아닌 양수여야 한다
		printf("행렬 B 의 COLUMN 값 (양수) 입력 : ");
		scanf("%d", &Bcolum);
		//그렇기 때문에 do while 문을 사용하여 음수가 되는것 방지
	} while (Bcolum <= 0);

	if (Acolum != Brow) {
		//A [j][k] B[k][i] 꼴이여야 곱셈 가능한데 K 값이 서로 다를 경우
		printf("곱할수 없습니다.!");
		//프로그램 종료
		exit(1);
	}

	//행렬 A 의 크기는 동적 할당을 사용하여 생성한다. 2차원 배열이므로 2중 포인터 생성
	int **Adata = (int *)malloc(sizeof(int)*Arow);
	for (int i = 0; i < Arow; i++) { //Adata 의 [i] 번째도 포인터이므로 for 문을 사용하여 동적 할당
		Adata[i] = malloc(sizeof(int)*Acolum);
	}

	//행렬 B 의 크기는 동적 할당을 사용하여 생성한다. 2차원 배열이므로 2중 포인터 생성
	int **Bdata = (int *)malloc(sizeof(int)*Brow);
	for (int i = 0; i < Brow; i++) { //Bdata 의 [i] 번째도 포인터이므로 for 문을 사용하여 동적 할당
		Bdata[i] = malloc(sizeof(int)*Bcolum);
	}

	//행렬 Sigmadata 의 크기는 동적 할당을 사용하여 생성한다. 2차원 배열이므로 2중 포인터 생성
	//row 는 A 의 row 만큼
	int **Sigmadata = (int*)malloc(sizeof(int)*Arow);
	for (int i = 0; i < Arow; i++) {
		Sigmadata[i] = malloc(sizeof(int)*Bcolum); //Sigmadata 의 [i] 번째도 포인터이므로 for 문을 사용하여 동적 할당
		//column 은 Bcolumn 만큼 할당
	}

	for (int i = 0; i < Arow; i++) {
		printf("A 행렬의 %d 번째 입력 (%d 개) : ", i, Acolum); //행렬 A 의 값을 저장하는 for 문
		for (int j = 0; j < Acolum; j++) {

			scanf("%d", &Adata[i][j]);
		}
	}

	for (int i = 0; i < Brow; i++) {
		//행렬 B 의 값을 저장하는 for 문
		printf("B 행렬의 %d 번째 입력 (%d 개) : ", i, Bcolum);
		for (int j = 0; j < Bcolum; j++) {

			scanf("%d", &Bdata[i][j]);
		}
	}

	//두개 곱한 행렬의 값을 계산하고 저장하는 for 문
	for (int i = 0; i < Arow; i++) {
		for (int j = 0; j < Bcolum; j++) {
			int sum = 0; //곱하고 더해야 하므로 일단 sum 은 0
			for (int k = 0; k < Brow; k++) {
				sum += Adata[i][k] * Bdata[k][j];
				//원래 있던 sum 의 aij * bji + aiu * b ui 이므로 sum 에 더해줌
			}
			Sigmadata[i][j] = sum;
			//for 문이 끝났으면 i j 번째에 값이 정해진것이므로 할당
		}
	}

	printf("\n입력받은 행렬의 곱셈 결과 \n"); //행렬을 출력하는 부분
	for (int i = 0; i < Arow; i++) {
		for (int j = 0; j < Bcolum; j++) {
			printf("%d ", Sigmadata[i][j]);
		}
		printf("\n");
	}


}