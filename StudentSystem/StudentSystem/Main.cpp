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

	int number;                            //학생번호

	//평균값을 내기위한 성적 데이터
	int DB;                                //DB 성적
	int C;                                 //C프로그래밍 성적
	int AI;                                //AI 성적
	int ESP;                               //ESP 성적
	int total;                             //합계 성적
	float avg;                             //평균 성적

};

int main()
{

	Student StudentArr[STUDENT_MAX] = {};
	char strName[NAME_SIZE] = {};
	char strDepartment[DEPARTMENT_SIZE] = {};
	char strID[ID_SIZE] = {};
	char strPhone[PHONE_SIZE] = {};
	char professor[PROFESSOR] = {};
	char consulting[CONSULTING] = {};

	int StudentCount = 0;
	int StudentNum = 1;

	int Menu = NULL;

	while (true)
	{
		// 메뉴 출력
		cout << "\n ======== <메인> 메뉴를 입력해주세요. ========" << endl;
		cout << " 1. 학생 등록  " << endl;
		cout << " 2. 학생 검색  " << endl;
		cout << " 3. 성적부진학생 리스트  " << endl;
		cout << " 4. 지도교수 상담 유무 확인  " << endl;
		cout << " 5. 메인으로 돌아가기 " << endl;
		cout << " 6. 프로그램 종료 \n\n" << endl;


		cout << " 메뉴를 선택하세요 : ";

		cin >> Menu;

		switch (Menu) 
		{
		case 1: {
			cout << "\n ======== <등록> 학생정보를 입력해주세요. ========" << endl;

			if (StudentCount == STUDENT_MAX)
				break;

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
				StudentArr[StudentCount].total / 4.f;

			StudentArr[StudentCount].number = StudentNum;

			++StudentNum;
			++StudentCount;
			cout << "======== 학생 추가가 완료되었습니다. ========\n" << endl;

			break;
		}
		case 2: {
			cout << "\n======== <검색> 학생이름을 입력해주세요. ========\n" << endl;

			cin.ignore(1024, '\n');
			cout << "이름을 검색하세요. : ";
			cin.getline(strName, NAME_SIZE);

			for (int i = 0; i < StudentCount; ++i)
			{
				if (strcmp(StudentArr[i].strName, strName) == 0)
				{
					cout << "이름:" << StudentArr[i].strName ;
					cout << "\t학과:" << StudentArr[i].strDepartment;
					cout << "\t학번:" << StudentArr[i].strID;
					cout << "\t전화번호:" << StudentArr[i].strPhone;
					cout << "\t 지도교사:" << StudentArr[i].professor;
					cout << "\t 상담유무:" << StudentArr[i].consulting;
					cout << "\t DB 점수:" << StudentArr[i].DB;
					cout << "\tC 프로그래밍 점수:" << StudentArr[i].C;
					cout << "\tAI 점수:" << StudentArr[i].AI;
					cout << "\tESP 점수:" << StudentArr[i].ESP<<"\n\n";
			
					break;
				}
				else {
					//만약 값이 없다면.
					cout << "\n======== 학생데이터가 존재하지 않습니다. ========\n\n" << endl;
					break;
				}
			}
		}
		case 3: {

		}
		case 4:
		{
			break;
		}
		default: {
			break; 
		}
		
		int Menu = NULL;

		}
	
	}
}