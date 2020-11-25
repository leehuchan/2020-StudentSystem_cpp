#include <iostream>
using namespace std;

#define NAME_SIZE 10             //이름
#define ID_SIZE 10               //학번
#define STUDENT_MAX 100          //학생 수
#define DEPARTMENT_SIZE 20       //학과
#define PHONE_SIZE 20            //전화번호
#define PROFESSOR  10            //교수
#define CONSULTING 10            //상담유무

struct Student
{
	//학생 데이터를 저장할 구조체
	char strName[NAME_SIZE];               //이름
	char strDepartment[DEPARTMENT_SIZE];   //학과
	char strID[ID_SIZE];                   //학번
	char strPhone[PHONE_SIZE];             //전화번호
	char professor[PROFESSOR];             //지도교수
	char consulting[CONSULTING];           //상담유무

	//평균값을 내기위한 성적 데이터
	int DB;                                //DB 성적
	int C;                                 //C프로그래밍 성적
	int AI;                                //AI 성적
	int ESP;                               //ESP 성적
	int total;                             //합계 성적
	double avg;                             //평균 성적

};

double totalAvg(int count, Student st[]); //전체 학생의 성적평균을 구하는 함수.
void consultionCheck(char strProf[], int count, Student st[]); //특정 교수에 대한 전체학생의 상담유무를 확인하는 함수.

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
		// 메뉴 출력
		cout << "\n ======== <메인> 메뉴를 입력해주세요. ========" << endl;
		cout << " 1. 학생 등록  " << endl;
		cout << " 2. 학생 검색  " << endl;
		cout << " 3. 학생 삭제  " << endl;
		cout << " 4. 성적부진학생 리스트  " << endl;
		cout << " 5. 지도교수 상담 유무 확인  " << endl;
		cout << " 6. 프로그램 종료 \n\n " << endl;


		cout << " 메뉴를 선택하세요 : ";

		cin >> Menu;

		switch (Menu) 
		{
		case 1: {
			cout << "\n ======== <등록> 학생정보를 입력해주세요. ========" << endl;

			if (StudentCount == STUDENT_MAX) {
				cout << "입력가능한 학생 데이터를 초과하였습니다.\n";
				break;
			}

			//학생정보를 등록한다. 이름, 학과, 학번, 성적, 전화번호, 지도교수, 상담유무 
			cout << "이름 : ";
			cin >> StudentArr[StudentCount].strName;

			cin.ignore(1024, '\n');            //cin 할 때 탭을 버퍼로 입력하는데 이를 비워주기 위함(정수 입력 할때는 상관 X)              

			cout << "학번 : ";
			cin.getline(StudentArr[StudentCount].strID, ID_SIZE);

			cout << "학과 : ";
			cin.getline(StudentArr[StudentCount].strDepartment, DEPARTMENT_SIZE);

			cout << "전화번호 : ";
			cin.getline(StudentArr[StudentCount].strPhone, PHONE_SIZE);

			cout << "지도교수 : ";
			cin.getline(StudentArr[StudentCount].professor, PROFESSOR);

			
			cout << "상담유무(T,F) : ";
			cin.getline(StudentArr[StudentCount].consulting, PROFESSOR);


			cout << "DB 점수 : ";
			cin >> StudentArr[StudentCount].DB;

			cout << "C 프로그래밍 점수 : ";
			cin >> StudentArr[StudentCount].C;

			cout << "AI 점수 : ";
			cin >> StudentArr[StudentCount].AI;

			cout << "ESP 점수 : ";
			cin >> StudentArr[StudentCount].ESP;

			//성적의 합을 구한다.
			StudentArr[StudentCount].total =
				StudentArr[StudentCount].DB +
				StudentArr[StudentCount].C +
				StudentArr[StudentCount].AI +
				StudentArr[StudentCount].ESP;
			
			//성적의 평균을 구한다.
			StudentArr[StudentCount].avg =
				StudentArr[StudentCount].total / 4.0;

			StudentCount++;
			cout << "======== 학생 추가가 완료되었습니다. ========\n" << endl;

			break;
		}
		case 2: {
			cout << "\n======== <검색> 학생이름을 입력해주세요. ========\n" << endl;

			cin.ignore(1024, '\n');
			cout << "이름을 검색하세요. : ";
			cin.getline(strName, NAME_SIZE); //이름을 입력 받음.


			for (int i = 0; i <= StudentCount; i++)
			{
				if (strcmp(StudentArr[i].strName, strName))
				{
					cout << "이름:" << StudentArr[i].strName;
					cout << "\t학과:" << StudentArr[i].strDepartment;
					cout << "\t학번:" << StudentArr[i].strID;
					cout << "\t전화번호:" << StudentArr[i].strPhone;
					cout << "\t 지도교사:" << StudentArr[i].professor;
					cout << "\t 상담유무:" << StudentArr[i].consulting;
					cout << "\t 평균점수:" << StudentArr[i].avg;
					cout << "\t DB 점수(100점):" << StudentArr[i].DB;
					cout << "\tC 프로그래밍 점수(100점):" << StudentArr[i].C;
					cout << "\tAI 점수(100점):" << StudentArr[i].AI;
					cout << "\tESP 점수(100점):" << StudentArr[i].ESP << "\n\n";
					break;
				}
		
				cout << "\n======== 학생데이터가 존재하지 않습니다.========\n\n" << endl;
			}	
			break;				
		}
		case 3: {
			//학생 삭제
			cout << "\n======== <삭제> 삭제할 학생의 학번을 입력해주세요. ========" << endl;

			cin.ignore(1024, '\n');
			cout << "삭제할 학생의 학번을 입력 : ";
			cin.getline(strID, ID_SIZE);

			for (int i = 0; i < StudentCount; ++i)
			{
				if (strcmp(StudentArr[i].strID, strID) == 0)
				{
					for (int j = i; j < StudentCount - 1; ++j)
						StudentArr[i] = StudentArr[i + 1];
				}
				--StudentCount;
				cout << "해당 학번의 학생정보가 삭제되었습니다." << endl;
				break;
			}
			cout << "해당 학번의 학생정보가 없습니다. " << endl;
		}
		case 4:
		{	
			//성적부진학생 리스트
			cout << endl;
			for (int i = 0; i < StudentCount; i++) {
				if (StudentArr[i].avg < totalAvg(StudentCount, StudentArr)) {
					cout<<StudentArr[i].strName<<" 학생의 평균은 "<<StudentArr[i].avg<<" 로 전체평균보다 낮습니다." << endl;
				}
				cout << "=======성적부진 학생이 없습니다.=======" << endl;
			}	
			break;
		}
	
		case 5: {
			//지도교수 상담 유무 확인
			cout << "\n======== 지도교수의 이름을 입력해주세요. ========\n" << endl;

			cin.ignore(1024, '\n');
			cout << "지도교수 이름을 검색하세요. : ";
			cin.getline(strProf, NAME_SIZE); //이름을 입력 받음.

			consultionCheck(strProf, StudentCount, StudentArr);

			break;
		}

		case 6: {		
			//프로그램 종료
			cout << "\n======== 프로그램이 종료되었습니다. ========\n\n" << endl;
			return 0;
		}
		default: {
			cout << "\n======== 메뉴를 잘못 입력하였습니다. ========\n\n" << endl;
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
			cout << st[i].professor << "지도교수의 " << st[i].strName << " 학생 상담유무는 " << st[i].consulting << "입니다." << endl;
		}
	}
}
