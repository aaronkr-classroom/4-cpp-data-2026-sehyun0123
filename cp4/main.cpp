//main.cpp

//중간고사,기말고사, 그리고 과제 점수 몇 개를 받고
//마지막 평균 결과 점수를 계산하기

#include<algorithm> // sort()
#include<ios>
#include<iostream>
#include<iomanip> // setprecision()
#include<string>
#include<stdexcept>
#include<vector>
#include "Student_info.h"
#include "grade.h"


using namespace std;

typedef vector<double> :: size_type vec_sz;
typedef vector<Student_info>::size_type si_sz;

 //함수 원형 정의문
double median(vector<double>);

int main(void) 
{
	// 새로운 구조 자료형 선언
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	cout << "For every student, enter: " << endl <<
		"name midterm fianl hw1 hw2 ..." << endl;
	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	//학생 정보를 알파벳순으로 정렬
	sort(students.begin(), students.end(), compare);

	//모든 학생들의 결과를 출력
	for (si_sz i = 0; i != students.size(); i++) {
		//이름과 오른쪽 공백을 포함하여 maxlen + 1개의 문자를 출력
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

		//최종 점수를 계산하여 출력
		try {
			double final_grade = grade(students[i]); // NEW 계산하는 함수 grade()
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}

	// NEW 함수 read_hw()
	read_hw(cin, homework);
	// 종합 점수를 계산해 생성
	

	return 0; 
}
//입력 스트림에서 과제 점수를 읽어서 vector<double>에 넣음
istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {
		//이전 내용을 제거
		hw.clear();

		//과제 점수를 읽음
		double x;

		while (in >> x) {
			hw.push_back(x);
		}

		//다음 학생의 점수 입력 작업을 고려해 스트림을 지움
		in.clear();
	}
	return in;
}
