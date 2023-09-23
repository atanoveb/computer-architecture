// 학번 : 32202643
// 이름 : 여지훈

#include <stdio.h>
#include <stdlib.h>

// complete
int *calc_in(void);
char calc_operator(void);
int *calc_before(int arr[], int counter, int count_diff);
// incomplete
int *calc(int arr1[], int arr2[], char op, int counter, int count_diff);
int calc_out(void);

int main(void)
{
    // STEP 1-1. 연산을 진행할 첫 번째 임의의 정수 (입력 1/3)
    int *arr1 = calc_in();
    int counter1 = 0;
    for (int i = 0; i < 10000; i++)
    {
        // printf("[arr1의 %d번째 자리 숫자] : %d\n", (i + 1), arr1[i]);

        if (arr1[i] == 10)
        {
            break;
        }
        counter1++;
    }
    // printf("첫 번째 임의의 정수의 자리의 숫자 : %d\n", counter1);

    // STEP 1-2. 연산을 진행할 두 번째 임의의 정수 (입력 2/3)
    int *arr2 = calc_in();
    int counter2 = 0;
    for (int i = 0; i < 10000; i++)
    {
        // printf("[arr2의 %d번째 자리 숫자] : %d\n", (i + 1), arr2[i]);

        if (arr2[i] == 10)
        {
            break;
        }
        counter2++;
    }
    // printf("두 번째 임의의 정수의 자리의 숫자 : %d\n", counter2);

    // STEP 2. 연산을 진행할 기호 (입력 3/3)
    char op = calc_operator();
    printf("입력한 기호 : %c\n", op);

    // STEP 3. 연산 전, 2개의 정수 정렬
    int counter_real = 0;
    int count_diff = 0;
    int *result;
    int *result1;
    int *result2;
    if (counter1 > counter2)
    {
        counter_real = counter1;
        count_diff = counter1 - counter2;
        int *arr_small = (int *)malloc(counter1 * sizeof(int));
        arr_small = calc_before((int *)arr2, counter_real, count_diff); // 더 작은 정수 arr2 전달
        for (int i = 0; i < counter_real; i++)
        {
            *(arr2 + i) = *(arr_small + i);
            // printf("%d\n", *(arr_small + i));
            // printf("작은 임의의 정수의 %d번째 자리 숫자 : %d\n", (i + 1), *(arr2 + i));
        }

        int *result = (int *)malloc(counter_real * sizeof(int));
        result = calc((int *)arr1, (int *)arr2, op, counter_real, count_diff);
    }
    else
    {
        counter_real = counter2;
        count_diff = counter2 - counter1;
        int *arr_small = (int *)malloc(counter2 * sizeof(int));
        arr_small = calc_before((int *)arr1, counter_real, count_diff); // 더 작은 정수 arr1 전달
        for (int i = 0; i < counter_real; i++)
        {
            *(arr1 + i) = *(arr_small + i);
            // printf("%d\n", *(arr_small + i));
            // printf("작은 임의의 정수의 %d번째 자리 숫자 : %d\n", (i + 1), *(arr1 + i));
        }

        int *result = (int *)malloc(counter_real * sizeof(int));
        result = calc((int *)arr2, (int *)arr1, op, counter_real, count_diff);
    }
    // printf("2개의 정수의 자릿수의 차이 : %d\n", count_diff);

    // (연산 진행 전 TEST) 2개의 정수
    // for (int i = 0; i < counter_real; i++)
    // {
    //     printf("[arr1의 %d번째 자리 숫자] : %d\n", (i + 1), arr1[i]);
    // }
    // for (int i = 0; i < counter_real; i++)
    // {
    //     printf("[(    )arr2의 %d번째 자리 숫자] : %d\n", (i + 1), arr2[i]);
    // }

    // STEP 4. 연산
    // STEP 5. 연산 결과 (출력)

    return 0;
}

int *calc_in(void)
{
    // Step 1-1.
    char input[10000];

    printf("계산을 진행할 \"임의의 정수\"를 입력하세요.\n");
    scanf("%s", input);

    // Step 1-2.
    int counter = 0;

    for (int i = 0; i < sizeof(input); i++)
    {
        if (input[i] == '\0')
        {
            break;
        }
        // printf("[%d번째 자리 숫자] : %c\n", (i + 1), input[i]);
        counter++;
    }
    // printf("\"임의의 정수\" : \"%d자리\"의 숫자\n", counter);

    // Step 1-3.
    int *arr = (int *)malloc(counter * sizeof(int));
    for (int i = 0; i < counter + 100; i++)
    {
        arr[i] = input[i] - 48;
        if (input[i] == '\0')
        {
            break;
        }
        // printf("임의의 정수 中 %d번째 자리 숫자 : %d | %c\n", (i + 1), arr[i], input[i]);
    }
    arr[counter] = 10;

    return (int *)arr;
}

char calc_operator(void)
{
    char operator;

    while (1)
    {
        printf("-------- 입력할 수 있는 기호 : \"+\" \"-\" \"*\" \"/\" --------\n");
        printf("(계산을 진행할 \"기호\"를 입력하세요.)\n");
        scanf("%c", &operator);

        if (operator== '+')
        {
            break;
        }
        else if (operator== '-')
        {
            break;
        }
        else if (operator== '*')
        {
            break;
        }
        else if (operator== '/')
        {
            break;
        }
    }

    return operator;
}

int *calc_before(int arr[], int counter, int count_diff)
{

    int *arr_small = (int *)malloc(counter * sizeof(int));
    for (int i = 0; i < counter; i++)
    {
        *(arr_small + (i + count_diff)) = *(arr + i);
        // printf("더 작은 정수의 %d번째 자리 숫자 : %d\n", (i + 1), *(arr_small + i));
    }

    return (int *)arr_small;
}

// In Progress (Incomplete)
int *calc(int arr1[], int arr2[], char op, int counter, int count_diff)
{
    int *result_arr = (int *)malloc(counter * sizeof(int));

    if (count_diff == 0)
    {
        if (*(arr1) > *(arr2))
        {

            for (int i = 0; i < counter; i++)
            {
                *(result_arr + i) = *(arr1 + i) - *(arr2 + i);
                printf("(Result : 뺄셈) 10^%d의 자리 숫자 : %d\n", (counter - i), *(result_arr + i));
            }
        }
        else
        {
            for (int i = 0; i < counter; i++)
            {
                *(result_arr + i) = *(arr2 + i) - *(arr1 + i);
                printf("(Result : 뺄셈) 10^%d의 자리 숫자 : %d\n", (counter - i), *(result_arr + i));
            }
        }
    }
    else // 더 큰 정수 : arr1
    {
        for (int i = 0; i < counter; i++)
        {
            *(result_arr + i) = *(arr1 + i) - *(arr2 + i);
            printf("(Result : 뺄셈) 10^%d의 자리 숫자 : %d\n", (counter - i), *(result_arr + i));
        }
    }
}

// In Progress (Incomplete)
int calc_out(void)
{
}
