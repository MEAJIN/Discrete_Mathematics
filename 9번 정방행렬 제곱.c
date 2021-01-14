


#include <stdio.h>
#include <stdlib.h>
int main() {


	int Arow;
	do {
		printf("��� A �� ROW �� �Է�(���) : ");
		scanf("%d", &Arow); //��� A �� row �� �׻� 0�� �ƴ� ������� �Ѵ�
	} while (Arow <= 0); //�׷��� ������ do While ���� ����Ͽ� ��� A �� row �� ������ ���°� ���� 


	int Acolum;
	do {
		printf("��� A �� COLUMN �� (���) �Է� : ");
		//��� A �� column �� �׻� 0�� �ƴ� ������� �Ѵ�
		scanf("%d", &Acolum);
		//�׷��� ������ do while ���� ����Ͽ� ��� A �� column �� ������ ���°� ����.
	} while (Acolum <= 0);



	int Brow;
	do {
		//��� B �� row �� �׻� 0�� �ƴ� ������� �Ѵ�
		printf("��� B �� ROW �� �Է�(���) : ");
		scanf("%d", &Brow);
		//�׷��� ������ do while ���� ����Ͽ� ������ �Ǵ°� ����
	} while (Brow <= 0);


	int Bcolum;
	do {
		//��� B �� COLUMN �� �׻� 0�� �ƴ� ������� �Ѵ�
		printf("��� B �� COLUMN �� (���) �Է� : ");
		scanf("%d", &Bcolum);
		//�׷��� ������ do while ���� ����Ͽ� ������ �Ǵ°� ����
	} while (Bcolum <= 0);

	if (Acolum != Brow) {
		//A [j][k] B[k][i] ���̿��� ���� �����ѵ� K ���� ���� �ٸ� ���
		printf("���Ҽ� �����ϴ�.!");
		//���α׷� ����
		exit(1);
	}

	//��� A �� ũ��� ���� �Ҵ��� ����Ͽ� �����Ѵ�. 2���� �迭�̹Ƿ� 2�� ������ ����
	int **Adata = (int *)malloc(sizeof(int)*Arow);
	for (int i = 0; i < Arow; i++) { //Adata �� [i] ��°�� �������̹Ƿ� for ���� ����Ͽ� ���� �Ҵ�
		Adata[i] = malloc(sizeof(int)*Acolum);
	}

	//��� B �� ũ��� ���� �Ҵ��� ����Ͽ� �����Ѵ�. 2���� �迭�̹Ƿ� 2�� ������ ����
	int **Bdata = (int *)malloc(sizeof(int)*Brow);
	for (int i = 0; i < Brow; i++) { //Bdata �� [i] ��°�� �������̹Ƿ� for ���� ����Ͽ� ���� �Ҵ�
		Bdata[i] = malloc(sizeof(int)*Bcolum);
	}

	//��� Sigmadata �� ũ��� ���� �Ҵ��� ����Ͽ� �����Ѵ�. 2���� �迭�̹Ƿ� 2�� ������ ����
	//row �� A �� row ��ŭ
	int **Sigmadata = (int*)malloc(sizeof(int)*Arow);
	for (int i = 0; i < Arow; i++) {
		Sigmadata[i] = malloc(sizeof(int)*Bcolum); //Sigmadata �� [i] ��°�� �������̹Ƿ� for ���� ����Ͽ� ���� �Ҵ�
		//column �� Bcolumn ��ŭ �Ҵ�
	}

	for (int i = 0; i < Arow; i++) {
		printf("A ����� %d ��° �Է� (%d ��) : ", i, Acolum); //��� A �� ���� �����ϴ� for ��
		for (int j = 0; j < Acolum; j++) {

			scanf("%d", &Adata[i][j]);
		}
	}

	for (int i = 0; i < Brow; i++) {
		//��� B �� ���� �����ϴ� for ��
		printf("B ����� %d ��° �Է� (%d ��) : ", i, Bcolum);
		for (int j = 0; j < Bcolum; j++) {

			scanf("%d", &Bdata[i][j]);
		}
	}

	//�ΰ� ���� ����� ���� ����ϰ� �����ϴ� for ��
	for (int i = 0; i < Arow; i++) {
		for (int j = 0; j < Bcolum; j++) {
			int sum = 0; //���ϰ� ���ؾ� �ϹǷ� �ϴ� sum �� 0
			for (int k = 0; k < Brow; k++) {
				sum += Adata[i][k] * Bdata[k][j];
				//���� �ִ� sum �� aij * bji + aiu * b ui �̹Ƿ� sum �� ������
			}
			Sigmadata[i][j] = sum;
			//for ���� �������� i j ��°�� ���� ���������̹Ƿ� �Ҵ�
		}
	}

	printf("\n�Է¹��� ����� ���� ��� \n"); //����� ����ϴ� �κ�
	for (int i = 0; i < Arow; i++) {
		for (int j = 0; j < Bcolum; j++) {
			printf("%d ", Sigmadata[i][j]);
		}
		printf("\n");
	}


}