#include <stdio.h>
#include <stdlib.h>

int x = 0, y = 0;
int xx = 8, yy = 8;
int di = 1;
int dd = 0;
// 1 ��������� ����
// 2 ��������� ����
// 3 ��������� ����
// 4 ��������� ����


int main(void)
{
	FILE* fp;
	char str[9][20];
	char m[9][10];

	fp = fopen("miro.txt", "r");

	if (fp == NULL)
	{
		printf("������ ������ �����ϴ�. \n");
		return 0;
	}

	fseek(fp, 0, SEEK_SET);
	int i = 0, k = 0;

	while (1)
	{
		fgets(str[i], sizeof(str), fp);
		if (feof(fp))
		{
			printf("i�� ���� %d  k�� ���� %d \n", i, k);
			break;
		}

		for (int j = 0; j < 20; j++)
		{
			if (str[i][j] == '\n') {
				m[8 - i][k] = '\n';
				k = 0;
				break;
			}

			if (str[i][j] == ' ') {
				// �к��ڴ� �����̽� ���� ' '
			}
			else {
				m[8 - i][k] = str[i][j];
				k++;
			}
		}
		if (i == 8) {
			m[i][9] = NULL;
		}
		i++;
	}


	fclose(fp);

	for (int i = 8; i >= 0; i--) {
		printf("%c %c %c %c %c %c %c %c %c \n", m[i][0], m[i][1], m[i][2], m[i][3], m[i][4], m[i][5], m[i][6], m[i][7], m[i][8]);
	}

	int dr;
	printf("�̷�ã�� ���α׷��� �����մϴ�. \n");
	printf("�̵���ġ�� �Է��ϼ��� ��� �Ǵ� ���������� �� ��ġ���� �̵��մϴ�. \n");
	printf("������ġ �������� ����� 0 \n");
	printf("�����ġ �������� ����� 1 (�� : 0) \n");
	scanf("%d", &dd);

	while (1)
	{
		printf("�̵���ġ�� �Է��ϼ��� ( ����: 1  ����: 2  ������: 3  ����: 4  ����: 5 ) ==>  \n");
		scanf("%d", &dr);
		system("cls");
		printf("Ű�Է��� ������ ��ġ�� x = %d, y = %d �̰� ����ġ�� ���� %c \n", x, y, m[x][y]);
		if (dr == 5) break;

		/************************************/
		if (dd)
		{
			switch (di)
			{
			case 1:
				printf("���� �������Դϴ� \n");
				switch (dr)
				{
				case 1:
					printf("������⿡�� ���� \n");
					break;
				case 2:
					printf("������⿡�� ��ȸ�� \n");
					break;
				case 3:
					printf("������⿡�� ��ȸ�� \n");
					break;
				case 4:
					printf("������⿡�� ���� \n");
					break;
				default:
					break;
				}
				break;

			case 2:
				printf("���� ��ȸ�� ���Դϴ� \n");
				switch (dr)
				{
				case 1:
					printf("������⿡�� ���� \n");
					dr = 2;
					break;
				case 2:
					printf("������⿡�� ��ȸ�� \n");
					dr = 4;
					break;
				case 3:
					printf("������⿡�� ��ȸ�� \n");
					dr = 1;
					break;
				case 4:
					printf("������⿡�� ���� \n");
					dr = 3;
					break;
				default:
					break;
				}
				break;
			case 3:
				printf("���� ��ȸ�� ���Դϴ� \n");
				switch (dr)
				{
				case 1:
					printf("������⿡�� ���� \n");
					dr = 3;
					break;
				case 2:
					printf("������⿡�� ��ȸ�� \n");
					dr = 1;
					break;
				case 3:
					printf("������⿡�� ��ȸ�� \n");
					dr = 4;
					break;
				case 4:
					printf("������⿡�� ���� \n");
					dr = 2;
					break;
				default:
					break;
				}
				break;
			case 4:
				printf("���� �ڷ� �̵����Դϴ� \n");
				switch (dr)
				{
				case 1:
					printf("������⿡�� ���� \n");
					dr = 4;
					break;
				case 2:
					printf("������⿡�� ��ȸ�� \n");
					dr = 3;
					break;
				case 3:
					printf("������⿡�� ��ȸ�� \n");
					dr = 2;
					break;
				case 4:
					printf("������⿡�� ���� \n");
					dr = 1;
					break;
				default:
					break;
				}
				break;
			default:
				printf("1~ 4 �������� �����ּ��� \n");
				break;
			}
			di = dr;
		}


		switch (dr)
		{
			char mm;
		case 1:

			if (y == yy) {
				printf("�ֻ���Դϴ� �ö󰥰��� �����ϴ�\n"); break;
			}
			printf("���� ���� \n");
			mm = m[y + 1][x];
			switch (mm)
			{
			case 'o':
				y++;
				break;
			case 'x':
				printf("************ ������ �����ϼ� �����ϴ�. ************\n");
				break;
			case 'S':
				y++;
				printf("������� ��ġ �Ͽ����ϴ� \n");
				break;
			case 'F':
				printf("������� ���� �Ͽ����ϴ� \n");
				return 0;
			default:
				break;
			}
			break;
		case 2:
			printf("���� ���� \n");
			if (x == 0) { printf("���� ��ġ�� ���� ���ʿ� �ֽ��ϴ�. \n");  break; }
			mm = m[y][x - 1];

			switch (mm)
			{
			case 'o':
				x--;
				break;
			case 'x':
				printf("************ ������ �����ϼ� �����ϴ�. ************\n");
				break;
			case 'S':
				x--;
				printf("������� ��ġ �Ͽ����ϴ� \n");
				break;
			case 'F':
				printf("������� ���� �Ͽ����ϴ� \n");
				return 0;
			default:
				break;
			}
			break;
		case 3:
			printf("���� ������ \n");
			if (x == xx) { printf("���� ��ġ�� ���� �����ʿ� �ֽ��ϴ�. \n");  break; }

			mm = m[y][x + 1];
			switch (mm)
			{
			case 'o':
				x++;
				break;
			case 'x':
				printf("************ ������ �����ϼ� �����ϴ�. ************\n");
				break;
			case 'S':
				x++;
				printf("������� ��ġ �Ͽ����ϴ� \n");
				break;
			case 'F':
				printf("������� ���� �Ͽ����ϴ� \n");
				return 0;
			default:
				break;
			}
			break;


		case 4:
			printf("���� ���� \n");
			if (y == 0) { printf("���� ��ġ�� ���� �ٴڿ� �ֽ��ϴ�. \n");  break; }

			mm = m[y - 1][x];
			switch (mm)
			{
			case 'o':
				y--;
				break;
			case 'x':
				printf("************ ������ �����ϼ� �����ϴ�. ************\n");
				break;
			case 'S':
				y--;
				printf("������� ��ġ �Ͽ����ϴ� \n");
				break;
			case 'F':
				printf("������� ���� �Ͽ����ϴ� \n");
				return 0;
			default:
				break;
			}
		default:
			break;
		}
		printf("Ű�Է��� ������ ��ġ�� x = %d, y = %d �̰� ����ġ�� ���� %c \n", x, y, m[x][y]);
	}

	return 0;
}