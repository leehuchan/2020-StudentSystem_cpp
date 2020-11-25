#include <iostream>
using namespace std;

#define NAME_SIZE 10             //�̸�
#define ID_SIZE 10               //�й�
#define STUDENT_MAX 100          //�л� ��
#define DEPARTMENT_SIZE 20       //�а�
#define PHONE_SIZE 20            //��ȭ��ȣ
#define PROFESSOR  10            //����
#define CONSULTING 10            //�������

struct Student
{
	//�л� �����͸� ������ ����ü
	char strName[NAME_SIZE];               //�̸�
	char strDepartment[DEPARTMENT_SIZE];   //�а�
	char strID[ID_SIZE];                   //�й�
	char strPhone[PHONE_SIZE];             //��ȭ��ȣ
	char professor[PROFESSOR];             //��������
	char consulting[CONSULTING];           //�������

	//��հ��� �������� ���� ������
	int DB;                                //DB ����
	int C;                                 //C���α׷��� ����
	int AI;                                //AI ����
	int ESP;                               //ESP ����
	int total;                             //�հ� ����
	double avg;                             //��� ����

};

double totalAvg(int count, Student st[]); //��ü �л��� ��������� ���ϴ� �Լ�.
void consultionCheck(char strProf[], int count, Student st[]); //Ư�� ������ ���� ��ü�л��� ��������� Ȯ���ϴ� �Լ�.

