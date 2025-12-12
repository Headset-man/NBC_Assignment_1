#include <iostream>
using namespace std;


// 포션 세팅 함수
void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion = count;
    *p_MPPotion = count;
}
// 레벨업 / 포션 추가 함수
void levelUp(int* p_HPPotion, int* p_MPPotion, int stat[], int SIZE) {

    // 포션 충전
    (*p_HPPotion)++;
    (*p_MPPotion)++;
    cout << " * Level UP! " << endl;
    cout << " * 회복 포션이 각각 1개씩 충전됩니다. " << endl;

    // 스탯 증가
    stat[0] += 10; // HP 증가
    stat[1] += 10; // MP 증가
    stat[2] += 3; // 공격력 증가
    stat[3] += 4; // 방어력 증가
    stat[4] += 2; // 힘 증가
    stat[5] += 3; // 민첩 증가
    stat[6] += 2; // 지능 증가
    stat[7] += 1; // 의지 증가

    cout << "* 스탯이 증가했습니다." << endl;
    cout << "" << endl;
}

int main()
{   // 스탯의 갯수(사이즈)는 총 8개
    const int SIZE = 8;
    int stat[SIZE] = { 0 };
    // stat[0] = HP , stat[1] = MP
    while (1) {
        cout << "HP와 MP를 입력해주세요: " << endl;
        cin >> stat[0] >> stat[1];

        if (stat[0] > 50 && stat[1] > 50) {
            break;
        }
        cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << endl;
    }
    // stat[2] = 공격력 , stat[3] = 방어력 
    while (1) {
        cout << "공격력과 방어력을 입력해주세요: " << endl;
        cin >> stat[2] >> stat[3];

        if (stat[2] > 0 && stat[3] > 0) {
            break;
        }
        cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요." << endl;
    }
    // stat [4] = 힘, stat [5] = 민첩, stat [6] = 지능, stat [7] = 의지
    while (1) {
        cout << "힘, 민첩, 지능, 의지 능력치를 입력해주세요." << endl;
        cin >> stat[4] >> stat[5] >> stat[6] >> stat[7];

        if (stat[4] > 0 && stat[5] > 0 && stat[6] > 0 && stat[7] > 0) {
            break;
            }
            cout << "스테이터스 값이 너무 작습니다.  다시 입력해주세요." << endl;
        }


    // 초기화
    int choice = 0;
    int HPPotion = 0;
    int MPPotion = 0;
    int Pow;
    int Def;
    int Level = 1;

    setPotion(5, &HPPotion, &MPPotion);

    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl;
    cout << "=============================================" << endl;
    cout << "<스탯 관리 시스템>" << endl;
    cout << "1. HP 포션 사용" << endl;
    cout << "2. MP 포션 사용" << endl;
    cout << "3. 공격력 버프" << endl;
    cout << "4. 방어력 버프" << endl;
    cout << "5. 현재 스테이터스" << endl;
    cout << "6. Level up!" << endl;
    cout << "0. 프로그램 종료" << endl;
    // ... (메뉴 출력)

    while (1) {
        cout << "* 번호를 선택해주세요: " << endl;
        cin >> choice;

        if (choice == 0) {
            cout << "* 프로그램을 종료합니다." << endl;
            break;
        }

        // 선택지 1~6
        switch (choice) {
        case 1: // HP 포션 사용
            if (HPPotion <= 0) {
                cout << "                     " << endl; // 가독성을 위한 한 줄 띄움
                cout << "* HP 포션이 부족합니다." << endl;
                continue;
            }
            // 만약 체력의 상한선이 정해져있되 최대 100이고, 포션을 사용했을 경우
            /*if (stat[0] >= 100) {
                cout << "체력이 가득찼습니다!" << endl;
                continue;
            }*/
            stat[0] += 20;
            HPPotion--;
            cout << "                     " << endl;
            cout << "* HP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
            cout << "* 현재 HP: " << stat[0] << endl;
            cout << "* 남은 포션 수: " << HPPotion << endl;
            break;

        case 2: // MP포션 사용
            if (MPPotion <= 0) {
                cout << "                     " << endl;
                cout << "* MP 포션이 부족합니다." << endl;
                continue;
            }
            stat[1] += 20;
            MPPotion--;
            cout << "                     " << endl;
            cout << "* MP가 20 증가되었습니다. 포션이 1개 차감됩니다. " << endl;
            cout << "* 현재 MP: " << stat[1] << endl;
            cout << "* 남은 포션 수: " << MPPotion << endl;
            break;

        case 3: // 공격력 증가
            stat[2] *= 2;
            cout << "                     " << endl;
            cout << "* 공격력이 증가되었습니다." << endl;
            cout << "* 현재 공격력: " << stat[2] << endl;
            break;


        case 4: // 방어력 증가
            stat[3] *= 2;
            cout << "                     " << endl;
            cout << "* 방어력이 증가되었습니다." << endl;
            cout << "* 현재 방어력: " << stat[3] << endl;
            break;


        case 5: // 현재 스텟 출력
            cout << "                     " << endl;
            cout << "===== 현재 스탯 =====" << endl;
            cout << "현재 레벨: " << Level << endl;
            cout << "HP: " << stat[0] << endl;
            cout << "MP: " << stat[1] << endl;
            cout << "공격력 : " << stat[2] << endl;
            cout << "방어력 : " << stat[3] << endl;
            cout << "힘 : " << stat[4] << endl;
            cout << "민첩 : " << stat[5] << endl;
            cout << "지능 : " << stat[6] << endl;
            cout << "의지 : " << stat[7] << endl;
            cout << "=====================" << endl;
            break;


        case 6: // 레벨업 - HP/MP 포션 하나씩 충전, 스탯 증가
            Level++;
            levelUp(&HPPotion, &MPPotion, stat, SIZE);
            break;

        default:
            cout << "                     " << endl;
            cout << "* 잘못된 입력입니다. 다시 입력해주세요." << endl;
            break;
        }
    }
    return 0;
}