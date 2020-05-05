#include <stdio.h>

int IsEven(int number)
{
    if (number % 2 == 0)
        return 1;
    else
        return 0;
}

int FibonacciSeriesSum(int MaximumNumber)
{
    int Sum = 0, FirstTerm=0, SecondTerm=1, NextTerm;
    NextTerm = FirstTerm + SecondTerm;

    while(NextTerm < MaximumNumber)
    {
        NextTerm = SecondTerm+FirstTerm;
        if(IsEven(NextTerm) && NextTerm < MaximumNumber)
            Sum = Sum + NextTerm;
        FirstTerm = SecondTerm;
        SecondTerm = NextTerm;

    }

    return Sum;
}
int main()
{
    int InputNumber;
    printf("Enter a number: ");
    scanf("%d", &InputNumber);
    printf("The sum of the even terms from the Fibonacci series which do not exceed %d is %d" ,InputNumber, FibonacciSeriesSum(InputNumber));
    return 0;

}