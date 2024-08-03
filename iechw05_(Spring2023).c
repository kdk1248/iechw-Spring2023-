#include <stdio.h>

void StartingComment() //��ȯ ���� ���� ������ void�� ���
{
    printf("This program keeps track of your monthly budget\n");
    printf("Please enter the following:\n");
}

float getMonthlyIncome() //getMonthlyIncome �Լ� ����
{
    float mi; //mi ���� ����
    printf("\tYour monthly income: ");
    scanf("%f", &mi);// float�� ��ȯ���ڸ� ����, ����mi�� �� �Է�
    return mi;//�Է��� mi�� ��ȯ
}

float getBudgetLiving() // getBudgetLiving �Լ� ����
{
    float bl; // bl ���� ����
    printf("\tYour budgeted living expenses: "); 
    scanf("%f", &bl); // float�� ��ȯ���ڸ� ����, ����bl�� �� �Է�
    return bl;//�Է��� bl�� ��ȯ
}

float getActualLiving() //getActualLiving �Լ� ����
{
    float ale; // ale ���� ����
    printf("\tYour actual living expenses: ");
    scanf("%f", &ale);//float�� ��ȯ���ڸ� ����, ����ale�� �� �Է�
    return ale;//�Է��� ale�� ��ȯ
}

float getActualTax() //getActualTax �Լ� ����
{
    float atw; // atw ���� ����
    printf("\tYour actual taxes withheld: ");
    scanf("%f", &atw);// float�� ��ȯ���ڸ� ����, ����atw�� �� �Է�
    return atw;//�Է��� atw�� ��ȯ
}

float getActualTithing()//getActualTithing �Լ� ����
{
    float ato;// ato ���� ����
    printf("\tYour actual tithe offerings: ");
    scanf("%f", &ato);// float�� ��ȯ���ڸ� ����, ����ato�� �� �Է�
    return ato;//�Է��� ato�� ��ȯ
}

float getActualOther()//getActualOther �Լ� ����
{
    float aoe; //aoe ���� ����
    printf("\tYour actual other expenses: ");
    scanf("%f", &aoe);// float�� ��ȯ���ڸ� ����, ����aoe�� �� �Է�
    return aoe;//�Է��� aoe�� ��ȯ
}

void followingmonthlyexpenses()//��ȯ ���� ���� ������ void�� ���
{
    printf("\nThe following is a report on your monthly expenses\n");
}

float Tithing(float budgettithe) { //Tithing�Լ��� budgetithe��� �Ű����� ����
    float Tithing = budgettithe * 0.1; //Tithing�̶�� ������ ���� budgettithe�� 0.1 ���� ���� Tithing�� �Ҵ�
    return Tithing;// Tithing ��ȯ
}

float differ(float mi, float atw, float ato, float ale, float aoe)// differ �Լ��� mi,atw,ato,ale,aoe ��� �Ű����� ����
{
    float differ = mi - atw - ato - ale - aoe; //differ��� ������ ���� mi-atw-ato-ale-aoe�� differ�� �Ҵ�

    return differ;//differ ��ȯ
}

float calculateTax(float monthlyIncome) {//�� ������ �����ͼ� ����ؾ��ϱ� ������ �Ű������� monthlyIncome�� ����
    float yearlyIncome = monthlyIncome * 12;//�� ���� �� ���� �������� ����ϱ� ������ ���� yearlyIncome�� ����monthlyIncome�� 12�� ���� ���̶�� ����
    float yearlyTax = 0; //yearlyTax�� �ʱ�ȭ �Ѵ�
    float monthlytax = 0;//monthlytax�� �ʱ�ȭ �Ѵ�

    if (yearlyIncome >= 0 && yearlyIncome < 15100) //���� ���� yearlyIncome�� ������ �����Ѵٸ� 
    {
        yearlyTax = yearlyIncome * 0.1;//10% of the amount over 0% ����
        
    }

    else if (yearlyIncome >= 15100 && yearlyIncome < 61300)//���� ���� yearlyIncome�� ������ �����Ѵٸ�
    {
        yearlyTax = ((1510 + (yearlyIncome - 15100) * 0.15));//1510 plus 15% of the amount over 15100 ����

    }
    else if (yearlyIncome >= 61300 && yearlyIncome < 123700)//���� ���� yearlyIncome�� ������ �����Ѵٸ�
    {
        yearlyTax = ((8440 + (yearlyIncome - 61300) * 0.25));//8440 plus 25% of the amount over 61300 ����
    }

    else if (yearlyIncome >= 123700 && yearlyIncome < 188450)//���� ���� yearlyIncome�� ������ �����Ѵٸ�
    {
        yearlyTax = ((24040 + (yearlyIncome - 123700) * 0.28));//24040 plus 28% of the amount over 123700 ����
    }

    else if (yearlyIncome >= 188450 && yearlyIncome < 336550)//���� ���� yearlyIncome�� ������ �����Ѵٸ�
    {
        yearlyTax = ((42170 + (yearlyIncome - 42170) * 0.33));//421710 plus 38% of the amount over 188450 ����
    }

    else if (yearlyIncome >= 336550)//���� ���� yearlyIncome�� ������ �����Ѵٸ�
    {
        yearlyTax = ((91043 + (yearlyIncome - 336550) * 0.35));//91043 plus 35% of the amount over 336550 ����
    }

    monthlytax = yearlyTax / 12; //�� ���� ���� ���� �� ���� 12�� �����ֱ� ������ ���� monthlytax�� yearlyTax/12�� ���ٰ� ����
    return monthlytax; //monthlytax ��ȯ
}


void printBudget(float mi,float ale, float atw, float ato, float bl, float aoe)//printBudget��� �Լ��� mi,ale,atw,ato,bl,aoe ��� �Ű����� ����
{
    float bt;//bt���� ����
    bt = calculateTax(mi);//�Էµ� mi (�� ����)�� �Ű������� �־� ȣ�� �ϰ� �׿� ���� ���� �Ҵ�
    printf("Item                  Budget          Actual\n");
    printf("=============== =============== =================\n");
    printf("Income          $     1000.00   $    %.2f\n", mi);//�Էµ� ������ �� ���
    printf("Taxes           $      %.2f   $     %.2f\n", bt, atw);//�Էµ� ������ �� ���
    printf("Tithing         $      100.00   $     %.2f\n", ato); //�Էµ� ������ �� ���
    printf("Living          $      %.2f   $     %.2f\n", bl, ale);//�Էµ� ������ �� ���
    printf("Other           $      150.00   $     %.2f\n", aoe);//�Էµ� ������ �� ���
    printf("=============== =============== =================\n");

    float diff = differ(mi, atw, ato, ale, aoe); //������ ������ ����differ�� ����diff�� ���ٰ� �����ϰ� �Ű����� �ȿ� mi,atw,ato,ale,aoe ���� ȣ��
    printf("Difference      $        0.00   $     %.2f\n", diff);//�Էµ� ������ �� ���
}

int main() {//main �Լ� ����
   //main �Լ��� �����ϰ� ���� �Լ����� ȣ���ϰ� �����մϴ� �� ���� �ٽ� ��ȯ�� ���ְ� ������ main�Լ��� �����մϴ�
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