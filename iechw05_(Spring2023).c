#include <stdio.h>

void StartingComment() //반환 값이 없기 때문에 void를 사용
{
    printf("This program keeps track of your monthly budget\n");
    printf("Please enter the following:\n");
}

float getMonthlyIncome() //getMonthlyIncome 함수 선언
{
    float mi; //mi 변수 선언
    printf("\tYour monthly income: ");
    scanf("%f", &mi);// float형 반환문자를 적고, 변수mi에 값 입력
    return mi;//입력한 mi를 반환
}

float getBudgetLiving() // getBudgetLiving 함수 선언
{
    float bl; // bl 변수 선언
    printf("\tYour budgeted living expenses: "); 
    scanf("%f", &bl); // float형 반환문자를 적고, 변수bl에 값 입력
    return bl;//입력한 bl를 반환
}

float getActualLiving() //getActualLiving 함수 선언
{
    float ale; // ale 변수 선언
    printf("\tYour actual living expenses: ");
    scanf("%f", &ale);//float형 반환문자를 적고, 변수ale에 값 입력
    return ale;//입력한 ale를 반환
}

float getActualTax() //getActualTax 함수 선언
{
    float atw; // atw 변수 선언
    printf("\tYour actual taxes withheld: ");
    scanf("%f", &atw);// float형 반환문자를 적고, 변수atw에 값 입력
    return atw;//입력한 atw를 반환
}

float getActualTithing()//getActualTithing 함수 선언
{
    float ato;// ato 변수 선언
    printf("\tYour actual tithe offerings: ");
    scanf("%f", &ato);// float형 반환문자를 적고, 변수ato에 값 입력
    return ato;//입력한 ato를 반환
}

float getActualOther()//getActualOther 함수 선언
{
    float aoe; //aoe 변수 선언
    printf("\tYour actual other expenses: ");
    scanf("%f", &aoe);// float형 반환문자를 적고, 변수aoe에 값 입력
    return aoe;//입력한 aoe를 반환
}

void followingmonthlyexpenses()//반환 값이 없기 때문에 void를 사용
{
    printf("\nThe following is a report on your monthly expenses\n");
}

float Tithing(float budgettithe) { //Tithing함수에 budgetithe라는 매개변수 선언
    float Tithing = budgettithe * 0.1; //Tithing이라는 변수에 받은 budgettithe에 0.1 곱한 것을 Tithing에 할당
    return Tithing;// Tithing 반환
}

float differ(float mi, float atw, float ato, float ale, float aoe)// differ 함수에 mi,atw,ato,ale,aoe 라는 매개변수 선언
{
    float differ = mi - atw - ato - ale - aoe; //differ라는 변수에 받은 mi-atw-ato-ale-aoe를 differ에 할당

    return differ;//differ 반환
}

float calculateTax(float monthlyIncome) {//월 예산을 가져와서 계산해야하기 때문에 매개변수를 monthlyIncome로 선언
    float yearlyIncome = monthlyIncome * 12;//월 값을 년 값인 조건으로 계산하기 때문에 변수 yearlyIncome는 변수monthlyIncome에 12를 곱함 값이라고 선언
    float yearlyTax = 0; //yearlyTax를 초기화 한다
    float monthlytax = 0;//monthlytax를 초기화 한다

    if (yearlyIncome >= 0 && yearlyIncome < 15100) //위의 변수 yearlyIncome의 범위가 만족한다면 
    {
        yearlyTax = yearlyIncome * 0.1;//10% of the amount over 0% 실행
        
    }

    else if (yearlyIncome >= 15100 && yearlyIncome < 61300)//위의 변수 yearlyIncome의 범위가 만족한다면
    {
        yearlyTax = ((1510 + (yearlyIncome - 15100) * 0.15));//1510 plus 15% of the amount over 15100 실행

    }
    else if (yearlyIncome >= 61300 && yearlyIncome < 123700)//위의 변수 yearlyIncome의 범위가 만족한다면
    {
        yearlyTax = ((8440 + (yearlyIncome - 61300) * 0.25));//8440 plus 25% of the amount over 61300 실행
    }

    else if (yearlyIncome >= 123700 && yearlyIncome < 188450)//위의 변수 yearlyIncome의 범위가 만족한다면
    {
        yearlyTax = ((24040 + (yearlyIncome - 123700) * 0.28));//24040 plus 28% of the amount over 123700 실행
    }

    else if (yearlyIncome >= 188450 && yearlyIncome < 336550)//위의 변수 yearlyIncome의 범위가 만족한다면
    {
        yearlyTax = ((42170 + (yearlyIncome - 42170) * 0.33));//421710 plus 38% of the amount over 188450 실행
    }

    else if (yearlyIncome >= 336550)//위의 변수 yearlyIncome의 범위가 만족한다면
    {
        yearlyTax = ((91043 + (yearlyIncome - 336550) * 0.35));//91043 plus 35% of the amount over 336550 실행
    }

    monthlytax = yearlyTax / 12; //월 값을 구할 때는 년 값을 12로 나눠주기 때문에 변수 monthlytax가 yearlyTax/12와 같다고 선언
    return monthlytax; //monthlytax 반환
}


void printBudget(float mi,float ale, float atw, float ato, float bl, float aoe)//printBudget라는 함수에 mi,ale,atw,ato,bl,aoe 라는 매개변수 선언
{
    float bt;//bt변수 선언
    bt = calculateTax(mi);//입력된 mi (월 예산)을 매개변수에 넣어 호출 하고 그에 대한 값을 할당
    printf("Item                  Budget          Actual\n");
    printf("=============== =============== =================\n");
    printf("Income          $     1000.00   $    %.2f\n", mi);//입력된 변수의 값 출력
    printf("Taxes           $      %.2f   $     %.2f\n", bt, atw);//입력된 변수의 값 출력
    printf("Tithing         $      100.00   $     %.2f\n", ato); //입력된 변수의 값 출력
    printf("Living          $      %.2f   $     %.2f\n", bl, ale);//입력된 변수의 값 출력
    printf("Other           $      150.00   $     %.2f\n", aoe);//입력된 변수의 값 출력
    printf("=============== =============== =================\n");

    float diff = differ(mi, atw, ato, ale, aoe); //위에서 지정한 변수differ가 변수diff와 같다고 선언하고 매개변수 안에 mi,atw,ato,ale,aoe 값을 호출
    printf("Difference      $        0.00   $     %.2f\n", diff);//입력된 변수의 값 출력
}

int main() {//main 함수 시작
   //main 함수를 실행하고 위의 함수들을 호출하고 실행합니다 그 다음 다시 반환을 해주고 나머지 main함수를 실행합니다
    StartingComment();
    float mi = getMonthlyIncome();
    float bl = getBudgetLiving();
    float ale = getActualLiving();
    float atw = getActualTax();
    float ato = getActualTithing();
    float aoe = getActualOther();
    followingmonthlyexpenses();
    printBudget(mi, ale, atw, ato, bl, aoe);

    return 0;
}