int main()
{

	Student StudentArr[STUDENT_MAX] = {}; 
	char strName[NAME_SIZE] = {};
	char strProf[NAME_SIZE] = {};
	char strDepartment[DEPARTMENT_SIZE] = {};
	char strID[ID_SIZE] = {};
	char strPhone[PHONE_SIZE] = {};
	char professor[PROFESSOR] = {};
	char consulting[CONSULTING] = {};

	int StudentCount = 0;

	int Menu = NULL;

	while (true)
	{
		// �޴� ���
		cout << "\n ======== <����> �޴��� �Է����ּ���. ========" << endl;
		cout << " 1. �л� ���  " << endl;
		cout << " 2. �л� �˻�  " << endl;
		cout << " 3. �л� ����  " << endl;
		cout << " 4. ���������л� ����Ʈ  " << endl;
		cout << " 5. �������� ��� ���� Ȯ��  " << endl;
		cout << " 6. ���α׷� ���� \n\n " << endl;


		cout << " �޴��� �����ϼ��� : ";

		cin >> Menu;

		switch (Menu) 
		{
		case 1: {
			cout << "\n ======== <���> �л������� �Է����ּ���. ========" << endl;

			if (StudentCount == STUDENT_MAX) {
				cout << "�Է°����� �л� �����͸� �ʰ��Ͽ����ϴ�.\n";
				break;
			}

			//�л������� ����Ѵ�. �̸�, �а�, �й�, ����, ��ȭ��ȣ, ��������, ������� 
			cout << "�̸� : ";
			cin >> StudentArr[StudentCount].strName;

			cin.ignore(1024, '\n');            //cin �� �� ���� ���۷� �Է��ϴµ� �̸� ����ֱ� ����(���� �Է� �Ҷ��� ��� X)              

			cout << "�й� : ";
			cin.getline(StudentArr[StudentCount].strID, ID_SIZE);

			cout << "�а� : ";
			cin.getline(StudentArr[StudentCount].strDepartment, DEPARTMENT_SIZE);

			cout << "��ȭ��ȣ : ";
			cin.getline(StudentArr[StudentCount].strPhone, PHONE_SIZE);

			cout << "�������� : ";
			cin.getline(StudentArr[StudentCount].professor, PROFESSOR);

			
			cout << "�������(T,F) : ";
			cin.getline(StudentArr[StudentCount].consulting, PROFESSOR);


			cout << "DB ���� : ";
			cin >> StudentArr[StudentCount].DB;

			cout << "C ���α׷��� ���� : ";
			cin >> StudentArr[StudentCount].C;

			cout << "AI ���� : ";
			cin >> StudentArr[StudentCount].AI;

			cout << "ESP ���� : ";
			cin >> StudentArr[StudentCount].ESP;

			//������ ���� ���Ѵ�.
			StudentArr[StudentCount].total =
				StudentArr[StudentCount].DB +
				StudentArr[StudentCount].C +
				StudentArr[StudentCount].AI +
				StudentArr[StudentCount].ESP;
			
			//������ ����� ���Ѵ�.
			StudentArr[StudentCount].avg =
				StudentArr[StudentCount].total / 4.0;

			StudentCount++;
			cout << "======== �л� �߰��� �Ϸ�Ǿ����ϴ�. ========\n" << endl;

			break;
		}
		case 2: {
			cout << "\n======== <�˻�> �л��̸��� �Է����ּ���. ========\n" << endl;

			cin.ignore(1024, '\n');
			cout << "�̸��� �˻��ϼ���. : ";
			cin.getline(strName, NAME_SIZE); //�̸��� �Է� ����.


			for (int i = 0; i <= StudentCount; i++)
			{
				if (strcmp(StudentArr[i].strName, strName))
				{
					cout << "�̸�:" << StudentArr[i].strName;
					cout << "\t�а�:" << StudentArr[i].strDepartment;
					cout << "\t�й�:" << StudentArr[i].strID;
					cout << "\t��ȭ��ȣ:" << StudentArr[i].strPhone;
					cout << "\t ��������:" << StudentArr[i].professor;
					cout << "\t �������:" << StudentArr[i].consulting;
					cout << "\t �������:" << StudentArr[i].avg;
					cout << "\t DB ����(100��):" << StudentArr[i].DB;
					cout << "\tC ���α׷��� ����(100��):" << StudentArr[i].C;
					cout << "\tAI ����(100��):" << StudentArr[i].AI;
					cout << "\tESP ����(100��):" << StudentArr[i].ESP << "\n\n";
					break;
				}
		
				cout << "\n======== �л������Ͱ� �������� �ʽ��ϴ�.========\n\n" << endl;
			}	
			break;				
		}
		case 3: {
			//�л� ����
			cout << "\n======== <����> ������ �л��� �й��� �Է����ּ���. ========" << endl;

			cin.ignore(1024, '\n');
			cout << "������ �л��� �й��� �Է� : ";
			cin.getline(strID, ID_SIZE);

			for (int i = 0; i < StudentCount; ++i)
			{
				if (strcmp(StudentArr[i].strID, strID) == 0)
				{
					for (int j = i; j < StudentCount - 1; ++j)
						StudentArr[i] = StudentArr[i + 1];
				}
				--StudentCount;
				cout << "�ش� �й��� �л������� �����Ǿ����ϴ�." << endl;
				break;
			}
			cout << "�ش� �й��� �л������� �����ϴ�. " << endl;
		}
		case 4:
		{	
			//���������л� ����Ʈ
			cout << endl;
			for (int i = 0; i < StudentCount; i++) {
				if (StudentArr[i].avg < totalAvg(StudentCount, StudentArr)) {
					cout<<StudentArr[i].strName<<" �л��� ����� "<<StudentArr[i].avg<<" �� ��ü��պ��� �����ϴ�." << endl;
				}
				cout << "=======�������� �л��� �����ϴ�.=======" << endl;
			}	
			break;
		}
	
		case 5: {
			//�������� ��� ���� Ȯ��
			cout << "\n======== ���������� �̸��� �Է����ּ���. ========\n" << endl;

			cin.ignore(1024, '\n');
			cout << "�������� �̸��� �˻��ϼ���. : ";
			cin.getline(strProf, NAME_SIZE); //�̸��� �Է� ����.

			consultionCheck(strProf, StudentCount, StudentArr);

			break;
		}

		case 6: {		
			//���α׷� ����
			cout << "\n======== ���α׷��� ����Ǿ����ϴ�. ========\n\n" << endl;
			return 0;
		}
		default: {
			cout << "\n======== �޴��� �߸� �Է��Ͽ����ϴ�. ========\n\n" << endl;
			break; 
		}
		
		int Menu = NULL;

		}
	
	}
}

double totalAvg(int count, Student st[]) {
	double all_avg = 0.0;
	for (int i = 0; i <= count; i++) {
		all_avg += st[i].total;
	}
	return (all_avg / count+1);
}

void consultionCheck(char strProf[], int count, Student st[])
{
	for (int i = 0; i <= count; i++) {
		if (strcmp(st[i].professor, strProf)) {
			cout << st[i].professor << "���������� " << st[i].strName << " �л� ��������� " << st[i].consulting << "�Դϴ�." << endl;
		}
	}
}
