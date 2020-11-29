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

double totalAvg(int count, Student st[]); 
void consultionCheck(char strProf[], int count, Student st[]); 

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

		while(cin.fail()) {		
			cout << "\n======== 잘못입력했습니다. 메뉴를 다시 입력해 주세요. =========" << endl;
			cout << "\n======== <메인> 메뉴를 입력해주세요. ========" << endl;
			cout << " 1. 학생 등록  " << endl;
			cout << " 2. 학생 검색  " << endl;
			cout << " 3. 학생 삭제  " << endl;
			cout << " 4. 성적부진학생 리스트  " << endl;
			cout << " 5. 지도교수 상담 유무 확인  " << endl;
			cout << " 6. 프로그램 종료 \n\n " << endl;

			cin.clear();
			cin.ignore();
			cin >> Menu;
		}

		switch (Menu) 
		{
		case 1:
		{
			system("cls");
			//학생 등록
			cout << "\n======== <등록> 학생정보를 입력해주세요. ========" << endl;

			if (StudentCount == STUDENT_MAX) {
				cout << "\n======== 입력가능한 학생 데이터를 초과하였습니다. ========" << endl;
				break;
			}

			
			cout << "이름 : ";
			cin >> StudentArr[StudentCount].strName;


			cin.ignore(1024, '\n');          

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
			*StudentArr[StudentCount].consulting = toupper(*StudentArr[StudentCount].consulting); 
			//입력받은 상담유무의 소문자를 대문자로 바꿔주는 코드

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
		case 2:
		{
			system("cls");
			//학생 검색
			cout << "\n======== <검색> 검색 할 학생의 학번을 입력해주세요. ========\n" << endl;
			bool seachCheck = false;

			cin.ignore(1024, '\n');
			cout << "검색 할 학생의 학번을 입력 : ";
			cin.getline(strID, ID_SIZE);

			for (int i = 0; i < StudentCount; ++i)
			{				
				if (strcmp(StudentArr[i].strID,strID)==0)
				{
					cout << "\n이름:" << StudentArr[i].strName;
					cout << "\t학과:" << StudentArr[i].strDepartment;
					cout << "\t학번:" << StudentArr[i].strID;
					cout << "\t전화번호:" << StudentArr[i].strPhone;
					cout << "\t 지도교수:" << StudentArr[i].professor;
					cout << "\t 상담유무:" << StudentArr[i].consulting;
					cout << "\t DB 점수:" << StudentArr[i].DB;
					cout << "\tC 프로그래밍 점수:" << StudentArr[i].C;
					cout << "\tAI 점수:" << StudentArr[i].AI;
					cout << "\tESP 점수:" << StudentArr[i].ESP;
					cout << "\t평점:" << StudentArr[i].avg<< "\n";
					seachCheck = true;  
				}
			}
			if (!seachCheck) {
				cout << "\n=======검색된 학생정보가 없습니다.=======\n" << endl;
			}
			seachCheck = false;
			break; 
		}
		case 3:
		{
			system("cls");
			//학생 삭제
			cout << "\n======== <삭제> 삭제할 학생의 학번을 입력해주세요. ========\n" << endl;
			
			bool deleteCheck = false;
			cin.ignore(1024, '\n');
			cout << "삭제할 학생의 학번을 입력 : ";
			cin.getline(strID, ID_SIZE);

			for (int i = 0; i < StudentCount; ++i)
			{
				if (strcmp(StudentArr[i].strID, strID) == 0)
				{
					for (int j = i; j < StudentCount - 1; ++j)
					{
						StudentArr[i] = StudentArr[i + 1];
					}
					--StudentCount;
					cout << "\n======= 해당 학번의 학생정보가 삭제되었습니다. ========" << endl;
					deleteCheck = true;
				}
			}
			if (!deleteCheck) {
				cout << "\n=======해당 학번의 학생정보가 없습니다.=======\n" << endl;
			}
			deleteCheck = false;
			break;
		}
		case 4:
		{	
			system("cls");
			//성적부진학생 리스트
			bool avgCheck = false;
			cout << endl;
			for (int i = 0; i < StudentCount; i++) {
				if (StudentArr[i].avg < totalAvg(StudentCount, StudentArr)) {
					cout<<StudentArr[i].strName<<" 학생의 평균은 "<<StudentArr[i].avg<<" 로 전체평균인"<<totalAvg(StudentCount,StudentArr)<<" 보다 낮습니다.\n" << endl;
					avgCheck = true;
				}
			}	
			if (!avgCheck) {
				cout << "\n=======성적부진 학생이 없습니다.=======\n" << endl;
			}
			avgCheck = false; 

			break;
		}
	
		case 5:
		{
			system("cls");
			//지도교수 상담 유무 확인
			cout << "\n======== 지도교수의 이름을 입력해주세요. ========\n" << endl;
			cin.ignore(1024, '\n');
			cout << "지도교수 이름을 검색하세요. : ";
			cin.getline(strProf, NAME_SIZE);
			consultionCheck(strProf, StudentCount, StudentArr);
			break;
		}
		case 6:
		{		
			//프로그램 종료
			cout << "\n======== 프로그램이 종료되었습니다. ========\n\n" << endl;
			return 0;
		}
		default: {
			cout << "\n======== 잘못입력했습니다. 메뉴를 다시 입력해 주세요. ========" << endl;
		}			
		Menu = NULL;
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
	bool profCheck = false;

	cout << endl;

	for (int i = 0; i <= count; i++)
	{
		if (strcmp(st[i].professor, strProf) == 0) {
			cout << st[i].professor << " 지도교수의 " << st[i].strName << " 학생 상담유무는 [ " << st[i].consulting << " ] 입니다." << endl;
			profCheck = true;
		}
	}
	if (!profCheck) {
		cout << "\n======== 해당 지도교수가 없습니다. ========" << endl;
	}
}