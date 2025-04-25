# Instrutions

- 4 * 4 맵이 있다.
- 박스 높이 1 ~ 4 있다.
- 입력 값이 그 위치에서 보이는 박스 개수
- 위 ---- 위 ---- 왼쪽 |||| 오른쪽 ||||
- 이 순서로 입력

만약 숫자가 4이면 그쪽에서 4개가 보여야 함

만약 숫자가 1개면 그쪽에서 1개가 보여야 함

그럴 수 없는 상황이라면 Error\n 출력
 
- 한 줄(row, col 모두 해당)에 같은 숫자 못 옴
- 보는 쪽에서 첫 박스부터(1)부터 시작해서 그거보다 큰 박스 나오면 count++ 하고 다시 그걸 기준으로 앞으로

-----------------------------------------------------

rush 01

view[4][4]

좌표[4][4]

좌표[0][0]의 숫자를 정하려면

좌표[0][0~3]와 좌표[0~3][0]에 없는 숫자로 채우고

일단 채우고 확인? 흠

view[2][0]와 view[3][0] 보고 숫자 4개 채우기?

일단 첫 번째 row 채우고 확인?print_char('0' + grid[row][col] % 10);
			if (row < rows - 1)
- 그 값을 그 좌표에 넣을 수 있는지 확인하는 기능(가로 세로 중복 확인) check_coor -> 넣을 값 고르기
- view 값을 통해 그 좌표에 그 값이 들어가는데 불가능한게 아닌지 확인하는 기능 check_view -> 불가능하다면 백트래킹
- 마지막 답까지 도착한 경우 보드를 출력하는 기능 print_board

```c
int	check_coor(int *array[], int row, int col, int num)
{
// 같은 row col에 중복 수 있으면 1 리턴, 그렇지 않으면 0 리턴
// 아직 비어 있는 곳은 값이 0으로 초기화 되어 있음!
	int 	i;
	int	j;
	
	i = 0;
	j = 0;
	while (i < 4)
	{
		if (array[row][i] == num)
			return (1);
	}
	while (i < 4)
	{
		if (array[i][col] == num)
			return (1);
	}
	return (0);
}
int	check_view()
{
// 우선 현재 좌표 상황에서 view가 불가능한 경우 백트래킹 하게 해야 함

}
void	back_tracking(int *array[], int row, int col)
{
	int	i;
	int	ii;
	int	num;
	if (row >= 4)
		back_tracking(array, 0, col + 1);
	// 마지막까지 도착한 경우 그대로 출력
	if (col >= 4)
		print_board(array);
	i = 0;
	while (i < 4)
	{
		ii = 0;
		while (ii < 4)
		{
			num = 1;
			while (num <= 4)
			{
				if (check_coor(array, i, ii, num) && check_view())
				{
					array[i][ii] = num;
					back_tracking(array, i + 1, ii);
					array[i][ii] = 0;
				}
				num++;
			}
			ii++;
		}
		i++;
	}
}
int	main(int argc, char *argv[])
{
}
```

백트래킹 알고리즘 시작 전에
view 값 1 또는 n 값인 줄은 미리 채워놓고 시작
생성된 것들은 정답이기에 수정 못 하게 flag 세워놓기

			view[0][0] view[0][1] view[0][2] view[0][3]
view[2][0]		00			01			02		03		view[3][0]
view[2][1]												view[3][1]
view[2][2]												view[3][2]
view[2][3]								32				view[3][3]
			view[1][0] view[1][1] view[1][2] view[1][3]

0, 1 is_valid_view 확인하려면
view[0][1], view[1][1], view[2][0] view[3][0]

3, 2 is_valid_view 확인하려면
view[0][2], view[1][2], view[2][3], view[3][3]

4 * 4

"3 2 1 4 2 2 2 1 3 2 1 4 2 2 2 1"

"4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"

5 * 5

"4 2 1 2 3 1 4 3 2 2 3 2 3 2 1 3 4 1 2 2"

"4 2 1 2 3 1 4 3 2 2 3 2 3 2 1 3 4 1 2 2"

6 * 6

"412342253212233212314232"

"522331241332423212132342"

레전드 빨리 되는 거

"422613232132322143234213"

7 * 7

"6343132122243347342212122434"

---------------------------------------------


0이 입력되는 경우 무한 루프

숫자아닌 거

음수

0 값

argc != 2

argv[1] 숫자 개수가 SIZE * 4가 아닌경우

0 값

        //while (argv[1][i])
        //{
        //      if ('1' <= argv[1][i] && argv[1][i] <= '0' + SIZE)
        //      {
        //              view[ii / SIZE][ii % SIZE] = argv[1][i] - '0';
        //              ii++;
        //      }
        //      i++;
        //}


int	init_view(int view[4][SIZE], char *argv)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (argv[i])
	{
		while (argv[i] == ' ' || argv[i] == '\t')
			i++;
		if ('1' <= argv[i] && argv[i] <= '0' + SIZE)
		{
			view[count / SIZE][count % SIZE] = argv[i] - '0';
			count++;
		}
		else if (argv[i] == '\0')
			break;
		else
			return (1);
		i++;
	}
	if (count != SIZE * 4)
		return (1);
	return (0);
}

int     parse_view(const char *input, int view[4][SIZE]) // 입력 조건 유효성 검사
{
        int     i;
        int     j;
        int     cnt;

        i = 0;
        j = 0;
        cnt = 0;
        while (*input)
        {
                while (*input == ' ' || *input == '\t')
                        input++;
                if (*input >= '1' && *input <= SIZE + '0')
                {
                        view[i][j] = *input - '0'; // 입력 조건을 숫자로 변환하여 배열에 저장
                        j++;
                        cnt++;
                        if (j == SIZE)
                        {
                                i++;
                                j = 0;
                        }
                }
                else if (*input == '\0')
                        break ;
                else
                        return (0);
                input++;
        }
        if (cnt != SIZE * 4)
                return (0);
        return (1);
}
                                                                                                                                                                                                 183,1         B



																																								---
																																								--
```
max = 4
count = 1

1

4
1
3
2

4 1 3 2


max = 4
count = 3


0 1

1 ~ 4
0 ~ 3
0 3
1

기본값 1

view[0][i] == SIZE

1

4


3

2

반대편 1일때 view 값이 2면
바로 옆이 SIZE - 1


기본 값이 1이면

1이 맞는지 확인하고

2 3 4